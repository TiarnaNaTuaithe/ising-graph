isingtest_sources = [
  'isingtest.cc',
]

isingtest_deps = [

]

isingtest_lib_deps = [
]

isingtest = executable('isingtest',
    [isingtest_sources, test_main],
    include_directories : inc,
    dependencies : [isingtest_deps,test_deps],
    link_with : [isingtest_lib_deps, test_dep_libs])

test('ising test', isingtest)

all_test_deps += isingtest_deps
all_test_dep_libs += isingtest_lib_deps
project_benchmark_sources += files(isingtest_sources)
