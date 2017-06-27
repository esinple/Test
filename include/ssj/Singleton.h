#ifndef _SINGLETON_H_
#define _SINGLETON_H_

/*#include <boost/serialization/singleton.hpp> 

template<class T>
class Singleton : public boost::serialization::singleton<Singleton<T>>
{
    public:
        Singleton<T>& GetInstance()
        {
            return Singleton<T>::get_mutable_instance();
        }
};*/

#define SINGLETON(CLASS) \
        public: \
static CLASS& GetInstance() \
{ \
    static CLASS ins; \
    return ins; \
} \
private: \
    CLASS(){}; \
    ~CLASS(){};

#endif
