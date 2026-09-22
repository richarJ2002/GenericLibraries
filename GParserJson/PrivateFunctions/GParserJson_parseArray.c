/*!
 * @file            GParserJson_parseArray.c
 * @brief           Parse a JSON array.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_parseArray(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out)
{
    GParserJson_Value *p_array = NULL;
    GParserJson_Value *p_value = NULL;
    int status;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Skip opening bracket */
    if (p_state_inout->position >= p_state_inout->fileSize ||
        p_state_inout->p_fileBuffer[p_state_inout->position] != '[')
    {
        return GCONST_FALSE;
    }
    p_state_inout->position++;

    /* Allocate array value */
    status = GParserJson_allocValue(&p_array);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_array->type = GPARSERJSON_VALUE_TYPE_ARRAY;
    p_array->p_children = NULL;
    p_array->numChildren = 0;

    /* Push to context stack */
    if (p_state_inout->depth >= GPARSERJSON_MAX_NESTING_DEPTH)
    {
        GParserJson_freeValue(p_array);
        return GCONST_FALSE;
    }
    p_state_inout->p_contextStack[p_state_inout->depth] = p_array;
    p_state_inout->depth++;

    while (p_state_inout->position < p_state_inout->fileSize)
    {
        /* Skip whitespace */
        status = GParserJson_skipWhitespace(p_state_inout);
        if (status != GCONST_TRUE)
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }

        if (p_state_inout->position >= p_state_inout->fileSize)
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }

        char c = p_state_inout->p_fileBuffer[p_state_inout->position];

        if (c == ']')
        {
            /* End of array */
            p_state_inout->position++;
            p_state_inout->depth--;
            p_state_inout->p_contextStack[p_state_inout->depth] = NULL;
            *pp_value_out = p_array;
            return GCONST_TRUE;
        }

        /* Parse value */
        status = GParserJson_parseValue(p_state_inout, &p_value);
        if (status != GCONST_TRUE || p_value == NULL)
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }

        /* Add to children */
        p_array->numChildren++;
        p_array->p_children = (GParserJson_Value *)realloc(p_array->p_children,
                                                            p_array->numChildren * sizeof(GParserJson_Value));
        if (p_array->p_children == NULL)
        {
            GParserJson_freeValue(p_array);
            GParserJson_freeValue(p_value);
            return GCONST_FALSE;
        }

        /* Copy value to children array */
        memcpy(&p_array->p_children[p_array->numChildren - 1], p_value, sizeof(GParserJson_Value));
        /* Transfer ownership of children array to the array element */
        p_value->p_children = NULL;
        GParserJson_freeValue(p_value);
        p_value = NULL;

        /* Skip whitespace */
        status = GParserJson_skipWhitespace(p_state_inout);
        if (status != GCONST_TRUE)
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }

        if (p_state_inout->position >= p_state_inout->fileSize)
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }

        c = p_state_inout->p_fileBuffer[p_state_inout->position];

        if (c == ',')
        {
            p_state_inout->position++;
            continue;
        }
        else if (c == ']')
        {
            /* End of array - will be handled at top of loop */
            continue;
        }
        else
        {
            GParserJson_freeValue(p_array);
            return GCONST_FALSE;
        }
    }

    GParserJson_freeValue(p_array);
    return GCONST_FALSE;
}
