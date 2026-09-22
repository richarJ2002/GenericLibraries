/*!
 * @file            GParserJson_parseObject.c
 * @brief           Parse a JSON object.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_parseObject(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out)
{
    GParserJson_Value *p_object = NULL;
    GParserJson_Value *p_key = NULL;
    GParserJson_Value *p_value = NULL;
    int status;
    int expectKey = 1;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Skip opening brace */
    if (p_state_inout->position >= p_state_inout->fileSize ||
        p_state_inout->p_fileBuffer[p_state_inout->position] != '{')
    {
        return GCONST_FALSE;
    }
    p_state_inout->position++;

    /* Allocate object value */
    status = GParserJson_allocValue(&p_object);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_object->type = GPARSERJSON_VALUE_TYPE_OBJECT;
    p_object->p_children = NULL;
    p_object->numChildren = 0;

    /* Push to context stack */
    if (p_state_inout->depth >= GPARSERJSON_MAX_NESTING_DEPTH)
    {
        GParserJson_freeValue(p_object);
        return GCONST_FALSE;
    }
    p_state_inout->p_contextStack[p_state_inout->depth] = p_object;
    p_state_inout->depth++;

    while (p_state_inout->position < p_state_inout->fileSize)
    {
        /* Skip whitespace */
        status = GParserJson_skipWhitespace(p_state_inout);
        if (status != GCONST_TRUE)
        {
            GParserJson_freeValue(p_object);
            return GCONST_FALSE;
        }

        if (p_state_inout->position >= p_state_inout->fileSize)
        {
            GParserJson_freeValue(p_object);
            return GCONST_FALSE;
        }

        char c = p_state_inout->p_fileBuffer[p_state_inout->position];

        if (c == '}')
        {
            /* End of object */
            p_state_inout->position++;
            p_state_inout->depth--;
            p_state_inout->p_contextStack[p_state_inout->depth] = NULL;
            *pp_value_out = p_object;
            return GCONST_TRUE;
        }

        if (expectKey)
        {
            /* Expect a string key */
            if (c != '"')
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }

            status = GParserJson_parseString(p_state_inout, &p_key);
            if (status != GCONST_TRUE || p_key == NULL)
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }

            /* Copy key name */
            strncpy(p_object->key, p_key->stringValue, GPARSERJSON_MAX_KEY_LENGTH - 1);
            p_object->key[GPARSERJSON_MAX_KEY_LENGTH - 1] = '\0';

            GParserJson_freeValue(p_key);
            p_key = NULL;

            expectKey = 0;
        }
        else
        {
            /* Expect colon */
            if (c != ':')
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }
            p_state_inout->position++;

            /* Parse value */
            status = GParserJson_parseValue(p_state_inout, &p_value);
            if (status != GCONST_TRUE || p_value == NULL)
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }

            /* Add to children */
            p_object->numChildren++;
            p_object->p_children = (GParserJson_Value *)realloc(p_object->p_children,
                                                                 p_object->numChildren * sizeof(GParserJson_Value));
            if (p_object->p_children == NULL)
            {
                GParserJson_freeValue(p_object);
                GParserJson_freeValue(p_value);
                return GCONST_FALSE;
            }

            /* Copy value to children array */
            memcpy(&p_object->p_children[p_object->numChildren - 1], p_value, sizeof(GParserJson_Value));
            /* Transfer ownership of children array to the array element */
            p_value->p_children = NULL;
            GParserJson_freeValue(p_value);
            p_value = NULL;

            expectKey = 1;

            /* Skip whitespace */
            status = GParserJson_skipWhitespace(p_state_inout);
            if (status != GCONST_TRUE)
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }

            if (p_state_inout->position >= p_state_inout->fileSize)
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }

            c = p_state_inout->p_fileBuffer[p_state_inout->position];

            if (c == ',')
            {
                p_state_inout->position++;
                continue;
            }
            else if (c == '}')
            {
                /* End of object - will be handled at top of loop */
                continue;
            }
            else
            {
                GParserJson_freeValue(p_object);
                return GCONST_FALSE;
            }
        }
    }

    GParserJson_freeValue(p_object);
    return GCONST_FALSE;
}
