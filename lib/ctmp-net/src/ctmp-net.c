/**
 * @file ctmp-net.c
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "ctmp-net/ctmp-net.h"
#include "ctmp-log/ctmp-log.h"

ctmp_net_socket *ctmp_net_socket_open(const char *host, const int port)
{
  ctmp_net_socket *self = malloc(sizeof(ctmp_net_socket));

  ctmp_net_socket_addr socket_addr = {.host = host, .port = port};
  self->addr = socket_addr;

  self->descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (self->descriptor == -1)
    goto ctmp_net_socket_open_error;

  ctmp_log_info("Socket opened at %s:%d", self->addr.host, self->addr.port);
  return self;

ctmp_net_socket_open_error:
  ctmp_log_error("Failed to open socket at %s:%d", self->addr.host, self->addr.port);
  return NULL;
}

void ctmp_net_socket_close(ctmp_net_socket *self)
{
  ctmp_log_info("Socket closed at %s:%d", self->addr.host, self->addr.port);
  free(self);
}