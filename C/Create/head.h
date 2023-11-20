#ifndef VAR
#define VAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** split(char ** needed_data , char * data);
char ** allocation(char ** needed_data , int a , int b);
void traitement_html(char ** needed_data,char *data);
void write_in_file(char ** needed_data);
char * create_file_name(char ** needed_data,char * file_name);
char * transform_data(char * data);
void move_file(char * file_name);
char * get_login(char * tab);
void create_html(char * username);

#endif 
