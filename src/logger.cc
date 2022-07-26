#include <logger.hpp>
#include <stdarg.h>
#include <iostream>

LOGGING_STREAM *Logger::file=NULL;
bool Logger::thread_safetylock=false;
std::mutex Logger::mtx;

void Logger::SET_THREAD_SAFETY_LOCK(bool condition)
{
    thread_safetylock= condition;
}
void  Logger::LOG(LOG_LEVEL level,const char * message, ...)
{
    std::lock_guard<std::mutex> lock(mtx);
    file = (level == ERROR) ? stderr: stdout;
    fprintf(file,colors_strings[level]);
    va_list  args;
    va_start(args,message);
    vfprintf(file, message,args);
    va_end(args);
}
