#! /usr/bin/env python
# encoding: utf-8

from waflib.Build import BuildContext
import os
import shutil

APPNAME = "cpuid"
VERSION = "8.0.0"

def options(opt):
    opt.add_option(
        '--cloudflare-auth', default=False, dest='cloudflare_auth',
        action='store_true', help='Use when deploying to Cloudflare')


def build(bld):

    # Build static library if this is top-level otherwise just .o files
    features = ["cxx"]
    if bld.is_toplevel():
        features += ["cxxstlib"]

    bld(
        features=features,
        source=bld.path.ant_glob("src/**/*.cpp"),
        target="cpuid",
        export_includes=["src"],
        use=["platform_includes"],
        install_path="${PREFIX}/lib",
    )

    # Add a manual dependency to rebuild cpuinfo.cpp if a header file changes.
    # waf cannot detect this dependency, because the headers are included
    # conditionally based on the platform
    bld.add_manual_dependency(
        bld.path.find_node("src/cpuid/cpuinfo.cpp"),
        bld.path.ant_glob("src/cpuid/**/*.hpp"),
    )

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse("test")
        bld.recurse("examples/print_cpuinfo")

        sourcepath = bld.path.find_node("src")

        bld.install_files(
            dest="${PREFIX}/include",
            files=sourcepath.ant_glob("**/*.hpp", excl=["**/detail/**"]),
            cwd=sourcepath,
            relative_trick=True,
        )

        bld.install_files(dest="${PREFIX}/", files=bld.path.ant_glob("NEWS.rst"))


class ReleaseContext(BuildContext):
    cmd = "prepare_release"
    fun = "prepare_release"


def prepare_release(ctx):
    """Prepare a release."""

    # Rewrite versions
    with ctx.rewrite_file(filename="src/cpuid/version.hpp") as f:

        pattern = r"#define STEINWURF_CPUID_VERSION v\d+_\d+_\d+"
        replacement = "#define STEINWURF_CPUID_VERSION v{}".format(
            VERSION.replace(".", "_")
        )

        f.regex_replace(pattern=pattern, replacement=replacement)

    with ctx.rewrite_file(filename="src/cpuid/version.cpp") as f:
        pattern = r'return "\d+\.\d+\.\d+"'
        replacement = 'return "{}"'.format(VERSION)

        f.regex_replace(pattern=pattern, replacement=replacement)


def docs(ctx):
    """Build the documentation in a virtualenv"""
    if ctx.options.cloudflare_auth:
        shutil.rmtree("./functions", ignore_errors=True)
        os.system("git clone git@github.com:steinwurf/cloudflare-auth.git")
        shutil.copytree('cloudflare-auth/functions', './functions')
        shutil.rmtree("./cloudflare-auth", ignore_errors=True)

    with ctx.create_virtualenv() as venv:

        # To update the requirements.txt just delete it - a fresh one
        # will be generated from test/requirements.in
        if not os.path.isfile("docs/requirements.txt"):
            venv.run("python -m pip install pip-tools")
            venv.run("pip-compile docs/requirements.in")

        venv.run("python -m pip install -r docs/requirements.txt")

        build_path = os.path.join(ctx.path.abspath(), "build", "site", "docs")

        venv.run(
            "giit clean . --build_path {}".format(build_path), cwd=ctx.path.abspath()
        )
        venv.run(
            "giit sphinx . --build_path {}".format(build_path), cwd=ctx.path.abspath()
        )
