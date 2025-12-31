/**/
#include <stdio.h>
#include <time.h>
#include <stdint.h>
// Works.

int generate_random_number(unsigned int limit){
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    uint64_t int_ = (uint64_t)ts.tv_nsec * 1000000000000ULL;
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
