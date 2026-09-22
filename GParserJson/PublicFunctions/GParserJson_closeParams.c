/*!
 * @file            GParserJson_closeParams.c
 * @brief           Close parameters and free JSON memory.
 * @date            22/09/2026
 */

#include "GParserJson_PublicFunctions.h"
#include "GParserJson_PrivateFunctions.h"

int GParserJson_closeParams(GParserJson_State *p_state_inout)
{
    if (p_state_inout == NULL)
    {
        return GCONST_FALSE;
    }

    return GParserJson_clearBuffers(p_state_inout);
}