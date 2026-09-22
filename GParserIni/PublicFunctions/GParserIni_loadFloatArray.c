/*!
 * @file            GParserIni_loadFloatArray.c
 * @brief           Loads an array of floats
 * @date            23/12/2023
 */

#include <string.h>

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
#include "GConversions/GConversions.h"
#include "GLog/GLog.h"
#include "GZero/GZero.h"

/*
 *  Refer to respective header file for function description
 */
int GParserIni_loadFloatArray(
    GParserIni_State *p_state_in,
    dictionary       *p_dic_in,
    float            *p_values_out,
    const char       *p_key_in,
    int               nCols_in,
    int               nRows_in)
{
    /* Declaring local variables */
    char    section_buffer[GPARSERINI_LOAD_ARRAY_SECTION_BUFFER];
    char    key_inputBuffer[GPARSERINI_LOAD_ARRAY_KEY_INPUT_BUFFER];
    char    dataToLoad_buffer[GPARSERINI_LOAD_ARRAY_DATA_TO_LOAD_BUFFER];
    int     dictionaryNumber;
    int16_t col;
    int16_t row;
    int16_t i;
    int16_t j;
    int16_t k;

    /* Clearing Buffers */
    GZero(&section_buffer, char[GPARSERINI_LOAD_ARRAY_SECTION_BUFFER]);
    GZero(&key_inputBuffer, char[GPARSERINI_LOAD_ARRAY_KEY_INPUT_BUFFER]);
    GZero(&dataToLoad_buffer, char[GPARSERINI_LOAD_ARRAY_DATA_TO_LOAD_BUFFER]);

    /* Defining local variables */
    dictionaryNumber = 0;
    i                = 0;
    j                = 0;

    /* Parsing data input for section */
    for (i = 0; *(p_key_in + i) != ':'; i++)
    {
        section_buffer[i] = *(p_key_in + i);
    }

    /* Parsing data input for key */
    for (i; *(p_key_in + i + 1) != '\0'; i++)
    {
        key_inputBuffer[j] = *(p_key_in + i + 1);
        j++;
    }

    /* Find dictionary for coresponding section */
    for (i = 0; i < p_state_in->maxNumberSection; i++)
    {
        /* check to see if section name matches */
        if (strcmp((p_dic_in + i)->section, section_buffer) == 0)
        {
            dictionaryNumber = i;
            break;
        }
    }

    /* Check to see if section exists */
    if (i == p_state_in->maxNumberSection)
    {
        GError("Section not found: %s", section_buffer);
    }

    /* ---------------------------- LOAD ARRAY ----------------------------- */

    /* Load key for 1D array */
    if (nRows_in == 1)
    {
        for (i = 0; i < nCols_in; i++)
        {
            /* Find the name of the key */
            if (sprintf(
                    dataToLoad_buffer,
                    "%s:%s[%d]",
                    section_buffer,
                    key_inputBuffer,
                    i) < 0)
            {
                GError("Wasn't able to write the key");
            }

            /* Load the key into the memory address */
            GParserIni_loadFloat(
                p_state_in,
                p_dic_in,
                (p_values_out + i),
                dataToLoad_buffer);
        }
    }
    /* Load key for 2D array */
    else
    {
        for (i = 0; i < nRows_in; i++)
        {
            for (j = 0; j < nCols_in; j++)
            {
                if (sprintf(
                        dataToLoad_buffer,
                        "%s:%s[%d][%d]",
                        &section_buffer[0],
                        &key_inputBuffer[0],
                        i,
                        j) < 0)
                {
                    GError("Wasn't able to write the key");
                }

                GParserIni_loadFloat(
                    p_state_in,
                    p_dic_in,
                    (p_values_out + j + i * nCols_in),
                    dataToLoad_buffer);
            }
        }
    }

    return GCONST_TRUE;
}