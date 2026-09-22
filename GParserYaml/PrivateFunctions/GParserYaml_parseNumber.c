/*!
 * @file            GParserYaml_parseNumber.c
 * @brief           Parse a YAML number value.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_parseNumber(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out)
{
    GParserYaml_Value *p_value = NULL;
    int status;
    size_t startPos;
    char *p_endPtr = NULL;
    double value;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    startPos = p_state_inout->position;

    /* Parse number: optional minus, digits, optional decimal point and digits, optional exponent */
    while (p_state_inout->position < p_state_inout->fileSize)
    {
        char c = p_state_inout->p_fileBuffer[p_state_inout->position];
        if ((c >= '0' && c <= '9') || c == '-' || c == '+' || c == '.' || c == 'e' || c == 'E')
        {
            p_state_inout->position++;
        }
        else
        {
            break;
        }
    }

    if (p_state_inout->position == startPos)
    {
        return GCONST_FALSE;
    }

    /* Allocate value */
    status = GParserYaml_allocValue(&p_value);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_value->type = GPARSERYAML_VALUE_TYPE_NUMBER;

    /* Parse number */
    char numStr[64];
    size_t numLen = p_state_inout->position - startPos;
    if (numLen >= sizeof(numStr))
    {
        numLen = sizeof(numStr) - 1;
    }
    strncpy(numStr, &p_state_inout->p_fileBuffer[startPos], numLen);
    numStr[numLen] = '\0';

    value = strtod(numStr, &p_endPtr);
    if (p_endPtr == numStr)
    {
        GParserYaml_freeValue(p_value);
        return GCONST_FALSE;
    }

    p_value->numberValue = value;

    *pp_value_out = p_value;
    return GCONST_TRUE;
}
