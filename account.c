#include "account.h"
#include <sched.h>

void account_init(Account *acc, long initial){
    acc->balance = initial;
    pthread_mutex_init(&acc->lock, NULL);
}

void account_destroy(Account *acc){
    pthread_mutex_destroy(&acc->lock);
}

/* deliberately broken: read, modify, write as THREE separate steps,
   so another thread can jump in between them */
void deposit_unsafe(Account *acc, long amount){
    long temp = acc->balance;
    sched_yield(); /* forces a context switch right in the danger window */
    temp = temp + amount;
    acc->balance = temp;
}

void deposit_safe(Account *acc, long amount){
    pthread_mutex_lock(&acc->lock);
    acc->balance += amount;
    pthread_mutex_unlock(&acc->lock);
}
