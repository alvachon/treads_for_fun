#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//gcc -g -pthread intro.c
/* Parallel programming */

void    *routine()
{
    printf("Starting parallel ...\n");
    sleep(3);
    printf("Sleep checking to see if steps are done in the same time\n");   
}

int main(int ac, char **av)
{
    pthread_t   t1, t2;
    /* 1. ptr to t1 var,
     * 2. attribute of T1, but ptr, can refer as NULL,
     * 3. ref. to actual function,
     * 4. argument of the function (since not, then put NULL).*/
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
      return (1);
      /*
      * NOTE : function should return o if no error */
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
      return (2);
    /* Similar to wait(),
     * 1. ref to t1 var,
     * 2. what phtread_create ef function return. */
    if (pthread_join(t1, NULL) != 0)
      return (3);
    if (pthread_join(t2, NULL) != 0)
      return (4);
    return (0);
}
