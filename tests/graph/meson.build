graphtest_sources = [
  'graphtest.cc',
  'grid2dtest.cc'
]

graphtest_deps = [

]

graphtest_lib_deps = [
]

graphtest = executable('graphtest',
    [graphtest_sources, test_main],
    include_directories : inc,
    dependencies : [graphtest_deps,test_deps],
    link_with : [graphtest_lib_deps, test_dep_libs])

test('graph test', graphtest)

all_test_deps += graphtest_deps
all_test_dep_libs += graphtest_lib_deps
project_benchmark_sources += files(graphtest_sources)
