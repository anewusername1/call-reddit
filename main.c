#include <string.h>
#include "socket.h"
#include "http.h"
void usage();

int main(int argc, char **argv){
  int sock;
  char *ip;
  char *get;
  char buf[BUFSIZ+1];
  char *host = "www.reddit.com";
  char *subreddit = "askreddit";

  if(argc > 1)
    subreddit = argv[1];

  sock = get_socket();
  ip = get_ip(host);

  fprintf(stdout, "ip is %s", ip);
  return 0;
}

void usage(){
  fprintf(stderr, "USAGE: call_reddit <subreddit>");
}
