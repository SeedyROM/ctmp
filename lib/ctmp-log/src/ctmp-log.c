/**
 * @file ctmp-log.c
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "ctmp-log/ctmp-log.h"

const char *ctmp_log_level_to_string(const ctmp_log_level level)
{
  // Assert valid log level.
  assert(level >= 0 && level < 5);
  // Pretty or not pretty name.
  if (LOG_COLOR)
  {
    return ctmp_log_level_string_colored[level];
  }
  else
  {
    return ctmp_log_level_string[level];
  }
}

void _ctmp_log(const char *caller_name, int line_number, const ctmp_log_level level, const char *format, ...)
{
  // Allocate some space for our log message
  char msg[128] = {0};

  // Get the current ISO timestamp
  char timestamp[32] = {0};
  time_t now;
  time(&now);
  strftime(timestamp, 32, "%FT%TZ", gmtime(&now));

  // Write our log level and timestamp to the beginning of the message.
  snprintf(msg, 128, "%s [%s] [%s:%d] ", timestamp, ctmp_log_level_to_string(level), caller_name, line_number);
  strncat(msg, format, 128);

  // Write message to stderr for now.
  // TODO: Make this customizable.
  va_list args;
  va_start(args, format);
  vfprintf(stderr, msg, args);
  fprintf(stderr, "\n");
  va_end(args);
}