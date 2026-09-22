/*!
 * @file            GParserJson_clearBuffers.c
 * @brief           Clear parsing buffers in the state.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserJson_clearBuffers(GParserJson_State *p_state_inout)
{
    int i;

    if (p_state_inout == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_state_inout->p_root != NULL)
    {
        GParserJson_freeValue(p_state_inout->p_root);
        p_state_inout->p_root = NULL;
    }

    if (p_state_inout->p_fileBuffer != NULL)
    {
        free(p_state_inout->p_fileBuffer);
        p_state_inout->p_fileBuffer = NULL;
    }

    p_state_inout->fileSize = 0;
    p_state_inout->position = 0;
    p_state_inout->state = GPARSERJSON_STATE_START;
    p_state_inout->depth = 0;
    p_state_inout->keyBuffer[0] = '\0';
    p_state_inout->valueBuffer[0] = '\0';
    p_state_inout->keyIndex = 0;
    p_state_inout->valueIndex = 0;

    for (i = 0; i < GPARSERJSON_MAX_NESTING_DEPTH; i++)
    {
        p_state_inout->p_contextStack[i] = NULL;
    }

    return GCONST_TRUE;
}
