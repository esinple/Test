#include "Logger.h"

bool Logger::Init(const std::string& name)
{
    log_.Init(name);
    return true;
}

Log& Logger::GetLog()
{
    return log_;
}
