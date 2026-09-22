/*
 *    @File:         GParserIni_waitingValue.c
 *
 *    @ Brief:       Waiting for value to be inputted in parsing
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
int GParserIni_waitingValue(GParserIni_State *p_GParserIni_state, const char cursor)
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
    GError("No value inputted before new line");
    break;
  case ('#'):
    GError("No value inputted before #");
    break;
  case (';'):
    GError("No value inputted before ;");
    break;
  case ('\"'):
    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_LOADING_STRING_VALUE;
    break;
  default:
    /* Load value buffer with cursor */
    *(p_GParserIni_state->valueBuffer + p_GParserIni_state->valueArrayIndex) = cursor;

    /* Incriment value index */
    p_GParserIni_state->valueArrayIndex++;

    /* Incriment value size */
    p_GParserIni_state->valueSize[p_GParserIni_state->sizeArrayIndex]++;

    /* Update state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_LOADING_VALUE;
    break;
  }

  return GCONST_TRUE;
}
