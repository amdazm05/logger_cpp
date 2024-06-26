#ifndef _MPMCBLOCKINGTHREAD
#define _MPMCBLOCKINGTHREAD
#include <mutex>
#include <condition_variable>
#include <details/queues/circular_queue.tpp>
namespace timber_line_datastructs
{

    /*************************************************************************
    * @param theory
    * 1- 
    * 2- 
    * 3- 
    **************************************************************************/
    template<typename T,bool isBlocking = true>
    class mpmc_queue
    {
        static_assert(isBlocking , " mpmc: blocking mode not implemented.");
        std::condition_variable place_cv_;
        std::condition_variable remove_cv_;
        std::mutex queue_mutex_;
        timber_line_datastructs::circular_queue<T> circular_q_;

        public:
            mpmc_queue(std::size_t maxSize) : circular_q_(maxSize){}
            void push(T && item)
            {
                std::unique_lock<std::mutex> ulock(queue_mutex_);
                place_cv_.wait(ulock,[this](){return !this->circular_q_.is_full();});
                circular_q_.push_back(item);
                place_cv_.notify_one();
            }
            void pop(T&popedItem)
            {
                std::unique_lock<std::mutex> ulock(queue_mutex_);
                remove_cv_.wait(ulock,[this](){return !this->circular_q_.is_empty();});
                popedItem = std::move(circular_q_.top());
                circular_q_.pop_front();
                remove_cv_.notify_one();
            }
            //shows active counts     
            const std::size_t size() const
            {
                return circular_q_.size();
            }
    };
}


#endif //_MPMCBLOCKINGTHREAD