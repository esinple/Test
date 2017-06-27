#include "ssj/testlib.h"
#include "Thread.h"
#include "Log.h"
#include "UUIDGenerator.h"

int main(void)
{
    Log log;
    log.Init();
    log.Debug("testtest!");

    /*auto u1 = UUIDGenerator::instance().genUUID("13524282899");
    auto u2 = UUIDGenerator::instance().genUUID("mytestuuid");

    std::stringstream ss1;
    ss1 << u1;
    printf("u1 %s\n",ss1.str().c_str());

    std::stringstream ss2;
    ss2 << u2;
    printf("u2 %s\n",ss2.str().c_str());*/

    return 0;
}
