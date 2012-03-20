#include "socket.h"

int get_socket(){
  int sock;
  if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
    perror("Can't create a socket");
    exit(1);
  }
  return sock;
}

char *get_ip(char *host){
  struct hostent *hent;
  int iplen = 15; // XXX.XXX.XXX.XXX\0
  char *ip = (char *)malloc(iplen+1);
  memset(ip, 0, iplen+1);
  if((hent = gethostbyname(host)) == NULL){
    herror("Can't get IP Address");
    exit(1);
  }

  if(inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen) == NULL){
    perror("Can't resolve host");
    exit(1);
  }
  return ip;
}
