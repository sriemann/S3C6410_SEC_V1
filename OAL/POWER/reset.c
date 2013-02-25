//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
// NOTE: stubs are being used - this isn't done

#include <windows.h>
#include <ceddk.h>
#include <nkintr.h>
#include <oal.h>

// Base Definitions
#include "s3c6410_base_regs.h"
#include "s3c6410_pwm.h"
#include "s3c6410_syscon.h"
#include "soc_cfg.h"
#include <pmplatform.h>

extern void _OEMSWReset(void);


void OEMSWReset(void)
{
//
// If the board design supports software-controllable hardware reset logic, it should be
// used.  Because this routine is specific to the S3C6410 CPU, it only uses the watchdog
// timer to assert reset.  One downside to this approach is that nRSTOUT isn't asserted
// so any board-level logic isn't reset via this method.  This routine can be overidden in
// the specific platform code to control board-level reset logic, should it exist.
//

    volatile S3C6410_SYSCON_REG *pSysConReg = (S3C6410_SYSCON_REG *)OALPAtoVA(S3C6410_BASE_REG_PA_SYSCON, FALSE);

    OALMSG(TRUE, (L"[OEM] ++OEMSWReset()\r\n"));

    // HCLK_IROM, HCLK_MEM1, HCLK_MEM0, HCLK_MFC Should be Always On for power Mode (Something coupled with BUS operation)
    pSysConReg->HCLK_GATE |= ((1<<25)|(1<<22)|(1<<21)|(1<<0));

    OALMSG(TRUE, (L"[OEM] + OEMSWReset() using watchdog timer\r\n"));
    // Generate Software Reset using watchdog timer
    _OEMSWReset();

   

    // Wait for Reset
    //
    while(1);

    // Should Never Get Here
    //
    OALMSG(TRUE, (L"[OEM] --OEMSWReset() : Do Not See Me !!!!!! \r\n"));
}

//------------------------------------------------------------------------------

