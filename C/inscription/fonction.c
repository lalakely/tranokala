#include "head.h"

char * get_data(char * data){
	char * tmp_data = getenv("CONTENT_LENGTH");
	int length  = 0;

	if(tmp_data == NULL){
		 printf("Content-Type: text/html\n\n");
        	printf("<p>Error: CONTENT_LENGTH not set.</p>");
        	exit(1);
	}
	length = atoi(tmp_data);
	fread(data , 1 , length , stdin);
	data[length] = '\0';
	return data;
}
char ** split_data(char ** needed_data , char * data){
	sscanf(data , "Username=%99[^&]&Password=%s" ,needed_data[0],needed_data[1] );
	return needed_data;
}
void write_in_file(char * username , char * password){
	FILE * f = fopen("../files/connexion" , "a+");
	fprintf(f , "%s:%s\n" , username , password);
	fclose(f);
}
int compare(int error , char * username , char * password){
	FILE * f = fopen("../files/connexion","r+");
	char ** tmp = allocation(tmp);
	int i = 0;
	while(fgets(tmp[i] , 255 , f) != NULL){
		i++;
	}
	fclose(f);
	char * tmp_login = malloc(256);
	char * tmp_passwd = malloc(256);
	for(int i = 0 ; i < 255 ; i++){
		if(strlen(username) < 8){error = 3;break;} // error = 3 pour username inferieur à 8
		if(strlen(password) < 8){error=2;break;} // mot de passe de taille inferieur à 8
		if(strlen(username) < 8 && strlen(password) < 8){error = 4 ; break;} //les deux inférieur à 8
		if(strcmp(tmp_passwd , password) == 0 && strcmp(tmp_login , username) == 0){error = 0;break;} //error = 0 pour forme valide avec noueau utilisateur
		strcpy(tmp_login , "");
		strcpy(tmp_passwd , "");
		sscanf(tmp[i] ,"%99[^:]:%s",tmp_login , tmp_passwd);
		if(strcmp(tmp_login , username) == 0){error = 1;break;} //error = 1 pour utilisateur déja existant
		if(strlen(tmp[i]) == 0){break;}
	}
	return error;
}
char ** allocation(char ** tab){
	tab = malloc(256 * sizeof(char*));
	for(int i = 0 ; i < 256 ; i++){
		tab[i] = malloc(256);
	}
	return tab;
}
void redirection(int error ,char * data, char * username , char * password){
	if(error == 0){
		write_in_file(username , password);
	        printf("Location: http://www.tranokala.com/Acceuil.html\n\n");
	}
	else{
		inscription_html(error);
	}
}
void inscription_html(int error){
	printf("Content-Type: text/html\n\n");
	printf(
	"<!DOCTYPE html>"
	"<html lang=\"en\">"
	"<head>"
		"<meta charset=\"UTF-8\">"
		"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
		"<title>Tranokala - Inscription</title>"
		"<style>"
			"body{"
				"margin: 0;"
				"padding: 0;"
				"background-color: #202124;"
				"font-family: Arial, Helvetica, sans-serif;"
			"}"
			".div_form{"
				"background-color: #ffffff39;"
				"border-radius: 10px;"
				"display: flex;"
				"justify-content: center;"
				"align-items: center;"
				"flex-direction: column;"
				"width: 500px;"
				"height: 500px;"
				"margin-top: 200px;"
				"margin-left: 150px;"
				"margin-right: 150px;"
				"box-shadow: 0px 5px 20px black;"
			"}"
			".form{"
				"display: flex;"
				"flex-direction: column;"
				"align-items: center;"
			"}"
			".inp{"
				"background-color: #ffffff39;"
				"border:none;"
				"outline: none;"
				"border-radius: 10px;"
				"height: 30px;"
				"width: 300px;"
				"margin: 5px;"
				"padding: 5px;"
				"z-index: 10;"
			"}"
			".submit{"
				"height: 40px;"
				"width: 280px;"
				"border-radius: 10px;"
				"margin: 20px;"
				"background-color: #ffffff39;"
				"border:none;"
				"outline: none;"
			"}"
			".submit:hover{"
				"background-color: yellowgreen;"
			"}"
			".in_line{"
				"display: flex;"
			"}"
			".inscription{"
				"text-decoration: none;"
				"color: black;"
				"font-weight: bold;"
			"}"
			".logo{"
				"background: url(../photo/Tranokala_logo_principale-removebg-preview.png);"
				"position: relative;"
				"top: 150px;"
				"left: 150px;"
				"width: 500px;"
				"height: 500px;"
			"}"
			".left{"
				"background-color: #ffffff39;"
				"width: 750px;"
				"height: 788px;"
				"box-shadow: 0 -5px 10px black;"
			"}"
			".all{"
				"display: flex;"
				"flex-direction: row;"
			"}"
			".connexion{"
				"background:url(../photo/inscription-removebg-preview.png);"
				"width: 180px;"
				"height: 60px;"
				"background-size: cover;"
			"}"
			".error{"
				"color:red;"
				"font-size:10px;"
			"}"
		"</style>"
	"</head>"
	"<body>"
		"<div class=\"all\">"
			"<div class=\"left\">"
				"<div class=\"logo\"></div>"
			"</div>"
			"<div class=\"div_form\">"
				"<form action=\"../cgi/inscription.cgi\" class=\"form\" method=\"post\">"
					"<div class=\"connexion\"></div>");
					printf("<input type=\"text\" placeholder=\"Username\" class=\"inp\" name=\"Username\">");
					if(error == 3 || error == 4){printf("<p class=\"error\">Username trop court</p>");}
					if(error == 1){printf("<p class=\"error\">Utilisateur déja existant</p>");}					if(error == 2 || error == 4){printf("<p class=\"error\">Mot de passe trop court</p>");}
					printf("<button type=\"submit\" class=\"submit\">Inscription</button>"
				"</form>");
				printf("<div class=\"in_line\">"
					"<label >Avez vous déja un compte ? </label>"
					"<a href=\"../Acceuil.html\" class=\"inscription\">Se Connecter</a>"
				"</div>"
			"</div>"
		"</div>"
	"</body>"
	"</html>"
	);
}
