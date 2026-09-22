/*!
 * @file            GParserYaml_getIndent.c
 * @brief           Get current indentation level.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_getIndent(GParserYaml_State *p_state_in, int *p_indent_out)
{
    int indent = 0;

    if (p_state_in == NULL || p_indent_out == NULL || p_state_in->p_fileBuffer == NULL)
    {
        return GCONST_FALSE;
    }

    size_t pos = p_state_in->position;

    /* Count spaces at current position */
    while (pos < p_state_in->fileSize)
    {
        char c = p_state_in->p_fileBuffer[pos];
        if (c == ' ')
        {
            indent++;
            pos++;
        }
        else if (c == '\t')
        {
            indent += 4; /* Treat tab as 4 spaces */
            pos++;
        }
        else
        {
            break;
        }
    }

    *p_indent_out = indent;
    return GCONST_TRUE;
}
