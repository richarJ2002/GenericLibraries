/*!
 * @file            GParserYaml_findKey.c
 * @brief           Find a value by key path in the parsed YAML.
 * @date            22/09/2026
 */

#include "GParserYaml_PrivateFunctions.h"
#include "GConst/GConst.h"

int GParserYaml_findKey(GParserYaml_Value *p_root_in, const char *p_keyPath_in, GParserYaml_Value **pp_value_out)
{
    char *p_keyCopy = NULL;
    char *p_token = NULL;
    char *p_savePtr = NULL;
    GParserYaml_Value *p_current = p_root_in;

    if (p_root_in == NULL || p_keyPath_in == NULL || pp_value_out == NULL)
    {
        return GCONST_FALSE;
    }

    /* Make a copy of the key string for tokenization */
    p_keyCopy = strdup(p_keyPath_in);
    if (p_keyCopy == NULL)
    {
        return GCONST_FALSE;
    }

    /* Tokenize by dot */
    p_token = strtok_r(p_keyCopy, ".", &p_savePtr);
    while (p_token != NULL)
    {
        if (p_current->type != GPARSERYAML_VALUE_TYPE_MAPPING)
        {
            free(p_keyCopy);
            return GCONST_FALSE;
        }

        int found = 0;
        int i;
    for (i = 0; i < p_current->numChildren; i++)
        {
            if (strcmp(p_current->p_children[i].key, p_token) == 0)
            {
                p_current = &p_current->p_children[i];
                found = 1;
                break;
            }
        }

        if (!found)
        {
            free(p_keyCopy);
            return GCONST_FALSE;
        }

        p_token = strtok_r(NULL, ".", &p_savePtr);
    }

    *pp_value_out = p_current;
    free(p_keyCopy);
    return GCONST_TRUE;
}
