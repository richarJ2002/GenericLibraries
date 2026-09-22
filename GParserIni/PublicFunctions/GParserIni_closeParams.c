/*!
 * @file            GParserIni_closeParams.c
 * @brief           Closes params and frees dictionary
 * @date            23/12/2023
 */

/* Function Includes */
/* None */

/* Structure Include */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/* Data include */
/* None */

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GZero/GZero.h"

/*
 *  Refer to respective header file for function description
 */
int GParserIni_closeParams(GParserIni_State *p_state_inout, dictionary *p_dic_in)
{
    /* Free the dictionary array */
    if (p_dic_in != NULL)
    {
        free(p_dic_in);
    }

    /* Clear the state */
    GZero(p_state_inout, GParserIni_State);

    return GCONST_TRUE;
}