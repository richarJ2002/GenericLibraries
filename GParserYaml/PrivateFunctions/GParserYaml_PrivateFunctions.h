/*!
 * @file            GParserYaml_PrivateFunctions.h
 * @brief           Private function definitions for the GParserYaml library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERYAML_PRIVATE_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERYAML_PRIVATE_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* External Library Includes */
/* None */

/* Module Includes */
#include "GParserYaml_PublicFunctions.h"

/* Object Includes */
#include "GParserYaml/DataStructs/GParserYaml_StateStruct.h"
#include "GParserYaml/ConstantDefs/GParserYaml_Const.h"

/*!
 * @brief           Clear parsing buffers in the state.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_clearBuffers(GParserYaml_State *p_state_inout);

/*!
 * @brief           Skip whitespace characters in the file buffer.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_skipWhitespace(GParserYaml_State *p_state_inout);

/*!
 * @brief           Parse a YAML string value.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_parseString(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Parse a YAML number value.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_parseNumber(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Parse a YAML value (string, number, bool, null, mapping, sequence).
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_parseValue(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Parse a YAML mapping (key-value pairs).
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed mapping value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_parseMapping(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Parse a YAML sequence (list).
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed sequence value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_parseSequence(GParserYaml_State *p_state_inout, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Find a value by key path in the parsed YAML.
 *
 * @param[in]       p_root_in
 *                  Root YAML value.
 * @param[in]       p_keyPath_in
 *                  Key path in dot notation (e.g., "Mapping.Key.SubKey").
 * @param[out]      pp_value_out
 *                  Pointer to receive the found value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_findKey(GParserYaml_Value *p_root_in, const char *p_keyPath_in, GParserYaml_Value **pp_value_out);

/*!
 * @brief           Allocate a new YAML value structure.
 *
 * @param[out]      pp_value_out
 *                  Pointer to receive the allocated value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_allocValue(GParserYaml_Value **pp_value_out);

/*!
 * @brief           Free a YAML value structure and its children.
 *
 * @param[in]       p_value_in
 *                  Value to free.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_freeValue(GParserYaml_Value *p_value_in);

/*!
 * @brief           Get current indentation level.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[out]      p_indent_out
 *                  Pointer to receive indentation level.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_getIndent(GParserYaml_State *p_state_in, int *p_indent_out);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERYAML_PRIVATE_FUNCTIONS_H */