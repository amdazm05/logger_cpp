#include <benchmark/benchmark.h>
#include <logger.hpp>
#include <iostream>


static void LOGGER_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
  {
    // Logger::LOG(INFO,"Hello %d %d %x",2,2,355);
    fopen("GeeksForGeeks.txt", "r");
    Logger::LOG(INFO,"file status");
  }
}
BENCHMARK(LOGGER_BENCHMARK)->Iterations(20);


static void COUT_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
  {
    fopen("GeeksForGeeks.txt", "r");
   std::cerr<<colors_strings[2]<<"cout"<<2<<2<<std::hex<<355<<strerror(errno); 
    
  }
}
BENCHMARK(COUT_BENCHMARK)->Iterations(20);

BENCHMARK_MAIN();