#include "head.h"

void deconnexion(){
	FILE * f = fopen("./files/login","r+");
	char * tmp_1 = malloc(256);
	char * tmp_2 = malloc(256);
	while(fgets(tmp_1 , 255 , f) != NULL){}
	fclose(f);
	int log = 0;
	sscanf(tmp_1 , "%99[^:]:%d",tmp_2 , &log);

	FILE * f2 = fopen("./files/login" , "a+");
	fprintf(f2 , "%s:0\n",tmp_2);
	fclose(f2);
}
void read_html(){
	printf("Content-Type: text/html\n\n");
	FILE * f = fopen("./htmls/connexion.html","r+");
	char * tmp = malloc(256);
	while(fgets(tmp , 255 , f) != NULL){
		printf("%s",tmp);
	}
}
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
	sscanf(data , "username=%99[^&]&password=%s" ,needed_data[0],needed_data[1] );
	return needed_data;
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
		if(strcmp(tmp_passwd , password) == 0 && strcmp(tmp_login , username) == 0){error = 0;break;} // Tous valide
		strcpy(tmp_login , "");
		strcpy(tmp_passwd , "");
		sscanf(tmp[i] ,"%99[^:]:%s",tmp_login , tmp_passwd);
		if(strcmp(tmp_login , username) != 0){error = 1;} //Nom d'utilisateur non-existant error = 1
 		if(strcmp(tmp_login , username) == 0 && strcmp(tmp_passwd , password) != 0){error = 2;break;} // mot de passe invalide error = 2
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
void redirection(int error , char * data , char * username , char * password){
	if(error == 0){
		get_in_net(username , password);
		printf("Location: http://www.tranokala.com/cgi/home.cgi\n\n");
	}
	else{
		connexion_html(error);
	}
}
void get_in_net(char * username , char * password){
	FILE * f = fopen("../files/login","a+");
	fprintf(f , "%s:1\n",username);
	fclose(f);
}
void connexion_html(int error){
	printf("Content-Type: text/html\n\n");
printf(
"<!DOCTYPE html>"
"<html lang=\"en\">"
"<head>"
    "<meta charset=\"UTF-8\">"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    "<title>Tranokala - Connexion</title>"
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
            "background:url(../photo/connexion-removebg-preview.png);"
            "width: 300px;"
            "height: 100px;"
        "}"
	".error{"
		"color:red;"
		"font-size:10px;"
	"}"
    "</style>"
"</head>"
"<body>"
    "<div class=\"all\">"
        "<div class=\"div_form\">"
            "<form action=\"../cgi/connexion.cgi\" class=\"form\" method=\"post\">"
                "<div class=\"connexion\"></div>");
                printf("<input type=\"text\" placeholder=\"Username\" class=\"inp\" name=\"username\">");
		if(error == 1){printf("<p class=\"error\">Utilisateur inexistant</p>");}
                printf("<input type=\"password\" placeholder=\"Password\" class=\"inp\" name=\"password\">");
                if(error == 2){printf("<p class=\"error\">Mot de passe invalide</p>");}
		printf("<button type=\"submit\" class=\"submit\">Connexion</button>");
            printf("</form>"
            "<div class=\"in_line\">"
                "<label >Avez vous déja un compte ? </label>"
                "<a href=\"../htmls/inscription.html\" class=\"inscription\">S'inscrire</a>"
            "</div>"
        "</div>"
        "<div class=\"left\">"
            "<div class=\"logo\"></div>"
        "</div>"
    "</div>"
"</body>"
"</html>"
	);

}
