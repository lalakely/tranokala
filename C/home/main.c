#include "head.h"

int main(){
	Site site;
	site.number = count_site(site.number);
	site.all_names = allocation(site.all_names);
	site.all_names = get_all_name(site.all_names);
	site.login = malloc(256);
	site.login = get_login(site.login);
	home_html(site.all_names,site.login, site.number);
	return 0;
}
