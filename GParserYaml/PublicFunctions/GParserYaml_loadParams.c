/*!
 * @file            GParserYaml_loadParams.c
 * @brief           Load parameters from a YAML file.
 * @date            22/09/2026
 */

#include "GParserYaml_PublicFunctions.h"
#include "GParserYaml_PrivateFunctions.h"

int GParserYaml_loadParams(GParserYaml_State *p_state_in, const char *p_filePath_in)
{
    FILE *p_file = NULL;
    long fileSize = 0;
    size_t bytesRead = 0;
    int status;

    if (p_state_in == NULL || p_filePath_in == NULL)
    {
        return GCONST_FALSE;
    }

    /* Clear any existing state */
    GParserYaml_clearBuffers(p_state_in);

    /* Open file */
    p_file = fopen(p_filePath_in, "rb");
    if (p_file == NULL)
    {
        return GCONST_FALSE;
    }

    /* Get file size */
    fseek(p_file, 0, SEEK_END);
    fileSize = ftell(p_file);
    fseek(p_file, 0, SEEK_SET);

    if (fileSize <= 0 || fileSize > GPARSERYAML_MAX_FILE_SIZE)
    {
        fclose(p_file);
        return GCONST_FALSE;
    }

    /* Allocate buffer */
    p_state_in->p_fileBuffer = (char *)malloc(fileSize + 1);
    if (p_state_in->p_fileBuffer == NULL)
    {
        fclose(p_file);
        return GCONST_FALSE;
    }

    /* Read file */
    bytesRead = fread(p_state_in->p_fileBuffer, 1, fileSize, p_file);
    fclose(p_file);

    if (bytesRead != (size_t)fileSize)
    {
        free(p_state_in->p_fileBuffer);
        p_state_in->p_fileBuffer = NULL;
        return GCONST_FALSE;
    }

    p_state_in->p_fileBuffer[fileSize] = '\0';
    p_state_in->fileSize = fileSize;
    p_state_in->position = 0;
    p_state_in->lineNumber = 1;
    p_state_in->state = GPARSERYAML_STATE_START;
    p_state_in->depth = 0;
    p_state_in->indentLevel = 0;

    /* Parse YAML */
    status = GParserYaml_parseValue(p_state_in, &p_state_in->p_root);
    if (status != GCONST_TRUE || p_state_in->p_root == NULL)
    {
        GParserYaml_clearBuffers(p_state_in);
        return GCONST_FALSE;
    }

    return GCONST_TRUE;
}