#include "Progress.h"
#include <unistd.h>
#include <boost/progress.hpp>

void Progress::Test()
{
    boost::progress_display  pd(100);
    for(int i = 0;i < 50;++i)
    {
        usleep(100000);
        pd += 2;  
    }
}

