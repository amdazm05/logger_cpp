#include <logger.hpp>
#include <stdarg.h>

LOGGING_FILE *Logger::file=NULL;
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
    va_list    args;
    va_start(args,message);
    fprintf (file,colors_strings[level]);
    fprintf (file,"LOG[%s]:" ,logger_level_strings[level]);
    vfprintf(file, message,args) ;
    fprintf (file,colors_strings[5]);
    va_end(args);
    return ;
}
