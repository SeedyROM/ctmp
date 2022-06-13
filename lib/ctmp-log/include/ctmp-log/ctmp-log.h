/**
 * @file ctmp-log.h
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string.h>
#include <stdbool.h>

// Global logging variables
#define LOG_LEVEL CTMP_LOG_LEVEL_INFO
#define LOG_COLOR true

// Filename helpers
static inline const char *strfnchr(const char *s, int c)
{
  const char *found = s;
  while (*(s++))
  {
    if (*s == c)
      found = s;
  }
  if (found != s)
    return found + 1;
  return s;
}
#define __FILE_NAME__ strfnchr(__FILE__, '/')

/**
 * @brief Log wrapper macro.
 *
 */
#define ctmp_log(level, format, ...) _ctmp_log(__FILE_NAME__, __LINE__, level, format, ##__VA_ARGS__);

/**
 * @brief Log wrapper macro for `trace`.
 *
 */
#define ctmp_log_trace(format, ...) ctmp_log(CTMP_LOG_LEVEL_TRACE, format, ##__VA_ARGS__)

/**
 * @brief Log wrapper macro for `debug`.
 *
 */
#define ctmp_log_debug(format, ...) ctmp_log(CTMP_LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)

/**
 * @brief Log wrapper macro for `info`.
 *
 */
#define ctmp_log_info(format, ...) ctmp_log(CTMP_LOG_LEVEL_INFO, format, ##__VA_ARGS__)

/**
 * @brief Log wrapper macro for `warn`.
 *
 */
#define ctmp_log_warn(format, ...) ctmp_log(CTMP_LOG_LEVEL_WARN, format, ##__VA_ARGS__)

/**
 * @brief Log wrapper macro for `error`.
 *
 */
#define ctmp_log_error(format, ...) ctmp_log(CTMP_LOG_LEVEL_ERROR, format, ##__VA_ARGS__)

/**
 * @brief Various levels to log at.
 *
 */
typedef enum _ctmp_log_level
{
  CTMP_LOG_LEVEL_TRACE = 0,
  CTMP_LOG_LEVEL_DEBUG = 1,
  CTMP_LOG_LEVEL_INFO = 2,
  CTMP_LOG_LEVEL_WARN = 3,
  CTMP_LOG_LEVEL_ERROR = 4,
} ctmp_log_level;

/**
 * @brief A map of the ctmp_log_level enum to a string.
 *
 */
static const char *ctmp_log_level_string[5] = {"TRACE", "DEBUG", "INFO", "WARN", "ERROR"};

/**
 * @brief A map of the ctmp_log_level enum to a string with colors.
 *
 */
static const char *ctmp_log_level_string_colored[5] = {"\e[34;1mTRACE\e[0m", "\e[36;1mDEBUG\e[0m", "\e[1;32mINFO\e[0m", "\e[33;1mWARN\e[0m", "\e[31;1mERROR\e[0m"};

/**
 * @brief Convert a log level to a human readable string.
 *
 * @param level
 * @return const char*
 */
const char *ctmp_log_level_to_string(const ctmp_log_level level);

/**
 * @brief Log a message at a specified level.
 *
 * @param format
 * @param args
 */
void _ctmp_log(const char *caller_name, int line_number, const ctmp_log_level level, const char *format, ...);
