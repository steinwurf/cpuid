#! /usr/bin/env python
# encoding: utf-8

from waflib.Build import BuildContext

APPNAME = 'cpuid'
VERSION = '5.0.2'


def build(bld):

    bld_features = []

    # Build static library if this is top-level otherwise just .o files
    if bld.is_toplevel():
        bld_features += ['cxx cxxstlib']
    else:
        bld_features += ['cxx']

    for features in bld_features:
        bld(features=features,
            source=bld.path.ant_glob('src/**/*.cpp'),
            target='cpuid',
            export_includes=['src'],
            use=['platform_includes'],
            install_path='${PREFIX}/lib')

    # Add a manual dependency to rebuild cpuinfo.cpp if a header file changes.
    # waf cannot detect this dependency, because the headers are included
    # conditionally based on the platform
    bld.add_manual_dependency(
        bld.path.find_node('src/cpuid/cpuinfo.cpp'),
        bld.path.ant_glob('src/cpuid/**/*.hpp'))

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse('test')
        bld.recurse('examples/print_cpuinfo')

        sourcepath = bld.path.find_node('src')

        bld.install_files(
            dest="${PREFIX}/include",
            files=sourcepath.ant_glob('**/*.hpp', excl=['**/detail/**']),
            cwd=sourcepath,
            relative_trick=True)


class DocsContext(BuildContext):
    cmd = 'docs'
    fun = 'docs'


def docs(ctx):
    with ctx.create_virtualenv() as venv:
        venv.run('pip install sphinx')
        venv.run(
            'pip install git+https://github.com/steinwurf/wurfapi@4416e13e6ca94ad833e25e81393d91eee59305f8')
        venv.run(
            'pip install git+https://github.com/steinwurf/restbuilder@830815608d4eb391e699bfb64315c89e091e4406')
        venv.run('sphinx-build -E -d build/doctrees -b rst -D version={} docs .'.format(VERSION),
                 cwd=ctx.path.abspath())

import re
from contextlib import contextmanager

@contextmanager
def rewrite(filename):
    class Content:

        def __init__(self):
            self.content = None

        def sub(self, pattern, repl):
            self.content = re.sub(pattern=pattern, repl=repl, string=self.content)


    content = Content()

    with open(filename) as f:
        content.content = f.read()

    yield content

    with open(filename, 'w') as f:
        f.write(content.content)


class ReleaseContext(BuildContext):
    cmd = 'prepare_release'
    fun = 'prepare_release'

def prepare_release(ctx):
    """ Prepare a release. """

    # Rewrite versions
    with rewrite(filename="src/cpuid/version.hpp") as f:
        v = "#define STEINWURF_CPUID_VERSION v{}".format(
            VERSION.replace('.', '_'))
        f.sub("#define STEINWURF_CPUID_VERSION v\d+_\d+_\d+", v)

    with rewrite(filename="src/cpuid/version.cpp") as f:
        v = 'return "{}"'.format(VERSION)
        f.sub('return "\d+\.\d+\.\d+"', v)

    # Build the docs
    docs(ctx)


