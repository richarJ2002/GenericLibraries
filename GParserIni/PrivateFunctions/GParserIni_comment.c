/*
 *   @File:         GParserIni_comment.c
 *
 *   @ Brief:       Function to determine how to change state depending on
 *                  cursor input
 *
 */

/* Function Includes */
#include "GParserIni/PrivateFunctions/GParserIni_PrivateFunctions.h"

/* Structure Include */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */
#include "GParserIni/ConstantDefs/GParserIni_Const.h"

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GLog/GLog.h"

/*
 *  Refer to respective header file for function description
 */
int GParserIni_comment(GParserIni_State *p_GParserIni_state, const char cursor_in)
{
  switch (cursor_in)
  {
  case ('\n'):
    /* Updating the state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_FOR_COMMAND;
    break;
  default:
    /* DO NOTHING */
    break;
  }

  return GCONST_TRUE;
}