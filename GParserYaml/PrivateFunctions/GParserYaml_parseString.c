/*!
 * @file            GParserYaml_parseString.c
 * @brief           Parse a YAML string value.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_parseString(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out)
{
    GParserYaml_Value *p_value = NULL;
    int status;
    size_t startPos;
    size_t len = 0;
    int quoted = 0;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Check if quoted */
    if (p_state_inout->position < p_state_inout->fileSize &&
        (p_state_inout->p_fileBuffer[p_state_inout->position] == '"' ||
         p_state_inout->p_fileBuffer[p_state_inout->position] == '\''))
    {
        quoted = 1;
        p_state_inout->position++;
    }

    startPos = p_state_inout->position;

    /* Find end of string */
    while (p_state_inout->position < p_state_inout->fileSize)
    {
        char c = p_state_inout->p_fileBuffer[p_state_inout->position];

        if (quoted)
        {
            if (c == '"' || c == '\'')
            {
                break;
            }
            else if (c == '\\')
            {
                p_state_inout->position += 2;
                len += 2;
                continue;
            }
        }
        else
        {
            /* Unquoted string ends at newline, colon, or comment */
            if (c == '\n' || c == ':' || c == '#')
            {
                break;
            }
        }

        p_state_inout->position++;
        len++;
    }

    if (quoted && (p_state_inout->position >= p_state_inout->fileSize ||
        (p_state_inout->p_fileBuffer[p_state_inout->position] != '"' &&
         p_state_inout->p_fileBuffer[p_state_inout->position] != '\'')))
    {
        return GCONST_FALSE;
    }

    /* Allocate value */
    status = GParserYaml_allocValue(&p_value);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_value->type = GPARSERYAML_VALUE_TYPE_STRING;

    /* Copy string value */
    if (len >= GPARSERYAML_MAX_VALUE_LENGTH)
    {
        len = GPARSERYAML_MAX_VALUE_LENGTH - 1;
    }
    strncpy(p_value->stringValue, &p_state_inout->p_fileBuffer[startPos], len);
    p_value->stringValue[len] = '\0';

    /* Skip closing quote if quoted */
    if (quoted)
    {
        p_state_inout->position++;
    }

    *pp_value_out = p_value;
    return GCONST_TRUE;
}
