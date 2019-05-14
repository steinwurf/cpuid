#! /usr/bin/env python
# encoding: utf-8

from waflib.Build import BuildContext
APPNAME = 'cpuid'
VERSION = '5.0.2'

default_prefix = '/' + APPNAME + '_' + VERSION


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_CPUID_VERSION="{}"'.format(VERSION))

    bld_features = []

    # Build static library if this is top-level otherwise just .o files
    if bld.is_toplevel():
        bld_features += ['cxx cxxstlib']
        bld_features += ['cxx cxxshlib']
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
            'pip install git+https://github.com/steinwurf/wurfapi@4f667e6290a1115d5443e5a45b0bf9ad2c3edbdc')
        venv.run(
            'pip install git+https://github.com/mortenvp/restbuilder@830815608d4eb391e699bfb64315c89e091e4406')
        venv.run('sphinx-build -E -d build/doctrees -b rst docs .',
                 cwd=ctx.path.abspath())
