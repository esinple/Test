#include "BoostLog.h"

#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
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

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};

void BoostLog::test()
{
    /*logging::core::get()->set_filter
      (
      logging::trivial::severity >= logging::trivial::info
      );

      logging::add_file_log
      (
      keywords::file_name = "sample\%N.log",
      keywords::rotation_size = 10 * 1024 * 1024,
         keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
         keywords::format = "[%TimeStamp%]: %Message%"
        );

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";*/

     src::severity_logger<severity_level> lg;

    /*logging::record rec = lg.open_record();
    if (rec)
    {
        logging::record_ostream strm(rec);
        strm << "Hello, World!";
        strm.flush();
        lg.push_record(boost::move(rec));

    }*/

     boost::shared_ptr< logging::core > core = logging::core::get();
     core->add_global_attribute("LineID", attrs::counter< unsigned int >(1));
     core->add_global_attribute("TimeStamp", attrs::local_clock());

     BOOST_LOG_SEV(lg, normal) << "A regular message";
     BOOST_LOG_SEV(lg, warning) << "Something bad is going on but I can handle it";
     BOOST_LOG_SEV(lg, critical) << "Everything crumbles, shoot me now!";
}

