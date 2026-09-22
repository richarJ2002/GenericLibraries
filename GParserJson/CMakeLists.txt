# GParserJson library - JSON format parser (custom implementation)
add_library(GParserJson
  PrivateFunctions/GParserJson_allocValue.c
  PrivateFunctions/GParserJson_clearBuffers.c
  PrivateFunctions/GParserJson_findKey.c
  PrivateFunctions/GParserJson_freeValue.c
  PrivateFunctions/GParserJson_parseString.c
  PrivateFunctions/GParserJson_parseNumber.c
  PrivateFunctions/GParserJson_parseValue.c
  PrivateFunctions/GParserJson_parseObject.c
  PrivateFunctions/GParserJson_parseArray.c
  PrivateFunctions/GParserJson_skipWhitespace.c
  PublicFunctions/GParserJson_closeParams.c
  PublicFunctions/GParserJson_loadDouble.c
  PublicFunctions/GParserJson_loadDoubleArray.c
  PublicFunctions/GParserJson_loadFloat.c
  PublicFunctions/GParserJson_loadFloatArray.c
  PublicFunctions/GParserJson_loadInt8.c
  PublicFunctions/GParserJson_loadInt.c
  PublicFunctions/GParserJson_loadIntArray.c
  PublicFunctions/GParserJson_loadParams.c
  PublicFunctions/GParserJson_loadString.c
  PublicFunctions/GParserJson_loadUInt.c
  PublicFunctions/GParserJson_loadUInt8.c
  PublicFunctions/GParserJson_loadUInt16.c
)

target_include_directories(GParserJson PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/PublicFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/PrivateFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStructs
  ${CMAKE_CURRENT_SOURCE_DIR}/ConstantDefs
)

target_link_libraries(GParserJson
  PRIVATE GConversions
)