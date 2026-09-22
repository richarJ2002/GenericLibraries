# GParserYaml library - YAML format parser (custom implementation)
add_library(GParserYaml
  PrivateFunctions/GParserYaml_allocValue.c
  PrivateFunctions/GParserYaml_clearBuffers.c
  PrivateFunctions/GParserYaml_findKey.c
  PrivateFunctions/GParserYaml_freeValue.c
  PrivateFunctions/GParserYaml_getIndent.c
  PrivateFunctions/GParserYaml_parseString.c
  PrivateFunctions/GParserYaml_parseNumber.c
  PrivateFunctions/GParserYaml_parseValue.c
  PrivateFunctions/GParserYaml_parseMapping.c
  PrivateFunctions/GParserYaml_parseSequence.c
  PrivateFunctions/GParserYaml_skipWhitespace.c
  PublicFunctions/GParserYaml_closeParams.c
  PublicFunctions/GParserYaml_loadDouble.c
  PublicFunctions/GParserYaml_loadDoubleArray.c
  PublicFunctions/GParserYaml_loadFloat.c
  PublicFunctions/GParserYaml_loadFloatArray.c
  PublicFunctions/GParserYaml_loadInt8.c
  PublicFunctions/GParserYaml_loadInt.c
  PublicFunctions/GParserYaml_loadIntArray.c
  PublicFunctions/GParserYaml_loadParams.c
  PublicFunctions/GParserYaml_loadString.c
  PublicFunctions/GParserYaml_loadUInt.c
  PublicFunctions/GParserYaml_loadUInt8.c
  PublicFunctions/GParserYaml_loadUInt16.c
)

target_include_directories(GParserYaml PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/PublicFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/PrivateFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStructs
  ${CMAKE_CURRENT_SOURCE_DIR}/ConstantDefs
)

target_link_libraries(GParserYaml
  PRIVATE GConversions
)