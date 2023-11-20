#include "head.h"

int count_site(int number){
	system("ls -1 /etc/apache2/sites-available/|wc -l > ../files/tmp");
	FILE * f = fopen("../files/tmp","r+");
	char * tmp = malloc(10);
	fgets(tmp , 9 , f);
	number = atoi(tmp);
	fclose(f);
	return number;
}
char ** get_all_name(char ** tab){
	system("ls -1 /etc/apache2/sites-available/ > ../files/tmp");
	int i = 0;
	FILE * f = fopen("../files/tmp" , "r+");
	while(fgets(tab[i] , 255 , f) != NULL){i++;}
	fclose(f);
	return tab;
}
char ** allocation(char ** tab){
	tab = malloc(256 * sizeof(char *));
	for(int i = 0 ; i < 256 ; i++){
		tab[i] = malloc(256);
	}
	return tab;
}
char * get_login(char * tab){
	char * tmp = malloc(256);
	FILE * f = fopen("../files/login","r+");
	while(fgets(tmp , 255 , f)!=NULL){}
	int log = 0;
	sscanf(tmp , "%99[^:]:%d",tab , &log);
	if(log == 0){
		printf("Location: http://www.tranokala.com/index.cgi\n\n");
	}
	return tab;
}
void home_html(char ** name ,char * username, int number){
	printf("Content-Type: text/html\n\n");
	printf(
	"<!DOCTYPE html>"
	"<html lang=\"en\">"
	"<head>"
		"<meta charset=\"UTF-8\">"
		"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
		"<title>Tranokala - Home</title>"
		"<style>"
			"body{"
				"margin: 0;"
				"background-color: #202124;"
				"font-family: Arial, Helvetica, sans-serif;"
			"}"
			".nav{"
				"background-color: #ffffff39;"
				"height: 80px;"
				"width: cover;"
				"display: flex;"
			"}"
			".logo{"
				"background: url(../photo/tranokala_label_only-removebg-preview.png);"
				"background-size: cover;"
				"background-position: center;"
				"height: 60px;"
				"width: 110px;"
				"position: relative;"
				"top: 5px;"
				"left: 5px;"
			"}"
			".inp{"
				"background-color: #ffffff39;"
				"border: none;"
				"outline: none;"
				"width: 500px;"
				"height: 30px;"
				"margin-top: 15px;"
				"margin-left: 200px;"
				"padding: 10px;"
				"border-radius: 30px;"
			"}"
			".button{"
				"width: 100px;"
				"height: 50px;"
				"outline: none;"
				"border: none;"
				"background-color: #ffffff91;"
				"position: relative;"
				"left: 10px;"
				"border-radius: 30px;"
			"}"
			".button:hover{"
				"background-color: yellowgreen;"
			"}"
			".login_cont{"
				"display: flex;"
				"justify-content: center;"
				"align-items: center;"
				"width: 300px;"
				"height: 50px;"
				"background-color: #ffffff39;"
				"position: relative;"
				"left: 200px;"
				"top:15px;"
				"border-radius: 30px;"
			"}"
			".deconnexion{"
				"font-family: Arial, Helvetica, sans-serif;"
				"font-size: 16px;"
				"text-decoration: none;"
				"display: flex;"
				"align-items: center;"
				"justify-content: center;"
				"color: black;"
				"background-color: yellowgreen;"
				"width: 130px;"
				"height: 40px;"
				"border-radius: 30px;"
			"}"
			".deconnexion:hover{"
				"background-color: red;"
				"font-weight: bold;"
			"}"
			".username{"
				"font-family: Arial, Helvetica, sans-serif;"
				"margin-right: 10px;"
				"color: white;"
			"}"
			".tab{"
				"display: flex;"
				"justify-content: center;"
				"align-items: center;"
				"position: relative;"
				"top: 20px;"
			"}"
			"table{"
				"border-spacing: 10px;"
			"}"
			"td{"
				"background-color: #ffffff25;"
				"margin: 20px;"
				"width: 200px;"
				"height: 100px;"
				"padding: 20px;"
				"border-radius: 30px;"
				"text-align: center;"
			"}"
			".nouveau{"
				"font-family: Arial, Helvetica, sans-serif;"
				"font-size: 50px;"
				"font-weight: bold;"
				"color: yellowgreen;"
				"text-decoration: none;"
			"}"
			".site{"
				"font-family: Arial, Helvetica, sans-serif;"
				"font-size: 16px;"
				"text-decoration: none;"
				"display: flex;"
				"align-items: center;"
				"justify-content: center;"
				"color: black;"
				"background-color: #ffffff39;"
				"width: 200px;"
				"height: 40px;"
				"border-radius: 20px;"
				"position: relative;"
				"bottom: 15px;"
			"}"
			".site:hover{"
				"background-color: yellowgreen;"
			"}"
			".vues{"
				"color: white;"
			"}"
		"</style>"
	"</head>"
	"<body>"
		"<div class=\"nav\">"
			"<a href=\"../cgi/home.cgi\">"
				"<div class=\"logo\"></div>"
			"</a>"
			"<form action=\"../cgi/\">"
				"<input type=\"text\" placeholder=\"rechercher\" name=\"search\" class=\"inp\">"
				"<button type=\"submit\" class=\"button\">Rechercher</button>"
			"</form>"
			"<div class=\"login_cont\">"
				"<p class=\"username\">%s</p>"
				"<a href=\"../index.cgi\" class=\"deconnexion\">Deconnexion</a>"
			"</div>"
		"</div>"
		"<div class=\"display_sites\">"
			"<div class=\"tab\">"
				"<table>",username);
				int j = 0;
				for(int i = 0 ; i < number/3 + 1; i++){
					printf("<tr>");
					for(int k = 0 ; k < 3 ; k++){
						if(j == number){break;}
						if(j == 0){
							printf("<td>"
								"<a href=\"../cgi/html_create.cgi\" class=\"nouveau\">+</a>"
							"</td>");
						}
						else{
							if(strcmp(name[j] , "default-ssl.conf") == 10){j++;}
							printf("<td>"
								"<a href=\"../cgi/\" class=\"site\">%s</a>"
								"<p class=\"vues\">vues : 12</p>"
							"</td>",name[j]);
						}
						j++;
					}
					if(j == number){break;}
					printf("</tr>");
				}
				printf("</table>"
			"</div>"
		"</div>"
	"</body>"
	"</html>"
	);
}
