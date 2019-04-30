#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'cpuid'
VERSION = '5.0.2'


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_CPUID_VERSION="{}"'.format(VERSION))

    if bld.is_toplevel():
        bld.stlib(
            features='cxx',
            source=bld.path.ant_glob('src/**/*.cpp'),
            target='cpuid',
            export_includes=['src'],
            use=['platform_includes'])

    else:
        bld.objects(
            features='cxx',
            source=bld.path.ant_glob('src/**/*.cpp'),
            target='cpuid',
            export_includes=['src'],
            use=['platform_includes'])



    # Add a manual dependency to rebuild cpuinfo.cpp if a header file changes.
    # waf cannot detect this dependency, because the headers are included
    # conditionally based on the platform
    bld.add_manual_dependency(
        bld.path.find_node('src/cpuid/cpuinfo.cpp'),
        bld.path.ant_glob('src/cpuid/**/*.hpp'))


    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        # bld.recurse('test')
        # bld.recurse('examples/print_cpuinfo')
        pass
