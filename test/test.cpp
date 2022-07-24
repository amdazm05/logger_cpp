#include <benchmark/benchmark.h>
#include <logger.hpp>
#include <iostream>


static void LOGGER_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
    Logger::LOG(INFO,"Hello");
}
// Register the function as a benchmark
BENCHMARK(LOGGER_BENCHMARK)->Iterations(100);


static void COUT_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
   std::cout<<"cout"; 
}
// Register the function as a benchmark
BENCHMARK(COUT_BENCHMARK)->Iterations(100);

BENCHMARK_MAIN();