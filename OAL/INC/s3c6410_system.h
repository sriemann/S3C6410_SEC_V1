//
// Oal_system.h
//
// Processor Core Control Functions
//
//

#ifndef __S3C6410_SYSTEM_H
#define __S3C6410_SYSTEM_H

#if __cplusplus
extern "C" {
#endif

typedef struct __ClockInfo_
{
    UINT32  APLLCLK;
    UINT32  MPLLCLK;
    UINT32  ARMCLK;
    UINT32  HCLK;
    UINT32  PCLK;
} ClockInfo;

//------------------------------------------------------------------------------

void    System_EnableVIC(void);
void    System_DisableVIC(void);
void    System_EnableIRQ(void);
void    System_DisableIRQ(void);
void    System_EnableFIQ(void);
void    System_DisableFIQ(void);
void    System_EnableBP(void);
void    System_DisableBP(void);
void    System_EnableICache(void);
void    System_SetSyncMode(void);
void    System_SetAsyncMode(void);
void    System_WaitForInterrupt(void);
void    OALStall_us(UINT32 uSec);
void    OALStall_ms(UINT32 mSec);

void    ChangeDivider(UINT32);
void    ChangeToL1(UINT32);
void    ChangeToL0(UINT32);

UINT32 System_VCheckSyncMode();
UINT32 System_GetPCLK();
UINT32 System_GetHCLK();
UINT32 System_GetARMCLK();
UINT32 System_GetAPLLCLK();
UINT32 System_GetMPLLCLK();
void FillClockInfo(ClockInfo *stCI);

//------------------------------------------------------------------------------

#if __cplusplus
}
#endif

#endif    // __OAL_SYSTEM_H
