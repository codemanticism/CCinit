#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
typedef union type_ type_;
typedef struct array_type array_type;
typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
struct array{
	void* ptr;
	unsigned int length;
	unsigned int capacity;
};
struct repeat{
	unsigned int length;
	unsigned int number;	
};
//works
unsigned int get_power_of_two(unsigned int integer){
	unsigned int power = 1;
	while(power < integer){
		power *= 2;
	}
	return power;
}
//works
struct array create(unsigned int starting_capacity, unsigned int starting_length, unsigned int size_of){
	struct array array_var;
	array_var.length = starting_length;
	array_var.capacity = starting_capacity;
	array_var.ptr = malloc(size_of * starting_capacity);
	return array_var;
}
//works
void append(struct array* arr1, struct array arr2, unsigned int size_of){
	struct array arr = *arr1;
	const unsigned int new_length = arr.length + arr2.length;
	void* ptr = arr.ptr;
	if(new_length > arr.capacity){
		unsigned int new_capacity = get_power_of_two(new_length);
		void* new_ptr = malloc(size_of * new_capacity);
		if (!new_ptr) {
		    // allocation failed — keep old array intact
		    return; // or handle error
		}

		memcpy(new_ptr, arr.ptr, arr.length * size_of);
		free(arr.ptr);
		ptr = new_ptr;
		arr1->capacity = new_capacity;
	}
	memcpy((u8*)ptr + (arr.length * size_of), (u8*)arr2.ptr, arr2.length * size_of);
	(*arr1).length = new_length;
	(*arr1).ptr = ptr; 
}
//works
void delete(struct array arr, unsigned int index, unsigned int size_of){
	memcpy((u8*)arr.ptr + (index * size_of), (u8*)arr.ptr + ((index + 1) * size_of), (arr.length - index - 1) * size_of);
}
