#ifndef __LOG_H__
#define __LOG_H__

#include <boost/log/sources/severity_logger.hpp>

enum severity_level
{
    eSL_Info,
    eSL_Debug,
    eSL_Error
};

static const char* const severity_level_str[] =  
{  
    "Info",  
    "Debug",  
    "Error"
};  

template< typename CharT, typename TraitsT >  
inline std::basic_ostream< CharT, TraitsT >& operator<< (std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)  
{  
    if (static_cast< std::size_t >(lvl) < (sizeof(severity_level_str) / sizeof(*severity_level_str)))  
        strm << severity_level_str[lvl];  
    else  
        strm << static_cast< int >(lvl);  
    return strm;  
}

class Log
{
    public:
        Log();
        ~Log();

    public:
        bool Init();

        void Debug(const char *format,...);
        void Error(const char *format,...);
        void Info(const char *format,...);

    private:
        boost::log::sources::severity_logger<severity_level> lg_;
};

#endif
