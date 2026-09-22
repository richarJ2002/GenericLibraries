/*
 *    @File:         GParserIni_waitingForNewLine.c
 *
 *    @ Brief:       Waits for a new line when parsing
 *
 *    @ Date:        20/12/2023
 *
 */

/* Function Includes */
/* None */

/* Structure Include */
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */
#include "GParserIni/ConstantDefs/GParserIni_Const.h"

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GLog/GLog.h"

/*
 *  Refer to respective header file for function description
 */
int GParserIni_waitingForNewLine(GParserIni_State *p_GParserIni_state, const char cursor)
{
  switch (cursor)
  {
  case (' '):
    /* DO NOTHING */
    break;
  case ('\t'):
    /* DO NOTHING */
    break;
  case ('\n'):
    /* Update the state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_FOR_COMMAND;
    break;
  case ('#'):
    /* Update the state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  case (';'):
    /* Update the state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  default:
    GError("Invalid expression, cursor= %d", cursor);
  }

  return GCONST_TRUE;
}
