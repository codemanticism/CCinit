/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/types.c*/
#include "types.c"
struct option_number{
	u32 number;
	char unactivated;
};
struct option_float{
	float number;
	char unactivated;
};
struct option_number convert(char character){ //Use with caution
	struct option_number option_number_instance;
	option_number_instance.unactivated = 1;
	if((character >= '0') && (character <= '9')){
		option_number_instance.number = character - '0';
		option_number_instance.unactivated = 0;
	}
	return option_number_instance;
}
unsigned int how_many_powers_of_ten(char* string){
	u32 b = 1;
	for(u32 i = 0; string[i] != '\0'; i++){
		b *= 10;
	}
	return b;	
}
struct option_number process_integer(char* string){
	u32 number = 0;
	for(u32 i = 0; string[i] != '\0'; i++){
		number *= 10;
		struct option_number return_value = convert(string[i]);
		if(return_value.unactivated){
			struct option_number to_return;
			to_return.unactivated = 1; 
			return to_return;
		}
		number += return_value.number;
	}
	struct option_number to_return;
	to_return.unactivated = 0;
	to_return.number = number; 
	return to_return;	
}

struct option_float process_float(char* string){
	for(u32 i = 0; string[i] != '\0'; i++){
		if(string[i] == '.'){
			string[i] = '\0';
			char* position = string + i + 1;
			struct option_number return_option_number = process_integer(position);
			if(return_option_number.unactivated){
				struct option_float opt_float;
				opt_float.unactivated = 1; 
				return opt_float;
			}
			float float_ = ((return_option_number.number) / how_many_powers_of_ten(position));
			return_option_number = process_integer(string);
			if(return_option_number.unactivated){
				struct option_float opt_float;
				opt_float.unactivated = 1; 
				return opt_float;
			}
			float_ += return_option_number.number;
			string[i] = '.';
			struct option_float opt_float;
			opt_float.number = float_;
			opt_float.unactivated = 0; 
			return opt_float;
		}
	}	
	struct option_number return_float = process_integer(string);
	struct option_float opt_float;
	opt_float.unactivated = return_float.unactivated;
	opt_float.number = return_float.number;	 
	return opt_float;
}
