#ifndef VAR
#define VAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_data(char * data);
void write_in_file(char * username , char * password);
char ** split_data(char ** needed_data , char * data);
char ** allocation(char ** tab);
int compare(int error , char * username , char * password);
void redirection(int error , char * data , char * username , char * password);
void connexion_html(int error);
void get_in_net(char * username , char * password);
void deconnexion();
void read_html();

#endif
