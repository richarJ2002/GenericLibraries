/*!
 * @file            GParserJson_freeValue.c
 * @brief           Free a JSON value structure and its children.
 * @date            22/09/2026
 */

#include "GParserJson_PrivateFunctions.h"
#include "GConst/GConst.h"

/*!
 * @brief           Recursively free children arrays of a JSON value.
 *
 *                  This function frees the p_children arrays of the value
 *                  and all its descendants, but does NOT free the value itself.
 *                  The caller is responsible for freeing the value.
 *
 * @param[in]       p_value_in
 *                  Pointer to JSON value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
static int GParserJson_freeChildren(GParserJson_Value *p_value_in)
{
    int i;

    if (p_value_in == NULL)
    {
        return GCONST_FALSE;
    }

    if (p_value_in->p_children != NULL)
    {
        for (i = 0; i < p_value_in->numChildren; i++)
        {
            /* Recursively free children's children arrays */
            GParserJson_freeChildren(&p_value_in->p_children[i]);
        }
        /* Free the children array itself */
        free(p_value_in->p_children);
        p_value_in->p_children = NULL;
    }

    return GCONST_TRUE;
}

int GParserJson_freeValue(GParserJson_Value *p_value_in)
{
    if (p_value_in == NULL)
    {
        return GCONST_FALSE;
    }

    /* Free all children arrays recursively */
    GParserJson_freeChildren(p_value_in);

    /* Free the value itself */
    free(p_value_in);
    return GCONST_TRUE;
}