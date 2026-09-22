/*!
 * @file            GParserYaml_parseSequence.c
 * @brief           Parse a YAML sequence (list).
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_parseSequence(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out)
{
    GParserYaml_Value *p_sequence = NULL;
    GParserYaml_Value *p_value = NULL;
    int status;
    int baseIndent = 0;

    if (p_state_inout == NULL || pp_value_out == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    /* Get base indentation */
    status = GParserYaml_getIndent(p_state_inout, &baseIndent);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    /* Allocate sequence value */
    status = GParserYaml_allocValue(&p_sequence);
    if (status != GCONST_TRUE)
    {
        return GCONST_FALSE;
    }

    p_sequence->type = GPARSERYAML_VALUE_TYPE_SEQUENCE;
    p_sequence->p_children = NULL;
    p_sequence->numChildren = 0;

    /* Push to context stack */
    if (p_state_inout->depth >= GPARSERYAML_MAX_NESTING_DEPTH)
    {
        GParserYaml_freeValue(p_sequence);
        return GCONST_FALSE;
    }
    p_state_inout->p_contextStack[p_state_inout->depth] = p_sequence;
    p_state_inout->depth++;

    while (p_state_inout->position < p_state_inout->fileSize)
    {
        /* Skip whitespace and newlines */
        status = GParserYaml_skipWhitespace(p_state_inout);
        if (status != GCONST_TRUE)
        {
            GParserYaml_freeValue(p_sequence);
            return GCONST_FALSE;
        }

        if (p_state_inout->position >= p_state_inout->fileSize)
        {
            break;
        }

        /* Check indentation */
        int currentIndent = 0;
        status = GParserYaml_getIndent(p_state_inout, &currentIndent);
        if (status != GCONST_TRUE)
        {
            GParserYaml_freeValue(p_sequence);
            return GCONST_FALSE;
        }

        if (currentIndent < baseIndent)
        {
            /* End of sequence */
            break;
        }

        char c = p_state_inout->p_fileBuffer[p_state_inout->position];

        /* Check for comment */
        if (c == '#')
        {
            /* Skip to end of line */
            while (p_state_inout->position < p_state_inout->fileSize &&
                   p_state_inout->p_fileBuffer[p_state_inout->position] != '\n')
            {
                p_state_inout->position++;
            }
            continue;
        }

        /* Expect dash for sequence item */
        if (c != '-')
        {
            /* Not a sequence item, end of sequence */
            break;
        }
        p_state_inout->position++;

        /* Skip whitespace after dash */
        status = GParserYaml_skipWhitespace(p_state_inout);
        if (status != GCONST_TRUE)
        {
            GParserYaml_freeValue(p_sequence);
            return GCONST_FALSE;
        }

        /* Parse value */
        status = GParserYaml_parseValue(p_state_inout, &p_value);
        if (status != GCONST_TRUE || p_value == NULL)
        {
            GParserYaml_freeValue(p_sequence);
            return GCONST_FALSE;
        }

        /* Add to children */
        p_sequence->numChildren++;
        p_sequence->p_children = (GParserYaml_Value *)realloc(p_sequence->p_children,
                                                               p_sequence->numChildren * sizeof(GParserYaml_Value));
        if (p_sequence->p_children == NULL)
        {
            GParserYaml_freeValue(p_sequence);
            GParserYaml_freeValue(p_value);
            return GCONST_FALSE;
        }

        /* Copy value to children array */
        memcpy(&p_sequence->p_children[p_sequence->numChildren - 1], p_value, sizeof(GParserYaml_Value));
        /* Transfer ownership of children array to the array element */
        p_value->p_children = NULL;
        GParserYaml_freeValue(p_value);
        p_value = NULL;
    }

    p_state_inout->depth--;
    p_state_inout->p_contextStack[p_state_inout->depth] = NULL;
    *pp_value_out = p_sequence;
    return GCONST_TRUE;
}
