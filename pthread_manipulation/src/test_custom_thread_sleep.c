#include "tests_pthread.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

static pthread_mutex_t fakeMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t fakeCond = PTHREAD_COND_INITIALIZER;

void mywait(int time_in_sec);
void* fun(void* arg);

void test_custom_thread_sleep()
{
    pthread_t thread;
    void *ret;

    pthread_create(&thread, NULL, fun, NULL);

    pthread_join(thread,&ret);
}

void mywait(int time_in_sec)
{
    struct timeval tv;
    struct timespec ts;

    gettimeofday(&tv, NULL);
    ts.tv_sec = time(NULL) + time_in_sec;
    ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (time_in_sec);
    ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
    ts.tv_nsec %= (1000 * 1000 * 1000);

    int n = pthread_cond_timedwait(&fakeCond, &fakeMutex, &ts);
}

void* fun(void* arg)
{
    printf("\nIn thread\n");
    mywait(5);
    printf("\nAfter Sleep\n");
}
