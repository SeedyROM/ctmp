add_library(ctmp-async src/ctmp-async.c)

include_directories(include/)

target_link_libraries(ctmp-async PUBLIC ctmp-log)
target_include_directories(
  ctmp-async PUBLIC
  ${CTMP_LOG_INCLUDE_DIR}
)

target_link_libraries(ctmp-async PUBLIC libuv)
target_include_directories(
  ctmp-async PUBLIC
  ${LIBUV_INCLUDE_DIR}
)
