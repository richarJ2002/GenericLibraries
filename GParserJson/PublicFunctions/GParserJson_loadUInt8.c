/*!
 * @file            GParserJson_loadUInt8.c
 * @brief           Load an unsigned 8-bit int value from the JSON file.
 * @date            22/09/2026
 */

#include "GParserJson_PublicFunctions.h"
#include "GParserJson_PrivateFunctions.h"

int GParserJson_loadUInt8(GParserJson_State *p_state_in, const char *p_key_in, uint8_t *p_value_out)
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

    status = GParserJson_findKey(p_state_in->p_root, p_key_in, &p_value);
    if (status != GCONST_TRUE || p_value == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_value->type != GPARSERJSON_VALUE_TYPE_NUMBER)
    {
        return GCONST_FALSE;
    }

    *p_value_out = (uint8_t)p_value->numberValue;
    return GCONST_TRUE;
}