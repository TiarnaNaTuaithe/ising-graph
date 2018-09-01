metropolisbenchmark_sources = [
  'metropolisbenchmark.cc',
]

wolffbenchmark_sources = [
  'wolffbenchmark.cc'
]

measurementbenchmark_sources = [
  'measurementbenchmark.cc'
]

metropolisbenchmark = executable('metropolisbenchmark',
    [metropolisbenchmark_sources,benchmark_main],
    include_directories : inc,
    dependencies : [benchmark_deps],
    link_with : [benchmark_dep_libs])

wolffbenchmark = executable('wolffbenchmark',
    [wolffbenchmark_sources,benchmark_main],
    include_directories : inc,
    dependencies : [benchmark_deps],
    link_with : [benchmark_dep_libs])

measurementbenchmark = executable('measurementbenchmark',
    [measurementbenchmark_sources,benchmark_main],
    include_directories : inc,
    dependencies : [benchmark_deps],
    link_with : [benchmark_dep_libs])

benchmark('Metropolis benchmark', metropolisbenchmark)
benchmark('Wolff benchmark', wolffbenchmark)
benchmark('Ising susceptibility benchmark', measurementbenchmark)

project_benchmark_sources += files(metropolisbenchmark_sources,
				measurementbenchmark_sources,
			  	wolffbenchmark_sources)
