/*!
 * @file            GParserJson_PublicFunctions.h
 * @brief           Public function declarations for the GParserJson library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERJSON_PUBLIC_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERJSON_PUBLIC_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
/* None */

/* External Library Includes */
/* None */

/* Module Includes */
#include "GParserJson/GParserJson.h"

/* Object Includes */
#include "GParserJson/DataStructs/GParserJson_StateStruct.h"
#include "GParserJson/ConstantDefs/GParserJson_Const.h"

/*!
 * @brief           Close parameters and free JSON memory.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserJson state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_closeParams(GParserJson_State *p_state_inout);

/*!
 * @brief           Load a double value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadDouble(GParserJson_State *p_state_in, const char *p_key_in, double *p_value_out);

/*!
 * @brief           Load a double array from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       maxCount_in
 *                  Maximum number of elements to load.
 * @param[out]      p_count_out
 *                  Pointer to store actual number of elements loaded.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadDoubleArray(GParserJson_State *p_state_in, const char *p_key_in, double *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load a float value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadFloat(GParserJson_State *p_state_in, const char *p_key_in, float *p_value_out);

/*!
 * @brief           Load a float array from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       maxCount_in
 *                  Maximum number of elements to load.
 * @param[out]      p_count_out
 *                  Pointer to store actual number of elements loaded.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadFloatArray(GParserJson_State *p_state_in, const char *p_key_in, float *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load an int8 value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadInt8(GParserJson_State *p_state_in, const char *p_key_in, int8_t *p_value_out);

/*!
 * @brief           Load an int value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadInt(GParserJson_State *p_state_in, const char *p_key_in, int *p_value_out);

/*!
 * @brief           Load an int array from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       maxCount_in
 *                  Maximum number of elements to load.
 * @param[out]      p_count_out
 *                  Pointer to store actual number of elements loaded.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadIntArray(GParserJson_State *p_state_in, const char *p_key_in, int *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load parameters from a JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_filePath_in
 *                  Path to the JSON file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadParams(GParserJson_State *p_state_in, const char *p_filePath_in);

/*!
 * @brief           Load a string value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       maxLen_in
 *                  Maximum length of the value buffer.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadString(GParserJson_State *p_state_in, const char *p_key_in, char *p_value_out, size_t maxLen_in);

/*!
 * @brief           Load an unsigned int value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadUInt(GParserJson_State *p_state_in, const char *p_key_in, unsigned int *p_value_out);

/*!
 * @brief           Load an unsigned 8-bit int value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadUInt8(GParserJson_State *p_state_in, const char *p_key_in, uint8_t *p_value_out);

/*!
 * @brief           Load an unsigned 16-bit int value from the JSON file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserJson state struct.
 * @param[in]       p_key_in
 *                  Key in format "Object.Key" (dot notation for nested objects).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserJson_loadUInt16(GParserJson_State *p_state_in, const char *p_key_in, uint16_t *p_value_out);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERJSON_PUBLIC_FUNCTIONS_H */