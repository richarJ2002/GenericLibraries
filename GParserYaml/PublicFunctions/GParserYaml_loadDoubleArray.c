/*!
 * @file            GParserYaml_loadDoubleArray.c
 * @brief           Load a double array from the YAML file.
 * @date            22/09/2026
 */

#include "GParserYaml_PublicFunctions.h"
#include "GParserYaml_PrivateFunctions.h"

int GParserYaml_loadDoubleArray(GParserYaml_State *p_state_in, const char *p_key_in, double *p_values_out, size_t maxCount_in, size_t *p_count_out)
{
    GParserYaml_Value *p_sequence = NULL;
    int status;
    size_t count = 0;

    if (p_state_in == NULL || p_key_in == NULL || p_values_out == NULL || p_count_out == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_state_in->p_root == NULL)
    {
        return GCONST_FALSE;
    }

    if (maxCount_in == 0)
    {
        *p_count_out = 0;
        return GCONST_TRUE;
    }

    status = GParserYaml_findKey(p_state_in->p_root, p_key_in, &p_sequence);
    if (status != GCONST_TRUE || p_sequence == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_sequence->type != GPARSERYAML_VALUE_TYPE_SEQUENCE)
    {
        return GCONST_FALSE;
    }

    int i;
    for (i = 0; i < p_sequence->numChildren && count < maxCount_in; i++)
    {
        if (p_sequence->p_children[i].type == GPARSERYAML_VALUE_TYPE_NUMBER)
        {
            p_values_out[count++] = p_sequence->p_children[i].numberValue;
        }
        else
        {
            return GCONST_FALSE;
        }
    }

    *p_count_out = count;
    return GCONST_TRUE;
}