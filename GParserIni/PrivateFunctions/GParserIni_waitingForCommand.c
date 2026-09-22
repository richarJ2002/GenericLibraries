/*
 *   @File:         GParserIni_waitingForCommand.c
 *
 *   @ Brief:       Function to determine how to change state depending on
 *                  cursor input
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>

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
int GParserIni_waitingForCommand(GParserIni_State *p_GParserIni_state, const char cursor)
{
  switch (cursor)
  {
  case ('\t'):
    /* DO NOTHING */
    break;
  case (' '):
    /* DO NOTHING */
    break;
  case ('\n'):
    /* DO NOTHING */
    break;
  case ('['):
    /* Check to see if dictionary should be loaded */
    switch (p_GParserIni_state->sectionCounter)
    {
    case (GCONST_FALSE):
      /* DO NOTHING */
      break;
    default:
      /* set load dictionary flag to True */
      p_GParserIni_state->loadDictionaryEnabled = GCONST_TRUE;
    }

    /* Updating State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_LOADING_SECTION;
    break;
  case ('#'):
    /* Updating State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  case (';'):
    /* Updating State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_COMMENT;
    break;
  case (EOF):
    /* Updating State */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_FINISHED;
    break;
  default:
    /* Cursor must be representing key, check to make sure there is a section */
    switch (p_GParserIni_state->sectionCounter)
    {
      /* If no section has been loaded throw an error */
    case (GCONST_FALSE):
      GError("Can't have a key with no section");
      break;
    default:
      /* Setting the State */
      p_GParserIni_state->loadParamsState = GPARSERINI_STATE_LOADING_KEY;

      /* Loading the key with the cursor */
      *(p_GParserIni_state->keyBuffer + p_GParserIni_state->keyArrayIndex) = cursor;

      /* Incrimenting the key index */
      p_GParserIni_state->keyArrayIndex++;

      /* Incrimenting the key size*/
      p_GParserIni_state->keySize[p_GParserIni_state->sizeArrayIndex]++;
      break;
    }
  }

  return GCONST_TRUE;
}
