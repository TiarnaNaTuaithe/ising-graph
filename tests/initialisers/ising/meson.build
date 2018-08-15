isingrandomtest_sources = [
    'randomtest.cc'
]

isingrandomtest_deps = [

]

isingrandomtest_lib_deps = [
]

isingrandomtest = executable('isingrandomtest',
    [isingrandomtest_sources, test_main],
    include_directories : inc,
    dependencies : [isingrandomtest_deps,test_deps],
    link_with : [isingrandomtest_lib_deps, test_dep_libs])

test('random ising initialiser test', isingrandomtest)

all_test_deps += isingrandomtest_deps
all_test_dep_libs += isingrandomtest_lib_deps
project_benchmark_sources += files(isingrandomtest_sources)
