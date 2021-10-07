/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-07
 */

#include "singleton.h"

static void test1()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    Singleton* instance = nullptr;

    while(1)
    {
        instance = Singleton::get_singleton(&mutex);
        instance->hello();
        sleep(1);
    }

    pthread_mutex_destroy(&mutex);
}

void *func(void *p)
{
    pthread_mutex_t *mutex = (pthread_mutex_t *)p;
    Singleton* instance = nullptr;
    Singleton* firstInstance = Singleton::get_singleton(mutex);
    printf("T --- ptId[%lu] firstInstance[%p]\n", pthread_self(), firstInstance);

    while(1)
    {
        instance = Singleton::get_singleton(mutex);
        if (instance != firstInstance)
        {
            printf("T --- error firstInstance[%p] instance[%p] \n", firstInstance, instance);
        }
        usleep(10);
    }
}

static void test2()
{
    int ret = -1;
    pthread_t ptId;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    ret = pthread_create(&ptId, nullptr, func, &mutex);
    if (ret < 0)
    {
        perror("pthread_create error");
    }

    ret = pthread_create(&ptId, nullptr, func, &mutex);
    if (ret < 0)
    {
        perror("pthread_create error");
    }

    ret = pthread_create(&ptId, nullptr, func, &mutex);
    if (ret < 0)
    {
        perror("pthread_create error");
    }

    while(1)
    {
        sleep(1);
    }
}


int main(int argc, char * argv [ ])
{
    // test1();
    test2();
    return 0;
}

