#include <benchmark/benchmark.h>
#include <logger.hpp>
#include <iostream>


static void LOGGER_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
  {
    Logger::LOG(INFO,"Hello %d %d %x",2,2,355);
    Logger::LOG(TRACE,"Hello %d %d %x",2,2,355);
  }
}
BENCHMARK(LOGGER_BENCHMARK)->Iterations(5000);


static void COUT_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
   std::cout<<colors_strings[2]<<"cout"<<2<<2<<std::hex<<355; 
}
// BENCHMARK(COUT_BENCHMARK)->Iterations(500);

BENCHMARK_MAIN();