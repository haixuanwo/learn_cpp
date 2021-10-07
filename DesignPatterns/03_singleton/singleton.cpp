/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-07
 */

#include "singleton.h"

using namespace std;

Singleton* Singleton::get_singleton(pthread_mutex_t *mutex)
{
    if (nullptr == instance)
    {
        pthread_mutex_lock(mutex);

        if (nullptr == instance)
        {
            instance = new Singleton;
            printf("T --- new instance[%p]\n", instance);
        }

        pthread_mutex_unlock(mutex);
    }
    return instance;
}

void Singleton::hello()
{
    cout<<"hello I'm singleton pattern p["<<this<<"]"<<endl;
}

Singleton* Singleton::instance = nullptr;

