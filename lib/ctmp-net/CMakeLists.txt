add_library(ctmp-net src/ctmp-net.c)

include_directories(include/)

target_link_libraries(ctmp-net PUBLIC ctmp-log)
target_include_directories(
  ctmp-net PUBLIC
  ${CTMP_LOG_INCLUDE_DIR}
)