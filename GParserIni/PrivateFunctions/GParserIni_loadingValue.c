/*
 *    @File:         GParserIni_loadingValue.c
 *
 *    @ Brief:       This loads the valude buffer of a params struct
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
int GParserIni_loadingValue(GParserIni_State *p_GParserIni_state, const char cursor)
{
  switch (cursor)
  {
  case (' '):
    /* Incriment size Index */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_NEWLINE;
    break;
  case ('\t'):
    /* Incriment size Index */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_NEWLINE;
    break;
  case ('\n'):
    /* Incriment size Index */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_FOR_COMMAND;
    break;
  case ('#'):
    /* Incriment size Index */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  case (';'):
    /* Incriment size Index */
    p_GParserIni_state->sizeArrayIndex++;

    /* Update State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  default:
    /* Load value buffer with cursor */
    p_GParserIni_state->valueBuffer[p_GParserIni_state->valueArrayIndex] = cursor;

    /* Incriment value index */
    p_GParserIni_state->valueArrayIndex++;

    /* Check to make sure the buffer has not been filled to max */
    if (p_GParserIni_state->valueArrayIndex > GPARSERINI_VALUE_BUFFERSIZE)
    {
      GError("Value Buffer has reached max capacity for section %s. "
             "\n[valueBuffer = %s]",
             p_GParserIni_state->sectionBuffer,
             p_GParserIni_state->valueBuffer);
    }

    /* incriment value size value */
    p_GParserIni_state->valueSize[p_GParserIni_state->sizeArrayIndex]++;
    break;
  }

  return GCONST_TRUE;
}
