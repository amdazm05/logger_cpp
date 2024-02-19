#include <details/async/thread_pool.tpp>
#include <iostream>
#include <windows.h>

int main()
{
    auto onStart = []()
    {
        std::cout<<"Start"<<std::endl;
    };
    auto onStop = []()
    {
        std::cout<<"Stop"<<std::endl;
    };
    auto Worker = []()
    {
        std::cout<<"Work"<<std::endl;
    };
    timber_line_details::thread_pool<3,3> pool(onStart,Worker,onStop);

    return 0;
}