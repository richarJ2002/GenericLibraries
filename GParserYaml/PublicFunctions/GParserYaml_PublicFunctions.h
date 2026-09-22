/*!
 * @file            GParserYaml_PublicFunctions.h
 * @brief           Public function declarations for the GParserYaml library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERYAML_PUBLIC_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERYAML_PUBLIC_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
/* None */

/* External Library Includes */
/* None */

/* Module Includes */
#include "GParserYaml/GParserYaml.h"

/* Object Includes */
#include "GParserYaml/DataStructs/GParserYaml_StateStruct.h"
#include "GParserYaml/ConstantDefs/GParserYaml_Const.h"

/*!
 * @brief           Close parameters and free YAML memory.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserYaml state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_closeParams(GParserYaml_State *p_state_inout);

/*!
 * @brief           Load a double value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadDouble(GParserYaml_State *p_state_in, const char *p_key_in, double *p_value_out);

/*!
 * @brief           Load a double array from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
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
extern int GParserYaml_loadDoubleArray(GParserYaml_State *p_state_in, const char *p_key_in, double *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load a float value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadFloat(GParserYaml_State *p_state_in, const char *p_key_in, float *p_value_out);

/*!
 * @brief           Load a float array from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
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
extern int GParserYaml_loadFloatArray(GParserYaml_State *p_state_in, const char *p_key_in, float *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load an int8 value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadInt8(GParserYaml_State *p_state_in, const char *p_key_in, int8_t *p_value_out);

/*!
 * @brief           Load an int value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadInt(GParserYaml_State *p_state_in, const char *p_key_in, int *p_value_out);

/*!
 * @brief           Load an int array from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
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
extern int GParserYaml_loadIntArray(GParserYaml_State *p_state_in, const char *p_key_in, int *p_values_out, size_t maxCount_in, size_t *p_count_out);

/*!
 * @brief           Load parameters from a YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_filePath_in
 *                  Path to the YAML file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadParams(GParserYaml_State *p_state_in, const char *p_filePath_in);

/*!
 * @brief           Load a string value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       maxLen_in
 *                  Maximum length of the value buffer.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadString(GParserYaml_State *p_state_in, const char *p_key_in, char *p_value_out, size_t maxLen_in);

/*!
 * @brief           Load an unsigned int value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadUInt(GParserYaml_State *p_state_in, const char *p_key_in, unsigned int *p_value_out);

/*!
 * @brief           Load an unsigned 8-bit int value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadUInt8(GParserYaml_State *p_state_in, const char *p_key_in, uint8_t *p_value_out);

/*!
 * @brief           Load an unsigned 16-bit int value from the YAML file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserYaml state struct.
 * @param[in]       p_key_in
 *                  Key in format "Mapping.Key" (dot notation for nested mappings).
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserYaml_loadUInt16(GParserYaml_State *p_state_in, const char *p_key_in, uint16_t *p_value_out);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERYAML_PUBLIC_FUNCTIONS_H */