isingbenchmark_sources = [
  'isingbenchmark.cc',
]

measurementbenchmark_sources = [
  'measurementbenchmark.cc'
]

isingbenchmark_deps = [
]

isingbenchmark_lib_deps = [
]

isingbenchmark = executable('isingbenchmark',
    [isingbenchmark_sources,benchmark_main],
    include_directories : inc,
    dependencies : [isingbenchmark_deps,benchmark_deps],
    link_with : [isingbenchmark_lib_deps, benchmark_dep_libs])

measurementbenchmark = executable('measurementbenchmark',
    [measurementbenchmark_sources,benchmark_main],
    include_directories : inc,
    dependencies : [isingbenchmark_deps,benchmark_deps],
    link_with : [isingbenchmark_lib_deps, benchmark_dep_libs])

benchmark('ising benchmark', isingbenchmark)
benchmark('ising susceptibility benchmark', measurementbenchmark)

all_benchmark_deps += isingbenchmark_deps
all_benchmark_dep_libs += isingbenchmark_lib_deps
project_benchmark_sources += files(isingbenchmark_sources)
