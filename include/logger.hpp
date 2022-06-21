#ifndef __logger
#define __logger

#include <stdint.h>
#include <fstream>
#include <string.h>
#include <mutex>
namespace LOGGER
{
    typedef uint8_t         LOG_LEVEL;
    typedef std::fstream    LOGGING_FILE;
    typedef std::string     LOGGER_COLOR;
    enum class log_levels
    {
        DEBUG = 0x00,
        INFO = 0x01,
        TRACE = 0x02,
        WARNING = 0x03,
        ERROR = 0x11
    };
    enum class log_colors
    {
        ERROR_COLOR=31,
        LOG_COLOR=32,
        DEBUG_COLOR=35,
        WARNING_COLOR=33,
        TRACE_COLOR=36,
    };
    enum class logger_output
    {
        FILE=0,
        CONSOLE=1
    };

    template <class type>
    class Logger
    {
    private:
        static LOGGING_FILE     *file;
        struct loglevelprofile
        {   
            public:
                static LOGGER_COLOR *   colorcode;
                static LOG_LEVEL        level;
        };
        static std::mutex  mtx;
         
    public:
        static void         SET_THREAD_SAFETY_LOCK(bool condition);
        static void         SET_LEVEL(uint8_t level);
        static void         SET_LOG_PREGERENCE(uint8_t preference);
        static void         SET_LOG_PREGERENCE(uint8_t preference,std::string filename);
        static void         LOG(LOG_LEVEL level);
    };
}

#endif //__logger