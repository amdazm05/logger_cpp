#include <logger.hpp>
#include <stdarg.h>

std::mutex mtx;
bool thread_safetylock;
const char * colors_strings[] = 
{   
    "\x1b[31m",          //COLOR_RED
    "\x1b[32m",          //COLOR_GREEN
    "\x1b[35m",          //COLOR_MAGENTA    
    "\x1b[33m" ,         //COLOR_YELLOW
    "\x1b[36m",          //COLOR_CYAN
    "\x1b[0m"  ,         //COLOR_RESET
};

const char *  logger_level_strings[] = 
{   
    "ERROR"  ,           //COLOR_RED
    "INFO"  ,            //COLOR_GREEN 
    "DEBUG"   ,        //COLOR_YELLOW
    "TRACE"    ,         //COLOR_MAGENTA
    "ERROR"   ,          //COLOR_CYAN
};

void  LOGGER::Logger::SET_THREAD_SAFETY_LOCK(bool condition)
{   
    thread_safetylock=condition;
}


void  LOGGER::Logger::LOG(LOGGER::LOG_LEVEL level,const char * message, ...)
{
    if(thread_safetylock)
    {
        std::lock_guard<std::mutex> lock(mtx);
    }
        
    va_list    args;
    va_start(args,message);
    printf(colors_strings[level]);
    printf("LOG[%s]:" ,logger_level_strings[level]);
    vfprintf(stdout, message, args);
    printf(colors_strings[4]);
    printf("\n");
    va_end(args);
}
