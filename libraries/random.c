/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/types.c*/
#include <stdio.h>
#include <time.h>
// works
int generate_random_number(unsigned int limit){
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
    printf("-%ld", ts.tv_nsec);
    unsigned int int_ = ts.tv_nsec * 1000000000000;
    unsigned int result = 0;
	for(; int_ > 0; int_ /= 10){
	    unsigned long factorial = 1;
	    for(unsigned int i = 2; i < (int_ % 10); i++){
	    	factorial *= i;
	    }
	    result *= 10;
	    result += (factorial % 10);
	}
	return result % limit;
}
