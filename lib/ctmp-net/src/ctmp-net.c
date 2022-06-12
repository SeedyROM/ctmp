#include <stdlib.h>
#include <stdio.h>

#include "ctmp-net/ctmp-net.h"

ctmp_net_socket *ctmp_net_socket_open(const char *host, const int port) {
  ctmp_net_socket *socket = malloc(sizeof(ctmp_net_socket));

  socket->host = host;
  socket->port = port;
  
  printf("ctmp-net-socket opened at %s:%d\n", socket->host, socket->port);
  return socket;
}

void ctmp_net_socket_close(ctmp_net_socket *socket) {
  printf("ctmp-net-socket closed at %s:%d\n", socket->host, socket->port);
  free(socket);
}