/**
 * @file ctmp-net.h
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct _ctmp_net_socket_addr
{
  const char *host;
  int port;
} ctmp_net_socket_addr;

/**
 * @brief TCP socket abstraction.
 *
 */
typedef struct _ctmp_net_socket
{
  ctmp_net_socket_addr addr;
  int descriptor;
  struct sockaddr_in socket;
} ctmp_net_socket;

/**
 * @brief Open a TCP socket.
 *
 * @param host
 * @param port
 * @return ctmp_net_socket*
 */
ctmp_net_socket *ctmp_net_socket_open(const char *host, const int port);

/**
 * @brief Close a tcp socket.
 *
 * @param socket
 */
void ctmp_net_socket_close(ctmp_net_socket *socket);