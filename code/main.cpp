#include "ssj/testlib.h"
#include "Thread.h"
#include "Log.h"

#include <log4cxx/logger.h>
#include <log4cxx/helpers/pool.h>
#include <log4cxx/basicconfigurator.h>
//layouts
#include <log4cxx/simplelayout.h>
#include <log4cxx/ttcclayout.h>
#include <log4cxx/patternlayout.h>
//appender
#include <log4cxx/dailyrollingfileappender.h>

using namespace log4cxx;

int main(void)
{
    log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("logger");
    helpers::Pool pool;

    std::string filename("testlog");
    //layouts
    //log4cxx::LayoutPtr layout = new log4cxx::SimpleLayout();
    auto layout = new PatternLayout();
    layout->setConversionPattern("[%d{yy-MM-dd H:m:s}][%p]%m%n");
    layout->activateOptions(pool);
    //appender
    auto appender = new log4cxx::DailyRollingFileAppender();
    appender->setDatePattern(".%Y-%M-%d");
    appender->setLayout(layout);
    appender->setName(filename);
    appender->setFile(filename);
    layout->activateOptions(pool);
    logger->addAppender(appender);
    //logger
    log4cxx::BasicConfigurator::configure(log4cxx::AppenderPtr(appender));

    log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getDebug());

    LOG4CXX_INFO(logger, "Simple message text.");
    return 0;
}
