/*!
 * @file            GParserYaml_allocValue.c
 * @brief           Allocate a new YAML value structure.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_allocValue(GParserYaml_Value **pp_value_out)
{
    GParserYaml_Value *p_value = NULL;

    if (pp_value_out == NULL)
    {
        return GCONST_FALSE;
    }

    p_value = (GParserYaml_Value *)calloc(1, sizeof(GParserYaml_Value));
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
