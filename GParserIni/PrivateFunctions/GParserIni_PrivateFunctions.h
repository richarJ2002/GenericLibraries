/*!
 * @file            GParserIni_PrivateFunctions.h
 * @brief           Private function definitions for the GParserIni library.
 * @date            22/09/2026
 */

#ifndef GENERICLIBRARIES_GPARSERINI_PRIVATE_FUNCTIONS_H
#define GENERICLIBRARIES_GPARSERINI_PRIVATE_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard Library Includes */
#include <stdint.h>
#include <stdio.h>

/* External Library Includes */
/* None */

/* Module Includes */
/* None */

/* Object Includes */
#include "GParserIni/DataStructs/Dictionary.h"
#include "GParserIni/DataStructs/GParserIni_StateStruct.h"

/*!
 * @brief           Clear parsing buffers in the state.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_clearBuffers(GParserIni_State *p_state_inout);

/*!
 * @brief           Handle comment state during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_comment(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Find the total number of sections in an INI file.
 *
 * @param[in]       p_file_in
 *                  File pointer to the INI file.
 * @param[out]      p_maxSections_out
 *                  Pointer to receive the maximum number of sections.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_findNumberOfSections(FILE *p_file_in, uint8_t *p_maxSections_out);

/*!
 * @brief           Load a dictionary for a section from the INI file.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 *
 * @return          Dictionary struct containing the section data.
 */
extern dictionary GParserIni_loadDictionary(GParserIni_State *p_state_inout);

/*!
 * @brief           Load a key during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadingKey(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Load a section during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadingSection(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Load a string value during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadingStringValue(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Load a value during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_loadingValue(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Wait for equals sign during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_waitingEquals(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Wait for command during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_waitingForCommand(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Wait for new line during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_waitingForNewLine(GParserIni_State *p_state_inout, const char cursor_in);

/*!
 * @brief           Wait for value during parsing.
 *
 * @param[inout]    p_state_inout
 *                  Pointer to GParserIni state struct.
 * @param[in]       cursor_in
 *                  Current character from the INI file.
 *
 * @retval          GCONST_TRUE on success.
 * @retval          GCONST_FALSE on error.
 */
extern int GParserIni_waitingValue(GParserIni_State *p_state_inout, const char cursor_in);

#ifdef __cplusplus
}
#endif

#endif /* GENERICLIBRARIES_GPARSERINI_PRIVATE_FUNCTIONS_H */