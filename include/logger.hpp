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
    typedef uint8_t    LOGGER_COLOR;
    enum log_levels
    {
        DEBUG = 0x02,
        INFO = 0x01,
        TRACE = 0x03,
        WARNING = 0x04,
        ERROR = 0x00
    } ;
    enum  log_colors
    {
        ERROR_COLOR=1,
        LOG_COLOR=2,
        DEBUG_COLOR=3,
        WARNING_COLOR=4
    } ;

    class Logger
    {
    private:
        static LOGGING_FILE     *file;
        static std::mutex   mtx;
        static void         SET_LEVEL(uint8_t level);
    public:
        static void         SET_THREAD_SAFETY_LOCK(bool condition);    
        // template<typename   ... Args>
        static void         LOG(LOG_LEVEL level,char * message,int args);
    };
}

#endif //__logger