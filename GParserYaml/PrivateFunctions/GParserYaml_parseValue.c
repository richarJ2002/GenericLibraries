/*!
 * @file            GParserYaml_parseValue.c
 * @brief           Parse a YAML value (string, number, bool, null, mapping, sequence).
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_parseValue(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out)
{
    int status;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Skip whitespace */
    status = GParserYaml_skipWhitespace(p_state_inout);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    if (p_state_inout->position >= p_state_inout->fileSize)
    {
        return GCONST_FALSE;
    }

    char c = p_state_inout->p_fileBuffer[p_state_inout->position];

    /* Check for sequence item */
    if (c == '-')
    {
        return GParserYaml_parseSequence(p_state_inout, pp_value_out);
    }

    /* Check for mapping */
    if (c == '{')
    {
        return GParserYaml_parseMapping(p_state_inout, pp_value_out);
    }

    /* Check for sequence */
    if (c == '[')
    {
        return GParserYaml_parseSequence(p_state_inout, pp_value_out);
    }

    /* Check for quoted string */
    if (c == '"' || c == '\'')
    {
        return GParserYaml_parseString(p_state_inout, pp_value_out);
    }

    /* Check for boolean true */
    if (c == 't' || c == 'T')
    {
        if (p_state_inout->position + 3 < p_state_inout->fileSize &&
            (strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "true", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "True", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "TRUE", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "yes", 3) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "on", 2) == 0))
        {
            GParserYaml_Value *p_value = NULL;
            status = GParserYaml_allocValue(&p_value);
            if (status != GCONST_TRUE)
            {
                return GCONST_FALSE;
            }
            p_value->type = GPARSERYAML_VALUE_TYPE_BOOL;
            p_value->boolValue = 1;
            p_state_inout->position += 4;
            *pp_value_out = p_value;
            return GCONST_TRUE;
        }
    }

    /* Check for boolean false */
    if (c == 'f' || c == 'F')
    {
        if (p_state_inout->position + 4 < p_state_inout->fileSize &&
            (strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "false", 5) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "False", 5) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "FALSE", 5) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "no", 2) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "off", 3) == 0))
        {
            GParserYaml_Value *p_value = NULL;
            status = GParserYaml_allocValue(&p_value);
            if (status != GCONST_TRUE)
            {
                return GCONST_FALSE;
            }
            p_value->type = GPARSERYAML_VALUE_TYPE_BOOL;
            p_value->boolValue = 0;
            p_state_inout->position += 5;
            *pp_value_out = p_value;
            return GCONST_TRUE;
        }
    }

    /* Check for null */
    if (c == 'n' || c == 'N')
    {
        if (p_state_inout->position + 3 < p_state_inout->fileSize &&
            (strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "null", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "Null", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "NULL", 4) == 0 ||
             strncmp(&p_state_inout->p_fileBuffer[p_state_inout->position], "~", 1) == 0))
        {
            GParserYaml_Value *p_value = NULL;
            status = GParserYaml_allocValue(&p_value);
            if (status != GCONST_TRUE)
            {
                return GCONST_FALSE;
            }
            p_value->type = GPARSERYAML_VALUE_TYPE_NULL;
            p_state_inout->position += 4;
            *pp_value_out = p_value;
            return GCONST_TRUE;
        }
    }

    /* Check for number */
    if (c == '-' || c == '+' || (c >= '0' && c <= '9'))
    {
        return GParserYaml_parseNumber(p_state_inout, pp_value_out);
    }

    /* Unquoted string */
    return GParserYaml_parseString(p_state_inout, pp_value_out);
}
