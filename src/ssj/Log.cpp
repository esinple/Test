#include "Log.h"

#include <sys/stat.h>
#include <sys/types.h>

#include <unistd.h>
#define GETCWD getcwd
#include <iostream>

#include <log4cxx/logger.h>
#include <log4cxx/helpers/pool.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/simplelayout.h>

using namespace log4cxx;

Log::Log()
{

}

Log::~Log()
{

}

void Log::test()
{
    /*log4cxx::FileAppender * fileAppender = new log4cxx::FileAppender(log4cxx::LayoutPtr(new log4cxx::SimpleLayout()), "logfile", false);

    log4cxx::helpers::Pool p;
    fileAppender->activateOptions(p);

    log4cxx::BasicConfigurator::configure(log4cxx::AppenderPtr(fileAppender));
    log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getDebug());
    log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("logger");

    LOG4CXX_INFO(logger,"Created FileAppender appender");*/
}
