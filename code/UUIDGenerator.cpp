#include "UUIDGenerator.h"

UUIDGenerator::UUIDGenerator()
{
}

UUIDGenerator::~UUIDGenerator()
{
}

uuid UUIDGenerator::genUUID(const std::string& s)const
{
    //static uuid base_id = string_generator()("{0123456789abcdef0123456789abcdef}");
    //static name_generator gen(base_id);
    
    //uuid id = gen(s);
    
    //random_generator rgen;
    //uuid id = rgen();

    boost::uuids::basic_random_generator<boost::mt19937> gen;
    boost::uuids::uuid id = gen();
    return id;
}

