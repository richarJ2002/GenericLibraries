/*!
 * @file            GParserIni_Const.h
 * @brief           Constants for the GParserIni library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERINI_CONSTANTDEFS_H
#define GENERICLIBRARIES_GPARSERINI_CONSTANTDEFS_H

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
 * @brief           Constant used for declaring memory to the buffer which will
 *                  contain the section name when a section is being loaded.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_SECTION_BUFFERSIZE (1024)

/*!
 * @brief           Constant used for declaring memory to the buffer which will
 *                  contain the section name when a key from a section is being
 *                  loaded from an ini file.
 *
 *                  NOTE: The buffer holds all keys in one long array before it gets
 *                  separated into a dictionary. Hence, the maximum the buffer
 *                  needs to be to fill up a dictionary section is the product
 *                  of the two constants below.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_KEY_BUFFERSIZE                                                 \
  (GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER *                             \
   GPARSERINI_DICTIONARY_MAX_KEY_LENGTH)

/*!
 * @brief           Constant used for declaring memory to the buffer which will
 *                  contain the section name when a value from a section is being
 *                  loaded from an ini file.
 *
 *                  NOTE: The buffer holds all values in one long array before it
 *                  gets separated into a dictionary. Hence, the maximum the
 *                  buffer needs to be to fill up a dictionary section is the
 *                  product of the two constants below.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_VALUE_BUFFERSIZE                                               \
  (GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER *                             \
   GPARSERINI_DICTIONARY_MAX_VALUE_LENGTH)

/*!
 * @brief           Constant used for assigning memory on the stack to a buffer
 *                  which holds the section when an array is being loaded from an
 *                  ini file.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_LOAD_ARRAY_SECTION_BUFFER             (256)

/*!
 * @brief           Constant used for assigning memory on the stack to a buffer
 *                  which holds the keys when an array is being loaded from an ini
 *                  file.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_LOAD_ARRAY_KEY_INPUT_BUFFER           (256)

/*!
 * @brief           Constant used for assigning memory on the stack to a buffer
 *                  which holds the keys when an array is being loaded from an ini
 *                  file.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_LOAD_ARRAY_DATA_TO_LOAD_BUFFER        (256)

/* -------------------------------------------------------------------------- *
 * DICTIONARY CONSTANTS
 * -------------------------------------------------------------------------- */

/*!
 * @brief           Constant to indicate the maximum number of keys a dictionary can
 *                  hold, along with the maximum number of its corresponding pair.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_DICTIONARY_MAX_KEY_VALUE_PAIRS_NUMBER (512)

/*!
 * @brief           Constant which is used to indicate the maximum length a key can
 *                  be.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_DICTIONARY_MAX_KEY_LENGTH             (64)

/*!
 * @brief           Constant which is used to indicate the maximum length a value
 *                  can be.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_DICTIONARY_MAX_VALUE_LENGTH           (64)

/* -------------------------------------------------------------------------- *
 * STATES
 * -------------------------------------------------------------------------- */

/*!
 * @brief           State which is used to indicate that the parser is waiting for a
 *                  command.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_WAITING_FOR_COMMAND             (0)

/*!
 * @brief           State to indicate that the parser is waiting for a new line.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_WAITING_NEWLINE                 (1)

/*!
 * @brief           State to indicate that the parser is currently reading a
 *                  comment. This differs from waiting to a new line as that will
 *                  throw errors if text is encountered. This just waits for a '\n'.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_COMMENT                         (2)

/*!
 * @brief           State to indicate that the parser is loading a section.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_LOADING_SECTION                 (10)

/*!
 * @brief           State to indicate that the parser is loading a key.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_LOADING_KEY                     (20)

/*!
 * @brief           State to indicate that the parser is waiting for an equals. It
 *                  will throw an error unless the character it is reading is a '\t'
 *                  or a space, in which it will do nothing. Once an equals is
 *                  reached, the state gets updated.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_KEY_WAITING_FOR_EQUALS          (21)

/*!
 * @brief           State to indicate that the parser is waiting for a value.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_WAITING_VALUE                   (22)

/*!
 * @brief           State to indicate that a value is being loaded into the parser.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_LOADING_VALUE                   (23)

/*!
 * @brief           State to indicate that a string is being loaded, and hence is
 *                  less restrictive on what is considered an invalid character.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_LOADING_STRING_VALUE            (24)

/*!
 * @brief           State to indicate that the parser has finished parsing the ini
 *                  file and break the while loop.
 *
 * @frame           N/A
 * @unit            N/A
 */
#define GPARSERINI_STATE_FINISHED                        (99)

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERINI_CONSTANTDEFS_H */