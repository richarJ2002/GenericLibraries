add_library(GUtilities
  DataStructs/GUtilities_stateStruct.c
  PrivateFunctions/GUtilities_sigintHandle.c
  PublicFunctions/GUtilities_init.c
)

target_include_directories(GUtilities PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/PublicFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/PrivateFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStructs
)

target_link_libraries(GUtilities
  PRIVATE GParserIni GConversions
)
