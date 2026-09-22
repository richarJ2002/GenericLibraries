/*
 *    @File:         GParserIni_waitingEquals.c
 *
 *    @ Brief:       This waits for the cursor to be equals
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
int GParserIni_waitingEquals(GParserIni_State *p_GParserIni_state, const char cursor)
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
    GError("No value inputted to key before new line");
    break;
  case ('='):
    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_VALUE;
    break;
  default:
    GError("Unkown Input");
    break;
  }

  return GCONST_TRUE;
}