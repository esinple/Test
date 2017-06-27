#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Log.h"
#include "Singleton.h"

class Logger
{
    SINGLETON(Logger);
    public:
        bool Init(const std::string& name);

        Log& GetLog();
    private:
        Log log_;
};

#define LOG_DEBUG(LOGGER,...) Logger::GetInstance().GetLog().Debug(LOGGER,##__VA_ARGS__);
#define LOG_INFO(LOGGER,...) Logger::GetInstance().GetLog().Info(LOGGER,##__VA_ARGS__);
#define LOG_ERROR(LOGGER,...) Logger::GetInstance().GetLog().Error(LOGGER,##__VA_ARGS__);

#endif
