#ifndef _MPMCBLOCKINGTHREAD
#define _MPMCBLOCKINGTHREAD

namespace timber_line_datastructs
{

    template<typename T,bool isBlocking = true>
    class mpmc_queue
    {
        static_assert(isBlocking , " mpmc: blocking mode not implemented.")
    };
}


#endif //_MPMCBLOCKINGTHREAD