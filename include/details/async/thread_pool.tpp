#ifndef _THREAD_POOL
#define _THREAD_POOL


#include <thread>
#include <functional>

/*******************************************************************************
 * @param theory  
 *    1-  Contains a special queue threadsafe for inputting tasks
 *    1*- user defines how big the queue must be  
 *    2*- Specify threads that will be used AKA the size of the pool
 *    3-  All threads must join and at the end of program life
 *      
 ******************************************************************************/
 namespace timber_line_details
 {
    template<std::size_t spqueue_size,std::size_t thread_pool_size>
    class thread_pool
    {
        static_assert(thread_pool_size,"thread pool size cannot be 0");
        public:
            using void_invokable = std::function<void()>; 
            thread_pool()=delete;
            thread_pool(
                void_invokable onstartInvokable,
                void_invokable workerInvokable,
                void_invokable onstopInvokable);
            ~thread_pool();

        private:
            thread_pool(const thread_pool &) = delete;
            std::vector<std::thread> threads_;
    };

    template<std::size_t spqueue_size,std::size_t thread_pool_size>
    thread_pool<spqueue_size,thread_pool_size>::thread_pool(void_invokable onstartInvokable,
                void_invokable workerInvokable,
                void_invokable onstopInvokable)
    {
        threads_.reserve(thread_pool_size);
        for(std::size_t threadI = 0;threadI<thread_pool_size;threadI++)
        {
            threads_.emplace_back([this,onstartInvokable,workerInvokable,onstopInvokable](){
                onstartInvokable();
                workerInvokable();
                onstopInvokable();
            });
        }
    }

    template<std::size_t spqueue_size,std::size_t thread_pool_size>
    thread_pool<spqueue_size,thread_pool_size>::~thread_pool()
    {
        for (auto &t : threads_) {
            t.join();
        }
    }

 }

#endif