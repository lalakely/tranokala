#include "head.h"

int main() {
    // En-tête de la réponse HTTP
    printf("Content-Type: text/html\n\n");

    // Récupère les données GET à partir de la variable d'environnement QUERY_STRING
    	char *data = getenv("QUERY_STRING");
	char ** needed_data = allocation(needed_data , 256 , 256);
	data = transform_data(data);
	needed_data = split(needed_data , data);
	traitement_html(needed_data,data);

    return 0;
}
