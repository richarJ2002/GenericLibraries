/*!
 * @file            Dictionary.h
 * @brief           Dictionary structure for the GParserIni library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERINI_DATASTRUCTS_DICTIONARY_H
#define GENERICLIBRARIES_GPARSERINI_DATASTRUCTS_DICTIONARY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
/* None */

/* External Library Includes */
/* None */

/* Module Includes */
/* None */

/* Object Includes */
#include "GParserIni/ConstantDefs/GParserIni_Const.h"

/* Generic Libraries */
#include "GConst/GConst.h"

/* -------------------------------------------------------------------------- *
 * DICTIONARY STRUCTURE
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Dictionary structure containing section, keys, and values.
 */
typedef struct dictionaryStruct
{
    /*!
     * @brief           Buffer which contains the name of the section.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char section[GPARSERINI_SECTION_BUFFERSIZE];

    /*!
     * @brief           Array of strings which contain the key names for a section.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char key[GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER]
            [GPARSERINI_DICTIONARY_MAX_KEY_LENGTH];

    /*!
     * @brief           Array of strings which contain the value names for a section.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char value[GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER]
              [GPARSERINI_DICTIONARY_MAX_VALUE_LENGTH];

    /*!
     * @brief           Integer which contains the number of keys within a section.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int nKeys;

} dictionary;

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERINI_DATASTRUCTS_DICTIONARY_H */