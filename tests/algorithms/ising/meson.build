isingalgotest_sources = [
    'metropolistest.cc',
    'wolfftest.cc'
]

isingalgotest_deps = [

]

isingalgotest_lib_deps = [
]

isingalgotest = executable('isingalgotest',
    [isingalgotest_sources, test_main],
    include_directories : inc,
    dependencies : [isingalgotest_deps,test_deps],
    link_with : [isingalgotest_lib_deps, test_dep_libs])

test('Ising algorithm test', isingalgotest)

all_test_deps += isingalgotest_deps
all_test_dep_libs += isingalgotest_lib_deps
project_benchmark_sources += files(isingalgotest_sources)
