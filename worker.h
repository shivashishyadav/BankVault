#ifndef WORKER_H
#define WORKER_H

#include "account.h"

typedef struct{
    Account *acc;
    long transactions;
    int use_mutex;
} WorkerArgs;

void *worker_thread(void *arg);

#endif
