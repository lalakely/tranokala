#include "head.h"

int main(){
	int error = 0;
	char * data = malloc(257);
	char ** needed_data  = allocation(needed_data);
	char * username = malloc(256);
	char * password = malloc(256);
	data = get_data(data);
	needed_data = split_data(needed_data , data);
	strcpy(username , needed_data[0]);
	strcpy(password , needed_data[1]);
	error = compare(error , username , password);
	redirection(error , data , username , password);
	return 0;
}
