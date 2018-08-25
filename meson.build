project('ising_graph', 'cpp',
	version : '1.0',
	license : [ 'proprietary'],
	meson_version : '>= 0.40.1',
	default_options : [ 'warning_level=3', 'buildtype=debugoptimized', 'cpp_std=c++17' ]
)

# Variables tracking sources and libraries
library_path = []
project_sources = []
project_header_files = []
project_test_sources = []
project_benchmark_sources = []

inc = [include_directories('include')]

subdir('include')
# This is where you should add in include directories

subdir('src')

ising_graph_deps = [
]

ising_graph_dep_libs = [
]

test_bin = executable('measure-lattice',
		      main_source,
		      include_directories : inc,
		      dependencies : ising_graph_deps,
		      link_with : ising_graph_dep_libs)

if get_option('enable-tests')
  subdir('tests')
endif
if get_option('enable-benchmarks')
  subdir('benchmarks')
endif

subdir('docs')

# This adds the clang format file to the build directory
configure_file(input : '.clang-format',
			   output : '.clang-format',
			   configuration : configuration_data())
run_target('format',
  command : ['clang-format','-i','-style=file',project_sources,project_test_sources,project_benchmark_sources,project_header_files])

# This regex excludes any sources from the third_party, tests, benchmarks
# and gtest related files.
regex = '^((?!(third_party|tests|benchmarks|gtest)).)*$'
# This adds clang tidy support
configure_file(input : '.clang-tidy',
			   output : '.clang-tidy',
			   configuration : configuration_data())
run_target('tidy',
  command : ['run-clang-tidy','-fix', '-j' , '8', 'files', regex ,'-format', '-p='+ meson.build_root()])
