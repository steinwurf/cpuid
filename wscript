#! /usr/bin/env python
# encoding: utf-8

import os

APPNAME = 'cpuid'
VERSION = '1.0.0'

def recurse_helper(ctx, name):

    if not ctx.has_dependency_path(name):
        ctx.fatal('Load a tool to find %s as system dependency' % name)
    else:
        p = ctx.dependency_path(name)
        ctx.recurse(p)

def options(opt):

    import waflib.extras.wurf_dependency_bundle as bundle
    import waflib.extras.wurf_dependency_resolve as resolve
    import waflib.extras.wurf_configure_output

    bundle.add_dependency(opt,
        resolve.ResolveGitMajorVersion(
            name='waf-tools',
            git_repository = 'github.com/steinwurf/external-waf-tools.git',
            major_version = 2))

    opt.load('wurf_dependency_bundle')
    opt.load('wurf_tools')

def configure(conf):

    if conf.is_toplevel():

        conf.load('wurf_dependency_bundle')
        conf.load_external_tool('mkspec', 'wurf_cxx_mkspec_tool')
        conf.load_external_tool('runners', 'wurf_runner')
        conf.load_external_tool('install_path', 'wurf_install_path')
        conf.load_external_tool('project_gen', 'wurf_project_generator')

def build(bld):

    bld.program(features = 'cxx',
              source = 'src/cpuid/cpuid.cpp',
              target = 'cpuid.o',
              use = [])

