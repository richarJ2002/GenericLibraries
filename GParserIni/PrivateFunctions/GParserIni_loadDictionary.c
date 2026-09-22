/*
 *    @File:         GParserIni_loadDictionary.c
 *
 *    @ Brief:       Loads dictionary with information from a section.
 *
 *    @ Date:        18/12/2023
 *
 */

#include <stdlib.h>
#include <string.h>

/* Function Includes */
/* None */

/* Structure Include */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GZero/GZero.h"

/*
 *  Refer to respective header file for function description
 */
dictionary GParserIni_loadDictionary(GParserIni_State *p_GParserIni_state)
{
  /* Defining local variables */
  dictionary dic_section;
  int        keyArrayIndex;
  int        valueArrayIndex;
  int        i;
  int        j;

  /* Clear Dictionary */
  GZero(&dic_section, dictionary);

  /* Set indexes to 0 */
  keyArrayIndex   = 0;
  valueArrayIndex = 0;

  /* Setting the section name to dictionary */
  for (i = 0; i < p_GParserIni_state->sectionIndex; i++)
  {
    dic_section.section[i] = *(p_GParserIni_state->sectionBuffer + i);
  }

  /* Loading the keys and values into dictionary */
  for (i = 0; i < p_GParserIni_state->sizeArrayIndex; i++)
  {
    /* Fill tmp Key Buffer */
    for (j = 0; j < p_GParserIni_state->keySize[i]; j++)
    {
      dic_section.key[i][j] = p_GParserIni_state->keyBuffer[keyArrayIndex];
      keyArrayIndex++;
    }

    /* Fill tmp Value Buffer */
    for (j = 0; j < p_GParserIni_state->valueSize[i]; j++)
    {
      dic_section.value[i][j] = p_GParserIni_state->valueBuffer[valueArrayIndex];
      valueArrayIndex++;
    }

    /* set number of keys in a section */
    dic_section.nKeys = p_GParserIni_state->sizeArrayIndex;
  }

  return dic_section;
}
