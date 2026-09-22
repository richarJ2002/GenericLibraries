/*!
 * @file            GParserJson_parseValue.c
 * @brief           Parse a JSON value (string, number, bool, null, object, array).
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_parseValue(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out)
{
    int status;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Skip whitespace */
    status = GParserJson_skipWhitespace(p_state_inout);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    if (p_state_inout->position >= p_state_inout->fileSize)
    {
        return GCONST_FALSE;
    }

    char c = p_state_inout->p_fileBuffer[p_state_inout->position];

    switch (c)
    {
        case '"':
            return GParserJson_parseString(p_state_inout, pp_value_out);

        case '{':
            return GParserJson_parseObject(p_state_inout, pp_value_out);

        case '[':
            return GParserJson_parseArray(p_state_inout, pp_value_out);

        case 't': /* true */
            if (p_state_inout->position + 3 < p_state_inout->fileSize &&
                strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "true", 4) == 0)
            {
                GParserJson_Value *p_value = NULL;
                status = GParserJson_allocValue(&p_value);
                if (status != GCONST_TRUE)
                {
                    return GCONST_FALSE;
                }
                p_value->type = GPARSERJSON_VALUE_TYPE_BOOL;
                p_value->boolValue = 1;
                p_state_inout->position += 4;
                *pp_value_out = p_value;
                return GCONST_TRUE;
            }
            return GCONST_FALSE;

        case 'f': /* false */
            if (p_state_inout->position + 4 < p_state_inout->fileSize &&
                strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "false", 5) == 0)
            {
                GParserJson_Value *p_value = NULL;
                status = GParserJson_allocValue(&p_value);
                if (status != GCONST_TRUE)
                {
                    return GCONST_FALSE;
                }
                p_value->type = GPARSERJSON_VALUE_TYPE_BOOL;
                p_value->boolValue = 0;
                p_state_inout->position += 5;
                *pp_value_out = p_value;
                return GCONST_TRUE;
            }
            return GCONST_FALSE;

        case 'n': /* null */
            if (p_state_inout->position + 3 < p_state_inout->fileSize &&
                strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "null", 4) == 0)
            {
                GParserJson_Value *p_value = NULL;
                status = GParserJson_allocValue(&p_value);
                if (status != GCONST_TRUE)
                {
                    return GCONST_FALSE;
                }
                p_value->type = GPARSERJSON_VALUE_TYPE_NULL;
                p_state_inout->position += 4;
                *pp_value_out = p_value;
                return GCONST_TRUE;
            }
            return GCONST_FALSE;

        case '-':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return GParserJson_parseNumber(p_state_inout, pp_value_out);

        default:
            return GCONST_FALSE;
    }
}
