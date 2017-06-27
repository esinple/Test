#ifndef _UUID_GENERATOR_H_
#define _UUID_GENERATOR_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <string>
#include "Singleton.h"


using namespace boost::uuids;

class UUIDGenerator
{
    SINGLETON(UUIDGenerator);
    public:
        uuid genUUID(const std::string& s)const;
    private:
};

#endif
