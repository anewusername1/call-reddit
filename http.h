#ifndef HTTP_H
#define HTTP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USERAGENT "REDDITBOT 1.0"

char *build_get_query(char *host, char *page);
char *get_page();

#endif
