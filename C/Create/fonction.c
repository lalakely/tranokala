#include "head.h"

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
void create_html(char * username){
    printf("Content-Type: text/html\n\n");
	printf("<!DOCTYPE html>"
    "<html lang=\"en\">"
    "<head>"
        "<meta charset=\"UTF-8\">"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
        "<title>Tranokala - Créer</title>"
        "<style>"
            "body{"
                "background-color:#202124;"
                "width: cover;"
                "height: cover;"
                "margin: 0;"
                "background-size: cover;"
                "font-family: Arial, Helvetica, sans-serif;"
            "}"
            ".div_form{"
                "display: flex;"
                "flex-direction: column;"
                "justify-content: center;"
                "margin-left: 10px;"
            "}"
            ".inp{"
                "background-color: #ffffff39;"
                "border:none;"
                "outline: none;"
                "border-radius: 10px;"
                "height: 30px;"
                "width: 200px;"
                "margin: 5px;"
                "padding: 5px;"
            "}"
            ".button{"
                "background-color: #ffffff39;"
                "border: none;"
                "outline: none;"
                "border-radius: 10px;"
                "height: 40px;"
                "width: 47vw;"
                "display: flex;"
                "margin: 10px;"
                "justify-content: center;"
                "align-items: center;"
            "}"
            "button:hover{"
                "background-color: yellowgreen;"
            "}"
            ".conteneur_form{"
                "background-color: #ffffff39;"
                "width: 787px;"
                "min-height: 787px;"
                "box-shadow:10px 0px 5px #18191b;"
                "display: inline-block;"
            "}"
            ".label{"
                "display: flex;"
                "justify-content: center;"
                "align-items: center;"
                "padding:30px;"
                "background-color: #ffffff39;"
                "width: 400px;"
                "height: 1px;"
                "border-radius: 10px;"
            "}"
            ".check{"
                "display: flex;"
                "color:#ffffff;"
            "}"
            ".div_button{"
                "display: flex;"
                "justify-content: center;"
            "}"
            ".imlogo{"
                "background: url(../photo/Tranokala_logo_principale-removebg-preview.png);"
                "width: 500px;"
                "height: 500px;"
                "position:relative;"
                "left:20px;"
            "}"
            ".div_creer{"
                "display: flex;"
            "}"
            ".div_imlogo{"
                "display: flex;"
                "justify-content: center;"
                "align-items: center;"
                "width: 700px;"
                "position:fixed;"
                "left:800px;"
                "top:150px;"
            "}"
            ".line{"
                "display: flex;"
                "flex-direction: row;"
            "}"
            "#form_2{"
                "display: none;"
            "}"
            ".before_label{"
                "margin: 15px;"
            "}"
            ".tab{"
                "margin-left: 60px;"
            "}"
            ".divip{"
                "display: flex;"
                "justify-content: center;"
                "margin: 10px;"
            "}"
            ".conteneur_label{"
                "display: flex;"
                "justify-content: center;"
            "}"
            ".nav_button{"
                "text-decoration: none;"
                "color: black;"
                "background-color: #ffffff39;"
                "height: 40px;"
                "border-radius: 100px;"
                "margin: 10px;"
                "display: flex;"
                "justify-content: center;"
                "align-items: center;"
            "}"
            ".nav_button:hover{"
                "background-color: yellowgreen;"
            "}"
            ".conteneur_nav_button{"
                "display: flex;"
                "position: fixed;"
                "left: 1000px;"
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
            ".login_cont{"
                "display: flex;"
                "justify-content: center;"
                "align-items: center;"
                "width: 300px;"
                "height: 50px;"
                "background-color: #ffffff39;"
                "position: relative;"
                "top:15px;"
                "border-radius: 30px;"
            "}"
            ".username{"
                "font-family: Arial, Helvetica, sans-serif;"
                "margin-right: 10px;"
                "color: white;"
            "}"
            ".home{"
                "border-radius: 100px;"
                "position: relative;"
                "top: 5px;"
                "height: 50px;"
                "width: 50px;"
            "}"
            ".icons_home{"
                "background: url(../photo/house-solid.svg);"
                "width: 20px;"
                "height: 20px;"
                "background-size: cover;"
                "background-position: center;"
            "}"
        "</style>"
    "</head>"
    "<body>"
        "<div class=\"conteneur_nav_button\">"
            "<a href=\"../cgi/home.cgi\" class=\"nav_button home\">"
                "<div class=\"icons_home\"></div>"
            "</a>"
            "<div class=\"login_cont\">"
                "<p class=\"username\">%s</p>"
                "<a href=\"../index.cgi\" class=\"deconnexion nav_button\">Deconnexion</a>"
           "</div>"
        "</a>"
        "</div>"
        "<div class=\"div_creer\">"
            "<div class=\"conteneur_form\">"
                "<div class=\"conteneur_label\">"
                    "<h2 class=\"label\">Configurez ici votre site</h2>"
                "</div>"
                "<form action=\"./cgi/tranokala.cgi\" method=\"get\" class=\"div_form\">"
                    "<label ><<label>VirtualHost *:80></label></label>"
                    "<div class=\"line tab\">"
                        "<label class=\"before_label\">ServerName</label>"
                        "<label class=\"before_label\">www.</label>"
                        "<input type=\"text\" name=\"a\" placeholder=\"Server Name\" class=\"inp\">"
                        "<label class=\"before_label\">.com</label>"
                        "</div>"
                    "<div class=\"line tab\">"
                        "<label class=\"before_label\">ServerAdmin</label>"
                        "<input type=\"text\" name=\"b\" placeholder=\"Server Admin\" class=\"inp\">"
                        "<label class=\"before_label\">@</label>"
                        "<input type=\"text\" name=\"c\" placeholder=\"host\" class=\"inp\">"
                    "</div>"
                    "<div class=\"line tab\">"
                    "<label class=\"before_label\">DocumentRoot</label>"
                        "<input type=\"text\" name=\"d\" placeholder=\"Document Root\" class=\"inp\">"
                    "</div>"
                    "<div class=\"line tab\">"
                        "<label class=\"before_label\">ScriptAlias</label>"
                        "<input type=\"text\" name=\"e\" placeholder=\"Script\" class=\"inp\">"
                        "<input type=\"text\" name=\"f\" class=\"inp\" placeholder=\"Alias\">"
                    "</div>"
                    "<div class=\"line tab\">"
                        "<input type=\"checkbox\" name=\"g\" id=\"form\" class=\"checkbox\">"
                        "<label class=\"before_label\"><<label>Directory</label></label>"
                        "<input type=\"text\" name=\"h\" class=\"inp form_2\" placeholder=\"Directory\">"
                        "<label class=\"before_label\">></label>"
                    "</div>"
                    "<div id=\"form_2\">"
                        "<div class=\"line tab\">"
                            "<label class=\"before_label\">Options</label>"
                            "<div class=\"check\">"
                            "   <div id=\"Ind\">"
                                    "<input type=\"text\" name=\"j\" class=\"inp\" placeholder=\"Options type\">"
                                "</div>"
                            "</div>"
                        "</div>"
                        "<div class=\"line tab\">"
                            "<label class=\"before_label\">AllowOverride</label>"
                            "<div id=\"allow_2\">"
                                "<input type=\"text\" name=\"l\" placeholder=\"type of AllowOverride\" class=\"inp\">"
                            "</div>"
                        "</div>"
                        "<div class=\"line tab\">"
                            "<label class=\"before_label\">SetHandler</label>"
                            "<div id=\"handler_2\">"
                                "<input type=\"text\" name=\"n\" placeholder=\"type for SetHandler\" class=\"inp\">"
                            "</div>"
                        "</div>"
                        "<div class=\"line tab\">"
                            "<label class=\"before_label\">AddHandler</label>"
                            "<div id=\"add_2\">"
                                "<div class=\"line\">"
                                    "<div class=\"check\">"
                                        "<input type=\"text\" name=\"p\" placeholder=\"Handler\" class=\"inp\">"
                                    "</div>"
                                    "<div class=\"check\">"
                                        "<input type=\"text\" name=\"q\" placeholder=\"Handler type\" class=\"inp\">"
                                    "</div>"
                               " </div>"
                            "</div>"
                        "</div>"
                        "<div class=\"line tab\">"
                        "<label class=\"before_label\">Require</label>"
                            "<div id=\"require_2\">"
                                "<input type=\"text\" name=\"s\" placeholder=\"Require\" class=\"inp\">"
                            "</div>"
                        "</div>"
                        "<label class=\"tab\"><<label>/Directory></label></label>"
                    "</div>"
                    "<label class=\"tab\">"
                        "ErrorLog ${APACHE_LOG_DIR}/error.log"
                    "</label>"
                    "<label class=\"tab\">"
                        "CustomLog ${APACHE_LOG_DIR}/access.log combined"
                    "</label>" 
                    "<label ><<label>/VirtualHost></label></label>"
                    "<div class=\"divip\">"
                        "<input type=\"text\" name=\"t\" placeholder=\"IP\" class=\"inp\">"
                    "</div>"
                    "<div class=\"div_button\">"
                        "<button type=\"submit\" class=\"button\">Créer</button>"
                    "</div>"
                "</form>"
            "</div>"
            "<div class=\"div_imlogo\">"
                "<div class=\"imlogo\"></div>"
            "</div>"
            "<script>"
                "const form = document.getElementById('form');"
                "const form_2 = document.getElementById('form_2');"

                "form.addEventListener('change', function() {"
                    "if (form.checked) {"
                        "form_2.style.display = 'block';"
                    "} else {"
                        "form_2.style.display = 'none';"
                    "}"
                "});"
            "</script>"
        "</div>"
    "</body>"
    "</html>"
	,username);
}
char ** split(char ** needed_data , char * data){
	int k = 0;
	int l = 0;
	for(int i = 0 ; i < strlen(data) ; i++){
		if(data[i] == '&'||data[i] == '='){
			k++;l=0;
		}
		else{
			needed_data[k][l] = data[i];l++;
		}
	}
	return needed_data;
}
char ** allocation(char ** needed_data, int a , int b){
	needed_data = malloc(a * sizeof(char *));
	for(int i = 0 ; i < a ; i++){
		needed_data[i] = malloc(b);
	}
	return needed_data;
}

void traitement_html(char ** needed_data , char * data){
	if (data) {
        	printf(
        	"<meta charset=\"UTF-8\">"
        	"<meta name=\"viewport\" content=\"width=device-width, initial-scale\">"
        	"<title>Tranokala - Traitement</title>"
        	);
		int tmp = 19;
        	printf("<html><head><title>Données GET</title></head><body>\n");
        	printf("<h1>Données GET :</h1>\n");
		printf("<p>%s</p><p>%s</p>\n",needed_data[tmp], data);
		printf("</body></html>\n");
		write_in_file(needed_data);
    	}
	else {
        	printf("<html><head><title>Erreur</title></head><body>\n");
        	printf("<h1>Erreur : Données GET non trouvées</h1>\n");
        	printf("</body></html>\n");
	}

}
char * transform_data(char * data){
	char * tmp = malloc(256);
	int l = 0;
	for(int i = 0 ; i < strlen(data) ; i++){
		if(data[i] == '%' && data[i+1] == '2' && data[i+2] == 'F'){
			tmp[l] = '/';i+=2;l++;
		}
		else if(data[i] == '%' && data[i+1] == '7' && data[i+2] == 'E'){
			tmp[l] = '~';i+=2;l++;
		}
		else if(data[i] == '+'){
			tmp[l] = ' ';l++;
		}
		else{
			tmp[l] = data[i];l++;
		}
	}
	strcpy(data,tmp);
	return data;
}
void write_in_file(char ** needed_data){
	char * file_name = malloc(256);
	file_name = create_file_name(needed_data , file_name);
	FILE * f = fopen(file_name , "a+");
	fprintf(f , "<VirtualHost *:80>\n");

	fprintf(f , "\tServerName www.%s.com\n",needed_data[1]);
	fprintf(f, "\tServerAdmin %s@%s\n",needed_data[3],needed_data[5]);
	fprintf(f , "\tDocumentRoot %s\n",needed_data[7]);
	fprintf(f,"\tScriptAlias %s %s\n",needed_data[9],needed_data[11]);
	if(strlen(needed_data[13]) != 0){
		fprintf(f,"\t<Directory %s>\n",needed_data[15]);
		if(strlen(needed_data[17]) != 0){
			fprintf(f,"\t\tOptions %s\n",needed_data[17]);
		}
		if(strlen(needed_data[19]) != 0){
			fprintf(f,"\t\tAllowOverride %s\n",needed_data[19]);
		}
		if(strlen(needed_data[21]) != 0){
			fprintf(f,"\t\tSetHandler %s\n",needed_data[21]);
		}
		if(strlen(needed_data[23]) != 0){
			fprintf(f,"\t\tAddHandler %s %s\n",needed_data[23],needed_data[33]);
		}
		if(strlen(needed_data[25]) != 0){
			fprintf(f,"\t\tRequire %s\n",needed_data[25]);
		}
		fprintf(f,"\t</Directory>\n");
	}
	fprintf(f,"\tErrorLog ${APACHE_LOG_DIR}/error.log\n");
	fprintf(f,"\tCustomLog ${APACHE_LOG_DIR}/access.log combined\n");
	fprintf(f , "</VirtualHost>");
	move_file(file_name);
}

char * create_file_name(char ** needed_data , char * file_name){
	sprintf(file_name,"%s.conf",needed_data[1]);
	char * cmd = malloc(256);
	sprintf(cmd,"touch %s",file_name);
	system(cmd);
	return file_name;
}

void move_file(char * file_name){
	char * tmp = malloc(256);
	sprintf(tmp,"mv %s /etc/apache2/sites-available/",file_name);
	system(tmp);
	sprintf(tmp,"ln -s /etc/apache2/sites-available/%s /etc/apache2/sites-enabled/",file_name);
	system(tmp);
	sprintf(tmp,"sudo systemctl reload apache2");
	system(tmp);
}
