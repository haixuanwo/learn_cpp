/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-07
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>

class Singleton
{
public:
    static Singleton* get_singleton(pthread_mutex_t *mutex);

    void hello();

    static Singleton* instance;
};

#endif

