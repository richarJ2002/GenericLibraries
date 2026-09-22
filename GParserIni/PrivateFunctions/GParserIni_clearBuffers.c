/*
 *    @File:         GParserIni_clearBuffers.c
 *
 *    @ Brief:       Clear buffers of state struct
 *
 *    @ Date:        20/12/2023
 *
 */

#include <stdint.h>

/* Function Includes */
/* None */

/* Structure Include */
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */
/* None */

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GZero/GZero.h"

/*
 *  Refer to respective header file for function description
 */
int GParserIni_clearBuffers(GParserIni_State *p_GParserIni_state)
{
  /* Clear Buffers */
  GZero(p_GParserIni_state->sectionBuffer, char[1024]);
  GZero(p_GParserIni_state->keyBuffer, char[1024]);
  GZero(p_GParserIni_state->valueBuffer, char[1024]);

  /* Clear Index's */
  GZero(&p_GParserIni_state->sizeArrayIndex, uint16_t);
  GZero(&p_GParserIni_state->sectionIndex, uint32_t);
  GZero(&p_GParserIni_state->valueArrayIndex, uint32_t);
  GZero(&p_GParserIni_state->keyArrayIndex, uint32_t);

  /* Clear size variables */
  GZero(&p_GParserIni_state->keySize, int[256]);
  GZero(&p_GParserIni_state->valueSize, int[256]);
  GZero(&p_GParserIni_state->sectionSize, int);

  return GCONST_TRUE;
}
