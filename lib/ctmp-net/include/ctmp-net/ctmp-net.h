#pragma once

typedef struct {
  const char *host;
  int port;
} ctmp_net_socket;

ctmp_net_socket *ctmp_net_socket_open(const char *host, const int port);
void ctmp_net_socket_close(ctmp_net_socket *socket);