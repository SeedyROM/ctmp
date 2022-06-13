set(MODULE_NAME ctmpd)
set(SOURCES src/main.c)
add_executable(${MODULE_NAME} ${SOURCES})

target_link_libraries(${MODULE_NAME} PUBLIC ctmp-net)
target_include_directories(
  ${MODULE_NAME} PUBLIC
  ${CTMP_NET_INCLUDE_DIR}
  )

target_link_libraries(${MODULE_NAME} PUBLIC ctmp-log)
target_include_directories(
  ${MODULE_NAME} PUBLIC
  ${CTMP_LOG_INCLUDE_DIR}
)
