#ifndef _LOGGER
#define _LOGGER

namespace timberline
{
    template<>
    class LoggerCore
    {
        private:
            std::shared_ptr<LoggerCore> instance_;
        private:
            LoggerCore()=default;
            ~LoggerCore()=default;
            LoggerCore(const Logger&)=delete;
            LoggerCore(Logger&&)=delete;
            LoggerCore& operator=(const LoggerCore&)=delete;
        public:
            LoggerCore & init();
    };
};

// @TODO 
// 1- rotating file
// 2- colors
// 3- thread, time, fmt, format logs
// 4- backtrace ? 
// 5- Asynchronus logging

//@AMAZING WORK
//https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/async.h
//
#endif //_LOGGER