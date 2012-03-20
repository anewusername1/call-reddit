#include "http.h"

char *build_get_query(char *host, char *page){
  char *query;
  char *getpage = page;
  char *tpl = "GET /%s HTTP?1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
  if(getpage[0] == '/'){
    getpage = getpage + 1;
    fprintf(stderr, "Removing leading \"/\", converting %s to %s\n", page, getpage);
  }
  query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
  sprintf(query, tpl, getpage, host, USERAGENT);
  return query;
}
