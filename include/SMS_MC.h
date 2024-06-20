/*
#     ___  _ _      ___
#    |    | | |    |
# ___|    |   | ___|    PS2DEV Open Source Project.
#----------------------------------------------------------
# (c) 200X ps2dev -> http://www.ps2dev.org
# Adopted for SMS in 2006 by Eugene Plotnikov <e-plotnikov@operamail.com>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
*/
#ifndef __SMS_MC_H
#define __SMS_MC_H
#include <libmc.h>

// rename all SMS nonsense
#define MC_Sync(x) mcSync(0, NULL, x)
#define MC_OpenS mcOpen
#define MC_SeekS mcSeek
#define MC_ReadS mcRead
#define MC_CloseS mcClose

#define SMS_MCTable sceMcTblGetDir

#define SMS_MCIcon mcIcon
 #define m_Header head
 #define m_Title title
 #define m_Offset nlOffset
 #define m_Trans trans
 #define m_ClrBg bgCol
 #define m_LightDir lightDir
 #define m_LightCol lightCol
 #define m_LightAmb lightAmbient
 #define m_View view
 #define m_Copy copy
 #define m_Del  del

#define MC_GetInfo mcGetInfo
#define MC_GetDir mcGetDir

#define MC_Init(x...) mcInit(MC_TYPE_XMC)

#endif  /* __SMS_MC_H */
