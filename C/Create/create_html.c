#include "head.h"

int main(){
	char * username = malloc(256);
	username = get_login(username);
	create_html(username);
	return 0;
}
