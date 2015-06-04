#!/usr/bin/env python
# encoding: utf-8

project_name = 'cpuid'

def configure(options):
    pass

def build(options):
    pass

def run_tests(options):
    pass

def coverage_settings(options):
    options['required_line_coverage'] = 100.0
    options['run_cmd'] = '%s --no_fail'
