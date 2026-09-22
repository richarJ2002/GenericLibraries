/*!
 * @file            GParserYaml_loadUInt16.c
 * @brief           Load an unsigned 16-bit int value from the YAML file.
 * @date            22/09/2026
 */

#include "GParserYaml_PublicFunctions.h"
#include "GParserYaml_PrivateFunctions.h"

int GParserYaml_loadUInt16(GParserYaml_State *p_state_in, const char *p_key_in, uint16_t *p_value_out)
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

    status = GParserYaml_findKey(p_state_in->p_root, p_key_in, &p_value);
    if (status != GCONST_TRUE || p_value == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_value->type != GPARSERYAML_VALUE_TYPE_NUMBER)
    {
        return GCONST_FALSE;
    }

    *p_value_out = (uint16_t)p_value->numberValue;
    return GCONST_TRUE;
}