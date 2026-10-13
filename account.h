#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <pthread.h>

typedef struct{
    long balance;
    pthread_mutex_t lock;
} Account;

void account_init(Account *acc, long initial);
void account_destroy(Account *acc);

void deposit_unsafe(Account *acc, long amount);
void deposit_safe(Account *acc, long amount);

#endif