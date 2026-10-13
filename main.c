#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "account.h"
#include "worker.h"

#define NUM_THREADS 4
#define TRANSACTIONS_PER_THREAD 200000

int main(int argc, char *argv[]){
    int use_mutex = (argc > 1 && strcmp(argv[1], "safe") == 0);

    Account acc;
    account_init(&acc, 0);

    pthread_t threads[NUM_THREADS];
    WorkerArgs args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){
        args[i].acc = &acc;
        args[i].transactions = TRANSACTIONS_PER_THREAD;
        args[i].use_mutex = use_mutex;
        pthread_create(&threads[i], NULL, worker_thread, &args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    long expected = (long)NUM_THREADS * TRANSACTIONS_PER_THREAD;
    printf("Mode: %s\n", use_mutex ? "SAFE (mutex)" : "UNSAFE (race condition)");
    printf("Expected balance: %ld\n", expected);
    printf("Actual balance:   %ld\n", acc.balance);
    printf("%s\n", (expected == acc.balance) ? "Correct!" : "MISMATCH -- race condition occurred!");

    account_destroy(&acc);
    return 0;
}
