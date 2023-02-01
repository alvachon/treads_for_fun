#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N_ACCOUNTS      10
#define N_TREADS        20
#define N_ROUNDS        10000
#define INIT_BALANCE    100

struct  account
{
    long balance;
} accts[N_ACCOUNTS];

int rand_range(int N)
{
    return (int)((double)rand() / ((double)RAND_MAX + 1) * N);
}

void    *disburse(void *arg)
{
    size_t  i;
    size_t  from;
    size_t  to;
    long    payment;

    (void)arg;
    i = 0;
    while (i < N_ROUNDS)
    {
        from = rand_range(N_ACCOUNTS);
        do{
            to = rand_range(N_ACCOUNTS);
        } while (to == from);
        if (accts[from].balance > 0)
        {
            payment = 1 + rand_range(accts[from].balance);
            accts[from].balance -= payment;
            accts[to].balance += payment;
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    size_t      i;
    long        total;
    pthread_t   accts[N_TREADS];

    i = 0;
    srand(time(NULL));
    while (i < N_ACCOUNTS)
    {
        accts[i].balance = INIT_BALANCE;
        i++;
    }
    printf("Initial money in system : %d\n", N_ACCOUNTS * INIT_BALANCE);
    //start threads
    i = 0;
    while (i < N_TREADS)
    {
        pthread_create(&ts[i], NULL, disburse, NULL);
        i++;
    }
    //wait for all threads to finish w/ handles of phtread_creates();
    i = 0;
    while (i < N_TREADS)
    {
        pthread_join(ts[i].balance);
        i++;
    }
    i = 0;
    while (i < N_TREADS)
    {
        total += accts[i].balance;
        i++;
    }
    printf("Final money in system : %ld\n", total);
}

