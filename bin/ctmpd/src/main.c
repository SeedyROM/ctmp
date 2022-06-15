#include <stdio.h>

#include "ctmp-net/ctmp-net.h"
#include "ctmp-log/ctmp-log.h"

static const char *CTMP_BANNER_ASCII_ART =
    "\n"
    "   ▄████▄  ▄▄▄█████▓ ███▄ ▄███▓ ██▓███  \n"
    "  ▒██▀ ▀█  ▓  ██▒ ▓▒▓██▒▀█▀ ██▒▓██░  ██▒\n"
    "  ▒▓█    ▄ ▒ ▓██░ ▒░▓██    ▓██░▓██░ ██▓▒\n"
    "  ▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██    ▒██ ▒██▄█▓▒ ▒\n"
    "  ▒ ▓███▀ ░  ▒██▒ ░ ▒██▒   ░██▒▒██▒ ░  ░\n"
    "  ░ ░▒ ▒  ░  ▒ ░░   ░ ▒░   ░  ░▒▓▒░ ░  ░\n"
    "  ░  ▒       ░    ░  ░      ░░▒ ░       \n"
    "             ░      ░      ░   ░        \n"
    "                                        \n";

int main(int argc, char **argv)
{
  printf("%s", CTMP_BANNER_ASCII_ART);
  ctmp_log_info("Welcome to ctmpd");

  ctmp_net_socket *socket = ctmp_net_socket_open("localhost", 80);

  ctmp_net_socket_close(socket);

  ctmp_log_info("Shutting down");
  return 0;
}