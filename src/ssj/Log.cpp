#include "Log.h"
#include <stdio.h>
/*#include <boost/log/core.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>  
#include <boost/log/sources/record_ostream.hpp>*/

#include <boost/log/core.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/trivial.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>  
#include <boost/shared_ptr.hpp>

using namespace boost;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

Log::Log()
{

}

Log::~Log()
{

}

bool Log::Init(const std::string& name,uint32_t fileSize,uint32_t rollHour)
{
    typedef sinks::synchronous_sink< sinks::text_file_backend > file_sink;  
    shared_ptr< file_sink > sink(new file_sink(  
                keywords::open_mode = std::ios::app,
                keywords::file_name = name + "%Y-%m-%d-%H.log",         // file name pattern  
                keywords::rotation_size = fileSize  // rotation size, in characters  
                ));  

    // Set up where the rotated files will be stored  
    sink->locked_backend()->set_file_collector(sinks::file::make_collector(  
                keywords::target = "logs"                          // where to store rotated files  
                //keywords::max_size = 16 * 1024 * 1024,              // maximum total size of the stored files, in bytes  
                //keywords::min_free_space = 100 * 1024 * 1024        // minimum free space on the drive, in bytes  
                ));

    // Upon restart, scan the target directory for files matching the file_name pattern  
    //sink->locked_backend()->scan_for_files();  
    //sink->locked_backend()->scan_for_files(sinks::file::scan_all);

    sink->set_formatter  
        (  
         expr::format("[%1%][%2%][%3%]")  
         % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
         % expr::attr<severity_level>("Severity")
         % expr::smessage  
        );

    //sink->locked_backend()->auto_flush(true);

    sinks::file::rotation_at_time_interval(posix_time::hours(rollHour));

    boost::shared_ptr<logging::core> core = logging::core::get();

    logging::add_common_attributes();  

    core->add_sink(sink);

    return true;
}

#define BuffSize 512

#define FORMAT_MSG() \
    static char buff[BuffSize] = {0}; \
    va_list va; \
    va_start(va,format); \
    vsnprintf(buff,BuffSize-1,format,va); \
    va_end(va); \

void Log::Debug(const char *format,...)
{
    FORMAT_MSG();
    BOOST_LOG_SEV(lg_, eSL_Debug) << buff;
}

void Log::Error(const char *format,...)
{
    FORMAT_MSG();
    BOOST_LOG_SEV(lg_, eSL_Error) << buff;
}

void Log::Info(const char *format,...)
{
    FORMAT_MSG();
    BOOST_LOG_SEV(lg_, eSL_Info) << buff;
}
