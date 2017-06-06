#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'cpuid'
VERSION = '5.0.1'


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_CPUID_VERSION="{}"'.format(VERSION))

    bld.recurse('src/cpuid')

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse('test')
        bld.recurse('examples/print_cpuinfo')
