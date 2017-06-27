#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#define SINGLETON(CLASS) \
    public: \
static CLASS& instance() \
{ \
    static CLASS ins; \
    return ins; \
} \
private: \
    CLASS(); \
    ~CLASS();

#endif
