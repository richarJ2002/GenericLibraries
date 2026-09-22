/*!
 * @file            GParserYaml_skipWhitespace.c
 * @brief           Skip whitespace characters in the file buffer.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_skipWhitespace(GParserYaml_State *p_state_inout)
{
    if (p_state_inout == NULL || p_state_inout->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    while (p_state_inout->position < p_state_inout->fileSize)
    {
        char c = p_state_inout->p_fileBuffer[p_state_inout->position];
        if (c == ' ' || c == '\t')
        {
            p_state_inout->position++;
        }
        else if (c == '\n')
        {
            p_state_inout->position++;
            p_state_inout->lineNumber++;
        }
        else if (c == '\r')
        {
            p_state_inout->position++;
        }
        else
        {
            break;
        }
    }

    return GCONST_TRUE;
}
