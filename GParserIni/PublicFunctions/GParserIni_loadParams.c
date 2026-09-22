/*
 *   @File:         GParserIni_loadParams
 *
 *   @ Brief:       Loads Params from ini file into a dictionary
 *
 *   @ Date:        20/12/2023
 *
 */

#include <stdint.h>
#include <stdio.h>

/* Function Includes */
#include "GParserIni/PrivateFunctions/GParserIni_PrivateFunctions.h"
#include "GParserIni/PublicFunctions/GParserIni_PublicFunctions.h"

/* Structure Include */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */
#include "GParserIni/ConstantDefs/GParserIni_Const.h"

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GLog/GLog.h"
#include "GZero/GZero.h"

/*
 *  Refer to respective header file for function description
 */
dictionary *GParserIni_loadParams(GParserIni_State *p_GParserIni_state,
                               const char    *filePath)
{
  /* Defining Local Variables */
  dictionary *p_dic;
  FILE       *file;
  char        cursor;

  /* Clearing Data values */
  GZero(p_GParserIni_state, GParserIni_State);
  p_dic = NULL;

  /* Opening file */
  file = fopen(filePath, "r");

  /* Check to make sure that the file was opened corectly */
  if (file == NULL)
  {
    GError("No file was able to open, filePath = %s", filePath);
    return NULL;
  }

  /* Finding number of Sections */
GParserIni_findNumberOfSections(file, &p_GParserIni_state->maxNumberSection);

  /* Assigning Memory to Dictionary */
  p_dic = (dictionary *)calloc(p_GParserIni_state->maxNumberSection,
                               sizeof(dictionary));

  /* Set the initial state */
  p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_FOR_COMMAND;

  /* Run through file */
  while (!(p_GParserIni_state->loadParamsState == GPARSERINI_STATE_FINISHED))
  {
    /* Get next cursor*/
    cursor = fgetc(file);

    if (cursor == EOF)
    {
      /* Check to see if file ends on a key, incriment size index */
      switch (p_GParserIni_state->loadParamsState)
      {
      case (GPARSERINI_STATE_LOADING_VALUE):
        p_GParserIni_state->sizeArrayIndex++;
        break;
      case (GPARSERINI_STATE_LOADING_STRING_VALUE):
        p_GParserIni_state->sizeArrayIndex++;
        break;
      }
      /* Update state to finish reading */
      p_GParserIni_state->loadParamsState = GPARSERINI_STATE_FINISHED;

      /* Set flag to load dictionary */
      p_GParserIni_state->loadDictionaryEnabled = GCONST_TRUE;
    }

    /* Check the state */
    switch (p_GParserIni_state->loadParamsState)
    {
    case (GPARSERINI_STATE_WAITING_FOR_COMMAND):
      /* Waiting for next commamnd */
      GParserIni_waitingForCommand(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_WAITING_NEWLINE):
      /* Waiting for a new line */
      GParserIni_waitingForNewLine(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_COMMENT):
      /* Parsing a comment section */
      GParserIni_comment(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_LOADING_SECTION):
      /* Loading a section */
      GParserIni_loadingSection(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_LOADING_KEY):
      /* Loading key into buffer */
      GParserIni_loadingKey(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_KEY_WAITING_FOR_EQUALS):
      /* Waiting for equals after the key */
      GParserIni_waitingEquals(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_WAITING_VALUE):
      /* Waiting for value to be loaded */
      GParserIni_waitingValue(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_LOADING_VALUE):
      /* Loading value into buffers */
      GParserIni_loadingValue(p_GParserIni_state, cursor);
      break;
    case (GPARSERINI_STATE_LOADING_STRING_VALUE):
      /* Loading a string value into buffers */
      GParserIni_loadingStringValue(p_GParserIni_state, cursor);
      break;
    }

    /*!
     * Check that the max number of sections has not been reached. The reason it
     * is > and not >= is to cover the case where their is exactly
     * GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER value-key pairs. In this
     * case, p_GParserIni_state->sizeArrayIndex will eventually equal
     * GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER before the dictionary is
     * loaded and the index is reset.
     */
    if (p_GParserIni_state->sizeArrayIndex >
        GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER)
    {
      GError("Maximum number of values/keys has been reached: \n"
             "  p_GParserIni_state->sizeArrayIndex = %d \n"
             "  GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER = %d",
             p_GParserIni_state->sizeArrayIndex,
             GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER);
    }

    /* If flag enabled, load section into dictionary */
    if (p_GParserIni_state->loadDictionaryEnabled)
    {
      *(p_dic + p_GParserIni_state->sectionCounter - 1) =
          GParserIni_loadDictionary(p_GParserIni_state);

      /* Clear buffers */
      GParserIni_clearBuffers(p_GParserIni_state);

      /* Reset flag */
      p_GParserIni_state->loadDictionaryEnabled = GCONST_FALSE;
    }
  }

  /* Clost the file */
  fclose(file);

  /* Output dictionary */
  return p_dic;
}
