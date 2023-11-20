#ifndef VAR
#define VAR

typedef struct {
	int number;
	char ** all_names;
	char * login;
} Site;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_site(int number);
char ** allocation(char ** tab);
char ** get_all_name(char ** tab);
char * get_login(char * tab);
void home_html(char ** name ,char * username, int number);

#endif
