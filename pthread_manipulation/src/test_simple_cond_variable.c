#include "tests_pthread.h"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t g_mutex         = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t g_cond_variable  = PTHREAD_COND_INITIALIZER;

void * thread1();
void * thread2();

void test_simple_cond_variable()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);

    sleep(3);

    pthread_create(&t2, NULL, thread2, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void * thread1()
{
    printf("Entrou na thread 1!\n");

    pthread_mutex_lock(&g_mutex);
    pthread_cond_wait(&g_cond_variable, &g_mutex);
    pthread_mutex_unlock(&g_mutex);

    printf("Signal recebido!\n");
}

void * thread2()
{
    printf("Entrou na thread 2!\n");

    pthread_mutex_lock(&g_mutex);
    pthread_cond_signal(&g_cond_variable);
    pthread_mutex_unlock(&g_mutex);

    printf("Signal Enviado!\n");
}