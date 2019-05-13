

extensions = ['sphinxcontrib.restbuilder', 'wurfapi']
source_suffix = '.rst'
master_doc = 'README'


# wurfapi options - relative to your docs dir
wurfapi = {
  'source_paths': ['../src/cpuid/cpuinfo.hpp'],
  'recursive': True,
  'parser': {'type': 'doxygen', 'download': True,  'warnings_as_error': True}
}