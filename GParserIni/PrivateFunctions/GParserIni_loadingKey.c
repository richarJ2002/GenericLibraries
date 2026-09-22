/*
 *    @File:         GParserIni_loadingKey.c
 *
 *    @ Brief:       This loads the key buffer in params struct
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
int GParserIni_loadingKey(GParserIni_State *p_GParserIni_state, const char cursor)
{
  switch (cursor)
  {
  case (' '):
    /* Update state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_KEY_WAITING_FOR_EQUALS;
    break;
  case ('='):
    /* Update state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_VALUE;
    break;
  case ('\t'):
    /* Update state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_KEY_WAITING_FOR_EQUALS;
    break;
  case ('\n'):
    GError("Value not inputted into key");
    break;
  default:
    /* Load key buffer with cursor */
    p_GParserIni_state->keyBuffer[p_GParserIni_state->keyArrayIndex] = cursor;

    /* Incriment key index */
    p_GParserIni_state->keyArrayIndex++;

    /* Check to make sure the buffer has not been filled to max */
    if (p_GParserIni_state->keyArrayIndex > GPARSERINI_KEY_BUFFERSIZE)
    {
      GError("Key Buffer has reached max capacity for section %s. \n[KeyBuffer "
             "= %s]",
             p_GParserIni_state->sectionBuffer,
             p_GParserIni_state->keyBuffer);
    }

    /* Incriment key size */
    p_GParserIni_state->keySize[p_GParserIni_state->sizeArrayIndex]++;

    break;
  }

  return GCONST_TRUE;
}
