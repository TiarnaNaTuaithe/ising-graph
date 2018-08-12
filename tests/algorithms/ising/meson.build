metropolistest_sources = [
    'metropolistest.cc'
]

metropolistest_deps = [

]

metropolistest_lib_deps = [
]

metropolistest = executable('metropolistest',
    [metropolistest_sources, test_main],
    include_directories : inc,
    dependencies : [metropolistest_deps,test_deps],
    link_with : [metropolistest_lib_deps, test_dep_libs])

test('metropolis test', metropolistest)

all_test_deps += metropolistest_deps
all_test_dep_libs += metropolistest_lib_deps
project_benchmark_sources += files(metropolistest_sources)
