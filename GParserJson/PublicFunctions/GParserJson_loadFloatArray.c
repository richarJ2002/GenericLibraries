/*!
 * @file            GParserJson_loadFloatArray.c
 * @brief           Load a float array from the JSON file.
 * @date            22/09/2026
 */

#include "GParserJson_PublicFunctions.h"
#include "GParserJson_PrivateFunctions.h"

int GParserJson_loadFloatArray(GParserJson_State *p_state_in, const char *p_key_in, float *p_values_out, size_t maxCount_in, size_t *p_count_out)
{
    GParserJson_Value *p_array = NULL;
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

    status = GParserJson_findKey(p_state_in->p_root, p_key_in, &p_array);
    if (status != GCONST_TRUE || p_array == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_array->type != GPARSERJSON_VALUE_TYPE_ARRAY)
    {
        return GCONST_FALSE;
    }

    int i;
    for (i = 0; i < p_array->numChildren && count < maxCount_in; i++)
    {
        if (p_array->p_children[i].type == GPARSERJSON_VALUE_TYPE_NUMBER)
        {
            p_values_out[count++] = (float)p_array->p_children[i].numberValue;
        }
        else
        {
            return GCONST_FALSE;
        }
    }

    *p_count_out = count;
    return GCONST_TRUE;
}