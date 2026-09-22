/*!
 * @file            GParserJson_parseString.c
 * @brief           Parse a JSON string value.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_parseString(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out)
{
    GParserJson_Value *p_value = NULL;
    int status;
    size_t startPos;
    size_t len = 0;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Skip opening quote */
    if (p_state_inout->position >= p_state_inout->fileSize ||
        p_state_inout->p_fileBuffer[p_state_inout->position] != '"')
    {
        return GCONST_FALSE;
    }
    p_state_inout->position++;

    startPos = p_state_inout->position;

    /* Find closing quote */
    while (p_state_inout->position < p_state_inout->fileSize)
    {
        char c = p_state_inout->p_fileBuffer[p_state_inout->position];
        if (c == '"')
        {
            break;
        }
        else if (c == '\\')
        {
            /* Skip escaped character */
            p_state_inout->position += 2;
            len += 2;
            continue;
        }
        p_state_inout->position++;
        len++;
    }

    if (p_state_inout->position >= p_state_inout->fileSize ||
        p_state_inout->p_fileBuffer[p_state_inout->position] != '"')
    {
        return GCONST_FALSE;
    }

    /* Allocate value */
    status = GParserJson_allocValue(&p_value);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_value->type = GPARSERJSON_VALUE_TYPE_STRING;

    /* Copy string value (without quotes) */
    if (len >= GPARSERJSON_MAX_VALUE_LENGTH)
    {
        len = GPARSERJSON_MAX_VALUE_LENGTH - 1;
    }
    strncpy(p_value->stringValue, &p_state_inout->p_fileBuffer[startPos], len);
    p_value->stringValue[len] = '\0';

    /* Skip closing quote */
    p_state_inout->position++;

    *pp_value_out = p_value;
    return GCONST_TRUE;
}
