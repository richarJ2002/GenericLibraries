/*!
 * @file            GParserYaml_Const.h
 * @brief           Constants for the GParserYaml library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERYAML_CONSTANTDEFS_H
#define GENERICLIBRARIES_GPARSERYAML_CONSTANTDEFS_H

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
/* None */

/* -------------------------------------------------------------------------- *
 * BUFFER SIZES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Maximum length for a YAML key name.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_MAX_KEY_LENGTH             (128)

/*!
 * @brief           Maximum length for a YAML string value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_MAX_VALUE_LENGTH           (1024)

/*!
 * @brief           Maximum number of key-value pairs in a YAML mapping.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_MAX_KEY_VALUE_PAIRS        (512)

/*!
 * @brief           Maximum depth of nested YAML mappings/sequences.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_MAX_NESTING_DEPTH          (32)

/*!
 * @brief           Maximum file size for YAML parsing (1 MB).
 *
 * @frame           N/A
 * @unit            bytes
 */
#define GPARSERYAML_MAX_FILE_SIZE              (1048576)

/* -------------------------------------------------------------------------- *
 * YAML TOKEN TYPES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Token type for YAML string.
 */
#define GPARSERYAML_TOKEN_STRING               (1)

/*!
 * @brief           Token type for YAML number.
 */
#define GPARSERYAML_TOKEN_NUMBER               (2)

/*!
 * @brief           Token type for YAML boolean true.
 */
#define GPARSERYAML_TOKEN_TRUE                 (3)

/*!
 * @brief           Token type for YAML boolean false.
 */
#define GPARSERYAML_TOKEN_FALSE                (4)

/*!
 * @brief           Token type for YAML null.
 */
#define GPARSERYAML_TOKEN_NULL                 (5)

/*!
 * @brief           Token type for YAML mapping start.
 */
#define GPARSERYAML_TOKEN_MAPPING_START        (6)

/*!
 * @brief           Token type for YAML mapping end.
 */
#define GPARSERYAML_TOKEN_MAPPING_END          (7)

/*!
 * @brief           Token type for YAML sequence start.
 */
#define GPARSERYAML_TOKEN_SEQUENCE_START       (8)

/*!
 * @brief           Token type for YAML sequence end.
 */
#define GPARSERYAML_TOKEN_SEQUENCE_END         (9)

/*!
 * @brief           Token type for YAML key-value separator ':'.
 */
#define GPARSERYAML_TOKEN_COLON                (10)

/*!
 * @brief           Token type for YAML sequence item '-'.
 */
#define GPARSERYAML_TOKEN_DASH                 (11)

/*!
 * @brief           Token type for end of input.
 */
#define GPARSERYAML_TOKEN_EOF                  (12)

/* -------------------------------------------------------------------------- *
 * STATES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           State indicating parser is at the start or between tokens.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_START                (0)

/*!
 * @brief           State indicating parser is reading a key name.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_READING_KEY          (1)

/*!
 * @brief           State indicating parser is reading a string value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_READING_STRING       (2)

/*!
 * @brief           State indicating parser is reading a number value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_READING_NUMBER       (3)

/*!
 * @brief           State indicating parser is reading a boolean value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_READING_BOOL         (4)

/*!
 * @brief           State indicating parser is reading a null value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_READING_NULL         (5)

/*!
 * @brief           State indicating parser is inside a mapping.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_IN_MAPPING           (6)

/*!
 * @brief           State indicating parser is inside a sequence.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_IN_SEQUENCE          (7)

/*!
 * @brief           State indicating parsing is complete.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_FINISHED             (99)

/*!
 * @brief           State indicating a parsing error occurred.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERYAML_STATE_ERROR                (-1)

/* -------------------------------------------------------------------------- *
 * VALUE TYPES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Value type for YAML string.
 */
#define GPARSERYAML_VALUE_TYPE_STRING          (1)

/*!
 * @brief           Value type for YAML number.
 */
#define GPARSERYAML_VALUE_TYPE_NUMBER          (2)

/*!
 * @brief           Value type for YAML boolean.
 */
#define GPARSERYAML_VALUE_TYPE_BOOL            (3)

/*!
 * @brief           Value type for YAML null.
 */
#define GPARSERYAML_VALUE_TYPE_NULL            (4)

/*!
 * @brief           Value type for YAML mapping.
 */
#define GPARSERYAML_VALUE_TYPE_MAPPING         (5)

/*!
 * @brief           Value type for YAML sequence.
 */
#define GPARSERYAML_VALUE_TYPE_SEQUENCE        (6)

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERYAML_CONSTANTDEFS_H */