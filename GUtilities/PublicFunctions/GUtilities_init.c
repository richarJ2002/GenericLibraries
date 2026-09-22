/*
 *    @File:         GUtilities_init.c
 *
 *    @ Brief:       Function which loads the parameters into the GUtilities
 *                   struct
 *
 *    @ Date:        28/01/2024
 */

#include <signal.h>

/* Function Includes */
#include "GUtilities/PrivateFunctions/GUtilities_PrivateFunctions.h"

/* Structure Include */
#include "GUtilities/DataStructs/GUtilities_StateStructs.h"

/* Data include */
/* None */

/* Generic Libraries */
#include "GConst/GConst.h"
#include "GLog/GLog.h"
#include "GParserIni/GParserIni.h"
#include "GZero/GZero.h"

int GUtilities_init(const char *p_paramsFilePath)
{
  /* Defining local variables */
  dictionary   *dic;
  GParserIni_State GParserIni_state;

  /* Clearing local variables */
  GZero(&GParserIni_state, GParserIni_State);
  dic = NULL;

  /* Set signal handling for SIGINT */
  signal(SIGINT, GUtilities_sigintHandle);

  /* Loading parameters into dictionaries */
  dic = GParserIni_loadParams(&GParserIni_state, p_paramsFilePath);

  /* Check parameters are loaded */
  if (dic == NULL)
  {
    GError("Params weren't loaded correctly");
  }

  /* ---------------- Load parameters into Utilities struct ---------------- */

  GParserIni_loadDouble(&GParserIni_state,
                        dic,
                        &Utilities.simTimeEnd_s,
                        "TimeParameters:simTimeEnd");

  GParserIni_loadDouble(&GParserIni_state,
                        dic,
                        &Utilities.simTimeStep_s,
                        "TimeParameters:simTimeStep");

  GParserIni_loadDouble(&GParserIni_state,
                        dic,
                        &Utilities.simTime_s,
                        "TimeParameters:simTimeInitial");

  /* Set the simulation status to True */
  Utilities.runSimStatus = GCONST_TRUE;

  /* Close Params */
  GParserIni_closeParams(&GParserIni_state, dic);

  return GCONST_TRUE;
}