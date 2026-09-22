/*!
 * @file            GParserYaml_closeParams.c
 * @brief           Close parameters and free YAML memory.
 * @date            22/09/2026
 */

#include "GParserYaml_PublicFunctions.h"
#include "GParserYaml_PrivateFunctions.h"

int GParserYaml_closeParams(GParserYaml_State *p_state_inout)
{
    if (p_state_inout == NULL)
    {
        return GCONST_FALSE;
    }

    return GParserYaml_clearBuffers(p_state_inout);
}