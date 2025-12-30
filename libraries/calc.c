/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/number.c /types.c*/
#include "number.c"
#include "types.c"
enum Operation{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	UNDEFINED,
};
struct option_float process(char* characters){
	u32 layer = 0;
	float result = 0;
	enum Operation op = UNDEFINED;
	for(u32 i = 0; characters[i] != '\0'; i++){
		switch(characters[i]){
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
				char* start = characters + i;
				while ((characters[i] == '.') || ((characters[i] >= '0') && (characters[i] <= '9'))){
					i++;
				}
				char character = characters[i];
				characters[i] = '\0';
				struct option_float opt = process_float(start);
				struct option_float flt;
				if(opt.unactivated == 1){
					flt.unactivated = 1;
					return flt;
				}
				characters[i] = character;
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
				
		}
	}
	struct option_float flt;
	flt.unactivated = 0;
	flt.number = result;
	return flt;
}
