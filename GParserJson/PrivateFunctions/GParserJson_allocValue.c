/*!
 * @file            GParserJson_allocValue.c
 * @brief           Allocate a new JSON value structure.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_allocValue(GParserJson_Value **pp_value_out)
{
    GParserJson_Value *p_value = NULL;

    if (pp_value_out == NULL)
    {
        return GCONST_FALSE;
    }

    p_value = (GParserJson_Value *)calloc(1, sizeof(GParserJson_Value));
    if (p_value == NULL)
    {
        return GCONST_FALSE;
    }

    p_value->type = 0;
    p_value->stringValue[0] = '\0';
    p_value->numberValue = 0.0;
    p_value->boolValue = 0;
    p_value->p_children = NULL;
    p_value->numChildren = 0;
    p_value->key[0] = '\0';

    *pp_value_out = p_value;
    return GCONST_TRUE;
}
