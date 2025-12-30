#include <stdio.h>
#include "types.c"
int main(){
	struct array my_array = create(1, 0, sizeof(unsigned int));
	struct array the_array = create(1, 1, sizeof(unsigned int));
	unsigned int* element = (unsigned int*)(the_array.ptr);
	(*element) = 1;
	for(unsigned int i = 1; i <= 32; i++){
		(*element) = (*element) * i;
		append(&my_array, the_array, sizeof(unsigned int));
	}
	for(unsigned int i = 0; i < my_array.length; i++){
		printf("%u, ", ((unsigned int*)(my_array.ptr))[i]);
	}
}
