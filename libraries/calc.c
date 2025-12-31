/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/number.c /types.c*/
#include "number.c"
enum Operation{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	UNDEFINED,
};
//works
struct option_float process(char* arr){
	u32 layer = 0;
	float result = 0;
	enum Operation op = UNDEFINED;
	for(u32 i = 0; arr[i] != '\0'; i++){
		switch(arr[i]){
			case ' ':
				break;
			case '+':
				op = ADD;
				break;
			case '-':
				op = SUBTRACT;
				break;
			case '*':
				op = MULTIPLY;
				break;
			case '/':
				op = DIVIDE;
				break;												
			case '(':
				layer += 1;
				break;
			case ')':
				if(layer == 0){
					struct option_float flt;
					flt.unactivated = 0;
					flt.number = result;
					return flt;
				}
				layer -= 1;
				break;
			default:
				char* start = arr + i;
				while ((arr[i] == '.') || ((arr[i] >= '0') && (arr[i] <= '9'))){
					i++;
				}
				char character = arr[i];
				arr[i] = '\0';
				struct option_float opt = process_float(start);
				struct option_float flt;
				if(opt.unactivated == 1){
					flt.unactivated = 1;
					return flt;
				}
				arr[i] = character;
				float the_number = opt.number;
				if(op == UNDEFINED){
					result = the_number;
				}else if(op == ADD){
					result += the_number;
				}else if(op == SUBTRACT){
					result -= the_number;
				}else if(op == MULTIPLY){
					result *= the_number;
				}else if(op == DIVIDE){
					result /= the_number;
				}
				break;				
				
		}
	}
	struct option_float flt;
	flt.unactivated = 0;
	flt.number = result;
	return flt;
}
