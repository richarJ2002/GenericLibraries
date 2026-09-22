/*
 *    @File:         GParserIni_loadingSection.c
 *
 *    @ Brief:       This loads section buffer of params struct
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
int GParserIni_loadingSection(GParserIni_State *p_GParserIni_state, const char cursor)
{
  switch (cursor)
  {
  case (' '):
    GError("Can't have an error in section name");
    break;
  case ('\t'):
    GError("Can't have a tab in section name");
    break;
  case ('\n'):
    GError("Section not finished before new line");
    break;
  case ('#'):
    GError("Can't have # in section name");
    break;
  case (';'):
    GError("Can't have ; in section name");
    break;
  case (']'):
    /* Incriment section counter */
    p_GParserIni_state->sectionCounter++;

    /* Update state */
    p_GParserIni_state->loadParamsState = GPARSERINI_STATE_WAITING_NEWLINE;
    break;
  default:
    /* Load section buffer with cursor */
    *(p_GParserIni_state->sectionBuffer + p_GParserIni_state->sectionIndex) = cursor;

    /* Incriment section index */
    p_GParserIni_state->sectionIndex++;

    /* Incriment section size */
    p_GParserIni_state->sectionSize++;
  }

  return GCONST_TRUE;
}
