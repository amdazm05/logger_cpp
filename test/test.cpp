#include <benchmark/benchmark.h>
#include <logger.hpp>
#include <iostream>


static void LOGGER_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
  {
    // Logger::LOG(INFO,"Hello %d %d %x",2,2,355);
    // fopen("GeeksForGeeks.txt", "r");
    Logger::LOG(__LINE__,__FILE__,"file status %d",5);
  }
}
// BENCHMARK(LOGGER_BENCHMARK)->Iterations(20);


static void COUT_BENCHMARK(benchmark::State& state) {
  for (auto _ : state)
  {
    fopen("GeeksForGeeks.txt", "r");
       Logger::LOG(TRACE,"file status %d",5);
  //  std::cerr<<__FILE__<<__LINE__; 
    
  }
}
BENCHMARK(COUT_BENCHMARK)->Iterations(20);

BENCHMARK_MAIN();