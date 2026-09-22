# GParserIni library - INI format parser (custom implementation)
add_library(GParserIni
  PrivateFunctions/GParserIni_clearBuffers.c
  PrivateFunctions/GParserIni_comment.c
  PrivateFunctions/GParserIni_findNumberOfSections.c
  PrivateFunctions/GParserIni_loadDictionary.c
  PrivateFunctions/GParserIni_loadingKey.c
  PrivateFunctions/GParserIni_loadingSection.c
  PrivateFunctions/GParserIni_loadingStringValue.c
  PrivateFunctions/GParserIni_loadingValue.c
  PrivateFunctions/GParserIni_waitingEquals.c
  PrivateFunctions/GParserIni_waitingForCommand.c
  PrivateFunctions/GParserIni_waitingForNewLine.c
  PrivateFunctions/GParserIni_waitingValue.c
  PublicFunctions/GParserIni_closeParams.c
  PublicFunctions/GParserIni_loadDouble.c
  PublicFunctions/GParserIni_loadDoubleArray.c
  PublicFunctions/GParserIni_loadFloat.c
  PublicFunctions/GParserIni_loadFloatArray.c
  PublicFunctions/GParserIni_loadInt8.c
  PublicFunctions/GParserIni_loadInt.c
  PublicFunctions/GParserIni_loadIntArray.c
  PublicFunctions/GParserIni_loadParams.c
  PublicFunctions/GParserIni_loadString.c
  PublicFunctions/GParserIni_loadUInt.c
  PublicFunctions/GParserIni_loadUInt8.c
  PublicFunctions/GParserIni_loadUInt16.c
)

target_include_directories(GParserIni PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/PublicFunctions
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStructs
  ${CMAKE_CURRENT_SOURCE_DIR}/ConstantDefs
)

target_link_libraries(GParserIni
  PRIVATE GConversions
)