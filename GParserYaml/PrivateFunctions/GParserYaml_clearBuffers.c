/*!
 * @file            GParserYaml_clearBuffers.c
 * @brief           Clear parsing buffers in the state.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_clearBuffers(GParserYaml_State *p_state_inout)
{
    if (p_state_inout == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_state_inout->p_root != NULL)
    {
        GParserYaml_freeValue(p_state_inout->p_root);
        p_state_inout->p_root = NULL;
    }

    if (p_state_inout->p_fileBuffer != NULL)
    {
        free(p_state_inout->p_fileBuffer);
        p_state_inout->p_fileBuffer = NULL;
    }

    p_state_inout->fileSize = 0;
    p_state_inout->position = 0;
    p_state_inout->lineNumber = 1;
    p_state_inout->state = GPARSERYAML_STATE_START;
    p_state_inout->depth = 0;
    p_state_inout->indentLevel = 0;
    p_state_inout->keyBuffer[0] = '\0';
    p_state_inout->valueBuffer[0] = '\0';
    p_state_inout->keyIndex = 0;
    p_state_inout->valueIndex = 0;

    int i;
    for (i = 0; i < GPARSERYAML_MAX_NESTING_DEPTH; i++)
    {
        p_state_inout->p_contextStack[i] = NULL;
    }

    return GCONST_TRUE;
}
