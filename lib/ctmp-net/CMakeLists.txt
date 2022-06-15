add_library(ctmp-net src/ctmp-net.c)

include_directories(include/)

# Logging
target_link_libraries(ctmp-net PUBLIC ctmp-log)
target_include_directories(
  ctmp-net PUBLIC
  ${CTMP_LOG_INCLUDE_DIR}
)

# libuv
target_link_libraries(ctmp-net PUBLIC libuv)
target_include_directories(
  ctmp-net PUBLIC
  ${LIBUV_INCLUDE_DIR}
)