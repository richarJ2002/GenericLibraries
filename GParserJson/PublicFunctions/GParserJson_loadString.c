/*!
 * @file            GParserJson_loadString.c
 * @brief           Load a string value from the JSON file.
 * @date            22/09/2026
 */

#include "GParserJson_PublicFunctions.h"
#include "GParserJson_PrivateFunctions.h"

int GParserJson_loadString(GParserJson_State *p_state_in, const char *p_key_in, char *p_value_out, size_t maxLen_in)
{
    GParserJson_Value *p_value = NULL;
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

    status = GParserJson_findKey(p_state_in->p_root, p_key_in, &p_value);
    if (status != GCONST_TRUE || p_value == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_value->type != GPARSERJSON_VALUE_TYPE_STRING)
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