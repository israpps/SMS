/*
#     ___  _ _      ___
#    |    | | |    |
# ___|    |   | ___|    PS2DEV Open Source Project.
#----------------------------------------------------------
# (c) 2006-2008 Eugene Plotnikov <e-plotnikov@operamail.com>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
*/
#include "SMS_GUI.h"
#include "SMS_CDDA.h"
#include "SMS_CDVD.h"
#include "SMS_EE.h"
#include "SMS_RC.h"
#include "SMS_IOP.h"
#include "SMS_DSP.h"
#include "SMS_DMA.h"
#include "SMS_Locale.h"
#include "SMS_Config.h"
#include "SMS_History.h"
#include "SMS_OS.h"
#include "SMS_GS.h"
#include "SMS_PgInd.h"
#include "SMS_CDDA.h"
#include "SMS_VIF.h"
#include <kernel.h>
#include <sys/ioctl.h>
#include <fileio.h>

#ifdef DISABLE_EXTRA_TIMERS_FUNCTIONS
DISABLE_EXTRA_TIMERS_FUNCTIONS();
#endif

int main ( int argc, char** argv ) {
 GS_BGCOLOUR(BGR_PURPLE);
 if ( argc > 0 && argv[ 0 ][ 0 ] == 'm' && argv[ 0 ][ 1 ] == 'c' ) {

  char lSlot = argv[ 0 ][ 2 ];

  SMS_SetMCSlot ( lSlot );
  g_pIPConf   [ 2 ] = lSlot;
  g_pBXDATASYS[ 2 ] = lSlot;
  g_pSMSSkn   [ 2 ] = lSlot;
  g_pSMSRMMAN [ 2 ] = lSlot;
  g_pExec0    [ 2 ] = lSlot;
  g_pExec1    [ 2 ] = lSlot;
  g_MCSlot          = lSlot - '0';

 }  /* end if */

 SMS_IOPReset ( 0 );
 GS_BGCOLOUR(BGR_YELLOW);
 SMS_EEInit   ();
 GS_BGCOLOUR(BGR_BLUE);
 CDVD_Init    ();
 GS_BGCOLOUR(BGR_GREEN);
 CDDA_Init    ();

 GS_BGCOLOUR(BGR_WHITE);
 GUI_Initialize ( 1 );
 GS_BGCOLOUR(BGR_BLACK);
 SMS_PgIndStart ();
 GUI_Status ( STR_INITIALIZING_SMS.m_pStr );
#ifndef EMBEDDED
 if ( g_Config.m_BrowserFlags & SMS_BF_UXH ) SMS_OSInit ( argv[ 0 ] );
#endif  /* EMBEDDED */
 DPRINTF("SMS_IOPInit()\n");
 SMS_IOPInit     ();
 DPRINTF("SMS_EEPort2Init()\n");
 SMS_EEPort2Init ();
 DPRINTF("CDVD_SetSpeed()\n");
 CDVD_SetSpeed   ();

 if (  CDDA_DiskType () != DiskType_None  ) CDVD_Stop ();

 DPRINTF("SMS_LoadXLT()\n");
 SMS_LoadXLT ();
 DPRINTF("SMS_EEScanDir(g_pMC0SMS, g_pExtMBF, g_Config.m_pMBFList )\n");
 SMS_EEScanDir ( g_pMC0SMS, g_pExtMBF, g_Config.m_pMBFList );
 DPRINTF("SMS_HistoryLoad()\n");
 SMS_HistoryLoad ();
 DPRINTF("GUI_DeleteObject(g_pVerStr)\n");
 GUI_DeleteObject ( g_pVerStr );
 DPRINTF("SMS_PgIndStop()\n");
 SMS_PgIndStop ();

 DPRINTF("GUI_Run()\n");
 GUI_Run ();

 return 0;

}  /* end main */
