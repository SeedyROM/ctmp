#include <stdio.h>

#include "ctmp-net/ctmp-net.h"

int main(int argc, char **argv) {
  ctmp_net_socket *socket = ctmp_net_socket_open("localhost", 8000);
  // TODO: Do Work 
  ctmp_net_socket_close(socket);
  return 0;
}