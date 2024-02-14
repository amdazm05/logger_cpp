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
template<std::size_t spqueue_size,std::size_t thread_pool_size>
class thread_pool
{
    using void_invokable = std::function<void()>; 
    static_assert("thread pool size cannot be 0",thread_pool_size);
    public:
        thread_pool();
        thread_pool(
            void_invokable onstartInvokable,
            void_invokable workerInvokable,
            void_invokable onstopInvokable);

    private:
        thread_pool(const thread_pool &) = delete;
        std::array<std::thread,thread_pool_size> threads_;
};

#endif