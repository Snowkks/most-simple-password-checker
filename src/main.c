#include <stdio.h>

const int require_lenght = 8;

int valid_lenght = 0;
int have_number = 0;
int have_uppercase = 0;
int have_lowercase = 0;
int have_symbol = 0;

int main(int argc, char* argv[])
{
	if( argc <= 0 ){
		printf("usage : passcheck password[lenght]");
		return 1;
	}

	char *password = argv[1];

	int lenght = 0;

	while(password[lenght] != '\0'){
		if(password[lenght] >= 'A' && password[lenght] <= 'Z'){
			have_uppercase = 1;
		}
		else if (password[lenght] >= '0' && password[lenght] <= '9') {
			have_number = 1;
		}
		else if (password[lenght] >= 'a' && password[lenght] <= 'z') {
			have_lowercase = 1;
		}
		else{
			have_symbol = 1;
		}

		lenght++;
	}

	if(lenght + 1 >= require_lenght){
		valid_lenght = 1;
	}
	
	if(valid_lenght){
		printf("Lenght : OK\n");
	}else{
		printf("Lenght : No\n");
	}

	if(have_lowercase){
		printf("Lowercase : OK\n");
	}else{
		printf("Lowercase : No\n");
	}

	if(have_uppercase){
		printf("Uppercase : OK\n");
	}else{
		printf("Uppercase : No\n");
	}

	if(have_number){
		printf("Number : OK\n");
	}else{
		printf("Number : No\n");
	}

	if(have_symbol){
		printf("Symbol : OK\n");
	}else{
		printf("Symbol : No\n");
	}

	if( valid_lenght && have_lowercase && have_number && have_uppercase && have_symbol){
		printf("Result : Strong\n");
	}
	else{
		printf("Result : Weak\n");
	}

	return 0;
}
