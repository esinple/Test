#ifndef __LOG_H__
#define __LOG_H__

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/consoleappender.h>

class Log
{
    public:
        Log();
        ~Log();

    public:
        void test();

    private:
};

#endif
