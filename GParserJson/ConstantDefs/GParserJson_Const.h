/*!
 * @file            GParserJson_Const.h
 * @brief           Constants for the GParserJson library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERJSON_CONSTANTDEFS_H
#define GENERICLIBRARIES_GPARSERJSON_CONSTANTDEFS_H

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
 * @brief           Maximum length for a JSON key name.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_MAX_KEY_LENGTH             (128)

/*!
 * @brief           Maximum length for a JSON string value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_MAX_VALUE_LENGTH           (1024)

/*!
 * @brief           Maximum number of key-value pairs in a JSON object.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_MAX_KEY_VALUE_PAIRS        (512)

/*!
 * @brief           Maximum depth of nested JSON objects/arrays.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_MAX_NESTING_DEPTH          (32)

/*!
 * @brief           Maximum file size for JSON parsing (1 MB).
 *
 * @frame           N/A
 * @unit            bytes
 */
#define GPARSERJSON_MAX_FILE_SIZE              (1048576)

/* -------------------------------------------------------------------------- *
 * JSON TOKEN TYPES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Token type for JSON string.
 */
#define GPARSERJSON_TOKEN_STRING               (1)

/*!
 * @brief           Token type for JSON number.
 */
#define GPARSERJSON_TOKEN_NUMBER               (2)

/*!
 * @brief           Token type for JSON boolean true.
 */
#define GPARSERJSON_TOKEN_TRUE                 (3)

/*!
 * @brief           Token type for JSON boolean false.
 */
#define GPARSERJSON_TOKEN_FALSE                (4)

/*!
 * @brief           Token type for JSON null.
 */
#define GPARSERJSON_TOKEN_NULL                 (5)

/*!
 * @brief           Token type for JSON object start '{'.
 */
#define GPARSERJSON_TOKEN_OBJECT_START         (6)

/*!
 * @brief           Token type for JSON object end '}'.
 */
#define GPARSERJSON_TOKEN_OBJECT_END           (7)

/*!
 * @brief           Token type for JSON array start '['.
 */
#define GPARSERJSON_TOKEN_ARRAY_START          (8)

/*!
 * @brief           Token type for JSON array end ']'.
 */
#define GPARSERJSON_TOKEN_ARRAY_END            (9)

/*!
 * @brief           Token type for JSON colon ':'.
 */
#define GPARSERJSON_TOKEN_COLON                (10)

/*!
 * @brief           Token type for JSON comma ','.
 */
#define GPARSERJSON_TOKEN_COMMA                (11)

/*!
 * @brief           Token type for end of input.
 */
#define GPARSERJSON_TOKEN_EOF                  (12)

/* -------------------------------------------------------------------------- *
 * STATES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           State indicating parser is at the start or between tokens.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_START                (0)

/*!
 * @brief           State indicating parser is reading a key name.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_READING_KEY          (1)

/*!
 * @brief           State indicating parser is reading a string value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_READING_STRING       (2)

/*!
 * @brief           State indicating parser is reading a number value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_READING_NUMBER       (3)

/*!
 * @brief           State indicating parser is reading a boolean value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_READING_BOOL         (4)

/*!
 * @brief           State indicating parser is reading a null value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_READING_NULL         (5)

/*!
 * @brief           State indicating parser is inside an object.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_IN_OBJECT            (6)

/*!
 * @brief           State indicating parser is inside an array.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_IN_ARRAY             (7)

/*!
 * @brief           State indicating parsing is complete.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_FINISHED             (99)

/*!
 * @brief           State indicating a parsing error occurred.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERJSON_STATE_ERROR                (-1)

/* -------------------------------------------------------------------------- *
 * VALUE TYPES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Value type for JSON string.
 */
#define GPARSERJSON_VALUE_TYPE_STRING          (1)

/*!
 * @brief           Value type for JSON number.
 */
#define GPARSERJSON_VALUE_TYPE_NUMBER          (2)

/*!
 * @brief           Value type for JSON boolean.
 */
#define GPARSERJSON_VALUE_TYPE_BOOL            (3)

/*!
 * @brief           Value type for JSON null.
 */
#define GPARSERJSON_VALUE_TYPE_NULL            (4)

/*!
 * @brief           Value type for JSON object.
 */
#define GPARSERJSON_VALUE_TYPE_OBJECT          (5)

/*!
 * @brief           Value type for JSON array.
 */
#define GPARSERJSON_VALUE_TYPE_ARRAY           (6)

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERJSON_CONSTANTDEFS_H */