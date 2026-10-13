#include "worker.h"

void *worker_thread(void *arg){
    WorkerArgs *wa = (WorkerArgs *)arg;
    for (long i = 0; i < wa->transactions; i++){
        if (wa->use_mutex)
            deposit_safe(wa->acc, 1);
        else
            deposit_unsafe(wa->acc, 1);
    }
    return NULL;
}
