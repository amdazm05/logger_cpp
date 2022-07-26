#ifndef __logger
#define __logger

#include <stdint.h>
#include <string.h>
#include <mutex>

typedef uint8_t    LOG_LEVEL;
typedef FILE       LOGGING_STREAM;
typedef uint8_t    LOGGER_COLOR;
enum    log_levels
{
    DEBUG =     0x02,
    INFO =      0x01,
    TRACE =     0x03,
    WARNING =   0x04,
    ERROR =     0x00
} ;

constexpr char *colors_strings[] =
    {
            "\n \x1b[31m LOG[ERROR]:\t",     // COLOR_RED
            "\n \x1b[32m LOG[INFO]:\t",     // COLOR_GREEN
            "\n \x1b[35m LOG[DEBUG]:\t",     // COLOR_MAGENTA
            "\n \x1b[33m LOG[WARN]:\t",     // COLOR_YELLOW
            "\n \x1b[36m LOG[TRACE]:\t",     // COLOR_CYAN
            "\n \x1b[0m \n",   // COLOR_RESET
    };

class Logger
{
public:
    static void         LOG(LOG_LEVEL level,const char * message,...);
    static void         setFileName(const char * filename);
    static void         SET_THREAD_SAFETY_LOCK(bool condition);    
private:
    
    static LOGGING_STREAM *file;
    static void         SET_LEVEL(uint8_t level);
    static bool thread_safetylock;
    static std::mutex mtx;
    static int written_characters;
};


#endif //__logger