/*/number.c /types.c */

enum Operation{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	UNDEFINED,
};
//Works, but it actually edits what it receives, so it must be editable, which can be made using the array.
struct option_float process(char* arr, char** ptr, char* changed_ptr){
	float result = 0;
	*changed_ptr = 0;
	enum Operation op = UNDEFINED;
	printf("hey");
	for(u32 i = 0; arr[i] != '\0'; i++){
		switch(arr[i]){
			case ' ':
				break;
			case '+':
				printf("+");
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
			case ')':
				*ptr = &arr[i];
				*changed_ptr = 1;
				struct option_float flt_;
				flt_.unactivated = 0;
				flt_.number = result;
				return flt_;												
			case '(':
				char* changed_ptr = malloc(1);
				char** to_write_to = malloc(1);
				struct option_float opt_ = process(&arr[i + 1], to_write_to, changed_ptr);
				if(*changed_ptr){
					arr = *to_write_to;
					i = 0;
				}
				if(opt_.unactivated == 1){
					opt_.unactivated = 1;
					return opt_;
				}
				switch(op){
					case UNDEFINED:
						result = opt_.number;
						break;
					case ADD:
						result += opt_.number;
						break;					
					case SUBTRACT:
						result -= opt_.number;					
						break;
					case MULTIPLY:
						result *= opt_.number;					
						break;
					case DIVIDE:
						result /= opt_.number;
						break;
				}
				break;
			default:
				char* start = arr + i;
				while ((arr[i] == '.') || ((arr[i] >= '0') && (arr[i] <= '9'))){
					i++;
				}
				char character = arr[i];
				arr[i] = '\0';
				struct option_float opt = process_float(start);
				if(opt.unactivated == 1){
					return opt;
				}
				arr[i] = character;
				i--;
				printf("@ %u @", op);
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
