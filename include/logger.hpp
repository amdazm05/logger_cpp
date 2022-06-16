#ifndef __logger
#define __logger
#include <stdint.h>
#include <fstream>

namespace LOGGER
{
    typedef uint8_t LOG_LEVEL;
    typedef std::fstream LOGGING_FILE;
    enum class log_levels
    {
        DEBUG = 0x00,
        INFO = 0x01,
        TRACE = 0x02,
        WARNING = 0x03,
        ERROR = 0x11
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
        LOG_LEVEL        level;
        LOGGING_FILE     *file;
        
    public:
        static void     SET_LEVEL(uint8_t level);
        static void     SET_LOG_PREGERENCE(uint8_t preference);
        static void     SET_LOG_PREGERENCE(uint8_t preference,std::string filename);
    };
}

#endif //__logger