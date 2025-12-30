/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/types.c*/
#include <stdio.h>
#include <time.h>
#include "types.c"

int generate_random_number(unsigned int limit){
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
    printf("%09ld", ts.tv_nsec * 100);
    unsigned int factorial = 1;
    for(unsigned int i = 2; i < (ts.tv_nsec); i++){
    	factorial *= i;
    }
    return factorial % limit;
}
