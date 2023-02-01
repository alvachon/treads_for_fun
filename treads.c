#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *myturn(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("My turn!\n");
    }
    return (NULL);
}

void yourturn()
{
    while (2)
    {
        sleep(1);
        printf("your Turn!\n");
    }
}

int main()
{
    pthread_t new;

    pthread_create(&new , NULL, myturn, NULL);
    //myturn();
    yourturn();
}
