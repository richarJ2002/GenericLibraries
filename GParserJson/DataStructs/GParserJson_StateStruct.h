/*!
 * @file            GParserJson_StateStruct.h
 * @brief           State structure for the GParserJson library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERJSON_DATASTRUCTS_GPARSERJSON_STATESTRUCT_H
#define GENERICLIBRARIES_GPARSERJSON_DATASTRUCTS_GPARSERJSON_STATESTRUCT_H

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
#include "GParserJson/ConstantDefs/GParserJson_Const.h"

/* Generic Libraries */
/* None */

/* -------------------------------------------------------------------------- *
 * JSON VALUE STRUCTURE
 * -------------------------------------------------------------------------- */

/*!
 * @brief           JSON value structure (variant type).
 */
typedef struct GParserJson_ValueStruct
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
    char stringValue[GPARSERJSON_MAX_VALUE_LENGTH];

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
     * @brief           Child values for objects/arrays.
     *
     * @frame           N/A
     * @unit            N/A
     */
    struct GParserJson_ValueStruct *p_children;

    /*!
     * @brief           Number of child values.
     *
     * @frame           N/A
     * @unit            N/A
     */
    int numChildren;

    /*!
     * @brief           Key name for object members.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char key[GPARSERJSON_MAX_KEY_LENGTH];

} GParserJson_Value;

/* -------------------------------------------------------------------------- *
 * STATE STRUCTURE
 * -------------------------------------------------------------------------- */

/*!
 * @brief           GParserJson state structure.
 */
typedef struct GParserJson_StateStruct
{
    /*!
     * @brief           Root JSON value.
     *
     * @frame           N/A
     * @unit            N/A
     */
    GParserJson_Value *p_root;

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
     * @brief           Buffer for key name during parsing.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char keyBuffer[GPARSERJSON_MAX_KEY_LENGTH];

    /*!
     * @brief           Buffer for value during parsing.
     *
     * @frame           N/A
     * @unit            N/A
     */
    char valueBuffer[GPARSERJSON_MAX_VALUE_LENGTH];

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
    GParserJson_Value *p_contextStack[GPARSERJSON_MAX_NESTING_DEPTH];

} GParserJson_State;

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERJSON_DATASTRUCTS_GPARSERJSON_STATESTRUCT_H */