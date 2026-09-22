/*!
 * @file            GParserJson_PrivateFunctions.h
 * @brief           Private function definitions for the GParserJson library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERJSON_PRIVATE_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERJSON_PRIVATE_FUNCTIONS_H

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
#include "GParserJson_PublicFunctions.h"

/* Object Includes */
#include "GParserJson/DataStructs/GParserJson_StateStruct.h"
#include "GParserJson/ConstantDefs/GParserJson_Const.h"

/*!
 * @brief           Clear parsing buffers in the state.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_clearBuffers(GParserJson_State *p_state_inout);

/*!
 * @brief           Skip whitespace characters in the file buffer.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_skipWhitespace(GParserJson_State *p_state_inout);

/*!
 * @brief           Parse a JSON string value.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_parseString(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out);

/*!
 * @brief           Parse a JSON number value.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_parseNumber(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out);

/*!
 * @brief           Parse a JSON value (string, number, bool, null, object, array).
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_parseValue(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out);

/*!
 * @brief           Parse a JSON object.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed object value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_parseObject(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out);

/*!
 * @brief           Parse a JSON array.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 * @param[out]      pp_value_out
 *                  Pointer to receive the parsed array value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_parseArray(GParserJson_State *p_state_inout, GParserJson_Value **pp_value_out);

/*!
 * @brief           Find a value by key path in the parsed JSON.
 *
 * @param[in]       p_root_in
 *                  Root JSON value.
 * @param[in]       p_keyPath_in
 *                  Key path in dot notation (e.g., "Object.Key.SubKey").
 * @param[out]      pp_value_out
 *                  Pointer to receive the found value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_findKey(GParserJson_Value *p_root_in, const char *p_keyPath_in, GParserJson_Value **pp_value_out);

/*!
 * @brief           Allocate a new JSON value structure.
 *
 * @param[out]      pp_value_out
 *                  Pointer to receive the allocated value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_allocValue(GParserJson_Value **pp_value_out);

/*!
 * @brief           Free a JSON value structure and its children.
 *
 * @param[in]       p_value_in
 *                  Value to free.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_freeValue(GParserJson_Value *p_value_in);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERJSON_PRIVATE_FUNCTIONS_H */