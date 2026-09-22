/*
 *    @File:         GParserIni_loadingStringValue.c
 *
 *    @ Brief:       This loads the value buffer of the params struct
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
int GParserIni_loadingStringValue(GParserIni_State *p_GParserIni_state,
                               const char     cursor)
{
  switch (cursor)
  {
  case ('\n'):
    GError("Can't have a newline before string is closed with \"");
    break;
  case ('\"'):
    /* Incriment size index (Need to incriment for for loop) */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_NEWLINE;
    break;
  default:
    /* Load value buffer with cursor */
    *(p_GParserIni_state->valueBuffer + p_GParserIni_state->valueArrayIndex) = cursor;

    /* Icnriment value index */
    p_GParserIni_state->valueArrayIndex++;

    /* Incriment size buffer */
    p_GParserIni_state->valueSize[p_GParserIni_state->sizeArrayIndex]++;
    break;
  }

  return GCONST_TRUE;
}
