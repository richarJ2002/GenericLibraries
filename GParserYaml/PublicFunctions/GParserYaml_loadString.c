/*!
 * @file            GParserYaml_loadString.c
 * @brief           Load a string value from the YAML file.
 * @date            22/09/2026
 */

#include "GParserYaml_PublicFunctions.h"
#include "GParserYaml_PrivateFunctions.h"

int GParserYaml_loadString(GParserYaml_State *p_state_in, const char *p_key_in, char *p_value_out, size_t maxLen_in)
{
    GParserYaml_Value *p_value = NULL;
    int status;

    if (p_state_in == NULL || p_key_in == NULL || p_value_out == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_state_in->p_root == NULL)
    {
        return GCONST_FALSE;
    }

    if (maxLen_in == 0)
    {
        return GCONST_FALSE;
    }

    status = GParserYaml_findKey(p_state_in->p_root, p_key_in, &p_value);
    if (status != GCONST_TRUE || p_value == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_value->type != GPARSERYAML_VALUE_TYPE_STRING)
    {
        return GCONST_FALSE;
    }

    if (strlen(p_value->stringValue) >= maxLen_in)
    {
        return GCONST_FALSE;
    }

    strcpy(p_value_out, p_value->stringValue);
    return GCONST_TRUE;
}