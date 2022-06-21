#include <logger.hpp>
#include <typeinfo>

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

// template<typename   Args>
void  LOGGER::Logger::LOG(LOGGER::LOG_LEVEL level,char * message,int args)
{
    printf("%s",colors_strings[level]);
    printf("LOG[%s]\t:\t" ,logger_level_strings[level]);
    printf("%s %d",message,args);
    printf("%s\n",colors_strings[4]);
}
