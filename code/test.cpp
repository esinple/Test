#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"
#include <iostream>
int main()  
{  
	log4cxx::PropertyConfigurator::configureAndWatch("log4cxx.properties");  
	log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("lib"));  
	LOG4CXX_DEBUG(logger, "this is log4cxx test");
	printf("123\n");
	return 0;  
}  
