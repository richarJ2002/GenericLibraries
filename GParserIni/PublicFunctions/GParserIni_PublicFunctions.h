/*!
 * @file            GParserIni_PublicFunctions.h
 * @brief           Public function declarations for the GParserIni library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERINI_PUBLIC_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERINI_PUBLIC_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
/* None */

/* External Library Includes */
/* None */

/* Module Includes */
#include "GParserIni/GParserIni.h"

/* Object Includes */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/*!
 * @brief           Close parameters and free dictionary memory.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_closeParams(GParserIni_State *p_state_inout, dictionary *p_dic_in);

/*!
 * @brief           Load a double value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadDouble(GParserIni_State *p_state_in, dictionary *p_dic_in, double *p_value_out, const char *p_key_in);

/*!
 * @brief           Load a double array from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 * @param[in]       nCols_in
 *                  Number of columns in the array.
 * @param[in]       nRows_in
 *                  Number of rows in the array.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadDoubleArray(GParserIni_State *p_state_in, dictionary *p_dic_in, double *p_values_out, const char *p_key_in, int nCols_in, int nRows_in);

/*!
 * @brief           Load a float value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadFloat(GParserIni_State *p_state_in, dictionary *p_dic_in, float *p_value_out, const char *p_key_in);

/*!
 * @brief           Load a float array from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 * @param[in]       nCols_in
 *                  Number of columns in the array.
 * @param[in]       nRows_in
 *                  Number of rows in the array.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadFloatArray(GParserIni_State *p_state_in, dictionary *p_dic_in, float *p_values_out, const char *p_key_in, int nCols_in, int nRows_in);

/*!
 * @brief           Load an int8 value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadInt8(GParserIni_State *p_state_in, dictionary *p_dic_in, int8_t *p_value_out, const char *p_key_in);

/*!
 * @brief           Load an int value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadInt(GParserIni_State *p_state_in, dictionary *p_dic_in, int *p_value_out, const char *p_key_in);

/*!
 * @brief           Load an int array from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_values_out
 *                  Pointer to array to store loaded values.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 * @param[in]       nCols_in
 *                  Number of columns in the array.
 * @param[in]       nRows_in
 *                  Number of rows in the array.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadIntArray(GParserIni_State *p_state_in, dictionary *p_dic_in, int *p_values_out, const char *p_key_in, int nCols_in, int nRows_in);

/*!
 * @brief           Load parameters from an INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_filePath_in
 *                  Path to the INI file.
 *
 * @return          Pointer to dictionary array on success, NULL on error.
 */
extern dictionary *GParserIni_loadParams(GParserIni_State *p_state_in, const char *p_filePath_in);

/*!
 * @brief           Load a string value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadString(GParserIni_State *p_state_in, dictionary *p_dic_in, char *p_value_out, const char *p_key_in);

/*!
 * @brief           Load an unsigned int value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadUInt(GParserIni_State *p_state_in, dictionary *p_dic_in, unsigned int *p_value_out, const char *p_key_in);

/*!
 * @brief           Load an unsigned 8-bit int value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadUInt8(GParserIni_State *p_state_in, dictionary *p_dic_in, uint8_t *p_value_out, const char *p_key_in);

/*!
 * @brief           Load an unsigned 16-bit int value from the INI file.
 *
 * @param[in]       p_state_in
 *                  Pointer to GParserIni state struct.
 * @param[in]       p_dic_in
 *                  Pointer to dictionary with sections loaded.
 * @param[out]      p_value_out
 *                  Pointer to store the loaded value.
 * @param[in]       p_key_in
 *                  Key in format "Section:Key".
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadUInt16(GParserIni_State *p_state_in, dictionary *p_dic_in, uint16_t *p_value_out, const char *p_key_in);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERINI_PUBLIC_FUNCTIONS_H */