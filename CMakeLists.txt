cmake_minimum_required(VERSION 3.18)
project(ctmp)

# C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

# Where the code is stored
set(CTMP_LIB_DIR lib)
set(CTMP_BIN_DIR bin)

# Library includes
SET(CTMP_NET_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/${CTMP_LIB_DIR}/ctmp-net/include")
SET(CTMP_LOG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/${CTMP_LIB_DIR}/ctmp-log/include")
SET(CTMP_ASYNC_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/${CTMP_LIB_DIR}/ctmp-async/include")
SET(LIBUV_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/${CTMP_LIB_DIR}/libuv/include")

# Libraries
add_subdirectory(${CTMP_LIB_DIR}/ctmp-net)
add_subdirectory(${CTMP_LIB_DIR}/ctmp-log)
add_subdirectory(${CTMP_LIB_DIR}/ctmp-async)
add_subdirectory(${CTMP_LIB_DIR}/libuv)

# The main daemon
add_subdirectory(${CTMP_BIN_DIR}/ctmpd)
