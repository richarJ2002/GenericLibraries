/*!
 * @file            GParserYaml_StateStruct.h
 * @brief           State structure for the GParserYaml library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERYAML_DATASTRUCTS_GPARSERYAML_STATESTRUCT_H
#define GENERICLIBRARIES_GPARSERYAML_DATASTRUCTS_GPARSERYAML_STATESTRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
#include <stdint.h>
#include <stddef.h>

/* External Library Includes */
/* None */

/* Module Includes */
/* None */

/* Object Includes */
#include "GParserYaml/ConstantDefs/GParserYaml_Const.h"

/* Generic Libraries */
/* None */

/* -------------------------------------------------------------------------- *
 * YAML VALUE STRUCTURE
 * -------------------------------------------------------------------------- */

/*!
 * @brief           YAML value structure (variant type).
 */
typedef struct GParserYaml_ValueStruct
{
    /*!
     * @brief           Type of the value.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int type;

    /*!
     * @brief           String value (for strings).
     *
     * @frame           N/A
     * @unit            N/A
     */
    char stringValue[GPARSERYAML_MAX_VALUE_LENGTH];

    /*!
     * @brief           Number value (for numbers).
     *
     * @frame           N/A
     * @unit            N/A
     */
    double numberValue;

    /*!
     * @brief           Boolean value (for true/false).
     *
     * @frame           N/A
     * @unit            N/A
     */
    int boolValue;

    /*!
     * @brief           Child values for mappings/sequences.
     *
     * @frame           N/A
     * @unit            N/A
     */
    struct GParserYaml_ValueStruct *p_children;

    /*!
     * @brief           Number of child values.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int numChildren;

    /*!
     * @brief           Key name for mapping members.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char key[GPARSERYAML_MAX_KEY_LENGTH];

} GParserYaml_Value;

/* -------------------------------------------------------------------------- *
 * STATE STRUCTURE
 * -------------------------------------------------------------------------- */

/*!
 * @brief           GParserYaml state structure.
 */
typedef struct GParserYaml_StateStruct
{
    /*!
     * @brief           Root YAML value.
     *
     * @frame           N/A
     * @unit            N/A
     */
    GParserYaml_Value *p_root;

    /*!
     * @brief           File buffer for parsing.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char *p_fileBuffer;

    /*!
     * @brief           Size of file buffer.
     *
     * @frame           N/A
     * @unit            bytes
     */
    size_t fileSize;

    /*!
     * @brief           Current position in file buffer.
     *
     * @frame           N/A
     * @unit            N/A
     */
    size_t position;

    /*!
     * @brief           Current line number (for error reporting).
     *
     * @frame           N/A
     * @unit            N/A
     */
    int lineNumber;

    /*!
     * @brief           Current parsing state.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int state;

    /*!
     * @brief           Current nesting depth.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int depth;

    /*!
     * @brief           Current indentation level.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int indentLevel;

    /*!
     * @brief           Buffer for key name during parsing.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char keyBuffer[GPARSERYAML_MAX_KEY_LENGTH];

    /*!
     * @brief           Buffer for value during parsing.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char valueBuffer[GPARSERYAML_MAX_VALUE_LENGTH];

    /*!
     * @brief           Current key index.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int keyIndex;

    /*!
     * @brief           Current value index.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int valueIndex;

    /*!
     * @brief           Stack for nested parsing contexts.
     *
     * @frame           N/A
     * @unit            N/A
     */
    GParserYaml_Value *p_contextStack[GPARSERYAML_MAX_NESTING_DEPTH];

} GParserYaml_State;

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERYAML_DATASTRUCTS_GPARSERYAML_STATESTRUCT_H */