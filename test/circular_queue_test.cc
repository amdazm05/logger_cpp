#include <details/queues/circular_queue.tpp>
#include <chrono>
int main()
{
    timber_line_datastructs::circular_queue<int> q(10);
    for(int i =0;i<q.size();i++)
    {
        q.push_back(i);
        if(q.is_full()) break;
    }
    for(int i =0;i<q.size();i++)
    {
        std::cout<<q.at(i)<<std::endl;
    }
    return {};
}