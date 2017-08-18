/**************************************************************************//**
 * @file     ld_boot.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 14/09/12 5:03p $
 * @brief    Show how to branch programs between LDROM, APROM start page,
 *           and APROM other page.
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "Nano100Series.h"
#include "map.h"


#ifdef __ARMCC_VERSION
__asm __set_SP(uint32_t _sp)
{
    MSR MSP, r0
    BX lr
}
#endif


void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK->PWRCTL &= ~CLK_PWRCTL_HXT_EN_Msk;
    CLK->PWRCTL |= (0x1 << CLK_PWRCTL_HXT_EN_Pos); // HXT Enabled

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HXT;

    /* Enable IP clock */
    CLK->APBCLK |= CLK_APBCLK_UART0_EN; // UART0 Clock Enable

    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD and TXD  */
    //SYS->PB_L_MFP &= ~(SYS_PB_L_MFP_PB0_MFP_Msk | SYS_PB_L_MFP_PB1_MFP_Msk);
    //SYS->PB_L_MFP |= (SYS_PB_L_MFP_PB0_MFP_UART0_TX | SYS_PB_L_MFP_PB1_MFP_UART0_RX);
    SYS->PB_L_MFP = ((SYS->PB_L_MFP & ~0xFF) | 0x11);

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART0, 115200);
}



/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main (void)
{
    int             u8Item;
    int             cbs;
    uint32_t        au32Config[2];
    FUNC_PTR        *func;
    volatile int    loop;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();
    /* Init UART0 for printf */
    UART0_Init();

    /* Enable FMC ISP function */
    SYS_UnlockReg();
    FMC_Open();

    if (FMC_ReadConfig(au32Config, 2) < 0) {
        printf("\n\nFailed to read Config!\n\n");
        return -1;
    }
    cbs = (au32Config[0] >> 6) & 0x3;
    printf("Config0 = 0x%x, Config1 = 0x%x, CBS=%d\n\n", au32Config[0], au32Config[1], cbs);

    do {
        printf("\n\n\n");
        printf("+----------------------------------------------+\n");
        printf("|       LD boot program running on LDROM       |\n");
        printf("+----------------------------------------------+\n");
        printf("|               Program Select                 |\n");
        printf("+----------------------------------------------|\n");
        printf("| [0] Run ISP program (at APROM %dK)           |\n", USER_AP_MAX_SIZE/1024);
        printf("| [1] Branch and run APROM program             |\n");
        printf("+----------------------------------------------+\n");
        printf("Please select...");
        u8Item = getchar();
        printf("%c\n", u8Item);

        switch (u8Item) {
        case '0':
            FMC_SetVectorPageAddr(ISP_CODE_BASE);
            func =  (FUNC_PTR *)(*(uint32_t *)(ISP_CODE_ENTRY+4));
            printf("branch_to address 0x%x\n", (int)func);
            printf("Please make sure isp.bin is in APROM address 0x%x.\n", ISP_CODE_ENTRY);
            printf("If not, please run \"[1] Branch and run APROM program\"\n");
            printf("\nChange VECMAP and branch to ISP code...\n");
            while (!UART_IS_TX_EMPTY(UART0));
            __set_SP(*(uint32_t *)ISP_CODE_BASE);
            func();
            break;

        case '1':
            FMC_SetVectorPageAddr(USER_AP_ENTRY);
            func =  (FUNC_PTR *)(*(uint32_t *)(USER_AP_ENTRY+4));
            printf("branch_to address 0x%x\n", (int)func);
            printf("\n\nChange VECMAP and branch to user application...\n");
            while (!UART_IS_TX_EMPTY(UART0));
            __set_SP(*(uint32_t *)USER_AP_ENTRY);
            func();
            break;

        default :
            continue;
        }
    } while (1);

}


