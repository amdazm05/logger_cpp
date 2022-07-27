#include <logger.hpp>
#include <stdarg.h>
#include <iostream>
#include <errno.h>
LOGGING_STREAM *Logger::file=NULL;
bool Logger::thread_safetylock=false;
std::mutex Logger::mtx;

void Logger::SET_THREAD_SAFETY_LOCK(bool condition)
{
    thread_safetylock= condition;
}

void  Logger::LOG(int level,const char *path,const char * message, ...)
{
    if(thread_safetylock)  std::lock_guard<std::mutex> lock(mtx);
    fprintf(stdout,colors_strings[TRACING],path,level);
    va_list  args;
    va_start(args,message);
    vfprintf(stdout, message,args);
    va_end(args);
    return;

}

void  Logger::LOG(LOG_LEVEL level,const char * message, ...)
{
    if(thread_safetylock)  std::lock_guard<std::mutex> lock(mtx);
    file = (level == ERROR) ? stderr: stdout;
    fprintf(file,colors_strings[level]);
    va_list  args;
    va_start(args,message);
    vfprintf(file, message,args);
    va_end(args);
    if(errno!=0 && level ==ERROR)  fprintf(file,"\n %s \n",strerror(errno));
    return;
}
