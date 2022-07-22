#ifndef __logger
#define __logger

#include <stdint.h>
#include <string.h>
#include <mutex>

typedef uint8_t         LOG_LEVEL;
typedef FILE       LOGGING_FILE;
typedef uint8_t    LOGGER_COLOR;
enum    log_levels
{
    DEBUG =     0x02,
    INFO =      0x01,
    TRACE =     0x03,
    WARNING =   0x04,
    ERROR =     0x00
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
public:
    static void         LOG(LOG_LEVEL level,const char * message,...);
    static void         setFileName(const char * filename);
    static void         SET_THREAD_SAFETY_LOCK(bool condition);    
private:
    
    static LOGGING_FILE *file;
    static void         SET_LEVEL(uint8_t level);
    static constexpr char *colors_strings[] =
    {
            "\x1b[31m",     // COLOR_RED
            "\x1b[32m",     // COLOR_GREEN
            "\x1b[35m",     // COLOR_MAGENTA
            "\x1b[33m",     // COLOR_YELLOW
            "\x1b[36m",     // COLOR_CYAN
            "\x1b[0m \n",   // COLOR_RESET
    };
    static constexpr char *logger_level_strings[] =
    {
            "ERROR",        // COLOR_RED
            "INFO",         // COLOR_GREEN
            "DEBUG",        // COLOR_YELLOW
            "TRACE",        // COLOR_MAGENTA
            "ERROR",        // COLOR_CYAN
    };
    static bool thread_safetylock;
    static std::mutex mtx;
    static int written_characters;
};


#endif //__logger