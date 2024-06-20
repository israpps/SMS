/*
#     ___  _ _      ___
#    |    | | |    |
# ___|    |   | ___|    PS2DEV Open Source Project.
#----------------------------------------------------------
# (c) 200X ps2dev -> http://www.ps2dev.org
# Adopted for SMS in 2005/6 by Eugene Plotnikov <e-plotnikov@operamail.com>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
*/
#ifndef __SMS_PAD_H
#define __SMS_PAD_H

#include <libpad.h>
int ReadCombinedPadStatus(void);
int ReadPadStatus(int port, int slot);
int ReadPadStatus_raw(int port, int slot);
int ReadCombinedPadStatus_raw(void);
void PadDeinitPads(void);
void PadInitPads(void);
#define SMS_PadButtonStatus padButtonStatus
#define PAD_Init() PadInitPads()
#define PAD_Quit() PadDeinitPads()

#define PAD_OpenPort(a,b,c) //padPortOpen(a,b,c)
#define PAD_ClosePort(a,b) //padPortClose(a,b)

#define PAD_ReqState padGetReqState
#define PAD_SetReqState padSetReqState
#define PAD_State padGetState
#define PAD_Read ReadPadStatus_raw
#define PAD_SetMainMode padSetMainMode


#define SMS_PAD_LEFT PAD_LEFT
#define SMS_PAD_DOWN PAD_DOWN
#define SMS_PAD_RIGHT PAD_RIGHT
#define SMS_PAD_UP PAD_UP
#define SMS_PAD_START PAD_START
#define SMS_PAD_R3 PAD_R3
#define SMS_PAD_L3 PAD_L3
#define SMS_PAD_SELECT PAD_SELECT
#define SMS_PAD_SQUARE PAD_SQUARE
#define SMS_PAD_CROSS PAD_CROSS
#define SMS_PAD_CIRCLE PAD_CIRCLE
#define SMS_PAD_TRIANGLE PAD_TRIANGLE
#define SMS_PAD_R1 PAD_R1
#define SMS_PAD_L1 PAD_L1
#define SMS_PAD_R2 PAD_R2
#define SMS_PAD_L2 PAD_L2


#define SMS_PAD_STATE_DISCONN  PAD_STATE_DISCONN 
#define SMS_PAD_STATE_FINDPAD  PAD_STATE_FINDPAD 
#define SMS_PAD_STATE_FINDCTP1 PAD_STATE_FINDCTP1
#define SMS_PAD_STATE_EXECCMD  PAD_STATE_EXECCMD 
#define SMS_PAD_STATE_STABLE   PAD_STATE_STABLE  
#define SMS_PAD_STATE_ERROR    PAD_STATE_ERROR   

#define SMS_PAD_RSTAT_COMPLETE PAD_RSTAT_COMPLETE
#define SMS_PAD_RSTAT_FAILED   PAD_RSTAT_FAILED  
#define SMS_PAD_RSTAT_BUSY     PAD_RSTAT_BUSY    

#define SMS_PAD_MMODE_DIGITAL   PAD_MMODE_DIGITAL  
#define SMS_PAD_MMODE_DUALSHOCK PAD_MMODE_DUALSHOCK

#define SMS_PAD_MMODE_UNLOCK PAD_MMODE_UNLOCK
#define SMS_PAD_MMODE_LOCK   PAD_MMODE_LOCK  


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#if 0
#define SMS_PAD_LEFT      0x0080
#define SMS_PAD_DOWN      0x0040
#define SMS_PAD_RIGHT     0x0020
#define SMS_PAD_UP        0x0010
#define SMS_PAD_START     0x0008
#define SMS_PAD_R3        0x0004
#define SMS_PAD_L3        0x0002
#define SMS_PAD_SELECT    0x0001
#define SMS_PAD_SQUARE    0x8000
#define SMS_PAD_CROSS     0x4000
#define SMS_PAD_CIRCLE    0x2000
#define SMS_PAD_TRIANGLE  0x1000
#define SMS_PAD_R1        0x0800
#define SMS_PAD_L1        0x0400
#define SMS_PAD_R2        0x0200
#define SMS_PAD_L2        0x0100

#define SMS_PAD_STATE_DISCONN  0x00
#define SMS_PAD_STATE_FINDPAD  0x01
#define SMS_PAD_STATE_FINDCTP1 0x02
#define SMS_PAD_STATE_EXECCMD  0x05
#define SMS_PAD_STATE_STABLE   0x06
#define SMS_PAD_STATE_ERROR    0x07

#define SMS_PAD_RSTAT_COMPLETE 0x00
#define SMS_PAD_RSTAT_FAILED   0x01
#define SMS_PAD_RSTAT_BUSY     0x02

#define SMS_PAD_MMODE_DIGITAL   0
#define SMS_PAD_MMODE_DUALSHOCK 1

#define SMS_PAD_MMODE_UNLOCK 0
#define SMS_PAD_MMODE_LOCK   3

typedef struct SMS_PadButtonStatus {

 unsigned char  m_OK;
 unsigned char  m_Mode;
 unsigned short m_Btns         __attribute__(  ( packed )  );
 unsigned char  m_RJoyH;
 unsigned char  m_RJoyV;
 unsigned char  m_LJoyH;
 unsigned char  m_LJoyV;
 unsigned char  m_RightP;
 unsigned char  m_LeftP;
 unsigned char  m_UpP;
 unsigned char  m_DownP;
 unsigned char  m_TriangleP;
 unsigned char  m_CircleP;
 unsigned char  m_CrossP;
 unsigned char  m_SquareP;
 unsigned char  m_L1P;
 unsigned char  m_R1P;
 unsigned char  m_L2P;
 unsigned char  m_R2P;
 unsigned char  m_Unkn16[ 12 ];

} SMS_PadButtonStatus;
int PAD_Init ( void );
int PAD_Quit ( void );

int PAD_OpenPort  ( int, int, void* );
int PAD_ClosePort ( int, int        );

unsigned char  PAD_ReqState    ( int, int           );
void           PAD_SetReqState ( int, int, int      );
int            PAD_State       ( int, int           );
unsigned short PAD_Read        ( int, int           );
int            PAD_SetMainMode ( int, int, int, int );

#ifdef __cplusplus
}
#endif
#endif  /* __cplusplus */
#endif  /* __SMS_PAD_H */
