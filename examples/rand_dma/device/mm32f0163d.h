/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MM32F0163D_H__
#define __MM32F0163D_H__

/* -----------------------------------------------------------------------------
  -- Interrupt vector numbers
  ----------------------------------------------------------------------------- */

/*!
* @addtogroup Interrupt_vector_numbers Interrupt vector numbers

* @{
*/

/** Interrupt Number Definitions */

#define NUMBER_OF_INT_VECTORS 38                 /**< Number of interrupts in the Vector table */

typedef enum IRQ {
  Reset_IRQn                               = -15,                                    /*!< Reset*/
  NMI_IRQn                                 = -14,                                    /*!< Unmaskable interrupt RCC Clock security system (CSS) connected to NMI */
  Hardwarefault_IRQn                       = -13,                                    /*!< All types of faults*/
  SVCall_IRQn                              = -5,                                     /*!< System service call via SWI instruction*/
  PendSV_IRQn                              = -2,                                     /*!< Pending system service*/
  SysTick_IRQn                             = -1,                                     /*!< System tick timer*/
  WWDG_IWDG_IRQn                           = 0,                                      /*!< Window watchdog interrupt and independent watchdog interrupt connected to EXTI21*/
  PVD_IRQn                                 = 1,                                      /*!< Power voltage detection (PVD) connected to EXTI16*/
  RTC_BKP_IRQn                             = 2,                                      /*!< RTC global interrupt and RTC_ALARAM interrupt connected to EXTI17*/
  FLASH_IRQn                               = 3,                                      /*!< Flash global interrupt*/
  RCC_IRQn                                 = 4,                                      /*!< RCC global interrupt*/
  EXTI0_1_IRQn                             = 5,                                      /*!< EXTI line [1:0] interrupt*/
  EXTI3_2_IRQn                             = 6,                                      /*!< EXTI line [3:2] interrupt*/
  EXTI15_4_IRQn                            = 7,                                      /*!< EXTI line [15:4] interrupt*/
  HWDIV_IRQn                               = 8,                                      /*!< Hard_Divider interrupt*/
  DMA1_CH1_IRQn                            = 9,                                      /*!< DMA1 channel 1 global interrupt*/
  DMA1_CH3_CH2_IRQn                        = 10,                                     /*!< DMA1 channel [3:2] global interrupt*/
  DMA1_CH7_CH4_IRQn                        = 11,                                     /*!< DMA1 channel [7:4] global interrupt*/
  ADC_COMP_IRQn                            = 12,                                     /*!< ADC1 global interrupt and Comparator 4 interrupt connected to EXTI19 */
  TIM1_BRK_UP_TRG_COM_IRQn                 = 13,                                     /*!< TIM1 break, update, trigger, COM interrupt*/
  TIM1_CC_IRQn                             = 14,                                     /*!< TIM1 capture compare interrupt*/
  TIM2_IRQn                                = 15,                                     /*!< TIM2 global interrupt */
  TIM3_IRQn                                = 16,                                     /*!< TIM3 global interrupt*/
  LPUART_IRQn                              = 17,                                     /*!< LPUART global interrupt connected to EXTI22*/
  LPTIM_IRQn                               = 18,                                     /*!< LPTIMER global interrupt connected to EXTI23*/
  TIM14_IRQn                               = 19,                                     /*!< TIM14 global interrupt*/
  TIM16_IRQn                               = 21,                                     /*!< TIM16 global interrupt*/
  TIM17_IRQn                               = 22,                                     /*!< TIM17 global interrupt*/
  I2C1_IRQn                                = 23,                                     /*!< I2C1 global interrupt connected to EXTI24 and I2C1 global interrupt*/
  I3C1_IRQn                                = 24,                                     /*!< I3C1 global interrupt */
  SPI1_IRQn                                = 25,                                     /*!< SPI1 global interrupt*/
  SPI2_IRQn                                = 26,                                     /*!< SPI2 global interrupt*/
  UART1_IRQn                               = 27,                                     /*!< UART1 global interrupt connected to EXTI25 and UART1 global interrupt*/
  UART2_IRQn                               = 28,                                     /*!< UART2 global interrupt connected to EXTI26 and UART2 global interrupt*/
  UART3_4_IRQn                             = 29,                                     /*!< UART3 and UART4 global interrupt */
  FlexCAN_IRQn                             = 30,                                     /*!< FLexCAN global interrupt */
  USB_IRQn                                 = 31,                                     /*!< USB global interrupt and USB wake-up interrupt (EXTI18)*/
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */



/* -----------------------------------------------------------------------------
 -- Cortex m0 Core Configuration
  ----------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex m0 Core Configuration
 * @{
 */

/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0_REV                 0x0000U   /* Core revision r0p0 */
#define __MPU_PRESENT             0U        /* no MPU present */
#define __VTOR_PRESENT            0U        /* no VTOR present */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

#include "core_cm0.h"                       /* Processor and core peripherals */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */
/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif
/* Define the base address of the large memory block mapping */

#define BOOT_BASE                   0x00000000u
#define FLASH_BASE_BASE             0x08000000u
#define ENCRYPTEDSPACE_BASE         0x1FFE1000u
#define SYSTEMMEMORY_BASE           0x1FFFF400u
#define OPTIONBYTES_BASE            0x1FFFF800u
#define SRAM_BASE                   0x20000000u
#define APB1_0_BASE                 0x40000000u
#define APB2_0_BASE                 0x40010000u
#define AHB1_0_BASE                 0x40020000u
#define AHB1_1_BASE                 0x40030000u
#define AHB1_2_BASE                 0x40100000u
#define AHB1_3_BASE                 0x48000000u
#define AHB1_4_BASE                 0x48010000u
#define AHB1_5_BASE                 0x48100000u
#define AHB2_0_BASE                 0x50000000u
#define AHB2_1_BASE                 0x50040000u
#define AHB2_2_BASE                 0x50100000u


/* Define the mapping base address of the peripheral module */
#define TIM2_BASE                   (APB1_0_BASE + 0x0000 )
#define TIM3_BASE                   (APB1_0_BASE + 0x0400 )
#define RTC_BKP_BASE                (APB1_0_BASE + 0x2800 )
#define WWDG_BASE                   (APB1_0_BASE + 0x2C00 )
#define IWDG_BASE                   (APB1_0_BASE + 0x3000 )
#define SPI2_BASE                   (APB1_0_BASE + 0x3800 )
#define UART2_BASE                  (APB1_0_BASE + 0x4400 )
#define UART3_BASE                  (APB1_0_BASE + 0x4800 )
#define UART4_BASE                  (APB1_0_BASE + 0x4C00 )
#define I2C1_BASE                   (APB1_0_BASE + 0x5400 )
#define CRS_BASE                    (APB1_0_BASE + 0x6C00 )
#define PWR_BASE                    (APB1_0_BASE + 0x7000 )
#define I3C1_BASE                   (APB1_0_BASE + 0xA000 )

#define FLEXCAN_BASE                (APB1_0_BASE + 0xC000 )
#define SYSCFG_BASE                 (APB2_0_BASE + 0x0000 )
#define EXTI_BASE                   (APB2_0_BASE + 0x0400 )
#define LPUART_BASE                 (APB2_0_BASE + 0x0800 )
#define ADC_BASE                    (APB2_0_BASE + 0x2400 )
#define LPTIM1_BASE                 (APB2_0_BASE + 0x2800 )
#define TIM1_BASE                   (APB2_0_BASE + 0x2C00 )
#define SPI1_BASE                   (APB2_0_BASE + 0x3000 )
#define DBGMCU_BASE                 (APB2_0_BASE + 0x3400 )
#define UART1_BASE                  (APB2_0_BASE + 0x3800 )
#define COMP_BASE                   (APB2_0_BASE + 0x3C00 )
#define TIM14_BASE                  (APB2_0_BASE + 0x4000 )
#define TIM16_BASE                  (APB2_0_BASE + 0x4400 )
#define TIM17_BASE                  (APB2_0_BASE + 0x4800 )

#define DMA_BASE                    (AHB1_0_BASE + 0x0000 )
#define RCC_BASE                    (AHB1_0_BASE + 0x1000 )
#define FLASH_BASE                  (AHB1_0_BASE + 0x2000 )
#define CRC_BASE                    (AHB1_0_BASE + 0x3000 )

#define HWDIV_BASE                  (AHB1_1_BASE + 0x0000 )

#define GPIOA_BASE                  (AHB1_3_BASE + 0x0000 )
#define GPIOB_BASE                  (AHB1_3_BASE + 0x0400 )
#define GPIOC_BASE                  (AHB1_3_BASE + 0x0800 )
#define GPIOD_BASE                  (AHB1_3_BASE + 0x0C00 )

#define USB_FS_BASE                 (AHB2_0_BASE + 0x0000 )


/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * ADC Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t ADDATA;                                                       ///< A/D Data Register                            offset: 0x00
    __IO uint32_t ADCFG;                                                        ///< A/D Configuration Register                   offset: 0x04
    __IO uint32_t ADCR;                                                         ///< A/D Control Register                         offset: 0x08
    __IO uint32_t ADCHS;                                                        ///< A/D Channel Selection Register               offset: 0x0C
    __IO uint32_t ADCMPR;                                                       ///< A/D Analog Watchdog Compare Register         offset: 0x10
    __IO uint32_t ADSTA;                                                        ///< A/D Status Register                          offset: 0x14
    __IO uint32_t ADDR[16];                                                     ///< A/D Channel Data Register                    offset: 0x18
    __IO uint32_t ADSTAEXT;                                                     ///< A/D Extended State Register                  offset: 0x58
    __IO uint32_t CHANY0;                                                       ///< A/D Any Channel Selection Register 0         offset: 0x5C
    __IO uint32_t CHANY1;                                                       ///< A/D Any Channel Selection Register 1         offset: 0x60
    __IO uint32_t ANYCFG;                                                       ///< A/D Any Channel Configuration Register       offset: 0x64
    __IO uint32_t ANYCR;                                                        ///< A/D Any Channel Control Register             offset: 0x68
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t SMPR1;                                                        ///< A/D Sample Configuration Register 1          offset: 0x70
    __IO uint32_t SMPR2;                                                        ///< A/D Sample Configuration Register 2          offset: 0x74
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t JOFR[4];                                                      ///< A/D Injected Channel Data Offset Register    offset: 0x7C
    __IO uint32_t JSQR;                                                         ///< A/D Injected Channel Sequence Register       offset: 0x8C
    __IO uint32_t JADDATA;                                                      ///< A/D Injected Data Register                   offset: 0x90
    __IO uint32_t Reserved2[7];                                                 ///< Reserved
    __IO uint32_t JDR[4];                                                       ///< A/D Injected Channel Data Register           offset: 0xB0
    __IO uint32_t Reserved3[12];                                                ///< Reserved
    __IO uint32_t LDATA;                                                        ///< A/D Last Conversion Data Register            offset: 0xF0
} ADC_Type;

/*******************************************************************************
 * ADC Type
 ******************************************************************************/

/*!
 * @addtogroup ADC_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief ADC_ADDATA Register Bit Definition
 */

#define ADC_ADDATA_VALID_SHIFT                  (21)
#define ADC_ADDATA_VALID_MASK                   (0x1U << ADC_ADDATA_VALID_SHIFT)
#define ADC_ADDATA_VALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADDATA_VALID_SHIFT)) & ADC_ADDATA_VALID_MASK)

#define ADC_ADDATA_OVERRUN_SHIFT                (20)
#define ADC_ADDATA_OVERRUN_MASK                 (0x1U << ADC_ADDATA_OVERRUN_SHIFT)
#define ADC_ADDATA_OVERRUN(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ADDATA_OVERRUN_SHIFT)) & ADC_ADDATA_OVERRUN_MASK)

#define ADC_ADDATA_CHANNELSEL_SHIFT             (16)
#define ADC_ADDATA_CHANNELSEL_MASK              (0xFU << ADC_ADDATA_CHANNELSEL_SHIFT)
#define ADC_ADDATA_CHANNELSEL(x)                (((uint32_t)(((uint32_t)(x)) << ADC_ADDATA_CHANNELSEL_SHIFT)) & ADC_ADDATA_CHANNELSEL_MASK)

#define ADC_ADDATA_DATA_SHIFT                   (0)
#define ADC_ADDATA_DATA_MASK                    (0xFFFFU << ADC_ADDATA_DATA_SHIFT)
#define ADC_ADDATA_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADDATA_DATA_SHIFT)) & ADC_ADDATA_DATA_MASK)

/*!
 * @brief ADC_ADCFG Register Bit Definition
 */

#define ADC_ADCFG_JAWDEN_SHIFT                  (16)
#define ADC_ADCFG_JAWDEN_MASK                   (0x1U << ADC_ADCFG_JAWDEN_SHIFT)
#define ADC_ADCFG_JAWDEN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_JAWDEN_SHIFT)) & ADC_ADCFG_JAWDEN_MASK)

#define ADC_ADCFG_ADCPREL_SHIFT                 (14)
#define ADC_ADCFG_ADCPREL_MASK                  (0x1U << ADC_ADCFG_ADCPREL_SHIFT)
#define ADC_ADCFG_ADCPREL(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_ADCPREL_SHIFT)) & ADC_ADCFG_ADCPREL_MASK)

#define ADC_ADCFG_RSLTCTL_SHIFT                 (7)
#define ADC_ADCFG_RSLTCTL_MASK                  (0x7U << ADC_ADCFG_RSLTCTL_SHIFT)
#define ADC_ADCFG_RSLTCTL(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_RSLTCTL_SHIFT)) & ADC_ADCFG_RSLTCTL_MASK)

#define ADC_ADCFG_ADCPREH_SHIFT                 (4)
#define ADC_ADCFG_ADCPREH_MASK                  (0x7U << ADC_ADCFG_ADCPREH_SHIFT)
#define ADC_ADCFG_ADCPREH(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_ADCPREH_SHIFT)) & ADC_ADCFG_ADCPREH_MASK)

#define ADC_ADCFG_VSEN_SHIFT                    (3)
#define ADC_ADCFG_VSEN_MASK                     (0x1U << ADC_ADCFG_VSEN_SHIFT)
#define ADC_ADCFG_VSEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_VSEN_SHIFT)) & ADC_ADCFG_VSEN_MASK)

#define ADC_ADCFG_TSEN_SHIFT                    (2)
#define ADC_ADCFG_TSEN_MASK                     (0x1U << ADC_ADCFG_TSEN_SHIFT)
#define ADC_ADCFG_TSEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_TSEN_SHIFT)) & ADC_ADCFG_TSEN_MASK)

#define ADC_ADCFG_AWDEN_SHIFT                   (1)
#define ADC_ADCFG_AWDEN_MASK                    (0x1U << ADC_ADCFG_AWDEN_SHIFT)
#define ADC_ADCFG_AWDEN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_AWDEN_SHIFT)) & ADC_ADCFG_AWDEN_MASK)

#define ADC_ADCFG_ADEN_SHIFT                    (0)
#define ADC_ADCFG_ADEN_MASK                     (0x1U << ADC_ADCFG_ADEN_SHIFT)
#define ADC_ADCFG_ADEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCFG_ADEN_SHIFT)) & ADC_ADCFG_ADEN_MASK)

/*!
 * @brief ADC_ADCR Register Bit Definition
 */

#define ADC_ADCR_EOCIE_SHIFT                    (27)
#define ADC_ADCR_EOCIE_MASK                     (0x1U << ADC_ADCR_EOCIE_SHIFT)
#define ADC_ADCR_EOCIE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_EOCIE_SHIFT)) & ADC_ADCR_EOCIE_MASK)

#define ADC_ADCR_EOSMPIE_SHIFT                  (26)
#define ADC_ADCR_EOSMPIE_MASK                   (0x1U << ADC_ADCR_EOSMPIE_SHIFT)
#define ADC_ADCR_EOSMPIE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_EOSMPIE_SHIFT)) & ADC_ADCR_EOSMPIE_MASK)

#define ADC_ADCR_TRGEDGE_SHIFT                  (24)
#define ADC_ADCR_TRGEDGE_MASK                   (0x3U << ADC_ADCR_TRGEDGE_SHIFT)
#define ADC_ADCR_TRGEDGE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_TRGEDGE_SHIFT)) & ADC_ADCR_TRGEDGE_MASK)

#define ADC_ADCR_TRGSHIFT_SHIFT                 (19)
#define ADC_ADCR_TRGSHIFT_MASK                  (0x7U << ADC_ADCR_TRGSHIFT_SHIFT)
#define ADC_ADCR_TRGSHIFT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_TRGSHIFT_SHIFT)) & ADC_ADCR_TRGSHIFT_MASK)

#define ADC_ADCR_TRGSELH_SHIFT                  (17)
#define ADC_ADCR_TRGSELH_MASK                   (0x3U << ADC_ADCR_TRGSELH_SHIFT)
#define ADC_ADCR_TRGSELH(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_TRGSELH_SHIFT)) & ADC_ADCR_TRGSELH_MASK)

#define ADC_ADCR_SCANDIR_SHIFT                  (16)
#define ADC_ADCR_SCANDIR_MASK                   (0x1U << ADC_ADCR_SCANDIR_SHIFT)
#define ADC_ADCR_SCANDIR(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_SCANDIR_SHIFT)) & ADC_ADCR_SCANDIR_MASK)

#define ADC_ADCR_CMPCH_SHIFT                    (12)
#define ADC_ADCR_CMPCH_MASK                     (0xFU << ADC_ADCR_CMPCH_SHIFT)
#define ADC_ADCR_CMPCH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_CMPCH_SHIFT)) & ADC_ADCR_CMPCH_MASK)

#define ADC_ADCR_ALIGN_SHIFT                    (11)
#define ADC_ADCR_ALIGN_MASK                     (0x1U << ADC_ADCR_ALIGN_SHIFT)
#define ADC_ADCR_ALIGN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_ALIGN_SHIFT)) & ADC_ADCR_ALIGN_MASK)

#define ADC_ADCR_ADMD_SHIFT                     (9)
#define ADC_ADCR_ADMD_MASK                      (0x3U << ADC_ADCR_ADMD_SHIFT)
#define ADC_ADCR_ADMD(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_ADMD_SHIFT)) & ADC_ADCR_ADMD_MASK)

#define ADC_ADCR_ADST_SHIFT                     (8)
#define ADC_ADCR_ADST_MASK                      (0x1U << ADC_ADCR_ADST_SHIFT)
#define ADC_ADCR_ADST(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_ADST_SHIFT)) & ADC_ADCR_ADST_MASK)

#define ADC_ADCR_TRGSELL_SHIFT                  (4)
#define ADC_ADCR_TRGSELL_MASK                   (0x7U << ADC_ADCR_TRGSELL_SHIFT)
#define ADC_ADCR_TRGSELL(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_TRGSELL_SHIFT)) & ADC_ADCR_TRGSELL_MASK)

#define ADC_ADCR_DMAEN_SHIFT                    (3)
#define ADC_ADCR_DMAEN_MASK                     (0x1U << ADC_ADCR_DMAEN_SHIFT)
#define ADC_ADCR_DMAEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_DMAEN_SHIFT)) & ADC_ADCR_DMAEN_MASK)

#define ADC_ADCR_TRGEN_SHIFT                    (2)
#define ADC_ADCR_TRGEN_MASK                     (0x1U << ADC_ADCR_TRGEN_SHIFT)
#define ADC_ADCR_TRGEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_TRGEN_SHIFT)) & ADC_ADCR_TRGEN_MASK)

#define ADC_ADCR_AWDIE_SHIFT                    (1)
#define ADC_ADCR_AWDIE_MASK                     (0x1U << ADC_ADCR_AWDIE_SHIFT)
#define ADC_ADCR_AWDIE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_AWDIE_SHIFT)) & ADC_ADCR_AWDIE_MASK)

#define ADC_ADCR_EOSIE_SHIFT                    (0)
#define ADC_ADCR_EOSIE_MASK                     (0x1U << ADC_ADCR_EOSIE_SHIFT)
#define ADC_ADCR_EOSIE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADCR_EOSIE_SHIFT)) & ADC_ADCR_EOSIE_MASK)

/*!
 * @brief ADC_ADCHS Register Bit Definition
 */

#define ADC_ADCHS_CHEN15_SHIFT                  (15)
#define ADC_ADCHS_CHEN15_MASK                   (0x1U << ADC_ADCHS_CHEN15_SHIFT)
#define ADC_ADCHS_CHEN15(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN15_SHIFT)) & ADC_ADCHS_CHEN15_MASK)

#define ADC_ADCHS_CHEN14_SHIFT                  (14)
#define ADC_ADCHS_CHEN14_MASK                   (0x1U << ADC_ADCHS_CHEN14_SHIFT)
#define ADC_ADCHS_CHEN14(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN14_SHIFT)) & ADC_ADCHS_CHEN14_MASK)

#define ADC_ADCHS_CHEN13_SHIFT                  (13)
#define ADC_ADCHS_CHEN13_MASK                   (0x1U << ADC_ADCHS_CHEN13_SHIFT)
#define ADC_ADCHS_CHEN13(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN13_SHIFT)) & ADC_ADCHS_CHEN13_MASK)

#define ADC_ADCHS_CHEN12_SHIFT                  (12)
#define ADC_ADCHS_CHEN12_MASK                   (0x1U << ADC_ADCHS_CHEN12_SHIFT)
#define ADC_ADCHS_CHEN12(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN12_SHIFT)) & ADC_ADCHS_CHEN12_MASK)

#define ADC_ADCHS_CHEN11_SHIFT                  (11)
#define ADC_ADCHS_CHEN11_MASK                   (0x1U << ADC_ADCHS_CHEN11_SHIFT)
#define ADC_ADCHS_CHEN11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN11_SHIFT)) & ADC_ADCHS_CHEN11_MASK)

#define ADC_ADCHS_CHEN10_SHIFT                  (10)
#define ADC_ADCHS_CHEN10_MASK                   (0x1U << ADC_ADCHS_CHEN10_SHIFT)
#define ADC_ADCHS_CHEN10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN10_SHIFT)) & ADC_ADCHS_CHEN10_MASK)

#define ADC_ADCHS_CHEN9_SHIFT                   (9)
#define ADC_ADCHS_CHEN9_MASK                    (0x1U << ADC_ADCHS_CHEN9_SHIFT)
#define ADC_ADCHS_CHEN9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN9_SHIFT)) & ADC_ADCHS_CHEN9_MASK)

#define ADC_ADCHS_CHEN8_SHIFT                   (8)
#define ADC_ADCHS_CHEN8_MASK                    (0x1U << ADC_ADCHS_CHEN8_SHIFT)
#define ADC_ADCHS_CHEN8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN8_SHIFT)) & ADC_ADCHS_CHEN8_MASK)

#define ADC_ADCHS_CHEN7_SHIFT                   (7)
#define ADC_ADCHS_CHEN7_MASK                    (0x1U << ADC_ADCHS_CHEN7_SHIFT)
#define ADC_ADCHS_CHEN7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN7_SHIFT)) & ADC_ADCHS_CHEN7_MASK)

#define ADC_ADCHS_CHEN6_SHIFT                   (6)
#define ADC_ADCHS_CHEN6_MASK                    (0x1U << ADC_ADCHS_CHEN6_SHIFT)
#define ADC_ADCHS_CHEN6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN6_SHIFT)) & ADC_ADCHS_CHEN6_MASK)

#define ADC_ADCHS_CHEN5_SHIFT                   (5)
#define ADC_ADCHS_CHEN5_MASK                    (0x1U << ADC_ADCHS_CHEN5_SHIFT)
#define ADC_ADCHS_CHEN5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN5_SHIFT)) & ADC_ADCHS_CHEN5_MASK)

#define ADC_ADCHS_CHEN4_SHIFT                   (4)
#define ADC_ADCHS_CHEN4_MASK                    (0x1U << ADC_ADCHS_CHEN4_SHIFT)
#define ADC_ADCHS_CHEN4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN4_SHIFT)) & ADC_ADCHS_CHEN4_MASK)

#define ADC_ADCHS_CHEN3_SHIFT                   (3)
#define ADC_ADCHS_CHEN3_MASK                    (0x1U << ADC_ADCHS_CHEN3_SHIFT)
#define ADC_ADCHS_CHEN3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN3_SHIFT)) & ADC_ADCHS_CHEN3_MASK)

#define ADC_ADCHS_CHEN2_SHIFT                   (2)
#define ADC_ADCHS_CHEN2_MASK                    (0x1U << ADC_ADCHS_CHEN2_SHIFT)
#define ADC_ADCHS_CHEN2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN2_SHIFT)) & ADC_ADCHS_CHEN2_MASK)

#define ADC_ADCHS_CHEN1_SHIFT                   (1)
#define ADC_ADCHS_CHEN1_MASK                    (0x1U << ADC_ADCHS_CHEN1_SHIFT)
#define ADC_ADCHS_CHEN1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN1_SHIFT)) & ADC_ADCHS_CHEN1_MASK)

#define ADC_ADCHS_CHEN0_SHIFT                   (0)
#define ADC_ADCHS_CHEN0_MASK                    (0x1U << ADC_ADCHS_CHEN0_SHIFT)
#define ADC_ADCHS_CHEN0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADCHS_CHEN0_SHIFT)) & ADC_ADCHS_CHEN0_MASK)

/*!
 * @brief ADC_ADCMPR Register Bit Definition
 */

#define ADC_ADCMPR_CMPHDATA_SHIFT               (16)
#define ADC_ADCMPR_CMPHDATA_MASK                (0xFFFU << ADC_ADCMPR_CMPHDATA_SHIFT)
#define ADC_ADCMPR_CMPHDATA(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ADCMPR_CMPHDATA_SHIFT)) & ADC_ADCMPR_CMPHDATA_MASK)

#define ADC_ADCMPR_CMPLDATA_SHIFT               (0)
#define ADC_ADCMPR_CMPLDATA_MASK                (0xFFFU << ADC_ADCMPR_CMPLDATA_SHIFT)
#define ADC_ADCMPR_CMPLDATA(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ADCMPR_CMPLDATA_SHIFT)) & ADC_ADCMPR_CMPLDATA_MASK)

/*!
 * @brief ADC_ADSTA Register Bit Definition
 */

#define ADC_ADSTA_OVERRUN_SHIFT                 (20)
#define ADC_ADSTA_OVERRUN_MASK                  (0xFFFU << ADC_ADSTA_OVERRUN_SHIFT)
#define ADC_ADSTA_OVERRUN(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_OVERRUN_SHIFT)) & ADC_ADSTA_OVERRUN_MASK)

#define ADC_ADSTA_VALID_SHIFT                   (8)
#define ADC_ADSTA_VALID_MASK                    (0xFFFU << ADC_ADSTA_VALID_SHIFT)
#define ADC_ADSTA_VALID(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_VALID_SHIFT)) & ADC_ADSTA_VALID_MASK)

#define ADC_ADSTA_CHANNEL_SHIFT                 (4)
#define ADC_ADSTA_CHANNEL_MASK                  (0xFU << ADC_ADSTA_CHANNEL_SHIFT)
#define ADC_ADSTA_CHANNEL(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_CHANNEL_SHIFT)) & ADC_ADSTA_CHANNEL_MASK)

#define ADC_ADSTA_BUSY_SHIFT                    (2)
#define ADC_ADSTA_BUSY_MASK                     (0x1U << ADC_ADSTA_BUSY_SHIFT)
#define ADC_ADSTA_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_BUSY_SHIFT)) & ADC_ADSTA_BUSY_MASK)

#define ADC_ADSTA_AWDIF_SHIFT                   (1)
#define ADC_ADSTA_AWDIF_MASK                    (0x1U << ADC_ADSTA_AWDIF_SHIFT)
#define ADC_ADSTA_AWDIF(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_AWDIF_SHIFT)) & ADC_ADSTA_AWDIF_MASK)

#define ADC_ADSTA_EOSIF_SHIFT                   (0)
#define ADC_ADSTA_EOSIF_MASK                    (0x1U << ADC_ADSTA_EOSIF_SHIFT)
#define ADC_ADSTA_EOSIF(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ADSTA_EOSIF_SHIFT)) & ADC_ADSTA_EOSIF_MASK)

/*!
 * @brief ADC_ADDR Register Bit Definition
 */

#define ADC_ADDR_VALID_SHIFT                    (21)
#define ADC_ADDR_VALID_MASK                     (0x1U << ADC_ADDR_VALID_SHIFT)
#define ADC_ADDR_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ADDR_VALID_SHIFT)) & ADC_ADDR_VALID_MASK)

#define ADC_ADDR_OVERRUN_SHIFT                  (20)
#define ADC_ADDR_OVERRUN_MASK                   (0x1U << ADC_ADDR_OVERRUN_SHIFT)
#define ADC_ADDR_OVERRUN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ADDR_OVERRUN_SHIFT)) & ADC_ADDR_OVERRUN_MASK)

#define ADC_ADDR_DATA_SHIFT                     (0)
#define ADC_ADDR_DATA_MASK                      (0xFFFFU << ADC_ADDR_DATA_SHIFT)
#define ADC_ADDR_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ADDR_DATA_SHIFT)) & ADC_ADDR_DATA_MASK)

/*!
 * @brief ADC_ADSTA_EXT Register Bit Definition
 */

#define ADC_ADSTAEXT_JBUSY_SHIFT                (21)
#define ADC_ADSTAEXT_JBUSY_MASK                 (0x1U << ADC_ADSTAEXT_JBUSY_SHIFT)
#define ADC_ADSTAEXT_JBUSY(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_JBUSY_SHIFT)) & ADC_ADSTAEXT_JBUSY_MASK)

#define ADC_ADSTAEXT_JEOSIF_SHIFT               (20)
#define ADC_ADSTAEXT_JEOSIF_MASK                (0x1U << ADC_ADSTAEXT_JEOSIF_SHIFT)
#define ADC_ADSTAEXT_JEOSIF(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_JEOSIF_SHIFT)) & ADC_ADSTAEXT_JEOSIF_MASK)

#define ADC_ADSTAEXT_JEOCIF_SHIFT               (19)
#define ADC_ADSTAEXT_JEOCIF_MASK                (0x1U << ADC_ADSTAEXT_JEOCIF_SHIFT)
#define ADC_ADSTAEXT_JEOCIF(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_JEOCIF_SHIFT)) & ADC_ADSTAEXT_JEOCIF_MASK)

#define ADC_ADSTAEXT_JEOSMPIF_SHIFT             (18)
#define ADC_ADSTAEXT_JEOSMPIF_MASK              (0x1U << ADC_ADSTAEXT_JEOSMPIF_SHIFT)
#define ADC_ADSTAEXT_JEOSMPIF(x)                (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_JEOSMPIF_SHIFT)) & ADC_ADSTAEXT_JEOSMPIF_MASK)

#define ADC_ADSTAEXT_EOCIF_SHIFT                (17)
#define ADC_ADSTAEXT_EOCIF_MASK                 (0x1U << ADC_ADSTAEXT_EOCIF_SHIFT)
#define ADC_ADSTAEXT_EOCIF(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_EOCIF_SHIFT)) & ADC_ADSTAEXT_EOCIF_MASK)

#define ADC_ADSTAEXT_EOSMPIF_SHIFT              (16)
#define ADC_ADSTAEXT_EOSMPIF_MASK               (0x1U << ADC_ADSTAEXT_EOSMPIF_SHIFT)
#define ADC_ADSTAEXT_EOSMPIF(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_EOSMPIF_SHIFT)) & ADC_ADSTAEXT_EOSMPIF_MASK)

#define ADC_ADSTAEXT_OVERRUN_SHIFT              (4)
#define ADC_ADSTAEXT_OVERRUN_MASK               (0xFU << ADC_ADSTAEXT_OVERRUN_SHIFT)
#define ADC_ADSTAEXT_OVERRUN(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_OVERRUN_SHIFT)) & ADC_ADSTAEXT_OVERRUN_MASK)

#define ADC_ADSTAEXT_VALID_SHIFT                (0)
#define ADC_ADSTAEXT_VALID_MASK                 (0xFU << ADC_ADSTAEXT_VALID_SHIFT)
#define ADC_ADSTAEXT_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ADSTAEXT_VALID_SHIFT)) & ADC_ADSTAEXT_VALID_MASK)

/*!
 * @brief ADC_CHANY0 Register Bit Definition
 */

#define ADC_CHANY0_CHANYSEL7_SHIFT              (28)
#define ADC_CHANY0_CHANYSEL7_MASK               (0xFU << ADC_CHANY0_CHANYSEL7_SHIFT)
#define ADC_CHANY0_CHANYSEL7(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL7_SHIFT)) & ADC_CHANY0_CHANYSEL7_MASK)

#define ADC_CHANY0_CHANYSEL6_SHIFT              (24)
#define ADC_CHANY0_CHANYSEL6_MASK               (0xFU << ADC_CHANY0_CHANYSEL6_SHIFT)
#define ADC_CHANY0_CHANYSEL6(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL6_SHIFT)) & ADC_CHANY0_CHANYSEL6_MASK)

#define ADC_CHANY0_CHANYSEL5_SHIFT              (20)
#define ADC_CHANY0_CHANYSEL5_MASK               (0xFU << ADC_CHANY0_CHANYSEL5_SHIFT)
#define ADC_CHANY0_CHANYSEL5(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL5_SHIFT)) & ADC_CHANY0_CHANYSEL5_MASK)

#define ADC_CHANY0_CHANYSEL4_SHIFT              (16)
#define ADC_CHANY0_CHANYSEL4_MASK               (0xFU << ADC_CHANY0_CHANYSEL4_SHIFT)
#define ADC_CHANY0_CHANYSEL4(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL4_SHIFT)) & ADC_CHANY0_CHANYSEL4_MASK)

#define ADC_CHANY0_CHANYSEL3_SHIFT              (12)
#define ADC_CHANY0_CHANYSEL3_MASK               (0xFU << ADC_CHANY0_CHANYSEL3_SHIFT)
#define ADC_CHANY0_CHANYSEL3(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL3_SHIFT)) & ADC_CHANY0_CHANYSEL3_MASK)

#define ADC_CHANY0_CHANYSEL2_SHIFT              (8)
#define ADC_CHANY0_CHANYSEL2_MASK               (0xFU << ADC_CHANY0_CHANYSEL2_SHIFT)
#define ADC_CHANY0_CHANYSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL2_SHIFT)) & ADC_CHANY0_CHANYSEL2_MASK)

#define ADC_CHANY0_CHANYSEL1_SHIFT              (4)
#define ADC_CHANY0_CHANYSEL1_MASK               (0xFU << ADC_CHANY0_CHANYSEL1_SHIFT)
#define ADC_CHANY0_CHANYSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL1_SHIFT)) & ADC_CHANY0_CHANYSEL1_MASK)

#define ADC_CHANY0_CHANYSEL0_SHIFT              (0)
#define ADC_CHANY0_CHANYSEL0_MASK               (0xFU << ADC_CHANY0_CHANYSEL0_SHIFT)
#define ADC_CHANY0_CHANYSEL0(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY0_CHANYSEL0_SHIFT)) & ADC_CHANY0_CHANYSEL0_MASK)

/*!
 * @brief ADC_CHANY1 Register Bit Definition
 */

#define ADC_CHANY1_CHANYSEL15_SHIFT             (28)
#define ADC_CHANY1_CHANYSEL15_MASK              (0xFU << ADC_CHANY1_CHANYSEL15_SHIFT)
#define ADC_CHANY1_CHANYSEL15(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL15_SHIFT)) & ADC_CHANY1_CHANYSEL15_MASK)

#define ADC_CHANY1_CHANYSEL14_SHIFT             (24)
#define ADC_CHANY1_CHANYSEL14_MASK              (0xFU << ADC_CHANY1_CHANYSEL14_SHIFT)
#define ADC_CHANY1_CHANYSEL14(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL14_SHIFT)) & ADC_CHANY1_CHANYSEL14_MASK)

#define ADC_CHANY1_CHANYSEL13_SHIFT             (20)
#define ADC_CHANY1_CHANYSEL13_MASK              (0xFU << ADC_CHANY1_CHANYSEL13_SHIFT)
#define ADC_CHANY1_CHANYSEL13(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL13_SHIFT)) & ADC_CHANY1_CHANYSEL13_MASK)

#define ADC_CHANY1_CHANYSEL12_SHIFT             (16)
#define ADC_CHANY1_CHANYSEL12_MASK              (0xFU << ADC_CHANY1_CHANYSEL12_SHIFT)
#define ADC_CHANY1_CHANYSEL12(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL12_SHIFT)) & ADC_CHANY1_CHANYSEL12_MASK)

#define ADC_CHANY1_CHANYSEL11_SHIFT             (12)
#define ADC_CHANY1_CHANYSEL11_MASK              (0xFU << ADC_CHANY1_CHANYSEL11_SHIFT)
#define ADC_CHANY1_CHANYSEL11(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL11_SHIFT)) & ADC_CHANY1_CHANYSEL11_MASK)

#define ADC_CHANY1_CHANYSEL10_SHIFT             (8)
#define ADC_CHANY1_CHANYSEL10_MASK              (0xFU << ADC_CHANY1_CHANYSEL10_SHIFT)
#define ADC_CHANY1_CHANYSEL10(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL10_SHIFT)) & ADC_CHANY1_CHANYSEL10_MASK)

#define ADC_CHANY1_CHANYSEL9_SHIFT              (4)
#define ADC_CHANY1_CHANYSEL9_MASK               (0xFU << ADC_CHANY1_CHANYSEL9_SHIFT)
#define ADC_CHANY1_CHANYSEL9(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL9_SHIFT)) & ADC_CHANY1_CHANYSEL9_MASK)

#define ADC_CHANY1_CHANYSEL8_SHIFT              (0)
#define ADC_CHANY1_CHANYSEL8_MASK               (0xFU << ADC_CHANY1_CHANYSEL8_SHIFT)
#define ADC_CHANY1_CHANYSEL8(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CHANY1_CHANYSEL8_SHIFT)) & ADC_CHANY1_CHANYSEL8_MASK)

/*!
 * @brief ADC_ANY_CFG Register Bit Definition
 */

#define ADC_ANYCFG_CHANYNUM_SHIFT               (0)
#define ADC_ANYCFG_CHANYNUM_MASK                (0xFU << ADC_ANYCFG_CHANYNUM_SHIFT)
#define ADC_ANYCFG_CHANYNUM(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ANYCFG_CHANYNUM_SHIFT)) & ADC_ANYCFG_CHANYNUM_MASK)

/*!
 * @brief ADC_ANY_CR Register Bit Definition
 */

#define ADC_ANYCR_JTRGEDGE_SHIFT                (16)
#define ADC_ANYCR_JTRGEDGE_MASK                 (0x3U << ADC_ANYCR_JTRGEDGE_SHIFT)
#define ADC_ANYCR_JTRGEDGE(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JTRGEDGE_SHIFT)) & ADC_ANYCR_JTRGEDGE_MASK)

#define ADC_ANYCR_JTRGSHIFT_SHIFT               (13)
#define ADC_ANYCR_JTRGSHIFT_MASK                (0x7U << ADC_ANYCR_JTRGSHIFT_SHIFT)
#define ADC_ANYCR_JTRGSHIFT(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JTRGSHIFT_SHIFT)) & ADC_ANYCR_JTRGSHIFT_MASK)

#define ADC_ANYCR_JTRGSEL_SHIFT                 (8)
#define ADC_ANYCR_JTRGSEL_MASK                  (0x1FU << ADC_ANYCR_JTRGSEL_SHIFT)
#define ADC_ANYCR_JTRGSEL(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JTRGSEL_SHIFT)) & ADC_ANYCR_JTRGSEL_MASK)

#define ADC_ANYCR_JTRGEN_SHIFT                  (7)
#define ADC_ANYCR_JTRGEN_MASK                   (0x1U << ADC_ANYCR_JTRGEN_SHIFT)
#define ADC_ANYCR_JTRGEN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JTRGEN_SHIFT)) & ADC_ANYCR_JTRGEN_MASK)

#define ADC_ANYCR_JADST_SHIFT                   (6)
#define ADC_ANYCR_JADST_MASK                    (0x1U << ADC_ANYCR_JADST_SHIFT)
#define ADC_ANYCR_JADST(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JADST_SHIFT)) & ADC_ANYCR_JADST_MASK)

#define ADC_ANYCR_JAUTO_SHIFT                   (5)
#define ADC_ANYCR_JAUTO_MASK                    (0x1U << ADC_ANYCR_JAUTO_SHIFT)
#define ADC_ANYCR_JAUTO(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JAUTO_SHIFT)) & ADC_ANYCR_JAUTO_MASK)

#define ADC_ANYCR_JEOSIE_SHIFT                  (4)
#define ADC_ANYCR_JEOSIE_MASK                   (0x1U << ADC_ANYCR_JEOSIE_SHIFT)
#define ADC_ANYCR_JEOSIE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JEOSIE_SHIFT)) & ADC_ANYCR_JEOSIE_MASK)

#define ADC_ANYCR_JEOCIE_SHIFT                  (3)
#define ADC_ANYCR_JEOCIE_MASK                   (0x1U << ADC_ANYCR_JEOCIE_SHIFT)
#define ADC_ANYCR_JEOCIE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JEOCIE_SHIFT)) & ADC_ANYCR_JEOCIE_MASK)

#define ADC_ANYCR_JEOSMPIE_SHIFT                (2)
#define ADC_ANYCR_JEOSMPIE_MASK                 (0x1U << ADC_ANYCR_JEOSMPIE_SHIFT)
#define ADC_ANYCR_JEOSMPIE(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JEOSMPIE_SHIFT)) & ADC_ANYCR_JEOSMPIE_MASK)

#define ADC_ANYCR_JCEN_SHIFT                    (1)
#define ADC_ANYCR_JCEN_MASK                     (0x1U << ADC_ANYCR_JCEN_SHIFT)
#define ADC_ANYCR_JCEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_JCEN_SHIFT)) & ADC_ANYCR_JCEN_MASK)

#define ADC_ANYCR_CHANYMDEN_SHIFT               (0)
#define ADC_ANYCR_CHANYMDEN_MASK                (0x1U << ADC_ANYCR_CHANYMDEN_SHIFT)
#define ADC_ANYCR_CHANYMDEN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_ANYCR_CHANYMDEN_SHIFT)) & ADC_ANYCR_CHANYMDEN_MASK)

/*!
 * @brief ADC_SMPR1 Register Bit Definition
 */

#define ADC_SMPR1_SAMP7_SHIFT                   (28)
#define ADC_SMPR1_SAMP7_MASK                    (0xFU << ADC_SMPR1_SAMP7_SHIFT)
#define ADC_SMPR1_SAMP7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP7_SHIFT)) & ADC_SMPR1_SAMP7_MASK)

#define ADC_SMPR1_SAMP6_SHIFT                   (24)
#define ADC_SMPR1_SAMP6_MASK                    (0xFU << ADC_SMPR1_SAMP6_SHIFT)
#define ADC_SMPR1_SAMP6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP6_SHIFT)) & ADC_SMPR1_SAMP6_MASK)

#define ADC_SMPR1_SAMP5_SHIFT                   (20)
#define ADC_SMPR1_SAMP5_MASK                    (0xFU << ADC_SMPR1_SAMP5_SHIFT)
#define ADC_SMPR1_SAMP5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP5_SHIFT)) & ADC_SMPR1_SAMP5_MASK)

#define ADC_SMPR1_SAMP4_SHIFT                   (16)
#define ADC_SMPR1_SAMP4_MASK                    (0xFU << ADC_SMPR1_SAMP4_SHIFT)
#define ADC_SMPR1_SAMP4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP4_SHIFT)) & ADC_SMPR1_SAMP4_MASK)

#define ADC_SMPR1_SAMP3_SHIFT                   (12)
#define ADC_SMPR1_SAMP3_MASK                    (0xFU << ADC_SMPR1_SAMP3_SHIFT)
#define ADC_SMPR1_SAMP3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP3_SHIFT)) & ADC_SMPR1_SAMP3_MASK)

#define ADC_SMPR1_SAMP2_SHIFT                   (8)
#define ADC_SMPR1_SAMP2_MASK                    (0xFU << ADC_SMPR1_SAMP2_SHIFT)
#define ADC_SMPR1_SAMP2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP2_SHIFT)) & ADC_SMPR1_SAMP2_MASK)

#define ADC_SMPR1_SAMP1_SHIFT                   (4)
#define ADC_SMPR1_SAMP1_MASK                    (0xFU << ADC_SMPR1_SAMP1_SHIFT)
#define ADC_SMPR1_SAMP1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP1_SHIFT)) & ADC_SMPR1_SAMP1_MASK)

#define ADC_SMPR1_SAMP0_SHIFT                   (0)
#define ADC_SMPR1_SAMP0_MASK                    (0xFU << ADC_SMPR1_SAMP0_SHIFT)
#define ADC_SMPR1_SAMP0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR1_SAMP0_SHIFT)) & ADC_SMPR1_SAMP0_MASK)

/*!
 * @brief ADC_SMPR2 Register Bit Definition
 */

#define ADC_SMPR2_SAMP15_SHIFT                  (28)
#define ADC_SMPR2_SAMP15_MASK                   (0xFU << ADC_SMPR2_SAMP15_SHIFT)
#define ADC_SMPR2_SAMP15(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP15_SHIFT)) & ADC_SMPR2_SAMP15_MASK)

#define ADC_SMPR2_SAMP14_SHIFT                  (24)
#define ADC_SMPR2_SAMP14_MASK                   (0xFU << ADC_SMPR2_SAMP14_SHIFT)
#define ADC_SMPR2_SAMP14(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP14_SHIFT)) & ADC_SMPR2_SAMP14_MASK)

#define ADC_SMPR2_SAMP13_SHIFT                  (20)
#define ADC_SMPR2_SAMP13_MASK                   (0xFU << ADC_SMPR2_SAMP13_SHIFT)
#define ADC_SMPR2_SAMP13(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP13_SHIFT)) & ADC_SMPR2_SAMP13_MASK)

#define ADC_SMPR2_SAMP12_SHIFT                  (16)
#define ADC_SMPR2_SAMP12_MASK                   (0xFU << ADC_SMPR2_SAMP12_SHIFT)
#define ADC_SMPR2_SAMP12(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP12_SHIFT)) & ADC_SMPR2_SAMP12_MASK)

#define ADC_SMPR2_SAMP11_SHIFT                  (12)
#define ADC_SMPR2_SAMP11_MASK                   (0xFU << ADC_SMPR2_SAMP11_SHIFT)
#define ADC_SMPR2_SAMP11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP11_SHIFT)) & ADC_SMPR2_SAMP11_MASK)

#define ADC_SMPR2_SAMP10_SHIFT                  (8)
#define ADC_SMPR2_SAMP10_MASK                   (0xFU << ADC_SMPR2_SAMP10_SHIFT)
#define ADC_SMPR2_SAMP10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP10_SHIFT)) & ADC_SMPR2_SAMP10_MASK)

#define ADC_SMPR2_SAMP9_SHIFT                   (4)
#define ADC_SMPR2_SAMP9_MASK                    (0xFU << ADC_SMPR2_SAMP9_SHIFT)
#define ADC_SMPR2_SAMP9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP9_SHIFT)) & ADC_SMPR2_SAMP9_MASK)

#define ADC_SMPR2_SAMP8_SHIFT                   (0)
#define ADC_SMPR2_SAMP8_MASK                    (0xFU << ADC_SMPR2_SAMP8_SHIFT)
#define ADC_SMPR2_SAMP8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SMPR2_SAMP8_SHIFT)) & ADC_SMPR2_SAMP8_MASK)

/*!
 * @brief ADC_JOFR Register Bit Definition
 */

#define ADC_JOFR_JOFFSET_SHIFT                  (0)
#define ADC_JOFR_JOFFSET_MASK                   (0xFFFU << ADC_JOFR_JOFFSET_SHIFT)
#define ADC_JOFR_JOFFSET(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_JOFR_JOFFSET_SHIFT)) & ADC_JOFR_JOFFSET_MASK)

/*!
 * @brief ADC_JSQR Register Bit Definition
 */

#define ADC_JSQR_JNUM_SHIFT                     (20)
#define ADC_JSQR_JNUM_MASK                      (0x3U << ADC_JSQR_JNUM_SHIFT)
#define ADC_JSQR_JNUM(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JSQR_JNUM_SHIFT)) & ADC_JSQR_JNUM_MASK)

#define ADC_JSQR_JSQ3_SHIFT                     (15)
#define ADC_JSQR_JSQ3_MASK                      (0x1FU << ADC_JSQR_JSQ3_SHIFT)
#define ADC_JSQR_JSQ3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JSQR_JSQ3_SHIFT)) & ADC_JSQR_JSQ3_MASK)

#define ADC_JSQR_JSQ2_SHIFT                     (10)
#define ADC_JSQR_JSQ2_MASK                      (0x1FU << ADC_JSQR_JSQ2_SHIFT)
#define ADC_JSQR_JSQ2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JSQR_JSQ2_SHIFT)) & ADC_JSQR_JSQ2_MASK)

#define ADC_JSQR_JSQ1_SHIFT                     (5)
#define ADC_JSQR_JSQ1_MASK                      (0x1FU << ADC_JSQR_JSQ1_SHIFT)
#define ADC_JSQR_JSQ1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JSQR_JSQ1_SHIFT)) & ADC_JSQR_JSQ1_MASK)

#define ADC_JSQR_JSQ0_SHIFT                     (0)
#define ADC_JSQR_JSQ0_MASK                      (0x1FU << ADC_JSQR_JSQ0_SHIFT)
#define ADC_JSQR_JSQ0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JSQR_JSQ0_SHIFT)) & ADC_JSQR_JSQ0_MASK)

/*!
 * @brief ADC_JADDATA Register Bit Definition
 */

#define ADC_JADDATA_JVALID_SHIFT                (22)
#define ADC_JADDATA_JVALID_MASK                 (0x1U << ADC_JADDATA_JVALID_SHIFT)
#define ADC_JADDATA_JVALID(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_JADDATA_JVALID_SHIFT)) & ADC_JADDATA_JVALID_MASK)

#define ADC_JADDATA_JOVERRUN_SHIFT              (21)
#define ADC_JADDATA_JOVERRUN_MASK               (0x1U << ADC_JADDATA_JOVERRUN_SHIFT)
#define ADC_JADDATA_JOVERRUN(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_JADDATA_JOVERRUN_SHIFT)) & ADC_JADDATA_JOVERRUN_MASK)

#define ADC_JADDATA_JCHANNELSEL_SHIFT           (16)
#define ADC_JADDATA_JCHANNELSEL_MASK            (0xFU << ADC_JADDATA_JCHANNELSEL_SHIFT)
#define ADC_JADDATA_JCHANNELSEL(x)              (((uint32_t)(((uint32_t)(x)) << ADC_JADDATA_JCHANNELSEL_SHIFT)) & ADC_JADDATA_JCHANNELSEL_MASK)

#define ADC_JADDATA_JDATA_SHIFT                 (0)
#define ADC_JADDATA_JDATA_MASK                  (0xFFFFU << ADC_JADDATA_JDATA_SHIFT)
#define ADC_JADDATA_JDATA(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_JADDATA_JDATA_SHIFT)) & ADC_JADDATA_JDATA_MASK)

/*!
 * @brief ADC_JDR Register Bit Definition
 */

#define ADC_JDR_JVALID_SHIFT                    (22)
#define ADC_JDR_JVALID_MASK                     (0x1U << ADC_JDR_JVALID_SHIFT)
#define ADC_JDR_JVALID(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_JDR_JVALID_SHIFT)) & ADC_JDR_JVALID_MASK)

#define ADC_JDR_JOVERRUN_SHIFT                  (21)
#define ADC_JDR_JOVERRUN_MASK                   (0x1U << ADC_JDR_JOVERRUN_SHIFT)
#define ADC_JDR_JOVERRUN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_JDR_JOVERRUN_SHIFT)) & ADC_JDR_JOVERRUN_MASK)

#define ADC_JDR_JDATA_SHIFT                     (0)
#define ADC_JDR_JDATA_MASK                      (0xFFFFU << ADC_JDR_JDATA_SHIFT)
#define ADC_JDR_JDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JDR_JDATA_SHIFT)) & ADC_JDR_JDATA_MASK)

/*!
 * @brief ADC_LDATA Register Bit Definition
 */

#define ADC_LDATA_LVALID_SHIFT                  (21)
#define ADC_LDATA_LVALID_MASK                   (0x1U << ADC_LDATA_LVALID_SHIFT)
#define ADC_LDATA_LVALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_LDATA_LVALID_SHIFT)) & ADC_LDATA_LVALID_MASK)

#define ADC_LDATA_LOVERRUN_SHIFT                (20)
#define ADC_LDATA_LOVERRUN_MASK                 (0x1U << ADC_LDATA_LOVERRUN_SHIFT)
#define ADC_LDATA_LOVERRUN(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_LDATA_LOVERRUN_SHIFT)) & ADC_LDATA_LOVERRUN_MASK)

#define ADC_LDATA_LCHANNELSEL_SHIFT             (16)
#define ADC_LDATA_LCHANNELSEL_MASK              (0xFU << ADC_LDATA_LCHANNELSEL_SHIFT)
#define ADC_LDATA_LCHANNELSEL(x)                (((uint32_t)(((uint32_t)(x)) << ADC_LDATA_LCHANNELSEL_SHIFT)) & ADC_LDATA_LCHANNELSEL_MASK)

#define ADC_LDATA_LDATA_SHIFT                   (0)
#define ADC_LDATA_LDATA_MASK                    (0xFFFFU << ADC_LDATA_LDATA_SHIFT)
#define ADC_LDATA_LDATA(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_LDATA_LDATA_SHIFT)) & ADC_LDATA_LDATA_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */
/******************************************************************************
 *ADC Instance
*******************************************************************************/

#define ADC                  ((ADC_Type*)ADC_BASE)

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */



/*!
 * @addtogroup BKP_Peripheral_Access_Layer BKP Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * BKP Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t Reserved0[16];                                                ///< Reserved
    __IO uint32_t RTCCR;                                                        ///< RTC clock calibration register               offset: 0x40
    __IO uint32_t CR;                                                           ///< Backup control register                      offset: 0x44
    __IO uint32_t CSR;                                                          ///< Backup control status register               offset: 0x48
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t DR[20];                                                       ///< Backup data register n                       offset: 0x50
} BKP_Type;

/*******************************************************************************
 * BKP Type
 ******************************************************************************/

/*!
 * @addtogroup BKP_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief BKP_RTCCR Register Bit Definition
 */

#define BKP_RTCCR_ASOS_SHIFT                    (9)
#define BKP_RTCCR_ASOS_MASK                     (0x1U << BKP_RTCCR_ASOS_SHIFT)
#define BKP_RTCCR_ASOS(x)                       (((uint32_t)(((uint32_t)(x)) << BKP_RTCCR_ASOS_SHIFT)) & BKP_RTCCR_ASOS_MASK)

#define BKP_RTCCR_ASOE_SHIFT                    (8)
#define BKP_RTCCR_ASOE_MASK                     (0x1U << BKP_RTCCR_ASOE_SHIFT)
#define BKP_RTCCR_ASOE(x)                       (((uint32_t)(((uint32_t)(x)) << BKP_RTCCR_ASOE_SHIFT)) & BKP_RTCCR_ASOE_MASK)

#define BKP_RTCCR_CCO_SHIFT                     (7)
#define BKP_RTCCR_CCO_MASK                      (0x1U << BKP_RTCCR_CCO_SHIFT)
#define BKP_RTCCR_CCO(x)                        (((uint32_t)(((uint32_t)(x)) << BKP_RTCCR_CCO_SHIFT)) & BKP_RTCCR_CCO_MASK)

#define BKP_RTCCR_CAL_SHIFT                     (0)
#define BKP_RTCCR_CAL_MASK                      (0x7FU << BKP_RTCCR_CAL_SHIFT)
#define BKP_RTCCR_CAL(x)                        (((uint32_t)(((uint32_t)(x)) << BKP_RTCCR_CAL_SHIFT)) & BKP_RTCCR_CAL_MASK)

/*!
 * @brief BKP_CR Register Bit Definition
 */

#define BKP_CR_TPAL_SHIFT                       (1)
#define BKP_CR_TPAL_MASK                        (0x1U << BKP_CR_TPAL_SHIFT)
#define BKP_CR_TPAL(x)                          (((uint32_t)(((uint32_t)(x)) << BKP_CR_TPAL_SHIFT)) & BKP_CR_TPAL_MASK)

#define BKP_CR_TPE_SHIFT                        (0)
#define BKP_CR_TPE_MASK                         (0x1U << BKP_CR_TPE_SHIFT)
#define BKP_CR_TPE(x)                           (((uint32_t)(((uint32_t)(x)) << BKP_CR_TPE_SHIFT)) & BKP_CR_TPE_MASK)

/*!
 * @brief BKP_CSR Register Bit Definition
 */

#define BKP_CSR_TIF_SHIFT                       (9)
#define BKP_CSR_TIF_MASK                        (0x1U << BKP_CSR_TIF_SHIFT)
#define BKP_CSR_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << BKP_CSR_TIF_SHIFT)) & BKP_CSR_TIF_MASK)

#define BKP_CSR_TEF_SHIFT                       (8)
#define BKP_CSR_TEF_MASK                        (0x1U << BKP_CSR_TEF_SHIFT)
#define BKP_CSR_TEF(x)                          (((uint32_t)(((uint32_t)(x)) << BKP_CSR_TEF_SHIFT)) & BKP_CSR_TEF_MASK)

#define BKP_CSR_TPIE_SHIFT                      (2)
#define BKP_CSR_TPIE_MASK                       (0x1U << BKP_CSR_TPIE_SHIFT)
#define BKP_CSR_TPIE(x)                         (((uint32_t)(((uint32_t)(x)) << BKP_CSR_TPIE_SHIFT)) & BKP_CSR_TPIE_MASK)

#define BKP_CSR_CTI_SHIFT                       (1)
#define BKP_CSR_CTI_MASK                        (0x1U << BKP_CSR_CTI_SHIFT)
#define BKP_CSR_CTI(x)                          (((uint32_t)(((uint32_t)(x)) << BKP_CSR_CTI_SHIFT)) & BKP_CSR_CTI_MASK)

#define BKP_CSR_CTE_SHIFT                       (0)
#define BKP_CSR_CTE_MASK                        (0x1U << BKP_CSR_CTE_SHIFT)
#define BKP_CSR_CTE(x)                          (((uint32_t)(((uint32_t)(x)) << BKP_CSR_CTE_SHIFT)) & BKP_CSR_CTE_MASK)

/*!
 * @brief BKP_DR Register Bit Definition
 */

#define BKP_DR_BKP_SHIFT                        (0)
#define BKP_DR_BKP_MASK                         (0xFFFFU << BKP_DR_BKP_SHIFT)
#define BKP_DR_BKP(x)                           (((uint32_t)(((uint32_t)(x)) << BKP_DR_BKP_SHIFT)) & BKP_DR_BKP_MASK)

/*!
 * @}
 */ /* end of group BKP_Register_Masks */
/******************************************************************************
 *BKP Instance
*******************************************************************************/

#define BKP                  ((BKP_Type*)RTC_BKP_BASE)

/*!
 * @}
 */ /* end of group BKP_Peripheral_Access_Layer */



/*!
 * @addtogroup COMP_Peripheral_Access_Layer COMP Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * COMP Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CSR[2];                                                       ///< COMP x (x=1, 2) control and status register  offset: 0x0
    __IO uint32_t Reserved0[4];                                                 ///< Reserved
    __IO uint32_t CRV;                                                          ///< COMP external reference voltage register     offset: 0x18
    __IO uint32_t POLL[2];                                                      ///< COMP x (x=1, 2) polling register             offset: 0x1C
} COMP_Type;

/*******************************************************************************
 * COMP Type
 ******************************************************************************/

/*!
 * @addtogroup COMP_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief COMP_CSR Register Bit Definition
 */

#define COMP_CSR_LOCK_SHIFT                     (31)
#define COMP_CSR_LOCK_MASK                      (0x1U << COMP_CSR_LOCK_SHIFT)
#define COMP_CSR_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << COMP_CSR_LOCK_SHIFT)) & COMP_CSR_LOCK_MASK)

#define COMP_CSR_OUT_SHIFT                      (30)
#define COMP_CSR_OUT_MASK                       (0x1U << COMP_CSR_OUT_SHIFT)
#define COMP_CSR_OUT(x)                         (((uint32_t)(((uint32_t)(x)) << COMP_CSR_OUT_SHIFT)) & COMP_CSR_OUT_MASK)

#define COMP_CSR_OUTANASEL_SHIFT                (29)
#define COMP_CSR_OUTANASEL_MASK                 (0x1U << COMP_CSR_OUTANASEL_SHIFT)
#define COMP_CSR_OUTANASEL(x)                   (((uint32_t)(((uint32_t)(x)) << COMP_CSR_OUTANASEL_SHIFT)) & COMP_CSR_OUTANASEL_MASK)

#define COMP_CSR_OFLT_SHIFT                     (18)
#define COMP_CSR_OFLT_MASK                      (0x7U << COMP_CSR_OFLT_SHIFT)
#define COMP_CSR_OFLT(x)                        (((uint32_t)(((uint32_t)(x)) << COMP_CSR_OFLT_SHIFT)) & COMP_CSR_OFLT_MASK)

#define COMP_CSR_HYST_SHIFT                     (16)
#define COMP_CSR_HYST_MASK                      (0x3U << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST(x)                        (((uint32_t)(((uint32_t)(x)) << COMP_CSR_HYST_SHIFT)) & COMP_CSR_HYST_MASK)

#define COMP_CSR_POL_SHIFT                      (15)
#define COMP_CSR_POL_MASK                       (0x1U << COMP_CSR_POL_SHIFT)
#define COMP_CSR_POL(x)                         (((uint32_t)(((uint32_t)(x)) << COMP_CSR_POL_SHIFT)) & COMP_CSR_POL_MASK)

#define COMP_CSR_OUTSEL_SHIFT                   (10)
#define COMP_CSR_OUTSEL_MASK                    (0xFU << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL(x)                      (((uint32_t)(((uint32_t)(x)) << COMP_CSR_OUTSEL_SHIFT)) & COMP_CSR_OUTSEL_MASK)

#define COMP_CSR_INPSEL_SHIFT                   (7)
#define COMP_CSR_INPSEL_MASK                    (0x3U << COMP_CSR_INPSEL_SHIFT)
#define COMP_CSR_INPSEL(x)                      (((uint32_t)(((uint32_t)(x)) << COMP_CSR_INPSEL_SHIFT)) & COMP_CSR_INPSEL_MASK)

#define COMP_CSR_INMSEL_SHIFT                   (4)
#define COMP_CSR_INMSEL_MASK                    (0x7U << COMP_CSR_INMSEL_SHIFT)
#define COMP_CSR_INMSEL(x)                      (((uint32_t)(((uint32_t)(x)) << COMP_CSR_INMSEL_SHIFT)) & COMP_CSR_INMSEL_MASK)

#define COMP_CSR_MODE_SHIFT                     (2)
#define COMP_CSR_MODE_MASK                      (0x3U << COMP_CSR_MODE_SHIFT)
#define COMP_CSR_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << COMP_CSR_MODE_SHIFT)) & COMP_CSR_MODE_MASK)

#define COMP_CSR_EN_SHIFT                       (0)
#define COMP_CSR_EN_MASK                        (0x1U << COMP_CSR_EN_SHIFT)
#define COMP_CSR_EN(x)                          (((uint32_t)(((uint32_t)(x)) << COMP_CSR_EN_SHIFT)) & COMP_CSR_EN_MASK)

/*!
 * @brief COMP_CRV Register Bit Definition
 */

#define COMP_CRV_CRVSRC_SHIFT                   (5)
#define COMP_CRV_CRVSRC_MASK                    (0x1U << COMP_CRV_CRVSRC_SHIFT)
#define COMP_CRV_CRVSRC(x)                      (((uint32_t)(((uint32_t)(x)) << COMP_CRV_CRVSRC_SHIFT)) & COMP_CRV_CRVSRC_MASK)

#define COMP_CRV_CRVEN_SHIFT                    (4)
#define COMP_CRV_CRVEN_MASK                     (0x1U << COMP_CRV_CRVEN_SHIFT)
#define COMP_CRV_CRVEN(x)                       (((uint32_t)(((uint32_t)(x)) << COMP_CRV_CRVEN_SHIFT)) & COMP_CRV_CRVEN_MASK)

#define COMP_CRV_CRVSEL_SHIFT                   (0)
#define COMP_CRV_CRVSEL_MASK                    (0xFU << COMP_CRV_CRVSEL_SHIFT)
#define COMP_CRV_CRVSEL(x)                      (((uint32_t)(((uint32_t)(x)) << COMP_CRV_CRVSEL_SHIFT)) & COMP_CRV_CRVSEL_MASK)

/*!
 * @brief COMP_POLL Register Bit Definition
 */

#define COMP_POLL_POUT_SHIFT                    (8)
#define COMP_POLL_POUT_MASK                     (0x7U << COMP_POLL_POUT_SHIFT)
#define COMP_POLL_POUT(x)                       (((uint32_t)(((uint32_t)(x)) << COMP_POLL_POUT_SHIFT)) & COMP_POLL_POUT_MASK)

#define COMP_POLL_PERIOD_SHIFT                  (4)
#define COMP_POLL_PERIOD_MASK                   (0x7U << COMP_POLL_PERIOD_SHIFT)
#define COMP_POLL_PERIOD(x)                     (((uint32_t)(((uint32_t)(x)) << COMP_POLL_PERIOD_SHIFT)) & COMP_POLL_PERIOD_MASK)

#define COMP_POLL_FIXN_SHIFT                    (2)
#define COMP_POLL_FIXN_MASK                     (0x1U << COMP_POLL_FIXN_SHIFT)
#define COMP_POLL_FIXN(x)                       (((uint32_t)(((uint32_t)(x)) << COMP_POLL_FIXN_SHIFT)) & COMP_POLL_FIXN_MASK)

#define COMP_POLL_POLLCH_SHIFT                  (1)
#define COMP_POLL_POLLCH_MASK                   (0x1U << COMP_POLL_POLLCH_SHIFT)
#define COMP_POLL_POLLCH(x)                     (((uint32_t)(((uint32_t)(x)) << COMP_POLL_POLLCH_SHIFT)) & COMP_POLL_POLLCH_MASK)

#define COMP_POLL_POLLEN_SHIFT                  (0)
#define COMP_POLL_POLLEN_MASK                   (0x1U << COMP_POLL_POLLEN_SHIFT)
#define COMP_POLL_POLLEN(x)                     (((uint32_t)(((uint32_t)(x)) << COMP_POLL_POLLEN_SHIFT)) & COMP_POLL_POLLEN_MASK)

/*!
 * @}
 */ /* end of group COMP_Register_Masks */
/******************************************************************************
 *COMP Instance
*******************************************************************************/

#define COMP                 ((COMP_Type*)COMP_BASE)

/*!
 * @}
 */ /* end of group COMP_Peripheral_Access_Layer */



/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * CRC Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t DR;                                                           ///< CRC Data Register                            offset: 0x00
    __IO uint32_t IDR;                                                          ///< CRC Independent Data Register                offset: 0x04
    __IO uint32_t CR;                                                           ///< CRC Control Register                         offset: 0x08
    __IO uint32_t MIR;                                                          ///< CRC Middle Data Register                     offset: 0x0C
} CRC_Type;

/*******************************************************************************
 * CRC Type
 ******************************************************************************/

/*!
 * @addtogroup CRC_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief CRC_DR Register Bit Definition
 */

#define CRC_DR_DR_SHIFT                         (0)
#define CRC_DR_DR_MASK                          (0xFFFFFFFFU << CRC_DR_DR_SHIFT)
#define CRC_DR_DR(x)                            (((uint32_t)(((uint32_t)(x)) << CRC_DR_DR_SHIFT)) & CRC_DR_DR_MASK)

/*!
 * @brief CRC_IDR Register Bit Definition
 */

#define CRC_IDR_IDR_SHIFT                       (0)
#define CRC_IDR_IDR_MASK                        (0xFFU << CRC_IDR_IDR_SHIFT)
#define CRC_IDR_IDR(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_IDR_IDR_SHIFT)) & CRC_IDR_IDR_MASK)

/*!
 * @brief CRC_CR Register Bit Definition
 */

#define CRC_CR_OES_SHIFT                        (5)
#define CRC_CR_OES_MASK                         (0x1U << CRC_CR_OES_SHIFT)
#define CRC_CR_OES(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_CR_OES_SHIFT)) & CRC_CR_OES_MASK)

#define CRC_CR_IES_SHIFT                        (4)
#define CRC_CR_IES_MASK                         (0x1U << CRC_CR_IES_SHIFT)
#define CRC_CR_IES(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_CR_IES_SHIFT)) & CRC_CR_IES_MASK)

#define CRC_CR_ISIZE_SHIFT                      (2)
#define CRC_CR_ISIZE_MASK                       (0x3U << CRC_CR_ISIZE_SHIFT)
#define CRC_CR_ISIZE(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CR_ISIZE_SHIFT)) & CRC_CR_ISIZE_MASK)

#define CRC_CR_AS_SHIFT                         (1)
#define CRC_CR_AS_MASK                          (0x1U << CRC_CR_AS_SHIFT)
#define CRC_CR_AS(x)                            (((uint32_t)(((uint32_t)(x)) << CRC_CR_AS_SHIFT)) & CRC_CR_AS_MASK)

#define CRC_CR_RST_SHIFT                        (0)
#define CRC_CR_RST_MASK                         (0x1U << CRC_CR_RST_SHIFT)
#define CRC_CR_RST(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_CR_RST_SHIFT)) & CRC_CR_RST_MASK)

/*!
 * @brief CRC_MIR Register Bit Definition
 */

#define CRC_MIR_MIR_SHIFT                       (0)
#define CRC_MIR_MIR_MASK                        (0xFFFFFFFFU << CRC_MIR_MIR_SHIFT)
#define CRC_MIR_MIR(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_MIR_MIR_SHIFT)) & CRC_MIR_MIR_MASK)

/*!
 * @}
 */ /* end of group CRC_Register_Masks */
/******************************************************************************
 *CRC Instance
*******************************************************************************/

#define CRC                  ((CRC_Type*)CRC_BASE)

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/*!
 * @addtogroup CRS_Peripheral_Access_Layer CRS Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * CRS Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR;                                                           ///< CRS control register                         offset: 0x00
    __IO uint32_t CFGR;                                                         ///< CRS configuration register                   offset: 0x04
    __IO uint32_t ISR;                                                          ///< CRS interrupt status register                offset: 0x08
    __IO uint32_t ICR;                                                          ///< CRS interrupt flag clear register            offset: 0x0C
} CRS_Type;

/*******************************************************************************
 * CRS Type
 ******************************************************************************/

/*!
 * @addtogroup CRS_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief CRS_CR Register Bit Definition
 */

#define CRS_CR_TRIM_SHIFT                       (8)
#define CRS_CR_TRIM_MASK                        (0x3FFU << CRS_CR_TRIM_SHIFT)
#define CRS_CR_TRIM(x)                          (((uint32_t)(((uint32_t)(x)) << CRS_CR_TRIM_SHIFT)) & CRS_CR_TRIM_MASK)

#define CRS_CR_SWSYNC_SHIFT                     (7)
#define CRS_CR_SWSYNC_MASK                      (0x1U << CRS_CR_SWSYNC_SHIFT)
#define CRS_CR_SWSYNC(x)                        (((uint32_t)(((uint32_t)(x)) << CRS_CR_SWSYNC_SHIFT)) & CRS_CR_SWSYNC_MASK)

#define CRS_CR_AUTOTRIMEN_SHIFT                 (6)
#define CRS_CR_AUTOTRIMEN_MASK                  (0x1U << CRS_CR_AUTOTRIMEN_SHIFT)
#define CRS_CR_AUTOTRIMEN(x)                    (((uint32_t)(((uint32_t)(x)) << CRS_CR_AUTOTRIMEN_SHIFT)) & CRS_CR_AUTOTRIMEN_MASK)

#define CRS_CR_CEN_SHIFT                        (5)
#define CRS_CR_CEN_MASK                         (0x1U << CRS_CR_CEN_SHIFT)
#define CRS_CR_CEN(x)                           (((uint32_t)(((uint32_t)(x)) << CRS_CR_CEN_SHIFT)) & CRS_CR_CEN_MASK)

#define CRS_CR_ESYNCIE_SHIFT                    (3)
#define CRS_CR_ESYNCIE_MASK                     (0x1U << CRS_CR_ESYNCIE_SHIFT)
#define CRS_CR_ESYNCIE(x)                       (((uint32_t)(((uint32_t)(x)) << CRS_CR_ESYNCIE_SHIFT)) & CRS_CR_ESYNCIE_MASK)

#define CRS_CR_ERRIE_SHIFT                      (2)
#define CRS_CR_ERRIE_MASK                       (0x1U << CRS_CR_ERRIE_SHIFT)
#define CRS_CR_ERRIE(x)                         (((uint32_t)(((uint32_t)(x)) << CRS_CR_ERRIE_SHIFT)) & CRS_CR_ERRIE_MASK)

#define CRS_CR_SYNCWARNIE_SHIFT                 (1)
#define CRS_CR_SYNCWARNIE_MASK                  (0x1U << CRS_CR_SYNCWARNIE_SHIFT)
#define CRS_CR_SYNCWARNIE(x)                    (((uint32_t)(((uint32_t)(x)) << CRS_CR_SYNCWARNIE_SHIFT)) & CRS_CR_SYNCWARNIE_MASK)

#define CRS_CR_SYNCOKIE_SHIFT                   (0)
#define CRS_CR_SYNCOKIE_MASK                    (0x1U << CRS_CR_SYNCOKIE_SHIFT)
#define CRS_CR_SYNCOKIE(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_CR_SYNCOKIE_SHIFT)) & CRS_CR_SYNCOKIE_MASK)

/*!
 * @brief CRS_CFGR Register Bit Definition
 */

#define CRS_CFGR_SYNCPOL_SHIFT                  (31)
#define CRS_CFGR_SYNCPOL_MASK                   (0x1U << CRS_CFGR_SYNCPOL_SHIFT)
#define CRS_CFGR_SYNCPOL(x)                     (((uint32_t)(((uint32_t)(x)) << CRS_CFGR_SYNCPOL_SHIFT)) & CRS_CFGR_SYNCPOL_MASK)

#define CRS_CFGR_SYNCSRC_SHIFT                  (28)
#define CRS_CFGR_SYNCSRC_MASK                   (0x3U << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC(x)                     (((uint32_t)(((uint32_t)(x)) << CRS_CFGR_SYNCSRC_SHIFT)) & CRS_CFGR_SYNCSRC_MASK)

#define CRS_CFGR_SYNCDIV_SHIFT                  (24)
#define CRS_CFGR_SYNCDIV_MASK                   (0x7U << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV(x)                     (((uint32_t)(((uint32_t)(x)) << CRS_CFGR_SYNCDIV_SHIFT)) & CRS_CFGR_SYNCDIV_MASK)

#define CRS_CFGR_FELIM_SHIFT                    (16)
#define CRS_CFGR_FELIM_MASK                     (0xFFU << CRS_CFGR_FELIM_SHIFT)
#define CRS_CFGR_FELIM(x)                       (((uint32_t)(((uint32_t)(x)) << CRS_CFGR_FELIM_SHIFT)) & CRS_CFGR_FELIM_MASK)

#define CRS_CFGR_RELOAD_SHIFT                   (0)
#define CRS_CFGR_RELOAD_MASK                    (0xFFFFU << CRS_CFGR_RELOAD_SHIFT)
#define CRS_CFGR_RELOAD(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_CFGR_RELOAD_SHIFT)) & CRS_CFGR_RELOAD_MASK)

/*!
 * @brief CRS_ISR Register Bit Definition
 */

#define CRS_ISR_FECAP_SHIFT                     (16)
#define CRS_ISR_FECAP_MASK                      (0xFFFFU << CRS_ISR_FECAP_SHIFT)
#define CRS_ISR_FECAP(x)                        (((uint32_t)(((uint32_t)(x)) << CRS_ISR_FECAP_SHIFT)) & CRS_ISR_FECAP_MASK)

#define CRS_ISR_FEDIR_SHIFT                     (15)
#define CRS_ISR_FEDIR_MASK                      (0x1U << CRS_ISR_FEDIR_SHIFT)
#define CRS_ISR_FEDIR(x)                        (((uint32_t)(((uint32_t)(x)) << CRS_ISR_FEDIR_SHIFT)) & CRS_ISR_FEDIR_MASK)

#define CRS_ISR_TRIMOVF_SHIFT                   (10)
#define CRS_ISR_TRIMOVF_MASK                    (0x1U << CRS_ISR_TRIMOVF_SHIFT)
#define CRS_ISR_TRIMOVF(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_ISR_TRIMOVF_SHIFT)) & CRS_ISR_TRIMOVF_MASK)

#define CRS_ISR_SYNCMISS_SHIFT                  (9)
#define CRS_ISR_SYNCMISS_MASK                   (0x1U << CRS_ISR_SYNCMISS_SHIFT)
#define CRS_ISR_SYNCMISS(x)                     (((uint32_t)(((uint32_t)(x)) << CRS_ISR_SYNCMISS_SHIFT)) & CRS_ISR_SYNCMISS_MASK)

#define CRS_ISR_SYNCERR_SHIFT                   (8)
#define CRS_ISR_SYNCERR_MASK                    (0x1U << CRS_ISR_SYNCERR_SHIFT)
#define CRS_ISR_SYNCERR(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_ISR_SYNCERR_SHIFT)) & CRS_ISR_SYNCERR_MASK)

#define CRS_ISR_ESYNCF_SHIFT                    (3)
#define CRS_ISR_ESYNCF_MASK                     (0x1U << CRS_ISR_ESYNCF_SHIFT)
#define CRS_ISR_ESYNCF(x)                       (((uint32_t)(((uint32_t)(x)) << CRS_ISR_ESYNCF_SHIFT)) & CRS_ISR_ESYNCF_MASK)

#define CRS_ISR_ERRF_SHIFT                      (2)
#define CRS_ISR_ERRF_MASK                       (0x1U << CRS_ISR_ERRF_SHIFT)
#define CRS_ISR_ERRF(x)                         (((uint32_t)(((uint32_t)(x)) << CRS_ISR_ERRF_SHIFT)) & CRS_ISR_ERRF_MASK)

#define CRS_ISR_SYNCWARNF_SHIFT                 (1)
#define CRS_ISR_SYNCWARNF_MASK                  (0x1U << CRS_ISR_SYNCWARNF_SHIFT)
#define CRS_ISR_SYNCWARNF(x)                    (((uint32_t)(((uint32_t)(x)) << CRS_ISR_SYNCWARNF_SHIFT)) & CRS_ISR_SYNCWARNF_MASK)

#define CRS_ISR_SYNCOKF_SHIFT                   (0)
#define CRS_ISR_SYNCOKF_MASK                    (0x1U << CRS_ISR_SYNCOKF_SHIFT)
#define CRS_ISR_SYNCOKF(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_ISR_SYNCOKF_SHIFT)) & CRS_ISR_SYNCOKF_MASK)

/*!
 * @brief CRS_ICR Register Bit Definition
 */

#define CRS_ICR_ESYNCC_SHIFT                    (3)
#define CRS_ICR_ESYNCC_MASK                     (0x1U << CRS_ICR_ESYNCC_SHIFT)
#define CRS_ICR_ESYNCC(x)                       (((uint32_t)(((uint32_t)(x)) << CRS_ICR_ESYNCC_SHIFT)) & CRS_ICR_ESYNCC_MASK)

#define CRS_ICR_ERRC_SHIFT                      (2)
#define CRS_ICR_ERRC_MASK                       (0x1U << CRS_ICR_ERRC_SHIFT)
#define CRS_ICR_ERRC(x)                         (((uint32_t)(((uint32_t)(x)) << CRS_ICR_ERRC_SHIFT)) & CRS_ICR_ERRC_MASK)

#define CRS_ICR_SYNCWARNC_SHIFT                 (1)
#define CRS_ICR_SYNCWARNC_MASK                  (0x1U << CRS_ICR_SYNCWARNC_SHIFT)
#define CRS_ICR_SYNCWARNC(x)                    (((uint32_t)(((uint32_t)(x)) << CRS_ICR_SYNCWARNC_SHIFT)) & CRS_ICR_SYNCWARNC_MASK)

#define CRS_ICR_SYNCOKC_SHIFT                   (0)
#define CRS_ICR_SYNCOKC_MASK                    (0x1U << CRS_ICR_SYNCOKC_SHIFT)
#define CRS_ICR_SYNCOKC(x)                      (((uint32_t)(((uint32_t)(x)) << CRS_ICR_SYNCOKC_SHIFT)) & CRS_ICR_SYNCOKC_MASK)

/*!
 * @}
 */ /* end of group CRS_Register_Masks */
/******************************************************************************
 *CRS Instance
*******************************************************************************/

#define CRS                  ((CRS_Type*)CRS_BASE)

/*!
 * @}
 */ /* end of group CRS_Peripheral_Access_Layer */

/*!
 * @addtogroup DBGMCU_Peripheral_Access_Layer DBGMCU Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * DBGMCU Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t IDCODE;                                                       ///< DBG ID code register                         offset: 0x00
    __IO uint32_t CR;                                                           ///< DBG control register                         offset: 0x04
} DBGMCU_Type;

/*******************************************************************************
 * DBGMCU Type
 ******************************************************************************/

/*!
 * @addtogroup DBGMCU_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief DBGMCU_IDCODE Register Bit Definition
 */

#define DBGMCU_IDCODE_DEVID_SHIFT               (0)
#define DBGMCU_IDCODE_DEVID_MASK                (0xFFFFFFFFU << DBGMCU_IDCODE_DEVID_SHIFT)
#define DBGMCU_IDCODE_DEVID(x)                  (((uint32_t)(((uint32_t)(x)) << DBGMCU_IDCODE_DEVID_SHIFT)) & DBGMCU_IDCODE_DEVID_MASK)

/*!
 * @brief DBGMCU_CR Register Bit Definition
 */

#define DBGMCU_CR_IPGDEBUG_SHIFT                (24)
#define DBGMCU_CR_IPGDEBUG_MASK                 (0x1U << DBGMCU_CR_IPGDEBUG_SHIFT)
#define DBGMCU_CR_IPGDEBUG(x)                   (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_IPGDEBUG_SHIFT)) & DBGMCU_CR_IPGDEBUG_MASK)

#define DBGMCU_CR_IPSTESTACCESS_SHIFT           (22)
#define DBGMCU_CR_IPSTESTACCESS_MASK            (0x1U << DBGMCU_CR_IPSTESTACCESS_SHIFT)
#define DBGMCU_CR_IPSTESTACCESS(x)              (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_IPSTESTACCESS_SHIFT)) & DBGMCU_CR_IPSTESTACCESS_MASK)

#define DBGMCU_CR_IPSSUPERVISORACCESS_SHIFT     (21)
#define DBGMCU_CR_IPSSUPERVISORACCESS_MASK      (0x1U << DBGMCU_CR_IPSSUPERVISORACCESS_SHIFT)
#define DBGMCU_CR_IPSSUPERVISORACCESS(x)        (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_IPSSUPERVISORACCESS_SHIFT)) & DBGMCU_CR_IPSSUPERVISORACCESS_MASK)

#define DBGMCU_CR_DBGTIM14STOP_SHIFT            (18)
#define DBGMCU_CR_DBGTIM14STOP_MASK             (0x1U << DBGMCU_CR_DBGTIM14STOP_SHIFT)
#define DBGMCU_CR_DBGTIM14STOP(x)               (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM14STOP_SHIFT)) & DBGMCU_CR_DBGTIM14STOP_MASK)

#define DBGMCU_CR_DBGTIM17STOP_SHIFT            (17)
#define DBGMCU_CR_DBGTIM17STOP_MASK             (0x1U << DBGMCU_CR_DBGTIM17STOP_SHIFT)
#define DBGMCU_CR_DBGTIM17STOP(x)               (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM17STOP_SHIFT)) & DBGMCU_CR_DBGTIM17STOP_MASK)

#define DBGMCU_CR_DBGTIM16STOP_SHIFT            (16)
#define DBGMCU_CR_DBGTIM16STOP_MASK             (0x1U << DBGMCU_CR_DBGTIM16STOP_SHIFT)
#define DBGMCU_CR_DBGTIM16STOP(x)               (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM16STOP_SHIFT)) & DBGMCU_CR_DBGTIM16STOP_MASK)

#define DBGMCU_CR_DBGTIM3STOP_SHIFT             (12)
#define DBGMCU_CR_DBGTIM3STOP_MASK              (0x1U << DBGMCU_CR_DBGTIM3STOP_SHIFT)
#define DBGMCU_CR_DBGTIM3STOP(x)                (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM3STOP_SHIFT)) & DBGMCU_CR_DBGTIM3STOP_MASK)

#define DBGMCU_CR_DBGTIM2STOP_SHIFT             (11)
#define DBGMCU_CR_DBGTIM2STOP_MASK              (0x1U << DBGMCU_CR_DBGTIM2STOP_SHIFT)
#define DBGMCU_CR_DBGTIM2STOP(x)                (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM2STOP_SHIFT)) & DBGMCU_CR_DBGTIM2STOP_MASK)

#define DBGMCU_CR_DBGTIM1STOP_SHIFT             (10)
#define DBGMCU_CR_DBGTIM1STOP_MASK              (0x1U << DBGMCU_CR_DBGTIM1STOP_SHIFT)
#define DBGMCU_CR_DBGTIM1STOP(x)                (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGTIM1STOP_SHIFT)) & DBGMCU_CR_DBGTIM1STOP_MASK)

#define DBGMCU_CR_DBGWWDGSTOP_SHIFT             (9)
#define DBGMCU_CR_DBGWWDGSTOP_MASK              (0x1U << DBGMCU_CR_DBGWWDGSTOP_SHIFT)
#define DBGMCU_CR_DBGWWDGSTOP(x)                (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGWWDGSTOP_SHIFT)) & DBGMCU_CR_DBGWWDGSTOP_MASK)

#define DBGMCU_CR_DBGIWDGSTOP_SHIFT             (8)
#define DBGMCU_CR_DBGIWDGSTOP_MASK              (0x1U << DBGMCU_CR_DBGIWDGSTOP_SHIFT)
#define DBGMCU_CR_DBGIWDGSTOP(x)                (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGIWDGSTOP_SHIFT)) & DBGMCU_CR_DBGIWDGSTOP_MASK)

#define DBGMCU_CR_DBGSTOPFORLDO_SHIFT           (3)
#define DBGMCU_CR_DBGSTOPFORLDO_MASK            (0x1U << DBGMCU_CR_DBGSTOPFORLDO_SHIFT)
#define DBGMCU_CR_DBGSTOPFORLDO(x)              (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGSTOPFORLDO_SHIFT)) & DBGMCU_CR_DBGSTOPFORLDO_MASK)

#define DBGMCU_CR_DBGSTANDBY_SHIFT              (2)
#define DBGMCU_CR_DBGSTANDBY_MASK               (0x1U << DBGMCU_CR_DBGSTANDBY_SHIFT)
#define DBGMCU_CR_DBGSTANDBY(x)                 (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGSTANDBY_SHIFT)) & DBGMCU_CR_DBGSTANDBY_MASK)

#define DBGMCU_CR_DBGSTOP_SHIFT                 (1)
#define DBGMCU_CR_DBGSTOP_MASK                  (0x1U << DBGMCU_CR_DBGSTOP_SHIFT)
#define DBGMCU_CR_DBGSTOP(x)                    (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGSTOP_SHIFT)) & DBGMCU_CR_DBGSTOP_MASK)

#define DBGMCU_CR_DBGSLEEP_SHIFT                (0)
#define DBGMCU_CR_DBGSLEEP_MASK                 (0x1U << DBGMCU_CR_DBGSLEEP_SHIFT)
#define DBGMCU_CR_DBGSLEEP(x)                   (((uint32_t)(((uint32_t)(x)) << DBGMCU_CR_DBGSLEEP_SHIFT)) & DBGMCU_CR_DBGSLEEP_MASK)

/*!
 * @}
 */ /* end of group DBGMCU_Register_Masks */
/******************************************************************************
 *DBGMCU Instance
*******************************************************************************/

#define DBGMCU               ((DBGMCU_Type*)DBGMCU_BASE)

/*!
 * @}
 */ /* end of group DBGMCU_Peripheral_Access_Layer */



/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * DMA Type
 ******************************************************************************/
#define DMA_CHANNEL_COUNT  7u
typedef struct {
    __IO uint32_t ISR;                                                          ///< DMA interrupt status register                offset: 0x00
    __IO uint32_t IFCR;                                                         ///< DMA interrupt flag clear register            offset: 0x04
    struct {
            __IO uint32_t CCR;                                                  ///< DMAchannelxconfigurationregister             offset: 0x08
            __IO uint32_t CNDTR;                                                ///< DMAchannelxtransferquantityregister          offset: 0x0C
            __IO uint32_t CPAR;                                                 ///< DMAchannelxperipheraladdressregister         offset: 0x10
            __IO uint32_t CMAR;                                                 ///< DMAchannelxmemoryaddressregister             offset: 0x14
            __IO uint32_t Reserved0;
    } CH[DMA_CHANNEL_COUNT];
} DMA_Type;

/*******************************************************************************
 * DMA Type
 ******************************************************************************/

/*!
 * @addtogroup DMA_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief DMA_ISR Register Bit Definition
 */

#define DMA_ISR_TEIF7_SHIFT                     (27)
#define DMA_ISR_TEIF7_MASK                      (0x1U << DMA_ISR_TEIF7_SHIFT)
#define DMA_ISR_TEIF7(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF7_SHIFT)) & DMA_ISR_TEIF7_MASK)

#define DMA_ISR_HTIF7_SHIFT                     (26)
#define DMA_ISR_HTIF7_MASK                      (0x1U << DMA_ISR_HTIF7_SHIFT)
#define DMA_ISR_HTIF7(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF7_SHIFT)) & DMA_ISR_HTIF7_MASK)

#define DMA_ISR_TCIF7_SHIFT                     (25)
#define DMA_ISR_TCIF7_MASK                      (0x1U << DMA_ISR_TCIF7_SHIFT)
#define DMA_ISR_TCIF7(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF7_SHIFT)) & DMA_ISR_TCIF7_MASK)

#define DMA_ISR_GIF7_SHIFT                      (24)
#define DMA_ISR_GIF7_MASK                       (0x1U << DMA_ISR_GIF7_SHIFT)
#define DMA_ISR_GIF7(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF7_SHIFT)) & DMA_ISR_GIF7_MASK)

#define DMA_ISR_TEIF6_SHIFT                     (23)
#define DMA_ISR_TEIF6_MASK                      (0x1U << DMA_ISR_TEIF6_SHIFT)
#define DMA_ISR_TEIF6(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF6_SHIFT)) & DMA_ISR_TEIF6_MASK)

#define DMA_ISR_HTIF6_SHIFT                     (22)
#define DMA_ISR_HTIF6_MASK                      (0x1U << DMA_ISR_HTIF6_SHIFT)
#define DMA_ISR_HTIF6(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF6_SHIFT)) & DMA_ISR_HTIF6_MASK)

#define DMA_ISR_TCIF16_SHIFT                    (21)
#define DMA_ISR_TCIF16_MASK                     (0x1U << DMA_ISR_TCIF16_SHIFT)
#define DMA_ISR_TCIF16(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF16_SHIFT)) & DMA_ISR_TCIF16_MASK)

#define DMA_ISR_GIF6_SHIFT                      (20)
#define DMA_ISR_GIF6_MASK                       (0x1U << DMA_ISR_GIF6_SHIFT)
#define DMA_ISR_GIF6(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF6_SHIFT)) & DMA_ISR_GIF6_MASK)

#define DMA_ISR_TEIF5_SHIFT                     (19)
#define DMA_ISR_TEIF5_MASK                      (0x1U << DMA_ISR_TEIF5_SHIFT)
#define DMA_ISR_TEIF5(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF5_SHIFT)) & DMA_ISR_TEIF5_MASK)

#define DMA_ISR_HTIF5_SHIFT                     (18)
#define DMA_ISR_HTIF5_MASK                      (0x1U << DMA_ISR_HTIF5_SHIFT)
#define DMA_ISR_HTIF5(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF5_SHIFT)) & DMA_ISR_HTIF5_MASK)

#define DMA_ISR_TCIF5_SHIFT                     (17)
#define DMA_ISR_TCIF5_MASK                      (0x1U << DMA_ISR_TCIF5_SHIFT)
#define DMA_ISR_TCIF5(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF5_SHIFT)) & DMA_ISR_TCIF5_MASK)

#define DMA_ISR_GIF5_SHIFT                      (16)
#define DMA_ISR_GIF5_MASK                       (0x1U << DMA_ISR_GIF5_SHIFT)
#define DMA_ISR_GIF5(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF5_SHIFT)) & DMA_ISR_GIF5_MASK)

#define DMA_ISR_TEIF4_SHIFT                     (15)
#define DMA_ISR_TEIF4_MASK                      (0x1U << DMA_ISR_TEIF4_SHIFT)
#define DMA_ISR_TEIF4(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF4_SHIFT)) & DMA_ISR_TEIF4_MASK)

#define DMA_ISR_HTIF4_SHIFT                     (14)
#define DMA_ISR_HTIF4_MASK                      (0x1U << DMA_ISR_HTIF4_SHIFT)
#define DMA_ISR_HTIF4(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF4_SHIFT)) & DMA_ISR_HTIF4_MASK)

#define DMA_ISR_TCIF4_SHIFT                     (13)
#define DMA_ISR_TCIF4_MASK                      (0x1U << DMA_ISR_TCIF4_SHIFT)
#define DMA_ISR_TCIF4(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF4_SHIFT)) & DMA_ISR_TCIF4_MASK)

#define DMA_ISR_GIF4_SHIFT                      (12)
#define DMA_ISR_GIF4_MASK                       (0x1U << DMA_ISR_GIF4_SHIFT)
#define DMA_ISR_GIF4(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF4_SHIFT)) & DMA_ISR_GIF4_MASK)

#define DMA_ISR_TEIF3_SHIFT                     (11)
#define DMA_ISR_TEIF3_MASK                      (0x1U << DMA_ISR_TEIF3_SHIFT)
#define DMA_ISR_TEIF3(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF3_SHIFT)) & DMA_ISR_TEIF3_MASK)

#define DMA_ISR_HTIF3_SHIFT                     (10)
#define DMA_ISR_HTIF3_MASK                      (0x1U << DMA_ISR_HTIF3_SHIFT)
#define DMA_ISR_HTIF3(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF3_SHIFT)) & DMA_ISR_HTIF3_MASK)

#define DMA_ISR_TCIF3_SHIFT                     (9)
#define DMA_ISR_TCIF3_MASK                      (0x1U << DMA_ISR_TCIF3_SHIFT)
#define DMA_ISR_TCIF3(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF3_SHIFT)) & DMA_ISR_TCIF3_MASK)

#define DMA_ISR_GIF3_SHIFT                      (8)
#define DMA_ISR_GIF3_MASK                       (0x1U << DMA_ISR_GIF3_SHIFT)
#define DMA_ISR_GIF3(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF3_SHIFT)) & DMA_ISR_GIF3_MASK)

#define DMA_ISR_TEIF2_SHIFT                     (7)
#define DMA_ISR_TEIF2_MASK                      (0x1U << DMA_ISR_TEIF2_SHIFT)
#define DMA_ISR_TEIF2(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF2_SHIFT)) & DMA_ISR_TEIF2_MASK)

#define DMA_ISR_HTIF2_SHIFT                     (6)
#define DMA_ISR_HTIF2_MASK                      (0x1U << DMA_ISR_HTIF2_SHIFT)
#define DMA_ISR_HTIF2(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF2_SHIFT)) & DMA_ISR_HTIF2_MASK)

#define DMA_ISR_TCIF2_SHIFT                     (5)
#define DMA_ISR_TCIF2_MASK                      (0x1U << DMA_ISR_TCIF2_SHIFT)
#define DMA_ISR_TCIF2(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF2_SHIFT)) & DMA_ISR_TCIF2_MASK)

#define DMA_ISR_GIF2_SHIFT                      (4)
#define DMA_ISR_GIF2_MASK                       (0x1U << DMA_ISR_GIF2_SHIFT)
#define DMA_ISR_GIF2(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF2_SHIFT)) & DMA_ISR_GIF2_MASK)

#define DMA_ISR_TEIF1_SHIFT                     (3)
#define DMA_ISR_TEIF1_MASK                      (0x1U << DMA_ISR_TEIF1_SHIFT)
#define DMA_ISR_TEIF1(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TEIF1_SHIFT)) & DMA_ISR_TEIF1_MASK)

#define DMA_ISR_HTIF1_SHIFT                     (2)
#define DMA_ISR_HTIF1_MASK                      (0x1U << DMA_ISR_HTIF1_SHIFT)
#define DMA_ISR_HTIF1(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_HTIF1_SHIFT)) & DMA_ISR_HTIF1_MASK)

#define DMA_ISR_TCIF1_SHIFT                     (1)
#define DMA_ISR_TCIF1_MASK                      (0x1U << DMA_ISR_TCIF1_SHIFT)
#define DMA_ISR_TCIF1(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_ISR_TCIF1_SHIFT)) & DMA_ISR_TCIF1_MASK)

#define DMA_ISR_GIF1_SHIFT                      (0)
#define DMA_ISR_GIF1_MASK                       (0x1U << DMA_ISR_GIF1_SHIFT)
#define DMA_ISR_GIF1(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ISR_GIF1_SHIFT)) & DMA_ISR_GIF1_MASK)

/*!
 * @brief DMA_IFCR Register Bit Definition
 */

#define DMA_IFCR_CTEIF7_SHIFT                   (27)
#define DMA_IFCR_CTEIF7_MASK                    (0x1U << DMA_IFCR_CTEIF7_SHIFT)
#define DMA_IFCR_CTEIF7(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF7_SHIFT)) & DMA_IFCR_CTEIF7_MASK)

#define DMA_IFCR_CHTIF7_SHIFT                   (26)
#define DMA_IFCR_CHTIF7_MASK                    (0x1U << DMA_IFCR_CHTIF7_SHIFT)
#define DMA_IFCR_CHTIF7(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF7_SHIFT)) & DMA_IFCR_CHTIF7_MASK)

#define DMA_IFCR_CTCIF7_SHIFT                   (25)
#define DMA_IFCR_CTCIF7_MASK                    (0x1U << DMA_IFCR_CTCIF7_SHIFT)
#define DMA_IFCR_CTCIF7(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF7_SHIFT)) & DMA_IFCR_CTCIF7_MASK)

#define DMA_IFCR_CGIF7_SHIFT                    (24)
#define DMA_IFCR_CGIF7_MASK                     (0x1U << DMA_IFCR_CGIF7_SHIFT)
#define DMA_IFCR_CGIF7(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF7_SHIFT)) & DMA_IFCR_CGIF7_MASK)

#define DMA_IFCR_CTEIF6_SHIFT                   (23)
#define DMA_IFCR_CTEIF6_MASK                    (0x1U << DMA_IFCR_CTEIF6_SHIFT)
#define DMA_IFCR_CTEIF6(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF6_SHIFT)) & DMA_IFCR_CTEIF6_MASK)

#define DMA_IFCR_CHTIF6_SHIFT                   (22)
#define DMA_IFCR_CHTIF6_MASK                    (0x1U << DMA_IFCR_CHTIF6_SHIFT)
#define DMA_IFCR_CHTIF6(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF6_SHIFT)) & DMA_IFCR_CHTIF6_MASK)

#define DMA_IFCR_CTCIF6_SHIFT                   (21)
#define DMA_IFCR_CTCIF6_MASK                    (0x1U << DMA_IFCR_CTCIF6_SHIFT)
#define DMA_IFCR_CTCIF6(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF6_SHIFT)) & DMA_IFCR_CTCIF6_MASK)

#define DMA_IFCR_CGIF6_SHIFT                    (20)
#define DMA_IFCR_CGIF6_MASK                     (0x1U << DMA_IFCR_CGIF6_SHIFT)
#define DMA_IFCR_CGIF6(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF6_SHIFT)) & DMA_IFCR_CGIF6_MASK)

#define DMA_IFCR_CTEIF5_SHIFT                   (19)
#define DMA_IFCR_CTEIF5_MASK                    (0x1U << DMA_IFCR_CTEIF5_SHIFT)
#define DMA_IFCR_CTEIF5(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF5_SHIFT)) & DMA_IFCR_CTEIF5_MASK)

#define DMA_IFCR_CHTIF5_SHIFT                   (18)
#define DMA_IFCR_CHTIF5_MASK                    (0x1U << DMA_IFCR_CHTIF5_SHIFT)
#define DMA_IFCR_CHTIF5(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF5_SHIFT)) & DMA_IFCR_CHTIF5_MASK)

#define DMA_IFCR_CTCIF5_SHIFT                   (17)
#define DMA_IFCR_CTCIF5_MASK                    (0x1U << DMA_IFCR_CTCIF5_SHIFT)
#define DMA_IFCR_CTCIF5(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF5_SHIFT)) & DMA_IFCR_CTCIF5_MASK)

#define DMA_IFCR_CGIF5_SHIFT                    (16)
#define DMA_IFCR_CGIF5_MASK                     (0x1U << DMA_IFCR_CGIF5_SHIFT)
#define DMA_IFCR_CGIF5(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF5_SHIFT)) & DMA_IFCR_CGIF5_MASK)

#define DMA_IFCR_CTEIF4_SHIFT                   (15)
#define DMA_IFCR_CTEIF4_MASK                    (0x1U << DMA_IFCR_CTEIF4_SHIFT)
#define DMA_IFCR_CTEIF4(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF4_SHIFT)) & DMA_IFCR_CTEIF4_MASK)

#define DMA_IFCR_CHTIF4_SHIFT                   (14)
#define DMA_IFCR_CHTIF4_MASK                    (0x1U << DMA_IFCR_CHTIF4_SHIFT)
#define DMA_IFCR_CHTIF4(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF4_SHIFT)) & DMA_IFCR_CHTIF4_MASK)

#define DMA_IFCR_CTCIF4_SHIFT                   (13)
#define DMA_IFCR_CTCIF4_MASK                    (0x1U << DMA_IFCR_CTCIF4_SHIFT)
#define DMA_IFCR_CTCIF4(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF4_SHIFT)) & DMA_IFCR_CTCIF4_MASK)

#define DMA_IFCR_CGIF4_SHIFT                    (12)
#define DMA_IFCR_CGIF4_MASK                     (0x1U << DMA_IFCR_CGIF4_SHIFT)
#define DMA_IFCR_CGIF4(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF4_SHIFT)) & DMA_IFCR_CGIF4_MASK)

#define DMA_IFCR_CTEIF3_SHIFT                   (11)
#define DMA_IFCR_CTEIF3_MASK                    (0x1U << DMA_IFCR_CTEIF3_SHIFT)
#define DMA_IFCR_CTEIF3(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF3_SHIFT)) & DMA_IFCR_CTEIF3_MASK)

#define DMA_IFCR_CHTIF3_SHIFT                   (10)
#define DMA_IFCR_CHTIF3_MASK                    (0x1U << DMA_IFCR_CHTIF3_SHIFT)
#define DMA_IFCR_CHTIF3(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF3_SHIFT)) & DMA_IFCR_CHTIF3_MASK)

#define DMA_IFCR_CTCIF3_SHIFT                   (9)
#define DMA_IFCR_CTCIF3_MASK                    (0x1U << DMA_IFCR_CTCIF3_SHIFT)
#define DMA_IFCR_CTCIF3(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF3_SHIFT)) & DMA_IFCR_CTCIF3_MASK)

#define DMA_IFCR_CGIF3_SHIFT                    (8)
#define DMA_IFCR_CGIF3_MASK                     (0x1U << DMA_IFCR_CGIF3_SHIFT)
#define DMA_IFCR_CGIF3(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF3_SHIFT)) & DMA_IFCR_CGIF3_MASK)

#define DMA_IFCR_CTEIF2_SHIFT                   (7)
#define DMA_IFCR_CTEIF2_MASK                    (0x1U << DMA_IFCR_CTEIF2_SHIFT)
#define DMA_IFCR_CTEIF2(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF2_SHIFT)) & DMA_IFCR_CTEIF2_MASK)

#define DMA_IFCR_CHTIF2_SHIFT                   (6)
#define DMA_IFCR_CHTIF2_MASK                    (0x1U << DMA_IFCR_CHTIF2_SHIFT)
#define DMA_IFCR_CHTIF2(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF2_SHIFT)) & DMA_IFCR_CHTIF2_MASK)

#define DMA_IFCR_CTCIF2_SHIFT                   (5)
#define DMA_IFCR_CTCIF2_MASK                    (0x1U << DMA_IFCR_CTCIF2_SHIFT)
#define DMA_IFCR_CTCIF2(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF2_SHIFT)) & DMA_IFCR_CTCIF2_MASK)

#define DMA_IFCR_CGIF2_SHIFT                    (4)
#define DMA_IFCR_CGIF2_MASK                     (0x1U << DMA_IFCR_CGIF2_SHIFT)
#define DMA_IFCR_CGIF2(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF2_SHIFT)) & DMA_IFCR_CGIF2_MASK)

#define DMA_IFCR_CTEIF1_SHIFT                   (3)
#define DMA_IFCR_CTEIF1_MASK                    (0x1U << DMA_IFCR_CTEIF1_SHIFT)
#define DMA_IFCR_CTEIF1(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTEIF1_SHIFT)) & DMA_IFCR_CTEIF1_MASK)

#define DMA_IFCR_CHTIF1_SHIFT                   (2)
#define DMA_IFCR_CHTIF1_MASK                    (0x1U << DMA_IFCR_CHTIF1_SHIFT)
#define DMA_IFCR_CHTIF1(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CHTIF1_SHIFT)) & DMA_IFCR_CHTIF1_MASK)

#define DMA_IFCR_CTCIF1_SHIFT                   (1)
#define DMA_IFCR_CTCIF1_MASK                    (0x1U << DMA_IFCR_CTCIF1_SHIFT)
#define DMA_IFCR_CTCIF1(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CTCIF1_SHIFT)) & DMA_IFCR_CTCIF1_MASK)

#define DMA_IFCR_CGIF1_SHIFT                    (0)
#define DMA_IFCR_CGIF1_MASK                     (0x1U << DMA_IFCR_CGIF1_SHIFT)
#define DMA_IFCR_CGIF1(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_IFCR_CGIF1_SHIFT)) & DMA_IFCR_CGIF1_MASK)

/*!
 * @brief DMA_CCR Register Bit Definition
 */

#define DMA_CCR_BURSTEN_SHIFT                   (16)
#define DMA_CCR_BURSTEN_MASK                    (0x1U << DMA_CCR_BURSTEN_SHIFT)
#define DMA_CCR_BURSTEN(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CCR_BURSTEN_SHIFT)) & DMA_CCR_BURSTEN_MASK)

#define DMA_CCR_ARE_SHIFT                       (15)
#define DMA_CCR_ARE_MASK                        (0x1U << DMA_CCR_ARE_SHIFT)
#define DMA_CCR_ARE(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CCR_ARE_SHIFT)) & DMA_CCR_ARE_MASK)

#define DMA_CCR_MEM2MEM_SHIFT                   (14)
#define DMA_CCR_MEM2MEM_MASK                    (0x1U << DMA_CCR_MEM2MEM_SHIFT)
#define DMA_CCR_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CCR_MEM2MEM_SHIFT)) & DMA_CCR_MEM2MEM_MASK)

#define DMA_CCR_PL_SHIFT                        (12)
#define DMA_CCR_PL_MASK                         (0x3U << DMA_CCR_PL_SHIFT)
#define DMA_CCR_PL(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CCR_PL_SHIFT)) & DMA_CCR_PL_MASK)

#define DMA_CCR_MSIZE_SHIFT                     (10)
#define DMA_CCR_MSIZE_MASK                      (0x3U << DMA_CCR_MSIZE_SHIFT)
#define DMA_CCR_MSIZE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CCR_MSIZE_SHIFT)) & DMA_CCR_MSIZE_MASK)

#define DMA_CCR_PSIZE_SHIFT                     (8)
#define DMA_CCR_PSIZE_MASK                      (0x3U << DMA_CCR_PSIZE_SHIFT)
#define DMA_CCR_PSIZE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CCR_PSIZE_SHIFT)) & DMA_CCR_PSIZE_MASK)

#define DMA_CCR_MINC_SHIFT                      (7)
#define DMA_CCR_MINC_MASK                       (0x1U << DMA_CCR_MINC_SHIFT)
#define DMA_CCR_MINC(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_MINC_SHIFT)) & DMA_CCR_MINC_MASK)

#define DMA_CCR_PINC_SHIFT                      (6)
#define DMA_CCR_PINC_MASK                       (0x1U << DMA_CCR_PINC_SHIFT)
#define DMA_CCR_PINC(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_PINC_SHIFT)) & DMA_CCR_PINC_MASK)

#define DMA_CCR_CIRC_SHIFT                      (5)
#define DMA_CCR_CIRC_MASK                       (0x1U << DMA_CCR_CIRC_SHIFT)
#define DMA_CCR_CIRC(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_CIRC_SHIFT)) & DMA_CCR_CIRC_MASK)

#define DMA_CCR_DIR_SHIFT                       (4)
#define DMA_CCR_DIR_MASK                        (0x1U << DMA_CCR_DIR_SHIFT)
#define DMA_CCR_DIR(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CCR_DIR_SHIFT)) & DMA_CCR_DIR_MASK)

#define DMA_CCR_TEIE_SHIFT                      (3)
#define DMA_CCR_TEIE_MASK                       (0x1U << DMA_CCR_TEIE_SHIFT)
#define DMA_CCR_TEIE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_TEIE_SHIFT)) & DMA_CCR_TEIE_MASK)

#define DMA_CCR_HTIE_SHIFT                      (2)
#define DMA_CCR_HTIE_MASK                       (0x1U << DMA_CCR_HTIE_SHIFT)
#define DMA_CCR_HTIE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_HTIE_SHIFT)) & DMA_CCR_HTIE_MASK)

#define DMA_CCR_TCIE_SHIFT                      (1)
#define DMA_CCR_TCIE_MASK                       (0x1U << DMA_CCR_TCIE_SHIFT)
#define DMA_CCR_TCIE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CCR_TCIE_SHIFT)) & DMA_CCR_TCIE_MASK)

#define DMA_CCR_EN_SHIFT                        (0)
#define DMA_CCR_EN_MASK                         (0x1U << DMA_CCR_EN_SHIFT)
#define DMA_CCR_EN(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CCR_EN_SHIFT)) & DMA_CCR_EN_MASK)

/*!
 * @brief DMA_CNDTR Register Bit Definition
 */

#define DMA_CNDTR_NDT_SHIFT                     (0)
#define DMA_CNDTR_NDT_MASK                      (0xFFFFU << DMA_CNDTR_NDT_SHIFT)
#define DMA_CNDTR_NDT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CNDTR_NDT_SHIFT)) & DMA_CNDTR_NDT_MASK)

/*!
 * @brief DMA_CPAR Register Bit Definition
 */

#define DMA_CPAR_PA_SHIFT                       (0)
#define DMA_CPAR_PA_MASK                        (0xFFFFFFFFU << DMA_CPAR_PA_SHIFT)
#define DMA_CPAR_PA(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CPAR_PA_SHIFT)) & DMA_CPAR_PA_MASK)

/*!
 * @brief DMA_CMAR Register Bit Definition
 */

#define DMA_CMAR_MA_SHIFT                       (0)
#define DMA_CMAR_MA_MASK                        (0xFFFFFFFFU << DMA_CMAR_MA_SHIFT)
#define DMA_CMAR_MA(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CMAR_MA_SHIFT)) & DMA_CMAR_MA_MASK)

/*!
 * @}
 */ /* end of group DMA_Register_Masks */
/******************************************************************************
 *DMA Instance
*******************************************************************************/

#define DMA1                  ((DMA_Type*)DMA_BASE)

/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */



/*!
 * @addtogroup EXTI_Peripheral_Access_Layer EXTI Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * EXTI Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t IMR;                                                          ///< Interrupt mask register                      offset: 0x00
    __IO uint32_t EMR;                                                          ///< Event mask register                          offset: 0x04
    __IO uint32_t RTSR;                                                         ///< Rising edge trigger selection register       offset: 0x08
    __IO uint32_t FTSR;                                                         ///< Falling edge trigger selection register      offset: 0x0C
    __IO uint32_t SWIER;                                                        ///< Software interrupt event register            offset: 0x10
    __IO uint32_t PR;                                                           ///< Pending register                             offset: 0x14
} EXTI_Type;

/*******************************************************************************
 * EXTI Type
 ******************************************************************************/

/*!
 * @addtogroup EXTI_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief EXTI_IMR Register Bit Definition
 */

#define EXTI_IMR_IMRX_SHIFT                     (0)
#define EXTI_IMR_IMRX_MASK                      (0xFFFFFFFFU << EXTI_IMR_IMRX_SHIFT)
#define EXTI_IMR_IMRX(x)                        (((uint32_t)(((uint32_t)(x)) << EXTI_IMR_IMRX_SHIFT)) & EXTI_IMR_IMRX_MASK)

/*!
 * @brief EXTI_EMR Register Bit Definition
 */

#define EXTI_EMR_EMRX_SHIFT                     (0)
#define EXTI_EMR_EMRX_MASK                      (0xFFFFFFFFU << EXTI_EMR_EMRX_SHIFT)
#define EXTI_EMR_EMRX(x)                        (((uint32_t)(((uint32_t)(x)) << EXTI_EMR_EMRX_SHIFT)) & EXTI_EMR_EMRX_MASK)

/*!
 * @brief EXTI_RTSR Register Bit Definition
 */

#define EXTI_RTSR_TRX_SHIFT                     (0)
#define EXTI_RTSR_TRX_MASK                      (0xFFFFFFFFU << EXTI_RTSR_TRX_SHIFT)
#define EXTI_RTSR_TRX(x)                        (((uint32_t)(((uint32_t)(x)) << EXTI_RTSR_TRX_SHIFT)) & EXTI_RTSR_TRX_MASK)

/*!
 * @brief EXTI_FTSR Register Bit Definition
 */

#define EXTI_FTSR_TRX_SHIFT                     (0)
#define EXTI_FTSR_TRX_MASK                      (0xFFFFFFFFU << EXTI_FTSR_TRX_SHIFT)
#define EXTI_FTSR_TRX(x)                        (((uint32_t)(((uint32_t)(x)) << EXTI_FTSR_TRX_SHIFT)) & EXTI_FTSR_TRX_MASK)

/*!
 * @brief EXTI_SWIER Register Bit Definition
 */

#define EXTI_SWIER_SWIERX_SHIFT                 (0)
#define EXTI_SWIER_SWIERX_MASK                  (0xFFFFFFFFU << EXTI_SWIER_SWIERX_SHIFT)
#define EXTI_SWIER_SWIERX(x)                    (((uint32_t)(((uint32_t)(x)) << EXTI_SWIER_SWIERX_SHIFT)) & EXTI_SWIER_SWIERX_MASK)

/*!
 * @brief EXTI_PR Register Bit Definition
 */

#define EXTI_PR_PRX_SHIFT                       (0)
#define EXTI_PR_PRX_MASK                        (0xFFFFFFFFU << EXTI_PR_PRX_SHIFT)
#define EXTI_PR_PRX(x)                          (((uint32_t)(((uint32_t)(x)) << EXTI_PR_PRX_SHIFT)) & EXTI_PR_PRX_MASK)

/*!
 * @}
 */ /* end of group EXTI_Register_Masks */
/******************************************************************************
 *EXTI Instance
*******************************************************************************/

#define EXTI                 ((EXTI_Type*)EXTI_BASE)

/*!
 * @}
 */ /* end of group EXTI_Peripheral_Access_Layer */



/*!
 * @addtogroup FLASH_Peripheral_Access_Layer FLASH Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * FLASH Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t ACR;                                                          ///< Flash access control register                offset: 0x00
    __IO uint32_t KEYR;                                                         ///< FPEC key register                            offset: 0x04
    __IO uint32_t OPTKEYR;                                                      ///< Flash OPTKEY register                        offset: 0x08
    __IO uint32_t SR;                                                           ///< Flash status register                        offset: 0x0C
    __IO uint32_t CR;                                                           ///< Flash control register                       offset: 0x10
    __IO uint32_t AR;                                                           ///< Flash address register                       offset: 0x14
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t OBR;                                                          ///< Option byte register                         offset: 0x1C
    __IO uint32_t WRPR;                                                         ///< Write protection register                    offset: 0x20
} FLASH_Type;

/*******************************************************************************
 * FLASH Type
 ******************************************************************************/

/*!
 * @addtogroup FLASH_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief FLASH_ACR Register Bit Definition
 */

#define FLASH_ACR_PRFTBS_SHIFT                  (5)
#define FLASH_ACR_PRFTBS_MASK                   (0x1U << FLASH_ACR_PRFTBS_SHIFT)
#define FLASH_ACR_PRFTBS(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_ACR_PRFTBS_SHIFT)) & FLASH_ACR_PRFTBS_MASK)

#define FLASH_ACR_PRFTBE_SHIFT                  (4)
#define FLASH_ACR_PRFTBE_MASK                   (0x1U << FLASH_ACR_PRFTBE_SHIFT)
#define FLASH_ACR_PRFTBE(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_ACR_PRFTBE_SHIFT)) & FLASH_ACR_PRFTBE_MASK)

#define FLASH_ACR_LATENCY_SHIFT                 (0)
#define FLASH_ACR_LATENCY_MASK                  (0x7U << FLASH_ACR_LATENCY_SHIFT)
#define FLASH_ACR_LATENCY(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_ACR_LATENCY_SHIFT)) & FLASH_ACR_LATENCY_MASK)

/*!
 * @brief FLASH_KEYR Register Bit Definition
 */

#define FLASH_KEYR_FKEYR_SHIFT                  (0)
#define FLASH_KEYR_FKEYR_MASK                   (0xFFFFFFFFU << FLASH_KEYR_FKEYR_SHIFT)
#define FLASH_KEYR_FKEYR(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_KEYR_FKEYR_SHIFT)) & FLASH_KEYR_FKEYR_MASK)

/*!
 * @brief FLASH_OPTKEYR Register Bit Definition
 */

#define FLASH_OPTKEYR_OPTKEYR_SHIFT             (0)
#define FLASH_OPTKEYR_OPTKEYR_MASK              (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_SHIFT)
#define FLASH_OPTKEYR_OPTKEYR(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_OPTKEYR_OPTKEYR_SHIFT)) & FLASH_OPTKEYR_OPTKEYR_MASK)

/*!
 * @brief FLASH_SR Register Bit Definition
 */

#define FLASH_SR_EOP_SHIFT                      (5)
#define FLASH_SR_EOP_MASK                       (0x1U << FLASH_SR_EOP_SHIFT)
#define FLASH_SR_EOP(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_SR_EOP_SHIFT)) & FLASH_SR_EOP_MASK)

#define FLASH_SR_WRPRTERR_SHIFT                 (4)
#define FLASH_SR_WRPRTERR_MASK                  (0x1U << FLASH_SR_WRPRTERR_SHIFT)
#define FLASH_SR_WRPRTERR(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_SR_WRPRTERR_SHIFT)) & FLASH_SR_WRPRTERR_MASK)

#define FLASH_SR_PGERR_SHIFT                    (2)
#define FLASH_SR_PGERR_MASK                     (0x1U << FLASH_SR_PGERR_SHIFT)
#define FLASH_SR_PGERR(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_SR_PGERR_SHIFT)) & FLASH_SR_PGERR_MASK)

#define FLASH_SR_BSY_SHIFT                      (0)
#define FLASH_SR_BSY_MASK                       (0x1U << FLASH_SR_BSY_SHIFT)
#define FLASH_SR_BSY(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_SR_BSY_SHIFT)) & FLASH_SR_BSY_MASK)

/*!
 * @brief FLASH_CR Register Bit Definition
 */

#define FLASH_CR_OPTWRE_SHIFT                   (9)
#define FLASH_CR_OPTWRE_MASK                    (0x1U << FLASH_CR_OPTWRE_SHIFT)
#define FLASH_CR_OPTWRE(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_CR_OPTWRE_SHIFT)) & FLASH_CR_OPTWRE_MASK)

#define FLASH_CR_LOCK_SHIFT                     (7)
#define FLASH_CR_LOCK_MASK                      (0x1U << FLASH_CR_LOCK_SHIFT)
#define FLASH_CR_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_CR_LOCK_SHIFT)) & FLASH_CR_LOCK_MASK)

#define FLASH_CR_STRT_SHIFT                     (6)
#define FLASH_CR_STRT_MASK                      (0x1U << FLASH_CR_STRT_SHIFT)
#define FLASH_CR_STRT(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_CR_STRT_SHIFT)) & FLASH_CR_STRT_MASK)

#define FLASH_CR_OPTER_SHIFT                    (5)
#define FLASH_CR_OPTER_MASK                     (0x1U << FLASH_CR_OPTER_SHIFT)
#define FLASH_CR_OPTER(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_CR_OPTER_SHIFT)) & FLASH_CR_OPTER_MASK)

#define FLASH_CR_OPTPG_SHIFT                    (4)
#define FLASH_CR_OPTPG_MASK                     (0x1U << FLASH_CR_OPTPG_SHIFT)
#define FLASH_CR_OPTPG(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_CR_OPTPG_SHIFT)) & FLASH_CR_OPTPG_MASK)

#define FLASH_CR_MER_SHIFT                      (2)
#define FLASH_CR_MER_MASK                       (0x1U << FLASH_CR_MER_SHIFT)
#define FLASH_CR_MER(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_CR_MER_SHIFT)) & FLASH_CR_MER_MASK)

#define FLASH_CR_PER_SHIFT                      (1)
#define FLASH_CR_PER_MASK                       (0x1U << FLASH_CR_PER_SHIFT)
#define FLASH_CR_PER(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_CR_PER_SHIFT)) & FLASH_CR_PER_MASK)

#define FLASH_CR_PG_SHIFT                       (0)
#define FLASH_CR_PG_MASK                        (0x1U << FLASH_CR_PG_SHIFT)
#define FLASH_CR_PG(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_CR_PG_SHIFT)) & FLASH_CR_PG_MASK)

/*!
 * @brief FLASH_AR Register Bit Definition
 */

#define FLASH_AR_FAR_SHIFT                      (0)
#define FLASH_AR_FAR_MASK                       (0xFFFFFFFFU << FLASH_AR_FAR_SHIFT)
#define FLASH_AR_FAR(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_AR_FAR_SHIFT)) & FLASH_AR_FAR_MASK)

/*!
 * @brief FLASH_OBR Register Bit Definition
 */

#define FLASH_OBR_DATA1_SHIFT                   (18)
#define FLASH_OBR_DATA1_MASK                    (0xFFU << FLASH_OBR_DATA1_SHIFT)
#define FLASH_OBR_DATA1(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_DATA1_SHIFT)) & FLASH_OBR_DATA1_MASK)

#define FLASH_OBR_DATA0_SHIFT                   (10)
#define FLASH_OBR_DATA0_MASK                    (0xFFU << FLASH_OBR_DATA0_SHIFT)
#define FLASH_OBR_DATA0(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_DATA0_SHIFT)) & FLASH_OBR_DATA0_MASK)

#define FLASH_OBR_NBOOT1_SHIFT                  (6)
#define FLASH_OBR_NBOOT1_MASK                   (0x1U << FLASH_OBR_NBOOT1_SHIFT)
#define FLASH_OBR_NBOOT1(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_NBOOT1_SHIFT)) & FLASH_OBR_NBOOT1_MASK)

#define FLASH_OBR_NRSTSTDBY_SHIFT               (4)
#define FLASH_OBR_NRSTSTDBY_MASK                (0x1U << FLASH_OBR_NRSTSTDBY_SHIFT)
#define FLASH_OBR_NRSTSTDBY(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_NRSTSTDBY_SHIFT)) & FLASH_OBR_NRSTSTDBY_MASK)

#define FLASH_OBR_NRSTSTOP_SHIFT                (3)
#define FLASH_OBR_NRSTSTOP_MASK                 (0x1U << FLASH_OBR_NRSTSTOP_SHIFT)
#define FLASH_OBR_NRSTSTOP(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_NRSTSTOP_SHIFT)) & FLASH_OBR_NRSTSTOP_MASK)

#define FLASH_OBR_WDGSW_SHIFT                   (2)
#define FLASH_OBR_WDGSW_MASK                    (0x1U << FLASH_OBR_WDGSW_SHIFT)
#define FLASH_OBR_WDGSW(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_WDGSW_SHIFT)) & FLASH_OBR_WDGSW_MASK)

#define FLASH_OBR_OPTERR_SHIFT                  (0)
#define FLASH_OBR_OPTERR_MASK                   (0x1U << FLASH_OBR_OPTERR_SHIFT)
#define FLASH_OBR_OPTERR(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_OBR_OPTERR_SHIFT)) & FLASH_OBR_OPTERR_MASK)

/*!
 * @brief FLASH_WRPR Register Bit Definition
 */

#define FLASH_WRPR_WRP_SHIFT                    (0)
#define FLASH_WRPR_WRP_MASK                     (0xFFFFFFFFU << FLASH_WRPR_WRP_SHIFT)
#define FLASH_WRPR_WRP(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_WRPR_WRP_SHIFT)) & FLASH_WRPR_WRP_MASK)

/*!
 * @}
 */ /* end of group FLASH_Register_Masks */
/******************************************************************************
 *FLASH Instance
*******************************************************************************/

#define FLASH                ((FLASH_Type*)FLASH_BASE)

/*!
 * @}
 */ /* end of group FLASH_Peripheral_Access_Layer */



/*!
 * @addtogroup FLEXCAN_Peripheral_Access_Layer FLEXCAN Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * FLEXCAN Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t MCR;                                                          ///< Module Configuration Register                offset: 0x00
    __IO uint32_t CTRL1;                                                        ///< Control Register 1                           offset: 0x04
    __IO uint32_t TIMER;                                                        ///< Free Running Timer Register                  offset: 0x08
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t RXMGMASK;                                                     ///< Rx Mailboxes Global Mask Register            offset: 0x10
    __IO uint32_t RX14MASK;                                                     ///< Rx 14 Mask Register                          offset: 0x14
    __IO uint32_t RX15MASK;                                                     ///< Rx 15 Mask Register                          offset: 0x18
    __IO uint32_t ECR;                                                          ///< Error Counter Register                       offset: 0x1C
    __IO uint32_t ESR1;                                                         ///< Error and Status Register 1                  offset: 0x20
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t IMASK1;                                                       ///< Interrupt Mask Register 1                    offset: 0x28
    __IO uint32_t Reserved2[1];                                                 ///< Reserved
    __IO uint32_t IFLAG1;                                                       ///< Interrupt Flag Register 1                    offset: 0x30
    __IO uint32_t CTRL2;                                                        ///< Control Register 2                           offset: 0x34
    __IO uint32_t ESR2;                                                         ///< Error and Status Register 2                  offset: 0x38
    __IO uint32_t Reserved3[2];                                                 ///< Reserved
    __IO uint32_t CRCR;                                                         ///< CRC Register                                 offset: 0x44
    __IO uint32_t RXFGMASK;                                                     ///< Rx FIFO Global Mask Register                 offset: 0x48
    __IO uint32_t RXFIR;                                                       ///< FIFO Information Register                    offset: 0x4C
    __IO uint32_t CBT;                                                          ///< CAN Bit Timing Register                      offset: 0x50
    __IO uint32_t Reserved4[11];                                                  ///< Reserved
    struct {
        __IO uint32_t CS ;                                                        ///<  Legacy Message Buffer 0 CS Register       offset: 0x80
        __IO uint32_t ID;                                                         ///<  Legacy Message Buffer 0 ID Register       offset: 0x84
        __IO uint32_t WORD0;                                                      ///<  Legacy Message Buffer 0 WORD0 Register    offset: 0x88
        __IO uint32_t WORD1;                                                      ///<  Legacy Message Buffer 0 WORD1 Register    offset: 0x8C
    } MB[32];
    __IO uint32_t Reserved5[384];                                               ///< Reserved
    __IO uint32_t RXIMRN[32];                                                    ///< Rx Individual Mask Registers (n = 0~31)      offset: 0x880
    __IO uint32_t Reserved6[192];                                               ///< Reserved
    __IO uint32_t FDCTRL;                                                       ///< CAN FD Control Register                      offset: 0xC00
    __IO uint32_t FDCBT;                                                        ///< CAN FD Bit Timing Register                   offset: 0xC04
    __IO uint32_t FDCRC;                                                        ///< CAN FD CRC Register                          offset: 0xC08
    __IO uint32_t ERFCR;                                                        ///< Enhanced Rx FIFO Control Register            offset: 0xC0C
    __IO uint32_t ERFIER;                                                       ///< Enhanced Rx FIFO Interrupt Enable Register   offset: 0xC10
    __IO uint32_t ERFSR;                                                        ///< Enhanced Rx FIFO Status Register             offset: 0xC14
    __IO uint32_t Reserved7[1274];                                              ///< Reserved
    struct {
        __IO uint32_t ERFCS ;                                                   ///<  Enhanced Rx FIFO Buffer 0 CS Register       offset: 0x2000
        __IO uint32_t ERFDID;                                                   ///<  Enhanced Rx FIFO Buffer 0 ID Register       offset: 0x2004
        __IO uint32_t ERFDWORD[16];                                             ///<  Enhanced Rx FIFO Buffer 0 WORD Register     offset: 0x2008
        __IO uint32_t IHOFF;                                                    ///<  Identifier receive filter hit indication    offset: 0x2048
        __IO uint32_t Reserved8;
    }ERFMB[6];
    __IO uint32_t Reserved9[904];                                               ///< Reserved
    __IO uint32_t ERFFEL[2];                                                    ///< Enhanced Rx FIFO Filter Element Registers (n=0 ~ 1)offset: 0x3000
} FLEXCAN_Type;

/*******************************************************************************
 * FLEXCAN Type
 ******************************************************************************/

/*!
 * @addtogroup FLEXCAN_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief FLEXCAN_MCR Register Bit Definition
 */

#define FLEXCAN_MCR_MDIS_SHIFT                  (31)
#define FLEXCAN_MCR_MDIS_MASK                   (0x1U << FLEXCAN_MCR_MDIS_SHIFT)
#define FLEXCAN_MCR_MDIS(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_MDIS_SHIFT)) & FLEXCAN_MCR_MDIS_MASK)

#define FLEXCAN_MCR_FRZ_SHIFT                   (30)
#define FLEXCAN_MCR_FRZ_MASK                    (0x1U << FLEXCAN_MCR_FRZ_SHIFT)
#define FLEXCAN_MCR_FRZ(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_FRZ_SHIFT)) & FLEXCAN_MCR_FRZ_MASK)

#define FLEXCAN_MCR_RFEN_SHIFT                  (29)
#define FLEXCAN_MCR_RFEN_MASK                   (0x1U << FLEXCAN_MCR_RFEN_SHIFT)
#define FLEXCAN_MCR_RFEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_RFEN_SHIFT)) & FLEXCAN_MCR_RFEN_MASK)

#define FLEXCAN_MCR_HALT_SHIFT                  (28)
#define FLEXCAN_MCR_HALT_MASK                   (0x1U << FLEXCAN_MCR_HALT_SHIFT)
#define FLEXCAN_MCR_HALT(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_HALT_SHIFT)) & FLEXCAN_MCR_HALT_MASK)

#define FLEXCAN_MCR_NOTRDY_SHIFT                (27)
#define FLEXCAN_MCR_NOTRDY_MASK                 (0x1U << FLEXCAN_MCR_NOTRDY_SHIFT)
#define FLEXCAN_MCR_NOTRDY(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_NOTRDY_SHIFT)) & FLEXCAN_MCR_NOTRDY_MASK)

#define FLEXCAN_MCR_SOFTRST_SHIFT               (25)
#define FLEXCAN_MCR_SOFTRST_MASK                (0x1U << FLEXCAN_MCR_SOFTRST_SHIFT)
#define FLEXCAN_MCR_SOFTRST(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_SOFTRST_SHIFT)) & FLEXCAN_MCR_SOFTRST_MASK)

#define FLEXCAN_MCR_FRZACK_SHIFT                (24)
#define FLEXCAN_MCR_FRZACK_MASK                 (0x1U << FLEXCAN_MCR_FRZACK_SHIFT)
#define FLEXCAN_MCR_FRZACK(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_FRZACK_SHIFT)) & FLEXCAN_MCR_FRZACK_MASK)

#define FLEXCAN_MCR_SUPV_SHIFT                  (23)
#define FLEXCAN_MCR_SUPV_MASK                   (0x1U << FLEXCAN_MCR_SUPV_SHIFT)
#define FLEXCAN_MCR_SUPV(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_SUPV_SHIFT)) & FLEXCAN_MCR_SUPV_MASK)

#define FLEXCAN_MCR_SLFWAK_SHIFT                (22)
#define FLEXCAN_MCR_SLFWAK_MASK                 (0x01U << FLEXCAN_MCR_SLFWAK_SHIFT)
#define FLEXCAN_MCR_SLFWAK(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_SLFWAK_SHIFT)) & FLEXCAN_MCR_SLFWAK_MASK)

#define FLEXCAN_MCR_WRNEN_SHIFT                 (21)
#define FLEXCAN_MCR_WRNEN_MASK                  (0x1U << FLEXCAN_MCR_WRNEN_SHIFT)
#define FLEXCAN_MCR_WRNEN(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_WRNEN_SHIFT)) & FLEXCAN_MCR_WRNEN_MASK)

#define FLEXCAN_MCR_LPMACK_SHIFT                (20)
#define FLEXCAN_MCR_LPMACK_MASK                 (0x1U << FLEXCAN_MCR_LPMACK_SHIFT)
#define FLEXCAN_MCR_LPMACK(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_LPMACK_SHIFT)) & FLEXCAN_MCR_LPMACK_MASK)

#define FLEXCAN_MCR_WAKSRC_SHIFT                (19)
#define FLEXCAN_MCR_WAKSRC_MASK                 (0x01U << FLEXCAN_MCR_WAKSRC_SHIFT)
#define FLEXCAN_MCR_WAKSRC(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_WAKSRC_SHIFT)) & FLEXCAN_MCR_WAKSRC_MASK)

#define FLEXCAN_MCR_SRXDIS_SHIFT                (17)
#define FLEXCAN_MCR_SRXDIS_MASK                 (0x1U << FLEXCAN_MCR_SRXDIS_SHIFT)
#define FLEXCAN_MCR_SRXDIS(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_SRXDIS_SHIFT)) & FLEXCAN_MCR_SRXDIS_MASK)

#define FLEXCAN_MCR_IRMQ_SHIFT                  (16)
#define FLEXCAN_MCR_IRMQ_MASK                   (0x1U << FLEXCAN_MCR_IRMQ_SHIFT)
#define FLEXCAN_MCR_IRMQ(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_IRMQ_SHIFT)) & FLEXCAN_MCR_IRMQ_MASK)

#define FLEXCAN_MCR_DMA_SHIFT                   (15)
#define FLEXCAN_MCR_DMA_MASK                    (0x1U << FLEXCAN_MCR_DMA_SHIFT)
#define FLEXCAN_MCR_DMA(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_DMA_SHIFT)) & FLEXCAN_MCR_DMA_MASK)

#define FLEXCAN_MCR_LPRIOEN_SHIFT               (13)
#define FLEXCAN_MCR_LPRIOEN_MASK                (0x1U << FLEXCAN_MCR_LPRIOEN_SHIFT)
#define FLEXCAN_MCR_LPRIOEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_LPRIOEN_SHIFT)) & FLEXCAN_MCR_LPRIOEN_MASK)

#define FLEXCAN_MCR_AEN_SHIFT                   (12)
#define FLEXCAN_MCR_AEN_MASK                    (0x1U << FLEXCAN_MCR_AEN_SHIFT)
#define FLEXCAN_MCR_AEN(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_AEN_SHIFT)) & FLEXCAN_MCR_AEN_MASK)

#define FLEXCAN_MCR_FDEN_SHIFT                  (11)
#define FLEXCAN_MCR_FDEN_MASK                   (0x1U << FLEXCAN_MCR_FDEN_SHIFT)
#define FLEXCAN_MCR_FDEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_FDEN_SHIFT)) & FLEXCAN_MCR_FDEN_MASK)

#define FLEXCAN_MCR_IDAM_SHIFT                  (8)
#define FLEXCAN_MCR_IDAM_MASK                   (0x3U << FLEXCAN_MCR_IDAM_SHIFT)
#define FLEXCAN_MCR_IDAM(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_IDAM_SHIFT)) & FLEXCAN_MCR_IDAM_MASK)

#define FLEXCAN_MCR_MAXMB_SHIFT                 (0)
#define FLEXCAN_MCR_MAXMB_MASK                  (0x7FU << FLEXCAN_MCR_MAXMB_SHIFT)
#define FLEXCAN_MCR_MAXMB(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_MCR_MAXMB_SHIFT)) & FLEXCAN_MCR_MAXMB_MASK)

/*!
 * @brief FLEXCAN_CTRL1 Register Bit Definition
 */

#define FLEXCAN_CTRL1_PRESDIV_SHIFT             (24)
#define FLEXCAN_CTRL1_PRESDIV_MASK              (0xFFU << FLEXCAN_CTRL1_PRESDIV_SHIFT)
#define FLEXCAN_CTRL1_PRESDIV(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_PRESDIV_SHIFT)) & FLEXCAN_CTRL1_PRESDIV_MASK)

#define FLEXCAN_CTRL1_RJW_SHIFT                 (22)
#define FLEXCAN_CTRL1_RJW_MASK                  (0x3U << FLEXCAN_CTRL1_RJW_SHIFT)
#define FLEXCAN_CTRL1_RJW(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_RJW_SHIFT)) & FLEXCAN_CTRL1_RJW_MASK)

#define FLEXCAN_CTRL1_PSEG1_SHIFT               (19)
#define FLEXCAN_CTRL1_PSEG1_MASK                (0x7U << FLEXCAN_CTRL1_PSEG1_SHIFT)
#define FLEXCAN_CTRL1_PSEG1(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_PSEG1_SHIFT)) & FLEXCAN_CTRL1_PSEG1_MASK)

#define FLEXCAN_CTRL1_PSEG2_SHIFT               (16)
#define FLEXCAN_CTRL1_PSEG2_MASK                (0x7U << FLEXCAN_CTRL1_PSEG2_SHIFT)
#define FLEXCAN_CTRL1_PSEG2(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_PSEG2_SHIFT)) & FLEXCAN_CTRL1_PSEG2_MASK)

#define FLEXCAN_CTRL1_BOFFMSK_SHIFT             (15)
#define FLEXCAN_CTRL1_BOFFMSK_MASK              (0x1U << FLEXCAN_CTRL1_BOFFMSK_SHIFT)
#define FLEXCAN_CTRL1_BOFFMSK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_BOFFMSK_SHIFT)) & FLEXCAN_CTRL1_BOFFMSK_MASK)

#define FLEXCAN_CTRL1_ERRMSK_SHIFT              (14)
#define FLEXCAN_CTRL1_ERRMSK_MASK               (0x1U << FLEXCAN_CTRL1_ERRMSK_SHIFT)
#define FLEXCAN_CTRL1_ERRMSK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_ERRMSK_SHIFT)) & FLEXCAN_CTRL1_ERRMSK_MASK)

#define FLEXCAN_CTRL1_CLKSRC_SHIFT              (13)
#define FLEXCAN_CTRL1_CLKSRC_MASK               (0x1U << FLEXCAN_CTRL1_CLKSRC_SHIFT)
#define FLEXCAN_CTRL1_CLKSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_CLKSRC_SHIFT)) & FLEXCAN_CTRL1_CLKSRC_MASK)

#define FLEXCAN_CTRL1_LPB_SHIFT                 (12)
#define FLEXCAN_CTRL1_LPB_MASK                  (0x1U << FLEXCAN_CTRL1_LPB_SHIFT)
#define FLEXCAN_CTRL1_LPB(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_LPB_SHIFT)) & FLEXCAN_CTRL1_LPB_MASK)

#define FLEXCAN_CTRL1_TWRNMSK_SHIFT             (11)
#define FLEXCAN_CTRL1_TWRNMSK_MASK              (0x1U << FLEXCAN_CTRL1_TWRNMSK_SHIFT)
#define FLEXCAN_CTRL1_TWRNMSK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_TWRNMSK_SHIFT)) & FLEXCAN_CTRL1_TWRNMSK_MASK)

#define FLEXCAN_CTRL1_RWRNMSK_SHIFT             (10)
#define FLEXCAN_CTRL1_RWRNMSK_MASK              (0x1U << FLEXCAN_CTRL1_RWRNMSK_SHIFT)
#define FLEXCAN_CTRL1_RWRNMSK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_RWRNMSK_SHIFT)) & FLEXCAN_CTRL1_RWRNMSK_MASK)

#define FLEXCAN_CTRL1_SMP_SHIFT                 (7)
#define FLEXCAN_CTRL1_SMP_MASK                  (0x1U << FLEXCAN_CTRL1_SMP_SHIFT)
#define FLEXCAN_CTRL1_SMP(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_SMP_SHIFT)) & FLEXCAN_CTRL1_SMP_MASK)

#define FLEXCAN_CTRL1_BOFFREC_SHIFT             (6)
#define FLEXCAN_CTRL1_BOFFREC_MASK              (0x1U << FLEXCAN_CTRL1_BOFFREC_SHIFT)
#define FLEXCAN_CTRL1_BOFFREC(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_BOFFREC_SHIFT)) & FLEXCAN_CTRL1_BOFFREC_MASK)

#define FLEXCAN_CTRL1_TSYN_SHIFT                (5)
#define FLEXCAN_CTRL1_TSYN_MASK                 (0x1U << FLEXCAN_CTRL1_TSYN_SHIFT)
#define FLEXCAN_CTRL1_TSYN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_TSYN_SHIFT)) & FLEXCAN_CTRL1_TSYN_MASK)

#define FLEXCAN_CTRL1_LBUF_SHIFT                (4)
#define FLEXCAN_CTRL1_LBUF_MASK                 (0x1U << FLEXCAN_CTRL1_LBUF_SHIFT)
#define FLEXCAN_CTRL1_LBUF(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_LBUF_SHIFT)) & FLEXCAN_CTRL1_LBUF_MASK)

#define FLEXCAN_CTRL1_LOM_SHIFT                 (3)
#define FLEXCAN_CTRL1_LOM_MASK                  (0x1U << FLEXCAN_CTRL1_LOM_SHIFT)
#define FLEXCAN_CTRL1_LOM(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_LOM_SHIFT)) & FLEXCAN_CTRL1_LOM_MASK)

#define FLEXCAN_CTRL1_PROPSEG_SHIFT             (0)
#define FLEXCAN_CTRL1_PROPSEG_MASK              (0x7U << FLEXCAN_CTRL1_PROPSEG_SHIFT)
#define FLEXCAN_CTRL1_PROPSEG(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL1_PROPSEG_SHIFT)) & FLEXCAN_CTRL1_PROPSEG_MASK)

/*!
 * @brief FLEXCAN_TIMER Register Bit Definition
 */

#define FLEXCAN_TIMER_TIMER_SHIFT               (0)
#define FLEXCAN_TIMER_TIMER_MASK                (0xFFFFU << FLEXCAN_TIMER_TIMER_SHIFT)
#define FLEXCAN_TIMER_TIMER(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_TIMER_TIMER_SHIFT)) & FLEXCAN_TIMER_TIMER_MASK)

/*!
 * @brief FLEXCAN_RXMGMASK Register Bit Definition
 */

#define FLEXCAN_RXMGMASK_MG_SHIFT               (0)
#define FLEXCAN_RXMGMASK_MG_MASK                (0xFFFFFFFFU << FLEXCAN_RXMGMASK_MG_SHIFT)
#define FLEXCAN_RXMGMASK_MG(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RXMGMASK_MG_SHIFT)) & FLEXCAN_RXMGMASK_MG_MASK)

/*!
 * @brief FLEXCAN_RX14MASK Register Bit Definition
 */

#define FLEXCAN_RX14MASK_RX14M_SHIFT            (0)
#define FLEXCAN_RX14MASK_RX14M_MASK             (0xFFFFFFFFU << FLEXCAN_RX14MASK_RX14M_SHIFT)
#define FLEXCAN_RX14MASK_RX14M(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RX14MASK_RX14M_SHIFT)) & FLEXCAN_RX14MASK_RX14M_MASK)

/*!
 * @brief FLEXCAN_RX15MASK Register Bit Definition
 */

#define FLEXCAN_RX15MASK_RX15M_SHIFT            (0)
#define FLEXCAN_RX15MASK_RX15M_MASK             (0xFFFFFFFFU << FLEXCAN_RX15MASK_RX15M_SHIFT)
#define FLEXCAN_RX15MASK_RX15M(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RX15MASK_RX15M_SHIFT)) & FLEXCAN_RX15MASK_RX15M_MASK)

/*!
 * @brief FLEXCAN_ECR Register Bit Definition
 */

#define FLEXCAN_ECR_RXERRCNTFAST_SHIFT          (24)
#define FLEXCAN_ECR_RXERRCNTFAST_MASK           (0xFFU << FLEXCAN_ECR_RXERRCNTFAST_SHIFT)
#define FLEXCAN_ECR_RXERRCNTFAST(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ECR_RXERRCNTFAST_SHIFT)) & FLEXCAN_ECR_RXERRCNTFAST_MASK)

#define FLEXCAN_ECR_TXERRCNTFAST_SHIFT          (16)
#define FLEXCAN_ECR_TXERRCNTFAST_MASK           (0xFFU << FLEXCAN_ECR_TXERRCNTFAST_SHIFT)
#define FLEXCAN_ECR_TXERRCNTFAST(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ECR_TXERRCNTFAST_SHIFT)) & FLEXCAN_ECR_TXERRCNTFAST_MASK)

#define FLEXCAN_ECR_RXERRCNT_SHIFT              (8)
#define FLEXCAN_ECR_RXERRCNT_MASK               (0xFFU << FLEXCAN_ECR_RXERRCNT_SHIFT)
#define FLEXCAN_ECR_RXERRCNT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ECR_RXERRCNT_SHIFT)) & FLEXCAN_ECR_RXERRCNT_MASK)

#define FLEXCAN_ECR_TXERRCNT_SHIFT              (0)
#define FLEXCAN_ECR_TXERRCNT_MASK               (0xFFU << FLEXCAN_ECR_TXERRCNT_SHIFT)
#define FLEXCAN_ECR_TXERRCNT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ECR_TXERRCNT_SHIFT)) & FLEXCAN_ECR_TXERRCNT_MASK)

/*!
 * @brief FLEXCAN_ESR1 Register Bit Definition
 */

#define FLEXCAN_ESR1_BIT1ERRFAST_SHIFT          (31)
#define FLEXCAN_ESR1_BIT1ERRFAST_MASK           (0x1U << FLEXCAN_ESR1_BIT1ERRFAST_SHIFT)
#define FLEXCAN_ESR1_BIT1ERRFAST(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BIT1ERRFAST_SHIFT)) & FLEXCAN_ESR1_BIT1ERRFAST_MASK)

#define FLEXCAN_ESR1_BIT0ERRFAST_SHIFT          (30)
#define FLEXCAN_ESR1_BIT0ERRFAST_MASK           (0x1U << FLEXCAN_ESR1_BIT0ERRFAST_SHIFT)
#define FLEXCAN_ESR1_BIT0ERRFAST(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BIT0ERRFAST_SHIFT)) & FLEXCAN_ESR1_BIT0ERRFAST_MASK)

#define FLEXCAN_ESR1_CRCERRFAST_SHIFT           (28)
#define FLEXCAN_ESR1_CRCERRFAST_MASK            (0x1U << FLEXCAN_ESR1_CRCERRFAST_SHIFT)
#define FLEXCAN_ESR1_CRCERRFAST(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_CRCERRFAST_SHIFT)) & FLEXCAN_ESR1_CRCERRFAST_MASK)

#define FLEXCAN_ESR1_FRMERRFAST_SHIFT           (27)
#define FLEXCAN_ESR1_FRMERRFAST_MASK            (0x1U << FLEXCAN_ESR1_FRMERRFAST_SHIFT)
#define FLEXCAN_ESR1_FRMERRFAST(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_FRMERRFAST_SHIFT)) & FLEXCAN_ESR1_FRMERRFAST_MASK)

#define FLEXCAN_ESR1_STFERRFAST_SHIFT           (26)
#define FLEXCAN_ESR1_STFERRFAST_MASK            (0x1U << FLEXCAN_ESR1_STFERRFAST_SHIFT)
#define FLEXCAN_ESR1_STFERRFAST(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_STFERRFAST_SHIFT)) & FLEXCAN_ESR1_STFERRFAST_MASK)

#define FLEXCAN_ESR1_ERROVR_SHIFT               (21)
#define FLEXCAN_ESR1_ERROVR_MASK                (0x1U << FLEXCAN_ESR1_ERROVR_SHIFT)
#define FLEXCAN_ESR1_ERROVR(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_ERROVR_SHIFT)) & FLEXCAN_ESR1_ERROVR_MASK)

#define FLEXCAN_ESR1_ERRINTFAST_SHIFT           (20)
#define FLEXCAN_ESR1_ERRINTFAST_MASK            (0x1U << FLEXCAN_ESR1_ERRINTFAST_SHIFT)
#define FLEXCAN_ESR1_ERRINTFAST(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_ERRINTFAST_SHIFT)) & FLEXCAN_ESR1_ERRINTFAST_MASK)

#define FLEXCAN_ESR1_BOFFDONEINT_SHIFT          (19)
#define FLEXCAN_ESR1_BOFFDONEINT_MASK           (0x1U << FLEXCAN_ESR1_BOFFDONEINT_SHIFT)
#define FLEXCAN_ESR1_BOFFDONEINT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BOFFDONEINT_SHIFT)) & FLEXCAN_ESR1_BOFFDONEINT_MASK)

#define FLEXCAN_ESR1_SYNCH_SHIFT                (18)
#define FLEXCAN_ESR1_SYNCH_MASK                 (0x1U << FLEXCAN_ESR1_SYNCH_SHIFT)
#define FLEXCAN_ESR1_SYNCH(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_SYNCH_SHIFT)) & FLEXCAN_ESR1_SYNCH_MASK)

#define FLEXCAN_ESR1_TWRNINT_SHIFT              (17)
#define FLEXCAN_ESR1_TWRNINT_MASK               (0x1U << FLEXCAN_ESR1_TWRNINT_SHIFT)
#define FLEXCAN_ESR1_TWRNINT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_TWRNINT_SHIFT)) & FLEXCAN_ESR1_TWRNINT_MASK)

#define FLEXCAN_ESR1_RWRNINT_SHIFT              (16)
#define FLEXCAN_ESR1_RWRNINT_MASK               (0x1U << FLEXCAN_ESR1_RWRNINT_SHIFT)
#define FLEXCAN_ESR1_RWRNINT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_RWRNINT_SHIFT)) & FLEXCAN_ESR1_RWRNINT_MASK)

#define FLEXCAN_ESR1_BIT1ERR_SHIFT              (15)
#define FLEXCAN_ESR1_BIT1ERR_MASK               (0x1U << FLEXCAN_ESR1_BIT1ERR_SHIFT)
#define FLEXCAN_ESR1_BIT1ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BIT1ERR_SHIFT)) & FLEXCAN_ESR1_BIT1ERR_MASK)

#define FLEXCAN_ESR1_BIT0ERR_SHIFT              (14)
#define FLEXCAN_ESR1_BIT0ERR_MASK               (0x1U << FLEXCAN_ESR1_BIT0ERR_SHIFT)
#define FLEXCAN_ESR1_BIT0ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BIT0ERR_SHIFT)) & FLEXCAN_ESR1_BIT0ERR_MASK)

#define FLEXCAN_ESR1_ACKERR_SHIFT               (13)
#define FLEXCAN_ESR1_ACKERR_MASK                (0x1U << FLEXCAN_ESR1_ACKERR_SHIFT)
#define FLEXCAN_ESR1_ACKERR(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_ACKERR_SHIFT)) & FLEXCAN_ESR1_ACKERR_MASK)

#define FLEXCAN_ESR1_CRCERR_SHIFT               (12)
#define FLEXCAN_ESR1_CRCERR_MASK                (0x1U << FLEXCAN_ESR1_CRCERR_SHIFT)
#define FLEXCAN_ESR1_CRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_CRCERR_SHIFT)) & FLEXCAN_ESR1_CRCERR_MASK)

#define FLEXCAN_ESR1_FRMERR_SHIFT               (11)
#define FLEXCAN_ESR1_FRMERR_MASK                (0x1U << FLEXCAN_ESR1_FRMERR_SHIFT)
#define FLEXCAN_ESR1_FRMERR(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_FRMERR_SHIFT)) & FLEXCAN_ESR1_FRMERR_MASK)

#define FLEXCAN_ESR1_STFERR_SHIFT               (10)
#define FLEXCAN_ESR1_STFERR_MASK                (0x1U << FLEXCAN_ESR1_STFERR_SHIFT)
#define FLEXCAN_ESR1_STFERR(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_STFERR_SHIFT)) & FLEXCAN_ESR1_STFERR_MASK)

#define FLEXCAN_ESR1_TXWRN_SHIFT                (9)
#define FLEXCAN_ESR1_TXWRN_MASK                 (0x1U << FLEXCAN_ESR1_TXWRN_SHIFT)
#define FLEXCAN_ESR1_TXWRN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_TXWRN_SHIFT)) & FLEXCAN_ESR1_TXWRN_MASK)

#define FLEXCAN_ESR1_RXWRN_SHIFT                (8)
#define FLEXCAN_ESR1_RXWRN_MASK                 (0x1U << FLEXCAN_ESR1_RXWRN_SHIFT)
#define FLEXCAN_ESR1_RXWRN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_RXWRN_SHIFT)) & FLEXCAN_ESR1_RXWRN_MASK)

#define FLEXCAN_ESR1_IDLE_SHIFT                 (7)
#define FLEXCAN_ESR1_IDLE_MASK                  (0x1U << FLEXCAN_ESR1_IDLE_SHIFT)
#define FLEXCAN_ESR1_IDLE(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_IDLE_SHIFT)) & FLEXCAN_ESR1_IDLE_MASK)

#define FLEXCAN_ESR1_TX_SHIFT                   (6)
#define FLEXCAN_ESR1_TX_MASK                    (0x1U << FLEXCAN_ESR1_TX_SHIFT)
#define FLEXCAN_ESR1_TX(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_TX_SHIFT)) & FLEXCAN_ESR1_TX_MASK)

#define FLEXCAN_ESR1_FLTCONF_SHIFT              (4)
#define FLEXCAN_ESR1_FLTCONF_MASK               (0x3U << FLEXCAN_ESR1_FLTCONF_SHIFT)
#define FLEXCAN_ESR1_FLTCONF(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_FLTCONF_SHIFT)) & FLEXCAN_ESR1_FLTCONF_MASK)

#define FLEXCAN_ESR1_RX_SHIFT                   (3)
#define FLEXCAN_ESR1_RX_MASK                    (0x1U << FLEXCAN_ESR1_RX_SHIFT)
#define FLEXCAN_ESR1_RX(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_RX_SHIFT)) & FLEXCAN_ESR1_RX_MASK)

#define FLEXCAN_ESR1_BOFFINT_SHIFT              (2)
#define FLEXCAN_ESR1_BOFFINT_MASK               (0x1U << FLEXCAN_ESR1_BOFFINT_SHIFT)
#define FLEXCAN_ESR1_BOFFINT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_BOFFINT_SHIFT)) & FLEXCAN_ESR1_BOFFINT_MASK)

#define FLEXCAN_ESR1_ERRINT_SHIFT               (1)
#define FLEXCAN_ESR1_ERRINT_MASK                (0x1U << FLEXCAN_ESR1_ERRINT_SHIFT)
#define FLEXCAN_ESR1_ERRINT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR1_ERRINT_SHIFT)) & FLEXCAN_ESR1_ERRINT_MASK)

/*!
 * @brief FLEXCAN_IMASK1 Register Bit Definition
 */

#define FLEXCAN_IMASK1_BUF31TO0M_SHIFT          (16)
#define FLEXCAN_IMASK1_BUF31TO0M_MASK           (0xFFFFU << FLEXCAN_IMASK1_BUF31TO0M_SHIFT)
#define FLEXCAN_IMASK1_BUF31TO0M(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IMASK1_BUF31TO0M_SHIFT)) & FLEXCAN_IMASK1_BUF31TO0M_MASK)

#define FLEXCAN_IMASK1_BUF15TO0M_SHIFT          (0)
#define FLEXCAN_IMASK1_BUF15TO0M_MASK           (0xFFFFU << FLEXCAN_IMASK1_BUF15TO0M_SHIFT)
#define FLEXCAN_IMASK1_BUF15TO0M(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IMASK1_BUF15TO0M_SHIFT)) & FLEXCAN_IMASK1_BUF15TO0M_MASK)

/*!
 * @brief FLEXCAN_IFLAG1 Register Bit Definition
 */

#define FLEXCAN_IFLAG1_BUF31TO8I_SHIFT          (16)
#define FLEXCAN_IFLAG1_BUF31TO8I_MASK           (0xFFFFU << FLEXCAN_IFLAG1_BUF31TO8I_SHIFT)
#define FLEXCAN_IFLAG1_BUF31TO8I(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF31TO8I_SHIFT)) & FLEXCAN_IFLAG1_BUF31TO8I_MASK)

#define FLEXCAN_IFLAG1_BUF15TO8I_SHIFT          (8)
#define FLEXCAN_IFLAG1_BUF15TO8I_MASK           (0xFFU << FLEXCAN_IFLAG1_BUF15TO8I_SHIFT)
#define FLEXCAN_IFLAG1_BUF15TO8I(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF15TO8I_SHIFT)) & FLEXCAN_IFLAG1_BUF15TO8I_MASK)

#define FLEXCAN_IFLAG1_BUF7I_SHIFT              (7)
#define FLEXCAN_IFLAG1_BUF7I_MASK               (0x1U << FLEXCAN_IFLAG1_BUF7I_SHIFT)
#define FLEXCAN_IFLAG1_BUF7I(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF7I_SHIFT)) & FLEXCAN_IFLAG1_BUF7I_MASK)

#define FLEXCAN_IFLAG1_BUF6I_SHIFT              (6)
#define FLEXCAN_IFLAG1_BUF6I_MASK               (0x1U << FLEXCAN_IFLAG1_BUF6I_SHIFT)
#define FLEXCAN_IFLAG1_BUF6I(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF6I_SHIFT)) & FLEXCAN_IFLAG1_BUF6I_MASK)

#define FLEXCAN_IFLAG1_BUF5I_SHIFT              (5)
#define FLEXCAN_IFLAG1_BUF5I_MASK               (0x1U << FLEXCAN_IFLAG1_BUF5I_SHIFT)
#define FLEXCAN_IFLAG1_BUF5I(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF5I_SHIFT)) & FLEXCAN_IFLAG1_BUF5I_MASK)

#define FLEXCAN_IFLAG1_BUF4TO1I_SHIFT           (1)
#define FLEXCAN_IFLAG1_BUF4TO1I_MASK            (0xFU << FLEXCAN_IFLAG1_BUF4TO1I_SHIFT)
#define FLEXCAN_IFLAG1_BUF4TO1I(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF4TO1I_SHIFT)) & FLEXCAN_IFLAG1_BUF4TO1I_MASK)

#define FLEXCAN_IFLAG1_BUF0I_SHIFT              (0)
#define FLEXCAN_IFLAG1_BUF0I_MASK               (0x1U << FLEXCAN_IFLAG1_BUF0I_SHIFT)
#define FLEXCAN_IFLAG1_BUF0I(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_IFLAG1_BUF0I_SHIFT)) & FLEXCAN_IFLAG1_BUF0I_MASK)

/*!
 * @brief FLEXCAN_CTRL2 Register Bit Definition
 */

#define FLEXCAN_CTRL2_ERRMSKFAST_SHIFT          (31)
#define FLEXCAN_CTRL2_ERRMSKFAST_MASK           (0x1U << FLEXCAN_CTRL2_ERRMSKFAST_SHIFT)
#define FLEXCAN_CTRL2_ERRMSKFAST(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_ERRMSKFAST_SHIFT)) & FLEXCAN_CTRL2_ERRMSKFAST_MASK)

#define FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT         (30)
#define FLEXCAN_CTRL2_BOFFDONEMSK_MASK          (0x1U << FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT)
#define FLEXCAN_CTRL2_BOFFDONEMSK(x)            (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT)) & FLEXCAN_CTRL2_BOFFDONEMSK_MASK)

#define FLEXCAN_CTRL2_RFFN_SHIFT                (24)
#define FLEXCAN_CTRL2_RFFN_MASK                 (0xFU << FLEXCAN_CTRL2_RFFN_SHIFT)
#define FLEXCAN_CTRL2_RFFN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_RFFN_SHIFT)) & FLEXCAN_CTRL2_RFFN_MASK)

#define FLEXCAN_CTRL2_TASD_SHIFT                (19)
#define FLEXCAN_CTRL2_TASD_MASK                 (0x1FU << FLEXCAN_CTRL2_TASD_SHIFT)
#define FLEXCAN_CTRL2_TASD(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_TASD_SHIFT)) & FLEXCAN_CTRL2_TASD_MASK)

#define FLEXCAN_CTRL2_MRP_SHIFT                 (18)
#define FLEXCAN_CTRL2_MRP_MASK                  (0x1U << FLEXCAN_CTRL2_MRP_SHIFT)
#define FLEXCAN_CTRL2_MRP(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_MRP_SHIFT)) & FLEXCAN_CTRL2_MRP_MASK)

#define FLEXCAN_CTRL2_RRS_SHIFT                 (17)
#define FLEXCAN_CTRL2_RRS_MASK                  (0x1U << FLEXCAN_CTRL2_RRS_SHIFT)
#define FLEXCAN_CTRL2_RRS(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_RRS_SHIFT)) & FLEXCAN_CTRL2_RRS_MASK)

#define FLEXCAN_CTRL2_EACEN_SHIFT               (16)
#define FLEXCAN_CTRL2_EACEN_MASK                (0x1U << FLEXCAN_CTRL2_EACEN_SHIFT)
#define FLEXCAN_CTRL2_EACEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_EACEN_SHIFT)) & FLEXCAN_CTRL2_EACEN_MASK)

#define FLEXCAN_CTRL2_PREXCEN_SHIFT             (14)
#define FLEXCAN_CTRL2_PREXCEN_MASK              (0x1U << FLEXCAN_CTRL2_PREXCEN_SHIFT)
#define FLEXCAN_CTRL2_PREXCEN(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_PREXCEN_SHIFT)) & FLEXCAN_CTRL2_PREXCEN_MASK)

#define FLEXCAN_CTRL2_ISOCANFDEN_SHIFT          (12)
#define FLEXCAN_CTRL2_ISOCANFDEN_MASK           (0x1U << FLEXCAN_CTRL2_ISOCANFDEN_SHIFT)
#define FLEXCAN_CTRL2_ISOCANFDEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_ISOCANFDEN_SHIFT)) & FLEXCAN_CTRL2_ISOCANFDEN_MASK)

#define FLEXCAN_CTRL2_EDFLTDIS_SHIFT            (11)
#define FLEXCAN_CTRL2_EDFLTDIS_MASK             (0x1U << FLEXCAN_CTRL2_EDFLTDIS_SHIFT)
#define FLEXCAN_CTRL2_EDFLTDIS(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CTRL2_EDFLTDIS_SHIFT)) & FLEXCAN_CTRL2_EDFLTDIS_MASK)

/*!
 * @brief FLEXCAN_ESR2 Register Bit Definition
 */

#define FLEXCAN_ESR2_LPTM_SHIFT                 (16)
#define FLEXCAN_ESR2_LPTM_MASK                  (0x7FU << FLEXCAN_ESR2_LPTM_SHIFT)
#define FLEXCAN_ESR2_LPTM(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR2_LPTM_SHIFT)) & FLEXCAN_ESR2_LPTM_MASK)

#define FLEXCAN_ESR2_VPS_SHIFT                  (14)
#define FLEXCAN_ESR2_VPS_MASK                   (0x1U << FLEXCAN_ESR2_VPS_SHIFT)
#define FLEXCAN_ESR2_VPS(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR2_VPS_SHIFT)) & FLEXCAN_ESR2_VPS_MASK)

#define FLEXCAN_ESR2_IMB_SHIFT                  (13)
#define FLEXCAN_ESR2_IMB_MASK                   (0x1U << FLEXCAN_ESR2_IMB_SHIFT)
#define FLEXCAN_ESR2_IMB(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ESR2_IMB_SHIFT)) & FLEXCAN_ESR2_IMB_MASK)

/*!
 * @brief FLEXCAN_CRCR Register Bit Definition
 */

#define FLEXCAN_CRCR_MBCRC_SHIFT                (16)
#define FLEXCAN_CRCR_MBCRC_MASK                 (0x7FU << FLEXCAN_CRCR_MBCRC_SHIFT)
#define FLEXCAN_CRCR_MBCRC(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CRCR_MBCRC_SHIFT)) & FLEXCAN_CRCR_MBCRC_MASK)

#define FLEXCAN_CRCR_TXCRC_SHIFT                (0)
#define FLEXCAN_CRCR_TXCRC_MASK                 (0x7FFFU << FLEXCAN_CRCR_TXCRC_SHIFT)
#define FLEXCAN_CRCR_TXCRC(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CRCR_TXCRC_SHIFT)) & FLEXCAN_CRCR_TXCRC_MASK)

/*!
 * @brief FLEXCAN_RXFGMASK Register Bit Definition
 */

#define FLEXCAN_RXFGMASK_FGM_SHIFT              (0)
#define FLEXCAN_RXFGMASK_FGM_MASK               (0xFFFFFFFFU << FLEXCAN_RXFGMASK_FGM_SHIFT)
#define FLEXCAN_RXFGMASK_FGM(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RXFGMASK_FGM_SHIFT)) & FLEXCAN_RXFGMASK_FGM_MASK)

/*!
 * @brief FLEXCAN_RXFIR Register Bit Definition
 */

#define FLEXCAN_RXFIR_IDHIT_SHIFT               (0)
#define FLEXCAN_RXFIR_IDHIT_MASK                (0x1FFU << FLEXCAN_RXFIR_IDHIT_SHIFT)
#define FLEXCAN_RXFIR_IDHIT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RXFIR_IDHIT_SHIFT)) & FLEXCAN_RXFIR_IDHIT_MASK)

/*!
 * @brief FLEXCAN_CBT Register Bit Definition
 */

#define FLEXCAN_CBT_BTF_SHIFT                   (31)
#define FLEXCAN_CBT_BTF_MASK                    (0x1U << FLEXCAN_CBT_BTF_SHIFT)
#define FLEXCAN_CBT_BTF(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_BTF_SHIFT)) & FLEXCAN_CBT_BTF_MASK)

#define FLEXCAN_CBT_EPRESDIV_SHIFT              (21)
#define FLEXCAN_CBT_EPRESDIV_MASK               (0x3FFU << FLEXCAN_CBT_EPRESDIV_SHIFT)
#define FLEXCAN_CBT_EPRESDIV(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_EPRESDIV_SHIFT)) & FLEXCAN_CBT_EPRESDIV_MASK)

#define FLEXCAN_CBT_ERJW_SHIFT                  (16)
#define FLEXCAN_CBT_ERJW_MASK                   (0x1FU << FLEXCAN_CBT_ERJW_SHIFT)
#define FLEXCAN_CBT_ERJW(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_ERJW_SHIFT)) & FLEXCAN_CBT_ERJW_MASK)

#define FLEXCAN_CBT_EPROPSEG_SHIFT              (10)
#define FLEXCAN_CBT_EPROPSEG_MASK               (0x3FU << FLEXCAN_CBT_EPROPSEG_SHIFT)
#define FLEXCAN_CBT_EPROPSEG(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_EPROPSEG_SHIFT)) & FLEXCAN_CBT_EPROPSEG_MASK)

#define FLEXCAN_CBT_EPSEG1_SHIFT                (5)
#define FLEXCAN_CBT_EPSEG1_MASK                 (0x1FU << FLEXCAN_CBT_EPSEG1_SHIFT)
#define FLEXCAN_CBT_EPSEG1(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_EPSEG1_SHIFT)) & FLEXCAN_CBT_EPSEG1_MASK)

#define FLEXCAN_CBT_EPSEG2_SHIFT                (0)
#define FLEXCAN_CBT_EPSEG2_MASK                 (0x1FU << FLEXCAN_CBT_EPSEG2_SHIFT)
#define FLEXCAN_CBT_EPSEG2(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CBT_EPSEG2_SHIFT)) & FLEXCAN_CBT_EPSEG2_MASK)

/*!
 * @brief FLEXCAN_CS  Register Bit Definition
 */

#define FLEXCAN_CS_CODE_SHIFT                   (24)
#define FLEXCAN_CS_CODE_MASK                    (0xFU << FLEXCAN_CS_CODE_SHIFT)
#define FLEXCAN_CS_CODE(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_CODE_SHIFT)) & FLEXCAN_CS_CODE_MASK)

#define FLEXCAN_CS_SRR_SHIFT                    (22)
#define FLEXCAN_CS_SRR_MASK                     (0x01U << FLEXCAN_CS_SRR_SHIFT)
#define FLEXCAN_CS_SRR(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_SRR_SHIFT)) & FLEXCAN_CS_SRR_MASK)

#define FLEXCAN_CS_IDE_SHIFT                    (21)
#define FLEXCAN_CS_IDE_MASK                     (0x01U << FLEXCAN_CS_IDE_SHIFT)
#define FLEXCAN_CS_IDE(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_IDE_SHIFT)) & FLEXCAN_CS_IDE_MASK)

#define FLEXCAN_CS_RTR_SHIFT                    (20)
#define FLEXCAN_CS_RTR_MASK                     (0x01U << FLEXCAN_CS_RTR_SHIFT)
#define FLEXCAN_CS_RTR(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_RTR_SHIFT)) & FLEXCAN_CS_RTR_MASK)

#define FLEXCAN_CS_DLC_SHIFT                    (16)
#define FLEXCAN_CS_DLC_MASK                     (0xFU << FLEXCAN_CS_DLC_SHIFT)
#define FLEXCAN_CS_DLC(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_DLC_SHIFT)) & FLEXCAN_CS_DLC_MASK)

#define FLEXCAN_CS_TIMESTAMP_SHIFT              (0)
#define FLEXCAN_CS_TIMESTAMP_MASK               (0xFFFFU << FLEXCAN_CS_TIMESTAMP_SHIFT)
#define FLEXCAN_CS_TIMESTAMP(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_CS_TIMESTAMP_SHIFT)) & FLEXCAN_CS_TIMESTAMP_MASK)

/*!
 * @brief FLEXCAN_ID Register Bit Definition
 */

#define FLEXCAN_ID_PRIO_SHIFT                   (29)
#define FLEXCAN_ID_PRIO_MASK                    (0x7U << FLEXCAN_ID_PRIO_SHIFT)
#define FLEXCAN_ID_PRIO(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ID_PRIO_SHIFT)) & FLEXCAN_ID_PRIO_MASK)

#define FLEXCAN_ID_STD_SHIFT                    (18)
#define FLEXCAN_ID_STD_MASK                     (0x7FFU << FLEXCAN_ID_STD_SHIFT)
#define FLEXCAN_ID_STD(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ID_STD_SHIFT)) & FLEXCAN_ID_STD_MASK)

#define FLEXCAN_ID_EXT_SHIFT                    (0)
#define FLEXCAN_ID_EXT_MASK                     (0x3FFFFU << FLEXCAN_ID_EXT_SHIFT)
#define FLEXCAN_ID_EXT(x)                       (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ID_EXT_SHIFT)) & FLEXCAN_ID_EXT_MASK)

/*!
 * @brief FLEXCAN_WORD0 Register Bit Definition
 */

#define FLEXCAN_WORD0_BYTE0_SHIFT               (24)
#define FLEXCAN_WORD0_BYTE0_MASK                (0xFFU << FLEXCAN_WORD0_BYTE0_SHIFT)
#define FLEXCAN_WORD0_BYTE0(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD0_BYTE0_SHIFT)) & FLEXCAN_WORD0_BYTE0_MASK)

#define FLEXCAN_WORD0_BYTE1_SHIFT               (16)
#define FLEXCAN_WORD0_BYTE1_MASK                (0x3FU << FLEXCAN_WORD0_BYTE1_SHIFT)
#define FLEXCAN_WORD0_BYTE1(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD0_BYTE1_SHIFT)) & FLEXCAN_WORD0_BYTE1_MASK)

#define FLEXCAN_WORD0_BYTE2_SHIFT               (8)
#define FLEXCAN_WORD0_BYTE2_MASK                (0xFFU << FLEXCAN_WORD0_BYTE2_SHIFT)
#define FLEXCAN_WORD0_BYTE2(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD0_BYTE2_SHIFT)) & FLEXCAN_WORD0_BYTE2_MASK)

#define FLEXCAN_WORD0_BYTE3_SHIFT               (0)
#define FLEXCAN_WORD0_BYTE3_MASK                (0xFFU << FLEXCAN_WORD0_BYTE3_SHIFT)
#define FLEXCAN_WORD0_BYTE3(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD0_BYTE3_SHIFT)) & FLEXCAN_WORD0_BYTE3_MASK)

/*!
 * @brief FLEXCAN_WORD1 Register Bit Definition
 */

#define FLEXCAN_WORD1_BYTE4_SHIFT               (24)
#define FLEXCAN_WORD1_BYTE4_MASK                (0xFFU << FLEXCAN_WORD1_BYTE4_SHIFT)
#define FLEXCAN_WORD1_BYTE4(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD1_BYTE4_SHIFT)) & FLEXCAN_WORD1_BYTE4_MASK)

#define FLEXCAN_WORD1_BYTE5_SHIFT               (16)
#define FLEXCAN_WORD1_BYTE5_MASK                (0x3FU << FLEXCAN_WORD1_BYTE5_SHIFT)
#define FLEXCAN_WORD1_BYTE5(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD1_BYTE5_SHIFT)) & FLEXCAN_WORD1_BYTE5_MASK)

#define FLEXCAN_WORD1_BYTE6_SHIFT               (8)
#define FLEXCAN_WORD1_BYTE6_MASK                (0xFFU << FLEXCAN_WORD1_BYTE6_SHIFT)
#define FLEXCAN_WORD1_BYTE6(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD1_BYTE6_SHIFT)) & FLEXCAN_WORD1_BYTE6_MASK)

#define FLEXCAN_WORD1_BYTE7_SHIFT               (0)
#define FLEXCAN_WORD1_BYTE7_MASK                (0xFFU << FLEXCAN_WORD1_BYTE7_SHIFT)
#define FLEXCAN_WORD1_BYTE7(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_WORD1_BYTE7_SHIFT)) & FLEXCAN_WORD1_BYTE7_MASK)

/*!
 * @brief FLEXCAN_RXIMR Register Bit Definition
 */

#define FLEXCAN_RXIMR_MI_SHIFT                  (0)
#define FLEXCAN_RXIMR_MI_MASK                   (0xFFFFFFFFU << FLEXCAN_RXIMR_MI_SHIFT)
#define FLEXCAN_RXIMR_MI(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXCAN_RXIMR_MI_SHIFT)) & FLEXCAN_RXIMR_MI_MASK)

/*!
 * @brief FLEXCAN_FDCTRL Register Bit Definition
 */

#define FLEXCAN_FDCTRL_FDRATE_SHIFT             (31)
#define FLEXCAN_FDCTRL_FDRATE_MASK              (0x1U << FLEXCAN_FDCTRL_FDRATE_SHIFT)
#define FLEXCAN_FDCTRL_FDRATE(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_FDRATE_SHIFT)) & FLEXCAN_FDCTRL_FDRATE_MASK)

#define FLEXCAN_FDCTRL_MBDSR0_SHIFT             (16)
#define FLEXCAN_FDCTRL_MBDSR0_MASK              (0x3U << FLEXCAN_FDCTRL_MBDSR0_SHIFT)
#define FLEXCAN_FDCTRL_MBDSR0(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_MBDSR0_SHIFT)) & FLEXCAN_FDCTRL_MBDSR0_MASK)

#define FLEXCAN_FDCTRL_TDCEN_SHIFT              (15)
#define FLEXCAN_FDCTRL_TDCEN_MASK               (0x1U << FLEXCAN_FDCTRL_TDCEN_SHIFT)
#define FLEXCAN_FDCTRL_TDCEN(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_TDCEN_SHIFT)) & FLEXCAN_FDCTRL_TDCEN_MASK)

#define FLEXCAN_FDCTRL_TDCFAIL_SHIFT            (14)
#define FLEXCAN_FDCTRL_TDCFAIL_MASK             (0x1U << FLEXCAN_FDCTRL_TDCFAIL_SHIFT)
#define FLEXCAN_FDCTRL_TDCFAIL(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_TDCFAIL_SHIFT)) & FLEXCAN_FDCTRL_TDCFAIL_MASK)

#define FLEXCAN_FDCTRL_TDCOFF_SHIFT             (8)
#define FLEXCAN_FDCTRL_TDCOFF_MASK              (0x1FU << FLEXCAN_FDCTRL_TDCOFF_SHIFT)
#define FLEXCAN_FDCTRL_TDCOFF(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_TDCOFF_SHIFT)) & FLEXCAN_FDCTRL_TDCOFF_MASK)

#define FLEXCAN_FDCTRL_TDCVAL_SHIFT             (0)
#define FLEXCAN_FDCTRL_TDCVAL_MASK              (0x3FU << FLEXCAN_FDCTRL_TDCVAL_SHIFT)
#define FLEXCAN_FDCTRL_TDCVAL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCTRL_TDCVAL_SHIFT)) & FLEXCAN_FDCTRL_TDCVAL_MASK)

/*!
 * @brief FLEXCAN_FDCBT Register Bit Definition
 */

#define FLEXCAN_FDCBT_FPRESDIV_SHIFT            (20)
#define FLEXCAN_FDCBT_FPRESDIV_MASK             (0x3FFU << FLEXCAN_FDCBT_FPRESDIV_SHIFT)
#define FLEXCAN_FDCBT_FPRESDIV(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCBT_FPRESDIV_SHIFT)) & FLEXCAN_FDCBT_FPRESDIV_MASK)

#define FLEXCAN_FDCBT_FRJW_SHIFT                (16)
#define FLEXCAN_FDCBT_FRJW_MASK                 (0x7U << FLEXCAN_FDCBT_FRJW_SHIFT)
#define FLEXCAN_FDCBT_FRJW(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCBT_FRJW_SHIFT)) & FLEXCAN_FDCBT_FRJW_MASK)

#define FLEXCAN_FDCBT_FPROPSEG_SHIFT            (10)
#define FLEXCAN_FDCBT_FPROPSEG_MASK             (0x1FU << FLEXCAN_FDCBT_FPROPSEG_SHIFT)
#define FLEXCAN_FDCBT_FPROPSEG(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCBT_FPROPSEG_SHIFT)) & FLEXCAN_FDCBT_FPROPSEG_MASK)

#define FLEXCAN_FDCBT_FPSEG1_SHIFT              (5)
#define FLEXCAN_FDCBT_FPSEG1_MASK               (0x7U << FLEXCAN_FDCBT_FPSEG1_SHIFT)
#define FLEXCAN_FDCBT_FPSEG1(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCBT_FPSEG1_SHIFT)) & FLEXCAN_FDCBT_FPSEG1_MASK)

#define FLEXCAN_FDCBT_FPSEG2_SHIFT              (0)
#define FLEXCAN_FDCBT_FPSEG2_MASK               (0x7U << FLEXCAN_FDCBT_FPSEG2_SHIFT)
#define FLEXCAN_FDCBT_FPSEG2(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCBT_FPSEG2_SHIFT)) & FLEXCAN_FDCBT_FPSEG2_MASK)

/*!
 * @brief FLEXCAN_FDCRC Register Bit Definition
 */

#define FLEXCAN_FDCRC_FDMBCRC_SHIFT             (24)
#define FLEXCAN_FDCRC_FDMBCRC_MASK              (0x7FU << FLEXCAN_FDCRC_FDMBCRC_SHIFT)
#define FLEXCAN_FDCRC_FDMBCRC(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCRC_FDMBCRC_SHIFT)) & FLEXCAN_FDCRC_FDMBCRC_MASK)

#define FLEXCAN_FDCRC_FDTXCRC_SHIFT             (0)
#define FLEXCAN_FDCRC_FDTXCRC_MASK              (0x1FFFFFU << FLEXCAN_FDCRC_FDTXCRC_SHIFT)
#define FLEXCAN_FDCRC_FDTXCRC(x)                (((uint32_t)(((uint32_t)(x)) << FLEXCAN_FDCRC_FDTXCRC_SHIFT)) & FLEXCAN_FDCRC_FDTXCRC_MASK)

/*!
 * @brief FLEXCAN_ERFCR Register Bit Definition
 */

#define FLEXCAN_ERFCR_ERFEN_SHIFT               (31)
#define FLEXCAN_ERFCR_ERFEN_MASK                (0x1U << FLEXCAN_ERFCR_ERFEN_SHIFT)
#define FLEXCAN_ERFCR_ERFEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFCR_ERFEN_SHIFT)) & FLEXCAN_ERFCR_ERFEN_MASK)

#define FLEXCAN_ERFCR_DMALW_SHIFT               (26)
#define FLEXCAN_ERFCR_DMALW_MASK                (0x1FU << FLEXCAN_ERFCR_DMALW_SHIFT)
#define FLEXCAN_ERFCR_DMALW(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFCR_DMALW_SHIFT)) & FLEXCAN_ERFCR_DMALW_MASK)

#define FLEXCAN_ERFCR_NEXIF_SHIFT               (16)
#define FLEXCAN_ERFCR_NEXIF_MASK                (0x1U << FLEXCAN_ERFCR_NEXIF_SHIFT)
#define FLEXCAN_ERFCR_NEXIF(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFCR_NEXIF_SHIFT)) & FLEXCAN_ERFCR_NEXIF_MASK)

#define FLEXCAN_ERFCR_ERFWM_SHIFT               (0)
#define FLEXCAN_ERFCR_ERFWM_MASK                (0x7U << FLEXCAN_ERFCR_ERFWM_SHIFT)
#define FLEXCAN_ERFCR_ERFWM(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFCR_ERFWM_SHIFT)) & FLEXCAN_ERFCR_ERFWM_MASK)

/*!
 * @brief FLEXCAN_ERFIER Register Bit Definition
 */

#define FLEXCAN_ERFIER_ERFUFWIE_SHIFT           (31)
#define FLEXCAN_ERFIER_ERFUFWIE_MASK            (0x1U << FLEXCAN_ERFIER_ERFUFWIE_SHIFT)
#define FLEXCAN_ERFIER_ERFUFWIE(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFIER_ERFUFWIE_SHIFT)) & FLEXCAN_ERFIER_ERFUFWIE_MASK)

#define FLEXCAN_ERFIER_ERFOVFIE_SHIFT           (30)
#define FLEXCAN_ERFIER_ERFOVFIE_MASK            (0x1U << FLEXCAN_ERFIER_ERFOVFIE_SHIFT)
#define FLEXCAN_ERFIER_ERFOVFIE(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFIER_ERFOVFIE_SHIFT)) & FLEXCAN_ERFIER_ERFOVFIE_MASK)

#define FLEXCAN_ERFIER_ERFWMIIE_SHIFT           (29)
#define FLEXCAN_ERFIER_ERFWMIIE_MASK            (0x1U << FLEXCAN_ERFIER_ERFWMIIE_SHIFT)
#define FLEXCAN_ERFIER_ERFWMIIE(x)              (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFIER_ERFWMIIE_SHIFT)) & FLEXCAN_ERFIER_ERFWMIIE_MASK)

#define FLEXCAN_ERFIER_ERFDAIE_SHIFT            (28)
#define FLEXCAN_ERFIER_ERFDAIE_MASK             (0x1U << FLEXCAN_ERFIER_ERFDAIE_SHIFT)
#define FLEXCAN_ERFIER_ERFDAIE(x)               (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFIER_ERFDAIE_SHIFT)) & FLEXCAN_ERFIER_ERFDAIE_MASK)

/*!
 * @brief FLEXCAN_ERFSR Register Bit Definition
 */

#define FLEXCAN_ERFSR_ERFUFW_SHIFT              (31)
#define FLEXCAN_ERFSR_ERFUFW_MASK               (0x1U << FLEXCAN_ERFSR_ERFUFW_SHIFT)
#define FLEXCAN_ERFSR_ERFUFW(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFUFW_SHIFT)) & FLEXCAN_ERFSR_ERFUFW_MASK)

#define FLEXCAN_ERFSR_ERFOVF_SHIFT              (30)
#define FLEXCAN_ERFSR_ERFOVF_MASK               (0x1U << FLEXCAN_ERFSR_ERFOVF_SHIFT)
#define FLEXCAN_ERFSR_ERFOVF(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFOVF_SHIFT)) & FLEXCAN_ERFSR_ERFOVF_MASK)

#define FLEXCAN_ERFSR_ERFWMI_SHIFT              (29)
#define FLEXCAN_ERFSR_ERFWMI_MASK               (0x1U << FLEXCAN_ERFSR_ERFWMI_SHIFT)
#define FLEXCAN_ERFSR_ERFWMI(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFWMI_SHIFT)) & FLEXCAN_ERFSR_ERFWMI_MASK)

#define FLEXCAN_ERFSR_ERFDA_SHIFT               (28)
#define FLEXCAN_ERFSR_ERFDA_MASK                (0x1U << FLEXCAN_ERFSR_ERFDA_SHIFT)
#define FLEXCAN_ERFSR_ERFDA(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFDA_SHIFT)) & FLEXCAN_ERFSR_ERFDA_MASK)

#define FLEXCAN_ERFSR_ERFCLR_SHIFT              (27)
#define FLEXCAN_ERFSR_ERFCLR_MASK               (0x1U << FLEXCAN_ERFSR_ERFCLR_SHIFT)
#define FLEXCAN_ERFSR_ERFCLR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFCLR_SHIFT)) & FLEXCAN_ERFSR_ERFCLR_MASK)

#define FLEXCAN_ERFSR_ERFE_SHIFT                (17)
#define FLEXCAN_ERFSR_ERFE_MASK                 (0x1U << FLEXCAN_ERFSR_ERFE_SHIFT)
#define FLEXCAN_ERFSR_ERFE(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFE_SHIFT)) & FLEXCAN_ERFSR_ERFE_MASK)

#define FLEXCAN_ERFSR_ERFF_SHIFT                (16)
#define FLEXCAN_ERFSR_ERFF_MASK                 (0x1U << FLEXCAN_ERFSR_ERFF_SHIFT)
#define FLEXCAN_ERFSR_ERFF(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFF_SHIFT)) & FLEXCAN_ERFSR_ERFF_MASK)

#define FLEXCAN_ERFSR_ERFEL_SHIFT               (0)
#define FLEXCAN_ERFSR_ERFEL_MASK                (0x7U << FLEXCAN_ERFSR_ERFEL_SHIFT)
#define FLEXCAN_ERFSR_ERFEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFSR_ERFEL_SHIFT)) & FLEXCAN_ERFSR_ERFEL_MASK)

/*!
 * @brief FLEXCAN_ERFFEL Register Bit Definition
 */

#define FLEXCAN_ERFFEL_FEL_SHIFT                (0)
#define FLEXCAN_ERFFEL_FEL_MASK                 (0xFFFFFFFFU << FLEXCAN_ERFFEL_FEL_SHIFT)
#define FLEXCAN_ERFFEL_FEL(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXCAN_ERFFEL_FEL_SHIFT)) & FLEXCAN_ERFFEL_FEL_MASK)

/*!
 * @}
 */ /* end of group FLEXCAN_Register_Masks */
/******************************************************************************
 *FLEXCAN Instance
*******************************************************************************/

#define FLEXCAN              ((FLEXCAN_Type*)FLEXCAN_BASE)

/*!
 * @}
 */ /* end of group FLEXCAN_Peripheral_Access_Layer */



/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * GPIO Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CRL;                                                          ///< Port configuration register low              offset: 0x00
    __IO uint32_t CRH;                                                          ///< Port configuration register high             offset: 0x04
    __IO uint32_t IDR;                                                          ///< Port input data register                     offset: 0x08
    __IO uint32_t ODR;                                                          ///< Port output data register                    offset: 0x0C
    __IO uint32_t BSRR;                                                         ///< Port bit set/reset register                  offset: 0x10
    __IO uint32_t BRR;                                                          ///< Port bit reset register                      offset: 0x14
    __IO uint32_t LCKR;                                                         ///< Port configuration lock register             offset: 0x18
    __IO uint32_t DCR;                                                          ///< Port output open drain control register      offset: 0x1C
    __IO uint32_t AFRL;                                                         ///< Port alternate function register low         offset: 0x20
    __IO uint32_t AFRH;                                                         ///< Port alternate function register high        offset: 0x24
} GPIO_Type;

/*******************************************************************************
 * GPIO Type
 ******************************************************************************/

/*!
 * @addtogroup GPIO_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief GPIO_CRL Register Bit Definition
 */

#define GPIO_CRL_CNF7_SHIFT                     (30)
#define GPIO_CRL_CNF7_MASK                      (0x3U << GPIO_CRL_CNF7_SHIFT)
#define GPIO_CRL_CNF7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF7_SHIFT)) & GPIO_CRL_CNF7_MASK)

#define GPIO_CRL_MODE7_SHIFT                    (28)
#define GPIO_CRL_MODE7_MASK                     (0x3U << GPIO_CRL_MODE7_SHIFT)
#define GPIO_CRL_MODE7(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE7_SHIFT)) & GPIO_CRL_MODE7_MASK)

#define GPIO_CRL_CNF6_SHIFT                     (26)
#define GPIO_CRL_CNF6_MASK                      (0x3U << GPIO_CRL_CNF6_SHIFT)
#define GPIO_CRL_CNF6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF6_SHIFT)) & GPIO_CRL_CNF6_MASK)

#define GPIO_CRL_MODE6_SHIFT                    (24)
#define GPIO_CRL_MODE6_MASK                     (0x3U << GPIO_CRL_MODE6_SHIFT)
#define GPIO_CRL_MODE6(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE6_SHIFT)) & GPIO_CRL_MODE6_MASK)

#define GPIO_CRL_CNF5_SHIFT                     (22)
#define GPIO_CRL_CNF5_MASK                      (0x3U << GPIO_CRL_CNF5_SHIFT)
#define GPIO_CRL_CNF5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF5_SHIFT)) & GPIO_CRL_CNF5_MASK)

#define GPIO_CRL_MODE5_SHIFT                    (20)
#define GPIO_CRL_MODE5_MASK                     (0x3U << GPIO_CRL_MODE5_SHIFT)
#define GPIO_CRL_MODE5(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE5_SHIFT)) & GPIO_CRL_MODE5_MASK)

#define GPIO_CRL_CNF4_SHIFT                     (18)
#define GPIO_CRL_CNF4_MASK                      (0x3U << GPIO_CRL_CNF4_SHIFT)
#define GPIO_CRL_CNF4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF4_SHIFT)) & GPIO_CRL_CNF4_MASK)

#define GPIO_CRL_MODE4_SHIFT                    (16)
#define GPIO_CRL_MODE4_MASK                     (0x3U << GPIO_CRL_MODE4_SHIFT)
#define GPIO_CRL_MODE4(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE4_SHIFT)) & GPIO_CRL_MODE4_MASK)

#define GPIO_CRL_CNF3_SHIFT                     (14)
#define GPIO_CRL_CNF3_MASK                      (0x3U << GPIO_CRL_CNF3_SHIFT)
#define GPIO_CRL_CNF3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF3_SHIFT)) & GPIO_CRL_CNF3_MASK)

#define GPIO_CRL_MODE3_SHIFT                    (12)
#define GPIO_CRL_MODE3_MASK                     (0x3U << GPIO_CRL_MODE3_SHIFT)
#define GPIO_CRL_MODE3(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE3_SHIFT)) & GPIO_CRL_MODE3_MASK)

#define GPIO_CRL_CNF2_SHIFT                     (10)
#define GPIO_CRL_CNF2_MASK                      (0x3U << GPIO_CRL_CNF2_SHIFT)
#define GPIO_CRL_CNF2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF2_SHIFT)) & GPIO_CRL_CNF2_MASK)

#define GPIO_CRL_MODE2_SHIFT                    (8)
#define GPIO_CRL_MODE2_MASK                     (0x3U << GPIO_CRL_MODE2_SHIFT)
#define GPIO_CRL_MODE2(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE2_SHIFT)) & GPIO_CRL_MODE2_MASK)

#define GPIO_CRL_CNF1_SHIFT                     (6)
#define GPIO_CRL_CNF1_MASK                      (0x3U << GPIO_CRL_CNF1_SHIFT)
#define GPIO_CRL_CNF1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF1_SHIFT)) & GPIO_CRL_CNF1_MASK)

#define GPIO_CRL_MODE1_SHIFT                    (4)
#define GPIO_CRL_MODE1_MASK                     (0x3U << GPIO_CRL_MODE1_SHIFT)
#define GPIO_CRL_MODE1(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE1_SHIFT)) & GPIO_CRL_MODE1_MASK)

#define GPIO_CRL_CNF0_SHIFT                     (2)
#define GPIO_CRL_CNF0_MASK                      (0x3U << GPIO_CRL_CNF0_SHIFT)
#define GPIO_CRL_CNF0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_CNF0_SHIFT)) & GPIO_CRL_CNF0_MASK)

#define GPIO_CRL_MODE0_SHIFT                    (0)
#define GPIO_CRL_MODE0_MASK                     (0x3U << GPIO_CRL_MODE0_SHIFT)
#define GPIO_CRL_MODE0(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRL_MODE0_SHIFT)) & GPIO_CRL_MODE0_MASK)

/*!
 * @brief GPIO_CRH Register Bit Definition
 */

#define GPIO_CRH_CNF15_SHIFT                    (30)
#define GPIO_CRH_CNF15_MASK                     (0x3U << GPIO_CRH_CNF15_SHIFT)
#define GPIO_CRH_CNF15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF15_SHIFT)) & GPIO_CRH_CNF15_MASK)

#define GPIO_CRH_MODE15_SHIFT                   (28)
#define GPIO_CRH_MODE15_MASK                    (0x3U << GPIO_CRH_MODE15_SHIFT)
#define GPIO_CRH_MODE15(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE15_SHIFT)) & GPIO_CRH_MODE15_MASK)

#define GPIO_CRH_CNF14_SHIFT                    (26)
#define GPIO_CRH_CNF14_MASK                     (0x3U << GPIO_CRH_CNF14_SHIFT)
#define GPIO_CRH_CNF14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF14_SHIFT)) & GPIO_CRH_CNF14_MASK)

#define GPIO_CRH_MODE14_SHIFT                   (24)
#define GPIO_CRH_MODE14_MASK                    (0x3U << GPIO_CRH_MODE14_SHIFT)
#define GPIO_CRH_MODE14(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE14_SHIFT)) & GPIO_CRH_MODE14_MASK)

#define GPIO_CRH_CNF13_SHIFT                    (22)
#define GPIO_CRH_CNF13_MASK                     (0x3U << GPIO_CRH_CNF13_SHIFT)
#define GPIO_CRH_CNF13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF13_SHIFT)) & GPIO_CRH_CNF13_MASK)

#define GPIO_CRH_MODE13_SHIFT                   (20)
#define GPIO_CRH_MODE13_MASK                    (0x3U << GPIO_CRH_MODE13_SHIFT)
#define GPIO_CRH_MODE13(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE13_SHIFT)) & GPIO_CRH_MODE13_MASK)

#define GPIO_CRH_CNF12_SHIFT                    (18)
#define GPIO_CRH_CNF12_MASK                     (0x3U << GPIO_CRH_CNF12_SHIFT)
#define GPIO_CRH_CNF12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF12_SHIFT)) & GPIO_CRH_CNF12_MASK)

#define GPIO_CRH_MODE12_SHIFT                   (16)
#define GPIO_CRH_MODE12_MASK                    (0x3U << GPIO_CRH_MODE12_SHIFT)
#define GPIO_CRH_MODE12(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE12_SHIFT)) & GPIO_CRH_MODE12_MASK)

#define GPIO_CRH_CNF11_SHIFT                    (14)
#define GPIO_CRH_CNF11_MASK                     (0x3U << GPIO_CRH_CNF11_SHIFT)
#define GPIO_CRH_CNF11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF11_SHIFT)) & GPIO_CRH_CNF11_MASK)

#define GPIO_CRH_MODE11_SHIFT                   (12)
#define GPIO_CRH_MODE11_MASK                    (0x3U << GPIO_CRH_MODE11_SHIFT)
#define GPIO_CRH_MODE11(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE11_SHIFT)) & GPIO_CRH_MODE11_MASK)

#define GPIO_CRH_CNF10_SHIFT                    (10)
#define GPIO_CRH_CNF10_MASK                     (0x3U << GPIO_CRH_CNF10_SHIFT)
#define GPIO_CRH_CNF10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF10_SHIFT)) & GPIO_CRH_CNF10_MASK)

#define GPIO_CRH_MODE10_SHIFT                   (8)
#define GPIO_CRH_MODE10_MASK                    (0x3U << GPIO_CRH_MODE10_SHIFT)
#define GPIO_CRH_MODE10(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE10_SHIFT)) & GPIO_CRH_MODE10_MASK)

#define GPIO_CRH_CNF9_SHIFT                     (6)
#define GPIO_CRH_CNF9_MASK                      (0x3U << GPIO_CRH_CNF9_SHIFT)
#define GPIO_CRH_CNF9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF9_SHIFT)) & GPIO_CRH_CNF9_MASK)

#define GPIO_CRH_MODE9_SHIFT                    (4)
#define GPIO_CRH_MODE9_MASK                     (0x3U << GPIO_CRH_MODE9_SHIFT)
#define GPIO_CRH_MODE9(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE9_SHIFT)) & GPIO_CRH_MODE9_MASK)

#define GPIO_CRH_CNF8_SHIFT                     (2)
#define GPIO_CRH_CNF8_MASK                      (0x3U << GPIO_CRH_CNF8_SHIFT)
#define GPIO_CRH_CNF8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_CNF8_SHIFT)) & GPIO_CRH_CNF8_MASK)

#define GPIO_CRH_MODE8_SHIFT                    (0)
#define GPIO_CRH_MODE8_MASK                     (0x3U << GPIO_CRH_MODE8_SHIFT)
#define GPIO_CRH_MODE8(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_CRH_MODE8_SHIFT)) & GPIO_CRH_MODE8_MASK)

/*!
 * @brief GPIO_IDR Register Bit Definition
 */

#define GPIO_IDR_IDRY_SHIFT                     (0)
#define GPIO_IDR_IDRY_MASK                      (0xFFFFU << GPIO_IDR_IDRY_SHIFT)
#define GPIO_IDR_IDRY(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_IDR_IDRY_SHIFT)) & GPIO_IDR_IDRY_MASK)

/*!
 * @brief GPIO_ODR Register Bit Definition
 */

#define GPIO_ODR_ODRY_SHIFT                     (0)
#define GPIO_ODR_ODRY_MASK                      (0xFFFFU << GPIO_ODR_ODRY_SHIFT)
#define GPIO_ODR_ODRY(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ODR_ODRY_SHIFT)) & GPIO_ODR_ODRY_MASK)

/*!
 * @brief GPIO_BSRR Register Bit Definition
 */

#define GPIO_BSRR_BRY_SHIFT                     (16)
#define GPIO_BSRR_BRY_MASK                      (0xFFFFU << GPIO_BSRR_BRY_SHIFT)
#define GPIO_BSRR_BRY(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_BSRR_BRY_SHIFT)) & GPIO_BSRR_BRY_MASK)

#define GPIO_BSRR_BSY_SHIFT                     (0)
#define GPIO_BSRR_BSY_MASK                      (0xFFFFU << GPIO_BSRR_BSY_SHIFT)
#define GPIO_BSRR_BSY(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_BSRR_BSY_SHIFT)) & GPIO_BSRR_BSY_MASK)

/*!
 * @brief GPIO_BRR Register Bit Definition
 */

#define GPIO_BRR_BRY_SHIFT                      (0)
#define GPIO_BRR_BRY_MASK                       (0xFFFFU << GPIO_BRR_BRY_SHIFT)
#define GPIO_BRR_BRY(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_BRR_BRY_SHIFT)) & GPIO_BRR_BRY_MASK)

/*!
 * @brief GPIO_LCKR Register Bit Definition
 */

#define GPIO_LCKR_LCKK_SHIFT                    (16)
#define GPIO_LCKR_LCKK_MASK                     (0x1U << GPIO_LCKR_LCKK_SHIFT)
#define GPIO_LCKR_LCKK(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_LCKR_LCKK_SHIFT)) & GPIO_LCKR_LCKK_MASK)

#define GPIO_LCKR_LCK_SHIFT                     (0)
#define GPIO_LCKR_LCK_MASK                      (0xFFFFU << GPIO_LCKR_LCK_SHIFT)
#define GPIO_LCKR_LCK(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_LCKR_LCK_SHIFT)) & GPIO_LCKR_LCK_MASK)

/*!
 * @brief GPIO_DCR Register Bit Definition
 */

#define GPIO_DCR_PX15_SHIFT                     (30)
#define GPIO_DCR_PX15_MASK                      (0x3U << GPIO_DCR_PX15_SHIFT)
#define GPIO_DCR_PX15(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX15_SHIFT)) & GPIO_DCR_PX15_MASK)

#define GPIO_DCR_PX14_SHIFT                     (28)
#define GPIO_DCR_PX14_MASK                      (0x3U << GPIO_DCR_PX14_SHIFT)
#define GPIO_DCR_PX14(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX14_SHIFT)) & GPIO_DCR_PX14_MASK)

#define GPIO_DCR_PX13_SHIFT                     (26)
#define GPIO_DCR_PX13_MASK                      (0x3U << GPIO_DCR_PX13_SHIFT)
#define GPIO_DCR_PX13(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX13_SHIFT)) & GPIO_DCR_PX13_MASK)

#define GPIO_DCR_PX12_SHIFT                     (24)
#define GPIO_DCR_PX12_MASK                      (0x3U << GPIO_DCR_PX12_SHIFT)
#define GPIO_DCR_PX12(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX12_SHIFT)) & GPIO_DCR_PX12_MASK)

#define GPIO_DCR_PX11_SHIFT                     (22)
#define GPIO_DCR_PX11_MASK                      (0x3U << GPIO_DCR_PX11_SHIFT)
#define GPIO_DCR_PX11(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX11_SHIFT)) & GPIO_DCR_PX11_MASK)

#define GPIO_DCR_PX10_SHIFT                     (20)
#define GPIO_DCR_PX10_MASK                      (0x3U << GPIO_DCR_PX10_SHIFT)
#define GPIO_DCR_PX10(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX10_SHIFT)) & GPIO_DCR_PX10_MASK)

#define GPIO_DCR_PX9_SHIFT                      (18)
#define GPIO_DCR_PX9_MASK                       (0x3U << GPIO_DCR_PX9_SHIFT)
#define GPIO_DCR_PX9(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX9_SHIFT)) & GPIO_DCR_PX9_MASK)

#define GPIO_DCR_PX8_SHIFT                      (16)
#define GPIO_DCR_PX8_MASK                       (0x3U << GPIO_DCR_PX8_SHIFT)
#define GPIO_DCR_PX8(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX8_SHIFT)) & GPIO_DCR_PX8_MASK)

#define GPIO_DCR_PX7_SHIFT                      (14)
#define GPIO_DCR_PX7_MASK                       (0x3U << GPIO_DCR_PX7_SHIFT)
#define GPIO_DCR_PX7(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX7_SHIFT)) & GPIO_DCR_PX7_MASK)

#define GPIO_DCR_PX6_SHIFT                      (12)
#define GPIO_DCR_PX6_MASK                       (0x3U << GPIO_DCR_PX6_SHIFT)
#define GPIO_DCR_PX6(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX6_SHIFT)) & GPIO_DCR_PX6_MASK)

#define GPIO_DCR_PX5_SHIFT                      (10)
#define GPIO_DCR_PX5_MASK                       (0x3U << GPIO_DCR_PX5_SHIFT)
#define GPIO_DCR_PX5(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX5_SHIFT)) & GPIO_DCR_PX5_MASK)

#define GPIO_DCR_PX4_SHIFT                      (8)
#define GPIO_DCR_PX4_MASK                       (0x3U << GPIO_DCR_PX4_SHIFT)
#define GPIO_DCR_PX4(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX4_SHIFT)) & GPIO_DCR_PX4_MASK)

#define GPIO_DCR_PX3_SHIFT                      (6)
#define GPIO_DCR_PX3_MASK                       (0x3U << GPIO_DCR_PX3_SHIFT)
#define GPIO_DCR_PX3(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX3_SHIFT)) & GPIO_DCR_PX3_MASK)

#define GPIO_DCR_PX2_SHIFT                      (4)
#define GPIO_DCR_PX2_MASK                       (0x3U << GPIO_DCR_PX2_SHIFT)
#define GPIO_DCR_PX2(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX2_SHIFT)) & GPIO_DCR_PX2_MASK)

#define GPIO_DCR_PX1_SHIFT                      (2)
#define GPIO_DCR_PX1_MASK                       (0x3U << GPIO_DCR_PX1_SHIFT)
#define GPIO_DCR_PX1(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX1_SHIFT)) & GPIO_DCR_PX1_MASK)

#define GPIO_DCR_PX0_SHIFT                      (0)
#define GPIO_DCR_PX0_MASK                       (0x3U << GPIO_DCR_PX0_SHIFT)
#define GPIO_DCR_PX0(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DCR_PX0_SHIFT)) & GPIO_DCR_PX0_MASK)

/*!
 * @brief GPIO_AFRL Register Bit Definition
 */

#define GPIO_AFRL_AFR7_SHIFT                    (28)
#define GPIO_AFRL_AFR7_MASK                     (0xFU << GPIO_AFRL_AFR7_SHIFT)
#define GPIO_AFRL_AFR7(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR7_SHIFT)) & GPIO_AFRL_AFR7_MASK)

#define GPIO_AFRL_AFR6_SHIFT                    (24)
#define GPIO_AFRL_AFR6_MASK                     (0xFU << GPIO_AFRL_AFR6_SHIFT)
#define GPIO_AFRL_AFR6(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR6_SHIFT)) & GPIO_AFRL_AFR6_MASK)

#define GPIO_AFRL_AFR5_SHIFT                    (20)
#define GPIO_AFRL_AFR5_MASK                     (0xFU << GPIO_AFRL_AFR5_SHIFT)
#define GPIO_AFRL_AFR5(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR5_SHIFT)) & GPIO_AFRL_AFR5_MASK)

#define GPIO_AFRL_AFR4_SHIFT                    (16)
#define GPIO_AFRL_AFR4_MASK                     (0xFU << GPIO_AFRL_AFR4_SHIFT)
#define GPIO_AFRL_AFR4(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR4_SHIFT)) & GPIO_AFRL_AFR4_MASK)

#define GPIO_AFRL_AFR3_SHIFT                    (12)
#define GPIO_AFRL_AFR3_MASK                     (0xFU << GPIO_AFRL_AFR3_SHIFT)
#define GPIO_AFRL_AFR3(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR3_SHIFT)) & GPIO_AFRL_AFR3_MASK)

#define GPIO_AFRL_AFR2_SHIFT                    (8)
#define GPIO_AFRL_AFR2_MASK                     (0xFU << GPIO_AFRL_AFR2_SHIFT)
#define GPIO_AFRL_AFR2(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR2_SHIFT)) & GPIO_AFRL_AFR2_MASK)

#define GPIO_AFRL_AFR1_SHIFT                    (4)
#define GPIO_AFRL_AFR1_MASK                     (0xFU << GPIO_AFRL_AFR1_SHIFT)
#define GPIO_AFRL_AFR1(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR1_SHIFT)) & GPIO_AFRL_AFR1_MASK)

#define GPIO_AFRL_AFR0_SHIFT                    (0)
#define GPIO_AFRL_AFR0_MASK                     (0xFU << GPIO_AFRL_AFR0_SHIFT)
#define GPIO_AFRL_AFR0(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRL_AFR0_SHIFT)) & GPIO_AFRL_AFR0_MASK)

/*!
 * @brief GPIO_AFRH Register Bit Definition
 */

#define GPIO_AFRH_AFR15_SHIFT                   (28)
#define GPIO_AFRH_AFR15_MASK                    (0xFU << GPIO_AFRH_AFR15_SHIFT)
#define GPIO_AFRH_AFR15(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR15_SHIFT)) & GPIO_AFRH_AFR15_MASK)

#define GPIO_AFRH_AFR14_SHIFT                   (24)
#define GPIO_AFRH_AFR14_MASK                    (0xFU << GPIO_AFRH_AFR14_SHIFT)
#define GPIO_AFRH_AFR14(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR14_SHIFT)) & GPIO_AFRH_AFR14_MASK)

#define GPIO_AFRH_AFR13_SHIFT                   (20)
#define GPIO_AFRH_AFR13_MASK                    (0xFU << GPIO_AFRH_AFR13_SHIFT)
#define GPIO_AFRH_AFR13(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR13_SHIFT)) & GPIO_AFRH_AFR13_MASK)

#define GPIO_AFRH_AFR12_SHIFT                   (16)
#define GPIO_AFRH_AFR12_MASK                    (0xFU << GPIO_AFRH_AFR12_SHIFT)
#define GPIO_AFRH_AFR12(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR12_SHIFT)) & GPIO_AFRH_AFR12_MASK)

#define GPIO_AFRH_AFR11_SHIFT                   (12)
#define GPIO_AFRH_AFR11_MASK                    (0xFU << GPIO_AFRH_AFR11_SHIFT)
#define GPIO_AFRH_AFR11(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR11_SHIFT)) & GPIO_AFRH_AFR11_MASK)

#define GPIO_AFRH_AFR10_SHIFT                   (8)
#define GPIO_AFRH_AFR10_MASK                    (0xFU << GPIO_AFRH_AFR10_SHIFT)
#define GPIO_AFRH_AFR10(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR10_SHIFT)) & GPIO_AFRH_AFR10_MASK)

#define GPIO_AFRH_AFR9_SHIFT                    (4)
#define GPIO_AFRH_AFR9_MASK                     (0xFU << GPIO_AFRH_AFR9_SHIFT)
#define GPIO_AFRH_AFR9(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR9_SHIFT)) & GPIO_AFRH_AFR9_MASK)

#define GPIO_AFRH_AFR8_SHIFT                    (0)
#define GPIO_AFRH_AFR8_MASK                     (0xFU << GPIO_AFRH_AFR8_SHIFT)
#define GPIO_AFRH_AFR8(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_AFRH_AFR8_SHIFT)) & GPIO_AFRH_AFR8_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */
/******************************************************************************
 *GPIO Instance
*******************************************************************************/

#define GPIOA                ((GPIO_Type*)GPIOA_BASE)

#define GPIOB                ((GPIO_Type*)GPIOB_BASE)

#define GPIOC                ((GPIO_Type*)GPIOC_BASE)

#define GPIOD                ((GPIO_Type*)GPIOD_BASE)

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */



/*!
 * @addtogroup HWDIV_Peripheral_Access_Layer HWDIV Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * HWDIV Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t DVDR;                                                         ///< Dividend register                            offset: 0x00
    __IO uint32_t DVSR;                                                         ///< Divisor register                             offset: 0x04
    __IO uint32_t QUOTR;                                                        ///< Quotient register                            offset: 0x08
    __IO uint32_t RMDR;                                                         ///< Remainder register                           offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status register                              offset: 0x10
    __IO uint32_t CR;                                                           ///< Control register                             offset: 0x14
} HWDIV_Type;

/*******************************************************************************
 * HWDIV Type
 ******************************************************************************/

/*!
 * @addtogroup HWDIV_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief HWDIV_DVDR Register Bit Definition
 */

#define HWDIV_DVDR_DIVIDEND_SHIFT               (0)
#define HWDIV_DVDR_DIVIDEND_MASK                (0xFFFFFFFFU << HWDIV_DVDR_DIVIDEND_SHIFT)
#define HWDIV_DVDR_DIVIDEND(x)                  (((uint32_t)(((uint32_t)(x)) << HWDIV_DVDR_DIVIDEND_SHIFT)) & HWDIV_DVDR_DIVIDEND_MASK)

/*!
 * @brief HWDIV_DVSR Register Bit Definition
 */

#define HWDIV_DVSR_DIVISOR_SHIFT                (0)
#define HWDIV_DVSR_DIVISOR_MASK                 (0xFFFFFFFFU << HWDIV_DVSR_DIVISOR_SHIFT)
#define HWDIV_DVSR_DIVISOR(x)                   (((uint32_t)(((uint32_t)(x)) << HWDIV_DVSR_DIVISOR_SHIFT)) & HWDIV_DVSR_DIVISOR_MASK)

/*!
 * @brief HWDIV_QUOTR Register Bit Definition
 */

#define HWDIV_QUOTR_QUOTIENT_SHIFT              (0)
#define HWDIV_QUOTR_QUOTIENT_MASK               (0xFFFFFFFFU << HWDIV_QUOTR_QUOTIENT_SHIFT)
#define HWDIV_QUOTR_QUOTIENT(x)                 (((uint32_t)(((uint32_t)(x)) << HWDIV_QUOTR_QUOTIENT_SHIFT)) & HWDIV_QUOTR_QUOTIENT_MASK)

/*!
 * @brief HWDIV_RMDR Register Bit Definition
 */

#define HWDIV_RMDR_REMAINDER_SHIFT              (0)
#define HWDIV_RMDR_REMAINDER_MASK               (0xFFFFFFFFU << HWDIV_RMDR_REMAINDER_SHIFT)
#define HWDIV_RMDR_REMAINDER(x)                 (((uint32_t)(((uint32_t)(x)) << HWDIV_RMDR_REMAINDER_SHIFT)) & HWDIV_RMDR_REMAINDER_MASK)

/*!
 * @brief HWDIV_SR Register Bit Definition
 */

#define HWDIV_SR_OVF_SHIFT                      (0)
#define HWDIV_SR_OVF_MASK                       (0x1U << HWDIV_SR_OVF_SHIFT)
#define HWDIV_SR_OVF(x)                         (((uint32_t)(((uint32_t)(x)) << HWDIV_SR_OVF_SHIFT)) & HWDIV_SR_OVF_MASK)

/*!
 * @brief HWDIV_CR Register Bit Definition
 */

#define HWDIV_CR_OVFE_SHIFT                     (1)
#define HWDIV_CR_OVFE_MASK                      (0x1U << HWDIV_CR_OVFE_SHIFT)
#define HWDIV_CR_OVFE(x)                        (((uint32_t)(((uint32_t)(x)) << HWDIV_CR_OVFE_SHIFT)) & HWDIV_CR_OVFE_MASK)

#define HWDIV_CR_USIGN_SHIFT                    (0)
#define HWDIV_CR_USIGN_MASK                     (0x1U << HWDIV_CR_USIGN_SHIFT)
#define HWDIV_CR_USIGN(x)                       (((uint32_t)(((uint32_t)(x)) << HWDIV_CR_USIGN_SHIFT)) & HWDIV_CR_USIGN_MASK)

/*!
 * @}
 */ /* end of group HWDIV_Register_Masks */
/******************************************************************************
 *HWDIV Instance
*******************************************************************************/

#define HWDIV                ((HWDIV_Type*)HWDIV_BASE)

/*!
 * @}
 */ /* end of group HWDIV_Peripheral_Access_Layer */



/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * I2C Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR;                                                           ///< Control Register                             offset: 0x00
    __IO uint32_t TAR;                                                          ///< Target Address Register                      offset: 0x04
    __IO uint32_t SAR;                                                          ///< Slave Address Register                       offset: 0x08
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t DR;                                                           ///< Data Command Register                        offset: 0x10
    __IO uint32_t SSHR;                                                         ///< Standard Mode SCL High Count Register        offset: 0x14
    __IO uint32_t SSLR;                                                         ///< Standard Mode SCL Low Count Register         offset: 0x18
    __IO uint32_t FSHR;                                                         ///< Fast Mode SCL High Count Register            offset: 0x1C
    __IO uint32_t FSLR;                                                         ///< Fast Mode SCL Low Count Register             offset: 0x20
    __IO uint32_t Reserved1[2];                                                 ///< Reserved
    __IO uint32_t ISR;                                                          ///< Interrupt Status Register                    offset: 0x2C
    __IO uint32_t IMR;                                                          ///< Interrupt Mask Register                      offset: 0x30
    __IO uint32_t RAWISR;                                                       ///< RAW Interrupt Status Register                offset: 0x34
    __IO uint32_t RXTLR;                                                        ///< Receive Threshold Register                   offset: 0x38
    __IO uint32_t TXTLR;                                                        ///< Transmit Threshold Register                  offset: 0x3C
    __IO uint32_t ICR;                                                          ///< Combined and Independent Interrupt Clear Registeroffset: 0x40
    __IO uint32_t RXUNDER;                                                      ///< RX_UNDER Interrupt Clear Register            offset: 0x44
    __IO uint32_t RXOVER;                                                       ///< RX_OVER Interrupt Clear Register             offset: 0x48
    __IO uint32_t TXOVER;                                                       ///< TX_OVER Interrupt Clear Register             offset: 0x4C
    __IO uint32_t RDREQ;                                                        ///< RD_REQ Interrupt Clear Register              offset: 0x50
    __IO uint32_t TXABRT;                                                       ///< TX_ABRT Interrupt Clear Register             offset: 0x54
    __IO uint32_t RXDONE;                                                       ///< RX_DONE Interrupt Clear Register             offset: 0x58
    __IO uint32_t ACTIV;                                                        ///< ACTIVITY Interrupt Clear Register            offset: 0x5C
    __IO uint32_t STOP;                                                         ///< STOP_DET Interrupt Clear Register            offset: 0x60
    __IO uint32_t START;                                                        ///< START_DET Interrupt Clear Register           offset: 0x64
    __IO uint32_t GC;                                                           ///< GEN_CALL Interrupt Clear Register            offset: 0x68
    __IO uint32_t ENR;                                                          ///< Enable Register                              offset: 0x6C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x70
    __IO uint32_t TXFLR;                                                        ///< Transmit FIFO Level Register                 offset: 0x74
    __IO uint32_t RXFLR;                                                        ///< Receive FIFO Level Register                  offset: 0x78
    __IO uint32_t HOLD;                                                         ///< SDA Hold Time Register                       offset: 0x7C
    __IO uint32_t Reserved2[2];                                                 ///< Reserved
    __IO uint32_t DMA;                                                          ///< DMA Control Register                         offset: 0x88
    __IO uint32_t Reserved3[2];                                                 ///< Reserved
    __IO uint32_t SETUP;                                                        ///< SDA Setup Time Register                      offset: 0x94
    __IO uint32_t GCR;                                                          ///< General Call ACK Register                    offset: 0x98
    __IO uint32_t Reserved4[5];                                                 ///< Reserved
    __IO uint32_t SLVMASK;                                                      ///< Slave Address Mask Register                  offset: 0xB0
    __IO uint32_t SLVRCVADDR;                                                   ///< Slave Address Receive Register               offset: 0xB4
} I2C_Type;

/*******************************************************************************
 * I2C Type
 ******************************************************************************/

/*!
 * @addtogroup I2C_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief I2C_CR Register Bit Definition
 */

#define I2C_CR_PADSEL_SHIFT                     (12)
#define I2C_CR_PADSEL_MASK                      (0x1U << I2C_CR_PADSEL_SHIFT)
#define I2C_CR_PADSEL(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_CR_PADSEL_SHIFT)) & I2C_CR_PADSEL_MASK)

#define I2C_CR_SLVTXABRTDIS_SHIFT               (11)
#define I2C_CR_SLVTXABRTDIS_MASK                (0x1U << I2C_CR_SLVTXABRTDIS_SHIFT)
#define I2C_CR_SLVTXABRTDIS(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_CR_SLVTXABRTDIS_SHIFT)) & I2C_CR_SLVTXABRTDIS_MASK)

#define I2C_CR_RESTART_SHIFT                    (10)
#define I2C_CR_RESTART_MASK                     (0x1U << I2C_CR_RESTART_SHIFT)
#define I2C_CR_RESTART(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_CR_RESTART_SHIFT)) & I2C_CR_RESTART_MASK)

#define I2C_CR_STOP_SHIFT                       (9)
#define I2C_CR_STOP_MASK                        (0x1U << I2C_CR_STOP_SHIFT)
#define I2C_CR_STOP(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_CR_STOP_SHIFT)) & I2C_CR_STOP_MASK)

#define I2C_CR_EMPINT_SHIFT                     (8)
#define I2C_CR_EMPINT_MASK                      (0x1U << I2C_CR_EMPINT_SHIFT)
#define I2C_CR_EMPINT(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_CR_EMPINT_SHIFT)) & I2C_CR_EMPINT_MASK)

#define I2C_CR_STOPINT_SHIFT                    (7)
#define I2C_CR_STOPINT_MASK                     (0x1U << I2C_CR_STOPINT_SHIFT)
#define I2C_CR_STOPINT(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_CR_STOPINT_SHIFT)) & I2C_CR_STOPINT_MASK)

#define I2C_CR_DISSLAVE_SHIFT                   (6)
#define I2C_CR_DISSLAVE_MASK                    (0x1U << I2C_CR_DISSLAVE_SHIFT)
#define I2C_CR_DISSLAVE(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_CR_DISSLAVE_SHIFT)) & I2C_CR_DISSLAVE_MASK)

#define I2C_CR_REPEN_SHIFT                      (5)
#define I2C_CR_REPEN_MASK                       (0x1U << I2C_CR_REPEN_SHIFT)
#define I2C_CR_REPEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_CR_REPEN_SHIFT)) & I2C_CR_REPEN_MASK)

#define I2C_CR_MASTER10_SHIFT                   (4)
#define I2C_CR_MASTER10_MASK                    (0x1U << I2C_CR_MASTER10_SHIFT)
#define I2C_CR_MASTER10(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_CR_MASTER10_SHIFT)) & I2C_CR_MASTER10_MASK)

#define I2C_CR_SLAVE10_SHIFT                    (3)
#define I2C_CR_SLAVE10_MASK                     (0x1U << I2C_CR_SLAVE10_SHIFT)
#define I2C_CR_SLAVE10(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_CR_SLAVE10_SHIFT)) & I2C_CR_SLAVE10_MASK)

#define I2C_CR_SPEED_SHIFT                      (1)
#define I2C_CR_SPEED_MASK                       (0x3U << I2C_CR_SPEED_SHIFT)
#define I2C_CR_SPEED(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_CR_SPEED_SHIFT)) & I2C_CR_SPEED_MASK)

#define I2C_CR_MASTER_SHIFT                     (0)
#define I2C_CR_MASTER_MASK                      (0x1U << I2C_CR_MASTER_SHIFT)
#define I2C_CR_MASTER(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_CR_MASTER_SHIFT)) & I2C_CR_MASTER_MASK)

/*!
 * @brief I2C_TAR Register Bit Definition
 */

#define I2C_TAR_SPECIAL_SHIFT                   (11)
#define I2C_TAR_SPECIAL_MASK                    (0x1U << I2C_TAR_SPECIAL_SHIFT)
#define I2C_TAR_SPECIAL(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_TAR_SPECIAL_SHIFT)) & I2C_TAR_SPECIAL_MASK)

#define I2C_TAR_GC_SHIFT                        (10)
#define I2C_TAR_GC_MASK                         (0x1U << I2C_TAR_GC_SHIFT)
#define I2C_TAR_GC(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_TAR_GC_SHIFT)) & I2C_TAR_GC_MASK)

#define I2C_TAR_ADDR_SHIFT                      (0)
#define I2C_TAR_ADDR_MASK                       (0x3FFU << I2C_TAR_ADDR_SHIFT)
#define I2C_TAR_ADDR(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_TAR_ADDR_SHIFT)) & I2C_TAR_ADDR_MASK)

/*!
 * @brief I2C_SAR Register Bit Definition
 */

#define I2C_SAR_ADDR_SHIFT                      (0)
#define I2C_SAR_ADDR_MASK                       (0x3FFU << I2C_SAR_ADDR_SHIFT)
#define I2C_SAR_ADDR(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_SAR_ADDR_SHIFT)) & I2C_SAR_ADDR_MASK)

/*!
 * @brief I2C_DR Register Bit Definition
 */

#define I2C_DR_CMD_SHIFT                        (8)
#define I2C_DR_CMD_MASK                         (0x1U << I2C_DR_CMD_SHIFT)
#define I2C_DR_CMD(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_DR_CMD_SHIFT)) & I2C_DR_CMD_MASK)

#define I2C_DR_DAT_SHIFT                        (0)
#define I2C_DR_DAT_MASK                         (0xFFU << I2C_DR_DAT_SHIFT)
#define I2C_DR_DAT(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_DR_DAT_SHIFT)) & I2C_DR_DAT_MASK)

/*!
 * @brief I2C_SSHR Register Bit Definition
 */

#define I2C_SSHR_CNT_SHIFT                      (0)
#define I2C_SSHR_CNT_MASK                       (0xFFFFU << I2C_SSHR_CNT_SHIFT)
#define I2C_SSHR_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_SSHR_CNT_SHIFT)) & I2C_SSHR_CNT_MASK)

/*!
 * @brief I2C_SSLR Register Bit Definition
 */

#define I2C_SSLR_CNT_SHIFT                      (0)
#define I2C_SSLR_CNT_MASK                       (0xFFFFU << I2C_SSLR_CNT_SHIFT)
#define I2C_SSLR_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_SSLR_CNT_SHIFT)) & I2C_SSLR_CNT_MASK)

/*!
 * @brief I2C_FSHR Register Bit Definition
 */

#define I2C_FSHR_CNT_SHIFT                      (0)
#define I2C_FSHR_CNT_MASK                       (0xFFFFU << I2C_FSHR_CNT_SHIFT)
#define I2C_FSHR_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_FSHR_CNT_SHIFT)) & I2C_FSHR_CNT_MASK)

/*!
 * @brief I2C_FSLR Register Bit Definition
 */

#define I2C_FSLR_CNT_SHIFT                      (0)
#define I2C_FSLR_CNT_MASK                       (0xFFFFU << I2C_FSLR_CNT_SHIFT)
#define I2C_FSLR_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_FSLR_CNT_SHIFT)) & I2C_FSLR_CNT_MASK)

/*!
 * @brief I2C_ISR Register Bit Definition
 */

#define I2C_ISR_RGC_SHIFT                       (11)
#define I2C_ISR_RGC_MASK                        (0x1U << I2C_ISR_RGC_SHIFT)
#define I2C_ISR_RGC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RGC_SHIFT)) & I2C_ISR_RGC_MASK)

#define I2C_ISR_RSTART_SHIFT                    (10)
#define I2C_ISR_RSTART_MASK                     (0x1U << I2C_ISR_RSTART_SHIFT)
#define I2C_ISR_RSTART(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RSTART_SHIFT)) & I2C_ISR_RSTART_MASK)

#define I2C_ISR_RSTOP_SHIFT                     (9)
#define I2C_ISR_RSTOP_MASK                      (0x1U << I2C_ISR_RSTOP_SHIFT)
#define I2C_ISR_RSTOP(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RSTOP_SHIFT)) & I2C_ISR_RSTOP_MASK)

#define I2C_ISR_RACTIV_SHIFT                    (8)
#define I2C_ISR_RACTIV_MASK                     (0x1U << I2C_ISR_RACTIV_SHIFT)
#define I2C_ISR_RACTIV(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RACTIV_SHIFT)) & I2C_ISR_RACTIV_MASK)

#define I2C_ISR_RRXDONE_SHIFT                   (7)
#define I2C_ISR_RRXDONE_MASK                    (0x1U << I2C_ISR_RRXDONE_SHIFT)
#define I2C_ISR_RRXDONE(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RRXDONE_SHIFT)) & I2C_ISR_RRXDONE_MASK)

#define I2C_ISR_RTXABRT_SHIFT                   (6)
#define I2C_ISR_RTXABRT_MASK                    (0x1U << I2C_ISR_RTXABRT_SHIFT)
#define I2C_ISR_RTXABRT(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RTXABRT_SHIFT)) & I2C_ISR_RTXABRT_MASK)

#define I2C_ISR_RRDREQ_SHIFT                    (5)
#define I2C_ISR_RRDREQ_MASK                     (0x1U << I2C_ISR_RRDREQ_SHIFT)
#define I2C_ISR_RRDREQ(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RRDREQ_SHIFT)) & I2C_ISR_RRDREQ_MASK)

#define I2C_ISR_RTXEMPTY_SHIFT                  (4)
#define I2C_ISR_RTXEMPTY_MASK                   (0x1U << I2C_ISR_RTXEMPTY_SHIFT)
#define I2C_ISR_RTXEMPTY(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RTXEMPTY_SHIFT)) & I2C_ISR_RTXEMPTY_MASK)

#define I2C_ISR_RTXOVER_SHIFT                   (3)
#define I2C_ISR_RTXOVER_MASK                    (0x1U << I2C_ISR_RTXOVER_SHIFT)
#define I2C_ISR_RTXOVER(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RTXOVER_SHIFT)) & I2C_ISR_RTXOVER_MASK)

#define I2C_ISR_RRXFULL_SHIFT                   (2)
#define I2C_ISR_RRXFULL_MASK                    (0x1U << I2C_ISR_RRXFULL_SHIFT)
#define I2C_ISR_RRXFULL(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RRXFULL_SHIFT)) & I2C_ISR_RRXFULL_MASK)

#define I2C_ISR_RRXOVER_SHIFT                   (1)
#define I2C_ISR_RRXOVER_MASK                    (0x1U << I2C_ISR_RRXOVER_SHIFT)
#define I2C_ISR_RRXOVER(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RRXOVER_SHIFT)) & I2C_ISR_RRXOVER_MASK)

#define I2C_ISR_RRXUNDER_SHIFT                  (0)
#define I2C_ISR_RRXUNDER_MASK                   (0x1U << I2C_ISR_RRXUNDER_SHIFT)
#define I2C_ISR_RRXUNDER(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_ISR_RRXUNDER_SHIFT)) & I2C_ISR_RRXUNDER_MASK)

/*!
 * @brief I2C_IMR Register Bit Definition
 */

#define I2C_IMR_MGC_SHIFT                       (11)
#define I2C_IMR_MGC_MASK                        (0x1U << I2C_IMR_MGC_SHIFT)
#define I2C_IMR_MGC(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MGC_SHIFT)) & I2C_IMR_MGC_MASK)

#define I2C_IMR_MSTART_SHIFT                    (10)
#define I2C_IMR_MSTART_MASK                     (0x1U << I2C_IMR_MSTART_SHIFT)
#define I2C_IMR_MSTART(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MSTART_SHIFT)) & I2C_IMR_MSTART_MASK)

#define I2C_IMR_MSTOP_SHIFT                     (9)
#define I2C_IMR_MSTOP_MASK                      (0x1U << I2C_IMR_MSTOP_SHIFT)
#define I2C_IMR_MSTOP(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MSTOP_SHIFT)) & I2C_IMR_MSTOP_MASK)

#define I2C_IMR_MACTIV_SHIFT                    (8)
#define I2C_IMR_MACTIV_MASK                     (0x1U << I2C_IMR_MACTIV_SHIFT)
#define I2C_IMR_MACTIV(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MACTIV_SHIFT)) & I2C_IMR_MACTIV_MASK)

#define I2C_IMR_MRXDONE_SHIFT                   (7)
#define I2C_IMR_MRXDONE_MASK                    (0x1U << I2C_IMR_MRXDONE_SHIFT)
#define I2C_IMR_MRXDONE(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MRXDONE_SHIFT)) & I2C_IMR_MRXDONE_MASK)

#define I2C_IMR_MTXABRT_SHIFT                   (6)
#define I2C_IMR_MTXABRT_MASK                    (0x1U << I2C_IMR_MTXABRT_SHIFT)
#define I2C_IMR_MTXABRT(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MTXABRT_SHIFT)) & I2C_IMR_MTXABRT_MASK)

#define I2C_IMR_MRDREQ_SHIFT                    (5)
#define I2C_IMR_MRDREQ_MASK                     (0x1U << I2C_IMR_MRDREQ_SHIFT)
#define I2C_IMR_MRDREQ(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MRDREQ_SHIFT)) & I2C_IMR_MRDREQ_MASK)

#define I2C_IMR_MTXEMPTY_SHIFT                  (4)
#define I2C_IMR_MTXEMPTY_MASK                   (0x1U << I2C_IMR_MTXEMPTY_SHIFT)
#define I2C_IMR_MTXEMPTY(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MTXEMPTY_SHIFT)) & I2C_IMR_MTXEMPTY_MASK)

#define I2C_IMR_MTXOVER_SHIFT                   (3)
#define I2C_IMR_MTXOVER_MASK                    (0x1U << I2C_IMR_MTXOVER_SHIFT)
#define I2C_IMR_MTXOVER(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MTXOVER_SHIFT)) & I2C_IMR_MTXOVER_MASK)

#define I2C_IMR_MRXFULL_SHIFT                   (2)
#define I2C_IMR_MRXFULL_MASK                    (0x1U << I2C_IMR_MRXFULL_SHIFT)
#define I2C_IMR_MRXFULL(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MRXFULL_SHIFT)) & I2C_IMR_MRXFULL_MASK)

#define I2C_IMR_MRXOVER_SHIFT                   (1)
#define I2C_IMR_MRXOVER_MASK                    (0x1U << I2C_IMR_MRXOVER_SHIFT)
#define I2C_IMR_MRXOVER(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MRXOVER_SHIFT)) & I2C_IMR_MRXOVER_MASK)

#define I2C_IMR_MRXUNDER_SHIFT                  (0)
#define I2C_IMR_MRXUNDER_MASK                   (0x1U << I2C_IMR_MRXUNDER_SHIFT)
#define I2C_IMR_MRXUNDER(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_IMR_MRXUNDER_SHIFT)) & I2C_IMR_MRXUNDER_MASK)

/*!
 * @brief I2C_RAWISR Register Bit Definition
 */

#define I2C_RAWISR_GC_SHIFT                     (11)
#define I2C_RAWISR_GC_MASK                      (0x1U << I2C_RAWISR_GC_SHIFT)
#define I2C_RAWISR_GC(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_GC_SHIFT)) & I2C_RAWISR_GC_MASK)

#define I2C_RAWISR_START_SHIFT                  (10)
#define I2C_RAWISR_START_MASK                   (0x1U << I2C_RAWISR_START_SHIFT)
#define I2C_RAWISR_START(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_START_SHIFT)) & I2C_RAWISR_START_MASK)

#define I2C_RAWISR_STOP_SHIFT                   (9)
#define I2C_RAWISR_STOP_MASK                    (0x1U << I2C_RAWISR_STOP_SHIFT)
#define I2C_RAWISR_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_STOP_SHIFT)) & I2C_RAWISR_STOP_MASK)

#define I2C_RAWISR_ACTIV_SHIFT                  (8)
#define I2C_RAWISR_ACTIV_MASK                   (0x1U << I2C_RAWISR_ACTIV_SHIFT)
#define I2C_RAWISR_ACTIV(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_ACTIV_SHIFT)) & I2C_RAWISR_ACTIV_MASK)

#define I2C_RAWISR_RXDONE_SHIFT                 (7)
#define I2C_RAWISR_RXDONE_MASK                  (0x1U << I2C_RAWISR_RXDONE_SHIFT)
#define I2C_RAWISR_RXDONE(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_RXDONE_SHIFT)) & I2C_RAWISR_RXDONE_MASK)

#define I2C_RAWISR_TXABRT_SHIFT                 (6)
#define I2C_RAWISR_TXABRT_MASK                  (0x1U << I2C_RAWISR_TXABRT_SHIFT)
#define I2C_RAWISR_TXABRT(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_TXABRT_SHIFT)) & I2C_RAWISR_TXABRT_MASK)

#define I2C_RAWISR_RDREQ_SHIFT                  (5)
#define I2C_RAWISR_RDREQ_MASK                   (0x1U << I2C_RAWISR_RDREQ_SHIFT)
#define I2C_RAWISR_RDREQ(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_RDREQ_SHIFT)) & I2C_RAWISR_RDREQ_MASK)

#define I2C_RAWISR_TXEMPTY_SHIFT                (4)
#define I2C_RAWISR_TXEMPTY_MASK                 (0x1U << I2C_RAWISR_TXEMPTY_SHIFT)
#define I2C_RAWISR_TXEMPTY(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_TXEMPTY_SHIFT)) & I2C_RAWISR_TXEMPTY_MASK)

#define I2C_RAWISR_TXOVER_SHIFT                 (3)
#define I2C_RAWISR_TXOVER_MASK                  (0x1U << I2C_RAWISR_TXOVER_SHIFT)
#define I2C_RAWISR_TXOVER(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_TXOVER_SHIFT)) & I2C_RAWISR_TXOVER_MASK)

#define I2C_RAWISR_RXFULL_SHIFT                 (2)
#define I2C_RAWISR_RXFULL_MASK                  (0x1U << I2C_RAWISR_RXFULL_SHIFT)
#define I2C_RAWISR_RXFULL(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_RXFULL_SHIFT)) & I2C_RAWISR_RXFULL_MASK)

#define I2C_RAWISR_RXOVER_SHIFT                 (1)
#define I2C_RAWISR_RXOVER_MASK                  (0x1U << I2C_RAWISR_RXOVER_SHIFT)
#define I2C_RAWISR_RXOVER(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_RXOVER_SHIFT)) & I2C_RAWISR_RXOVER_MASK)

#define I2C_RAWISR_RXUNDER_SHIFT                (0)
#define I2C_RAWISR_RXUNDER_MASK                 (0x1U << I2C_RAWISR_RXUNDER_SHIFT)
#define I2C_RAWISR_RXUNDER(x)                   (((uint32_t)(((uint32_t)(x)) << I2C_RAWISR_RXUNDER_SHIFT)) & I2C_RAWISR_RXUNDER_MASK)

/*!
 * @brief I2C_RXTLR Register Bit Definition
 */

#define I2C_RXTLR_TL_SHIFT                      (0)
#define I2C_RXTLR_TL_MASK                       (0xFFU << I2C_RXTLR_TL_SHIFT)
#define I2C_RXTLR_TL(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_RXTLR_TL_SHIFT)) & I2C_RXTLR_TL_MASK)

/*!
 * @brief I2C_TXTLR Register Bit Definition
 */

#define I2C_TXTLR_TL_SHIFT                      (0)
#define I2C_TXTLR_TL_MASK                       (0xFFU << I2C_TXTLR_TL_SHIFT)
#define I2C_TXTLR_TL(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_TXTLR_TL_SHIFT)) & I2C_TXTLR_TL_MASK)

/*!
 * @brief I2C_ICR Register Bit Definition
 */

#define I2C_ICR_ICR_SHIFT                       (0)
#define I2C_ICR_ICR_MASK                        (0x1U << I2C_ICR_ICR_SHIFT)
#define I2C_ICR_ICR(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_ICR_ICR_SHIFT)) & I2C_ICR_ICR_MASK)

/*!
 * @brief I2C_RX_UNDER Register Bit Definition
 */

#define I2C_RXUNDER_RXUNDER_SHIFT               (0)
#define I2C_RXUNDER_RXUNDER_MASK                (0x1U << I2C_RXUNDER_RXUNDER_SHIFT)
#define I2C_RXUNDER_RXUNDER(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_RXUNDER_RXUNDER_SHIFT)) & I2C_RXUNDER_RXUNDER_MASK)

/*!
 * @brief I2C_RX_OVER Register Bit Definition
 */

#define I2C_RXOVER_RXOVER_SHIFT                 (0)
#define I2C_RXOVER_RXOVER_MASK                  (0x1U << I2C_RXOVER_RXOVER_SHIFT)
#define I2C_RXOVER_RXOVER(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RXOVER_RXOVER_SHIFT)) & I2C_RXOVER_RXOVER_MASK)

/*!
 * @brief I2C_TX_OVER Register Bit Definition
 */

#define I2C_TXOVER_TXOVER_SHIFT                 (0)
#define I2C_TXOVER_TXOVER_MASK                  (0x1U << I2C_TXOVER_TXOVER_SHIFT)
#define I2C_TXOVER_TXOVER(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_TXOVER_TXOVER_SHIFT)) & I2C_TXOVER_TXOVER_MASK)

/*!
 * @brief I2C_RD_REQ Register Bit Definition
 */

#define I2C_RDREQ_RDREQ_SHIFT                   (0)
#define I2C_RDREQ_RDREQ_MASK                    (0x1U << I2C_RDREQ_RDREQ_SHIFT)
#define I2C_RDREQ_RDREQ(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_RDREQ_RDREQ_SHIFT)) & I2C_RDREQ_RDREQ_MASK)

/*!
 * @brief I2C_TX_ABRT Register Bit Definition
 */

#define I2C_TXABRT_TXABRT_SHIFT                 (0)
#define I2C_TXABRT_TXABRT_MASK                  (0x1U << I2C_TXABRT_TXABRT_SHIFT)
#define I2C_TXABRT_TXABRT(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_TXABRT_TXABRT_SHIFT)) & I2C_TXABRT_TXABRT_MASK)

/*!
 * @brief I2C_RX_DONE Register Bit Definition
 */

#define I2C_RXDONE_RXDONE_SHIFT                 (0)
#define I2C_RXDONE_RXDONE_MASK                  (0x1U << I2C_RXDONE_RXDONE_SHIFT)
#define I2C_RXDONE_RXDONE(x)                    (((uint32_t)(((uint32_t)(x)) << I2C_RXDONE_RXDONE_SHIFT)) & I2C_RXDONE_RXDONE_MASK)

/*!
 * @brief I2C_ACTIV Register Bit Definition
 */

#define I2C_ACTIV_ACTIV_SHIFT                   (0)
#define I2C_ACTIV_ACTIV_MASK                    (0x1U << I2C_ACTIV_ACTIV_SHIFT)
#define I2C_ACTIV_ACTIV(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_ACTIV_ACTIV_SHIFT)) & I2C_ACTIV_ACTIV_MASK)

/*!
 * @brief I2C_STOP Register Bit Definition
 */

#define I2C_STOP_STOP_SHIFT                     (0)
#define I2C_STOP_STOP_MASK                      (0x1U << I2C_STOP_STOP_SHIFT)
#define I2C_STOP_STOP(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_STOP_STOP_SHIFT)) & I2C_STOP_STOP_MASK)

/*!
 * @brief I2C_START Register Bit Definition
 */

#define I2C_START_START_SHIFT                   (0)
#define I2C_START_START_MASK                    (0x1U << I2C_START_START_SHIFT)
#define I2C_START_START(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_START_START_SHIFT)) & I2C_START_START_MASK)

/*!
 * @brief I2C_GC Register Bit Definition
 */

#define I2C_GC_GC_SHIFT                         (0)
#define I2C_GC_GC_MASK                          (0x1U << I2C_GC_GC_SHIFT)
#define I2C_GC_GC(x)                            (((uint32_t)(((uint32_t)(x)) << I2C_GC_GC_SHIFT)) & I2C_GC_GC_MASK)

/*!
 * @brief I2C_ENR Register Bit Definition
 */

#define I2C_ENR_ABORT_SHIFT                     (1)
#define I2C_ENR_ABORT_MASK                      (0x1U << I2C_ENR_ABORT_SHIFT)
#define I2C_ENR_ABORT(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_ENR_ABORT_SHIFT)) & I2C_ENR_ABORT_MASK)

#define I2C_ENR_ENABLE_SHIFT                    (0)
#define I2C_ENR_ENABLE_MASK                     (0x1U << I2C_ENR_ENABLE_SHIFT)
#define I2C_ENR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x)) << I2C_ENR_ENABLE_SHIFT)) & I2C_ENR_ENABLE_MASK)

/*!
 * @brief I2C_SR Register Bit Definition
 */

#define I2C_SR_SLVACTIV_SHIFT                   (6)
#define I2C_SR_SLVACTIV_MASK                    (0x1U << I2C_SR_SLVACTIV_SHIFT)
#define I2C_SR_SLVACTIV(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_SR_SLVACTIV_SHIFT)) & I2C_SR_SLVACTIV_MASK)

#define I2C_SR_MSTACTIV_SHIFT                   (5)
#define I2C_SR_MSTACTIV_MASK                    (0x1U << I2C_SR_MSTACTIV_SHIFT)
#define I2C_SR_MSTACTIV(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_SR_MSTACTIV_SHIFT)) & I2C_SR_MSTACTIV_MASK)

#define I2C_SR_RFF_SHIFT                        (4)
#define I2C_SR_RFF_MASK                         (0x1U << I2C_SR_RFF_SHIFT)
#define I2C_SR_RFF(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_SR_RFF_SHIFT)) & I2C_SR_RFF_MASK)

#define I2C_SR_RFNE_SHIFT                       (3)
#define I2C_SR_RFNE_MASK                        (0x1U << I2C_SR_RFNE_SHIFT)
#define I2C_SR_RFNE(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_SR_RFNE_SHIFT)) & I2C_SR_RFNE_MASK)

#define I2C_SR_TFE_SHIFT                        (2)
#define I2C_SR_TFE_MASK                         (0x1U << I2C_SR_TFE_SHIFT)
#define I2C_SR_TFE(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_SR_TFE_SHIFT)) & I2C_SR_TFE_MASK)

#define I2C_SR_TFNF_SHIFT                       (1)
#define I2C_SR_TFNF_MASK                        (0x1U << I2C_SR_TFNF_SHIFT)
#define I2C_SR_TFNF(x)                          (((uint32_t)(((uint32_t)(x)) << I2C_SR_TFNF_SHIFT)) & I2C_SR_TFNF_MASK)

#define I2C_SR_ACTIV_SHIFT                      (0)
#define I2C_SR_ACTIV_MASK                       (0x1U << I2C_SR_ACTIV_SHIFT)
#define I2C_SR_ACTIV(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_SR_ACTIV_SHIFT)) & I2C_SR_ACTIV_MASK)

/*!
 * @brief I2C_TXFLR Register Bit Definition
 */

#define I2C_TXFLR_CNT_SHIFT                     (0)
#define I2C_TXFLR_CNT_MASK                      (0x3U << I2C_TXFLR_CNT_SHIFT)
#define I2C_TXFLR_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_TXFLR_CNT_SHIFT)) & I2C_TXFLR_CNT_MASK)

/*!
 * @brief I2C_RXFLR Register Bit Definition
 */

#define I2C_RXFLR_CNT_SHIFT                     (0)
#define I2C_RXFLR_CNT_MASK                      (0x3U << I2C_RXFLR_CNT_SHIFT)
#define I2C_RXFLR_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_RXFLR_CNT_SHIFT)) & I2C_RXFLR_CNT_MASK)

/*!
 * @brief I2C_HOLD Register Bit Definition
 */

#define I2C_HOLD_RXHOLD_SHIFT                   (16)
#define I2C_HOLD_RXHOLD_MASK                    (0xFFU << I2C_HOLD_RXHOLD_SHIFT)
#define I2C_HOLD_RXHOLD(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_HOLD_RXHOLD_SHIFT)) & I2C_HOLD_RXHOLD_MASK)

#define I2C_HOLD_TXHOLD_SHIFT                   (0)
#define I2C_HOLD_TXHOLD_MASK                    (0xFFFFU << I2C_HOLD_TXHOLD_SHIFT)
#define I2C_HOLD_TXHOLD(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_HOLD_TXHOLD_SHIFT)) & I2C_HOLD_TXHOLD_MASK)

/*!
 * @brief I2C_DMA Register Bit Definition
 */

#define I2C_DMA_TXEN_SHIFT                      (1)
#define I2C_DMA_TXEN_MASK                       (0x1U << I2C_DMA_TXEN_SHIFT)
#define I2C_DMA_TXEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_DMA_TXEN_SHIFT)) & I2C_DMA_TXEN_MASK)

#define I2C_DMA_RXEN_SHIFT                      (0)
#define I2C_DMA_RXEN_MASK                       (0x1U << I2C_DMA_RXEN_SHIFT)
#define I2C_DMA_RXEN(x)                         (((uint32_t)(((uint32_t)(x)) << I2C_DMA_RXEN_SHIFT)) & I2C_DMA_RXEN_MASK)

/*!
 * @brief I2C_SETUP Register Bit Definition
 */

#define I2C_SETUP_CNT_SHIFT                     (0)
#define I2C_SETUP_CNT_MASK                      (0xFFU << I2C_SETUP_CNT_SHIFT)
#define I2C_SETUP_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << I2C_SETUP_CNT_SHIFT)) & I2C_SETUP_CNT_MASK)

/*!
 * @brief I2C_GCR Register Bit Definition
 */

#define I2C_GCR_GC_SHIFT                        (0)
#define I2C_GCR_GC_MASK                         (0x1U << I2C_GCR_GC_SHIFT)
#define I2C_GCR_GC(x)                           (((uint32_t)(((uint32_t)(x)) << I2C_GCR_GC_SHIFT)) & I2C_GCR_GC_MASK)

/*!
 * @brief I2C_SLVMASK Register Bit Definition
 */

#define I2C_SLVMASK_MASK_SHIFT                  (0)
#define I2C_SLVMASK_MASK_MASK                   (0x3FFU << I2C_SLVMASK_MASK_SHIFT)
#define I2C_SLVMASK_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_SLVMASK_MASK_SHIFT)) & I2C_SLVMASK_MASK_MASK)

/*!
 * @brief I2C_SLVRCVADDR Register Bit Definition
 */

#define I2C_SLVRCVADDR_ADDR_SHIFT               (0)
#define I2C_SLVRCVADDR_ADDR_MASK                (0x3FFU << I2C_SLVRCVADDR_ADDR_SHIFT)
#define I2C_SLVRCVADDR_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_SLVRCVADDR_ADDR_SHIFT)) & I2C_SLVRCVADDR_ADDR_MASK)

/*!
 * @}
 */ /* end of group I2C_Register_Masks */
/******************************************************************************
 *I2C Instance
*******************************************************************************/

#define I2C1                 ((I2C_Type*)I2C1_BASE)

/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */



/*!
 * @addtogroup I3C_Peripheral_Access_Layer I3C Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * I3C Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t Reserved0;                                                    ///< Reserved
    __IO uint32_t CONFIG;                                                       ///< Configuration register                       offset: 0x004
    __IO uint32_t STATUS;                                                       ///< Status register                              offset: 0x008
    __IO uint32_t CTRL;                                                         ///< Control register                             offset: 0x00C
    __IO uint32_t INTSET;                                                       ///< Interrupt enable set register                offset: 0x010
    __IO uint32_t INTCLR;                                                       ///< Interrupt enable clear register              offset: 0x014
    __IO uint32_t INTMSK;                                                       ///< Interrupt masked register                    offset: 0x018
    __IO uint32_t ERWAR;                                                        ///< Error and warning register                   offset: 0x01C
    __IO uint32_t DMACTRL;                                                      ///< DMA control register                         offset: 0x020
    __IO uint32_t Reserved1[2];                                                 ///< Reserved
    __IO uint32_t DATACTRL;                                                     ///< Data control register                        offset: 0x02C
    __IO uint32_t WDATAB;                                                       ///< Write byte register                          offset: 0x030
    __IO uint32_t WDATABE;                                                      ///< Write byte as end register                   offset: 0x034
    __IO uint32_t WDATAH;                                                       ///< Write halfword register                      offset: 0x038
    __IO uint32_t WDATAHE;                                                      ///< Write halfword as end register               offset: 0x03C
    __IO uint32_t RDATAB;                                                       ///< Read byte register                           offset: 0x040
    __IO uint32_t Reserved2[1];                                                 ///< Reserved
    __IO uint32_t RDATAH;                                                       ///< Read halfword register                       offset: 0x048
    __IO uint32_t Reserved3[2];                                                 ///< Reserved
    __IO uint32_t WDATAB1;                                                      ///< Byte-only Write byte register                offset: 0x054
    __IO uint32_t Reserved4[1];                                                 ///< Reserved
    __IO uint32_t CAPABILITIES2;                                                ///< Capabilities 2 register                      offset: 0x05C
    __IO uint32_t CAPABILITIES;                                                 ///< Capabilities register                        offset: 0x060
    __IO uint32_t DYNADDR;                                                      ///< Dynamic address register                     offset: 0x064
    __IO uint32_t MAXLIMITS;                                                    ///< Maximum limits register                      offset: 0x068
    __IO uint32_t IDPARTNO;                                                     ///< Part number ID register                      offset: 0x06C
    __IO uint32_t IDEXT;                                                        ///< ID components register                       offset: 0x070
    __IO uint32_t VENDORID;                                                     ///< Vendor ID register                           offset: 0x074
    __IO uint32_t Reserved5[98];                                                ///< Reserved
    __IO uint32_t DIV;                                                          ///< Division register                            offset: 0x200
    __IO uint32_t SPKLEN;                                                       ///< Filter register                              offset: 0x204
} I3C_Type;

/*******************************************************************************
 * I3C Type
 ******************************************************************************/

/*!
 * @addtogroup I3C_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief I3C_CONFIG Register Bit Definition
 */

#define I3C_CONFIG_SADDR_SHIFT                  (25)
#define I3C_CONFIG_SADDR_MASK                   (0x7FU << I3C_CONFIG_SADDR_SHIFT)
#define I3C_CONFIG_SADDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_SADDR_SHIFT)) & I3C_CONFIG_SADDR_MASK)

#define I3C_CONFIG_BAMAT_SHIFT                  (16)
#define I3C_CONFIG_BAMAT_MASK                   (0xFFU << I3C_CONFIG_BAMAT_SHIFT)
#define I3C_CONFIG_BAMAT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_BAMAT_SHIFT)) & I3C_CONFIG_BAMAT_MASK)

#define I3C_CONFIG_OFFLINE_SHIFT                (9)
#define I3C_CONFIG_OFFLINE_MASK                 (0x1U << I3C_CONFIG_OFFLINE_SHIFT)
#define I3C_CONFIG_OFFLINE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_OFFLINE_SHIFT)) & I3C_CONFIG_OFFLINE_MASK)

#define I3C_CONFIG_IDRAND_SHIFT                 (8)
#define I3C_CONFIG_IDRAND_MASK                  (0x1U << I3C_CONFIG_IDRAND_SHIFT)
#define I3C_CONFIG_IDRAND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_IDRAND_SHIFT)) & I3C_CONFIG_IDRAND_MASK)

#define I3C_CONFIG_S0IGNORE_SHIFT               (3)
#define I3C_CONFIG_S0IGNORE_MASK                (0x1U << I3C_CONFIG_S0IGNORE_SHIFT)
#define I3C_CONFIG_S0IGNORE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_S0IGNORE_SHIFT)) & I3C_CONFIG_S0IGNORE_MASK)

#define I3C_CONFIG_MATSS_SHIFT                  (2)
#define I3C_CONFIG_MATSS_MASK                   (0x1U << I3C_CONFIG_MATSS_SHIFT)
#define I3C_CONFIG_MATSS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_MATSS_SHIFT)) & I3C_CONFIG_MATSS_MASK)

#define I3C_CONFIG_NACK_SHIFT                   (1)
#define I3C_CONFIG_NACK_MASK                    (0x1U << I3C_CONFIG_NACK_SHIFT)
#define I3C_CONFIG_NACK(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_NACK_SHIFT)) & I3C_CONFIG_NACK_MASK)

#define I3C_CONFIG_SLVENA_SHIFT                 (0)
#define I3C_CONFIG_SLVENA_MASK                  (0x1U << I3C_CONFIG_SLVENA_SHIFT)
#define I3C_CONFIG_SLVENA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_CONFIG_SLVENA_SHIFT)) & I3C_CONFIG_SLVENA_MASK)

/*!
 * @brief I3C_STATUS Register Bit Definition
 */

#define I3C_STATUS_ACTSTATE_SHIFT               (28)
#define I3C_STATUS_ACTSTATE_MASK                (0x3U << I3C_STATUS_ACTSTATE_SHIFT)
#define I3C_STATUS_ACTSTATE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_ACTSTATE_SHIFT)) & I3C_STATUS_ACTSTATE_MASK)

#define I3C_STATUS_HJDIS_SHIFT                  (27)
#define I3C_STATUS_HJDIS_MASK                   (0x1U << I3C_STATUS_HJDIS_SHIFT)
#define I3C_STATUS_HJDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_HJDIS_SHIFT)) & I3C_STATUS_HJDIS_MASK)

#define I3C_STATUS_MRDIS_SHIFT                  (25)
#define I3C_STATUS_MRDIS_MASK                   (0x1U << I3C_STATUS_MRDIS_SHIFT)
#define I3C_STATUS_MRDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_MRDIS_SHIFT)) & I3C_STATUS_MRDIS_MASK)

#define I3C_STATUS_IBIDIS_SHIFT                 (24)
#define I3C_STATUS_IBIDIS_MASK                  (0x1U << I3C_STATUS_IBIDIS_SHIFT)
#define I3C_STATUS_IBIDIS(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_IBIDIS_SHIFT)) & I3C_STATUS_IBIDIS_MASK)

#define I3C_STATUS_EVDET_SHIFT                  (20)
#define I3C_STATUS_EVDET_MASK                   (0x3U << I3C_STATUS_EVDET_SHIFT)
#define I3C_STATUS_EVDET(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_EVDET_SHIFT)) & I3C_STATUS_EVDET_MASK)

#define I3C_STATUS_EVENT_SHIFT                  (18)
#define I3C_STATUS_EVENT_MASK                   (0x1U << I3C_STATUS_EVENT_SHIFT)
#define I3C_STATUS_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_EVENT_SHIFT)) & I3C_STATUS_EVENT_MASK)

#define I3C_STATUS_CHANDLED_SHIFT               (17)
#define I3C_STATUS_CHANDLED_MASK                (0x1U << I3C_STATUS_CHANDLED_SHIFT)
#define I3C_STATUS_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_CHANDLED_SHIFT)) & I3C_STATUS_CHANDLED_MASK)

#define I3C_STATUS_ERWAR_SHIFT                  (15)
#define I3C_STATUS_ERWAR_MASK                   (0x1U << I3C_STATUS_ERWAR_SHIFT)
#define I3C_STATUS_ERWAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_ERWAR_SHIFT)) & I3C_STATUS_ERWAR_MASK)

#define I3C_STATUS_CCC_SHIFT                    (14)
#define I3C_STATUS_CCC_MASK                     (0x1U << I3C_STATUS_CCC_SHIFT)
#define I3C_STATUS_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_CCC_SHIFT)) & I3C_STATUS_CCC_MASK)

#define I3C_STATUS_DACHG_SHIFT                  (13)
#define I3C_STATUS_DACHG_MASK                   (0x1U << I3C_STATUS_DACHG_SHIFT)
#define I3C_STATUS_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_DACHG_SHIFT)) & I3C_STATUS_DACHG_MASK)

#define I3C_STATUS_TXNF_SHIFT                   (12)
#define I3C_STATUS_TXNF_MASK                    (0x1U << I3C_STATUS_TXNF_SHIFT)
#define I3C_STATUS_TXNF(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_TXNF_SHIFT)) & I3C_STATUS_TXNF_MASK)

#define I3C_STATUS_RXPEND_SHIFT                 (11)
#define I3C_STATUS_RXPEND_MASK                  (0x1U << I3C_STATUS_RXPEND_SHIFT)
#define I3C_STATUS_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_RXPEND_SHIFT)) & I3C_STATUS_RXPEND_MASK)

#define I3C_STATUS_STOP_SHIFT                   (10)
#define I3C_STATUS_STOP_MASK                    (0x1U << I3C_STATUS_STOP_SHIFT)
#define I3C_STATUS_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STOP_SHIFT)) & I3C_STATUS_STOP_MASK)

#define I3C_STATUS_MATED_SHIFT                  (9)
#define I3C_STATUS_MATED_MASK                   (0x1U << I3C_STATUS_MATED_SHIFT)
#define I3C_STATUS_MATED(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_MATED_SHIFT)) & I3C_STATUS_MATED_MASK)

#define I3C_STATUS_START_SHIFT                  (8)
#define I3C_STATUS_START_MASK                   (0x1U << I3C_STATUS_START_SHIFT)
#define I3C_STATUS_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_START_SHIFT)) & I3C_STATUS_START_MASK)

#define I3C_STATUS_STHDR_SHIFT                  (6)
#define I3C_STATUS_STHDR_MASK                   (0x1U << I3C_STATUS_STHDR_SHIFT)
#define I3C_STATUS_STHDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STHDR_SHIFT)) & I3C_STATUS_STHDR_MASK)

#define I3C_STATUS_STDAA_SHIFT                  (5)
#define I3C_STATUS_STDAA_MASK                   (0x1U << I3C_STATUS_STDAA_SHIFT)
#define I3C_STATUS_STDAA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STDAA_SHIFT)) & I3C_STATUS_STDAA_MASK)

#define I3C_STATUS_STREQWR_SHIFT                (4)
#define I3C_STATUS_STREQWR_MASK                 (0x1U << I3C_STATUS_STREQWR_SHIFT)
#define I3C_STATUS_STREQWR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STREQWR_SHIFT)) & I3C_STATUS_STREQWR_MASK)

#define I3C_STATUS_STREQRD_SHIFT                (3)
#define I3C_STATUS_STREQRD_MASK                 (0x1U << I3C_STATUS_STREQRD_SHIFT)
#define I3C_STATUS_STREQRD(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STREQRD_SHIFT)) & I3C_STATUS_STREQRD_MASK)

#define I3C_STATUS_STCCCH_SHIFT                 (2)
#define I3C_STATUS_STCCCH_MASK                  (0x1U << I3C_STATUS_STCCCH_SHIFT)
#define I3C_STATUS_STCCCH(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STCCCH_SHIFT)) & I3C_STATUS_STCCCH_MASK)

#define I3C_STATUS_STMSG_SHIFT                  (1)
#define I3C_STATUS_STMSG_MASK                   (0x1U << I3C_STATUS_STMSG_SHIFT)
#define I3C_STATUS_STMSG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STMSG_SHIFT)) & I3C_STATUS_STMSG_MASK)

#define I3C_STATUS_STNOTSTOP_SHIFT              (0)
#define I3C_STATUS_STNOTSTOP_MASK               (0x1U << I3C_STATUS_STNOTSTOP_SHIFT)
#define I3C_STATUS_STNOTSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_STATUS_STNOTSTOP_SHIFT)) & I3C_STATUS_STNOTSTOP_MASK)

/*!
 * @brief I3C_CTRL Register Bit Definition
 */

#define I3C_CTRL_VENDINFO_SHIFT                 (24)
#define I3C_CTRL_VENDINFO_MASK                  (0xFFU << I3C_CTRL_VENDINFO_SHIFT)
#define I3C_CTRL_VENDINFO(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_VENDINFO_SHIFT)) & I3C_CTRL_VENDINFO_MASK)

#define I3C_CTRL_ACTSTATE_SHIFT                 (20)
#define I3C_CTRL_ACTSTATE_MASK                  (0x3U << I3C_CTRL_ACTSTATE_SHIFT)
#define I3C_CTRL_ACTSTATE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_ACTSTATE_SHIFT)) & I3C_CTRL_ACTSTATE_MASK)

#define I3C_CTRL_PENDINT_SHIFT                  (16)
#define I3C_CTRL_PENDINT_MASK                   (0xFU << I3C_CTRL_PENDINT_SHIFT)
#define I3C_CTRL_PENDINT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_PENDINT_SHIFT)) & I3C_CTRL_PENDINT_MASK)

#define I3C_CTRL_IBIDATA_SHIFT                  (8)
#define I3C_CTRL_IBIDATA_MASK                   (0xFFU << I3C_CTRL_IBIDATA_SHIFT)
#define I3C_CTRL_IBIDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_IBIDATA_SHIFT)) & I3C_CTRL_IBIDATA_MASK)

#define I3C_CTRL_EXTDATA_SHIFT                  (3)
#define I3C_CTRL_EXTDATA_MASK                   (0x1U << I3C_CTRL_EXTDATA_SHIFT)
#define I3C_CTRL_EXTDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_EXTDATA_SHIFT)) & I3C_CTRL_EXTDATA_MASK)

#define I3C_CTRL_EVENT_SHIFT                    (0)
#define I3C_CTRL_EVENT_MASK                     (0x3U << I3C_CTRL_EVENT_SHIFT)
#define I3C_CTRL_EVENT(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_CTRL_EVENT_SHIFT)) & I3C_CTRL_EVENT_MASK)

/*!
 * @brief I3C_INTSET Register Bit Definition
 */

#define I3C_INTSET_EVTIE_SHIFT                  (18)
#define I3C_INTSET_EVTIE_MASK                   (0x1U << I3C_INTSET_EVTIE_SHIFT)
#define I3C_INTSET_EVTIE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_EVTIE_SHIFT)) & I3C_INTSET_EVTIE_MASK)

#define I3C_INTSET_HANDLEDIE_SHIFT              (17)
#define I3C_INTSET_HANDLEDIE_MASK               (0x1U << I3C_INTSET_HANDLEDIE_SHIFT)
#define I3C_INTSET_HANDLEDIE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_HANDLEDIE_SHIFT)) & I3C_INTSET_HANDLEDIE_MASK)

#define I3C_INTSET_ERWARIE_SHIFT                (15)
#define I3C_INTSET_ERWARIE_MASK                 (0x1U << I3C_INTSET_ERWARIE_SHIFT)
#define I3C_INTSET_ERWARIE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_ERWARIE_SHIFT)) & I3C_INTSET_ERWARIE_MASK)

#define I3C_INTSET_CCCIE_SHIFT                  (14)
#define I3C_INTSET_CCCIE_MASK                   (0x1U << I3C_INTSET_CCCIE_SHIFT)
#define I3C_INTSET_CCCIE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_CCCIE_SHIFT)) & I3C_INTSET_CCCIE_MASK)

#define I3C_INTSET_DACHGIE_SHIFT                (13)
#define I3C_INTSET_DACHGIE_MASK                 (0x1U << I3C_INTSET_DACHGIE_SHIFT)
#define I3C_INTSET_DACHGIE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_DACHGIE_SHIFT)) & I3C_INTSET_DACHGIE_MASK)

#define I3C_INTSET_TXSIE_SHIFT                  (12)
#define I3C_INTSET_TXSIE_MASK                   (0x1U << I3C_INTSET_TXSIE_SHIFT)
#define I3C_INTSET_TXSIE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_TXSIE_SHIFT)) & I3C_INTSET_TXSIE_MASK)

#define I3C_INTSET_RXPIE_SHIFT                  (11)
#define I3C_INTSET_RXPIE_MASK                   (0x1U << I3C_INTSET_RXPIE_SHIFT)
#define I3C_INTSET_RXPIE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_RXPIE_SHIFT)) & I3C_INTSET_RXPIE_MASK)

#define I3C_INTSET_SPIE_SHIFT                   (10)
#define I3C_INTSET_SPIE_MASK                    (0x1U << I3C_INTSET_SPIE_SHIFT)
#define I3C_INTSET_SPIE(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_SPIE_SHIFT)) & I3C_INTSET_SPIE_MASK)

#define I3C_INTSET_MATEDIE_SHIFT                (9)
#define I3C_INTSET_MATEDIE_MASK                 (0x1U << I3C_INTSET_MATEDIE_SHIFT)
#define I3C_INTSET_MATEDIE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_MATEDIE_SHIFT)) & I3C_INTSET_MATEDIE_MASK)

#define I3C_INTSET_STIE_SHIFT                   (8)
#define I3C_INTSET_STIE_MASK                    (0x1U << I3C_INTSET_STIE_SHIFT)
#define I3C_INTSET_STIE(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_INTSET_STIE_SHIFT)) & I3C_INTSET_STIE_MASK)

/*!
 * @brief I3C_INTCLR Register Bit Definition
 */

#define I3C_INTCLR_EVTCLR_SHIFT                 (18)
#define I3C_INTCLR_EVTCLR_MASK                  (0x1U << I3C_INTCLR_EVTCLR_SHIFT)
#define I3C_INTCLR_EVTCLR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_EVTCLR_SHIFT)) & I3C_INTCLR_EVTCLR_MASK)

#define I3C_INTCLR_HANDLEDCLR_SHIFT             (17)
#define I3C_INTCLR_HANDLEDCLR_MASK              (0x1U << I3C_INTCLR_HANDLEDCLR_SHIFT)
#define I3C_INTCLR_HANDLEDCLR(x)                (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_HANDLEDCLR_SHIFT)) & I3C_INTCLR_HANDLEDCLR_MASK)

#define I3C_INTCLR_ERWARCLR_SHIFT               (15)
#define I3C_INTCLR_ERWARCLR_MASK                (0x1U << I3C_INTCLR_ERWARCLR_SHIFT)
#define I3C_INTCLR_ERWARCLR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_ERWARCLR_SHIFT)) & I3C_INTCLR_ERWARCLR_MASK)

#define I3C_INTCLR_CCCCLR_SHIFT                 (14)
#define I3C_INTCLR_CCCCLR_MASK                  (0x1U << I3C_INTCLR_CCCCLR_SHIFT)
#define I3C_INTCLR_CCCCLR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_CCCCLR_SHIFT)) & I3C_INTCLR_CCCCLR_MASK)

#define I3C_INTCLR_DACHGCLR_SHIFT               (13)
#define I3C_INTCLR_DACHGCLR_MASK                (0x1U << I3C_INTCLR_DACHGCLR_SHIFT)
#define I3C_INTCLR_DACHGCLR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_DACHGCLR_SHIFT)) & I3C_INTCLR_DACHGCLR_MASK)

#define I3C_INTCLR_TXSCLR_SHIFT                 (12)
#define I3C_INTCLR_TXSCLR_MASK                  (0x1U << I3C_INTCLR_TXSCLR_SHIFT)
#define I3C_INTCLR_TXSCLR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_TXSCLR_SHIFT)) & I3C_INTCLR_TXSCLR_MASK)

#define I3C_INTCLR_RXPCLR_SHIFT                 (11)
#define I3C_INTCLR_RXPCLR_MASK                  (0x1U << I3C_INTCLR_RXPCLR_SHIFT)
#define I3C_INTCLR_RXPCLR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_RXPCLR_SHIFT)) & I3C_INTCLR_RXPCLR_MASK)

#define I3C_INTCLR_SPCLR_SHIFT                  (10)
#define I3C_INTCLR_SPCLR_MASK                   (0x1U << I3C_INTCLR_SPCLR_SHIFT)
#define I3C_INTCLR_SPCLR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_SPCLR_SHIFT)) & I3C_INTCLR_SPCLR_MASK)

#define I3C_INTCLR_MATEDCLR_SHIFT               (9)
#define I3C_INTCLR_MATEDCLR_MASK                (0x1U << I3C_INTCLR_MATEDCLR_SHIFT)
#define I3C_INTCLR_MATEDCLR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_MATEDCLR_SHIFT)) & I3C_INTCLR_MATEDCLR_MASK)

#define I3C_INTCLR_STCLR_SHIFT                  (8)
#define I3C_INTCLR_STCLR_MASK                   (0x1U << I3C_INTCLR_STCLR_SHIFT)
#define I3C_INTCLR_STCLR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_INTCLR_STCLR_SHIFT)) & I3C_INTCLR_STCLR_MASK)

/*!
 * @brief I3C_INTMASKED Register Bit Definition
 */

#define I3C_INTMASKED_EVTMSK_SHIFT              (18)
#define I3C_INTMASKED_EVTMSK_MASK               (0x1U << I3C_INTMASKED_EVTMSK_SHIFT)
#define I3C_INTMASKED_EVTMSK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_EVTMSK_SHIFT)) & I3C_INTMASKED_EVTMSK_MASK)

#define I3C_INTMASKED_HANDLEDMSK_SHIFT          (17)
#define I3C_INTMASKED_HANDLEDMSK_MASK           (0x1U << I3C_INTMASKED_HANDLEDMSK_SHIFT)
#define I3C_INTMASKED_HANDLEDMSK(x)             (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_HANDLEDMSK_SHIFT)) & I3C_INTMASKED_HANDLEDMSK_MASK)

#define I3C_INTMASKED_ERWARMSK_SHIFT            (15)
#define I3C_INTMASKED_ERWARMSK_MASK             (0x1U << I3C_INTMASKED_ERWARMSK_SHIFT)
#define I3C_INTMASKED_ERWARMSK(x)               (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_ERWARMSK_SHIFT)) & I3C_INTMASKED_ERWARMSK_MASK)

#define I3C_INTMASKED_CCCMSK_SHIFT              (14)
#define I3C_INTMASKED_CCCMSK_MASK               (0x1U << I3C_INTMASKED_CCCMSK_SHIFT)
#define I3C_INTMASKED_CCCMSK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_CCCMSK_SHIFT)) & I3C_INTMASKED_CCCMSK_MASK)

#define I3C_INTMASKED_DACHGMSK_SHIFT            (13)
#define I3C_INTMASKED_DACHGMSK_MASK             (0x1U << I3C_INTMASKED_DACHGMSK_SHIFT)
#define I3C_INTMASKED_DACHGMSK(x)               (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_DACHGMSK_SHIFT)) & I3C_INTMASKED_DACHGMSK_MASK)

#define I3C_INTMASKED_TXSMSK_SHIFT              (12)
#define I3C_INTMASKED_TXSMSK_MASK               (0x1U << I3C_INTMASKED_TXSMSK_SHIFT)
#define I3C_INTMASKED_TXSMSK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_TXSMSK_SHIFT)) & I3C_INTMASKED_TXSMSK_MASK)

#define I3C_INTMASKED_RXPMSK_SHIFT              (11)
#define I3C_INTMASKED_RXPMSK_MASK               (0x1U << I3C_INTMASKED_RXPMSK_SHIFT)
#define I3C_INTMASKED_RXPMSK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_RXPMSK_SHIFT)) & I3C_INTMASKED_RXPMSK_MASK)

#define I3C_INTMASKED_SPMSK_SHIFT               (10)
#define I3C_INTMASKED_SPMSK_MASK                (0x1U << I3C_INTMASKED_SPMSK_SHIFT)
#define I3C_INTMASKED_SPMSK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_SPMSK_SHIFT)) & I3C_INTMASKED_SPMSK_MASK)

#define I3C_INTMASKED_MATEDMSK_SHIFT            (9)
#define I3C_INTMASKED_MATEDMSK_MASK             (0x1U << I3C_INTMASKED_MATEDMSK_SHIFT)
#define I3C_INTMASKED_MATEDMSK(x)               (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_MATEDMSK_SHIFT)) & I3C_INTMASKED_MATEDMSK_MASK)

#define I3C_INTMASKED_STMSK_SHIFT               (8)
#define I3C_INTMASKED_STMSK_MASK                (0x1U << I3C_INTMASKED_STMSK_SHIFT)
#define I3C_INTMASKED_STMSK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_INTMASKED_STMSK_SHIFT)) & I3C_INTMASKED_STMSK_MASK)

/*!
 * @brief I3C_ERWAR Register Bit Definition
 */

#define I3C_ERWAR_OWRITE_SHIFT                  (17)
#define I3C_ERWAR_OWRITE_MASK                   (0x1U << I3C_ERWAR_OWRITE_SHIFT)
#define I3C_ERWAR_OWRITE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_OWRITE_SHIFT)) & I3C_ERWAR_OWRITE_MASK)

#define I3C_ERWAR_OREAD_SHIFT                   (16)
#define I3C_ERWAR_OREAD_MASK                    (0x1U << I3C_ERWAR_OREAD_SHIFT)
#define I3C_ERWAR_OREAD(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_OREAD_SHIFT)) & I3C_ERWAR_OREAD_MASK)

#define I3C_ERWAR_S0S1_SHIFT                    (11)
#define I3C_ERWAR_S0S1_MASK                     (0x1U << I3C_ERWAR_S0S1_SHIFT)
#define I3C_ERWAR_S0S1(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_S0S1_SHIFT)) & I3C_ERWAR_S0S1_MASK)

#define I3C_ERWAR_SPAR_SHIFT                    (8)
#define I3C_ERWAR_SPAR_MASK                     (0x1U << I3C_ERWAR_SPAR_SHIFT)
#define I3C_ERWAR_SPAR(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_SPAR_SHIFT)) & I3C_ERWAR_SPAR_MASK)

#define I3C_ERWAR_INVST_SHIFT                   (4)
#define I3C_ERWAR_INVST_MASK                    (0x1U << I3C_ERWAR_INVST_SHIFT)
#define I3C_ERWAR_INVST(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_INVST_SHIFT)) & I3C_ERWAR_INVST_MASK)

#define I3C_ERWAR_TERM_SHIFT                    (3)
#define I3C_ERWAR_TERM_MASK                     (0x1U << I3C_ERWAR_TERM_SHIFT)
#define I3C_ERWAR_TERM(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_TERM_SHIFT)) & I3C_ERWAR_TERM_MASK)

#define I3C_ERWAR_URUNNACK_SHIFT                (2)
#define I3C_ERWAR_URUNNACK_MASK                 (0x1U << I3C_ERWAR_URUNNACK_SHIFT)
#define I3C_ERWAR_URUNNACK(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_URUNNACK_SHIFT)) & I3C_ERWAR_URUNNACK_MASK)

#define I3C_ERWAR_URUN_SHIFT                    (1)
#define I3C_ERWAR_URUN_MASK                     (0x1U << I3C_ERWAR_URUN_SHIFT)
#define I3C_ERWAR_URUN(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_URUN_SHIFT)) & I3C_ERWAR_URUN_MASK)

#define I3C_ERWAR_ORUN_SHIFT                    (0)
#define I3C_ERWAR_ORUN_MASK                     (0x1U << I3C_ERWAR_ORUN_SHIFT)
#define I3C_ERWAR_ORUN(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_ERWAR_ORUN_SHIFT)) & I3C_ERWAR_ORUN_MASK)

/*!
 * @brief I3C_DMACTRL Register Bit Definition
 */

#define I3C_DMACTRL_DMAWTH_SHIFT                (4)
#define I3C_DMACTRL_DMAWTH_MASK                 (0x3U << I3C_DMACTRL_DMAWTH_SHIFT)
#define I3C_DMACTRL_DMAWTH(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_DMACTRL_DMAWTH_SHIFT)) & I3C_DMACTRL_DMAWTH_MASK)

#define I3C_DMACTRL_DMATB_SHIFT                 (2)
#define I3C_DMACTRL_DMATB_MASK                  (0x3U << I3C_DMACTRL_DMATB_SHIFT)
#define I3C_DMACTRL_DMATB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_DMACTRL_DMATB_SHIFT)) & I3C_DMACTRL_DMATB_MASK)

#define I3C_DMACTRL_DMAFB_SHIFT                 (0)
#define I3C_DMACTRL_DMAFB_MASK                  (0x3U << I3C_DMACTRL_DMAFB_SHIFT)
#define I3C_DMACTRL_DMAFB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_DMACTRL_DMAFB_SHIFT)) & I3C_DMACTRL_DMAFB_MASK)

/*!
 * @brief I3C_DATACTRL Register Bit Definition
 */

#define I3C_DATACTRL_RXEMPTY_SHIFT              (31)
#define I3C_DATACTRL_RXEMPTY_MASK               (0x1U << I3C_DATACTRL_RXEMPTY_SHIFT)
#define I3C_DATACTRL_RXEMPTY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_RXEMPTY_SHIFT)) & I3C_DATACTRL_RXEMPTY_MASK)

#define I3C_DATACTRL_TXFULL_SHIFT               (30)
#define I3C_DATACTRL_TXFULL_MASK                (0x1U << I3C_DATACTRL_TXFULL_SHIFT)
#define I3C_DATACTRL_TXFULL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_TXFULL_SHIFT)) & I3C_DATACTRL_TXFULL_MASK)

#define I3C_DATACTRL_RXCNT_SHIFT                (24)
#define I3C_DATACTRL_RXCNT_MASK                 (0x1FU << I3C_DATACTRL_RXCNT_SHIFT)
#define I3C_DATACTRL_RXCNT(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_RXCNT_SHIFT)) & I3C_DATACTRL_RXCNT_MASK)

#define I3C_DATACTRL_TXCNT_SHIFT                (16)
#define I3C_DATACTRL_TXCNT_MASK                 (0x1FU << I3C_DATACTRL_TXCNT_SHIFT)
#define I3C_DATACTRL_TXCNT(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_TXCNT_SHIFT)) & I3C_DATACTRL_TXCNT_MASK)

#define I3C_DATACTRL_RXTRIG_SHIFT               (6)
#define I3C_DATACTRL_RXTRIG_MASK                (0x3U << I3C_DATACTRL_RXTRIG_SHIFT)
#define I3C_DATACTRL_RXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_RXTRIG_SHIFT)) & I3C_DATACTRL_RXTRIG_MASK)

#define I3C_DATACTRL_TXTRIG_SHIFT               (4)
#define I3C_DATACTRL_TXTRIG_MASK                (0x3U << I3C_DATACTRL_TXTRIG_SHIFT)
#define I3C_DATACTRL_TXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_TXTRIG_SHIFT)) & I3C_DATACTRL_TXTRIG_MASK)

#define I3C_DATACTRL_UNLOCK_SHIFT               (3)
#define I3C_DATACTRL_UNLOCK_MASK                (0x1U << I3C_DATACTRL_UNLOCK_SHIFT)
#define I3C_DATACTRL_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_UNLOCK_SHIFT)) & I3C_DATACTRL_UNLOCK_MASK)

#define I3C_DATACTRL_FLUSHFB_SHIFT              (1)
#define I3C_DATACTRL_FLUSHFB_MASK               (0x1U << I3C_DATACTRL_FLUSHFB_SHIFT)
#define I3C_DATACTRL_FLUSHFB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_FLUSHFB_SHIFT)) & I3C_DATACTRL_FLUSHFB_MASK)

#define I3C_DATACTRL_FLUSHTB_SHIFT              (0)
#define I3C_DATACTRL_FLUSHTB_MASK               (0x1U << I3C_DATACTRL_FLUSHTB_SHIFT)
#define I3C_DATACTRL_FLUSHTB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_DATACTRL_FLUSHTB_SHIFT)) & I3C_DATACTRL_FLUSHTB_MASK)

/*!
 * @brief I3C_WDATAB Register Bit Definition
 */

#define I3C_WDATAB_END2_SHIFT                   (16)
#define I3C_WDATAB_END2_MASK                    (0x1U << I3C_WDATAB_END2_SHIFT)
#define I3C_WDATAB_END2(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_WDATAB_END2_SHIFT)) & I3C_WDATAB_END2_MASK)

#define I3C_WDATAB_END_SHIFT                    (8)
#define I3C_WDATAB_END_MASK                     (0x1U << I3C_WDATAB_END_SHIFT)
#define I3C_WDATAB_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_WDATAB_END_SHIFT)) & I3C_WDATAB_END_MASK)

#define I3C_WDATAB_DATA_SHIFT                   (0)
#define I3C_WDATAB_DATA_MASK                    (0xFFU << I3C_WDATAB_DATA_SHIFT)
#define I3C_WDATAB_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_WDATAB_DATA_SHIFT)) & I3C_WDATAB_DATA_MASK)

/*!
 * @brief I3C_WDATABE Register Bit Definition
 */

#define I3C_WDATABE_DATA_SHIFT                  (0)
#define I3C_WDATABE_DATA_MASK                   (0xFFU << I3C_WDATABE_DATA_SHIFT)
#define I3C_WDATABE_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_WDATABE_DATA_SHIFT)) & I3C_WDATABE_DATA_MASK)

/*!
 * @brief I3C_WDATAH Register Bit Definition
 */

#define I3C_WDATAH_END_SHIFT                    (16)
#define I3C_WDATAH_END_MASK                     (0x1U << I3C_WDATAH_END_SHIFT)
#define I3C_WDATAH_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_WDATAH_END_SHIFT)) & I3C_WDATAH_END_MASK)

#define I3C_WDATAH_DATA1_SHIFT                  (8)
#define I3C_WDATAH_DATA1_MASK                   (0xFFU << I3C_WDATAH_DATA1_SHIFT)
#define I3C_WDATAH_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_WDATAH_DATA1_SHIFT)) & I3C_WDATAH_DATA1_MASK)

#define I3C_WDATAH_DATA0_SHIFT                  (0)
#define I3C_WDATAH_DATA0_MASK                   (0xFFU << I3C_WDATAH_DATA0_SHIFT)
#define I3C_WDATAH_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_WDATAH_DATA0_SHIFT)) & I3C_WDATAH_DATA0_MASK)

/*!
 * @brief I3C_WDATAHE Register Bit Definition
 */

#define I3C_WDATAHE_DATA1_SHIFT                 (8)
#define I3C_WDATAHE_DATA1_MASK                  (0xFFU << I3C_WDATAHE_DATA1_SHIFT)
#define I3C_WDATAHE_DATA1(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_WDATAHE_DATA1_SHIFT)) & I3C_WDATAHE_DATA1_MASK)

#define I3C_WDATAHE_DATA0_SHIFT                 (0)
#define I3C_WDATAHE_DATA0_MASK                  (0xFFU << I3C_WDATAHE_DATA0_SHIFT)
#define I3C_WDATAHE_DATA0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_WDATAHE_DATA0_SHIFT)) & I3C_WDATAHE_DATA0_MASK)

/*!
 * @brief I3C_RDATAB Register Bit Definition
 */

#define I3C_RDATAB_DATA0_SHIFT                  (0)
#define I3C_RDATAB_DATA0_MASK                   (0xFFU << I3C_RDATAB_DATA0_SHIFT)
#define I3C_RDATAB_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_RDATAB_DATA0_SHIFT)) & I3C_RDATAB_DATA0_MASK)

/*!
 * @brief I3C_RDATAH Register Bit Definition
 */

#define I3C_RDATAH_MSB_SHIFT                    (8)
#define I3C_RDATAH_MSB_MASK                     (0xFFU << I3C_RDATAH_MSB_SHIFT)
#define I3C_RDATAH_MSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_RDATAH_MSB_SHIFT)) & I3C_RDATAH_MSB_MASK)

#define I3C_RDATAH_LSB_SHIFT                    (0)
#define I3C_RDATAH_LSB_MASK                     (0xFFU << I3C_RDATAH_LSB_SHIFT)
#define I3C_RDATAH_LSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_RDATAH_LSB_SHIFT)) & I3C_RDATAH_LSB_MASK)

/*!
 * @brief I3C_WDATAB1 Register Bit Definition
 */

#define I3C_WDATAB1_DATA_SHIFT                  (0)
#define I3C_WDATAB1_DATA_MASK                   (0xFFU << I3C_WDATAB1_DATA_SHIFT)
#define I3C_WDATAB1_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_WDATAB1_DATA_SHIFT)) & I3C_WDATAB1_DATA_MASK)

/*!
 * @brief I3C_CAPABILITIES2 Register Bit Definition
 */

#define I3C_CAPABILITIES2_SSTWR_SHIFT           (23)
#define I3C_CAPABILITIES2_SSTWR_MASK            (0x1U << I3C_CAPABILITIES2_SSTWR_SHIFT)
#define I3C_CAPABILITIES2_SSTWR(x)              (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_SSTWR_SHIFT)) & I3C_CAPABILITIES2_SSTWR_MASK)

#define I3C_CAPABILITIES2_SSTSUB_SHIFT          (22)
#define I3C_CAPABILITIES2_SSTSUB_MASK           (0x1U << I3C_CAPABILITIES2_SSTSUB_SHIFT)
#define I3C_CAPABILITIES2_SSTSUB(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_SSTSUB_SHIFT)) & I3C_CAPABILITIES2_SSTSUB_MASK)

#define I3C_CAPABILITIES2_AASA_SHIFT            (21)
#define I3C_CAPABILITIES2_AASA_MASK             (0x1U << I3C_CAPABILITIES2_AASA_SHIFT)
#define I3C_CAPABILITIES2_AASA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_AASA_SHIFT)) & I3C_CAPABILITIES2_AASA_MASK)

#define I3C_CAPABILITIES2_GROUP_SHIFT           (18)
#define I3C_CAPABILITIES2_GROUP_MASK            (0x3U << I3C_CAPABILITIES2_GROUP_SHIFT)
#define I3C_CAPABILITIES2_GROUP(x)              (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_GROUP_SHIFT)) & I3C_CAPABILITIES2_GROUP_MASK)

#define I3C_CAPABILITIES2_SLVRST_SHIFT          (17)
#define I3C_CAPABILITIES2_SLVRST_MASK           (0x1U << I3C_CAPABILITIES2_SLVRST_SHIFT)
#define I3C_CAPABILITIES2_SLVRST(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_SLVRST_SHIFT)) & I3C_CAPABILITIES2_SLVRST_MASK)

#define I3C_CAPABILITIES2_V1P1_SHIFT            (16)
#define I3C_CAPABILITIES2_V1P1_MASK             (0x1U << I3C_CAPABILITIES2_V1P1_SHIFT)
#define I3C_CAPABILITIES2_V1P1(x)               (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_V1P1_SHIFT)) & I3C_CAPABILITIES2_V1P1_MASK)

#define I3C_CAPABILITIES2_IBIFIFO_SHIFT         (9)
#define I3C_CAPABILITIES2_IBIFIFO_MASK          (0x1U << I3C_CAPABILITIES2_IBIFIFO_SHIFT)
#define I3C_CAPABILITIES2_IBIFIFO(x)            (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_IBIFIFO_SHIFT)) & I3C_CAPABILITIES2_IBIFIFO_MASK)

#define I3C_CAPABILITIES2_IBIEXT_SHIFT          (8)
#define I3C_CAPABILITIES2_IBIEXT_MASK           (0x1U << I3C_CAPABILITIES2_IBIEXT_SHIFT)
#define I3C_CAPABILITIES2_IBIEXT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_IBIEXT_SHIFT)) & I3C_CAPABILITIES2_IBIEXT_MASK)

#define I3C_CAPABILITIES2_I2CDEVID_SHIFT        (6)
#define I3C_CAPABILITIES2_I2CDEVID_MASK         (0x1U << I3C_CAPABILITIES2_I2CDEVID_SHIFT)
#define I3C_CAPABILITIES2_I2CDEVID(x)           (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_I2CDEVID_SHIFT)) & I3C_CAPABILITIES2_I2CDEVID_MASK)

#define I3C_CAPABILITIES2_I2CRST_SHIFT          (5)
#define I3C_CAPABILITIES2_I2CRST_MASK           (0x1U << I3C_CAPABILITIES2_I2CRST_SHIFT)
#define I3C_CAPABILITIES2_I2CRST(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_I2CRST_SHIFT)) & I3C_CAPABILITIES2_I2CRST_MASK)

#define I3C_CAPABILITIES2_I2C10B_SHIFT          (4)
#define I3C_CAPABILITIES2_I2C10B_MASK           (0x1U << I3C_CAPABILITIES2_I2C10B_SHIFT)
#define I3C_CAPABILITIES2_I2C10B(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_I2C10B_SHIFT)) & I3C_CAPABILITIES2_I2C10B_MASK)

#define I3C_CAPABILITIES2_MAPCNT_SHIFT          (0)
#define I3C_CAPABILITIES2_MAPCNT_MASK           (0xFU << I3C_CAPABILITIES2_MAPCNT_SHIFT)
#define I3C_CAPABILITIES2_MAPCNT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES2_MAPCNT_SHIFT)) & I3C_CAPABILITIES2_MAPCNT_MASK)

/*!
 * @brief I3C_CAPABILITIES Register Bit Definition
 */

#define I3C_CAPABILITIES_DMA_SHIFT              (31)
#define I3C_CAPABILITIES_DMA_MASK               (0x1U << I3C_CAPABILITIES_DMA_SHIFT)
#define I3C_CAPABILITIES_DMA(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_DMA_SHIFT)) & I3C_CAPABILITIES_DMA_MASK)

#define I3C_CAPABILITIES_INT_SHIFT              (30)
#define I3C_CAPABILITIES_INT_MASK               (0x1U << I3C_CAPABILITIES_INT_SHIFT)
#define I3C_CAPABILITIES_INT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_INT_SHIFT)) & I3C_CAPABILITIES_INT_MASK)

#define I3C_CAPABILITIES_FIFORX_SHIFT           (28)
#define I3C_CAPABILITIES_FIFORX_MASK            (0x3U << I3C_CAPABILITIES_FIFORX_SHIFT)
#define I3C_CAPABILITIES_FIFORX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_FIFORX_SHIFT)) & I3C_CAPABILITIES_FIFORX_MASK)

#define I3C_CAPABILITIES_FIFOTX_SHIFT           (26)
#define I3C_CAPABILITIES_FIFOTX_MASK            (0x3U << I3C_CAPABILITIES_FIFOTX_SHIFT)
#define I3C_CAPABILITIES_FIFOTX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_FIFOTX_SHIFT)) & I3C_CAPABILITIES_FIFOTX_MASK)

#define I3C_CAPABILITIES_EXTFIFO_SHIFT          (23)
#define I3C_CAPABILITIES_EXTFIFO_MASK           (0x7U << I3C_CAPABILITIES_EXTFIFO_SHIFT)
#define I3C_CAPABILITIES_EXTFIFO(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_EXTFIFO_SHIFT)) & I3C_CAPABILITIES_EXTFIFO_MASK)

#define I3C_CAPABILITIES_TIMECTRL_SHIFT         (21)
#define I3C_CAPABILITIES_TIMECTRL_MASK          (0x1U << I3C_CAPABILITIES_TIMECTRL_SHIFT)
#define I3C_CAPABILITIES_TIMECTRL(x)            (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_TIMECTRL_SHIFT)) & I3C_CAPABILITIES_TIMECTRL_MASK)

#define I3C_CAPABILITIES_IBIMRHJ_SHIFT          (16)
#define I3C_CAPABILITIES_IBIMRHJ_MASK           (0x1FU << I3C_CAPABILITIES_IBIMRHJ_SHIFT)
#define I3C_CAPABILITIES_IBIMRHJ(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_IBIMRHJ_SHIFT)) & I3C_CAPABILITIES_IBIMRHJ_MASK)

#define I3C_CAPABILITIES_CCCHANDLE_SHIFT        (12)
#define I3C_CAPABILITIES_CCCHANDLE_MASK         (0xFU << I3C_CAPABILITIES_CCCHANDLE_SHIFT)
#define I3C_CAPABILITIES_CCCHANDLE(x)           (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_CCCHANDLE_SHIFT)) & I3C_CAPABILITIES_CCCHANDLE_MASK)

#define I3C_CAPABILITIES_SADDR_SHIFT            (10)
#define I3C_CAPABILITIES_SADDR_MASK             (0x3U << I3C_CAPABILITIES_SADDR_SHIFT)
#define I3C_CAPABILITIES_SADDR(x)               (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_SADDR_SHIFT)) & I3C_CAPABILITIES_SADDR_MASK)

#define I3C_CAPABILITIES_MASTER_SHIFT           (9)
#define I3C_CAPABILITIES_MASTER_MASK            (0x1U << I3C_CAPABILITIES_MASTER_SHIFT)
#define I3C_CAPABILITIES_MASTER(x)              (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_MASTER_SHIFT)) & I3C_CAPABILITIES_MASTER_MASK)

#define I3C_CAPABILITIES_HDRSUPP_SHIFT          (6)
#define I3C_CAPABILITIES_HDRSUPP_MASK           (0x7U << I3C_CAPABILITIES_HDRSUPP_SHIFT)
#define I3C_CAPABILITIES_HDRSUPP(x)             (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_HDRSUPP_SHIFT)) & I3C_CAPABILITIES_HDRSUPP_MASK)

#define I3C_CAPABILITIES_IDREG_SHIFT            (2)
#define I3C_CAPABILITIES_IDREG_MASK             (0xFU << I3C_CAPABILITIES_IDREG_SHIFT)
#define I3C_CAPABILITIES_IDREG(x)               (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_IDREG_SHIFT)) & I3C_CAPABILITIES_IDREG_MASK)

#define I3C_CAPABILITIES_IDENA_SHIFT            (0)
#define I3C_CAPABILITIES_IDENA_MASK             (0x3U << I3C_CAPABILITIES_IDENA_SHIFT)
#define I3C_CAPABILITIES_IDENA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_CAPABILITIES_IDENA_SHIFT)) & I3C_CAPABILITIES_IDENA_MASK)

/*!
 * @brief I3C_DYNADDR Register Bit Definition
 */

#define I3C_DYNADDR_KEY_SHIFT                   (16)
#define I3C_DYNADDR_KEY_MASK                    (0xFFFFU << I3C_DYNADDR_KEY_SHIFT)
#define I3C_DYNADDR_KEY(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_DYNADDR_KEY_SHIFT)) & I3C_DYNADDR_KEY_MASK)

#define I3C_DYNADDR_DCAUSE_SHIFT                (8)
#define I3C_DYNADDR_DCAUSE_MASK                 (0x7U << I3C_DYNADDR_DCAUSE_SHIFT)
#define I3C_DYNADDR_DCAUSE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_DYNADDR_DCAUSE_SHIFT)) & I3C_DYNADDR_DCAUSE_MASK)

#define I3C_DYNADDR_DADDR_SHIFT                 (1)
#define I3C_DYNADDR_DADDR_MASK                  (0x7FU << I3C_DYNADDR_DADDR_SHIFT)
#define I3C_DYNADDR_DADDR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_DYNADDR_DADDR_SHIFT)) & I3C_DYNADDR_DADDR_MASK)

#define I3C_DYNADDR_DAVLD_SHIFT                 (0)
#define I3C_DYNADDR_DAVLD_MASK                  (0x1U << I3C_DYNADDR_DAVLD_SHIFT)
#define I3C_DYNADDR_DAVLD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_DYNADDR_DAVLD_SHIFT)) & I3C_DYNADDR_DAVLD_MASK)

/*!
 * @brief I3C_MAXLIMITS Register Bit Definition
 */

#define I3C_MAXLIMITS_MAXWR_SHIFT               (16)
#define I3C_MAXLIMITS_MAXWR_MASK                (0xFFFU << I3C_MAXLIMITS_MAXWR_SHIFT)
#define I3C_MAXLIMITS_MAXWR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MAXLIMITS_MAXWR_SHIFT)) & I3C_MAXLIMITS_MAXWR_MASK)

#define I3C_MAXLIMITS_MAXRD_SHIFT               (0)
#define I3C_MAXLIMITS_MAXRD_MASK                (0xFFFU << I3C_MAXLIMITS_MAXRD_SHIFT)
#define I3C_MAXLIMITS_MAXRD(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MAXLIMITS_MAXRD_SHIFT)) & I3C_MAXLIMITS_MAXRD_MASK)

/*!
 * @brief I3C_IDPARTNO Register Bit Definition
 */

#define I3C_IDPARTNO_PARTNO_SHIFT                 (0)
#define I3C_IDPARTNO_PARTNO_MASK                  (0xFFFFFFFFU << I3C_IDPARTNO_PARTNO_SHIFT)
#define I3C_IDPARTNO_PARTNO(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_IDPARTNO_PARTNO_SHIFT)) & I3C_IDPARTNO_PARTNO_MASK)

/*!
 * @brief I3C_IDEXT Register Bit Definition
 */

#define I3C_IDEXT_BCR_SHIFT                     (16)
#define I3C_IDEXT_BCR_MASK                      (0xFFU << I3C_IDEXT_BCR_SHIFT)
#define I3C_IDEXT_BCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_IDEXT_BCR_SHIFT)) & I3C_IDEXT_BCR_MASK)

#define I3C_IDEXT_DCR_SHIFT                     (8)
#define I3C_IDEXT_DCR_MASK                      (0xFFU << I3C_IDEXT_DCR_SHIFT)
#define I3C_IDEXT_DCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_IDEXT_DCR_SHIFT)) & I3C_IDEXT_DCR_MASK)

/*!
 * @brief I3C_VENDORID Register Bit Definition
 */

#define I3C_VENDORID_VID_SHIFT                  (0)
#define I3C_VENDORID_VID_MASK                   (0x7FFFU << I3C_VENDORID_VID_SHIFT)
#define I3C_VENDORID_VID(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_VENDORID_VID_SHIFT)) & I3C_VENDORID_VID_MASK)

/*!
 * @brief I3C_DIV Register Bit Definition
 */

#define I3C_DIV_DIV_SHIFT                       (0)
#define I3C_DIV_DIV_MASK                        (0xFFU << I3C_DIV_DIV_SHIFT)
#define I3C_DIV_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I3C_DIV_DIV_SHIFT)) & I3C_DIV_DIV_MASK)

/*!
 * @brief I3C_SPKLEN Register Bit Definition
 */

#define I3C_SPKLEN_FLTEN_SHIFT                  (16)
#define I3C_SPKLEN_FLTEN_MASK                   (0x1U << I3C_SPKLEN_FLTEN_SHIFT)
#define I3C_SPKLEN_FLTEN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SPKLEN_FLTEN_SHIFT)) & I3C_SPKLEN_FLTEN_MASK)

#define I3C_SPKLEN_SPKLEN_SHIFT                 (0)
#define I3C_SPKLEN_SPKLEN_MASK                  (0xFFU << I3C_SPKLEN_SPKLEN_SHIFT)
#define I3C_SPKLEN_SPKLEN(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SPKLEN_SPKLEN_SHIFT)) & I3C_SPKLEN_SPKLEN_MASK)

/*!
 * @}
 */ /* end of group I3C_Register_Masks */
/******************************************************************************
 *I3C Instance
*******************************************************************************/

#define I3C                  ((I3C_Type*)I3C1_BASE)

/*!
 * @}
 */ /* end of group I3C_Peripheral_Access_Layer */



/*!
 * @addtogroup IWDG_Peripheral_Access_Layer IWDG Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * IWDG Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t KR;                                                           ///< Key register                                 offset: 0x00
    __IO uint32_t PR;                                                           ///< Prescaler register                           offset: 0x04
    __IO uint32_t RLR;                                                          ///< Reload register                              offset: 0x08
    __IO uint32_t SR;                                                           ///< Status register                              offset: 0x0C
    __IO uint32_t CR;                                                           ///< Control register                             offset: 0x10
    __IO uint32_t IGEN;                                                         ///< Interrupt generate register                  offset: 0x14
    __IO uint32_t CNT;                                                          ///< Counter register                             offset: 0x18
} IWDG_Type;

/*******************************************************************************
 * IWDG Type
 ******************************************************************************/

/*!
 * @addtogroup IWDG_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief IWDG_KR Register Bit Definition
 */

#define IWDG_KR_KEY_SHIFT                       (0)
#define IWDG_KR_KEY_MASK                        (0xFFFFU << IWDG_KR_KEY_SHIFT)
#define IWDG_KR_KEY(x)                          (((uint32_t)(((uint32_t)(x)) << IWDG_KR_KEY_SHIFT)) & IWDG_KR_KEY_MASK)

/*!
 * @brief IWDG_PR Register Bit Definition
 */

#define IWDG_PR_PR_SHIFT                        (0)
#define IWDG_PR_PR_MASK                         (0x7U << IWDG_PR_PR_SHIFT)
#define IWDG_PR_PR(x)                           (((uint32_t)(((uint32_t)(x)) << IWDG_PR_PR_SHIFT)) & IWDG_PR_PR_MASK)

/*!
 * @brief IWDG_RLR Register Bit Definition
 */

#define IWDG_RLR_RL_SHIFT                       (0)
#define IWDG_RLR_RL_MASK                        (0xFFFU << IWDG_RLR_RL_SHIFT)
#define IWDG_RLR_RL(x)                          (((uint32_t)(((uint32_t)(x)) << IWDG_RLR_RL_SHIFT)) & IWDG_RLR_RL_MASK)

/*!
 * @brief IWDG_SR Register Bit Definition
 */

#define IWDG_SR_UPDATE_SHIFT                    (3)
#define IWDG_SR_UPDATE_MASK                     (0x1U << IWDG_SR_UPDATE_SHIFT)
#define IWDG_SR_UPDATE(x)                       (((uint32_t)(((uint32_t)(x)) << IWDG_SR_UPDATE_SHIFT)) & IWDG_SR_UPDATE_MASK)

#define IWDG_SR_IVU_SHIFT                       (2)
#define IWDG_SR_IVU_MASK                        (0x1U << IWDG_SR_IVU_SHIFT)
#define IWDG_SR_IVU(x)                          (((uint32_t)(((uint32_t)(x)) << IWDG_SR_IVU_SHIFT)) & IWDG_SR_IVU_MASK)

#define IWDG_SR_RVU_SHIFT                       (1)
#define IWDG_SR_RVU_MASK                        (0x1U << IWDG_SR_RVU_SHIFT)
#define IWDG_SR_RVU(x)                          (((uint32_t)(((uint32_t)(x)) << IWDG_SR_RVU_SHIFT)) & IWDG_SR_RVU_MASK)

#define IWDG_SR_PVU_SHIFT                       (0)
#define IWDG_SR_PVU_MASK                        (0x1U << IWDG_SR_PVU_SHIFT)
#define IWDG_SR_PVU(x)                          (((uint32_t)(((uint32_t)(x)) << IWDG_SR_PVU_SHIFT)) & IWDG_SR_PVU_MASK)

/*!
 * @brief IWDG_CR Register Bit Definition
 */

#define IWDG_CR_IRQCLR_SHIFT                    (1)
#define IWDG_CR_IRQCLR_MASK                     (0x1U << IWDG_CR_IRQCLR_SHIFT)
#define IWDG_CR_IRQCLR(x)                       (((uint32_t)(((uint32_t)(x)) << IWDG_CR_IRQCLR_SHIFT)) & IWDG_CR_IRQCLR_MASK)

#define IWDG_CR_IRQSEL_SHIFT                    (0)
#define IWDG_CR_IRQSEL_MASK                     (0x1U << IWDG_CR_IRQSEL_SHIFT)
#define IWDG_CR_IRQSEL(x)                       (((uint32_t)(((uint32_t)(x)) << IWDG_CR_IRQSEL_SHIFT)) & IWDG_CR_IRQSEL_MASK)

/*!
 * @brief IWDG_IGEN Register Bit Definition
 */

#define IWDG_IGEN_IGEN_SHIFT                    (0)
#define IWDG_IGEN_IGEN_MASK                     (0xFFFU << IWDG_IGEN_IGEN_SHIFT)
#define IWDG_IGEN_IGEN(x)                       (((uint32_t)(((uint32_t)(x)) << IWDG_IGEN_IGEN_SHIFT)) & IWDG_IGEN_IGEN_MASK)

/*!
 * @brief IWDG_CNT Register Bit Definition
 */

#define IWDG_CNT_IWDGCNT_SHIFT                  (8)
#define IWDG_CNT_IWDGCNT_MASK                   (0x7FFU << IWDG_CNT_IWDGCNT_SHIFT)
#define IWDG_CNT_IWDGCNT(x)                     (((uint32_t)(((uint32_t)(x)) << IWDG_CNT_IWDGCNT_SHIFT)) & IWDG_CNT_IWDGCNT_MASK)

#define IWDG_CNT_IWDGPS_SHIFT                   (0)
#define IWDG_CNT_IWDGPS_MASK                    (0xFFU << IWDG_CNT_IWDGPS_SHIFT)
#define IWDG_CNT_IWDGPS(x)                      (((uint32_t)(((uint32_t)(x)) << IWDG_CNT_IWDGPS_SHIFT)) & IWDG_CNT_IWDGPS_MASK)

/*!
 * @}
 */ /* end of group IWDG_Register_Masks */
/******************************************************************************
 *IWDG Instance
*******************************************************************************/

#define IWDG                 ((IWDG_Type*)IWDG_BASE)

/*!
 * @}
 */ /* end of group IWDG_Peripheral_Access_Layer */



/*!
 * @addtogroup LPTIM_Peripheral_Access_Layer LPTIM Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * LPTIM Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CFG;                                                          ///< Configuration rRegister                      offset: 0x00
    __IO uint32_t IE;                                                           ///< Interrupt Enable Register                    offset: 0x04
    __IO uint32_t IF;                                                           ///< Interrupt Flag Register                      offset: 0x08
    __IO uint32_t CTRL;                                                         ///< Control Register                             offset: 0x0C
    __IO uint32_t CNT;                                                          ///< Count Register                               offset: 0x10
    __IO uint32_t CMP;                                                          ///< Compare Value Register                       offset: 0x14
    __IO uint32_t TARGET;                                                       ///< Target Value Register                        offset: 0x18
} LPTIM_Type;

/*******************************************************************************
 * LPTIM Type
 ******************************************************************************/

/*!
 * @addtogroup LPTIM_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief LPTIM_CFG Register Bit Definition
 */

#define LPTIM_CFG_FLTEN_SHIFT                   (15)
#define LPTIM_CFG_FLTEN_MASK                    (0x1U << LPTIM_CFG_FLTEN_SHIFT)
#define LPTIM_CFG_FLTEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_FLTEN_SHIFT)) & LPTIM_CFG_FLTEN_MASK)

#define LPTIM_CFG_DIVSEL_SHIFT                  (8)
#define LPTIM_CFG_DIVSEL_MASK                   (0x7U << LPTIM_CFG_DIVSEL_SHIFT)
#define LPTIM_CFG_DIVSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_DIVSEL_SHIFT)) & LPTIM_CFG_DIVSEL_MASK)

#define LPTIM_CFG_TRIGCFG_SHIFT                 (6)
#define LPTIM_CFG_TRIGCFG_MASK                  (0x3U << LPTIM_CFG_TRIGCFG_SHIFT)
#define LPTIM_CFG_TRIGCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_TRIGCFG_SHIFT)) & LPTIM_CFG_TRIGCFG_MASK)

#define LPTIM_CFG_TRIGSEL_SHIFT                 (5)
#define LPTIM_CFG_TRIGSEL_MASK                  (0x1U << LPTIM_CFG_TRIGSEL_SHIFT)
#define LPTIM_CFG_TRIGSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_TRIGSEL_SHIFT)) & LPTIM_CFG_TRIGSEL_MASK)

#define LPTIM_CFG_POLARITY_SHIFT                (4)
#define LPTIM_CFG_POLARITY_MASK                 (0x1U << LPTIM_CFG_POLARITY_SHIFT)
#define LPTIM_CFG_POLARITY(x)                   (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_POLARITY_SHIFT)) & LPTIM_CFG_POLARITY_MASK)

#define LPTIM_CFG_PWM_SHIFT                     (3)
#define LPTIM_CFG_PWM_MASK                      (0x1U << LPTIM_CFG_PWM_SHIFT)
#define LPTIM_CFG_PWM(x)                        (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_PWM_SHIFT)) & LPTIM_CFG_PWM_MASK)

#define LPTIM_CFG_TMODE_SHIFT                   (1)
#define LPTIM_CFG_TMODE_MASK                    (0x3U << LPTIM_CFG_TMODE_SHIFT)
#define LPTIM_CFG_TMODE(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_TMODE_SHIFT)) & LPTIM_CFG_TMODE_MASK)

#define LPTIM_CFG_MODE_SHIFT                    (0)
#define LPTIM_CFG_MODE_MASK                     (0x1U << LPTIM_CFG_MODE_SHIFT)
#define LPTIM_CFG_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << LPTIM_CFG_MODE_SHIFT)) & LPTIM_CFG_MODE_MASK)

/*!
 * @brief LPTIM_IE Register Bit Definition
 */

#define LPTIM_IE_COMPIE_SHIFT                   (2)
#define LPTIM_IE_COMPIE_MASK                    (0x1U << LPTIM_IE_COMPIE_SHIFT)
#define LPTIM_IE_COMPIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_IE_COMPIE_SHIFT)) & LPTIM_IE_COMPIE_MASK)

#define LPTIM_IE_TRIGIE_SHIFT                   (1)
#define LPTIM_IE_TRIGIE_MASK                    (0x1U << LPTIM_IE_TRIGIE_SHIFT)
#define LPTIM_IE_TRIGIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_IE_TRIGIE_SHIFT)) & LPTIM_IE_TRIGIE_MASK)

#define LPTIM_IE_OVIE_SHIFT                     (0)
#define LPTIM_IE_OVIE_MASK                      (0x1U << LPTIM_IE_OVIE_SHIFT)
#define LPTIM_IE_OVIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPTIM_IE_OVIE_SHIFT)) & LPTIM_IE_OVIE_MASK)

/*!
 * @brief LPTIM_IF Register Bit Definition
 */

#define LPTIM_IF_COMPIF_SHIFT                   (2)
#define LPTIM_IF_COMPIF_MASK                    (0x1U << LPTIM_IF_COMPIF_SHIFT)
#define LPTIM_IF_COMPIF(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_IF_COMPIF_SHIFT)) & LPTIM_IF_COMPIF_MASK)

#define LPTIM_IF_TRIGIF_SHIFT                   (1)
#define LPTIM_IF_TRIGIF_MASK                    (0x1U << LPTIM_IF_TRIGIF_SHIFT)
#define LPTIM_IF_TRIGIF(x)                      (((uint32_t)(((uint32_t)(x)) << LPTIM_IF_TRIGIF_SHIFT)) & LPTIM_IF_TRIGIF_MASK)

#define LPTIM_IF_OVIF_SHIFT                     (0)
#define LPTIM_IF_OVIF_MASK                      (0x1U << LPTIM_IF_OVIF_SHIFT)
#define LPTIM_IF_OVIF(x)                        (((uint32_t)(((uint32_t)(x)) << LPTIM_IF_OVIF_SHIFT)) & LPTIM_IF_OVIF_MASK)

/*!
 * @brief LPTIM_CTRL Register Bit Definition
 */

#define LPTIM_CTRL_LPTEN_SHIFT                  (0)
#define LPTIM_CTRL_LPTEN_MASK                   (0x1U << LPTIM_CTRL_LPTEN_SHIFT)
#define LPTIM_CTRL_LPTEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPTIM_CTRL_LPTEN_SHIFT)) & LPTIM_CTRL_LPTEN_MASK)

/*!
 * @brief LPTIM_CNT Register Bit Definition
 */

#define LPTIM_CNT_CNT_SHIFT                     (0)
#define LPTIM_CNT_CNT_MASK                      (0xFFFFU << LPTIM_CNT_CNT_SHIFT)
#define LPTIM_CNT_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << LPTIM_CNT_CNT_SHIFT)) & LPTIM_CNT_CNT_MASK)

/*!
 * @brief LPTIM_CMP Register Bit Definition
 */

#define LPTIM_CMP_COMPAREREG_SHIFT              (0)
#define LPTIM_CMP_COMPAREREG_MASK               (0xFFFFU << LPTIM_CMP_COMPAREREG_SHIFT)
#define LPTIM_CMP_COMPAREREG(x)                 (((uint32_t)(((uint32_t)(x)) << LPTIM_CMP_COMPAREREG_SHIFT)) & LPTIM_CMP_COMPAREREG_MASK)

/*!
 * @brief LPTIM_TARGET Register Bit Definition
 */

#define LPTIM_TARGET_TARGETREG_SHIFT            (0)
#define LPTIM_TARGET_TARGETREG_MASK             (0xFFFFU << LPTIM_TARGET_TARGETREG_SHIFT)
#define LPTIM_TARGET_TARGETREG(x)               (((uint32_t)(((uint32_t)(x)) << LPTIM_TARGET_TARGETREG_SHIFT)) & LPTIM_TARGET_TARGETREG_MASK)

/*!
 * @}
 */ /* end of group LPTIM_Register_Masks */
/******************************************************************************
 *LPTIM Instance
*******************************************************************************/

#define LPTIM                ((LPTIM_Type*)LPTIM1_BASE)

/*!
 * @}
 */ /* end of group LPTIM_Peripheral_Access_Layer */



/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * LPUART Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t LPUBAUD;                                                      ///< Baud Rate Register                           offset: 0x00
    __IO uint32_t MODU;                                                         ///< Baud Rate Modulating Control Register        offset: 0x04
    __IO uint32_t LPUIF;                                                        ///< Interrupt Flag Register                      offset: 0x08
    __IO uint32_t LPUSTA;                                                       ///< Status Register                              offset: 0x0C
    __IO uint32_t LPUCON;                                                       ///< Control Register                             offset: 0x10
    __IO uint32_t LPUEN;                                                        ///< Ransmission And Reception Enable Register    offset: 0x14
    __IO uint32_t LPURXD;                                                       ///< Receive Data Register                        offset: 0x18
    __IO uint32_t LPUTXD;                                                       ///< Transmit Data Register                       offset: 0x1C
    __IO uint32_t COMPARE;                                                      ///< Compare Register                             offset: 0x20
    __IO uint32_t WKCKE;                                                        ///< Wakeup Register                              offset: 0x24
} LPUART_Type;

/*******************************************************************************
 * LPUART Type
 ******************************************************************************/

/*!
 * @addtogroup LPUART_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief LPUART_LPUBAUD Register Bit Definition
 */

#define LPUART_LPUBAUD_BR_SHIFT                 (16)
#define LPUART_LPUBAUD_BR_MASK                  (0xFFFFU << LPUART_LPUBAUD_BR_SHIFT)
#define LPUART_LPUBAUD_BR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUBAUD_BR_SHIFT)) & LPUART_LPUBAUD_BR_MASK)

#define LPUART_LPUBAUD_BREN_SHIFT               (8)
#define LPUART_LPUBAUD_BREN_MASK                (0x1U << LPUART_LPUBAUD_BREN_SHIFT)
#define LPUART_LPUBAUD_BREN(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUBAUD_BREN_SHIFT)) & LPUART_LPUBAUD_BREN_MASK)

#define LPUART_LPUBAUD_BAUD_SHIFT               (0)
#define LPUART_LPUBAUD_BAUD_MASK                (0x7U << LPUART_LPUBAUD_BAUD_SHIFT)
#define LPUART_LPUBAUD_BAUD(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUBAUD_BAUD_SHIFT)) & LPUART_LPUBAUD_BAUD_MASK)

/*!
 * @brief LPUART_MODU Register Bit Definition
 */

#define LPUART_MODU_MCTL_SHIFT                  (0)
#define LPUART_MODU_MCTL_MASK                   (0xFFFU << LPUART_MODU_MCTL_SHIFT)
#define LPUART_MODU_MCTL(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_MODU_MCTL_SHIFT)) & LPUART_MODU_MCTL_MASK)

/*!
 * @brief LPUART_LPUIF Register Bit Definition
 */

#define LPUART_LPUIF_TCIF_SHIFT                 (3)
#define LPUART_LPUIF_TCIF_MASK                  (0x1U << LPUART_LPUIF_TCIF_SHIFT)
#define LPUART_LPUIF_TCIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUIF_TCIF_SHIFT)) & LPUART_LPUIF_TCIF_MASK)

#define LPUART_LPUIF_RXNEGIF_SHIFT              (2)
#define LPUART_LPUIF_RXNEGIF_MASK               (0x1U << LPUART_LPUIF_RXNEGIF_SHIFT)
#define LPUART_LPUIF_RXNEGIF(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_LPUIF_RXNEGIF_SHIFT)) & LPUART_LPUIF_RXNEGIF_MASK)

#define LPUART_LPUIF_TXIF_SHIFT                 (1)
#define LPUART_LPUIF_TXIF_MASK                  (0x1U << LPUART_LPUIF_TXIF_SHIFT)
#define LPUART_LPUIF_TXIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUIF_TXIF_SHIFT)) & LPUART_LPUIF_TXIF_MASK)

#define LPUART_LPUIF_RXIF_SHIFT                 (0)
#define LPUART_LPUIF_RXIF_MASK                  (0x1U << LPUART_LPUIF_RXIF_SHIFT)
#define LPUART_LPUIF_RXIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUIF_RXIF_SHIFT)) & LPUART_LPUIF_RXIF_MASK)

/*!
 * @brief LPUART_LPUSTA Register Bit Definition
 */

#define LPUART_LPUSTA_START_SHIFT               (7)
#define LPUART_LPUSTA_START_MASK                (0x1U << LPUART_LPUSTA_START_SHIFT)
#define LPUART_LPUSTA_START(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_START_SHIFT)) & LPUART_LPUSTA_START_MASK)

#define LPUART_LPUSTA_PERR_SHIFT                (6)
#define LPUART_LPUSTA_PERR_MASK                 (0x1U << LPUART_LPUSTA_PERR_SHIFT)
#define LPUART_LPUSTA_PERR(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_PERR_SHIFT)) & LPUART_LPUSTA_PERR_MASK)

#define LPUART_LPUSTA_TC_SHIFT                  (5)
#define LPUART_LPUSTA_TC_MASK                   (0x1U << LPUART_LPUSTA_TC_SHIFT)
#define LPUART_LPUSTA_TC(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_TC_SHIFT)) & LPUART_LPUSTA_TC_MASK)

#define LPUART_LPUSTA_TXE_SHIFT                 (4)
#define LPUART_LPUSTA_TXE_MASK                  (0x1U << LPUART_LPUSTA_TXE_SHIFT)
#define LPUART_LPUSTA_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_TXE_SHIFT)) & LPUART_LPUSTA_TXE_MASK)

#define LPUART_LPUSTA_RXF_SHIFT                 (3)
#define LPUART_LPUSTA_RXF_MASK                  (0x1U << LPUART_LPUSTA_RXF_SHIFT)
#define LPUART_LPUSTA_RXF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_RXF_SHIFT)) & LPUART_LPUSTA_RXF_MASK)

#define LPUART_LPUSTA_MATCH_SHIFT               (2)
#define LPUART_LPUSTA_MATCH_MASK                (0x1U << LPUART_LPUSTA_MATCH_SHIFT)
#define LPUART_LPUSTA_MATCH(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_MATCH_SHIFT)) & LPUART_LPUSTA_MATCH_MASK)

#define LPUART_LPUSTA_FERR_SHIFT                (1)
#define LPUART_LPUSTA_FERR_MASK                 (0x1U << LPUART_LPUSTA_FERR_SHIFT)
#define LPUART_LPUSTA_FERR(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_FERR_SHIFT)) & LPUART_LPUSTA_FERR_MASK)

#define LPUART_LPUSTA_RXOV_SHIFT                (0)
#define LPUART_LPUSTA_RXOV_MASK                 (0x1U << LPUART_LPUSTA_RXOV_SHIFT)
#define LPUART_LPUSTA_RXOV(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUSTA_RXOV_SHIFT)) & LPUART_LPUSTA_RXOV_MASK)

/*!
 * @brief LPUART_LPUCON Register Bit Definition
 */

#define LPUART_LPUCON_TXPOL_SHIFT               (12)
#define LPUART_LPUCON_TXPOL_MASK                (0x1U << LPUART_LPUCON_TXPOL_SHIFT)
#define LPUART_LPUCON_TXPOL(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_TXPOL_SHIFT)) & LPUART_LPUCON_TXPOL_MASK)

#define LPUART_LPUCON_RXPOL_SHIFT               (11)
#define LPUART_LPUCON_RXPOL_MASK                (0x1U << LPUART_LPUCON_RXPOL_SHIFT)
#define LPUART_LPUCON_RXPOL(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_RXPOL_SHIFT)) & LPUART_LPUCON_RXPOL_MASK)

#define LPUART_LPUCON_PAREN_SHIFT               (10)
#define LPUART_LPUCON_PAREN_MASK                (0x1U << LPUART_LPUCON_PAREN_SHIFT)
#define LPUART_LPUCON_PAREN(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_PAREN_SHIFT)) & LPUART_LPUCON_PAREN_MASK)

#define LPUART_LPUCON_PTYP_SHIFT                (9)
#define LPUART_LPUCON_PTYP_MASK                 (0x1U << LPUART_LPUCON_PTYP_SHIFT)
#define LPUART_LPUCON_PTYP(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_PTYP_SHIFT)) & LPUART_LPUCON_PTYP_MASK)

#define LPUART_LPUCON_SL_SHIFT                  (8)
#define LPUART_LPUCON_SL_MASK                   (0x1U << LPUART_LPUCON_SL_SHIFT)
#define LPUART_LPUCON_SL(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_SL_SHIFT)) & LPUART_LPUCON_SL_MASK)

#define LPUART_LPUCON_DL_SHIFT                  (7)
#define LPUART_LPUCON_DL_MASK                   (0x1U << LPUART_LPUCON_DL_SHIFT)
#define LPUART_LPUCON_DL(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_DL_SHIFT)) & LPUART_LPUCON_DL_MASK)

#define LPUART_LPUCON_RXEV_SHIFT                (5)
#define LPUART_LPUCON_RXEV_MASK                 (0x3U << LPUART_LPUCON_RXEV_SHIFT)
#define LPUART_LPUCON_RXEV(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_RXEV_SHIFT)) & LPUART_LPUCON_RXEV_MASK)

#define LPUART_LPUCON_ERRIE_SHIFT               (4)
#define LPUART_LPUCON_ERRIE_MASK                (0x1U << LPUART_LPUCON_ERRIE_SHIFT)
#define LPUART_LPUCON_ERRIE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_ERRIE_SHIFT)) & LPUART_LPUCON_ERRIE_MASK)

#define LPUART_LPUCON_TCIE_SHIFT                (3)
#define LPUART_LPUCON_TCIE_MASK                 (0x1U << LPUART_LPUCON_TCIE_SHIFT)
#define LPUART_LPUCON_TCIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_TCIE_SHIFT)) & LPUART_LPUCON_TCIE_MASK)

#define LPUART_LPUCON_TXIE_SHIFT                (2)
#define LPUART_LPUCON_TXIE_MASK                 (0x1U << LPUART_LPUCON_TXIE_SHIFT)
#define LPUART_LPUCON_TXIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_TXIE_SHIFT)) & LPUART_LPUCON_TXIE_MASK)

#define LPUART_LPUCON_NEDET_SHIFT               (1)
#define LPUART_LPUCON_NEDET_MASK                (0x1U << LPUART_LPUCON_NEDET_SHIFT)
#define LPUART_LPUCON_NEDET(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_NEDET_SHIFT)) & LPUART_LPUCON_NEDET_MASK)

#define LPUART_LPUCON_RXIE_SHIFT                (0)
#define LPUART_LPUCON_RXIE_MASK                 (0x1U << LPUART_LPUCON_RXIE_SHIFT)
#define LPUART_LPUCON_RXIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUCON_RXIE_SHIFT)) & LPUART_LPUCON_RXIE_MASK)

/*!
 * @brief LPUART_LPUEN Register Bit Definition
 */

#define LPUART_LPUEN_DMAR_SHIFT                 (3)
#define LPUART_LPUEN_DMAR_MASK                  (0x1U << LPUART_LPUEN_DMAR_SHIFT)
#define LPUART_LPUEN_DMAR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUEN_DMAR_SHIFT)) & LPUART_LPUEN_DMAR_MASK)

#define LPUART_LPUEN_DMAT_SHIFT                 (2)
#define LPUART_LPUEN_DMAT_MASK                  (0x1U << LPUART_LPUEN_DMAT_SHIFT)
#define LPUART_LPUEN_DMAT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUEN_DMAT_SHIFT)) & LPUART_LPUEN_DMAT_MASK)

#define LPUART_LPUEN_RXEN_SHIFT                 (1)
#define LPUART_LPUEN_RXEN_MASK                  (0x1U << LPUART_LPUEN_RXEN_SHIFT)
#define LPUART_LPUEN_RXEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUEN_RXEN_SHIFT)) & LPUART_LPUEN_RXEN_MASK)

#define LPUART_LPUEN_TXEN_SHIFT                 (0)
#define LPUART_LPUEN_TXEN_MASK                  (0x1U << LPUART_LPUEN_TXEN_SHIFT)
#define LPUART_LPUEN_TXEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_LPUEN_TXEN_SHIFT)) & LPUART_LPUEN_TXEN_MASK)

/*!
 * @brief LPUART_LPURXD Register Bit Definition
 */

#define LPUART_LPURXD_DATA_SHIFT                (0)
#define LPUART_LPURXD_DATA_MASK                 (0xFFU << LPUART_LPURXD_DATA_SHIFT)
#define LPUART_LPURXD_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPURXD_DATA_SHIFT)) & LPUART_LPURXD_DATA_MASK)

/*!
 * @brief LPUART_LPUTXD Register Bit Definition
 */

#define LPUART_LPUTXD_DATA_SHIFT                (0)
#define LPUART_LPUTXD_DATA_MASK                 (0xFFU << LPUART_LPUTXD_DATA_SHIFT)
#define LPUART_LPUTXD_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_LPUTXD_DATA_SHIFT)) & LPUART_LPUTXD_DATA_MASK)

/*!
 * @brief LPUART_COMPARE Register Bit Definition
 */

#define LPUART_COMPARE_COMPARE_SHIFT            (0)
#define LPUART_COMPARE_COMPARE_MASK             (0xFFU << LPUART_COMPARE_COMPARE_SHIFT)
#define LPUART_COMPARE_COMPARE(x)               (((uint32_t)(((uint32_t)(x)) << LPUART_COMPARE_COMPARE_SHIFT)) & LPUART_COMPARE_COMPARE_MASK)

/*!
 * @brief LPUART_WKCKE Register Bit Definition
 */

#define LPUART_WKCKE_WKCKE_SHIFT                (0)
#define LPUART_WKCKE_WKCKE_MASK                 (0x1U << LPUART_WKCKE_WKCKE_SHIFT)
#define LPUART_WKCKE_WKCKE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_WKCKE_WKCKE_SHIFT)) & LPUART_WKCKE_WKCKE_MASK)

/*!
 * @}
 */ /* end of group LPUART_Register_Masks */
/******************************************************************************
 *LPUART Instance
*******************************************************************************/

#define LPUART               ((LPUART_Type*)LPUART_BASE)

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */



/*!
 * @addtogroup PWR_Peripheral_Access_Layer PWR Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * PWR Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR;                                                           ///< Power control register                       offset: 0x00
    __IO uint32_t CSR;                                                          ///< Power control status register                offset: 0x04
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t CR1;                                                          ///< Power control register 1                     offset: 0x0C
    __IO uint32_t SR1;                                                          ///< Power status register 1                      offset: 0x10
    __IO uint32_t SCR;                                                          ///< Power status clear register                  offset: 0x14
    __IO uint32_t Reserved1[3];                                                 ///< Reserved
    __IO uint32_t CFGR;                                                         ///< Power configuration register                 offset: 0x24
} PWR_Type;

/*******************************************************************************
 * PWR Type
 ******************************************************************************/

/*!
 * @addtogroup PWR_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief PWR_CR Register Bit Definition
 */

#define PWR_CR_STDBYFSWK_SHIFT                  (14)
#define PWR_CR_STDBYFSWK_MASK                   (0x3U << PWR_CR_STDBYFSWK_SHIFT)
#define PWR_CR_STDBYFSWK(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR_STDBYFSWK_SHIFT)) & PWR_CR_STDBYFSWK_MASK)

#define PWR_CR_PLS_SHIFT                        (9)
#define PWR_CR_PLS_MASK                         (0xFU << PWR_CR_PLS_SHIFT)
#define PWR_CR_PLS(x)                           (((uint32_t)(((uint32_t)(x)) << PWR_CR_PLS_SHIFT)) & PWR_CR_PLS_MASK)

#define PWR_CR_PVDE_SHIFT                       (4)
#define PWR_CR_PVDE_MASK                        (0x1U << PWR_CR_PVDE_SHIFT)
#define PWR_CR_PVDE(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CR_PVDE_SHIFT)) & PWR_CR_PVDE_MASK)

#define PWR_CR_CSBF_SHIFT                       (3)
#define PWR_CR_CSBF_MASK                        (0x1U << PWR_CR_CSBF_SHIFT)
#define PWR_CR_CSBF(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CR_CSBF_SHIFT)) & PWR_CR_CSBF_MASK)

#define PWR_CR_CWUF_SHIFT                       (2)
#define PWR_CR_CWUF_MASK                        (0x1U << PWR_CR_CWUF_SHIFT)
#define PWR_CR_CWUF(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CR_CWUF_SHIFT)) & PWR_CR_CWUF_MASK)

#define PWR_CR_PDDS_SHIFT                       (1)
#define PWR_CR_PDDS_MASK                        (0x1U << PWR_CR_PDDS_SHIFT)
#define PWR_CR_PDDS(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CR_PDDS_SHIFT)) & PWR_CR_PDDS_MASK)

#define PWR_CR_LPDS_SHIFT                       (0)
#define PWR_CR_LPDS_MASK                        (0x1U << PWR_CR_LPDS_SHIFT)
#define PWR_CR_LPDS(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CR_LPDS_SHIFT)) & PWR_CR_LPDS_MASK)

/*!
 * @brief PWR_CSR Register Bit Definition
 */

#define PWR_CSR_EWUP6_SHIFT                     (13)
#define PWR_CSR_EWUP6_MASK                      (0x1U << PWR_CSR_EWUP6_SHIFT)
#define PWR_CSR_EWUP6(x)                        (((uint32_t)(((uint32_t)(x)) << PWR_CSR_EWUP6_SHIFT)) & PWR_CSR_EWUP6_MASK)

#define PWR_CSR_EWUP5_SHIFT                     (12)
#define PWR_CSR_EWUP5_MASK                      (0x1U << PWR_CSR_EWUP5_SHIFT)
#define PWR_CSR_EWUP5(x)                        (((uint32_t)(((uint32_t)(x)) << PWR_CSR_EWUP5_SHIFT)) & PWR_CSR_EWUP5_MASK)

#define PWR_CSR_EWUP4_SHIFT                     (11)
#define PWR_CSR_EWUP4_MASK                      (0x1U << PWR_CSR_EWUP4_SHIFT)
#define PWR_CSR_EWUP4(x)                        (((uint32_t)(((uint32_t)(x)) << PWR_CSR_EWUP4_SHIFT)) & PWR_CSR_EWUP4_MASK)

#define PWR_CSR_EWUP2_SHIFT                     (9)
#define PWR_CSR_EWUP2_MASK                      (0x1U << PWR_CSR_EWUP2_SHIFT)
#define PWR_CSR_EWUP2(x)                        (((uint32_t)(((uint32_t)(x)) << PWR_CSR_EWUP2_SHIFT)) & PWR_CSR_EWUP2_MASK)

#define PWR_CSR_EWUP1_SHIFT                     (8)
#define PWR_CSR_EWUP1_MASK                      (0x1U << PWR_CSR_EWUP1_SHIFT)
#define PWR_CSR_EWUP1(x)                        (((uint32_t)(((uint32_t)(x)) << PWR_CSR_EWUP1_SHIFT)) & PWR_CSR_EWUP1_MASK)

#define PWR_CSR_PVDO_SHIFT                      (2)
#define PWR_CSR_PVDO_MASK                       (0x1U << PWR_CSR_PVDO_SHIFT)
#define PWR_CSR_PVDO(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_CSR_PVDO_SHIFT)) & PWR_CSR_PVDO_MASK)

#define PWR_CSR_SBF_SHIFT                       (1)
#define PWR_CSR_SBF_MASK                        (0x1U << PWR_CSR_SBF_SHIFT)
#define PWR_CSR_SBF(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CSR_SBF_SHIFT)) & PWR_CSR_SBF_MASK)

#define PWR_CSR_WUF_SHIFT                       (0)
#define PWR_CSR_WUF_MASK                        (0x1U << PWR_CSR_WUF_SHIFT)
#define PWR_CSR_WUF(x)                          (((uint32_t)(((uint32_t)(x)) << PWR_CSR_WUF_SHIFT)) & PWR_CSR_WUF_MASK)

/*!
 * @brief PWR_CR1 Register Bit Definition
 */

#define PWR_CR1_WKPEDGE6_SHIFT                  (5)
#define PWR_CR1_WKPEDGE6_MASK                   (0x1U << PWR_CR1_WKPEDGE6_SHIFT)
#define PWR_CR1_WKPEDGE6(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR1_WKPEDGE6_SHIFT)) & PWR_CR1_WKPEDGE6_MASK)

#define PWR_CR1_WKPEDGE5_SHIFT                  (4)
#define PWR_CR1_WKPEDGE5_MASK                   (0x1U << PWR_CR1_WKPEDGE5_SHIFT)
#define PWR_CR1_WKPEDGE5(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR1_WKPEDGE5_SHIFT)) & PWR_CR1_WKPEDGE5_MASK)

#define PWR_CR1_WKPEDGE4_SHIFT                  (3)
#define PWR_CR1_WKPEDGE4_MASK                   (0x1U << PWR_CR1_WKPEDGE4_SHIFT)
#define PWR_CR1_WKPEDGE4(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR1_WKPEDGE4_SHIFT)) & PWR_CR1_WKPEDGE4_MASK)

#define PWR_CR1_WKPEDGE2_SHIFT                  (1)
#define PWR_CR1_WKPEDGE2_MASK                   (0x1U << PWR_CR1_WKPEDGE2_SHIFT)
#define PWR_CR1_WKPEDGE2(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR1_WKPEDGE2_SHIFT)) & PWR_CR1_WKPEDGE2_MASK)

#define PWR_CR1_WKPEDGE1_SHIFT                  (0)
#define PWR_CR1_WKPEDGE1_MASK                   (0x1U << PWR_CR1_WKPEDGE1_SHIFT)
#define PWR_CR1_WKPEDGE1(x)                     (((uint32_t)(((uint32_t)(x)) << PWR_CR1_WKPEDGE1_SHIFT)) & PWR_CR1_WKPEDGE1_MASK)

/*!
 * @brief PWR_SR1 Register Bit Definition
 */

#define PWR_SR1_WUF6_SHIFT                      (5)
#define PWR_SR1_WUF6_MASK                       (0x1U << PWR_SR1_WUF6_SHIFT)
#define PWR_SR1_WUF6(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_SR1_WUF6_SHIFT)) & PWR_SR1_WUF6_MASK)

#define PWR_SR1_WUF5_SHIFT                      (4)
#define PWR_SR1_WUF5_MASK                       (0x1U << PWR_SR1_WUF5_SHIFT)
#define PWR_SR1_WUF5(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_SR1_WUF5_SHIFT)) & PWR_SR1_WUF5_MASK)

#define PWR_SR1_WUF4_SHIFT                      (3)
#define PWR_SR1_WUF4_MASK                       (0x1U << PWR_SR1_WUF4_SHIFT)
#define PWR_SR1_WUF4(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_SR1_WUF4_SHIFT)) & PWR_SR1_WUF4_MASK)

#define PWR_SR1_WUF2_SHIFT                      (1)
#define PWR_SR1_WUF2_MASK                       (0x1U << PWR_SR1_WUF2_SHIFT)
#define PWR_SR1_WUF2(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_SR1_WUF2_SHIFT)) & PWR_SR1_WUF2_MASK)

#define PWR_SR1_WUF1_SHIFT                      (0)
#define PWR_SR1_WUF1_MASK                       (0x1U << PWR_SR1_WUF1_SHIFT)
#define PWR_SR1_WUF1(x)                         (((uint32_t)(((uint32_t)(x)) << PWR_SR1_WUF1_SHIFT)) & PWR_SR1_WUF1_MASK)

/*!
 * @brief PWR_SCR Register Bit Definition
 */

#define PWR_SCR_WUF6CLR_SHIFT                   (5)
#define PWR_SCR_WUF6CLR_MASK                    (0x1U << PWR_SCR_WUF6CLR_SHIFT)
#define PWR_SCR_WUF6CLR(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_SCR_WUF6CLR_SHIFT)) & PWR_SCR_WUF6CLR_MASK)

#define PWR_SCR_WUF5CLR_SHIFT                   (4)
#define PWR_SCR_WUF5CLR_MASK                    (0x1U << PWR_SCR_WUF5CLR_SHIFT)
#define PWR_SCR_WUF5CLR(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_SCR_WUF5CLR_SHIFT)) & PWR_SCR_WUF5CLR_MASK)

#define PWR_SCR_WUF4CLR_SHIFT                   (3)
#define PWR_SCR_WUF4CLR_MASK                    (0x1U << PWR_SCR_WUF4CLR_SHIFT)
#define PWR_SCR_WUF4CLR(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_SCR_WUF4CLR_SHIFT)) & PWR_SCR_WUF4CLR_MASK)

#define PWR_SCR_WUF2CLR_SHIFT                   (1)
#define PWR_SCR_WUF2CLR_MASK                    (0x1U << PWR_SCR_WUF2CLR_SHIFT)
#define PWR_SCR_WUF2CLR(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_SCR_WUF2CLR_SHIFT)) & PWR_SCR_WUF2CLR_MASK)

#define PWR_SCR_WUF1CLR_SHIFT                   (0)
#define PWR_SCR_WUF1CLR_MASK                    (0x1U << PWR_SCR_WUF1CLR_SHIFT)
#define PWR_SCR_WUF1CLR(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_SCR_WUF1CLR_SHIFT)) & PWR_SCR_WUF1CLR_MASK)

/*!
 * @brief PWR_CFGR Register Bit Definition
 */

#define PWR_CFGR_LSICAL_SHIFT                   (5)
#define PWR_CFGR_LSICAL_MASK                    (0x1FU << PWR_CFGR_LSICAL_SHIFT)
#define PWR_CFGR_LSICAL(x)                      (((uint32_t)(((uint32_t)(x)) << PWR_CFGR_LSICAL_SHIFT)) & PWR_CFGR_LSICAL_MASK)

#define PWR_CFGR_LSICALSEL_SHIFT                (0)
#define PWR_CFGR_LSICALSEL_MASK                 (0x1FU << PWR_CFGR_LSICALSEL_SHIFT)
#define PWR_CFGR_LSICALSEL(x)                   (((uint32_t)(((uint32_t)(x)) << PWR_CFGR_LSICALSEL_SHIFT)) & PWR_CFGR_LSICALSEL_MASK)

/*!
 * @}
 */ /* end of group PWR_Register_Masks */
/******************************************************************************
 *PWR Instance
*******************************************************************************/

#define PWR                  ((PWR_Type*)PWR_BASE)

/*!
 * @}
 */ /* end of group PWR_Peripheral_Access_Layer */



/*!
 * @addtogroup RCC_Peripheral_Access_Layer RCC Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * RCC Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR;                                                           ///< Clock Control Register                       offset: 0x00
    __IO uint32_t CFGR;                                                         ///< Clock Configuration Register                 offset: 0x04
    __IO uint32_t CIR;                                                          ///< Clock Interrupt Register                     offset: 0x08
    __IO uint32_t APB2RSTR;                                                     ///< APB2 Peripheral Reset Register               offset: 0x0C
    __IO uint32_t APB1RSTR;                                                     ///< APB1 Peripheral Reset Register               offset: 0x10
    __IO uint32_t AHBENR;                                                       ///< AHB Peripheral Clock Enable Register         offset: 0x14
    __IO uint32_t APB2ENR;                                                      ///< APB2 Peripheral Clock Enable Register        offset: 0x18
    __IO uint32_t APB1ENR;                                                      ///< APB1 Peripheral Clock Enable Register        offset: 0x1C
    __IO uint32_t BDCR;                                                         ///< Backup Domain Control Register               offset: 0x20
    __IO uint32_t CSR;                                                          ///< Control Status Register                      offset: 0x24
    __IO uint32_t AHBRSTR;                                                      ///< AHB Peripheral Reset Register                offset: 0x28
    __IO uint32_t CFGR2;                                                        ///< Clock Configuration Register 2               offset: 0x2C
    __IO uint32_t Reserved0[4];                                                 ///< Reserved
    __IO uint32_t SYSCFG;                                                       ///< System Configuration Register                offset: 0x40
    __IO uint32_t Reserved1[2];                                                 ///< Reserved
    __IO uint32_t ICSCR;                                                        ///< Internal Clock Source Calibration Register   offset: 0x4C
    __IO uint32_t PLL1CFGR;                                                     ///< PLL1 Configuration Register                  offset: 0x50
    __IO uint32_t PLL2CFGR;                                                     ///< PLL2 Configuration Register                  offset: 0x54
} RCC_Type;

/*******************************************************************************
 * RCC Type
 ******************************************************************************/

/*!
 * @addtogroup RCC_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief RCC_CR Register Bit Definition
 */

#define RCC_CR_PLL2RDY_SHIFT                    (29)
#define RCC_CR_PLL2RDY_MASK                     (0x1U << RCC_CR_PLL2RDY_SHIFT)
#define RCC_CR_PLL2RDY(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_CR_PLL2RDY_SHIFT)) & RCC_CR_PLL2RDY_MASK)

#define RCC_CR_PLL2ON_SHIFT                     (28)
#define RCC_CR_PLL2ON_MASK                      (0x1U << RCC_CR_PLL2ON_SHIFT)
#define RCC_CR_PLL2ON(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_PLL2ON_SHIFT)) & RCC_CR_PLL2ON_MASK)

#define RCC_CR_PLL1RDY_SHIFT                    (25)
#define RCC_CR_PLL1RDY_MASK                     (0x1U << RCC_CR_PLL1RDY_SHIFT)
#define RCC_CR_PLL1RDY(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_CR_PLL1RDY_SHIFT)) & RCC_CR_PLL1RDY_MASK)

#define RCC_CR_PLL1ON_SHIFT                     (24)
#define RCC_CR_PLL1ON_MASK                      (0x1U << RCC_CR_PLL1ON_SHIFT)
#define RCC_CR_PLL1ON(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_PLL1ON_SHIFT)) & RCC_CR_PLL1ON_MASK)

#define RCC_CR_CSSON_SHIFT                      (19)
#define RCC_CR_CSSON_MASK                       (0x1U << RCC_CR_CSSON_SHIFT)
#define RCC_CR_CSSON(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CR_CSSON_SHIFT)) & RCC_CR_CSSON_MASK)

#define RCC_CR_HSEBYP_SHIFT                     (18)
#define RCC_CR_HSEBYP_MASK                      (0x1U << RCC_CR_HSEBYP_SHIFT)
#define RCC_CR_HSEBYP(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSEBYP_SHIFT)) & RCC_CR_HSEBYP_MASK)

#define RCC_CR_HSERDY_SHIFT                     (17)
#define RCC_CR_HSERDY_MASK                      (0x1U << RCC_CR_HSERDY_SHIFT)
#define RCC_CR_HSERDY(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSERDY_SHIFT)) & RCC_CR_HSERDY_MASK)

#define RCC_CR_HSEON_SHIFT                      (16)
#define RCC_CR_HSEON_MASK                       (0x1U << RCC_CR_HSEON_SHIFT)
#define RCC_CR_HSEON(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSEON_SHIFT)) & RCC_CR_HSEON_MASK)

#define RCC_CR_HSIDIV_SHIFT                     (11)
#define RCC_CR_HSIDIV_MASK                      (0x7U << RCC_CR_HSIDIV_SHIFT)
#define RCC_CR_HSIDIV(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSIDIV_SHIFT)) & RCC_CR_HSIDIV_MASK)

#define RCC_CR_HSEOUTPUTSEL_SHIFT               (8)
#define RCC_CR_HSEOUTPUTSEL_MASK                (0x1U << RCC_CR_HSEOUTPUTSEL_SHIFT)
#define RCC_CR_HSEOUTPUTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSEOUTPUTSEL_SHIFT)) & RCC_CR_HSEOUTPUTSEL_MASK)

#define RCC_CR_HSEDEGLITCHSEL_SHIFT             (7)
#define RCC_CR_HSEDEGLITCHSEL_MASK              (0x1U << RCC_CR_HSEDEGLITCHSEL_SHIFT)
#define RCC_CR_HSEDEGLITCHSEL(x)                (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSEDEGLITCHSEL_SHIFT)) & RCC_CR_HSEDEGLITCHSEL_MASK)

#define RCC_CR_HSEDEGLITCHBYP_SHIFT             (6)
#define RCC_CR_HSEDEGLITCHBYP_MASK              (0x1U << RCC_CR_HSEDEGLITCHBYP_SHIFT)
#define RCC_CR_HSEDEGLITCHBYP(x)                (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSEDEGLITCHBYP_SHIFT)) & RCC_CR_HSEDEGLITCHBYP_MASK)

#define RCC_CR_HSELPFSEL_SHIFT                  (5)
#define RCC_CR_HSELPFSEL_MASK                   (0x1U << RCC_CR_HSELPFSEL_SHIFT)
#define RCC_CR_HSELPFSEL(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSELPFSEL_SHIFT)) & RCC_CR_HSELPFSEL_MASK)

#define RCC_CR_HSELPFBYP_SHIFT                  (4)
#define RCC_CR_HSELPFBYP_MASK                   (0x1U << RCC_CR_HSELPFBYP_SHIFT)
#define RCC_CR_HSELPFBYP(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSELPFBYP_SHIFT)) & RCC_CR_HSELPFBYP_MASK)

#define RCC_CR_HSIRDY_SHIFT                     (1)
#define RCC_CR_HSIRDY_MASK                      (0x1U << RCC_CR_HSIRDY_SHIFT)
#define RCC_CR_HSIRDY(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSIRDY_SHIFT)) & RCC_CR_HSIRDY_MASK)

#define RCC_CR_HSION_SHIFT                      (0)
#define RCC_CR_HSION_MASK                       (0x1U << RCC_CR_HSION_SHIFT)
#define RCC_CR_HSION(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CR_HSION_SHIFT)) & RCC_CR_HSION_MASK)

/*!
 * @brief RCC_CFGR Register Bit Definition
 */

#define RCC_CFGR_MCO_SHIFT                      (24)
#define RCC_CFGR_MCO_MASK                       (0x7U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_MCO_SHIFT)) & RCC_CFGR_MCO_MASK)

#define RCC_CFGR_USBPRE_SHIFT                   (22)
#define RCC_CFGR_USBPRE_MASK                    (0x3U << RCC_CFGR_USBPRE_SHIFT)
#define RCC_CFGR_USBPRE(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_USBPRE_SHIFT)) & RCC_CFGR_USBPRE_MASK)

#define RCC_CFGR_USBCLKSEL_SHIFT                (19)
#define RCC_CFGR_USBCLKSEL_MASK                 (0x1U << RCC_CFGR_USBCLKSEL_SHIFT)
#define RCC_CFGR_USBCLKSEL(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_USBCLKSEL_SHIFT)) & RCC_CFGR_USBCLKSEL_MASK)

#define RCC_CFGR_PPRE2_SHIFT                    (11)
#define RCC_CFGR_PPRE2_MASK                     (0x7U << RCC_CFGR_PPRE2_SHIFT)
#define RCC_CFGR_PPRE2(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_PPRE2_SHIFT)) & RCC_CFGR_PPRE2_MASK)

#define RCC_CFGR_PPRE1_SHIFT                    (8)
#define RCC_CFGR_PPRE1_MASK                     (0x7U << RCC_CFGR_PPRE1_SHIFT)
#define RCC_CFGR_PPRE1(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_PPRE1_SHIFT)) & RCC_CFGR_PPRE1_MASK)

#define RCC_CFGR_HPRE_SHIFT                     (4)
#define RCC_CFGR_HPRE_MASK                      (0xFU << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_HPRE_SHIFT)) & RCC_CFGR_HPRE_MASK)

#define RCC_CFGR_SWS_SHIFT                      (2)
#define RCC_CFGR_SWS_MASK                       (0x3U << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_SWS_SHIFT)) & RCC_CFGR_SWS_MASK)

#define RCC_CFGR_SW_SHIFT                       (0)
#define RCC_CFGR_SW_MASK                        (0x3U << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW(x)                          (((uint32_t)(((uint32_t)(x)) << RCC_CFGR_SW_SHIFT)) & RCC_CFGR_SW_MASK)

/*!
 * @brief RCC_CIR Register Bit Definition
 */

#define RCC_CIR_CSSC_SHIFT                      (23)
#define RCC_CIR_CSSC_MASK                       (0x1U << RCC_CIR_CSSC_SHIFT)
#define RCC_CIR_CSSC(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CIR_CSSC_SHIFT)) & RCC_CIR_CSSC_MASK)

#define RCC_CIR_PLL2RDYC_SHIFT                  (21)
#define RCC_CIR_PLL2RDYC_MASK                   (0x1U << RCC_CIR_PLL2RDYC_SHIFT)
#define RCC_CIR_PLL2RDYC(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_PLL2RDYC_SHIFT)) & RCC_CIR_PLL2RDYC_MASK)

#define RCC_CIR_PLL1RDYC_SHIFT                  (20)
#define RCC_CIR_PLL1RDYC_MASK                   (0x1U << RCC_CIR_PLL1RDYC_SHIFT)
#define RCC_CIR_PLL1RDYC(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_PLL1RDYC_SHIFT)) & RCC_CIR_PLL1RDYC_MASK)

#define RCC_CIR_HSERDYC_SHIFT                   (19)
#define RCC_CIR_HSERDYC_MASK                    (0x1U << RCC_CIR_HSERDYC_SHIFT)
#define RCC_CIR_HSERDYC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSERDYC_SHIFT)) & RCC_CIR_HSERDYC_MASK)

#define RCC_CIR_HSIRDYC_SHIFT                   (18)
#define RCC_CIR_HSIRDYC_MASK                    (0x1U << RCC_CIR_HSIRDYC_SHIFT)
#define RCC_CIR_HSIRDYC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSIRDYC_SHIFT)) & RCC_CIR_HSIRDYC_MASK)

#define RCC_CIR_LSERDYC_SHIFT                   (17)
#define RCC_CIR_LSERDYC_MASK                    (0x1U << RCC_CIR_LSERDYC_SHIFT)
#define RCC_CIR_LSERDYC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSERDYC_SHIFT)) & RCC_CIR_LSERDYC_MASK)

#define RCC_CIR_LSIRDYC_SHIFT                   (16)
#define RCC_CIR_LSIRDYC_MASK                    (0x1U << RCC_CIR_LSIRDYC_SHIFT)
#define RCC_CIR_LSIRDYC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSIRDYC_SHIFT)) & RCC_CIR_LSIRDYC_MASK)

#define RCC_CIR_PLL1RDYIE_SHIFT                 (12)
#define RCC_CIR_PLL1RDYIE_MASK                  (0x1U << RCC_CIR_PLL1RDYIE_SHIFT)
#define RCC_CIR_PLL1RDYIE(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_CIR_PLL1RDYIE_SHIFT)) & RCC_CIR_PLL1RDYIE_MASK)

#define RCC_CIR_HSERDYIE_SHIFT                  (11)
#define RCC_CIR_HSERDYIE_MASK                   (0x1U << RCC_CIR_HSERDYIE_SHIFT)
#define RCC_CIR_HSERDYIE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSERDYIE_SHIFT)) & RCC_CIR_HSERDYIE_MASK)

#define RCC_CIR_HSIRDYIE_SHIFT                  (10)
#define RCC_CIR_HSIRDYIE_MASK                   (0x1U << RCC_CIR_HSIRDYIE_SHIFT)
#define RCC_CIR_HSIRDYIE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSIRDYIE_SHIFT)) & RCC_CIR_HSIRDYIE_MASK)

#define RCC_CIR_LSERDYIE_SHIFT                  (9)
#define RCC_CIR_LSERDYIE_MASK                   (0x1U << RCC_CIR_LSERDYIE_SHIFT)
#define RCC_CIR_LSERDYIE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSERDYIE_SHIFT)) & RCC_CIR_LSERDYIE_MASK)

#define RCC_CIR_LSIRDYIE_SHIFT                  (8)
#define RCC_CIR_LSIRDYIE_MASK                   (0x1U << RCC_CIR_LSIRDYIE_SHIFT)
#define RCC_CIR_LSIRDYIE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSIRDYIE_SHIFT)) & RCC_CIR_LSIRDYIE_MASK)

#define RCC_CIR_CSSF_SHIFT                      (7)
#define RCC_CIR_CSSF_MASK                       (0x1U << RCC_CIR_CSSF_SHIFT)
#define RCC_CIR_CSSF(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CIR_CSSF_SHIFT)) & RCC_CIR_CSSF_MASK)

#define RCC_CIR_PLL2RDYF_SHIFT                  (5)
#define RCC_CIR_PLL2RDYF_MASK                   (0x1U << RCC_CIR_PLL2RDYF_SHIFT)
#define RCC_CIR_PLL2RDYF(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_PLL2RDYF_SHIFT)) & RCC_CIR_PLL2RDYF_MASK)

#define RCC_CIR_PLL1RDYF_SHIFT                  (4)
#define RCC_CIR_PLL1RDYF_MASK                   (0x1U << RCC_CIR_PLL1RDYF_SHIFT)
#define RCC_CIR_PLL1RDYF(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CIR_PLL1RDYF_SHIFT)) & RCC_CIR_PLL1RDYF_MASK)

#define RCC_CIR_HSERDYF_SHIFT                   (3)
#define RCC_CIR_HSERDYF_MASK                    (0x1U << RCC_CIR_HSERDYF_SHIFT)
#define RCC_CIR_HSERDYF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSERDYF_SHIFT)) & RCC_CIR_HSERDYF_MASK)

#define RCC_CIR_HSIRDYF_SHIFT                   (2)
#define RCC_CIR_HSIRDYF_MASK                    (0x1U << RCC_CIR_HSIRDYF_SHIFT)
#define RCC_CIR_HSIRDYF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_HSIRDYF_SHIFT)) & RCC_CIR_HSIRDYF_MASK)

#define RCC_CIR_LSERDYF_SHIFT                   (1)
#define RCC_CIR_LSERDYF_MASK                    (0x1U << RCC_CIR_LSERDYF_SHIFT)
#define RCC_CIR_LSERDYF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSERDYF_SHIFT)) & RCC_CIR_LSERDYF_MASK)

#define RCC_CIR_LSIRDYF_SHIFT                   (0)
#define RCC_CIR_LSIRDYF_MASK                    (0x1U << RCC_CIR_LSIRDYF_SHIFT)
#define RCC_CIR_LSIRDYF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CIR_LSIRDYF_SHIFT)) & RCC_CIR_LSIRDYF_MASK)

/*!
 * @brief RCC_APB2RSTR Register Bit Definition
 */

#define RCC_APB2RSTR_LPUART_SHIFT               (31)
#define RCC_APB2RSTR_LPUART_MASK                (0x1U << RCC_APB2RSTR_LPUART_SHIFT)
#define RCC_APB2RSTR_LPUART(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_LPUART_SHIFT)) & RCC_APB2RSTR_LPUART_MASK)

#define RCC_APB2RSTR_LPTIM_SHIFT                (30)
#define RCC_APB2RSTR_LPTIM_MASK                 (0x1U << RCC_APB2RSTR_LPTIM_SHIFT)
#define RCC_APB2RSTR_LPTIM(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_LPTIM_SHIFT)) & RCC_APB2RSTR_LPTIM_MASK)

#define RCC_APB2RSTR_DBG_SHIFT                  (22)
#define RCC_APB2RSTR_DBG_MASK                   (0x1U << RCC_APB2RSTR_DBG_SHIFT)
#define RCC_APB2RSTR_DBG(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_DBG_SHIFT)) & RCC_APB2RSTR_DBG_MASK)

#define RCC_APB2RSTR_TIM17_SHIFT                (18)
#define RCC_APB2RSTR_TIM17_MASK                 (0x1U << RCC_APB2RSTR_TIM17_SHIFT)
#define RCC_APB2RSTR_TIM17(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_TIM17_SHIFT)) & RCC_APB2RSTR_TIM17_MASK)

#define RCC_APB2RSTR_TIM16_SHIFT                (17)
#define RCC_APB2RSTR_TIM16_MASK                 (0x1U << RCC_APB2RSTR_TIM16_SHIFT)
#define RCC_APB2RSTR_TIM16(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_TIM16_SHIFT)) & RCC_APB2RSTR_TIM16_MASK)

#define RCC_APB2RSTR_TIM14_SHIFT                (16)
#define RCC_APB2RSTR_TIM14_MASK                 (0x1U << RCC_APB2RSTR_TIM14_SHIFT)
#define RCC_APB2RSTR_TIM14(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_TIM14_SHIFT)) & RCC_APB2RSTR_TIM14_MASK)

#define RCC_APB2RSTR_CPT_SHIFT                  (15)
#define RCC_APB2RSTR_CPT_MASK                   (0x1U << RCC_APB2RSTR_CPT_SHIFT)
#define RCC_APB2RSTR_CPT(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_CPT_SHIFT)) & RCC_APB2RSTR_CPT_MASK)

#define RCC_APB2RSTR_UART1_SHIFT                (14)
#define RCC_APB2RSTR_UART1_MASK                 (0x1U << RCC_APB2RSTR_UART1_SHIFT)
#define RCC_APB2RSTR_UART1(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_UART1_SHIFT)) & RCC_APB2RSTR_UART1_MASK)

#define RCC_APB2RSTR_SPI1_SHIFT                 (12)
#define RCC_APB2RSTR_SPI1_MASK                  (0x1U << RCC_APB2RSTR_SPI1_SHIFT)
#define RCC_APB2RSTR_SPI1(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_SPI1_SHIFT)) & RCC_APB2RSTR_SPI1_MASK)

#define RCC_APB2RSTR_TIM1_SHIFT                 (11)
#define RCC_APB2RSTR_TIM1_MASK                  (0x1U << RCC_APB2RSTR_TIM1_SHIFT)
#define RCC_APB2RSTR_TIM1(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_TIM1_SHIFT)) & RCC_APB2RSTR_TIM1_MASK)

#define RCC_APB2RSTR_ADC_SHIFT                  (9)
#define RCC_APB2RSTR_ADC_MASK                   (0x1U << RCC_APB2RSTR_ADC_SHIFT)
#define RCC_APB2RSTR_ADC(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_ADC_SHIFT)) & RCC_APB2RSTR_ADC_MASK)

#define RCC_APB2RSTR_SYSCFG_SHIFT               (0)
#define RCC_APB2RSTR_SYSCFG_MASK                (0x1U << RCC_APB2RSTR_SYSCFG_SHIFT)
#define RCC_APB2RSTR_SYSCFG(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_APB2RSTR_SYSCFG_SHIFT)) & RCC_APB2RSTR_SYSCFG_MASK)

/*!
 * @brief RCC_APB1RSTR Register Bit Definition
 */

#define RCC_APB1RSTR_RTC_SHIFT                  (31)
#define RCC_APB1RSTR_RTC_MASK                   (0x1U << RCC_APB1RSTR_RTC_SHIFT)
#define RCC_APB1RSTR_RTC(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_RTC_SHIFT)) & RCC_APB1RSTR_RTC_MASK)

#define RCC_APB1RSTR_PWR_SHIFT                  (28)
#define RCC_APB1RSTR_PWR_MASK                   (0x1U << RCC_APB1RSTR_PWR_SHIFT)
#define RCC_APB1RSTR_PWR(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_PWR_SHIFT)) & RCC_APB1RSTR_PWR_MASK)

#define RCC_APB1RSTR_CRS_SHIFT                  (27)
#define RCC_APB1RSTR_CRS_MASK                   (0x1U << RCC_APB1RSTR_CRS_SHIFT)
#define RCC_APB1RSTR_CRS(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_CRS_SHIFT)) & RCC_APB1RSTR_CRS_MASK)

#define RCC_APB1RSTR_FLEXCAN_SHIFT              (25)
#define RCC_APB1RSTR_FLEXCAN_MASK               (0x1U << RCC_APB1RSTR_FLEXCAN_SHIFT)
#define RCC_APB1RSTR_FLEXCAN(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_FLEXCAN_SHIFT)) & RCC_APB1RSTR_FLEXCAN_MASK)

#define RCC_APB1RSTR_BKP_SHIFT                  (24)
#define RCC_APB1RSTR_BKP_MASK                   (0x1U << RCC_APB1RSTR_BKP_SHIFT)
#define RCC_APB1RSTR_BKP(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_BKP_SHIFT)) & RCC_APB1RSTR_BKP_MASK)

#define RCC_APB1RSTR_I2C1_SHIFT                 (21)
#define RCC_APB1RSTR_I2C1_MASK                  (0x1U << RCC_APB1RSTR_I2C1_SHIFT)
#define RCC_APB1RSTR_I2C1(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_I2C1_SHIFT)) & RCC_APB1RSTR_I2C1_MASK)

#define RCC_APB1RSTR_UART4_SHIFT                (19)
#define RCC_APB1RSTR_UART4_MASK                 (0x1U << RCC_APB1RSTR_UART4_SHIFT)
#define RCC_APB1RSTR_UART4(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_UART4_SHIFT)) & RCC_APB1RSTR_UART4_MASK)

#define RCC_APB1RSTR_UART3_SHIFT                (18)
#define RCC_APB1RSTR_UART3_MASK                 (0x1U << RCC_APB1RSTR_UART3_SHIFT)
#define RCC_APB1RSTR_UART3(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_UART3_SHIFT)) & RCC_APB1RSTR_UART3_MASK)

#define RCC_APB1RSTR_UART2_SHIFT                (17)
#define RCC_APB1RSTR_UART2_MASK                 (0x1U << RCC_APB1RSTR_UART2_SHIFT)
#define RCC_APB1RSTR_UART2(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_UART2_SHIFT)) & RCC_APB1RSTR_UART2_MASK)

#define RCC_APB1RSTR_SPI2_SHIFT                 (14)
#define RCC_APB1RSTR_SPI2_MASK                  (0x1U << RCC_APB1RSTR_SPI2_SHIFT)
#define RCC_APB1RSTR_SPI2(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_SPI2_SHIFT)) & RCC_APB1RSTR_SPI2_MASK)

#define RCC_APB1RSTR_WWDG_SHIFT                 (11)
#define RCC_APB1RSTR_WWDG_MASK                  (0x1U << RCC_APB1RSTR_WWDG_SHIFT)
#define RCC_APB1RSTR_WWDG(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_WWDG_SHIFT)) & RCC_APB1RSTR_WWDG_MASK)

#define RCC_APB1RSTR_I3C_SHIFT                  (6)
#define RCC_APB1RSTR_I3C_MASK                   (0x1U << RCC_APB1RSTR_I3C_SHIFT)
#define RCC_APB1RSTR_I3C(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_I3C_SHIFT)) & RCC_APB1RSTR_I3C_MASK)

#define RCC_APB1RSTR_TIM3_SHIFT                 (1)
#define RCC_APB1RSTR_TIM3_MASK                  (0x1U << RCC_APB1RSTR_TIM3_SHIFT)
#define RCC_APB1RSTR_TIM3(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_TIM3_SHIFT)) & RCC_APB1RSTR_TIM3_MASK)

#define RCC_APB1RSTR_TIM2_SHIFT                 (0)
#define RCC_APB1RSTR_TIM2_MASK                  (0x1U << RCC_APB1RSTR_TIM2_SHIFT)
#define RCC_APB1RSTR_TIM2(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1RSTR_TIM2_SHIFT)) & RCC_APB1RSTR_TIM2_MASK)

/*!
 * @brief RCC_AHBENR Register Bit Definition
 */

#define RCC_AHBENR_HWDIV_SHIFT                  (26)
#define RCC_AHBENR_HWDIV_MASK                   (0x1U << RCC_AHBENR_HWDIV_SHIFT)
#define RCC_AHBENR_HWDIV(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_HWDIV_SHIFT)) & RCC_AHBENR_HWDIV_MASK)

#define RCC_AHBENR_USB_SHIFT                    (24)
#define RCC_AHBENR_USB_MASK                     (0x1U << RCC_AHBENR_USB_SHIFT)
#define RCC_AHBENR_USB(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_USB_SHIFT)) & RCC_AHBENR_USB_MASK)

#define RCC_AHBENR_GPIOD_SHIFT                  (20)
#define RCC_AHBENR_GPIOD_MASK                   (0x1U << RCC_AHBENR_GPIOD_SHIFT)
#define RCC_AHBENR_GPIOD(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_GPIOD_SHIFT)) & RCC_AHBENR_GPIOD_MASK)

#define RCC_AHBENR_GPIOC_SHIFT                  (19)
#define RCC_AHBENR_GPIOC_MASK                   (0x1U << RCC_AHBENR_GPIOC_SHIFT)
#define RCC_AHBENR_GPIOC(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_GPIOC_SHIFT)) & RCC_AHBENR_GPIOC_MASK)

#define RCC_AHBENR_GPIOB_SHIFT                  (18)
#define RCC_AHBENR_GPIOB_MASK                   (0x1U << RCC_AHBENR_GPIOB_SHIFT)
#define RCC_AHBENR_GPIOB(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_GPIOB_SHIFT)) & RCC_AHBENR_GPIOB_MASK)

#define RCC_AHBENR_GPIOA_SHIFT                  (17)
#define RCC_AHBENR_GPIOA_MASK                   (0x1U << RCC_AHBENR_GPIOA_SHIFT)
#define RCC_AHBENR_GPIOA(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_GPIOA_SHIFT)) & RCC_AHBENR_GPIOA_MASK)

#define RCC_AHBENR_CRC_SHIFT                    (6)
#define RCC_AHBENR_CRC_MASK                     (0x1U << RCC_AHBENR_CRC_SHIFT)
#define RCC_AHBENR_CRC(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_CRC_SHIFT)) & RCC_AHBENR_CRC_MASK)

#define RCC_AHBENR_FLASH_SHIFT                  (4)
#define RCC_AHBENR_FLASH_MASK                   (0x1U << RCC_AHBENR_FLASH_SHIFT)
#define RCC_AHBENR_FLASH(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_FLASH_SHIFT)) & RCC_AHBENR_FLASH_MASK)

#define RCC_AHBENR_SRAM_SHIFT                   (2)
#define RCC_AHBENR_SRAM_MASK                    (0x1U << RCC_AHBENR_SRAM_SHIFT)
#define RCC_AHBENR_SRAM(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_SRAM_SHIFT)) & RCC_AHBENR_SRAM_MASK)

#define RCC_AHBENR_DMA_SHIFT                    (0)
#define RCC_AHBENR_DMA_MASK                     (0x1U << RCC_AHBENR_DMA_SHIFT)
#define RCC_AHBENR_DMA(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_AHBENR_DMA_SHIFT)) & RCC_AHBENR_DMA_MASK)

/*!
 * @brief RCC_APB2ENR Register Bit Definition
 */

#define RCC_APB2ENR_LPUART_SHIFT                (31)
#define RCC_APB2ENR_LPUART_MASK                 (0x1U << RCC_APB2ENR_LPUART_SHIFT)
#define RCC_APB2ENR_LPUART(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_LPUART_SHIFT)) & RCC_APB2ENR_LPUART_MASK)

#define RCC_APB2ENR_LPTIM_SHIFT                 (30)
#define RCC_APB2ENR_LPTIM_MASK                  (0x1U << RCC_APB2ENR_LPTIM_SHIFT)
#define RCC_APB2ENR_LPTIM(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_LPTIM_SHIFT)) & RCC_APB2ENR_LPTIM_MASK)

#define RCC_APB2ENR_EXTI_SHIFT                  (29)
#define RCC_APB2ENR_EXTI_MASK                   (0x1U << RCC_APB2ENR_EXTI_SHIFT)
#define RCC_APB2ENR_EXTI(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_EXTI_SHIFT)) & RCC_APB2ENR_EXTI_MASK)

#define RCC_APB2ENR_DBG_SHIFT                   (22)
#define RCC_APB2ENR_DBG_MASK                    (0x1U << RCC_APB2ENR_DBG_SHIFT)
#define RCC_APB2ENR_DBG(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_DBG_SHIFT)) & RCC_APB2ENR_DBG_MASK)

#define RCC_APB2ENR_TIM17_SHIFT                 (18)
#define RCC_APB2ENR_TIM17_MASK                  (0x1U << RCC_APB2ENR_TIM17_SHIFT)
#define RCC_APB2ENR_TIM17(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_TIM17_SHIFT)) & RCC_APB2ENR_TIM17_MASK)

#define RCC_APB2ENR_TIM16_SHIFT                 (17)
#define RCC_APB2ENR_TIM16_MASK                  (0x1U << RCC_APB2ENR_TIM16_SHIFT)
#define RCC_APB2ENR_TIM16(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_TIM16_SHIFT)) & RCC_APB2ENR_TIM16_MASK)

#define RCC_APB2ENR_TIM14_SHIFT                 (16)
#define RCC_APB2ENR_TIM14_MASK                  (0x1U << RCC_APB2ENR_TIM14_SHIFT)
#define RCC_APB2ENR_TIM14(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_TIM14_SHIFT)) & RCC_APB2ENR_TIM14_MASK)

#define RCC_APB2ENR_COMP_SHIFT                  (15)
#define RCC_APB2ENR_COMP_MASK                   (0x1U << RCC_APB2ENR_COMP_SHIFT)
#define RCC_APB2ENR_COMP(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_COMP_SHIFT)) & RCC_APB2ENR_COMP_MASK)

#define RCC_APB2ENR_UART1_SHIFT                 (14)
#define RCC_APB2ENR_UART1_MASK                  (0x1U << RCC_APB2ENR_UART1_SHIFT)
#define RCC_APB2ENR_UART1(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_UART1_SHIFT)) & RCC_APB2ENR_UART1_MASK)

#define RCC_APB2ENR_SPI1_SHIFT                  (12)
#define RCC_APB2ENR_SPI1_MASK                   (0x1U << RCC_APB2ENR_SPI1_SHIFT)
#define RCC_APB2ENR_SPI1(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_SPI1_SHIFT)) & RCC_APB2ENR_SPI1_MASK)

#define RCC_APB2ENR_TIM1_SHIFT                  (11)
#define RCC_APB2ENR_TIM1_MASK                   (0x1U << RCC_APB2ENR_TIM1_SHIFT)
#define RCC_APB2ENR_TIM1(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_TIM1_SHIFT)) & RCC_APB2ENR_TIM1_MASK)

#define RCC_APB2ENR_ADC_SHIFT                   (9)
#define RCC_APB2ENR_ADC_MASK                    (0x1U << RCC_APB2ENR_ADC_SHIFT)
#define RCC_APB2ENR_ADC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_ADC_SHIFT)) & RCC_APB2ENR_ADC_MASK)

#define RCC_APB2ENR_SYSCFG_SHIFT                (0)
#define RCC_APB2ENR_SYSCFG_MASK                 (0x1U << RCC_APB2ENR_SYSCFG_SHIFT)
#define RCC_APB2ENR_SYSCFG(x)                   (((uint32_t)(((uint32_t)(x)) << RCC_APB2ENR_SYSCFG_SHIFT)) & RCC_APB2ENR_SYSCFG_MASK)

/*!
 * @brief RCC_APB1ENR Register Bit Definition
 */

#define RCC_APB1ENR_RTC_SHIFT                   (31)
#define RCC_APB1ENR_RTC_MASK                    (0x1U << RCC_APB1ENR_RTC_SHIFT)
#define RCC_APB1ENR_RTC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_RTC_SHIFT)) & RCC_APB1ENR_RTC_MASK)

#define RCC_APB1ENR_IWDG_SHIFT                  (30)
#define RCC_APB1ENR_IWDG_MASK                   (0x1U << RCC_APB1ENR_IWDG_SHIFT)
#define RCC_APB1ENR_IWDG(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_IWDG_SHIFT)) & RCC_APB1ENR_IWDG_MASK)

#define RCC_APB1ENR_PWR_SHIFT                   (28)
#define RCC_APB1ENR_PWR_MASK                    (0x1U << RCC_APB1ENR_PWR_SHIFT)
#define RCC_APB1ENR_PWR(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_PWR_SHIFT)) & RCC_APB1ENR_PWR_MASK)

#define RCC_APB1ENR_CRS_SHIFT                   (27)
#define RCC_APB1ENR_CRS_MASK                    (0x1U << RCC_APB1ENR_CRS_SHIFT)
#define RCC_APB1ENR_CRS(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_CRS_SHIFT)) & RCC_APB1ENR_CRS_MASK)

#define RCC_APB1ENR_FLEXCAN_SHIFT               (25)
#define RCC_APB1ENR_FLEXCAN_MASK                (0x1U << RCC_APB1ENR_FLEXCAN_SHIFT)
#define RCC_APB1ENR_FLEXCAN(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_FLEXCAN_SHIFT)) & RCC_APB1ENR_FLEXCAN_MASK)

#define RCC_APB1ENR_BKP_SHIFT                   (24)
#define RCC_APB1ENR_BKP_MASK                    (0x1U << RCC_APB1ENR_BKP_SHIFT)
#define RCC_APB1ENR_BKP(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_BKP_SHIFT)) & RCC_APB1ENR_BKP_MASK)

#define RCC_APB1ENR_I2C1_SHIFT                  (21)
#define RCC_APB1ENR_I2C1_MASK                   (0x1U << RCC_APB1ENR_I2C1_SHIFT)
#define RCC_APB1ENR_I2C1(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_I2C1_SHIFT)) & RCC_APB1ENR_I2C1_MASK)

#define RCC_APB1ENR_UART4_SHIFT                 (19)
#define RCC_APB1ENR_UART4_MASK                  (0x1U << RCC_APB1ENR_UART4_SHIFT)
#define RCC_APB1ENR_UART4(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_UART4_SHIFT)) & RCC_APB1ENR_UART4_MASK)

#define RCC_APB1ENR_UART3_SHIFT                 (18)
#define RCC_APB1ENR_UART3_MASK                  (0x1U << RCC_APB1ENR_UART3_SHIFT)
#define RCC_APB1ENR_UART3(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_UART3_SHIFT)) & RCC_APB1ENR_UART3_MASK)

#define RCC_APB1ENR_UART2_SHIFT                 (17)
#define RCC_APB1ENR_UART2_MASK                  (0x1U << RCC_APB1ENR_UART2_SHIFT)
#define RCC_APB1ENR_UART2(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_UART2_SHIFT)) & RCC_APB1ENR_UART2_MASK)

#define RCC_APB1ENR_SPI2_SHIFT                  (14)
#define RCC_APB1ENR_SPI2_MASK                   (0x1U << RCC_APB1ENR_SPI2_SHIFT)
#define RCC_APB1ENR_SPI2(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_SPI2_SHIFT)) & RCC_APB1ENR_SPI2_MASK)

#define RCC_APB1ENR_WWDG_SHIFT                  (11)
#define RCC_APB1ENR_WWDG_MASK                   (0x1U << RCC_APB1ENR_WWDG_SHIFT)
#define RCC_APB1ENR_WWDG(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_WWDG_SHIFT)) & RCC_APB1ENR_WWDG_MASK)

#define RCC_APB1ENR_I3C_SHIFT                   (6)
#define RCC_APB1ENR_I3C_MASK                    (0x1U << RCC_APB1ENR_I3C_SHIFT)
#define RCC_APB1ENR_I3C(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_I3C_SHIFT)) & RCC_APB1ENR_I3C_MASK)

#define RCC_APB1ENR_TIM3_SHIFT                  (1)
#define RCC_APB1ENR_TIM3_MASK                   (0x1U << RCC_APB1ENR_TIM3_SHIFT)
#define RCC_APB1ENR_TIM3(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_TIM3_SHIFT)) & RCC_APB1ENR_TIM3_MASK)

#define RCC_APB1ENR_TIM2_SHIFT                  (0)
#define RCC_APB1ENR_TIM2_MASK                   (0x1U << RCC_APB1ENR_TIM2_SHIFT)
#define RCC_APB1ENR_TIM2(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_APB1ENR_TIM2_SHIFT)) & RCC_APB1ENR_TIM2_MASK)

/*!
 * @brief RCC_BDCR Register Bit Definition
 */

#define RCC_BDCR_DBP_SHIFT                      (24)
#define RCC_BDCR_DBP_MASK                       (0x1U << RCC_BDCR_DBP_SHIFT)
#define RCC_BDCR_DBP(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_DBP_SHIFT)) & RCC_BDCR_DBP_MASK)

#define RCC_BDCR_BDRST_SHIFT                    (16)
#define RCC_BDCR_BDRST_MASK                     (0x1U << RCC_BDCR_BDRST_SHIFT)
#define RCC_BDCR_BDRST(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_BDRST_SHIFT)) & RCC_BDCR_BDRST_MASK)

#define RCC_BDCR_RTCEN_SHIFT                    (15)
#define RCC_BDCR_RTCEN_MASK                     (0x1U << RCC_BDCR_RTCEN_SHIFT)
#define RCC_BDCR_RTCEN(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_RTCEN_SHIFT)) & RCC_BDCR_RTCEN_MASK)

#define RCC_BDCR_RTCSEL_SHIFT                   (8)
#define RCC_BDCR_RTCSEL_MASK                    (0x3U << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_RTCSEL(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_RTCSEL_SHIFT)) & RCC_BDCR_RTCSEL_MASK)

#define RCC_BDCR_LSEBYP_SHIFT                   (2)
#define RCC_BDCR_LSEBYP_MASK                    (0x1U << RCC_BDCR_LSEBYP_SHIFT)
#define RCC_BDCR_LSEBYP(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_LSEBYP_SHIFT)) & RCC_BDCR_LSEBYP_MASK)

#define RCC_BDCR_LSERDY_SHIFT                   (1)
#define RCC_BDCR_LSERDY_MASK                    (0x1U << RCC_BDCR_LSERDY_SHIFT)
#define RCC_BDCR_LSERDY(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_LSERDY_SHIFT)) & RCC_BDCR_LSERDY_MASK)

#define RCC_BDCR_LSEON_SHIFT                    (0)
#define RCC_BDCR_LSEON_MASK                     (0x1U << RCC_BDCR_LSEON_SHIFT)
#define RCC_BDCR_LSEON(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_BDCR_LSEON_SHIFT)) & RCC_BDCR_LSEON_MASK)

/*!
 * @brief RCC_CSR Register Bit Definition
 */

#define RCC_CSR_LPWRRSTF_SHIFT                  (31)
#define RCC_CSR_LPWRRSTF_MASK                   (0x1U << RCC_CSR_LPWRRSTF_SHIFT)
#define RCC_CSR_LPWRRSTF(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LPWRRSTF_SHIFT)) & RCC_CSR_LPWRRSTF_MASK)

#define RCC_CSR_WWDGRSTF_SHIFT                  (30)
#define RCC_CSR_WWDGRSTF_MASK                   (0x1U << RCC_CSR_WWDGRSTF_SHIFT)
#define RCC_CSR_WWDGRSTF(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CSR_WWDGRSTF_SHIFT)) & RCC_CSR_WWDGRSTF_MASK)

#define RCC_CSR_IWDGRSTF_SHIFT                  (29)
#define RCC_CSR_IWDGRSTF_MASK                   (0x1U << RCC_CSR_IWDGRSTF_SHIFT)
#define RCC_CSR_IWDGRSTF(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CSR_IWDGRSTF_SHIFT)) & RCC_CSR_IWDGRSTF_MASK)

#define RCC_CSR_SFTRSTF_SHIFT                   (28)
#define RCC_CSR_SFTRSTF_MASK                    (0x1U << RCC_CSR_SFTRSTF_SHIFT)
#define RCC_CSR_SFTRSTF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CSR_SFTRSTF_SHIFT)) & RCC_CSR_SFTRSTF_MASK)

#define RCC_CSR_PORRSTF_SHIFT                   (27)
#define RCC_CSR_PORRSTF_MASK                    (0x1U << RCC_CSR_PORRSTF_SHIFT)
#define RCC_CSR_PORRSTF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CSR_PORRSTF_SHIFT)) & RCC_CSR_PORRSTF_MASK)

#define RCC_CSR_PINRSTF_SHIFT                   (26)
#define RCC_CSR_PINRSTF_MASK                    (0x1U << RCC_CSR_PINRSTF_SHIFT)
#define RCC_CSR_PINRSTF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CSR_PINRSTF_SHIFT)) & RCC_CSR_PINRSTF_MASK)

#define RCC_CSR_RMVF_SHIFT                      (24)
#define RCC_CSR_RMVF_MASK                       (0x1U << RCC_CSR_RMVF_SHIFT)
#define RCC_CSR_RMVF(x)                         (((uint32_t)(((uint32_t)(x)) << RCC_CSR_RMVF_SHIFT)) & RCC_CSR_RMVF_MASK)

#define RCC_CSR_LOCKUPF_SHIFT                   (23)
#define RCC_CSR_LOCKUPF_MASK                    (0x1U << RCC_CSR_LOCKUPF_SHIFT)
#define RCC_CSR_LOCKUPF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LOCKUPF_SHIFT)) & RCC_CSR_LOCKUPF_MASK)

#define RCC_CSR_PVDRSTF_SHIFT                   (22)
#define RCC_CSR_PVDRSTF_MASK                    (0x1U << RCC_CSR_PVDRSTF_SHIFT)
#define RCC_CSR_PVDRSTF(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_CSR_PVDRSTF_SHIFT)) & RCC_CSR_PVDRSTF_MASK)

#define RCC_CSR_LOCKUPEN_SHIFT                  (7)
#define RCC_CSR_LOCKUPEN_MASK                   (0x1U << RCC_CSR_LOCKUPEN_SHIFT)
#define RCC_CSR_LOCKUPEN(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LOCKUPEN_SHIFT)) & RCC_CSR_LOCKUPEN_MASK)

#define RCC_CSR_PVDRSTEN_SHIFT                  (6)
#define RCC_CSR_PVDRSTEN_MASK                   (0x1U << RCC_CSR_PVDRSTEN_SHIFT)
#define RCC_CSR_PVDRSTEN(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CSR_PVDRSTEN_SHIFT)) & RCC_CSR_PVDRSTEN_MASK)

#define RCC_CSR_LSIOE_SHIFT                     (5)
#define RCC_CSR_LSIOE_MASK                      (0x1U << RCC_CSR_LSIOE_SHIFT)
#define RCC_CSR_LSIOE(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LSIOE_SHIFT)) & RCC_CSR_LSIOE_MASK)

#define RCC_CSR_LSIRDY_SHIFT                    (1)
#define RCC_CSR_LSIRDY_MASK                     (0x1U << RCC_CSR_LSIRDY_SHIFT)
#define RCC_CSR_LSIRDY(x)                       (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LSIRDY_SHIFT)) & RCC_CSR_LSIRDY_MASK)

#define RCC_CSR_LSION_SHIFT                     (0)
#define RCC_CSR_LSION_MASK                      (0x1U << RCC_CSR_LSION_SHIFT)
#define RCC_CSR_LSION(x)                        (((uint32_t)(((uint32_t)(x)) << RCC_CSR_LSION_SHIFT)) & RCC_CSR_LSION_MASK)

/*!
 * @brief RCC_AHBRSTR Register Bit Definition
 */

#define RCC_AHBRSTR_HWDIV_SHIFT                 (26)
#define RCC_AHBRSTR_HWDIV_MASK                  (0x1U << RCC_AHBRSTR_HWDIV_SHIFT)
#define RCC_AHBRSTR_HWDIV(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_HWDIV_SHIFT)) & RCC_AHBRSTR_HWDIV_MASK)

#define RCC_AHBRSTR_USB_SHIFT                   (24)
#define RCC_AHBRSTR_USB_MASK                    (0x1U << RCC_AHBRSTR_USB_SHIFT)
#define RCC_AHBRSTR_USB(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_USB_SHIFT)) & RCC_AHBRSTR_USB_MASK)

#define RCC_AHBRSTR_GPIOD_SHIFT                 (20)
#define RCC_AHBRSTR_GPIOD_MASK                  (0x1U << RCC_AHBRSTR_GPIOD_SHIFT)
#define RCC_AHBRSTR_GPIOD(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_GPIOD_SHIFT)) & RCC_AHBRSTR_GPIOD_MASK)

#define RCC_AHBRSTR_GPIOC_SHIFT                 (19)
#define RCC_AHBRSTR_GPIOC_MASK                  (0x1U << RCC_AHBRSTR_GPIOC_SHIFT)
#define RCC_AHBRSTR_GPIOC(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_GPIOC_SHIFT)) & RCC_AHBRSTR_GPIOC_MASK)

#define RCC_AHBRSTR_GPIOB_SHIFT                 (18)
#define RCC_AHBRSTR_GPIOB_MASK                  (0x1U << RCC_AHBRSTR_GPIOB_SHIFT)
#define RCC_AHBRSTR_GPIOB(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_GPIOB_SHIFT)) & RCC_AHBRSTR_GPIOB_MASK)

#define RCC_AHBRSTR_GPIOA_SHIFT                 (17)
#define RCC_AHBRSTR_GPIOA_MASK                  (0x1U << RCC_AHBRSTR_GPIOA_SHIFT)
#define RCC_AHBRSTR_GPIOA(x)                    (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_GPIOA_SHIFT)) & RCC_AHBRSTR_GPIOA_MASK)

#define RCC_AHBRSTR_CRC_SHIFT                   (6)
#define RCC_AHBRSTR_CRC_MASK                    (0x1U << RCC_AHBRSTR_CRC_SHIFT)
#define RCC_AHBRSTR_CRC(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_CRC_SHIFT)) & RCC_AHBRSTR_CRC_MASK)

#define RCC_AHBRSTR_DMA_SHIFT                   (0)
#define RCC_AHBRSTR_DMA_MASK                    (0x1U << RCC_AHBRSTR_DMA_SHIFT)
#define RCC_AHBRSTR_DMA(x)                      (((uint32_t)(((uint32_t)(x)) << RCC_AHBRSTR_DMA_SHIFT)) & RCC_AHBRSTR_DMA_MASK)

/*!
 * @brief RCC_CFGR2 Register Bit Definition
 */

#define RCC_CFGR2_LPTIMCLKSEL_SHIFT             (29)
#define RCC_CFGR2_LPTIMCLKSEL_MASK              (0x3U << RCC_CFGR2_LPTIMCLKSEL_SHIFT)
#define RCC_CFGR2_LPTIMCLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_LPTIMCLKSEL_SHIFT)) & RCC_CFGR2_LPTIMCLKSEL_MASK)

#define RCC_CFGR2_MCOPRE_SHIFT                  (20)
#define RCC_CFGR2_MCOPRE_MASK                   (0xFU << RCC_CFGR2_MCOPRE_SHIFT)
#define RCC_CFGR2_MCOPRE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_MCOPRE_SHIFT)) & RCC_CFGR2_MCOPRE_MASK)

#define RCC_CFGR2_APB1CLKHVPRE_SHIFT            (16)
#define RCC_CFGR2_APB1CLKHVPRE_MASK             (0xFU << RCC_CFGR2_APB1CLKHVPRE_SHIFT)
#define RCC_CFGR2_APB1CLKHVPRE(x)               (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_APB1CLKHVPRE_SHIFT)) & RCC_CFGR2_APB1CLKHVPRE_MASK)

#define RCC_CFGR2_CANPRE_SHIFT                  (12)
#define RCC_CFGR2_CANPRE_MASK                   (0x3U << RCC_CFGR2_CANPRE_SHIFT)
#define RCC_CFGR2_CANPRE(x)                     (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_CANPRE_SHIFT)) & RCC_CFGR2_CANPRE_MASK)

#define RCC_CFGR2_CANCLKSEL_SHIFT               (8)
#define RCC_CFGR2_CANCLKSEL_MASK                (0x3U << RCC_CFGR2_CANCLKSEL_SHIFT)
#define RCC_CFGR2_CANCLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_CANCLKSEL_SHIFT)) & RCC_CFGR2_CANCLKSEL_MASK)

#define RCC_CFGR2_LPUARTCLKSEL_SHIFT            (0)
#define RCC_CFGR2_LPUARTCLKSEL_MASK             (0x3U << RCC_CFGR2_LPUARTCLKSEL_SHIFT)
#define RCC_CFGR2_LPUARTCLKSEL(x)               (((uint32_t)(((uint32_t)(x)) << RCC_CFGR2_LPUARTCLKSEL_SHIFT)) & RCC_CFGR2_LPUARTCLKSEL_MASK)

/*!
 * @brief RCC_SYSCFG Register Bit Definition
 */

#define RCC_SYSCFG_HSELPFEN_SHIFT               (14)
#define RCC_SYSCFG_HSELPFEN_MASK                (0x1U << RCC_SYSCFG_HSELPFEN_SHIFT)
#define RCC_SYSCFG_HSELPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << RCC_SYSCFG_HSELPFEN_SHIFT)) & RCC_SYSCFG_HSELPFEN_MASK)

#define RCC_SYSCFG_HSERFBSEL_SHIFT              (8)
#define RCC_SYSCFG_HSERFBSEL_MASK               (0x3U << RCC_SYSCFG_HSERFBSEL_SHIFT)
#define RCC_SYSCFG_HSERFBSEL(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_SYSCFG_HSERFBSEL_SHIFT)) & RCC_SYSCFG_HSERFBSEL_MASK)

#define RCC_SYSCFG_PROGCHECKEN_SHIFT            (0)
#define RCC_SYSCFG_PROGCHECKEN_MASK             (0x1U << RCC_SYSCFG_PROGCHECKEN_SHIFT)
#define RCC_SYSCFG_PROGCHECKEN(x)               (((uint32_t)(((uint32_t)(x)) << RCC_SYSCFG_PROGCHECKEN_SHIFT)) & RCC_SYSCFG_PROGCHECKEN_MASK)

/*!
 * @brief RCC_ICSCR Register Bit Definition
 */

#define RCC_ICSCR_TRIMCRSSEL_SHIFT              (0)
#define RCC_ICSCR_TRIMCRSSEL_MASK               (0x1U << RCC_ICSCR_TRIMCRSSEL_SHIFT)
#define RCC_ICSCR_TRIMCRSSEL(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_ICSCR_TRIMCRSSEL_SHIFT)) & RCC_ICSCR_TRIMCRSSEL_MASK)

/*!
 * @brief RCC_PLL1CFGR Register Bit Definition
 */

#define RCC_PLL1CFGR_PLL1PDIV_SHIFT             (29)
#define RCC_PLL1CFGR_PLL1PDIV_MASK              (0x7U << RCC_PLL1CFGR_PLL1PDIV_SHIFT)
#define RCC_PLL1CFGR_PLL1PDIV(x)                (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1PDIV_SHIFT)) & RCC_PLL1CFGR_PLL1PDIV_MASK)

#define RCC_PLL1CFGR_PLL1MUL_SHIFT              (16)
#define RCC_PLL1CFGR_PLL1MUL_MASK               (0xFFU << RCC_PLL1CFGR_PLL1MUL_SHIFT)
#define RCC_PLL1CFGR_PLL1MUL(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1MUL_SHIFT)) & RCC_PLL1CFGR_PLL1MUL_MASK)

#define RCC_PLL1CFGR_PLL1DIV_SHIFT              (8)
#define RCC_PLL1CFGR_PLL1DIV_MASK               (0x7U << RCC_PLL1CFGR_PLL1DIV_SHIFT)
#define RCC_PLL1CFGR_PLL1DIV(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1DIV_SHIFT)) & RCC_PLL1CFGR_PLL1DIV_MASK)

#define RCC_PLL1CFGR_PLL1LDS_SHIFT              (4)
#define RCC_PLL1CFGR_PLL1LDS_MASK               (0x3U << RCC_PLL1CFGR_PLL1LDS_SHIFT)
#define RCC_PLL1CFGR_PLL1LDS(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1LDS_SHIFT)) & RCC_PLL1CFGR_PLL1LDS_MASK)

#define RCC_PLL1CFGR_PLL1ICTRL_SHIFT            (2)
#define RCC_PLL1CFGR_PLL1ICTRL_MASK             (0x3U << RCC_PLL1CFGR_PLL1ICTRL_SHIFT)
#define RCC_PLL1CFGR_PLL1ICTRL(x)               (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1ICTRL_SHIFT)) & RCC_PLL1CFGR_PLL1ICTRL_MASK)

#define RCC_PLL1CFGR_PLL1XTPRE_SHIFT            (1)
#define RCC_PLL1CFGR_PLL1XTPRE_MASK             (0x1U << RCC_PLL1CFGR_PLL1XTPRE_SHIFT)
#define RCC_PLL1CFGR_PLL1XTPRE(x)               (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1XTPRE_SHIFT)) & RCC_PLL1CFGR_PLL1XTPRE_MASK)

#define RCC_PLL1CFGR_PLL1SRC_SHIFT              (0)
#define RCC_PLL1CFGR_PLL1SRC_MASK               (0x1U << RCC_PLL1CFGR_PLL1SRC_SHIFT)
#define RCC_PLL1CFGR_PLL1SRC(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL1CFGR_PLL1SRC_SHIFT)) & RCC_PLL1CFGR_PLL1SRC_MASK)

/*!
 * @brief RCC_PLL2CFGR Register Bit Definition
 */

#define RCC_PLL2CFGR_PLL2PDIV_SHIFT             (29)
#define RCC_PLL2CFGR_PLL2PDIV_MASK              (0x7U << RCC_PLL2CFGR_PLL2PDIV_SHIFT)
#define RCC_PLL2CFGR_PLL2PDIV(x)                (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2PDIV_SHIFT)) & RCC_PLL2CFGR_PLL2PDIV_MASK)

#define RCC_PLL2CFGR_PLL2MUL_SHIFT              (16)
#define RCC_PLL2CFGR_PLL2MUL_MASK               (0xFFU << RCC_PLL2CFGR_PLL2MUL_SHIFT)
#define RCC_PLL2CFGR_PLL2MUL(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2MUL_SHIFT)) & RCC_PLL2CFGR_PLL2MUL_MASK)

#define RCC_PLL2CFGR_PLL2DIV_SHIFT              (8)
#define RCC_PLL2CFGR_PLL2DIV_MASK               (0x7U << RCC_PLL2CFGR_PLL2DIV_SHIFT)
#define RCC_PLL2CFGR_PLL2DIV(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2DIV_SHIFT)) & RCC_PLL2CFGR_PLL2DIV_MASK)

#define RCC_PLL2CFGR_PLL2LDS_SHIFT              (4)
#define RCC_PLL2CFGR_PLL2LDS_MASK               (0x3U << RCC_PLL2CFGR_PLL2LDS_SHIFT)
#define RCC_PLL2CFGR_PLL2LDS(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2LDS_SHIFT)) & RCC_PLL2CFGR_PLL2LDS_MASK)

#define RCC_PLL2CFGR_PLL2ICTRL_SHIFT            (2)
#define RCC_PLL2CFGR_PLL2ICTRL_MASK             (0x3U << RCC_PLL2CFGR_PLL2ICTRL_SHIFT)
#define RCC_PLL2CFGR_PLL2ICTRL(x)               (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2ICTRL_SHIFT)) & RCC_PLL2CFGR_PLL2ICTRL_MASK)

#define RCC_PLL2CFGR_PLL2XTPRE_SHIFT            (1)
#define RCC_PLL2CFGR_PLL2XTPRE_MASK             (0x1U << RCC_PLL2CFGR_PLL2XTPRE_SHIFT)
#define RCC_PLL2CFGR_PLL2XTPRE(x)               (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2XTPRE_SHIFT)) & RCC_PLL2CFGR_PLL2XTPRE_MASK)

#define RCC_PLL2CFGR_PLL2SRC_SHIFT              (0)
#define RCC_PLL2CFGR_PLL2SRC_MASK               (0x1U << RCC_PLL2CFGR_PLL2SRC_SHIFT)
#define RCC_PLL2CFGR_PLL2SRC(x)                 (((uint32_t)(((uint32_t)(x)) << RCC_PLL2CFGR_PLL2SRC_SHIFT)) & RCC_PLL2CFGR_PLL2SRC_MASK)

/*!
 * @}
 */ /* end of group RCC_Register_Masks */
/******************************************************************************
 *RCC Instance
*******************************************************************************/

#define RCC                  ((RCC_Type*)RCC_BASE)

/*!
 * @}
 */ /* end of group RCC_Peripheral_Access_Layer */



/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * RTC Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CRH;                                                          ///< RTC control register high                    offset: 0x00
    __IO uint32_t CRL;                                                          ///< RTC control register low                     offset: 0x04
    __IO uint32_t PRLH;                                                         ///< RTC prescaler load register high             offset: 0x08
    __IO uint32_t PRLL;                                                         ///< RTC prescaler load register low              offset: 0x0C
    __IO uint32_t DIVH;                                                         ///< RTC prescaler divider register high          offset: 0x10
    __IO uint32_t DIVL;                                                         ///< RTC prescaler divider register low           offset: 0x14
    __IO uint32_t CNTH;                                                         ///< RTC counter register high                    offset: 0x18
    __IO uint32_t CNTL;                                                         ///< RTC counter register low                     offset: 0x1C
    __IO uint32_t ALRH;                                                         ///< RTC alarm register high                      offset: 0x20
    __IO uint32_t ALRL;                                                         ///< RTC alarm register low                       offset: 0x24
    __IO uint32_t MSRH;                                                         ///< RTC millisecond register high                offset: 0x28
    __IO uint32_t MSRL;                                                         ///< RTC millisecond register low                 offset: 0x2C
    __IO uint32_t Reserved0[3];                                                 ///< Reserved
    __IO uint32_t LSECFG;                                                       ///< RTC LSE configuration register               offset: 0x3C
} RTC_Type;

/*******************************************************************************
 * RTC Type
 ******************************************************************************/

/*!
 * @addtogroup RTC_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief RTC_CRH Register Bit Definition
 */

#define RTC_CRH_OWIE_SHIFT                      (2)
#define RTC_CRH_OWIE_MASK                       (0x1U << RTC_CRH_OWIE_SHIFT)
#define RTC_CRH_OWIE(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CRH_OWIE_SHIFT)) & RTC_CRH_OWIE_MASK)

#define RTC_CRH_ALRIE_SHIFT                     (1)
#define RTC_CRH_ALRIE_MASK                      (0x1U << RTC_CRH_ALRIE_SHIFT)
#define RTC_CRH_ALRIE(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_CRH_ALRIE_SHIFT)) & RTC_CRH_ALRIE_MASK)

#define RTC_CRH_SECIE_SHIFT                     (0)
#define RTC_CRH_SECIE_MASK                      (0x1U << RTC_CRH_SECIE_SHIFT)
#define RTC_CRH_SECIE(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_CRH_SECIE_SHIFT)) & RTC_CRH_SECIE_MASK)

/*!
 * @brief RTC_CRL Register Bit Definition
 */

#define RTC_CRL_ALPEN_SHIFT                     (6)
#define RTC_CRL_ALPEN_MASK                      (0x1U << RTC_CRL_ALPEN_SHIFT)
#define RTC_CRL_ALPEN(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_CRL_ALPEN_SHIFT)) & RTC_CRL_ALPEN_MASK)

#define RTC_CRL_RTOFF_SHIFT                     (5)
#define RTC_CRL_RTOFF_MASK                      (0x1U << RTC_CRL_RTOFF_SHIFT)
#define RTC_CRL_RTOFF(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_CRL_RTOFF_SHIFT)) & RTC_CRL_RTOFF_MASK)

#define RTC_CRL_CNF_SHIFT                       (4)
#define RTC_CRL_CNF_MASK                        (0x1U << RTC_CRL_CNF_SHIFT)
#define RTC_CRL_CNF(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CRL_CNF_SHIFT)) & RTC_CRL_CNF_MASK)

#define RTC_CRL_RSF_SHIFT                       (3)
#define RTC_CRL_RSF_MASK                        (0x1U << RTC_CRL_RSF_SHIFT)
#define RTC_CRL_RSF(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CRL_RSF_SHIFT)) & RTC_CRL_RSF_MASK)

#define RTC_CRL_OWF_SHIFT                       (2)
#define RTC_CRL_OWF_MASK                        (0x1U << RTC_CRL_OWF_SHIFT)
#define RTC_CRL_OWF(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CRL_OWF_SHIFT)) & RTC_CRL_OWF_MASK)

#define RTC_CRL_ALRF_SHIFT                      (1)
#define RTC_CRL_ALRF_MASK                       (0x1U << RTC_CRL_ALRF_SHIFT)
#define RTC_CRL_ALRF(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CRL_ALRF_SHIFT)) & RTC_CRL_ALRF_MASK)

#define RTC_CRL_SECF_SHIFT                      (0)
#define RTC_CRL_SECF_MASK                       (0x1U << RTC_CRL_SECF_SHIFT)
#define RTC_CRL_SECF(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CRL_SECF_SHIFT)) & RTC_CRL_SECF_MASK)

/*!
 * @brief RTC_PRLH Register Bit Definition
 */

#define RTC_PRLH_PRL_SHIFT                      (0)
#define RTC_PRLH_PRL_MASK                       (0xFU << RTC_PRLH_PRL_SHIFT)
#define RTC_PRLH_PRL(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_PRLH_PRL_SHIFT)) & RTC_PRLH_PRL_MASK)

/*!
 * @brief RTC_PRLL Register Bit Definition
 */

#define RTC_PRLL_PRL_SHIFT                      (0)
#define RTC_PRLL_PRL_MASK                       (0xFFFFU << RTC_PRLL_PRL_SHIFT)
#define RTC_PRLL_PRL(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_PRLL_PRL_SHIFT)) & RTC_PRLL_PRL_MASK)

/*!
 * @brief RTC_DIVH Register Bit Definition
 */

#define RTC_DIVH_DIV_SHIFT                      (0)
#define RTC_DIVH_DIV_MASK                       (0xFU << RTC_DIVH_DIV_SHIFT)
#define RTC_DIVH_DIV(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_DIVH_DIV_SHIFT)) & RTC_DIVH_DIV_MASK)

/*!
 * @brief RTC_DIVL Register Bit Definition
 */

#define RTC_DIVL_DIV_SHIFT                      (0)
#define RTC_DIVL_DIV_MASK                       (0xFFFFU << RTC_DIVL_DIV_SHIFT)
#define RTC_DIVL_DIV(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_DIVL_DIV_SHIFT)) & RTC_DIVL_DIV_MASK)

/*!
 * @brief RTC_CNTH Register Bit Definition
 */

#define RTC_CNTH_CNT_SHIFT                      (0)
#define RTC_CNTH_CNT_MASK                       (0xFFFFU << RTC_CNTH_CNT_SHIFT)
#define RTC_CNTH_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CNTH_CNT_SHIFT)) & RTC_CNTH_CNT_MASK)

/*!
 * @brief RTC_CNTL Register Bit Definition
 */

#define RTC_CNTL_CNT_SHIFT                      (0)
#define RTC_CNTL_CNT_MASK                       (0xFFFFU << RTC_CNTL_CNT_SHIFT)
#define RTC_CNTL_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_CNTL_CNT_SHIFT)) & RTC_CNTL_CNT_MASK)

/*!
 * @brief RTC_ALRH Register Bit Definition
 */

#define RTC_ALRH_ALR_SHIFT                      (0)
#define RTC_ALRH_ALR_MASK                       (0xFFFFU << RTC_ALRH_ALR_SHIFT)
#define RTC_ALRH_ALR(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_ALRH_ALR_SHIFT)) & RTC_ALRH_ALR_MASK)

/*!
 * @brief RTC_ALRL Register Bit Definition
 */

#define RTC_ALRL_ALR_SHIFT                      (0)
#define RTC_ALRL_ALR_MASK                       (0xFFFFU << RTC_ALRL_ALR_SHIFT)
#define RTC_ALRL_ALR(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_ALRL_ALR_SHIFT)) & RTC_ALRL_ALR_MASK)

/*!
 * @brief RTC_MSRH Register Bit Definition
 */

#define RTC_MSRH_MSR_SHIFT                      (0)
#define RTC_MSRH_MSR_MASK                       (0xFU << RTC_MSRH_MSR_SHIFT)
#define RTC_MSRH_MSR(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_MSRH_MSR_SHIFT)) & RTC_MSRH_MSR_MASK)

/*!
 * @brief RTC_MSRL Register Bit Definition
 */

#define RTC_MSRL_MSR_SHIFT                      (0)
#define RTC_MSRL_MSR_MASK                       (0xFFFFU << RTC_MSRL_MSR_SHIFT)
#define RTC_MSRL_MSR(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_MSRL_MSR_SHIFT)) & RTC_MSRL_MSR_MASK)

/*!
 * @brief RTC_LSE_CFG Register Bit Definition
 */

#define RTC_LSECFG_LSEAAC_SHIFT                 (10)
#define RTC_LSECFG_LSEAAC_MASK                  (0x1U << RTC_LSECFG_LSEAAC_SHIFT)
#define RTC_LSECFG_LSEAAC(x)                    (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSEAAC_SHIFT)) & RTC_LSECFG_LSEAAC_MASK)

#define RTC_LSECFG_LSEIB_SHIFT                  (8)
#define RTC_LSECFG_LSEIB_MASK                   (0x3U << RTC_LSECFG_LSEIB_SHIFT)
#define RTC_LSECFG_LSEIB(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSEIB_SHIFT)) & RTC_LSECFG_LSEIB_MASK)

#define RTC_LSECFG_LSERFBSEL_SHIFT              (6)
#define RTC_LSECFG_LSERFBSEL_MASK               (0x3U << RTC_LSECFG_LSERFBSEL_SHIFT)
#define RTC_LSECFG_LSERFBSEL(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSERFBSEL_SHIFT)) & RTC_LSECFG_LSERFBSEL_MASK)

#define RTC_LSECFG_LSEDR_SHIFT                  (4)
#define RTC_LSECFG_LSEDR_MASK                   (0x3U << RTC_LSECFG_LSEDR_SHIFT)
#define RTC_LSECFG_LSEDR(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSEDR_SHIFT)) & RTC_LSECFG_LSEDR_MASK)

#define RTC_LSECFG_LSEOUTENH_SHIFT              (2)
#define RTC_LSECFG_LSEOUTENH_MASK               (0x1U << RTC_LSECFG_LSEOUTENH_SHIFT)
#define RTC_LSECFG_LSEOUTENH(x)                 (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSEOUTENH_SHIFT)) & RTC_LSECFG_LSEOUTENH_MASK)

#define RTC_LSECFG_LSETC_SHIFT                  (0)
#define RTC_LSECFG_LSETC_MASK                   (0x3U << RTC_LSECFG_LSETC_SHIFT)
#define RTC_LSECFG_LSETC(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_LSECFG_LSETC_SHIFT)) & RTC_LSECFG_LSETC_MASK)

/*!
 * @}
 */ /* end of group RTC_Register_Masks */
/******************************************************************************
 *RTC Instance
*******************************************************************************/

#define RTC                  ((RTC_Type*)RTC_BKP_BASE)

/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */



/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * SPI Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t TXREG;                                                        ///< Transmission Data Register                   offset: 0x00
    __IO uint32_t RXREG;                                                        ///< Receipt Data Register                        offset: 0x04
    __IO uint32_t CSTAT;                                                        ///< Current Status Register                      offset: 0x08
    __IO uint32_t INTSTAT;                                                      ///< Interrupt Status Register                    offset: 0x0C
    __IO uint32_t INTEN;                                                        ///< Interrupt Enable Register                    offset: 0x10
    __IO uint32_t INTCLR;                                                       ///< Interrupt Clear Register                     offset: 0x14
    __IO uint32_t GCTL;                                                         ///< Global Control Register                      offset: 0x18
    __IO uint32_t CCTL;                                                         ///< Universal Control Register                   offset: 0x1C
    __IO uint32_t SPBRG;                                                        ///< Baud Rate Generator                          offset: 0x20
    __IO uint32_t RXDNR;                                                        ///< Receipt Data Number Register                 offset: 0x24
    __IO uint32_t NSSR;                                                         ///< Slave Chip Selection Register                offset: 0x28
    __IO uint32_t EXTCTL;                                                       ///< Data Length Control Register                 offset: 0x2C
    __IO uint32_t I2SCFGR;                                                      ///< I2S Configuration Register                   offset: 0x30
} SPI_Type,I2S_Type;

/*******************************************************************************
 * SPI Type
 ******************************************************************************/

/*!
 * @addtogroup SPI_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief SPI_I2S_TXREG Register Bit Definition
 */

#define SPI_I2S_TXREG_TXREG_SHIFT               (0)
#define SPI_I2S_TXREG_TXREG_MASK                (0xFFFFFFFFU << SPI_I2S_TXREG_TXREG_SHIFT)
#define SPI_I2S_TXREG_TXREG(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_TXREG_TXREG_SHIFT)) & SPI_I2S_TXREG_TXREG_MASK)

/*!
 * @brief SPI_I2S_RXREG Register Bit Definition
 */

#define SPI_I2S_RXREG_RXREG_SHIFT               (0)
#define SPI_I2S_RXREG_RXREG_MASK                (0xFFFFFFFFU << SPI_I2S_RXREG_RXREG_SHIFT)
#define SPI_I2S_RXREG_RXREG(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_RXREG_RXREG_SHIFT)) & SPI_I2S_RXREG_RXREG_MASK)

/*!
 * @brief SPI_I2S_CSTAT Register Bit Definition
 */

#define SPI_I2S_CSTAT_CHSIDE_SHIFT              (13)
#define SPI_I2S_CSTAT_CHSIDE_MASK               (0x1U << SPI_I2S_CSTAT_CHSIDE_SHIFT)
#define SPI_I2S_CSTAT_CHSIDE(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_CHSIDE_SHIFT)) & SPI_I2S_CSTAT_CHSIDE_MASK)

#define SPI_I2S_CSTAT_BUSY_SHIFT                (12)
#define SPI_I2S_CSTAT_BUSY_MASK                 (0x1U << SPI_I2S_CSTAT_BUSY_SHIFT)
#define SPI_I2S_CSTAT_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_BUSY_SHIFT)) & SPI_I2S_CSTAT_BUSY_MASK)

#define SPI_I2S_CSTAT_RXFADDR_SHIFT             (8)
#define SPI_I2S_CSTAT_RXFADDR_MASK              (0xFU << SPI_I2S_CSTAT_RXFADDR_SHIFT)
#define SPI_I2S_CSTAT_RXFADDR(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_RXFADDR_SHIFT)) & SPI_I2S_CSTAT_RXFADDR_MASK)

#define SPI_I2S_CSTAT_TXFADDR_SHIFT             (4)
#define SPI_I2S_CSTAT_TXFADDR_MASK              (0xFU << SPI_I2S_CSTAT_TXFADDR_SHIFT)
#define SPI_I2S_CSTAT_TXFADDR(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_TXFADDR_SHIFT)) & SPI_I2S_CSTAT_TXFADDR_MASK)

#define SPI_I2S_CSTAT_RXAVL4BYTE_SHIFT          (3)
#define SPI_I2S_CSTAT_RXAVL4BYTE_MASK           (0x1U << SPI_I2S_CSTAT_RXAVL4BYTE_SHIFT)
#define SPI_I2S_CSTAT_RXAVL4BYTE(x)             (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_RXAVL4BYTE_SHIFT)) & SPI_I2S_CSTAT_RXAVL4BYTE_MASK)

#define SPI_I2S_CSTAT_TXFULL_SHIFT              (2)
#define SPI_I2S_CSTAT_TXFULL_MASK               (0x1U << SPI_I2S_CSTAT_TXFULL_SHIFT)
#define SPI_I2S_CSTAT_TXFULL(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_TXFULL_SHIFT)) & SPI_I2S_CSTAT_TXFULL_MASK)

#define SPI_I2S_CSTAT_RXAVL_SHIFT               (1)
#define SPI_I2S_CSTAT_RXAVL_MASK                (0x1U << SPI_I2S_CSTAT_RXAVL_SHIFT)
#define SPI_I2S_CSTAT_RXAVL(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_RXAVL_SHIFT)) & SPI_I2S_CSTAT_RXAVL_MASK)

#define SPI_I2S_CSTAT_TXEPT_SHIFT               (0)
#define SPI_I2S_CSTAT_TXEPT_MASK                (0x1U << SPI_I2S_CSTAT_TXEPT_SHIFT)
#define SPI_I2S_CSTAT_TXEPT(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CSTAT_TXEPT_SHIFT)) & SPI_I2S_CSTAT_TXEPT_MASK)

/*!
 * @brief SPI_I2S_INTSTAT Register Bit Definition
 */

#define SPI_I2S_INTSTAT_FREINTF_SHIFT           (7)
#define SPI_I2S_INTSTAT_FREINTF_MASK            (0x1U << SPI_I2S_INTSTAT_FREINTF_SHIFT)
#define SPI_I2S_INTSTAT_FREINTF(x)              (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_FREINTF_SHIFT)) & SPI_I2S_INTSTAT_FREINTF_MASK)

#define SPI_I2S_INTSTAT_TXEPTINTF_SHIFT         (6)
#define SPI_I2S_INTSTAT_TXEPTINTF_MASK          (0x1U << SPI_I2S_INTSTAT_TXEPTINTF_SHIFT)
#define SPI_I2S_INTSTAT_TXEPTINTF(x)            (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_TXEPTINTF_SHIFT)) & SPI_I2S_INTSTAT_TXEPTINTF_MASK)

#define SPI_I2S_INTSTAT_RXFULLINTF_SHIFT        (5)
#define SPI_I2S_INTSTAT_RXFULLINTF_MASK         (0x1U << SPI_I2S_INTSTAT_RXFULLINTF_SHIFT)
#define SPI_I2S_INTSTAT_RXFULLINTF(x)           (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_RXFULLINTF_SHIFT)) & SPI_I2S_INTSTAT_RXFULLINTF_MASK)

#define SPI_I2S_INTSTAT_RXMATCHINTF_SHIFT       (4)
#define SPI_I2S_INTSTAT_RXMATCHINTF_MASK        (0x1U << SPI_I2S_INTSTAT_RXMATCHINTF_SHIFT)
#define SPI_I2S_INTSTAT_RXMATCHINTF(x)          (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_RXMATCHINTF_SHIFT)) & SPI_I2S_INTSTAT_RXMATCHINTF_MASK)

#define SPI_I2S_INTSTAT_RXOERRINTF_SHIFT        (3)
#define SPI_I2S_INTSTAT_RXOERRINTF_MASK         (0x1U << SPI_I2S_INTSTAT_RXOERRINTF_SHIFT)
#define SPI_I2S_INTSTAT_RXOERRINTF(x)           (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_RXOERRINTF_SHIFT)) & SPI_I2S_INTSTAT_RXOERRINTF_MASK)

#define SPI_I2S_INTSTAT_UNDERRUNINTF_SHIFT      (2)
#define SPI_I2S_INTSTAT_UNDERRUNINTF_MASK       (0x1U << SPI_I2S_INTSTAT_UNDERRUNINTF_SHIFT)
#define SPI_I2S_INTSTAT_UNDERRUNINTF(x)         (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_UNDERRUNINTF_SHIFT)) & SPI_I2S_INTSTAT_UNDERRUNINTF_MASK)

#define SPI_I2S_INTSTAT_RXINTF_SHIFT            (1)
#define SPI_I2S_INTSTAT_RXINTF_MASK             (0x1U << SPI_I2S_INTSTAT_RXINTF_SHIFT)
#define SPI_I2S_INTSTAT_RXINTF(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_RXINTF_SHIFT)) & SPI_I2S_INTSTAT_RXINTF_MASK)

#define SPI_I2S_INTSTAT_TXINTF_SHIFT            (0)
#define SPI_I2S_INTSTAT_TXINTF_MASK             (0x1U << SPI_I2S_INTSTAT_TXINTF_SHIFT)
#define SPI_I2S_INTSTAT_TXINTF(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTSTAT_TXINTF_SHIFT)) & SPI_I2S_INTSTAT_TXINTF_MASK)

/*!
 * @brief SPI_I2S_INTEN Register Bit Definition
 */

#define SPI_I2S_INTEN_FREIEN_SHIFT              (7)
#define SPI_I2S_INTEN_FREIEN_MASK               (0x1U << SPI_I2S_INTEN_FREIEN_SHIFT)
#define SPI_I2S_INTEN_FREIEN(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_FREIEN_SHIFT)) & SPI_I2S_INTEN_FREIEN_MASK)

#define SPI_I2S_INTEN_TXEPTIEN_SHIFT            (6)
#define SPI_I2S_INTEN_TXEPTIEN_MASK             (0x1U << SPI_I2S_INTEN_TXEPTIEN_SHIFT)
#define SPI_I2S_INTEN_TXEPTIEN(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_TXEPTIEN_SHIFT)) & SPI_I2S_INTEN_TXEPTIEN_MASK)

#define SPI_I2S_INTEN_RXFULLIEN_SHIFT           (5)
#define SPI_I2S_INTEN_RXFULLIEN_MASK            (0x1U << SPI_I2S_INTEN_RXFULLIEN_SHIFT)
#define SPI_I2S_INTEN_RXFULLIEN(x)              (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_RXFULLIEN_SHIFT)) & SPI_I2S_INTEN_RXFULLIEN_MASK)

#define SPI_I2S_INTEN_RXMATCHIEN_SHIFT          (4)
#define SPI_I2S_INTEN_RXMATCHIEN_MASK           (0x1U << SPI_I2S_INTEN_RXMATCHIEN_SHIFT)
#define SPI_I2S_INTEN_RXMATCHIEN(x)             (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_RXMATCHIEN_SHIFT)) & SPI_I2S_INTEN_RXMATCHIEN_MASK)

#define SPI_I2S_INTEN_RXOERRIEN_SHIFT           (3)
#define SPI_I2S_INTEN_RXOERRIEN_MASK            (0x1U << SPI_I2S_INTEN_RXOERRIEN_SHIFT)
#define SPI_I2S_INTEN_RXOERRIEN(x)              (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_RXOERRIEN_SHIFT)) & SPI_I2S_INTEN_RXOERRIEN_MASK)

#define SPI_I2S_INTEN_UNDERRUNIEN_SHIFT         (2)
#define SPI_I2S_INTEN_UNDERRUNIEN_MASK          (0x1U << SPI_I2S_INTEN_UNDERRUNIEN_SHIFT)
#define SPI_I2S_INTEN_UNDERRUNIEN(x)            (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_UNDERRUNIEN_SHIFT)) & SPI_I2S_INTEN_UNDERRUNIEN_MASK)

#define SPI_I2S_INTEN_RXIEN_SHIFT               (1)
#define SPI_I2S_INTEN_RXIEN_MASK                (0x1U << SPI_I2S_INTEN_RXIEN_SHIFT)
#define SPI_I2S_INTEN_RXIEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_RXIEN_SHIFT)) & SPI_I2S_INTEN_RXIEN_MASK)

#define SPI_I2S_INTEN_TXIEN_SHIFT               (0)
#define SPI_I2S_INTEN_TXIEN_MASK                (0x1U << SPI_I2S_INTEN_TXIEN_SHIFT)
#define SPI_I2S_INTEN_TXIEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTEN_TXIEN_SHIFT)) & SPI_I2S_INTEN_TXIEN_MASK)

/*!
 * @brief SPI_I2S_INTCLR Register Bit Definition
 */

#define SPI_I2S_INTCLR_FREICLR_SHIFT            (7)
#define SPI_I2S_INTCLR_FREICLR_MASK             (0x1U << SPI_I2S_INTCLR_FREICLR_SHIFT)
#define SPI_I2S_INTCLR_FREICLR(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_FREICLR_SHIFT)) & SPI_I2S_INTCLR_FREICLR_MASK)

#define SPI_I2S_INTCLR_TXEPTICLR_SHIFT          (6)
#define SPI_I2S_INTCLR_TXEPTICLR_MASK           (0x1U << SPI_I2S_INTCLR_TXEPTICLR_SHIFT)
#define SPI_I2S_INTCLR_TXEPTICLR(x)             (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_TXEPTICLR_SHIFT)) & SPI_I2S_INTCLR_TXEPTICLR_MASK)

#define SPI_I2S_INTCLR_RXFULLICLR_SHIFT         (5)
#define SPI_I2S_INTCLR_RXFULLICLR_MASK          (0x1U << SPI_I2S_INTCLR_RXFULLICLR_SHIFT)
#define SPI_I2S_INTCLR_RXFULLICLR(x)            (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_RXFULLICLR_SHIFT)) & SPI_I2S_INTCLR_RXFULLICLR_MASK)

#define SPI_I2S_INTCLR_RXMATCHICLR_SHIFT        (4)
#define SPI_I2S_INTCLR_RXMATCHICLR_MASK         (0x1U << SPI_I2S_INTCLR_RXMATCHICLR_SHIFT)
#define SPI_I2S_INTCLR_RXMATCHICLR(x)           (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_RXMATCHICLR_SHIFT)) & SPI_I2S_INTCLR_RXMATCHICLR_MASK)

#define SPI_I2S_INTCLR_RXOERRICLR_SHIFT         (3)
#define SPI_I2S_INTCLR_RXOERRICLR_MASK          (0x1U << SPI_I2S_INTCLR_RXOERRICLR_SHIFT)
#define SPI_I2S_INTCLR_RXOERRICLR(x)            (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_RXOERRICLR_SHIFT)) & SPI_I2S_INTCLR_RXOERRICLR_MASK)

#define SPI_I2S_INTCLR_UNDERRUNICLR_SHIFT       (2)
#define SPI_I2S_INTCLR_UNDERRUNICLR_MASK        (0x1U << SPI_I2S_INTCLR_UNDERRUNICLR_SHIFT)
#define SPI_I2S_INTCLR_UNDERRUNICLR(x)          (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_UNDERRUNICLR_SHIFT)) & SPI_I2S_INTCLR_UNDERRUNICLR_MASK)

#define SPI_I2S_INTCLR_RXICLR_SHIFT             (1)
#define SPI_I2S_INTCLR_RXICLR_MASK              (0x1U << SPI_I2S_INTCLR_RXICLR_SHIFT)
#define SPI_I2S_INTCLR_RXICLR(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_RXICLR_SHIFT)) & SPI_I2S_INTCLR_RXICLR_MASK)

#define SPI_I2S_INTCLR_TXICLR_SHIFT             (0)
#define SPI_I2S_INTCLR_TXICLR_MASK              (0x1U << SPI_I2S_INTCLR_TXICLR_SHIFT)
#define SPI_I2S_INTCLR_TXICLR(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_INTCLR_TXICLR_SHIFT)) & SPI_I2S_INTCLR_TXICLR_MASK)

/*!
 * @brief SPI_I2S_GCTL Register Bit Definition
 */

#define SPI_I2S_GCTL_PADSEL_SHIFT               (13)
#define SPI_I2S_GCTL_PADSEL_MASK                (0x1FU << SPI_I2S_GCTL_PADSEL_SHIFT)
#define SPI_I2S_GCTL_PADSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_PADSEL_SHIFT)) & SPI_I2S_GCTL_PADSEL_MASK)

#define SPI_I2S_GCTL_DW832_SHIFT                (11)
#define SPI_I2S_GCTL_DW832_MASK                 (0x1U << SPI_I2S_GCTL_DW832_SHIFT)
#define SPI_I2S_GCTL_DW832(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_DW832_SHIFT)) & SPI_I2S_GCTL_DW832_MASK)

#define SPI_I2S_GCTL_NSS_SHIFT                  (10)
#define SPI_I2S_GCTL_NSS_MASK                   (0x1U << SPI_I2S_GCTL_NSS_SHIFT)
#define SPI_I2S_GCTL_NSS(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_NSS_SHIFT)) & SPI_I2S_GCTL_NSS_MASK)

#define SPI_I2S_GCTL_DMAMODE_SHIFT              (9)
#define SPI_I2S_GCTL_DMAMODE_MASK               (0x1U << SPI_I2S_GCTL_DMAMODE_SHIFT)
#define SPI_I2S_GCTL_DMAMODE(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_DMAMODE_SHIFT)) & SPI_I2S_GCTL_DMAMODE_MASK)

#define SPI_I2S_GCTL_RXEN_SHIFT                 (4)
#define SPI_I2S_GCTL_RXEN_MASK                  (0x1U << SPI_I2S_GCTL_RXEN_SHIFT)
#define SPI_I2S_GCTL_RXEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_RXEN_SHIFT)) & SPI_I2S_GCTL_RXEN_MASK)

#define SPI_I2S_GCTL_TXEN_SHIFT                 (3)
#define SPI_I2S_GCTL_TXEN_MASK                  (0x1U << SPI_I2S_GCTL_TXEN_SHIFT)
#define SPI_I2S_GCTL_TXEN(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_TXEN_SHIFT)) & SPI_I2S_GCTL_TXEN_MASK)

#define SPI_I2S_GCTL_MODE_SHIFT                 (2)
#define SPI_I2S_GCTL_MODE_MASK                  (0x1U << SPI_I2S_GCTL_MODE_SHIFT)
#define SPI_I2S_GCTL_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_MODE_SHIFT)) & SPI_I2S_GCTL_MODE_MASK)

#define SPI_I2S_GCTL_INTEN_SHIFT                (1)
#define SPI_I2S_GCTL_INTEN_MASK                 (0x1U << SPI_I2S_GCTL_INTEN_SHIFT)
#define SPI_I2S_GCTL_INTEN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_INTEN_SHIFT)) & SPI_I2S_GCTL_INTEN_MASK)

#define SPI_I2S_GCTL_SPIEN_SHIFT                (0)
#define SPI_I2S_GCTL_SPIEN_MASK                 (0x1U << SPI_I2S_GCTL_SPIEN_SHIFT)
#define SPI_I2S_GCTL_SPIEN(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_I2S_GCTL_SPIEN_SHIFT)) & SPI_I2S_GCTL_SPIEN_MASK)

/*!
 * @brief SPI_I2S_CCTL Register Bit Definition
 */

#define SPI_I2S_CCTL_CPHASEL_SHIFT              (6)
#define SPI_I2S_CCTL_CPHASEL_MASK               (0x1U << SPI_I2S_CCTL_CPHASEL_SHIFT)
#define SPI_I2S_CCTL_CPHASEL(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_CPHASEL_SHIFT)) & SPI_I2S_CCTL_CPHASEL_MASK)

#define SPI_I2S_CCTL_TXEDGE_SHIFT               (5)
#define SPI_I2S_CCTL_TXEDGE_MASK                (0x1U << SPI_I2S_CCTL_TXEDGE_SHIFT)
#define SPI_I2S_CCTL_TXEDGE(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_TXEDGE_SHIFT)) & SPI_I2S_CCTL_TXEDGE_MASK)

#define SPI_I2S_CCTL_RXEDGE_SHIFT               (4)
#define SPI_I2S_CCTL_RXEDGE_MASK                (0x1U << SPI_I2S_CCTL_RXEDGE_SHIFT)
#define SPI_I2S_CCTL_RXEDGE(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_RXEDGE_SHIFT)) & SPI_I2S_CCTL_RXEDGE_MASK)

#define SPI_I2S_CCTL_SPILEN_SHIFT               (3)
#define SPI_I2S_CCTL_SPILEN_MASK                (0x1U << SPI_I2S_CCTL_SPILEN_SHIFT)
#define SPI_I2S_CCTL_SPILEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_SPILEN_SHIFT)) & SPI_I2S_CCTL_SPILEN_MASK)

#define SPI_I2S_CCTL_LSBFE_SHIFT                (2)
#define SPI_I2S_CCTL_LSBFE_MASK                 (0x1U << SPI_I2S_CCTL_LSBFE_SHIFT)
#define SPI_I2S_CCTL_LSBFE(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_LSBFE_SHIFT)) & SPI_I2S_CCTL_LSBFE_MASK)

#define SPI_I2S_CCTL_CPOL_SHIFT                 (1)
#define SPI_I2S_CCTL_CPOL_MASK                  (0x1U << SPI_I2S_CCTL_CPOL_SHIFT)
#define SPI_I2S_CCTL_CPOL(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_CPOL_SHIFT)) & SPI_I2S_CCTL_CPOL_MASK)

#define SPI_I2S_CCTL_CPHA_SHIFT                 (0)
#define SPI_I2S_CCTL_CPHA_MASK                  (0x1U << SPI_I2S_CCTL_CPHA_SHIFT)
#define SPI_I2S_CCTL_CPHA(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_I2S_CCTL_CPHA_SHIFT)) & SPI_I2S_CCTL_CPHA_MASK)

/*!
 * @brief SPI_I2S_SPBRG Register Bit Definition
 */

#define SPI_I2S_SPBRG_SPBRG_SHIFT               (0)
#define SPI_I2S_SPBRG_SPBRG_MASK                (0xFFFFU << SPI_I2S_SPBRG_SPBRG_SHIFT)
#define SPI_I2S_SPBRG_SPBRG(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_SPBRG_SPBRG_SHIFT)) & SPI_I2S_SPBRG_SPBRG_MASK)

/*!
 * @brief SPI_I2S_RXDNR Register Bit Definition
 */

#define SPI_I2S_RXDNR_RXDNR_SHIFT               (0)
#define SPI_I2S_RXDNR_RXDNR_MASK                (0xFFFFU << SPI_I2S_RXDNR_RXDNR_SHIFT)
#define SPI_I2S_RXDNR_RXDNR(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_I2S_RXDNR_RXDNR_SHIFT)) & SPI_I2S_RXDNR_RXDNR_MASK)

/*!
 * @brief SPI_I2S_NSSR Register Bit Definition
 */

#define SPI_I2S_NSSR_NSS_SHIFT                  (0)
#define SPI_I2S_NSSR_NSS_MASK                   (0x1U << SPI_I2S_NSSR_NSS_SHIFT)
#define SPI_I2S_NSSR_NSS(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_I2S_NSSR_NSS_SHIFT)) & SPI_I2S_NSSR_NSS_MASK)

/*!
 * @brief SPI_I2S_EXTCTL Register Bit Definition
 */

#define SPI_I2S_EXTCTL_EXTLEN_SHIFT             (0)
#define SPI_I2S_EXTCTL_EXTLEN_MASK              (0x1FU << SPI_I2S_EXTCTL_EXTLEN_SHIFT)
#define SPI_I2S_EXTCTL_EXTLEN(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_EXTCTL_EXTLEN_SHIFT)) & SPI_I2S_EXTCTL_EXTLEN_MASK)

/*!
 * @brief SPI_I2S_I2SCFGR Register Bit Definition
 */

#define SPI_I2S_I2SCFGR_I2SDIV_SHIFT            (16)
#define SPI_I2S_I2SCFGR_I2SDIV_MASK             (0x1FFU << SPI_I2S_I2SCFGR_I2SDIV_SHIFT)
#define SPI_I2S_I2SCFGR_I2SDIV(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_I2SDIV_SHIFT)) & SPI_I2S_I2SCFGR_I2SDIV_MASK)

#define SPI_I2S_I2SCFGR_MCKOE_SHIFT             (11)
#define SPI_I2S_I2SCFGR_MCKOE_MASK              (0x1U << SPI_I2S_I2SCFGR_MCKOE_SHIFT)
#define SPI_I2S_I2SCFGR_MCKOE(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_MCKOE_SHIFT)) & SPI_I2S_I2SCFGR_MCKOE_MASK)

#define SPI_I2S_I2SCFGR_SPII2S_SHIFT            (10)
#define SPI_I2S_I2SCFGR_SPII2S_MASK             (0x1U << SPI_I2S_I2SCFGR_SPII2S_SHIFT)
#define SPI_I2S_I2SCFGR_SPII2S(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_SPII2S_SHIFT)) & SPI_I2S_I2SCFGR_SPII2S_MASK)

#define SPI_I2S_I2SCFGR_PCMSYN_SHIFT            (6)
#define SPI_I2S_I2SCFGR_PCMSYN_MASK             (0x1U << SPI_I2S_I2SCFGR_PCMSYN_SHIFT)
#define SPI_I2S_I2SCFGR_PCMSYN(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_PCMSYN_SHIFT)) & SPI_I2S_I2SCFGR_PCMSYN_MASK)

#define SPI_I2S_I2SCFGR_I2SSTD_SHIFT            (4)
#define SPI_I2S_I2SCFGR_I2SSTD_MASK             (0x3U << SPI_I2S_I2SCFGR_I2SSTD_SHIFT)
#define SPI_I2S_I2SCFGR_I2SSTD(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_I2SSTD_SHIFT)) & SPI_I2S_I2SCFGR_I2SSTD_MASK)

#define SPI_I2S_I2SCFGR_DATLEN_SHIFT            (1)
#define SPI_I2S_I2SCFGR_DATLEN_MASK             (0x3U << SPI_I2S_I2SCFGR_DATLEN_SHIFT)
#define SPI_I2S_I2SCFGR_DATLEN(x)               (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_DATLEN_SHIFT)) & SPI_I2S_I2SCFGR_DATLEN_MASK)

#define SPI_I2S_I2SCFGR_CHLEN_SHIFT             (0)
#define SPI_I2S_I2SCFGR_CHLEN_MASK              (0x1U << SPI_I2S_I2SCFGR_CHLEN_SHIFT)
#define SPI_I2S_I2SCFGR_CHLEN(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_CHLEN_SHIFT)) & SPI_I2S_I2SCFGR_CHLEN_MASK)

/*!
 * @}
 */ /* end of group SPI_I2S_Register_Masks */
/******************************************************************************
 *SPI_I2S Instance
*******************************************************************************/

#define SPI1                 ((SPI_Type*)SPI1_BASE)

#define SPI2                 ((SPI_Type*)SPI2_BASE)

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */



/*!
 * @addtogroup SYSCFG_Peripheral_Access_Layer SYSCFG Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * SYSCFG Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CFGR;                                                         ///< SYSCFG Configuration Register                offset: 0x00
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t EXTICR1;                                                      ///< SYSCFG External Interrupt Configuration Register 1offset: 0x08
    __IO uint32_t EXTICR2;                                                      ///< SYSCFG External Interrupt Configuration Register 2offset: 0x0C
    __IO uint32_t EXTICR3;                                                      ///< SYSCFG External Interrupt Configuration Register 3offset: 0x10
    __IO uint32_t EXTICR4;                                                      ///< SYSCFG External Interrupt Configuration Register 4offset: 0x14
    __IO uint32_t PADHYS;                                                       ///< SYSCFG PAD Configuration Register 2          offset: 0x18
} SYSCFG_Type;

/*******************************************************************************
 * SYSCFG Type
 ******************************************************************************/

/*!
 * @addtogroup SYSCFG_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief SYSCFG_CFGR Register Bit Definition
 */

#define SYSCFG_CFGR_TIM3TRIGDMARMP_SHIFT        (29)
#define SYSCFG_CFGR_TIM3TRIGDMARMP_MASK         (0x1U << SYSCFG_CFGR_TIM3TRIGDMARMP_SHIFT)
#define SYSCFG_CFGR_TIM3TRIGDMARMP(x)           (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM3TRIGDMARMP_SHIFT)) & SYSCFG_CFGR_TIM3TRIGDMARMP_MASK)

#define SYSCFG_CFGR_TIM3CH1DMARMP_SHIFT         (28)
#define SYSCFG_CFGR_TIM3CH1DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM3CH1DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM3CH1DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM3CH1DMARMP_SHIFT)) & SYSCFG_CFGR_TIM3CH1DMARMP_MASK)

#define SYSCFG_CFGR_TIM2CH4DMARMP_SHIFT         (27)
#define SYSCFG_CFGR_TIM2CH4DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM2CH4DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM2CH4DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM2CH4DMARMP_SHIFT)) & SYSCFG_CFGR_TIM2CH4DMARMP_MASK)

#define SYSCFG_CFGR_TIM2CH2DMARMP_SHIFT         (26)
#define SYSCFG_CFGR_TIM2CH2DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM2CH2DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM2CH2DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM2CH2DMARMP_SHIFT)) & SYSCFG_CFGR_TIM2CH2DMARMP_MASK)

#define SYSCFG_CFGR_TIM1CH3DMARMP_SHIFT         (25)
#define SYSCFG_CFGR_TIM1CH3DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM1CH3DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM1CH3DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM1CH3DMARMP_SHIFT)) & SYSCFG_CFGR_TIM1CH3DMARMP_MASK)

#define SYSCFG_CFGR_TIM1CH2DMARMP_SHIFT         (24)
#define SYSCFG_CFGR_TIM1CH2DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM1CH2DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM1CH2DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM1CH2DMARMP_SHIFT)) & SYSCFG_CFGR_TIM1CH2DMARMP_MASK)

#define SYSCFG_CFGR_TIM1CH1DMARMP_SHIFT         (23)
#define SYSCFG_CFGR_TIM1CH1DMARMP_MASK          (0x1U << SYSCFG_CFGR_TIM1CH1DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM1CH1DMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM1CH1DMARMP_SHIFT)) & SYSCFG_CFGR_TIM1CH1DMARMP_MASK)

#define SYSCFG_CFGR_I2C1RXDMARMP_SHIFT          (22)
#define SYSCFG_CFGR_I2C1RXDMARMP_MASK           (0x1U << SYSCFG_CFGR_I2C1RXDMARMP_SHIFT)
#define SYSCFG_CFGR_I2C1RXDMARMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_I2C1RXDMARMP_SHIFT)) & SYSCFG_CFGR_I2C1RXDMARMP_MASK)

#define SYSCFG_CFGR_I2C1TXDMARMP_SHIFT          (21)
#define SYSCFG_CFGR_I2C1TXDMARMP_MASK           (0x1U << SYSCFG_CFGR_I2C1TXDMARMP_SHIFT)
#define SYSCFG_CFGR_I2C1TXDMARMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_I2C1TXDMARMP_SHIFT)) & SYSCFG_CFGR_I2C1TXDMARMP_MASK)

#define SYSCFG_CFGR_UART3RXDMARMP_SHIFT         (20)
#define SYSCFG_CFGR_UART3RXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART3RXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART3RXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART3RXDMARMP_SHIFT)) & SYSCFG_CFGR_UART3RXDMARMP_MASK)

#define SYSCFG_CFGR_UART3TXDMARMP_SHIFT         (19)
#define SYSCFG_CFGR_UART3TXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART3TXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART3TXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART3TXDMARMP_SHIFT)) & SYSCFG_CFGR_UART3TXDMARMP_MASK)

#define SYSCFG_CFGR_UART2RXDMARMP_SHIFT         (18)
#define SYSCFG_CFGR_UART2RXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART2RXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART2RXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART2RXDMARMP_SHIFT)) & SYSCFG_CFGR_UART2RXDMARMP_MASK)

#define SYSCFG_CFGR_UART2TXDMARMP_SHIFT         (17)
#define SYSCFG_CFGR_UART2TXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART2TXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART2TXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART2TXDMARMP_SHIFT)) & SYSCFG_CFGR_UART2TXDMARMP_MASK)

#define SYSCFG_CFGR_SPI2RXDMARMP_SHIFT          (16)
#define SYSCFG_CFGR_SPI2RXDMARMP_MASK           (0x1U << SYSCFG_CFGR_SPI2RXDMARMP_SHIFT)
#define SYSCFG_CFGR_SPI2RXDMARMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_SPI2RXDMARMP_SHIFT)) & SYSCFG_CFGR_SPI2RXDMARMP_MASK)

#define SYSCFG_CFGR_SPI2TXDMARMP_SHIFT          (15)
#define SYSCFG_CFGR_SPI2TXDMARMP_MASK           (0x1U << SYSCFG_CFGR_SPI2TXDMARMP_SHIFT)
#define SYSCFG_CFGR_SPI2TXDMARMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_SPI2TXDMARMP_SHIFT)) & SYSCFG_CFGR_SPI2TXDMARMP_MASK)

#define SYSCFG_CFGR_TIM17DMARMP_SHIFT           (12)
#define SYSCFG_CFGR_TIM17DMARMP_MASK            (0x1U << SYSCFG_CFGR_TIM17DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM17DMARMP(x)              (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM17DMARMP_SHIFT)) & SYSCFG_CFGR_TIM17DMARMP_MASK)

#define SYSCFG_CFGR_TIM16DMARMP_SHIFT           (11)
#define SYSCFG_CFGR_TIM16DMARMP_MASK            (0x1U << SYSCFG_CFGR_TIM16DMARMP_SHIFT)
#define SYSCFG_CFGR_TIM16DMARMP(x)              (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_TIM16DMARMP_SHIFT)) & SYSCFG_CFGR_TIM16DMARMP_MASK)

#define SYSCFG_CFGR_UART1RXDMARMP_SHIFT         (10)
#define SYSCFG_CFGR_UART1RXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART1RXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART1RXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART1RXDMARMP_SHIFT)) & SYSCFG_CFGR_UART1RXDMARMP_MASK)

#define SYSCFG_CFGR_UART1TXDMARMP_SHIFT         (9)
#define SYSCFG_CFGR_UART1TXDMARMP_MASK          (0x1U << SYSCFG_CFGR_UART1TXDMARMP_SHIFT)
#define SYSCFG_CFGR_UART1TXDMARMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_UART1TXDMARMP_SHIFT)) & SYSCFG_CFGR_UART1TXDMARMP_MASK)

#define SYSCFG_CFGR_ADCDMARMP_SHIFT             (8)
#define SYSCFG_CFGR_ADCDMARMP_MASK              (0x1U << SYSCFG_CFGR_ADCDMARMP_SHIFT)
#define SYSCFG_CFGR_ADCDMARMP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_ADCDMARMP_SHIFT)) & SYSCFG_CFGR_ADCDMARMP_MASK)

#define SYSCFG_CFGR_MEMMODE_SHIFT               (0)
#define SYSCFG_CFGR_MEMMODE_MASK                (0x3U << SYSCFG_CFGR_MEMMODE_SHIFT)
#define SYSCFG_CFGR_MEMMODE(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCFG_CFGR_MEMMODE_SHIFT)) & SYSCFG_CFGR_MEMMODE_MASK)

/*!
 * @brief SYSCFG_EXTICR1 Register Bit Definition
 */

#define SYSCFG_EXTICR1_EXTI3_SHIFT              (12)
#define SYSCFG_EXTICR1_EXTI3_MASK               (0xFU << SYSCFG_EXTICR1_EXTI3_SHIFT)
#define SYSCFG_EXTICR1_EXTI3(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR1_EXTI3_SHIFT)) & SYSCFG_EXTICR1_EXTI3_MASK)

#define SYSCFG_EXTICR1_EXTI2_SHIFT              (8)
#define SYSCFG_EXTICR1_EXTI2_MASK               (0xFU << SYSCFG_EXTICR1_EXTI2_SHIFT)
#define SYSCFG_EXTICR1_EXTI2(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR1_EXTI2_SHIFT)) & SYSCFG_EXTICR1_EXTI2_MASK)

#define SYSCFG_EXTICR1_EXTI1_SHIFT              (4)
#define SYSCFG_EXTICR1_EXTI1_MASK               (0xFU << SYSCFG_EXTICR1_EXTI1_SHIFT)
#define SYSCFG_EXTICR1_EXTI1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR1_EXTI1_SHIFT)) & SYSCFG_EXTICR1_EXTI1_MASK)

#define SYSCFG_EXTICR1_EXTI0_SHIFT              (0)
#define SYSCFG_EXTICR1_EXTI0_MASK               (0xFU << SYSCFG_EXTICR1_EXTI0_SHIFT)
#define SYSCFG_EXTICR1_EXTI0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR1_EXTI0_SHIFT)) & SYSCFG_EXTICR1_EXTI0_MASK)

/*!
 * @brief SYSCFG_EXTICR2 Register Bit Definition
 */

#define SYSCFG_EXTICR2_EXTI7_SHIFT              (12)
#define SYSCFG_EXTICR2_EXTI7_MASK               (0xFU << SYSCFG_EXTICR2_EXTI7_SHIFT)
#define SYSCFG_EXTICR2_EXTI7(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR2_EXTI7_SHIFT)) & SYSCFG_EXTICR2_EXTI7_MASK)

#define SYSCFG_EXTICR2_EXTI6_SHIFT              (8)
#define SYSCFG_EXTICR2_EXTI6_MASK               (0xFU << SYSCFG_EXTICR2_EXTI6_SHIFT)
#define SYSCFG_EXTICR2_EXTI6(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR2_EXTI6_SHIFT)) & SYSCFG_EXTICR2_EXTI6_MASK)

#define SYSCFG_EXTICR2_EXTI5_SHIFT              (4)
#define SYSCFG_EXTICR2_EXTI5_MASK               (0xFU << SYSCFG_EXTICR2_EXTI5_SHIFT)
#define SYSCFG_EXTICR2_EXTI5(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR2_EXTI5_SHIFT)) & SYSCFG_EXTICR2_EXTI5_MASK)

#define SYSCFG_EXTICR2_EXTI4_SHIFT              (0)
#define SYSCFG_EXTICR2_EXTI4_MASK               (0xFU << SYSCFG_EXTICR2_EXTI4_SHIFT)
#define SYSCFG_EXTICR2_EXTI4(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR2_EXTI4_SHIFT)) & SYSCFG_EXTICR2_EXTI4_MASK)

/*!
 * @brief SYSCFG_EXTICR3 Register Bit Definition
 */

#define SYSCFG_EXTICR3_EXTI11_SHIFT             (12)
#define SYSCFG_EXTICR3_EXTI11_MASK              (0xFU << SYSCFG_EXTICR3_EXTI11_SHIFT)
#define SYSCFG_EXTICR3_EXTI11(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR3_EXTI11_SHIFT)) & SYSCFG_EXTICR3_EXTI11_MASK)

#define SYSCFG_EXTICR3_EXTI10_SHIFT             (8)
#define SYSCFG_EXTICR3_EXTI10_MASK              (0xFU << SYSCFG_EXTICR3_EXTI10_SHIFT)
#define SYSCFG_EXTICR3_EXTI10(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR3_EXTI10_SHIFT)) & SYSCFG_EXTICR3_EXTI10_MASK)

#define SYSCFG_EXTICR3_EXTI9_SHIFT              (4)
#define SYSCFG_EXTICR3_EXTI9_MASK               (0xFU << SYSCFG_EXTICR3_EXTI9_SHIFT)
#define SYSCFG_EXTICR3_EXTI9(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR3_EXTI9_SHIFT)) & SYSCFG_EXTICR3_EXTI9_MASK)

#define SYSCFG_EXTICR3_EXTI8_SHIFT              (0)
#define SYSCFG_EXTICR3_EXTI8_MASK               (0xFU << SYSCFG_EXTICR3_EXTI8_SHIFT)
#define SYSCFG_EXTICR3_EXTI8(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR3_EXTI8_SHIFT)) & SYSCFG_EXTICR3_EXTI8_MASK)

/*!
 * @brief SYSCFG_EXTICR4 Register Bit Definition
 */

#define SYSCFG_EXTICR4_EXTI15_SHIFT             (12)
#define SYSCFG_EXTICR4_EXTI15_MASK              (0xFU << SYSCFG_EXTICR4_EXTI15_SHIFT)
#define SYSCFG_EXTICR4_EXTI15(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR4_EXTI15_SHIFT)) & SYSCFG_EXTICR4_EXTI15_MASK)

#define SYSCFG_EXTICR4_EXTI14_SHIFT             (8)
#define SYSCFG_EXTICR4_EXTI14_MASK              (0xFU << SYSCFG_EXTICR4_EXTI14_SHIFT)
#define SYSCFG_EXTICR4_EXTI14(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR4_EXTI14_SHIFT)) & SYSCFG_EXTICR4_EXTI14_MASK)

#define SYSCFG_EXTICR4_EXTI13_SHIFT             (4)
#define SYSCFG_EXTICR4_EXTI13_MASK              (0xFU << SYSCFG_EXTICR4_EXTI13_SHIFT)
#define SYSCFG_EXTICR4_EXTI13(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR4_EXTI13_SHIFT)) & SYSCFG_EXTICR4_EXTI13_MASK)

#define SYSCFG_EXTICR4_EXTI12_SHIFT             (0)
#define SYSCFG_EXTICR4_EXTI12_MASK              (0xFU << SYSCFG_EXTICR4_EXTI12_SHIFT)
#define SYSCFG_EXTICR4_EXTI12(x)                (((uint32_t)(((uint32_t)(x)) << SYSCFG_EXTICR4_EXTI12_SHIFT)) & SYSCFG_EXTICR4_EXTI12_MASK)

/*!
 * @brief SYSCFG_PADHYS Register Bit Definition
 */

#define SYSCFG_PADHYS_I2C1MODESEL_SHIFT         (16)
#define SYSCFG_PADHYS_I2C1MODESEL_MASK          (0x1U << SYSCFG_PADHYS_I2C1MODESEL_SHIFT)
#define SYSCFG_PADHYS_I2C1MODESEL(x)            (((uint32_t)(((uint32_t)(x)) << SYSCFG_PADHYS_I2C1MODESEL_SHIFT)) & SYSCFG_PADHYS_I2C1MODESEL_MASK)

/*!
 * @}
 */ /* end of group SYSCFG_Register_Masks */
/******************************************************************************
 *SYSCFG Instance
*******************************************************************************/

#define SYSCFG               ((SYSCFG_Type*)SYSCFG_BASE)

/*!
 * @}
 */ /* end of group SYSCFG_Peripheral_Access_Layer */



/*!
 * @addtogroup TIM1_Peripheral_Access_Layer TIM1 Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM1 Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                          ///< Control Register 1                           offset: 0x00
    __IO uint32_t CR2;                                                          ///< Control Register 2                           offset: 0x04
    __IO uint32_t SMCR;                                                         ///< Slave Mode Control Register                  offset: 0x08
    __IO uint32_t DIER;                                                         ///< DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA)offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x10
    __IO uint32_t EGR;                                                          ///< Event Generation Register                    offset: 0x14
    __IO uint32_t CCMR1;                                                        ///< Capture/Compare Mode Register 1              offset: 0x18
    __IO uint32_t CCMR2;                                                        ///< Capture/Compare Mode Register 2              offset: 0x1C
    __IO uint32_t CCER;                                                         ///< Capture/Compare Enable Register              offset: 0x20
    __IO uint32_t CNT;                                                          ///< Counter                                      offset: 0x24
    __IO uint32_t PSC;                                                          ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                          ///< Auto Reload Register                         offset: 0x2C
    __IO uint32_t RCR;                                                          ///< Repeat Count Register                        offset: 0x30
    __IO uint32_t CCR[4];                                                       ///< Capture/Compare Register                     offset: 0x34
    __IO uint32_t BDTR;                                                         ///< Break And Dead-Time Register                 offset: 0x44
    __IO uint32_t DCR;                                                          ///< DMA Control Register (only suitable for the chip with built in DMA)offset: 0x48
    __IO uint32_t DMAR;                                                         ///< DMA Address Register Of Continuous Mode (only suitable for the chip with built in DMA)offset: 0x4C
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t CCMR3;                                                        ///< Capture/Compare Mode Register 3              offset: 0x54
    __IO uint32_t CCR5;                                                         ///< Capture/Compare Register 5                   offset: 0x58
    __IO uint32_t PDER;                                                         ///< PWM Phase Shift/DMA Repeat Update Request Enable Registeroffset: 0x5C
    __IO uint32_t CCRXFALL[5];                                                  ///< PWM Phase Shift Count Down Capture/Compare Registeroffset: 0x60
    __IO uint32_t BKINF;                                                        ///< Break Input Filter Register                  offset: 0x74
} TIM1_Type;

/*******************************************************************************
 * TIM1 Type
 ******************************************************************************/

/*!
 * @addtogroup TIM1_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM1_CR1 Register Bit Definition
 */

#define TIM1_CR1_CKD_SHIFT                      (8)
#define TIM1_CR1_CKD_MASK                       (0x3U << TIM1_CR1_CKD_SHIFT)
#define TIM1_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_CKD_SHIFT)) & TIM1_CR1_CKD_MASK)

#define TIM1_CR1_ARPE_SHIFT                     (7)
#define TIM1_CR1_ARPE_MASK                      (0x1U << TIM1_CR1_ARPE_SHIFT)
#define TIM1_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_ARPE_SHIFT)) & TIM1_CR1_ARPE_MASK)

#define TIM1_CR1_CMS_SHIFT                      (5)
#define TIM1_CR1_CMS_MASK                       (0x3U << TIM1_CR1_CMS_SHIFT)
#define TIM1_CR1_CMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_CMS_SHIFT)) & TIM1_CR1_CMS_MASK)

#define TIM1_CR1_DIR_SHIFT                      (4)
#define TIM1_CR1_DIR_MASK                       (0x1U << TIM1_CR1_DIR_SHIFT)
#define TIM1_CR1_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_DIR_SHIFT)) & TIM1_CR1_DIR_MASK)

#define TIM1_CR1_OPM_SHIFT                      (3)
#define TIM1_CR1_OPM_MASK                       (0x1U << TIM1_CR1_OPM_SHIFT)
#define TIM1_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_OPM_SHIFT)) & TIM1_CR1_OPM_MASK)

#define TIM1_CR1_URS_SHIFT                      (2)
#define TIM1_CR1_URS_MASK                       (0x1U << TIM1_CR1_URS_SHIFT)
#define TIM1_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_URS_SHIFT)) & TIM1_CR1_URS_MASK)

#define TIM1_CR1_UDIS_SHIFT                     (1)
#define TIM1_CR1_UDIS_MASK                      (0x1U << TIM1_CR1_UDIS_SHIFT)
#define TIM1_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_UDIS_SHIFT)) & TIM1_CR1_UDIS_MASK)

#define TIM1_CR1_CEN_SHIFT                      (0)
#define TIM1_CR1_CEN_MASK                       (0x1U << TIM1_CR1_CEN_SHIFT)
#define TIM1_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR1_CEN_SHIFT)) & TIM1_CR1_CEN_MASK)

/*!
 * @brief TIM1_CR2 Register Bit Definition
 */

#define TIM1_CR2_OIS4_SHIFT                     (14)
#define TIM1_CR2_OIS4_MASK                      (0x1U << TIM1_CR2_OIS4_SHIFT)
#define TIM1_CR2_OIS4(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS4_SHIFT)) & TIM1_CR2_OIS4_MASK)

#define TIM1_CR2_OIS3N_SHIFT                    (13)
#define TIM1_CR2_OIS3N_MASK                     (0x1U << TIM1_CR2_OIS3N_SHIFT)
#define TIM1_CR2_OIS3N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS3N_SHIFT)) & TIM1_CR2_OIS3N_MASK)

#define TIM1_CR2_OIS3_SHIFT                     (12)
#define TIM1_CR2_OIS3_MASK                      (0x1U << TIM1_CR2_OIS3_SHIFT)
#define TIM1_CR2_OIS3(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS3_SHIFT)) & TIM1_CR2_OIS3_MASK)

#define TIM1_CR2_OIS2N_SHIFT                    (11)
#define TIM1_CR2_OIS2N_MASK                     (0x1U << TIM1_CR2_OIS2N_SHIFT)
#define TIM1_CR2_OIS2N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS2N_SHIFT)) & TIM1_CR2_OIS2N_MASK)

#define TIM1_CR2_OIS2_SHIFT                     (10)
#define TIM1_CR2_OIS2_MASK                      (0x1U << TIM1_CR2_OIS2_SHIFT)
#define TIM1_CR2_OIS2(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS2_SHIFT)) & TIM1_CR2_OIS2_MASK)

#define TIM1_CR2_OIS1N_SHIFT                    (9)
#define TIM1_CR2_OIS1N_MASK                     (0x1U << TIM1_CR2_OIS1N_SHIFT)
#define TIM1_CR2_OIS1N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS1N_SHIFT)) & TIM1_CR2_OIS1N_MASK)

#define TIM1_CR2_OIS1_SHIFT                     (8)
#define TIM1_CR2_OIS1_MASK                      (0x1U << TIM1_CR2_OIS1_SHIFT)
#define TIM1_CR2_OIS1(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_OIS1_SHIFT)) & TIM1_CR2_OIS1_MASK)

#define TIM1_CR2_TI1S_SHIFT                     (7)
#define TIM1_CR2_TI1S_MASK                      (0x1U << TIM1_CR2_TI1S_SHIFT)
#define TIM1_CR2_TI1S(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_TI1S_SHIFT)) & TIM1_CR2_TI1S_MASK)

#define TIM1_CR2_MMS_SHIFT                      (4)
#define TIM1_CR2_MMS_MASK                       (0x7U << TIM1_CR2_MMS_SHIFT)
#define TIM1_CR2_MMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_MMS_SHIFT)) & TIM1_CR2_MMS_MASK)

#define TIM1_CR2_CCDS_SHIFT                     (3)
#define TIM1_CR2_CCDS_MASK                      (0x1U << TIM1_CR2_CCDS_SHIFT)
#define TIM1_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_CCDS_SHIFT)) & TIM1_CR2_CCDS_MASK)

#define TIM1_CR2_CCUS_SHIFT                     (2)
#define TIM1_CR2_CCUS_MASK                      (0x1U << TIM1_CR2_CCUS_SHIFT)
#define TIM1_CR2_CCUS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_CCUS_SHIFT)) & TIM1_CR2_CCUS_MASK)

#define TIM1_CR2_CCPC_SHIFT                     (0)
#define TIM1_CR2_CCPC_MASK                      (0x1U << TIM1_CR2_CCPC_SHIFT)
#define TIM1_CR2_CCPC(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CR2_CCPC_SHIFT)) & TIM1_CR2_CCPC_MASK)

/*!
 * @brief TIM1_SMCR Register Bit Definition
 */

#define TIM1_SMCR_ETP_SHIFT                     (15)
#define TIM1_SMCR_ETP_MASK                      (0x1U << TIM1_SMCR_ETP_SHIFT)
#define TIM1_SMCR_ETP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_ETP_SHIFT)) & TIM1_SMCR_ETP_MASK)

#define TIM1_SMCR_ECE_SHIFT                     (14)
#define TIM1_SMCR_ECE_MASK                      (0x1U << TIM1_SMCR_ECE_SHIFT)
#define TIM1_SMCR_ECE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_ECE_SHIFT)) & TIM1_SMCR_ECE_MASK)

#define TIM1_SMCR_ETPS_SHIFT                    (12)
#define TIM1_SMCR_ETPS_MASK                     (0x3U << TIM1_SMCR_ETPS_SHIFT)
#define TIM1_SMCR_ETPS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_ETPS_SHIFT)) & TIM1_SMCR_ETPS_MASK)

#define TIM1_SMCR_ETF_SHIFT                     (8)
#define TIM1_SMCR_ETF_MASK                      (0xFU << TIM1_SMCR_ETF_SHIFT)
#define TIM1_SMCR_ETF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_ETF_SHIFT)) & TIM1_SMCR_ETF_MASK)

#define TIM1_SMCR_MSM_SHIFT                     (7)
#define TIM1_SMCR_MSM_MASK                      (0x1U << TIM1_SMCR_MSM_SHIFT)
#define TIM1_SMCR_MSM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_MSM_SHIFT)) & TIM1_SMCR_MSM_MASK)

#define TIM1_SMCR_TS_SHIFT                      (4)
#define TIM1_SMCR_TS_MASK                       (0x7U << TIM1_SMCR_TS_SHIFT)
#define TIM1_SMCR_TS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_TS_SHIFT)) & TIM1_SMCR_TS_MASK)

#define TIM1_SMCR_OCCS_SHIFT                    (3)
#define TIM1_SMCR_OCCS_MASK                     (0x1U << TIM1_SMCR_OCCS_SHIFT)
#define TIM1_SMCR_OCCS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_OCCS_SHIFT)) & TIM1_SMCR_OCCS_MASK)

#define TIM1_SMCR_SMS_SHIFT                     (0)
#define TIM1_SMCR_SMS_MASK                      (0x7U << TIM1_SMCR_SMS_SHIFT)
#define TIM1_SMCR_SMS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SMCR_SMS_SHIFT)) & TIM1_SMCR_SMS_MASK)

/*!
 * @brief TIM1_DIER Register Bit Definition
 */

#define TIM1_DIER_CC5DE_SHIFT                   (17)
#define TIM1_DIER_CC5DE_MASK                    (0x1U << TIM1_DIER_CC5DE_SHIFT)
#define TIM1_DIER_CC5DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC5DE_SHIFT)) & TIM1_DIER_CC5DE_MASK)

#define TIM1_DIER_CC5IE_SHIFT                   (16)
#define TIM1_DIER_CC5IE_MASK                    (0x1U << TIM1_DIER_CC5IE_SHIFT)
#define TIM1_DIER_CC5IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC5IE_SHIFT)) & TIM1_DIER_CC5IE_MASK)

#define TIM1_DIER_TDE_SHIFT                     (14)
#define TIM1_DIER_TDE_MASK                      (0x1U << TIM1_DIER_TDE_SHIFT)
#define TIM1_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_TDE_SHIFT)) & TIM1_DIER_TDE_MASK)

#define TIM1_DIER_COMDE_SHIFT                   (13)
#define TIM1_DIER_COMDE_MASK                    (0x1U << TIM1_DIER_COMDE_SHIFT)
#define TIM1_DIER_COMDE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_COMDE_SHIFT)) & TIM1_DIER_COMDE_MASK)

#define TIM1_DIER_CC4DE_SHIFT                   (12)
#define TIM1_DIER_CC4DE_MASK                    (0x1U << TIM1_DIER_CC4DE_SHIFT)
#define TIM1_DIER_CC4DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC4DE_SHIFT)) & TIM1_DIER_CC4DE_MASK)

#define TIM1_DIER_CC3DE_SHIFT                   (11)
#define TIM1_DIER_CC3DE_MASK                    (0x1U << TIM1_DIER_CC3DE_SHIFT)
#define TIM1_DIER_CC3DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC3DE_SHIFT)) & TIM1_DIER_CC3DE_MASK)

#define TIM1_DIER_CC2DE_SHIFT                   (10)
#define TIM1_DIER_CC2DE_MASK                    (0x1U << TIM1_DIER_CC2DE_SHIFT)
#define TIM1_DIER_CC2DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC2DE_SHIFT)) & TIM1_DIER_CC2DE_MASK)

#define TIM1_DIER_CC1DE_SHIFT                   (9)
#define TIM1_DIER_CC1DE_MASK                    (0x1U << TIM1_DIER_CC1DE_SHIFT)
#define TIM1_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC1DE_SHIFT)) & TIM1_DIER_CC1DE_MASK)

#define TIM1_DIER_UDE_SHIFT                     (8)
#define TIM1_DIER_UDE_MASK                      (0x1U << TIM1_DIER_UDE_SHIFT)
#define TIM1_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_UDE_SHIFT)) & TIM1_DIER_UDE_MASK)

#define TIM1_DIER_BIE_SHIFT                     (7)
#define TIM1_DIER_BIE_MASK                      (0x1U << TIM1_DIER_BIE_SHIFT)
#define TIM1_DIER_BIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_BIE_SHIFT)) & TIM1_DIER_BIE_MASK)

#define TIM1_DIER_TIE_SHIFT                     (6)
#define TIM1_DIER_TIE_MASK                      (0x1U << TIM1_DIER_TIE_SHIFT)
#define TIM1_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_TIE_SHIFT)) & TIM1_DIER_TIE_MASK)

#define TIM1_DIER_COMIE_SHIFT                   (5)
#define TIM1_DIER_COMIE_MASK                    (0x1U << TIM1_DIER_COMIE_SHIFT)
#define TIM1_DIER_COMIE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_COMIE_SHIFT)) & TIM1_DIER_COMIE_MASK)

#define TIM1_DIER_CC4IE_SHIFT                   (4)
#define TIM1_DIER_CC4IE_MASK                    (0x1U << TIM1_DIER_CC4IE_SHIFT)
#define TIM1_DIER_CC4IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC4IE_SHIFT)) & TIM1_DIER_CC4IE_MASK)

#define TIM1_DIER_CC3IE_SHIFT                   (3)
#define TIM1_DIER_CC3IE_MASK                    (0x1U << TIM1_DIER_CC3IE_SHIFT)
#define TIM1_DIER_CC3IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC3IE_SHIFT)) & TIM1_DIER_CC3IE_MASK)

#define TIM1_DIER_CC2IE_SHIFT                   (2)
#define TIM1_DIER_CC2IE_MASK                    (0x1U << TIM1_DIER_CC2IE_SHIFT)
#define TIM1_DIER_CC2IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC2IE_SHIFT)) & TIM1_DIER_CC2IE_MASK)

#define TIM1_DIER_CC1IE_SHIFT                   (1)
#define TIM1_DIER_CC1IE_MASK                    (0x1U << TIM1_DIER_CC1IE_SHIFT)
#define TIM1_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_CC1IE_SHIFT)) & TIM1_DIER_CC1IE_MASK)

#define TIM1_DIER_UIE_SHIFT                     (0)
#define TIM1_DIER_UIE_MASK                      (0x1U << TIM1_DIER_UIE_SHIFT)
#define TIM1_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_DIER_UIE_SHIFT)) & TIM1_DIER_UIE_MASK)

/*!
 * @brief TIM1_SR Register Bit Definition
 */

#define TIM1_SR_CC5IF_SHIFT                     (16)
#define TIM1_SR_CC5IF_MASK                      (0x1U << TIM1_SR_CC5IF_SHIFT)
#define TIM1_SR_CC5IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC5IF_SHIFT)) & TIM1_SR_CC5IF_MASK)

#define TIM1_SR_CC4OF_SHIFT                     (12)
#define TIM1_SR_CC4OF_MASK                      (0x1U << TIM1_SR_CC4OF_SHIFT)
#define TIM1_SR_CC4OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC4OF_SHIFT)) & TIM1_SR_CC4OF_MASK)

#define TIM1_SR_CC3OF_SHIFT                     (11)
#define TIM1_SR_CC3OF_MASK                      (0x1U << TIM1_SR_CC3OF_SHIFT)
#define TIM1_SR_CC3OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC3OF_SHIFT)) & TIM1_SR_CC3OF_MASK)

#define TIM1_SR_CC2OF_SHIFT                     (10)
#define TIM1_SR_CC2OF_MASK                      (0x1U << TIM1_SR_CC2OF_SHIFT)
#define TIM1_SR_CC2OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC2OF_SHIFT)) & TIM1_SR_CC2OF_MASK)

#define TIM1_SR_CC1OF_SHIFT                     (9)
#define TIM1_SR_CC1OF_MASK                      (0x1U << TIM1_SR_CC1OF_SHIFT)
#define TIM1_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC1OF_SHIFT)) & TIM1_SR_CC1OF_MASK)

#define TIM1_SR_BIF_SHIFT                       (7)
#define TIM1_SR_BIF_MASK                        (0x1U << TIM1_SR_BIF_SHIFT)
#define TIM1_SR_BIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_SR_BIF_SHIFT)) & TIM1_SR_BIF_MASK)

#define TIM1_SR_TIF_SHIFT                       (6)
#define TIM1_SR_TIF_MASK                        (0x1U << TIM1_SR_TIF_SHIFT)
#define TIM1_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_SR_TIF_SHIFT)) & TIM1_SR_TIF_MASK)

#define TIM1_SR_COMIF_SHIFT                     (5)
#define TIM1_SR_COMIF_MASK                      (0x1U << TIM1_SR_COMIF_SHIFT)
#define TIM1_SR_COMIF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_COMIF_SHIFT)) & TIM1_SR_COMIF_MASK)

#define TIM1_SR_CC4IF_SHIFT                     (4)
#define TIM1_SR_CC4IF_MASK                      (0x1U << TIM1_SR_CC4IF_SHIFT)
#define TIM1_SR_CC4IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC4IF_SHIFT)) & TIM1_SR_CC4IF_MASK)

#define TIM1_SR_CC3IF_SHIFT                     (3)
#define TIM1_SR_CC3IF_MASK                      (0x1U << TIM1_SR_CC3IF_SHIFT)
#define TIM1_SR_CC3IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC3IF_SHIFT)) & TIM1_SR_CC3IF_MASK)

#define TIM1_SR_CC2IF_SHIFT                     (2)
#define TIM1_SR_CC2IF_MASK                      (0x1U << TIM1_SR_CC2IF_SHIFT)
#define TIM1_SR_CC2IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC2IF_SHIFT)) & TIM1_SR_CC2IF_MASK)

#define TIM1_SR_CC1IF_SHIFT                     (1)
#define TIM1_SR_CC1IF_MASK                      (0x1U << TIM1_SR_CC1IF_SHIFT)
#define TIM1_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_SR_CC1IF_SHIFT)) & TIM1_SR_CC1IF_MASK)

#define TIM1_SR_UIF_SHIFT                       (0)
#define TIM1_SR_UIF_MASK                        (0x1U << TIM1_SR_UIF_SHIFT)
#define TIM1_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_SR_UIF_SHIFT)) & TIM1_SR_UIF_MASK)

/*!
 * @brief TIM1_EGR Register Bit Definition
 */

#define TIM1_EGR_CC5G_SHIFT                     (16)
#define TIM1_EGR_CC5G_MASK                      (0x1U << TIM1_EGR_CC5G_SHIFT)
#define TIM1_EGR_CC5G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_CC5G_SHIFT)) & TIM1_EGR_CC5G_MASK)

#define TIM1_EGR_BG_SHIFT                       (7)
#define TIM1_EGR_BG_MASK                        (0x1U << TIM1_EGR_BG_SHIFT)
#define TIM1_EGR_BG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_BG_SHIFT)) & TIM1_EGR_BG_MASK)

#define TIM1_EGR_TG_SHIFT                       (6)
#define TIM1_EGR_TG_MASK                        (0x1U << TIM1_EGR_TG_SHIFT)
#define TIM1_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_TG_SHIFT)) & TIM1_EGR_TG_MASK)

#define TIM1_EGR_COMG_SHIFT                     (5)
#define TIM1_EGR_COMG_MASK                      (0x1U << TIM1_EGR_COMG_SHIFT)
#define TIM1_EGR_COMG(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_COMG_SHIFT)) & TIM1_EGR_COMG_MASK)

#define TIM1_EGR_CC4G_SHIFT                     (4)
#define TIM1_EGR_CC4G_MASK                      (0x1U << TIM1_EGR_CC4G_SHIFT)
#define TIM1_EGR_CC4G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_CC4G_SHIFT)) & TIM1_EGR_CC4G_MASK)

#define TIM1_EGR_CC3G_SHIFT                     (3)
#define TIM1_EGR_CC3G_MASK                      (0x1U << TIM1_EGR_CC3G_SHIFT)
#define TIM1_EGR_CC3G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_CC3G_SHIFT)) & TIM1_EGR_CC3G_MASK)

#define TIM1_EGR_CC2G_SHIFT                     (2)
#define TIM1_EGR_CC2G_MASK                      (0x1U << TIM1_EGR_CC2G_SHIFT)
#define TIM1_EGR_CC2G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_CC2G_SHIFT)) & TIM1_EGR_CC2G_MASK)

#define TIM1_EGR_CC1G_SHIFT                     (1)
#define TIM1_EGR_CC1G_MASK                      (0x1U << TIM1_EGR_CC1G_SHIFT)
#define TIM1_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_CC1G_SHIFT)) & TIM1_EGR_CC1G_MASK)

#define TIM1_EGR_UG_SHIFT                       (0)
#define TIM1_EGR_UG_MASK                        (0x1U << TIM1_EGR_UG_SHIFT)
#define TIM1_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM1_EGR_UG_SHIFT)) & TIM1_EGR_UG_MASK)

/*!
 * @brief TIM1_CCMR1_OUTPUT Register Bit Definition
 */

#define TIM1_CCMR1OUTPUT_OC2CE_SHIFT            (15)
#define TIM1_CCMR1OUTPUT_OC2CE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC2CE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC2CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC2CE_SHIFT)) & TIM1_CCMR1OUTPUT_OC2CE_MASK)

#define TIM1_CCMR1OUTPUT_OC2M_SHIFT             (12)
#define TIM1_CCMR1OUTPUT_OC2M_MASK              (0x7U << TIM1_CCMR1OUTPUT_OC2M_SHIFT)
#define TIM1_CCMR1OUTPUT_OC2M(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC2M_SHIFT)) & TIM1_CCMR1OUTPUT_OC2M_MASK)

#define TIM1_CCMR1OUTPUT_OC2PE_SHIFT            (11)
#define TIM1_CCMR1OUTPUT_OC2PE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC2PE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC2PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC2PE_SHIFT)) & TIM1_CCMR1OUTPUT_OC2PE_MASK)

#define TIM1_CCMR1OUTPUT_OC2FE_SHIFT            (10)
#define TIM1_CCMR1OUTPUT_OC2FE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC2FE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC2FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC2FE_SHIFT)) & TIM1_CCMR1OUTPUT_OC2FE_MASK)

#define TIM1_CCMR1OUTPUT_CC2S_SHIFT             (8)
#define TIM1_CCMR1OUTPUT_CC2S_MASK              (0x3U << TIM1_CCMR1OUTPUT_CC2S_SHIFT)
#define TIM1_CCMR1OUTPUT_CC2S(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_CC2S_SHIFT)) & TIM1_CCMR1OUTPUT_CC2S_MASK)

#define TIM1_CCMR1OUTPUT_OC1CE_SHIFT            (7)
#define TIM1_CCMR1OUTPUT_OC1CE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC1CE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC1CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC1CE_SHIFT)) & TIM1_CCMR1OUTPUT_OC1CE_MASK)

#define TIM1_CCMR1OUTPUT_OC1M_SHIFT             (4)
#define TIM1_CCMR1OUTPUT_OC1M_MASK              (0x7U << TIM1_CCMR1OUTPUT_OC1M_SHIFT)
#define TIM1_CCMR1OUTPUT_OC1M(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC1M_SHIFT)) & TIM1_CCMR1OUTPUT_OC1M_MASK)

#define TIM1_CCMR1OUTPUT_OC1PE_SHIFT            (3)
#define TIM1_CCMR1OUTPUT_OC1PE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC1PE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC1PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC1PE_SHIFT)) & TIM1_CCMR1OUTPUT_OC1PE_MASK)

#define TIM1_CCMR1OUTPUT_OC1FE_SHIFT            (2)
#define TIM1_CCMR1OUTPUT_OC1FE_MASK             (0x1U << TIM1_CCMR1OUTPUT_OC1FE_SHIFT)
#define TIM1_CCMR1OUTPUT_OC1FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_OC1FE_SHIFT)) & TIM1_CCMR1OUTPUT_OC1FE_MASK)

#define TIM1_CCMR1OUTPUT_CC1S_SHIFT             (0)
#define TIM1_CCMR1OUTPUT_CC1S_MASK              (0x3U << TIM1_CCMR1OUTPUT_CC1S_SHIFT)
#define TIM1_CCMR1OUTPUT_CC1S(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1OUTPUT_CC1S_SHIFT)) & TIM1_CCMR1OUTPUT_CC1S_MASK)

/*!
 * @brief TIM1_CCMR1_INPUT Register Bit Definition
 */

#define TIM1_CCMR1INPUT_IC2F_SHIFT              (12)
#define TIM1_CCMR1INPUT_IC2F_MASK               (0xFU << TIM1_CCMR1INPUT_IC2F_SHIFT)
#define TIM1_CCMR1INPUT_IC2F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_IC2F_SHIFT)) & TIM1_CCMR1INPUT_IC2F_MASK)

#define TIM1_CCMR1INPUT_IC2PSC_SHIFT            (10)
#define TIM1_CCMR1INPUT_IC2PSC_MASK             (0x3U << TIM1_CCMR1INPUT_IC2PSC_SHIFT)
#define TIM1_CCMR1INPUT_IC2PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_IC2PSC_SHIFT)) & TIM1_CCMR1INPUT_IC2PSC_MASK)

#define TIM1_CCMR1INPUT_CC2S_SHIFT              (8)
#define TIM1_CCMR1INPUT_CC2S_MASK               (0x3U << TIM1_CCMR1INPUT_CC2S_SHIFT)
#define TIM1_CCMR1INPUT_CC2S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_CC2S_SHIFT)) & TIM1_CCMR1INPUT_CC2S_MASK)

#define TIM1_CCMR1INPUT_IC1F_SHIFT              (4)
#define TIM1_CCMR1INPUT_IC1F_MASK               (0xFU << TIM1_CCMR1INPUT_IC1F_SHIFT)
#define TIM1_CCMR1INPUT_IC1F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_IC1F_SHIFT)) & TIM1_CCMR1INPUT_IC1F_MASK)

#define TIM1_CCMR1INPUT_IC1PSC_SHIFT            (2)
#define TIM1_CCMR1INPUT_IC1PSC_MASK             (0x3U << TIM1_CCMR1INPUT_IC1PSC_SHIFT)
#define TIM1_CCMR1INPUT_IC1PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_IC1PSC_SHIFT)) & TIM1_CCMR1INPUT_IC1PSC_MASK)

#define TIM1_CCMR1INPUT_CC1S_SHIFT              (0)
#define TIM1_CCMR1INPUT_CC1S_MASK               (0x3U << TIM1_CCMR1INPUT_CC1S_SHIFT)
#define TIM1_CCMR1INPUT_CC1S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR1INPUT_CC1S_SHIFT)) & TIM1_CCMR1INPUT_CC1S_MASK)

/*!
 * @brief TIM1_CCMR2_OUTPUT Register Bit Definition
 */

#define TIM1_CCMR2OUTPUT_OC4CE_SHIFT            (15)
#define TIM1_CCMR2OUTPUT_OC4CE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC4CE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC4CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC4CE_SHIFT)) & TIM1_CCMR2OUTPUT_OC4CE_MASK)

#define TIM1_CCMR2OUTPUT_OC4M_SHIFT             (12)
#define TIM1_CCMR2OUTPUT_OC4M_MASK              (0x7U << TIM1_CCMR2OUTPUT_OC4M_SHIFT)
#define TIM1_CCMR2OUTPUT_OC4M(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC4M_SHIFT)) & TIM1_CCMR2OUTPUT_OC4M_MASK)

#define TIM1_CCMR2OUTPUT_OC4PE_SHIFT            (11)
#define TIM1_CCMR2OUTPUT_OC4PE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC4PE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC4PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC4PE_SHIFT)) & TIM1_CCMR2OUTPUT_OC4PE_MASK)

#define TIM1_CCMR2OUTPUT_OC4FE_SHIFT            (10)
#define TIM1_CCMR2OUTPUT_OC4FE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC4FE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC4FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC4FE_SHIFT)) & TIM1_CCMR2OUTPUT_OC4FE_MASK)

#define TIM1_CCMR2OUTPUT_CC4S_SHIFT             (8)
#define TIM1_CCMR2OUTPUT_CC4S_MASK              (0x3U << TIM1_CCMR2OUTPUT_CC4S_SHIFT)
#define TIM1_CCMR2OUTPUT_CC4S(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_CC4S_SHIFT)) & TIM1_CCMR2OUTPUT_CC4S_MASK)

#define TIM1_CCMR2OUTPUT_OC3CE_SHIFT            (7)
#define TIM1_CCMR2OUTPUT_OC3CE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC3CE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC3CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC3CE_SHIFT)) & TIM1_CCMR2OUTPUT_OC3CE_MASK)

#define TIM1_CCMR2OUTPUT_OC3M_SHIFT             (4)
#define TIM1_CCMR2OUTPUT_OC3M_MASK              (0x7U << TIM1_CCMR2OUTPUT_OC3M_SHIFT)
#define TIM1_CCMR2OUTPUT_OC3M(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC3M_SHIFT)) & TIM1_CCMR2OUTPUT_OC3M_MASK)

#define TIM1_CCMR2OUTPUT_OC3PE_SHIFT            (3)
#define TIM1_CCMR2OUTPUT_OC3PE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC3PE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC3PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC3PE_SHIFT)) & TIM1_CCMR2OUTPUT_OC3PE_MASK)

#define TIM1_CCMR2OUTPUT_OC3FE_SHIFT            (2)
#define TIM1_CCMR2OUTPUT_OC3FE_MASK             (0x1U << TIM1_CCMR2OUTPUT_OC3FE_SHIFT)
#define TIM1_CCMR2OUTPUT_OC3FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_OC3FE_SHIFT)) & TIM1_CCMR2OUTPUT_OC3FE_MASK)

#define TIM1_CCMR2OUTPUT_CC3S_SHIFT             (0)
#define TIM1_CCMR2OUTPUT_CC3S_MASK              (0x3U << TIM1_CCMR2OUTPUT_CC3S_SHIFT)
#define TIM1_CCMR2OUTPUT_CC3S(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2OUTPUT_CC3S_SHIFT)) & TIM1_CCMR2OUTPUT_CC3S_MASK)

/*!
 * @brief TIM1_CCMR2_INPUT Register Bit Definition
 */

#define TIM1_CCMR2INPUT_IC4F_SHIFT              (12)
#define TIM1_CCMR2INPUT_IC4F_MASK               (0xFU << TIM1_CCMR2INPUT_IC4F_SHIFT)
#define TIM1_CCMR2INPUT_IC4F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_IC4F_SHIFT)) & TIM1_CCMR2INPUT_IC4F_MASK)

#define TIM1_CCMR2INPUT_IC4PSC_SHIFT            (10)
#define TIM1_CCMR2INPUT_IC4PSC_MASK             (0x3U << TIM1_CCMR2INPUT_IC4PSC_SHIFT)
#define TIM1_CCMR2INPUT_IC4PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_IC4PSC_SHIFT)) & TIM1_CCMR2INPUT_IC4PSC_MASK)

#define TIM1_CCMR2INPUT_CC4S_SHIFT              (8)
#define TIM1_CCMR2INPUT_CC4S_MASK               (0x3U << TIM1_CCMR2INPUT_CC4S_SHIFT)
#define TIM1_CCMR2INPUT_CC4S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_CC4S_SHIFT)) & TIM1_CCMR2INPUT_CC4S_MASK)

#define TIM1_CCMR2INPUT_IC3F_SHIFT              (4)
#define TIM1_CCMR2INPUT_IC3F_MASK               (0xFU << TIM1_CCMR2INPUT_IC3F_SHIFT)
#define TIM1_CCMR2INPUT_IC3F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_IC3F_SHIFT)) & TIM1_CCMR2INPUT_IC3F_MASK)

#define TIM1_CCMR2INPUT_IC3PSC_SHIFT            (2)
#define TIM1_CCMR2INPUT_IC3PSC_MASK             (0x3U << TIM1_CCMR2INPUT_IC3PSC_SHIFT)
#define TIM1_CCMR2INPUT_IC3PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_IC3PSC_SHIFT)) & TIM1_CCMR2INPUT_IC3PSC_MASK)

#define TIM1_CCMR2INPUT_CC3S_SHIFT              (0)
#define TIM1_CCMR2INPUT_CC3S_MASK               (0x3U << TIM1_CCMR2INPUT_CC3S_SHIFT)
#define TIM1_CCMR2INPUT_CC3S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR2INPUT_CC3S_SHIFT)) & TIM1_CCMR2INPUT_CC3S_MASK)

/*!
 * @brief TIM1_CCER Register Bit Definition
 */

#define TIM1_CCER_CC4NP_SHIFT                   (15)
#define TIM1_CCER_CC4NP_MASK                    (0x1U << TIM1_CCER_CC4NP_SHIFT)
#define TIM1_CCER_CC4NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC4NP_SHIFT)) & TIM1_CCER_CC4NP_MASK)

#define TIM1_CCER_CC4P_SHIFT                    (13)
#define TIM1_CCER_CC4P_MASK                     (0x1U << TIM1_CCER_CC4P_SHIFT)
#define TIM1_CCER_CC4P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC4P_SHIFT)) & TIM1_CCER_CC4P_MASK)

#define TIM1_CCER_CC4E_SHIFT                    (12)
#define TIM1_CCER_CC4E_MASK                     (0x1U << TIM1_CCER_CC4E_SHIFT)
#define TIM1_CCER_CC4E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC4E_SHIFT)) & TIM1_CCER_CC4E_MASK)

#define TIM1_CCER_CC3NP_SHIFT                   (11)
#define TIM1_CCER_CC3NP_MASK                    (0x1U << TIM1_CCER_CC3NP_SHIFT)
#define TIM1_CCER_CC3NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC3NP_SHIFT)) & TIM1_CCER_CC3NP_MASK)

#define TIM1_CCER_CC3NE_SHIFT                   (10)
#define TIM1_CCER_CC3NE_MASK                    (0x1U << TIM1_CCER_CC3NE_SHIFT)
#define TIM1_CCER_CC3NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC3NE_SHIFT)) & TIM1_CCER_CC3NE_MASK)

#define TIM1_CCER_CC3P_SHIFT                    (9)
#define TIM1_CCER_CC3P_MASK                     (0x1U << TIM1_CCER_CC3P_SHIFT)
#define TIM1_CCER_CC3P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC3P_SHIFT)) & TIM1_CCER_CC3P_MASK)

#define TIM1_CCER_CC3E_SHIFT                    (8)
#define TIM1_CCER_CC3E_MASK                     (0x1U << TIM1_CCER_CC3E_SHIFT)
#define TIM1_CCER_CC3E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC3E_SHIFT)) & TIM1_CCER_CC3E_MASK)

#define TIM1_CCER_CC2NP_SHIFT                   (7)
#define TIM1_CCER_CC2NP_MASK                    (0x1U << TIM1_CCER_CC2NP_SHIFT)
#define TIM1_CCER_CC2NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC2NP_SHIFT)) & TIM1_CCER_CC2NP_MASK)

#define TIM1_CCER_CC2NE_SHIFT                   (6)
#define TIM1_CCER_CC2NE_MASK                    (0x1U << TIM1_CCER_CC2NE_SHIFT)
#define TIM1_CCER_CC2NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC2NE_SHIFT)) & TIM1_CCER_CC2NE_MASK)

#define TIM1_CCER_CC2P_SHIFT                    (5)
#define TIM1_CCER_CC2P_MASK                     (0x1U << TIM1_CCER_CC2P_SHIFT)
#define TIM1_CCER_CC2P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC2P_SHIFT)) & TIM1_CCER_CC2P_MASK)

#define TIM1_CCER_CC2E_SHIFT                    (4)
#define TIM1_CCER_CC2E_MASK                     (0x1U << TIM1_CCER_CC2E_SHIFT)
#define TIM1_CCER_CC2E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC2E_SHIFT)) & TIM1_CCER_CC2E_MASK)

#define TIM1_CCER_CC1NP_SHIFT                   (3)
#define TIM1_CCER_CC1NP_MASK                    (0x1U << TIM1_CCER_CC1NP_SHIFT)
#define TIM1_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC1NP_SHIFT)) & TIM1_CCER_CC1NP_MASK)

#define TIM1_CCER_CC1NE_SHIFT                   (2)
#define TIM1_CCER_CC1NE_MASK                    (0x1U << TIM1_CCER_CC1NE_SHIFT)
#define TIM1_CCER_CC1NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC1NE_SHIFT)) & TIM1_CCER_CC1NE_MASK)

#define TIM1_CCER_CC1P_SHIFT                    (1)
#define TIM1_CCER_CC1P_MASK                     (0x1U << TIM1_CCER_CC1P_SHIFT)
#define TIM1_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC1P_SHIFT)) & TIM1_CCER_CC1P_MASK)

#define TIM1_CCER_CC1E_SHIFT                    (0)
#define TIM1_CCER_CC1E_MASK                     (0x1U << TIM1_CCER_CC1E_SHIFT)
#define TIM1_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCER_CC1E_SHIFT)) & TIM1_CCER_CC1E_MASK)

/*!
 * @brief TIM1_CNT Register Bit Definition
 */

#define TIM1_CNT_CNT_SHIFT                      (0)
#define TIM1_CNT_CNT_MASK                       (0xFFFFU << TIM1_CNT_CNT_SHIFT)
#define TIM1_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_CNT_CNT_SHIFT)) & TIM1_CNT_CNT_MASK)

/*!
 * @brief TIM1_PSC Register Bit Definition
 */

#define TIM1_PSC_PSC_SHIFT                      (0)
#define TIM1_PSC_PSC_MASK                       (0xFFFFU << TIM1_PSC_PSC_SHIFT)
#define TIM1_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_PSC_PSC_SHIFT)) & TIM1_PSC_PSC_MASK)

/*!
 * @brief TIM1_ARR Register Bit Definition
 */

#define TIM1_ARR_ARR_SHIFT                      (0)
#define TIM1_ARR_ARR_MASK                       (0xFFFFU << TIM1_ARR_ARR_SHIFT)
#define TIM1_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_ARR_ARR_SHIFT)) & TIM1_ARR_ARR_MASK)

/*!
 * @brief TIM1_RCR Register Bit Definition
 */

#define TIM1_RCR_REPCNT_SHIFT                   (8)
#define TIM1_RCR_REPCNT_MASK                    (0xFFU << TIM1_RCR_REPCNT_SHIFT)
#define TIM1_RCR_REPCNT(x)                      (((uint32_t)(((uint32_t)(x)) << TIM1_RCR_REPCNT_SHIFT)) & TIM1_RCR_REPCNT_MASK)

#define TIM1_RCR_REP_SHIFT                      (0)
#define TIM1_RCR_REP_MASK                       (0xFFU << TIM1_RCR_REP_SHIFT)
#define TIM1_RCR_REP(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_RCR_REP_SHIFT)) & TIM1_RCR_REP_MASK)

/*!
 * @brief TIM1_CCR Register Bit Definition
 */

#define TIM1_CCR_CCR1_SHIFT                     (0)
#define TIM1_CCR_CCR1_MASK                      (0xFFFFU << TIM1_CCR_CCR1_SHIFT)
#define TIM1_CCR_CCR1(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_CCR_CCR1_SHIFT)) & TIM1_CCR_CCR1_MASK)

/*!
 * @brief TIM1_BDTR Register Bit Definition
 */

#define TIM1_BDTR_DOE_SHIFT                     (16)
#define TIM1_BDTR_DOE_MASK                      (0x1U << TIM1_BDTR_DOE_SHIFT)
#define TIM1_BDTR_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_DOE_SHIFT)) & TIM1_BDTR_DOE_MASK)

#define TIM1_BDTR_MOE_SHIFT                     (15)
#define TIM1_BDTR_MOE_MASK                      (0x1U << TIM1_BDTR_MOE_SHIFT)
#define TIM1_BDTR_MOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_MOE_SHIFT)) & TIM1_BDTR_MOE_MASK)

#define TIM1_BDTR_AOE_SHIFT                     (14)
#define TIM1_BDTR_AOE_MASK                      (0x1U << TIM1_BDTR_AOE_SHIFT)
#define TIM1_BDTR_AOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_AOE_SHIFT)) & TIM1_BDTR_AOE_MASK)

#define TIM1_BDTR_BKP_SHIFT                     (13)
#define TIM1_BDTR_BKP_MASK                      (0x1U << TIM1_BDTR_BKP_SHIFT)
#define TIM1_BDTR_BKP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_BKP_SHIFT)) & TIM1_BDTR_BKP_MASK)

#define TIM1_BDTR_BKE_SHIFT                     (12)
#define TIM1_BDTR_BKE_MASK                      (0x1U << TIM1_BDTR_BKE_SHIFT)
#define TIM1_BDTR_BKE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_BKE_SHIFT)) & TIM1_BDTR_BKE_MASK)

#define TIM1_BDTR_OSSR_SHIFT                    (11)
#define TIM1_BDTR_OSSR_MASK                     (0x1U << TIM1_BDTR_OSSR_SHIFT)
#define TIM1_BDTR_OSSR(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_OSSR_SHIFT)) & TIM1_BDTR_OSSR_MASK)

#define TIM1_BDTR_OSSI_SHIFT                    (10)
#define TIM1_BDTR_OSSI_MASK                     (0x1U << TIM1_BDTR_OSSI_SHIFT)
#define TIM1_BDTR_OSSI(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_OSSI_SHIFT)) & TIM1_BDTR_OSSI_MASK)

#define TIM1_BDTR_LOCK_SHIFT                    (8)
#define TIM1_BDTR_LOCK_MASK                     (0x3U << TIM1_BDTR_LOCK_SHIFT)
#define TIM1_BDTR_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_LOCK_SHIFT)) & TIM1_BDTR_LOCK_MASK)

#define TIM1_BDTR_DTG_SHIFT                     (0)
#define TIM1_BDTR_DTG_MASK                      (0xFFU << TIM1_BDTR_DTG_SHIFT)
#define TIM1_BDTR_DTG(x)                        (((uint32_t)(((uint32_t)(x)) << TIM1_BDTR_DTG_SHIFT)) & TIM1_BDTR_DTG_MASK)

/*!
 * @brief TIM1_DCR Register Bit Definition
 */

#define TIM1_DCR_DBL_SHIFT                      (8)
#define TIM1_DCR_DBL_MASK                       (0x1FU << TIM1_DCR_DBL_SHIFT)
#define TIM1_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_DCR_DBL_SHIFT)) & TIM1_DCR_DBL_MASK)

#define TIM1_DCR_DBA_SHIFT                      (0)
#define TIM1_DCR_DBA_MASK                       (0x1FU << TIM1_DCR_DBA_SHIFT)
#define TIM1_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x)) << TIM1_DCR_DBA_SHIFT)) & TIM1_DCR_DBA_MASK)

/*!
 * @brief TIM1_DMAR Register Bit Definition
 */

#define TIM1_DMAR_DMAB_SHIFT                    (0)
#define TIM1_DMAR_DMAB_MASK                     (0xFFFFU << TIM1_DMAR_DMAB_SHIFT)
#define TIM1_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_DMAR_DMAB_SHIFT)) & TIM1_DMAR_DMAB_MASK)

/*!
 * @brief TIM1_CCMR3 Register Bit Definition
 */

#define TIM1_CCMR3_OC5PE_SHIFT                  (3)
#define TIM1_CCMR3_OC5PE_MASK                   (0x1U << TIM1_CCMR3_OC5PE_SHIFT)
#define TIM1_CCMR3_OC5PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM1_CCMR3_OC5PE_SHIFT)) & TIM1_CCMR3_OC5PE_MASK)

/*!
 * @brief TIM1_CCR5 Register Bit Definition
 */

#define TIM1_CCR5_CCR5_SHIFT                    (0)
#define TIM1_CCR5_CCR5_MASK                     (0xFFFFU << TIM1_CCR5_CCR5_SHIFT)
#define TIM1_CCR5_CCR5(x)                       (((uint32_t)(((uint32_t)(x)) << TIM1_CCR5_CCR5_SHIFT)) & TIM1_CCR5_CCR5_MASK)

/*!
 * @brief TIM1_PDER Register Bit Definition
 */

#define TIM1_PDER_CCR5SHIFTEN_SHIFT             (5)
#define TIM1_PDER_CCR5SHIFTEN_MASK              (0x1U << TIM1_PDER_CCR5SHIFTEN_SHIFT)
#define TIM1_PDER_CCR5SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCR5SHIFTEN_SHIFT)) & TIM1_PDER_CCR5SHIFTEN_MASK)

#define TIM1_PDER_CCR4SHIFTEN_SHIFT             (4)
#define TIM1_PDER_CCR4SHIFTEN_MASK              (0x1U << TIM1_PDER_CCR4SHIFTEN_SHIFT)
#define TIM1_PDER_CCR4SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCR4SHIFTEN_SHIFT)) & TIM1_PDER_CCR4SHIFTEN_MASK)

#define TIM1_PDER_CCR3SHIFTEN_SHIFT             (3)
#define TIM1_PDER_CCR3SHIFTEN_MASK              (0x1U << TIM1_PDER_CCR3SHIFTEN_SHIFT)
#define TIM1_PDER_CCR3SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCR3SHIFTEN_SHIFT)) & TIM1_PDER_CCR3SHIFTEN_MASK)

#define TIM1_PDER_CCR2SHIFTEN_SHIFT             (2)
#define TIM1_PDER_CCR2SHIFTEN_MASK              (0x1U << TIM1_PDER_CCR2SHIFTEN_SHIFT)
#define TIM1_PDER_CCR2SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCR2SHIFTEN_SHIFT)) & TIM1_PDER_CCR2SHIFTEN_MASK)

#define TIM1_PDER_CCR1SHIFTEN_SHIFT             (1)
#define TIM1_PDER_CCR1SHIFTEN_MASK              (0x1U << TIM1_PDER_CCR1SHIFTEN_SHIFT)
#define TIM1_PDER_CCR1SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCR1SHIFTEN_SHIFT)) & TIM1_PDER_CCR1SHIFTEN_MASK)

#define TIM1_PDER_CCDREPE_SHIFT                 (0)
#define TIM1_PDER_CCDREPE_MASK                  (0x1U << TIM1_PDER_CCDREPE_SHIFT)
#define TIM1_PDER_CCDREPE(x)                    (((uint32_t)(((uint32_t)(x)) << TIM1_PDER_CCDREPE_SHIFT)) & TIM1_PDER_CCDREPE_MASK)

/*!
 * @brief TIM1_CCRxFALL Register Bit Definition
 */

#define TIM1_CCRxFALL_CCRXFALL_SHIFT            (0)
#define TIM1_CCRxFALL_CCRXFALL_MASK             (0xFFFFU << TIM1_CCRxFALL_CCRXFALL_SHIFT)
#define TIM1_CCRxFALL_CCRXFALL(x)               (((uint32_t)(((uint32_t)(x)) << TIM1_CCRxFALL_CCRXFALL_SHIFT)) & TIM1_CCRxFALL_CCRXFALL_MASK)

/*!
 * @brief TIM1_BKINF Register Bit Definition
 */

#define TIM1_BKINF_BKINSEL_SHIFT                (5)
#define TIM1_BKINF_BKINSEL_MASK                 (0xFFFU << TIM1_BKINF_BKINSEL_SHIFT)
#define TIM1_BKINF_BKINSEL(x)                   (((uint32_t)(((uint32_t)(x)) << TIM1_BKINF_BKINSEL_SHIFT)) & TIM1_BKINF_BKINSEL_MASK)

#define TIM1_BKINF_BKINF_SHIFT                  (1)
#define TIM1_BKINF_BKINF_MASK                   (0xFU << TIM1_BKINF_BKINF_SHIFT)
#define TIM1_BKINF_BKINF(x)                     (((uint32_t)(((uint32_t)(x)) << TIM1_BKINF_BKINF_SHIFT)) & TIM1_BKINF_BKINF_MASK)

#define TIM1_BKINF_BKINFE_SHIFT                 (0)
#define TIM1_BKINF_BKINFE_MASK                  (0x1U << TIM1_BKINF_BKINFE_SHIFT)
#define TIM1_BKINF_BKINFE(x)                    (((uint32_t)(((uint32_t)(x)) << TIM1_BKINF_BKINFE_SHIFT)) & TIM1_BKINF_BKINFE_MASK)

/*!
 * @}
 */ /* end of group TIM1_Register_Masks */
/******************************************************************************
 *TIM1 Instance
*******************************************************************************/

#define TIM1                 ((TIM1_Type*)TIM1_BASE)

/*!
 * @}
 */ /* end of group TIM1_Peripheral_Access_Layer */



/*!
 * @addtogroup TIM14_Peripheral_Access_Layer TIM14 Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM14 Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                          ///< Control Register 1                           offset: 0x00
    __IO uint32_t Reserved0[2];                                                 ///< Reserved
    __IO uint32_t DIER;                                                         ///< DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA)offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x10
    __IO uint32_t EGR;                                                          ///< Event Generation Register                    offset: 0x14
    __IO uint32_t CCMR1;                                                        ///< Capture/Compare Mode Register 1              offset: 0x18
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t CCER;                                                         ///< Capture/Compare Enable Register              offset: 0x20
    __IO uint32_t CNT;                                                          ///< Counter                                      offset: 0x24
    __IO uint32_t PSC;                                                          ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                          ///< Auto Reload Register                         offset: 0x2C
    __IO uint32_t Reserved2[1];                                                 ///< Reserved
    __IO uint32_t CCR1;                                                         ///< Capture/Compare Register 1                   offset: 0x34
    __IO uint32_t Reserved3[3];                                                 ///< Reserved
    __IO uint32_t BDTR;                                                         ///< Break And Dead-Time Register                 offset: 0x44
} TIM14_Type;

/*******************************************************************************
 * TIM14 Type
 ******************************************************************************/

/*!
 * @addtogroup TIM14_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM14_CR1 Register Bit Definition
 */

#define TIM14_CR1_CKD_SHIFT                     (8)
#define TIM14_CR1_CKD_MASK                      (0x3U << TIM14_CR1_CKD_SHIFT)
#define TIM14_CR1_CKD(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_CKD_SHIFT)) & TIM14_CR1_CKD_MASK)

#define TIM14_CR1_ARPE_SHIFT                    (7)
#define TIM14_CR1_ARPE_MASK                     (0x1U << TIM14_CR1_ARPE_SHIFT)
#define TIM14_CR1_ARPE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_ARPE_SHIFT)) & TIM14_CR1_ARPE_MASK)

#define TIM14_CR1_OPM_SHIFT                     (3)
#define TIM14_CR1_OPM_MASK                      (0x1U << TIM14_CR1_OPM_SHIFT)
#define TIM14_CR1_OPM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_OPM_SHIFT)) & TIM14_CR1_OPM_MASK)

#define TIM14_CR1_URS_SHIFT                     (2)
#define TIM14_CR1_URS_MASK                      (0x1U << TIM14_CR1_URS_SHIFT)
#define TIM14_CR1_URS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_URS_SHIFT)) & TIM14_CR1_URS_MASK)

#define TIM14_CR1_UDIS_SHIFT                    (1)
#define TIM14_CR1_UDIS_MASK                     (0x1U << TIM14_CR1_UDIS_SHIFT)
#define TIM14_CR1_UDIS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_UDIS_SHIFT)) & TIM14_CR1_UDIS_MASK)

#define TIM14_CR1_CEN_SHIFT                     (0)
#define TIM14_CR1_CEN_MASK                      (0x1U << TIM14_CR1_CEN_SHIFT)
#define TIM14_CR1_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_CR1_CEN_SHIFT)) & TIM14_CR1_CEN_MASK)

/*!
 * @brief TIM14_DIER Register Bit Definition
 */

#define TIM14_DIER_CC1DE_SHIFT                  (9)
#define TIM14_DIER_CC1DE_MASK                   (0x1U << TIM14_DIER_CC1DE_SHIFT)
#define TIM14_DIER_CC1DE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM14_DIER_CC1DE_SHIFT)) & TIM14_DIER_CC1DE_MASK)

#define TIM14_DIER_UDE_SHIFT                    (8)
#define TIM14_DIER_UDE_MASK                     (0x1U << TIM14_DIER_UDE_SHIFT)
#define TIM14_DIER_UDE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_DIER_UDE_SHIFT)) & TIM14_DIER_UDE_MASK)

#define TIM14_DIER_CC1IE_SHIFT                  (1)
#define TIM14_DIER_CC1IE_MASK                   (0x1U << TIM14_DIER_CC1IE_SHIFT)
#define TIM14_DIER_CC1IE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM14_DIER_CC1IE_SHIFT)) & TIM14_DIER_CC1IE_MASK)

#define TIM14_DIER_UIE_SHIFT                    (0)
#define TIM14_DIER_UIE_MASK                     (0x1U << TIM14_DIER_UIE_SHIFT)
#define TIM14_DIER_UIE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_DIER_UIE_SHIFT)) & TIM14_DIER_UIE_MASK)

/*!
 * @brief TIM14_SR Register Bit Definition
 */

#define TIM14_SR_CC1OF_SHIFT                    (9)
#define TIM14_SR_CC1OF_MASK                     (0x1U << TIM14_SR_CC1OF_SHIFT)
#define TIM14_SR_CC1OF(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_SR_CC1OF_SHIFT)) & TIM14_SR_CC1OF_MASK)

#define TIM14_SR_CC1IF_SHIFT                    (1)
#define TIM14_SR_CC1IF_MASK                     (0x1U << TIM14_SR_CC1IF_SHIFT)
#define TIM14_SR_CC1IF(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_SR_CC1IF_SHIFT)) & TIM14_SR_CC1IF_MASK)

#define TIM14_SR_UIF_SHIFT                      (0)
#define TIM14_SR_UIF_MASK                       (0x1U << TIM14_SR_UIF_SHIFT)
#define TIM14_SR_UIF(x)                         (((uint32_t)(((uint32_t)(x)) << TIM14_SR_UIF_SHIFT)) & TIM14_SR_UIF_MASK)

/*!
 * @brief TIM14_EGR Register Bit Definition
 */

#define TIM14_EGR_CC1G_SHIFT                    (1)
#define TIM14_EGR_CC1G_MASK                     (0x1U << TIM14_EGR_CC1G_SHIFT)
#define TIM14_EGR_CC1G(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_EGR_CC1G_SHIFT)) & TIM14_EGR_CC1G_MASK)

#define TIM14_EGR_UG_SHIFT                      (0)
#define TIM14_EGR_UG_MASK                       (0x1U << TIM14_EGR_UG_SHIFT)
#define TIM14_EGR_UG(x)                         (((uint32_t)(((uint32_t)(x)) << TIM14_EGR_UG_SHIFT)) & TIM14_EGR_UG_MASK)

/*!
 * @brief TIM14_CCMR1_OUTPUT Register Bit Definition
 */

#define TIM14_CCMR1OUTPUT_OC1M_SHIFT            (4)
#define TIM14_CCMR1OUTPUT_OC1M_MASK             (0x7U << TIM14_CCMR1OUTPUT_OC1M_SHIFT)
#define TIM14_CCMR1OUTPUT_OC1M(x)               (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1OUTPUT_OC1M_SHIFT)) & TIM14_CCMR1OUTPUT_OC1M_MASK)

#define TIM14_CCMR1OUTPUT_OC1PE_SHIFT           (3)
#define TIM14_CCMR1OUTPUT_OC1PE_MASK            (0x1U << TIM14_CCMR1OUTPUT_OC1PE_SHIFT)
#define TIM14_CCMR1OUTPUT_OC1PE(x)              (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1OUTPUT_OC1PE_SHIFT)) & TIM14_CCMR1OUTPUT_OC1PE_MASK)

#define TIM14_CCMR1OUTPUT_CC1S_SHIFT            (0)
#define TIM14_CCMR1OUTPUT_CC1S_MASK             (0x3U << TIM14_CCMR1OUTPUT_CC1S_SHIFT)
#define TIM14_CCMR1OUTPUT_CC1S(x)               (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1OUTPUT_CC1S_SHIFT)) & TIM14_CCMR1OUTPUT_CC1S_MASK)

/*!
 * @brief TIM14_CCMR1_INPUT Register Bit Definition
 */

#define TIM14_CCMR1INPUT_IC1F_SHIFT             (4)
#define TIM14_CCMR1INPUT_IC1F_MASK              (0xFU << TIM14_CCMR1INPUT_IC1F_SHIFT)
#define TIM14_CCMR1INPUT_IC1F(x)                (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1INPUT_IC1F_SHIFT)) & TIM14_CCMR1INPUT_IC1F_MASK)

#define TIM14_CCMR1INPUT_IC1PSC_SHIFT           (2)
#define TIM14_CCMR1INPUT_IC1PSC_MASK            (0x3U << TIM14_CCMR1INPUT_IC1PSC_SHIFT)
#define TIM14_CCMR1INPUT_IC1PSC(x)              (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1INPUT_IC1PSC_SHIFT)) & TIM14_CCMR1INPUT_IC1PSC_MASK)

#define TIM14_CCMR1INPUT_CC1S_SHIFT             (0)
#define TIM14_CCMR1INPUT_CC1S_MASK              (0x3U << TIM14_CCMR1INPUT_CC1S_SHIFT)
#define TIM14_CCMR1INPUT_CC1S(x)                (((uint32_t)(((uint32_t)(x)) << TIM14_CCMR1INPUT_CC1S_SHIFT)) & TIM14_CCMR1INPUT_CC1S_MASK)

/*!
 * @brief TIM14_CCER Register Bit Definition
 */

#define TIM14_CCER_CC1NP_SHIFT                  (3)
#define TIM14_CCER_CC1NP_MASK                   (0x1U << TIM14_CCER_CC1NP_SHIFT)
#define TIM14_CCER_CC1NP(x)                     (((uint32_t)(((uint32_t)(x)) << TIM14_CCER_CC1NP_SHIFT)) & TIM14_CCER_CC1NP_MASK)

#define TIM14_CCER_CC1P_SHIFT                   (1)
#define TIM14_CCER_CC1P_MASK                    (0x1U << TIM14_CCER_CC1P_SHIFT)
#define TIM14_CCER_CC1P(x)                      (((uint32_t)(((uint32_t)(x)) << TIM14_CCER_CC1P_SHIFT)) & TIM14_CCER_CC1P_MASK)

#define TIM14_CCER_CC1E_SHIFT                   (0)
#define TIM14_CCER_CC1E_MASK                    (0x1U << TIM14_CCER_CC1E_SHIFT)
#define TIM14_CCER_CC1E(x)                      (((uint32_t)(((uint32_t)(x)) << TIM14_CCER_CC1E_SHIFT)) & TIM14_CCER_CC1E_MASK)

/*!
 * @brief TIM14_CNT Register Bit Definition
 */

#define TIM14_CNT_CNT_SHIFT                     (0)
#define TIM14_CNT_CNT_MASK                      (0xFFFFU << TIM14_CNT_CNT_SHIFT)
#define TIM14_CNT_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_CNT_CNT_SHIFT)) & TIM14_CNT_CNT_MASK)

/*!
 * @brief TIM14_PSC Register Bit Definition
 */

#define TIM14_PSC_PSC_SHIFT                     (0)
#define TIM14_PSC_PSC_MASK                      (0xFFFFU << TIM14_PSC_PSC_SHIFT)
#define TIM14_PSC_PSC(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_PSC_PSC_SHIFT)) & TIM14_PSC_PSC_MASK)

/*!
 * @brief TIM14_ARR Register Bit Definition
 */

#define TIM14_ARR_ARR_SHIFT                     (0)
#define TIM14_ARR_ARR_MASK                      (0xFFFFU << TIM14_ARR_ARR_SHIFT)
#define TIM14_ARR_ARR(x)                        (((uint32_t)(((uint32_t)(x)) << TIM14_ARR_ARR_SHIFT)) & TIM14_ARR_ARR_MASK)

/*!
 * @brief TIM14_CCR1 Register Bit Definition
 */

#define TIM14_CCR1_CCR1_SHIFT                   (0)
#define TIM14_CCR1_CCR1_MASK                    (0xFFFFU << TIM14_CCR1_CCR1_SHIFT)
#define TIM14_CCR1_CCR1(x)                      (((uint32_t)(((uint32_t)(x)) << TIM14_CCR1_CCR1_SHIFT)) & TIM14_CCR1_CCR1_MASK)

/*!
 * @brief TIM14_BDTR Register Bit Definition
 */

#define TIM14_BDTR_MOE_SHIFT                    (15)
#define TIM14_BDTR_MOE_MASK                     (0x1U << TIM14_BDTR_MOE_SHIFT)
#define TIM14_BDTR_MOE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM14_BDTR_MOE_SHIFT)) & TIM14_BDTR_MOE_MASK)

/*!
 * @}
 */ /* end of group TIM14_Register_Masks */
/******************************************************************************
 *TIM14 Instance
*******************************************************************************/

#define TIM14                ((TIM14_Type*)TIM14_BASE)

/*!
 * @}
 */ /* end of group TIM14_Peripheral_Access_Layer */



/*!
 * @addtogroup TIM16_Peripheral_Access_Layer TIM16 Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM16 Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                          ///< Control Register 1                           offset: 0x00
    __IO uint32_t CR2;                                                          ///< Control Register 2                           offset: 0x04
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t DIER;                                                         ///< DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA)offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x10
    __IO uint32_t EGR;                                                          ///< Event Generation Register                    offset: 0x14
    __IO uint32_t CCMR1;                                                        ///< Capture/Compare Mode Register 1              offset: 0x18
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t CCER;                                                         ///< Capture/Compare Enable Register              offset: 0x20
    __IO uint32_t CNT;                                                          ///< Counter                                      offset: 0x24
    __IO uint32_t PSC;                                                          ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                          ///< Auto Reload Register                         offset: 0x2C
    __IO uint32_t Reserved2[1];                                                 ///< Reserved
    __IO uint32_t CCR1;                                                         ///< Capture/Compare Register 1                   offset: 0x34
    __IO uint32_t Reserved3[3];                                                 ///< Reserved
    __IO uint32_t BDTR;                                                         ///< Break And Dead-Time Register                 offset: 0x44
    __IO uint32_t Reserved4[11];                                                ///< Reserved
    __IO uint32_t BKINF;                                                        ///< Break Input Filter Register                  offset: 0x74
} TIM16_Type;

/*******************************************************************************
 * TIM16 Type
 ******************************************************************************/

/*!
 * @addtogroup TIM16_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM16_CR1 Register Bit Definition
 */

#define TIM16_CR1_CKD_SHIFT                     (8)
#define TIM16_CR1_CKD_MASK                      (0x3U << TIM16_CR1_CKD_SHIFT)
#define TIM16_CR1_CKD(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_CKD_SHIFT)) & TIM16_CR1_CKD_MASK)

#define TIM16_CR1_ARPE_SHIFT                    (7)
#define TIM16_CR1_ARPE_MASK                     (0x1U << TIM16_CR1_ARPE_SHIFT)
#define TIM16_CR1_ARPE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_ARPE_SHIFT)) & TIM16_CR1_ARPE_MASK)

#define TIM16_CR1_OPM_SHIFT                     (3)
#define TIM16_CR1_OPM_MASK                      (0x1U << TIM16_CR1_OPM_SHIFT)
#define TIM16_CR1_OPM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_OPM_SHIFT)) & TIM16_CR1_OPM_MASK)

#define TIM16_CR1_URS_SHIFT                     (2)
#define TIM16_CR1_URS_MASK                      (0x1U << TIM16_CR1_URS_SHIFT)
#define TIM16_CR1_URS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_URS_SHIFT)) & TIM16_CR1_URS_MASK)

#define TIM16_CR1_UDIS_SHIFT                    (1)
#define TIM16_CR1_UDIS_MASK                     (0x1U << TIM16_CR1_UDIS_SHIFT)
#define TIM16_CR1_UDIS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_UDIS_SHIFT)) & TIM16_CR1_UDIS_MASK)

#define TIM16_CR1_CEN_SHIFT                     (0)
#define TIM16_CR1_CEN_MASK                      (0x1U << TIM16_CR1_CEN_SHIFT)
#define TIM16_CR1_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_CR1_CEN_SHIFT)) & TIM16_CR1_CEN_MASK)

/*!
 * @brief TIM16_CR2 Register Bit Definition
 */

#define TIM16_CR2_OIS1N_SHIFT                   (9)
#define TIM16_CR2_OIS1N_MASK                    (0x1U << TIM16_CR2_OIS1N_SHIFT)
#define TIM16_CR2_OIS1N(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_CR2_OIS1N_SHIFT)) & TIM16_CR2_OIS1N_MASK)

#define TIM16_CR2_OIS1_SHIFT                    (8)
#define TIM16_CR2_OIS1_MASK                     (0x1U << TIM16_CR2_OIS1_SHIFT)
#define TIM16_CR2_OIS1(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR2_OIS1_SHIFT)) & TIM16_CR2_OIS1_MASK)

#define TIM16_CR2_CCDS_SHIFT                    (3)
#define TIM16_CR2_CCDS_MASK                     (0x1U << TIM16_CR2_CCDS_SHIFT)
#define TIM16_CR2_CCDS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR2_CCDS_SHIFT)) & TIM16_CR2_CCDS_MASK)

#define TIM16_CR2_CCUS_SHIFT                    (2)
#define TIM16_CR2_CCUS_MASK                     (0x1U << TIM16_CR2_CCUS_SHIFT)
#define TIM16_CR2_CCUS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR2_CCUS_SHIFT)) & TIM16_CR2_CCUS_MASK)

#define TIM16_CR2_CCPC_SHIFT                    (0)
#define TIM16_CR2_CCPC_MASK                     (0x1U << TIM16_CR2_CCPC_SHIFT)
#define TIM16_CR2_CCPC(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_CR2_CCPC_SHIFT)) & TIM16_CR2_CCPC_MASK)

/*!
 * @brief TIM16_DIER Register Bit Definition
 */

#define TIM16_DIER_CC1DE_SHIFT                  (9)
#define TIM16_DIER_CC1DE_MASK                   (0x1U << TIM16_DIER_CC1DE_SHIFT)
#define TIM16_DIER_CC1DE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_CC1DE_SHIFT)) & TIM16_DIER_CC1DE_MASK)

#define TIM16_DIER_UDE_SHIFT                    (8)
#define TIM16_DIER_UDE_MASK                     (0x1U << TIM16_DIER_UDE_SHIFT)
#define TIM16_DIER_UDE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_UDE_SHIFT)) & TIM16_DIER_UDE_MASK)

#define TIM16_DIER_BIE_SHIFT                    (7)
#define TIM16_DIER_BIE_MASK                     (0x1U << TIM16_DIER_BIE_SHIFT)
#define TIM16_DIER_BIE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_BIE_SHIFT)) & TIM16_DIER_BIE_MASK)

#define TIM16_DIER_COMIE_SHIFT                  (5)
#define TIM16_DIER_COMIE_MASK                   (0x1U << TIM16_DIER_COMIE_SHIFT)
#define TIM16_DIER_COMIE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_COMIE_SHIFT)) & TIM16_DIER_COMIE_MASK)

#define TIM16_DIER_CC1IE_SHIFT                  (1)
#define TIM16_DIER_CC1IE_MASK                   (0x1U << TIM16_DIER_CC1IE_SHIFT)
#define TIM16_DIER_CC1IE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_CC1IE_SHIFT)) & TIM16_DIER_CC1IE_MASK)

#define TIM16_DIER_UIE_SHIFT                    (0)
#define TIM16_DIER_UIE_MASK                     (0x1U << TIM16_DIER_UIE_SHIFT)
#define TIM16_DIER_UIE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_DIER_UIE_SHIFT)) & TIM16_DIER_UIE_MASK)

/*!
 * @brief TIM16_SR Register Bit Definition
 */

#define TIM16_SR_CC1OF_SHIFT                    (9)
#define TIM16_SR_CC1OF_MASK                     (0x1U << TIM16_SR_CC1OF_SHIFT)
#define TIM16_SR_CC1OF(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_SR_CC1OF_SHIFT)) & TIM16_SR_CC1OF_MASK)

#define TIM16_SR_BIF_SHIFT                      (7)
#define TIM16_SR_BIF_MASK                       (0x1U << TIM16_SR_BIF_SHIFT)
#define TIM16_SR_BIF(x)                         (((uint32_t)(((uint32_t)(x)) << TIM16_SR_BIF_SHIFT)) & TIM16_SR_BIF_MASK)

#define TIM16_SR_COMIF_SHIFT                    (5)
#define TIM16_SR_COMIF_MASK                     (0x1U << TIM16_SR_COMIF_SHIFT)
#define TIM16_SR_COMIF(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_SR_COMIF_SHIFT)) & TIM16_SR_COMIF_MASK)

#define TIM16_SR_CC1IF_SHIFT                    (1)
#define TIM16_SR_CC1IF_MASK                     (0x1U << TIM16_SR_CC1IF_SHIFT)
#define TIM16_SR_CC1IF(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_SR_CC1IF_SHIFT)) & TIM16_SR_CC1IF_MASK)

#define TIM16_SR_UIF_SHIFT                      (0)
#define TIM16_SR_UIF_MASK                       (0x1U << TIM16_SR_UIF_SHIFT)
#define TIM16_SR_UIF(x)                         (((uint32_t)(((uint32_t)(x)) << TIM16_SR_UIF_SHIFT)) & TIM16_SR_UIF_MASK)

/*!
 * @brief TIM16_EGR Register Bit Definition
 */

#define TIM16_EGR_BG_SHIFT                      (7)
#define TIM16_EGR_BG_MASK                       (0x1U << TIM16_EGR_BG_SHIFT)
#define TIM16_EGR_BG(x)                         (((uint32_t)(((uint32_t)(x)) << TIM16_EGR_BG_SHIFT)) & TIM16_EGR_BG_MASK)

#define TIM16_EGR_COMG_SHIFT                    (5)
#define TIM16_EGR_COMG_MASK                     (0x1U << TIM16_EGR_COMG_SHIFT)
#define TIM16_EGR_COMG(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_EGR_COMG_SHIFT)) & TIM16_EGR_COMG_MASK)

#define TIM16_EGR_CC1G_SHIFT                    (1)
#define TIM16_EGR_CC1G_MASK                     (0x1U << TIM16_EGR_CC1G_SHIFT)
#define TIM16_EGR_CC1G(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_EGR_CC1G_SHIFT)) & TIM16_EGR_CC1G_MASK)

#define TIM16_EGR_UG_SHIFT                      (0)
#define TIM16_EGR_UG_MASK                       (0x1U << TIM16_EGR_UG_SHIFT)
#define TIM16_EGR_UG(x)                         (((uint32_t)(((uint32_t)(x)) << TIM16_EGR_UG_SHIFT)) & TIM16_EGR_UG_MASK)

/*!
 * @brief TIM16_CCMR1_OUTPUT Register Bit Definition
 */

#define TIM16_CCMR1OUTPUT_OC1M_SHIFT            (4)
#define TIM16_CCMR1OUTPUT_OC1M_MASK             (0x7U << TIM16_CCMR1OUTPUT_OC1M_SHIFT)
#define TIM16_CCMR1OUTPUT_OC1M(x)               (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1OUTPUT_OC1M_SHIFT)) & TIM16_CCMR1OUTPUT_OC1M_MASK)

#define TIM16_CCMR1OUTPUT_OC1PE_SHIFT           (3)
#define TIM16_CCMR1OUTPUT_OC1PE_MASK            (0x1U << TIM16_CCMR1OUTPUT_OC1PE_SHIFT)
#define TIM16_CCMR1OUTPUT_OC1PE(x)              (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1OUTPUT_OC1PE_SHIFT)) & TIM16_CCMR1OUTPUT_OC1PE_MASK)

#define TIM16_CCMR1OUTPUT_OC1FE_SHIFT           (2)
#define TIM16_CCMR1OUTPUT_OC1FE_MASK            (0x1U << TIM16_CCMR1OUTPUT_OC1FE_SHIFT)
#define TIM16_CCMR1OUTPUT_OC1FE(x)              (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1OUTPUT_OC1FE_SHIFT)) & TIM16_CCMR1OUTPUT_OC1FE_MASK)

#define TIM16_CCMR1OUTPUT_CC1S_SHIFT            (0)
#define TIM16_CCMR1OUTPUT_CC1S_MASK             (0x3U << TIM16_CCMR1OUTPUT_CC1S_SHIFT)
#define TIM16_CCMR1OUTPUT_CC1S(x)               (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1OUTPUT_CC1S_SHIFT)) & TIM16_CCMR1OUTPUT_CC1S_MASK)

/*!
 * @brief TIM16_CCMR1_INPUT Register Bit Definition
 */

#define TIM16_CCMR1INPUT_IC1F_SHIFT             (4)
#define TIM16_CCMR1INPUT_IC1F_MASK              (0xFU << TIM16_CCMR1INPUT_IC1F_SHIFT)
#define TIM16_CCMR1INPUT_IC1F(x)                (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1INPUT_IC1F_SHIFT)) & TIM16_CCMR1INPUT_IC1F_MASK)

#define TIM16_CCMR1INPUT_IC1PSC_SHIFT           (2)
#define TIM16_CCMR1INPUT_IC1PSC_MASK            (0x3U << TIM16_CCMR1INPUT_IC1PSC_SHIFT)
#define TIM16_CCMR1INPUT_IC1PSC(x)              (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1INPUT_IC1PSC_SHIFT)) & TIM16_CCMR1INPUT_IC1PSC_MASK)

#define TIM16_CCMR1INPUT_CC1S_SHIFT             (0)
#define TIM16_CCMR1INPUT_CC1S_MASK              (0x3U << TIM16_CCMR1INPUT_CC1S_SHIFT)
#define TIM16_CCMR1INPUT_CC1S(x)                (((uint32_t)(((uint32_t)(x)) << TIM16_CCMR1INPUT_CC1S_SHIFT)) & TIM16_CCMR1INPUT_CC1S_MASK)

/*!
 * @brief TIM16_CCER Register Bit Definition
 */

#define TIM16_CCER_CC1NP_SHIFT                  (3)
#define TIM16_CCER_CC1NP_MASK                   (0x1U << TIM16_CCER_CC1NP_SHIFT)
#define TIM16_CCER_CC1NP(x)                     (((uint32_t)(((uint32_t)(x)) << TIM16_CCER_CC1NP_SHIFT)) & TIM16_CCER_CC1NP_MASK)

#define TIM16_CCER_CC1NE_SHIFT                  (2)
#define TIM16_CCER_CC1NE_MASK                   (0x1U << TIM16_CCER_CC1NE_SHIFT)
#define TIM16_CCER_CC1NE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM16_CCER_CC1NE_SHIFT)) & TIM16_CCER_CC1NE_MASK)

#define TIM16_CCER_CC1P_SHIFT                   (1)
#define TIM16_CCER_CC1P_MASK                    (0x1U << TIM16_CCER_CC1P_SHIFT)
#define TIM16_CCER_CC1P(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_CCER_CC1P_SHIFT)) & TIM16_CCER_CC1P_MASK)

#define TIM16_CCER_CC1E_SHIFT                   (0)
#define TIM16_CCER_CC1E_MASK                    (0x1U << TIM16_CCER_CC1E_SHIFT)
#define TIM16_CCER_CC1E(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_CCER_CC1E_SHIFT)) & TIM16_CCER_CC1E_MASK)

/*!
 * @brief TIM16_CNT Register Bit Definition
 */

#define TIM16_CNT_CNT_SHIFT                     (0)
#define TIM16_CNT_CNT_MASK                      (0xFFFFU << TIM16_CNT_CNT_SHIFT)
#define TIM16_CNT_CNT(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_CNT_CNT_SHIFT)) & TIM16_CNT_CNT_MASK)

/*!
 * @brief TIM16_PSC Register Bit Definition
 */

#define TIM16_PSC_PSC_SHIFT                     (0)
#define TIM16_PSC_PSC_MASK                      (0xFFFFU << TIM16_PSC_PSC_SHIFT)
#define TIM16_PSC_PSC(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_PSC_PSC_SHIFT)) & TIM16_PSC_PSC_MASK)

/*!
 * @brief TIM16_ARR Register Bit Definition
 */

#define TIM16_ARR_ARR_SHIFT                     (0)
#define TIM16_ARR_ARR_MASK                      (0xFFFFU << TIM16_ARR_ARR_SHIFT)
#define TIM16_ARR_ARR(x)                        (((uint32_t)(((uint32_t)(x)) << TIM16_ARR_ARR_SHIFT)) & TIM16_ARR_ARR_MASK)

/*!
 * @brief TIM16_CCR1 Register Bit Definition
 */

#define TIM16_CCR1_CCR1_SHIFT                   (0)
#define TIM16_CCR1_CCR1_MASK                    (0xFFFFU << TIM16_CCR1_CCR1_SHIFT)
#define TIM16_CCR1_CCR1(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_CCR1_CCR1_SHIFT)) & TIM16_CCR1_CCR1_MASK)

/*!
 * @brief TIM16_BDTR Register Bit Definition
 */

#define TIM16_BDTR_MOE_SHIFT                    (15)
#define TIM16_BDTR_MOE_MASK                     (0x1U << TIM16_BDTR_MOE_SHIFT)
#define TIM16_BDTR_MOE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_MOE_SHIFT)) & TIM16_BDTR_MOE_MASK)

#define TIM16_BDTR_AOE_SHIFT                    (14)
#define TIM16_BDTR_AOE_MASK                     (0x1U << TIM16_BDTR_AOE_SHIFT)
#define TIM16_BDTR_AOE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_AOE_SHIFT)) & TIM16_BDTR_AOE_MASK)

#define TIM16_BDTR_BKP_SHIFT                    (13)
#define TIM16_BDTR_BKP_MASK                     (0x1U << TIM16_BDTR_BKP_SHIFT)
#define TIM16_BDTR_BKP(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_BKP_SHIFT)) & TIM16_BDTR_BKP_MASK)

#define TIM16_BDTR_BKE_SHIFT                    (12)
#define TIM16_BDTR_BKE_MASK                     (0x1U << TIM16_BDTR_BKE_SHIFT)
#define TIM16_BDTR_BKE(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_BKE_SHIFT)) & TIM16_BDTR_BKE_MASK)

#define TIM16_BDTR_OSSR_SHIFT                   (11)
#define TIM16_BDTR_OSSR_MASK                    (0x1U << TIM16_BDTR_OSSR_SHIFT)
#define TIM16_BDTR_OSSR(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_OSSR_SHIFT)) & TIM16_BDTR_OSSR_MASK)

#define TIM16_BDTR_OSSI_SHIFT                   (10)
#define TIM16_BDTR_OSSI_MASK                    (0x1U << TIM16_BDTR_OSSI_SHIFT)
#define TIM16_BDTR_OSSI(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_OSSI_SHIFT)) & TIM16_BDTR_OSSI_MASK)

#define TIM16_BDTR_LOCK_SHIFT                   (8)
#define TIM16_BDTR_LOCK_MASK                    (0x3U << TIM16_BDTR_LOCK_SHIFT)
#define TIM16_BDTR_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_LOCK_SHIFT)) & TIM16_BDTR_LOCK_MASK)

#define TIM16_BDTR_DTG_SHIFT                    (0)
#define TIM16_BDTR_DTG_MASK                     (0xFFU << TIM16_BDTR_DTG_SHIFT)
#define TIM16_BDTR_DTG(x)                       (((uint32_t)(((uint32_t)(x)) << TIM16_BDTR_DTG_SHIFT)) & TIM16_BDTR_DTG_MASK)

/*!
 * @brief TIM16_BKINF Register Bit Definition
 */

#define TIM16_BKINF_BKINSEL_SHIFT               (5)
#define TIM16_BKINF_BKINSEL_MASK                (0xFFFU << TIM16_BKINF_BKINSEL_SHIFT)
#define TIM16_BKINF_BKINSEL(x)                  (((uint32_t)(((uint32_t)(x)) << TIM16_BKINF_BKINSEL_SHIFT)) & TIM16_BKINF_BKINSEL_MASK)

#define TIM16_BKINF_BKINF_SHIFT                 (1)
#define TIM16_BKINF_BKINF_MASK                  (0xFU << TIM16_BKINF_BKINF_SHIFT)
#define TIM16_BKINF_BKINF(x)                    (((uint32_t)(((uint32_t)(x)) << TIM16_BKINF_BKINF_SHIFT)) & TIM16_BKINF_BKINF_MASK)

#define TIM16_BKINF_BKINFE_SHIFT                (0)
#define TIM16_BKINF_BKINFE_MASK                 (0x1U << TIM16_BKINF_BKINFE_SHIFT)
#define TIM16_BKINF_BKINFE(x)                   (((uint32_t)(((uint32_t)(x)) << TIM16_BKINF_BKINFE_SHIFT)) & TIM16_BKINF_BKINFE_MASK)

/*!
 * @}
 */ /* end of group TIM16_Register_Masks */
/******************************************************************************
 *TIM16 Instance
*******************************************************************************/

#define TIM16                ((TIM16_Type*)TIM16_BASE)

#define TIM17                ((TIM16_Type*)TIM17_BASE)

/*!
 * @}
 */ /* end of group TIM16_Peripheral_Access_Layer */



/*!
 * @addtogroup TIM2_Peripheral_Access_Layer TIM2 Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM2 Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                          ///< Control Register 1                           offset: 0x00
    __IO uint32_t CR2;                                                          ///< Control Register 2                           offset: 0x04
    __IO uint32_t SMCR;                                                         ///< Slave Mode Control Register                  offset: 0x08
    __IO uint32_t DIER;                                                         ///< DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA)offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x10
    __IO uint32_t EGR;                                                          ///< Event Generation Register                    offset: 0x14
    __IO uint32_t CCMR1;                                                        ///< Capture/Compare Mode Register 1              offset: 0x18
    __IO uint32_t CCMR2;                                                        ///< Capture/Compare Mode Register 2              offset: 0x1C
    __IO uint32_t CCER;                                                         ///< Capture/Compare Enable Register              offset: 0x20
    __IO uint32_t CNT;                                                          ///< Counter                                      offset: 0x24
    __IO uint32_t PSC;                                                          ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                          ///< Auto Reload Register                         offset: 0x2C
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t CCR1;                                                         ///< Capture/Compare Register 1                   offset: 0x34
    __IO uint32_t CCR2;                                                         ///< Capture/Compare Register 2                   offset: 0x38
    __IO uint32_t CCR3;                                                         ///< Capture/Compare Register 3                   offset: 0x3C
    __IO uint32_t CCR4;                                                         ///< Capture/Compare Register 4                   offset: 0x40
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t DCR;                                                          ///< DMA Control Register (only suitable for the chip with built in DMA)offset: 0x48
    __IO uint32_t DMAR;                                                         ///< DMA Address Register Of Continuous Mode (only suitable for the chip with built in DMA)offset: 0x4C
    __IO uint32_t OR;                                                           ///< Input Option Register                        offset: 0x50
} TIM2_Type;

/*******************************************************************************
 * TIM2 Type
 ******************************************************************************/

/*!
 * @addtogroup TIM2_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM2_CR1 Register Bit Definition
 */

#define TIM2_CR1_CKD_SHIFT                      (8)
#define TIM2_CR1_CKD_MASK                       (0x3U << TIM2_CR1_CKD_SHIFT)
#define TIM2_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_CKD_SHIFT)) & TIM2_CR1_CKD_MASK)

#define TIM2_CR1_ARPE_SHIFT                     (7)
#define TIM2_CR1_ARPE_MASK                      (0x1U << TIM2_CR1_ARPE_SHIFT)
#define TIM2_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_ARPE_SHIFT)) & TIM2_CR1_ARPE_MASK)

#define TIM2_CR1_CMS_SHIFT                      (5)
#define TIM2_CR1_CMS_MASK                       (0x3U << TIM2_CR1_CMS_SHIFT)
#define TIM2_CR1_CMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_CMS_SHIFT)) & TIM2_CR1_CMS_MASK)

#define TIM2_CR1_DIR_SHIFT                      (4)
#define TIM2_CR1_DIR_MASK                       (0x1U << TIM2_CR1_DIR_SHIFT)
#define TIM2_CR1_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_DIR_SHIFT)) & TIM2_CR1_DIR_MASK)

#define TIM2_CR1_OPM_SHIFT                      (3)
#define TIM2_CR1_OPM_MASK                       (0x1U << TIM2_CR1_OPM_SHIFT)
#define TIM2_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_OPM_SHIFT)) & TIM2_CR1_OPM_MASK)

#define TIM2_CR1_URS_SHIFT                      (2)
#define TIM2_CR1_URS_MASK                       (0x1U << TIM2_CR1_URS_SHIFT)
#define TIM2_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_URS_SHIFT)) & TIM2_CR1_URS_MASK)

#define TIM2_CR1_UDIS_SHIFT                     (1)
#define TIM2_CR1_UDIS_MASK                      (0x1U << TIM2_CR1_UDIS_SHIFT)
#define TIM2_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_UDIS_SHIFT)) & TIM2_CR1_UDIS_MASK)

#define TIM2_CR1_CEN_SHIFT                      (0)
#define TIM2_CR1_CEN_MASK                       (0x1U << TIM2_CR1_CEN_SHIFT)
#define TIM2_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR1_CEN_SHIFT)) & TIM2_CR1_CEN_MASK)

/*!
 * @brief TIM2_CR2 Register Bit Definition
 */

#define TIM2_CR2_TI1S_SHIFT                     (7)
#define TIM2_CR2_TI1S_MASK                      (0x1U << TIM2_CR2_TI1S_SHIFT)
#define TIM2_CR2_TI1S(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_CR2_TI1S_SHIFT)) & TIM2_CR2_TI1S_MASK)

#define TIM2_CR2_MMS_SHIFT                      (4)
#define TIM2_CR2_MMS_MASK                       (0x7U << TIM2_CR2_MMS_SHIFT)
#define TIM2_CR2_MMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CR2_MMS_SHIFT)) & TIM2_CR2_MMS_MASK)

#define TIM2_CR2_CCDS_SHIFT                     (3)
#define TIM2_CR2_CCDS_MASK                      (0x1U << TIM2_CR2_CCDS_SHIFT)
#define TIM2_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_CR2_CCDS_SHIFT)) & TIM2_CR2_CCDS_MASK)

/*!
 * @brief TIM2_SMCR Register Bit Definition
 */

#define TIM2_SMCR_ETP_SHIFT                     (15)
#define TIM2_SMCR_ETP_MASK                      (0x1U << TIM2_SMCR_ETP_SHIFT)
#define TIM2_SMCR_ETP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_ETP_SHIFT)) & TIM2_SMCR_ETP_MASK)

#define TIM2_SMCR_ECE_SHIFT                     (14)
#define TIM2_SMCR_ECE_MASK                      (0x1U << TIM2_SMCR_ECE_SHIFT)
#define TIM2_SMCR_ECE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_ECE_SHIFT)) & TIM2_SMCR_ECE_MASK)

#define TIM2_SMCR_ETPS_SHIFT                    (12)
#define TIM2_SMCR_ETPS_MASK                     (0x3U << TIM2_SMCR_ETPS_SHIFT)
#define TIM2_SMCR_ETPS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_ETPS_SHIFT)) & TIM2_SMCR_ETPS_MASK)

#define TIM2_SMCR_ETF_SHIFT                     (8)
#define TIM2_SMCR_ETF_MASK                      (0xFU << TIM2_SMCR_ETF_SHIFT)
#define TIM2_SMCR_ETF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_ETF_SHIFT)) & TIM2_SMCR_ETF_MASK)

#define TIM2_SMCR_MSM_SHIFT                     (7)
#define TIM2_SMCR_MSM_MASK                      (0x1U << TIM2_SMCR_MSM_SHIFT)
#define TIM2_SMCR_MSM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_MSM_SHIFT)) & TIM2_SMCR_MSM_MASK)

#define TIM2_SMCR_TS_SHIFT                      (4)
#define TIM2_SMCR_TS_MASK                       (0x7U << TIM2_SMCR_TS_SHIFT)
#define TIM2_SMCR_TS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_TS_SHIFT)) & TIM2_SMCR_TS_MASK)

#define TIM2_SMCR_OCCS_SHIFT                    (3)
#define TIM2_SMCR_OCCS_MASK                     (0x1U << TIM2_SMCR_OCCS_SHIFT)
#define TIM2_SMCR_OCCS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_OCCS_SHIFT)) & TIM2_SMCR_OCCS_MASK)

#define TIM2_SMCR_SMS_SHIFT                     (0)
#define TIM2_SMCR_SMS_MASK                      (0x7U << TIM2_SMCR_SMS_SHIFT)
#define TIM2_SMCR_SMS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SMCR_SMS_SHIFT)) & TIM2_SMCR_SMS_MASK)

/*!
 * @brief TIM2_DIER Register Bit Definition
 */

#define TIM2_DIER_TDE_SHIFT                     (14)
#define TIM2_DIER_TDE_MASK                      (0x1U << TIM2_DIER_TDE_SHIFT)
#define TIM2_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_TDE_SHIFT)) & TIM2_DIER_TDE_MASK)

#define TIM2_DIER_CC4DE_SHIFT                   (12)
#define TIM2_DIER_CC4DE_MASK                    (0x1U << TIM2_DIER_CC4DE_SHIFT)
#define TIM2_DIER_CC4DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC4DE_SHIFT)) & TIM2_DIER_CC4DE_MASK)

#define TIM2_DIER_CC3DE_SHIFT                   (11)
#define TIM2_DIER_CC3DE_MASK                    (0x1U << TIM2_DIER_CC3DE_SHIFT)
#define TIM2_DIER_CC3DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC3DE_SHIFT)) & TIM2_DIER_CC3DE_MASK)

#define TIM2_DIER_CC2DE_SHIFT                   (10)
#define TIM2_DIER_CC2DE_MASK                    (0x1U << TIM2_DIER_CC2DE_SHIFT)
#define TIM2_DIER_CC2DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC2DE_SHIFT)) & TIM2_DIER_CC2DE_MASK)

#define TIM2_DIER_CC1DE_SHIFT                   (9)
#define TIM2_DIER_CC1DE_MASK                    (0x1U << TIM2_DIER_CC1DE_SHIFT)
#define TIM2_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC1DE_SHIFT)) & TIM2_DIER_CC1DE_MASK)

#define TIM2_DIER_UDE_SHIFT                     (8)
#define TIM2_DIER_UDE_MASK                      (0x1U << TIM2_DIER_UDE_SHIFT)
#define TIM2_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_UDE_SHIFT)) & TIM2_DIER_UDE_MASK)

#define TIM2_DIER_TIE_SHIFT                     (6)
#define TIM2_DIER_TIE_MASK                      (0x1U << TIM2_DIER_TIE_SHIFT)
#define TIM2_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_TIE_SHIFT)) & TIM2_DIER_TIE_MASK)

#define TIM2_DIER_CC4IE_SHIFT                   (4)
#define TIM2_DIER_CC4IE_MASK                    (0x1U << TIM2_DIER_CC4IE_SHIFT)
#define TIM2_DIER_CC4IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC4IE_SHIFT)) & TIM2_DIER_CC4IE_MASK)

#define TIM2_DIER_CC3IE_SHIFT                   (3)
#define TIM2_DIER_CC3IE_MASK                    (0x1U << TIM2_DIER_CC3IE_SHIFT)
#define TIM2_DIER_CC3IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC3IE_SHIFT)) & TIM2_DIER_CC3IE_MASK)

#define TIM2_DIER_CC2IE_SHIFT                   (2)
#define TIM2_DIER_CC2IE_MASK                    (0x1U << TIM2_DIER_CC2IE_SHIFT)
#define TIM2_DIER_CC2IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC2IE_SHIFT)) & TIM2_DIER_CC2IE_MASK)

#define TIM2_DIER_CC1IE_SHIFT                   (1)
#define TIM2_DIER_CC1IE_MASK                    (0x1U << TIM2_DIER_CC1IE_SHIFT)
#define TIM2_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_CC1IE_SHIFT)) & TIM2_DIER_CC1IE_MASK)

#define TIM2_DIER_UIE_SHIFT                     (0)
#define TIM2_DIER_UIE_MASK                      (0x1U << TIM2_DIER_UIE_SHIFT)
#define TIM2_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_DIER_UIE_SHIFT)) & TIM2_DIER_UIE_MASK)

/*!
 * @brief TIM2_SR Register Bit Definition
 */

#define TIM2_SR_CC4OF_SHIFT                     (12)
#define TIM2_SR_CC4OF_MASK                      (0x1U << TIM2_SR_CC4OF_SHIFT)
#define TIM2_SR_CC4OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC4OF_SHIFT)) & TIM2_SR_CC4OF_MASK)

#define TIM2_SR_CC3OF_SHIFT                     (11)
#define TIM2_SR_CC3OF_MASK                      (0x1U << TIM2_SR_CC3OF_SHIFT)
#define TIM2_SR_CC3OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC3OF_SHIFT)) & TIM2_SR_CC3OF_MASK)

#define TIM2_SR_CC2OF_SHIFT                     (10)
#define TIM2_SR_CC2OF_MASK                      (0x1U << TIM2_SR_CC2OF_SHIFT)
#define TIM2_SR_CC2OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC2OF_SHIFT)) & TIM2_SR_CC2OF_MASK)

#define TIM2_SR_CC1OF_SHIFT                     (9)
#define TIM2_SR_CC1OF_MASK                      (0x1U << TIM2_SR_CC1OF_SHIFT)
#define TIM2_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC1OF_SHIFT)) & TIM2_SR_CC1OF_MASK)

#define TIM2_SR_TIF_SHIFT                       (6)
#define TIM2_SR_TIF_MASK                        (0x1U << TIM2_SR_TIF_SHIFT)
#define TIM2_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM2_SR_TIF_SHIFT)) & TIM2_SR_TIF_MASK)

#define TIM2_SR_CC4IF_SHIFT                     (4)
#define TIM2_SR_CC4IF_MASK                      (0x1U << TIM2_SR_CC4IF_SHIFT)
#define TIM2_SR_CC4IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC4IF_SHIFT)) & TIM2_SR_CC4IF_MASK)

#define TIM2_SR_CC3IF_SHIFT                     (3)
#define TIM2_SR_CC3IF_MASK                      (0x1U << TIM2_SR_CC3IF_SHIFT)
#define TIM2_SR_CC3IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC3IF_SHIFT)) & TIM2_SR_CC3IF_MASK)

#define TIM2_SR_CC2IF_SHIFT                     (2)
#define TIM2_SR_CC2IF_MASK                      (0x1U << TIM2_SR_CC2IF_SHIFT)
#define TIM2_SR_CC2IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC2IF_SHIFT)) & TIM2_SR_CC2IF_MASK)

#define TIM2_SR_CC1IF_SHIFT                     (1)
#define TIM2_SR_CC1IF_MASK                      (0x1U << TIM2_SR_CC1IF_SHIFT)
#define TIM2_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_SR_CC1IF_SHIFT)) & TIM2_SR_CC1IF_MASK)

#define TIM2_SR_UIF_SHIFT                       (0)
#define TIM2_SR_UIF_MASK                        (0x1U << TIM2_SR_UIF_SHIFT)
#define TIM2_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM2_SR_UIF_SHIFT)) & TIM2_SR_UIF_MASK)

/*!
 * @brief TIM2_EGR Register Bit Definition
 */

#define TIM2_EGR_TG_SHIFT                       (6)
#define TIM2_EGR_TG_MASK                        (0x1U << TIM2_EGR_TG_SHIFT)
#define TIM2_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_TG_SHIFT)) & TIM2_EGR_TG_MASK)

#define TIM2_EGR_CC4G_SHIFT                     (4)
#define TIM2_EGR_CC4G_MASK                      (0x1U << TIM2_EGR_CC4G_SHIFT)
#define TIM2_EGR_CC4G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_CC4G_SHIFT)) & TIM2_EGR_CC4G_MASK)

#define TIM2_EGR_CC3G_SHIFT                     (3)
#define TIM2_EGR_CC3G_MASK                      (0x1U << TIM2_EGR_CC3G_SHIFT)
#define TIM2_EGR_CC3G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_CC3G_SHIFT)) & TIM2_EGR_CC3G_MASK)

#define TIM2_EGR_CC2G_SHIFT                     (2)
#define TIM2_EGR_CC2G_MASK                      (0x1U << TIM2_EGR_CC2G_SHIFT)
#define TIM2_EGR_CC2G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_CC2G_SHIFT)) & TIM2_EGR_CC2G_MASK)

#define TIM2_EGR_CC1G_SHIFT                     (1)
#define TIM2_EGR_CC1G_MASK                      (0x1U << TIM2_EGR_CC1G_SHIFT)
#define TIM2_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_CC1G_SHIFT)) & TIM2_EGR_CC1G_MASK)

#define TIM2_EGR_UG_SHIFT                       (0)
#define TIM2_EGR_UG_MASK                        (0x1U << TIM2_EGR_UG_SHIFT)
#define TIM2_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM2_EGR_UG_SHIFT)) & TIM2_EGR_UG_MASK)

/*!
 * @brief TIM2_CCMR1_OUTPUT Register Bit Definition
 */

#define TIM2_CCMR1OUTPUT_OC2CE_SHIFT            (15)
#define TIM2_CCMR1OUTPUT_OC2CE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC2CE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC2CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC2CE_SHIFT)) & TIM2_CCMR1OUTPUT_OC2CE_MASK)

#define TIM2_CCMR1OUTPUT_OC2M_SHIFT             (12)
#define TIM2_CCMR1OUTPUT_OC2M_MASK              (0x7U << TIM2_CCMR1OUTPUT_OC2M_SHIFT)
#define TIM2_CCMR1OUTPUT_OC2M(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC2M_SHIFT)) & TIM2_CCMR1OUTPUT_OC2M_MASK)

#define TIM2_CCMR1OUTPUT_OC2PE_SHIFT            (11)
#define TIM2_CCMR1OUTPUT_OC2PE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC2PE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC2PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC2PE_SHIFT)) & TIM2_CCMR1OUTPUT_OC2PE_MASK)

#define TIM2_CCMR1OUTPUT_OC2FE_SHIFT            (10)
#define TIM2_CCMR1OUTPUT_OC2FE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC2FE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC2FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC2FE_SHIFT)) & TIM2_CCMR1OUTPUT_OC2FE_MASK)

#define TIM2_CCMR1OUTPUT_CC2S_SHIFT             (8)
#define TIM2_CCMR1OUTPUT_CC2S_MASK              (0x3U << TIM2_CCMR1OUTPUT_CC2S_SHIFT)
#define TIM2_CCMR1OUTPUT_CC2S(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_CC2S_SHIFT)) & TIM2_CCMR1OUTPUT_CC2S_MASK)

#define TIM2_CCMR1OUTPUT_OC1CE_SHIFT            (7)
#define TIM2_CCMR1OUTPUT_OC1CE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC1CE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC1CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC1CE_SHIFT)) & TIM2_CCMR1OUTPUT_OC1CE_MASK)

#define TIM2_CCMR1OUTPUT_OC1M_SHIFT             (4)
#define TIM2_CCMR1OUTPUT_OC1M_MASK              (0x7U << TIM2_CCMR1OUTPUT_OC1M_SHIFT)
#define TIM2_CCMR1OUTPUT_OC1M(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC1M_SHIFT)) & TIM2_CCMR1OUTPUT_OC1M_MASK)

#define TIM2_CCMR1OUTPUT_OC1PE_SHIFT            (3)
#define TIM2_CCMR1OUTPUT_OC1PE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC1PE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC1PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC1PE_SHIFT)) & TIM2_CCMR1OUTPUT_OC1PE_MASK)

#define TIM2_CCMR1OUTPUT_OC1FE_SHIFT            (2)
#define TIM2_CCMR1OUTPUT_OC1FE_MASK             (0x1U << TIM2_CCMR1OUTPUT_OC1FE_SHIFT)
#define TIM2_CCMR1OUTPUT_OC1FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_OC1FE_SHIFT)) & TIM2_CCMR1OUTPUT_OC1FE_MASK)

#define TIM2_CCMR1OUTPUT_CC1S_SHIFT             (0)
#define TIM2_CCMR1OUTPUT_CC1S_MASK              (0x3U << TIM2_CCMR1OUTPUT_CC1S_SHIFT)
#define TIM2_CCMR1OUTPUT_CC1S(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1OUTPUT_CC1S_SHIFT)) & TIM2_CCMR1OUTPUT_CC1S_MASK)

/*!
 * @brief TIM2_CCMR1_INPUT Register Bit Definition
 */

#define TIM2_CCMR1INPUT_IC2F_SHIFT              (12)
#define TIM2_CCMR1INPUT_IC2F_MASK               (0xFU << TIM2_CCMR1INPUT_IC2F_SHIFT)
#define TIM2_CCMR1INPUT_IC2F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_IC2F_SHIFT)) & TIM2_CCMR1INPUT_IC2F_MASK)

#define TIM2_CCMR1INPUT_IC2PSC_SHIFT            (10)
#define TIM2_CCMR1INPUT_IC2PSC_MASK             (0x3U << TIM2_CCMR1INPUT_IC2PSC_SHIFT)
#define TIM2_CCMR1INPUT_IC2PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_IC2PSC_SHIFT)) & TIM2_CCMR1INPUT_IC2PSC_MASK)

#define TIM2_CCMR1INPUT_CC2S_SHIFT              (8)
#define TIM2_CCMR1INPUT_CC2S_MASK               (0x3U << TIM2_CCMR1INPUT_CC2S_SHIFT)
#define TIM2_CCMR1INPUT_CC2S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_CC2S_SHIFT)) & TIM2_CCMR1INPUT_CC2S_MASK)

#define TIM2_CCMR1INPUT_IC1F_SHIFT              (4)
#define TIM2_CCMR1INPUT_IC1F_MASK               (0xFU << TIM2_CCMR1INPUT_IC1F_SHIFT)
#define TIM2_CCMR1INPUT_IC1F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_IC1F_SHIFT)) & TIM2_CCMR1INPUT_IC1F_MASK)

#define TIM2_CCMR1INPUT_IC1PSC_SHIFT            (2)
#define TIM2_CCMR1INPUT_IC1PSC_MASK             (0x3U << TIM2_CCMR1INPUT_IC1PSC_SHIFT)
#define TIM2_CCMR1INPUT_IC1PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_IC1PSC_SHIFT)) & TIM2_CCMR1INPUT_IC1PSC_MASK)

#define TIM2_CCMR1INPUT_CC1S_SHIFT              (0)
#define TIM2_CCMR1INPUT_CC1S_MASK               (0x3U << TIM2_CCMR1INPUT_CC1S_SHIFT)
#define TIM2_CCMR1INPUT_CC1S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR1INPUT_CC1S_SHIFT)) & TIM2_CCMR1INPUT_CC1S_MASK)

/*!
 * @brief TIM2_CCMR2_OUTPUT Register Bit Definition
 */

#define TIM2_CCMR2OUTPUT_OC4CE_SHIFT            (15)
#define TIM2_CCMR2OUTPUT_OC4CE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC4CE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC4CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC4CE_SHIFT)) & TIM2_CCMR2OUTPUT_OC4CE_MASK)

#define TIM2_CCMR2OUTPUT_OC4M_SHIFT             (12)
#define TIM2_CCMR2OUTPUT_OC4M_MASK              (0x7U << TIM2_CCMR2OUTPUT_OC4M_SHIFT)
#define TIM2_CCMR2OUTPUT_OC4M(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC4M_SHIFT)) & TIM2_CCMR2OUTPUT_OC4M_MASK)

#define TIM2_CCMR2OUTPUT_OC4PE_SHIFT            (11)
#define TIM2_CCMR2OUTPUT_OC4PE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC4PE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC4PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC4PE_SHIFT)) & TIM2_CCMR2OUTPUT_OC4PE_MASK)

#define TIM2_CCMR2OUTPUT_OC4FE_SHIFT            (10)
#define TIM2_CCMR2OUTPUT_OC4FE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC4FE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC4FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC4FE_SHIFT)) & TIM2_CCMR2OUTPUT_OC4FE_MASK)

#define TIM2_CCMR2OUTPUT_CC4S_SHIFT             (8)
#define TIM2_CCMR2OUTPUT_CC4S_MASK              (0x3U << TIM2_CCMR2OUTPUT_CC4S_SHIFT)
#define TIM2_CCMR2OUTPUT_CC4S(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_CC4S_SHIFT)) & TIM2_CCMR2OUTPUT_CC4S_MASK)

#define TIM2_CCMR2OUTPUT_OC3CE_SHIFT            (7)
#define TIM2_CCMR2OUTPUT_OC3CE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC3CE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC3CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC3CE_SHIFT)) & TIM2_CCMR2OUTPUT_OC3CE_MASK)

#define TIM2_CCMR2OUTPUT_OC3M_SHIFT             (4)
#define TIM2_CCMR2OUTPUT_OC3M_MASK              (0x7U << TIM2_CCMR2OUTPUT_OC3M_SHIFT)
#define TIM2_CCMR2OUTPUT_OC3M(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC3M_SHIFT)) & TIM2_CCMR2OUTPUT_OC3M_MASK)

#define TIM2_CCMR2OUTPUT_OC3PE_SHIFT            (3)
#define TIM2_CCMR2OUTPUT_OC3PE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC3PE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC3PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC3PE_SHIFT)) & TIM2_CCMR2OUTPUT_OC3PE_MASK)

#define TIM2_CCMR2OUTPUT_OC3FE_SHIFT            (2)
#define TIM2_CCMR2OUTPUT_OC3FE_MASK             (0x1U << TIM2_CCMR2OUTPUT_OC3FE_SHIFT)
#define TIM2_CCMR2OUTPUT_OC3FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_OC3FE_SHIFT)) & TIM2_CCMR2OUTPUT_OC3FE_MASK)

#define TIM2_CCMR2OUTPUT_CC3S_SHIFT             (0)
#define TIM2_CCMR2OUTPUT_CC3S_MASK              (0x3U << TIM2_CCMR2OUTPUT_CC3S_SHIFT)
#define TIM2_CCMR2OUTPUT_CC3S(x)                (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2OUTPUT_CC3S_SHIFT)) & TIM2_CCMR2OUTPUT_CC3S_MASK)

/*!
 * @brief TIM2_CCMR2_INPUT Register Bit Definition
 */

#define TIM2_CCMR2INPUT_IC4F_SHIFT              (12)
#define TIM2_CCMR2INPUT_IC4F_MASK               (0xFU << TIM2_CCMR2INPUT_IC4F_SHIFT)
#define TIM2_CCMR2INPUT_IC4F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_IC4F_SHIFT)) & TIM2_CCMR2INPUT_IC4F_MASK)

#define TIM2_CCMR2INPUT_IC4PSC_SHIFT            (10)
#define TIM2_CCMR2INPUT_IC4PSC_MASK             (0x3U << TIM2_CCMR2INPUT_IC4PSC_SHIFT)
#define TIM2_CCMR2INPUT_IC4PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_IC4PSC_SHIFT)) & TIM2_CCMR2INPUT_IC4PSC_MASK)

#define TIM2_CCMR2INPUT_CC4S_SHIFT              (8)
#define TIM2_CCMR2INPUT_CC4S_MASK               (0x3U << TIM2_CCMR2INPUT_CC4S_SHIFT)
#define TIM2_CCMR2INPUT_CC4S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_CC4S_SHIFT)) & TIM2_CCMR2INPUT_CC4S_MASK)

#define TIM2_CCMR2INPUT_IC3F_SHIFT              (4)
#define TIM2_CCMR2INPUT_IC3F_MASK               (0xFU << TIM2_CCMR2INPUT_IC3F_SHIFT)
#define TIM2_CCMR2INPUT_IC3F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_IC3F_SHIFT)) & TIM2_CCMR2INPUT_IC3F_MASK)

#define TIM2_CCMR2INPUT_IC3PSC_SHIFT            (2)
#define TIM2_CCMR2INPUT_IC3PSC_MASK             (0x3U << TIM2_CCMR2INPUT_IC3PSC_SHIFT)
#define TIM2_CCMR2INPUT_IC3PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_IC3PSC_SHIFT)) & TIM2_CCMR2INPUT_IC3PSC_MASK)

#define TIM2_CCMR2INPUT_CC3S_SHIFT              (0)
#define TIM2_CCMR2INPUT_CC3S_MASK               (0x3U << TIM2_CCMR2INPUT_CC3S_SHIFT)
#define TIM2_CCMR2INPUT_CC3S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM2_CCMR2INPUT_CC3S_SHIFT)) & TIM2_CCMR2INPUT_CC3S_MASK)

/*!
 * @brief TIM2_CCER Register Bit Definition
 */

#define TIM2_CCER_CC4NP_SHIFT                   (15)
#define TIM2_CCER_CC4NP_MASK                    (0x1U << TIM2_CCER_CC4NP_SHIFT)
#define TIM2_CCER_CC4NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC4NP_SHIFT)) & TIM2_CCER_CC4NP_MASK)

#define TIM2_CCER_CC4P_SHIFT                    (13)
#define TIM2_CCER_CC4P_MASK                     (0x1U << TIM2_CCER_CC4P_SHIFT)
#define TIM2_CCER_CC4P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC4P_SHIFT)) & TIM2_CCER_CC4P_MASK)

#define TIM2_CCER_CC4E_SHIFT                    (12)
#define TIM2_CCER_CC4E_MASK                     (0x1U << TIM2_CCER_CC4E_SHIFT)
#define TIM2_CCER_CC4E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC4E_SHIFT)) & TIM2_CCER_CC4E_MASK)

#define TIM2_CCER_CC3NP_SHIFT                   (11)
#define TIM2_CCER_CC3NP_MASK                    (0x1U << TIM2_CCER_CC3NP_SHIFT)
#define TIM2_CCER_CC3NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC3NP_SHIFT)) & TIM2_CCER_CC3NP_MASK)

#define TIM2_CCER_CC3P_SHIFT                    (9)
#define TIM2_CCER_CC3P_MASK                     (0x1U << TIM2_CCER_CC3P_SHIFT)
#define TIM2_CCER_CC3P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC3P_SHIFT)) & TIM2_CCER_CC3P_MASK)

#define TIM2_CCER_CC3E_SHIFT                    (8)
#define TIM2_CCER_CC3E_MASK                     (0x1U << TIM2_CCER_CC3E_SHIFT)
#define TIM2_CCER_CC3E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC3E_SHIFT)) & TIM2_CCER_CC3E_MASK)

#define TIM2_CCER_CC2NP_SHIFT                   (7)
#define TIM2_CCER_CC2NP_MASK                    (0x1U << TIM2_CCER_CC2NP_SHIFT)
#define TIM2_CCER_CC2NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC2NP_SHIFT)) & TIM2_CCER_CC2NP_MASK)

#define TIM2_CCER_CC2P_SHIFT                    (5)
#define TIM2_CCER_CC2P_MASK                     (0x1U << TIM2_CCER_CC2P_SHIFT)
#define TIM2_CCER_CC2P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC2P_SHIFT)) & TIM2_CCER_CC2P_MASK)

#define TIM2_CCER_CC2E_SHIFT                    (4)
#define TIM2_CCER_CC2E_MASK                     (0x1U << TIM2_CCER_CC2E_SHIFT)
#define TIM2_CCER_CC2E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC2E_SHIFT)) & TIM2_CCER_CC2E_MASK)

#define TIM2_CCER_CC1NP_SHIFT                   (3)
#define TIM2_CCER_CC1NP_MASK                    (0x1U << TIM2_CCER_CC1NP_SHIFT)
#define TIM2_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC1NP_SHIFT)) & TIM2_CCER_CC1NP_MASK)

#define TIM2_CCER_CC1P_SHIFT                    (1)
#define TIM2_CCER_CC1P_MASK                     (0x1U << TIM2_CCER_CC1P_SHIFT)
#define TIM2_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC1P_SHIFT)) & TIM2_CCER_CC1P_MASK)

#define TIM2_CCER_CC1E_SHIFT                    (0)
#define TIM2_CCER_CC1E_MASK                     (0x1U << TIM2_CCER_CC1E_SHIFT)
#define TIM2_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCER_CC1E_SHIFT)) & TIM2_CCER_CC1E_MASK)

/*!
 * @brief TIM2_CNT Register Bit Definition
 */

#define TIM2_CNT_CNT_SHIFT                      (0)
#define TIM2_CNT_CNT_MASK                       (0xFFFFFFFFU << TIM2_CNT_CNT_SHIFT)
#define TIM2_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_CNT_CNT_SHIFT)) & TIM2_CNT_CNT_MASK)

/*!
 * @brief TIM2_PSC Register Bit Definition
 */

#define TIM2_PSC_PSC_SHIFT                      (0)
#define TIM2_PSC_PSC_MASK                       (0xFFFFU << TIM2_PSC_PSC_SHIFT)
#define TIM2_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_PSC_PSC_SHIFT)) & TIM2_PSC_PSC_MASK)

/*!
 * @brief TIM2_ARR Register Bit Definition
 */

#define TIM2_ARR_ARR_SHIFT                      (0)
#define TIM2_ARR_ARR_MASK                       (0xFFFFFFFFU << TIM2_ARR_ARR_SHIFT)
#define TIM2_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_ARR_ARR_SHIFT)) & TIM2_ARR_ARR_MASK)

/*!
 * @brief TIM2_CCR1 Register Bit Definition
 */

#define TIM2_CCR1_CCR1_SHIFT                    (0)
#define TIM2_CCR1_CCR1_MASK                     (0xFFFFFFFFU << TIM2_CCR1_CCR1_SHIFT)
#define TIM2_CCR1_CCR1(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCR1_CCR1_SHIFT)) & TIM2_CCR1_CCR1_MASK)

/*!
 * @brief TIM2_CCR2 Register Bit Definition
 */

#define TIM2_CCR2_CCR2_SHIFT                    (0)
#define TIM2_CCR2_CCR2_MASK                     (0xFFFFFFFFU << TIM2_CCR2_CCR2_SHIFT)
#define TIM2_CCR2_CCR2(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCR2_CCR2_SHIFT)) & TIM2_CCR2_CCR2_MASK)

/*!
 * @brief TIM2_CCR3 Register Bit Definition
 */

#define TIM2_CCR3_CCR3_SHIFT                    (0)
#define TIM2_CCR3_CCR3_MASK                     (0xFFFFFFFFU << TIM2_CCR3_CCR3_SHIFT)
#define TIM2_CCR3_CCR3(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCR3_CCR3_SHIFT)) & TIM2_CCR3_CCR3_MASK)

/*!
 * @brief TIM2_CCR4 Register Bit Definition
 */

#define TIM2_CCR4_CCR4_SHIFT                    (0)
#define TIM2_CCR4_CCR4_MASK                     (0xFFFFFFFFU << TIM2_CCR4_CCR4_SHIFT)
#define TIM2_CCR4_CCR4(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_CCR4_CCR4_SHIFT)) & TIM2_CCR4_CCR4_MASK)

/*!
 * @brief TIM2_DCR Register Bit Definition
 */

#define TIM2_DCR_DBL_SHIFT                      (8)
#define TIM2_DCR_DBL_MASK                       (0x1FU << TIM2_DCR_DBL_SHIFT)
#define TIM2_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_DCR_DBL_SHIFT)) & TIM2_DCR_DBL_MASK)

#define TIM2_DCR_DBA_SHIFT                      (0)
#define TIM2_DCR_DBA_MASK                       (0x1FU << TIM2_DCR_DBA_SHIFT)
#define TIM2_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x)) << TIM2_DCR_DBA_SHIFT)) & TIM2_DCR_DBA_MASK)

/*!
 * @brief TIM2_DMAR Register Bit Definition
 */

#define TIM2_DMAR_DMAB_SHIFT                    (0)
#define TIM2_DMAR_DMAB_MASK                     (0xFFFFU << TIM2_DMAR_DMAB_SHIFT)
#define TIM2_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_DMAR_DMAB_SHIFT)) & TIM2_DMAR_DMAB_MASK)

/*!
 * @brief TIM2_OR Register Bit Definition
 */

#define TIM2_OR_TI4RMP_SHIFT                    (6)
#define TIM2_OR_TI4RMP_MASK                     (0x3U << TIM2_OR_TI4RMP_SHIFT)
#define TIM2_OR_TI4RMP(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_OR_TI4RMP_SHIFT)) & TIM2_OR_TI4RMP_MASK)

#define TIM2_OR_ETRRMP_SHIFT                    (0)
#define TIM2_OR_ETRRMP_MASK                     (0x3U << TIM2_OR_ETRRMP_SHIFT)
#define TIM2_OR_ETRRMP(x)                       (((uint32_t)(((uint32_t)(x)) << TIM2_OR_ETRRMP_SHIFT)) & TIM2_OR_ETRRMP_MASK)

/*!
 * @}
 */ /* end of group TIM2_Register_Masks */
/******************************************************************************
 *TIM2 Instance
*******************************************************************************/

#define TIM2                 ((TIM2_Type*)TIM2_BASE)

/*!
 * @}
 */ /* end of group TIM2_Peripheral_Access_Layer */



/*!
 * @addtogroup TIM3_Peripheral_Access_Layer TIM3 Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM3 Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                          ///< Control Register 1                           offset: 0x00
    __IO uint32_t CR2;                                                          ///< Control Register 2                           offset: 0x04
    __IO uint32_t SMCR;                                                         ///< Slave Mode Control Register                  offset: 0x08
    __IO uint32_t DIER;                                                         ///< DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA)offset: 0x0C
    __IO uint32_t SR;                                                           ///< Status Register                              offset: 0x10
    __IO uint32_t EGR;                                                          ///< Event Generation Register                    offset: 0x14
    __IO uint32_t CCMR1;                                                        ///< Capture/Compare Mode Register 1              offset: 0x18
    __IO uint32_t CCMR2;                                                        ///< Capture/Compare Mode Register 2              offset: 0x1C
    __IO uint32_t CCER;                                                         ///< Capture/Compare Enable Register              offset: 0x20
    __IO uint32_t CNT;                                                          ///< Counter                                      offset: 0x24
    __IO uint32_t PSC;                                                          ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                          ///< Auto Reload Register                         offset: 0x2C
    __IO uint32_t Reserved0[1];                                                 ///< Reserved
    __IO uint32_t CCR1;                                                         ///< Capture/Compare Register 1                   offset: 0x34
    __IO uint32_t CCR2;                                                         ///< Capture/Compare Register 2                   offset: 0x38
    __IO uint32_t CCR3;                                                         ///< Capture/Compare Register 3                   offset: 0x3C
    __IO uint32_t CCR4;                                                         ///< Capture/Compare Register 4                   offset: 0x40
    __IO uint32_t Reserved1[1];                                                 ///< Reserved
    __IO uint32_t DCR;                                                          ///< DMA Control Register (only suitable for the chip with built in DMA)offset: 0x48
    __IO uint32_t DMAR;                                                         ///< DMA Address Register Of Continuous Mode (only suitable for the chip with built in DMA)offset: 0x4C
    __IO uint32_t OR;                                                           ///< Input Option Register                        offset: 0x50
} TIM3_Type;

/*******************************************************************************
 * TIM3 Type
 ******************************************************************************/

/*!
 * @addtogroup TIM3_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM3_CR1 Register Bit Definition
 */

#define TIM3_CR1_CKD_SHIFT                      (8)
#define TIM3_CR1_CKD_MASK                       (0x3U << TIM3_CR1_CKD_SHIFT)
#define TIM3_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_CKD_SHIFT)) & TIM3_CR1_CKD_MASK)

#define TIM3_CR1_ARPE_SHIFT                     (7)
#define TIM3_CR1_ARPE_MASK                      (0x1U << TIM3_CR1_ARPE_SHIFT)
#define TIM3_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_ARPE_SHIFT)) & TIM3_CR1_ARPE_MASK)

#define TIM3_CR1_CMS_SHIFT                      (5)
#define TIM3_CR1_CMS_MASK                       (0x3U << TIM3_CR1_CMS_SHIFT)
#define TIM3_CR1_CMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_CMS_SHIFT)) & TIM3_CR1_CMS_MASK)

#define TIM3_CR1_DIR_SHIFT                      (4)
#define TIM3_CR1_DIR_MASK                       (0x1U << TIM3_CR1_DIR_SHIFT)
#define TIM3_CR1_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_DIR_SHIFT)) & TIM3_CR1_DIR_MASK)

#define TIM3_CR1_OPM_SHIFT                      (3)
#define TIM3_CR1_OPM_MASK                       (0x1U << TIM3_CR1_OPM_SHIFT)
#define TIM3_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_OPM_SHIFT)) & TIM3_CR1_OPM_MASK)

#define TIM3_CR1_URS_SHIFT                      (2)
#define TIM3_CR1_URS_MASK                       (0x1U << TIM3_CR1_URS_SHIFT)
#define TIM3_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_URS_SHIFT)) & TIM3_CR1_URS_MASK)

#define TIM3_CR1_UDIS_SHIFT                     (1)
#define TIM3_CR1_UDIS_MASK                      (0x1U << TIM3_CR1_UDIS_SHIFT)
#define TIM3_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_UDIS_SHIFT)) & TIM3_CR1_UDIS_MASK)

#define TIM3_CR1_CEN_SHIFT                      (0)
#define TIM3_CR1_CEN_MASK                       (0x1U << TIM3_CR1_CEN_SHIFT)
#define TIM3_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR1_CEN_SHIFT)) & TIM3_CR1_CEN_MASK)

/*!
 * @brief TIM3_CR2 Register Bit Definition
 */

#define TIM3_CR2_TI1S_SHIFT                     (7)
#define TIM3_CR2_TI1S_MASK                      (0x1U << TIM3_CR2_TI1S_SHIFT)
#define TIM3_CR2_TI1S(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_CR2_TI1S_SHIFT)) & TIM3_CR2_TI1S_MASK)

#define TIM3_CR2_MMS_SHIFT                      (4)
#define TIM3_CR2_MMS_MASK                       (0x7U << TIM3_CR2_MMS_SHIFT)
#define TIM3_CR2_MMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CR2_MMS_SHIFT)) & TIM3_CR2_MMS_MASK)

#define TIM3_CR2_CCDS_SHIFT                     (3)
#define TIM3_CR2_CCDS_MASK                      (0x1U << TIM3_CR2_CCDS_SHIFT)
#define TIM3_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_CR2_CCDS_SHIFT)) & TIM3_CR2_CCDS_MASK)

/*!
 * @brief TIM3_SMCR Register Bit Definition
 */

#define TIM3_SMCR_ETP_SHIFT                     (15)
#define TIM3_SMCR_ETP_MASK                      (0x1U << TIM3_SMCR_ETP_SHIFT)
#define TIM3_SMCR_ETP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_ETP_SHIFT)) & TIM3_SMCR_ETP_MASK)

#define TIM3_SMCR_ECE_SHIFT                     (14)
#define TIM3_SMCR_ECE_MASK                      (0x1U << TIM3_SMCR_ECE_SHIFT)
#define TIM3_SMCR_ECE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_ECE_SHIFT)) & TIM3_SMCR_ECE_MASK)

#define TIM3_SMCR_ETPS_SHIFT                    (12)
#define TIM3_SMCR_ETPS_MASK                     (0x3U << TIM3_SMCR_ETPS_SHIFT)
#define TIM3_SMCR_ETPS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_ETPS_SHIFT)) & TIM3_SMCR_ETPS_MASK)

#define TIM3_SMCR_ETF_SHIFT                     (8)
#define TIM3_SMCR_ETF_MASK                      (0xFU << TIM3_SMCR_ETF_SHIFT)
#define TIM3_SMCR_ETF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_ETF_SHIFT)) & TIM3_SMCR_ETF_MASK)

#define TIM3_SMCR_MSM_SHIFT                     (7)
#define TIM3_SMCR_MSM_MASK                      (0x1U << TIM3_SMCR_MSM_SHIFT)
#define TIM3_SMCR_MSM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_MSM_SHIFT)) & TIM3_SMCR_MSM_MASK)

#define TIM3_SMCR_TS_SHIFT                      (4)
#define TIM3_SMCR_TS_MASK                       (0x7U << TIM3_SMCR_TS_SHIFT)
#define TIM3_SMCR_TS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_TS_SHIFT)) & TIM3_SMCR_TS_MASK)

#define TIM3_SMCR_OCCS_SHIFT                    (3)
#define TIM3_SMCR_OCCS_MASK                     (0x1U << TIM3_SMCR_OCCS_SHIFT)
#define TIM3_SMCR_OCCS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_OCCS_SHIFT)) & TIM3_SMCR_OCCS_MASK)

#define TIM3_SMCR_SMS_SHIFT                     (0)
#define TIM3_SMCR_SMS_MASK                      (0x7U << TIM3_SMCR_SMS_SHIFT)
#define TIM3_SMCR_SMS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SMCR_SMS_SHIFT)) & TIM3_SMCR_SMS_MASK)

/*!
 * @brief TIM3_DIER Register Bit Definition
 */

#define TIM3_DIER_TDE_SHIFT                     (14)
#define TIM3_DIER_TDE_MASK                      (0x1U << TIM3_DIER_TDE_SHIFT)
#define TIM3_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_TDE_SHIFT)) & TIM3_DIER_TDE_MASK)

#define TIM3_DIER_CC4DE_SHIFT                   (12)
#define TIM3_DIER_CC4DE_MASK                    (0x1U << TIM3_DIER_CC4DE_SHIFT)
#define TIM3_DIER_CC4DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC4DE_SHIFT)) & TIM3_DIER_CC4DE_MASK)

#define TIM3_DIER_CC3DE_SHIFT                   (11)
#define TIM3_DIER_CC3DE_MASK                    (0x1U << TIM3_DIER_CC3DE_SHIFT)
#define TIM3_DIER_CC3DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC3DE_SHIFT)) & TIM3_DIER_CC3DE_MASK)

#define TIM3_DIER_CC2DE_SHIFT                   (10)
#define TIM3_DIER_CC2DE_MASK                    (0x1U << TIM3_DIER_CC2DE_SHIFT)
#define TIM3_DIER_CC2DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC2DE_SHIFT)) & TIM3_DIER_CC2DE_MASK)

#define TIM3_DIER_CC1DE_SHIFT                   (9)
#define TIM3_DIER_CC1DE_MASK                    (0x1U << TIM3_DIER_CC1DE_SHIFT)
#define TIM3_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC1DE_SHIFT)) & TIM3_DIER_CC1DE_MASK)

#define TIM3_DIER_UDE_SHIFT                     (8)
#define TIM3_DIER_UDE_MASK                      (0x1U << TIM3_DIER_UDE_SHIFT)
#define TIM3_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_UDE_SHIFT)) & TIM3_DIER_UDE_MASK)

#define TIM3_DIER_TIE_SHIFT                     (6)
#define TIM3_DIER_TIE_MASK                      (0x1U << TIM3_DIER_TIE_SHIFT)
#define TIM3_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_TIE_SHIFT)) & TIM3_DIER_TIE_MASK)

#define TIM3_DIER_CC4IE_SHIFT                   (4)
#define TIM3_DIER_CC4IE_MASK                    (0x1U << TIM3_DIER_CC4IE_SHIFT)
#define TIM3_DIER_CC4IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC4IE_SHIFT)) & TIM3_DIER_CC4IE_MASK)

#define TIM3_DIER_CC3IE_SHIFT                   (3)
#define TIM3_DIER_CC3IE_MASK                    (0x1U << TIM3_DIER_CC3IE_SHIFT)
#define TIM3_DIER_CC3IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC3IE_SHIFT)) & TIM3_DIER_CC3IE_MASK)

#define TIM3_DIER_CC2IE_SHIFT                   (2)
#define TIM3_DIER_CC2IE_MASK                    (0x1U << TIM3_DIER_CC2IE_SHIFT)
#define TIM3_DIER_CC2IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC2IE_SHIFT)) & TIM3_DIER_CC2IE_MASK)

#define TIM3_DIER_CC1IE_SHIFT                   (1)
#define TIM3_DIER_CC1IE_MASK                    (0x1U << TIM3_DIER_CC1IE_SHIFT)
#define TIM3_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_CC1IE_SHIFT)) & TIM3_DIER_CC1IE_MASK)

#define TIM3_DIER_UIE_SHIFT                     (0)
#define TIM3_DIER_UIE_MASK                      (0x1U << TIM3_DIER_UIE_SHIFT)
#define TIM3_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_DIER_UIE_SHIFT)) & TIM3_DIER_UIE_MASK)

/*!
 * @brief TIM3_SR Register Bit Definition
 */

#define TIM3_SR_CC4OF_SHIFT                     (12)
#define TIM3_SR_CC4OF_MASK                      (0x1U << TIM3_SR_CC4OF_SHIFT)
#define TIM3_SR_CC4OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC4OF_SHIFT)) & TIM3_SR_CC4OF_MASK)

#define TIM3_SR_CC3OF_SHIFT                     (11)
#define TIM3_SR_CC3OF_MASK                      (0x1U << TIM3_SR_CC3OF_SHIFT)
#define TIM3_SR_CC3OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC3OF_SHIFT)) & TIM3_SR_CC3OF_MASK)

#define TIM3_SR_CC2OF_SHIFT                     (10)
#define TIM3_SR_CC2OF_MASK                      (0x1U << TIM3_SR_CC2OF_SHIFT)
#define TIM3_SR_CC2OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC2OF_SHIFT)) & TIM3_SR_CC2OF_MASK)

#define TIM3_SR_CC1OF_SHIFT                     (9)
#define TIM3_SR_CC1OF_MASK                      (0x1U << TIM3_SR_CC1OF_SHIFT)
#define TIM3_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC1OF_SHIFT)) & TIM3_SR_CC1OF_MASK)

#define TIM3_SR_TIF_SHIFT                       (6)
#define TIM3_SR_TIF_MASK                        (0x1U << TIM3_SR_TIF_SHIFT)
#define TIM3_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM3_SR_TIF_SHIFT)) & TIM3_SR_TIF_MASK)

#define TIM3_SR_CC4IF_SHIFT                     (4)
#define TIM3_SR_CC4IF_MASK                      (0x1U << TIM3_SR_CC4IF_SHIFT)
#define TIM3_SR_CC4IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC4IF_SHIFT)) & TIM3_SR_CC4IF_MASK)

#define TIM3_SR_CC3IF_SHIFT                     (3)
#define TIM3_SR_CC3IF_MASK                      (0x1U << TIM3_SR_CC3IF_SHIFT)
#define TIM3_SR_CC3IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC3IF_SHIFT)) & TIM3_SR_CC3IF_MASK)

#define TIM3_SR_CC2IF_SHIFT                     (2)
#define TIM3_SR_CC2IF_MASK                      (0x1U << TIM3_SR_CC2IF_SHIFT)
#define TIM3_SR_CC2IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC2IF_SHIFT)) & TIM3_SR_CC2IF_MASK)

#define TIM3_SR_CC1IF_SHIFT                     (1)
#define TIM3_SR_CC1IF_MASK                      (0x1U << TIM3_SR_CC1IF_SHIFT)
#define TIM3_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_SR_CC1IF_SHIFT)) & TIM3_SR_CC1IF_MASK)

#define TIM3_SR_UIF_SHIFT                       (0)
#define TIM3_SR_UIF_MASK                        (0x1U << TIM3_SR_UIF_SHIFT)
#define TIM3_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM3_SR_UIF_SHIFT)) & TIM3_SR_UIF_MASK)

/*!
 * @brief TIM3_EGR Register Bit Definition
 */

#define TIM3_EGR_TG_SHIFT                       (6)
#define TIM3_EGR_TG_MASK                        (0x1U << TIM3_EGR_TG_SHIFT)
#define TIM3_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_TG_SHIFT)) & TIM3_EGR_TG_MASK)

#define TIM3_EGR_CC4G_SHIFT                     (4)
#define TIM3_EGR_CC4G_MASK                      (0x1U << TIM3_EGR_CC4G_SHIFT)
#define TIM3_EGR_CC4G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_CC4G_SHIFT)) & TIM3_EGR_CC4G_MASK)

#define TIM3_EGR_CC3G_SHIFT                     (3)
#define TIM3_EGR_CC3G_MASK                      (0x1U << TIM3_EGR_CC3G_SHIFT)
#define TIM3_EGR_CC3G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_CC3G_SHIFT)) & TIM3_EGR_CC3G_MASK)

#define TIM3_EGR_CC2G_SHIFT                     (2)
#define TIM3_EGR_CC2G_MASK                      (0x1U << TIM3_EGR_CC2G_SHIFT)
#define TIM3_EGR_CC2G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_CC2G_SHIFT)) & TIM3_EGR_CC2G_MASK)

#define TIM3_EGR_CC1G_SHIFT                     (1)
#define TIM3_EGR_CC1G_MASK                      (0x1U << TIM3_EGR_CC1G_SHIFT)
#define TIM3_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_CC1G_SHIFT)) & TIM3_EGR_CC1G_MASK)

#define TIM3_EGR_UG_SHIFT                       (0)
#define TIM3_EGR_UG_MASK                        (0x1U << TIM3_EGR_UG_SHIFT)
#define TIM3_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM3_EGR_UG_SHIFT)) & TIM3_EGR_UG_MASK)

/*!
 * @brief TIM3_CCMR1_OUTPUT Register Bit Definition
 */

#define TIM3_CCMR1OUTPUT_OC2CE_SHIFT            (15)
#define TIM3_CCMR1OUTPUT_OC2CE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC2CE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC2CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC2CE_SHIFT)) & TIM3_CCMR1OUTPUT_OC2CE_MASK)

#define TIM3_CCMR1OUTPUT_OC2M_SHIFT             (12)
#define TIM3_CCMR1OUTPUT_OC2M_MASK              (0x7U << TIM3_CCMR1OUTPUT_OC2M_SHIFT)
#define TIM3_CCMR1OUTPUT_OC2M(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC2M_SHIFT)) & TIM3_CCMR1OUTPUT_OC2M_MASK)

#define TIM3_CCMR1OUTPUT_OC2PE_SHIFT            (11)
#define TIM3_CCMR1OUTPUT_OC2PE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC2PE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC2PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC2PE_SHIFT)) & TIM3_CCMR1OUTPUT_OC2PE_MASK)

#define TIM3_CCMR1OUTPUT_OC2FE_SHIFT            (10)
#define TIM3_CCMR1OUTPUT_OC2FE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC2FE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC2FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC2FE_SHIFT)) & TIM3_CCMR1OUTPUT_OC2FE_MASK)

#define TIM3_CCMR1OUTPUT_CC2S_SHIFT             (8)
#define TIM3_CCMR1OUTPUT_CC2S_MASK              (0x3U << TIM3_CCMR1OUTPUT_CC2S_SHIFT)
#define TIM3_CCMR1OUTPUT_CC2S(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_CC2S_SHIFT)) & TIM3_CCMR1OUTPUT_CC2S_MASK)

#define TIM3_CCMR1OUTPUT_OC1CE_SHIFT            (7)
#define TIM3_CCMR1OUTPUT_OC1CE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC1CE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC1CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC1CE_SHIFT)) & TIM3_CCMR1OUTPUT_OC1CE_MASK)

#define TIM3_CCMR1OUTPUT_OC1M_SHIFT             (4)
#define TIM3_CCMR1OUTPUT_OC1M_MASK              (0x7U << TIM3_CCMR1OUTPUT_OC1M_SHIFT)
#define TIM3_CCMR1OUTPUT_OC1M(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC1M_SHIFT)) & TIM3_CCMR1OUTPUT_OC1M_MASK)

#define TIM3_CCMR1OUTPUT_OC1PE_SHIFT            (3)
#define TIM3_CCMR1OUTPUT_OC1PE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC1PE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC1PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC1PE_SHIFT)) & TIM3_CCMR1OUTPUT_OC1PE_MASK)

#define TIM3_CCMR1OUTPUT_OC1FE_SHIFT            (2)
#define TIM3_CCMR1OUTPUT_OC1FE_MASK             (0x1U << TIM3_CCMR1OUTPUT_OC1FE_SHIFT)
#define TIM3_CCMR1OUTPUT_OC1FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_OC1FE_SHIFT)) & TIM3_CCMR1OUTPUT_OC1FE_MASK)

#define TIM3_CCMR1OUTPUT_CC1S_SHIFT             (0)
#define TIM3_CCMR1OUTPUT_CC1S_MASK              (0x3U << TIM3_CCMR1OUTPUT_CC1S_SHIFT)
#define TIM3_CCMR1OUTPUT_CC1S(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1OUTPUT_CC1S_SHIFT)) & TIM3_CCMR1OUTPUT_CC1S_MASK)

/*!
 * @brief TIM3_CCMR1_INPUT Register Bit Definition
 */

#define TIM3_CCMR1INPUT_IC2F_SHIFT              (12)
#define TIM3_CCMR1INPUT_IC2F_MASK               (0xFU << TIM3_CCMR1INPUT_IC2F_SHIFT)
#define TIM3_CCMR1INPUT_IC2F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_IC2F_SHIFT)) & TIM3_CCMR1INPUT_IC2F_MASK)

#define TIM3_CCMR1INPUT_IC2PSC_SHIFT            (10)
#define TIM3_CCMR1INPUT_IC2PSC_MASK             (0x3U << TIM3_CCMR1INPUT_IC2PSC_SHIFT)
#define TIM3_CCMR1INPUT_IC2PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_IC2PSC_SHIFT)) & TIM3_CCMR1INPUT_IC2PSC_MASK)

#define TIM3_CCMR1INPUT_CC2S_SHIFT              (8)
#define TIM3_CCMR1INPUT_CC2S_MASK               (0x3U << TIM3_CCMR1INPUT_CC2S_SHIFT)
#define TIM3_CCMR1INPUT_CC2S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_CC2S_SHIFT)) & TIM3_CCMR1INPUT_CC2S_MASK)

#define TIM3_CCMR1INPUT_IC1F_SHIFT              (4)
#define TIM3_CCMR1INPUT_IC1F_MASK               (0xFU << TIM3_CCMR1INPUT_IC1F_SHIFT)
#define TIM3_CCMR1INPUT_IC1F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_IC1F_SHIFT)) & TIM3_CCMR1INPUT_IC1F_MASK)

#define TIM3_CCMR1INPUT_IC1PSC_SHIFT            (2)
#define TIM3_CCMR1INPUT_IC1PSC_MASK             (0x3U << TIM3_CCMR1INPUT_IC1PSC_SHIFT)
#define TIM3_CCMR1INPUT_IC1PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_IC1PSC_SHIFT)) & TIM3_CCMR1INPUT_IC1PSC_MASK)

#define TIM3_CCMR1INPUT_CC1S_SHIFT              (0)
#define TIM3_CCMR1INPUT_CC1S_MASK               (0x3U << TIM3_CCMR1INPUT_CC1S_SHIFT)
#define TIM3_CCMR1INPUT_CC1S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR1INPUT_CC1S_SHIFT)) & TIM3_CCMR1INPUT_CC1S_MASK)

/*!
 * @brief TIM3_CCMR2_OUTPUT Register Bit Definition
 */

#define TIM3_CCMR2OUTPUT_OC4CE_SHIFT            (15)
#define TIM3_CCMR2OUTPUT_OC4CE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC4CE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC4CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC4CE_SHIFT)) & TIM3_CCMR2OUTPUT_OC4CE_MASK)

#define TIM3_CCMR2OUTPUT_OC4M_SHIFT             (12)
#define TIM3_CCMR2OUTPUT_OC4M_MASK              (0x7U << TIM3_CCMR2OUTPUT_OC4M_SHIFT)
#define TIM3_CCMR2OUTPUT_OC4M(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC4M_SHIFT)) & TIM3_CCMR2OUTPUT_OC4M_MASK)

#define TIM3_CCMR2OUTPUT_OC4PE_SHIFT            (11)
#define TIM3_CCMR2OUTPUT_OC4PE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC4PE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC4PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC4PE_SHIFT)) & TIM3_CCMR2OUTPUT_OC4PE_MASK)

#define TIM3_CCMR2OUTPUT_OC4FE_SHIFT            (10)
#define TIM3_CCMR2OUTPUT_OC4FE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC4FE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC4FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC4FE_SHIFT)) & TIM3_CCMR2OUTPUT_OC4FE_MASK)

#define TIM3_CCMR2OUTPUT_CC4S_SHIFT             (8)
#define TIM3_CCMR2OUTPUT_CC4S_MASK              (0x3U << TIM3_CCMR2OUTPUT_CC4S_SHIFT)
#define TIM3_CCMR2OUTPUT_CC4S(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_CC4S_SHIFT)) & TIM3_CCMR2OUTPUT_CC4S_MASK)

#define TIM3_CCMR2OUTPUT_OC3CE_SHIFT            (7)
#define TIM3_CCMR2OUTPUT_OC3CE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC3CE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC3CE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC3CE_SHIFT)) & TIM3_CCMR2OUTPUT_OC3CE_MASK)

#define TIM3_CCMR2OUTPUT_OC3M_SHIFT             (4)
#define TIM3_CCMR2OUTPUT_OC3M_MASK              (0x7U << TIM3_CCMR2OUTPUT_OC3M_SHIFT)
#define TIM3_CCMR2OUTPUT_OC3M(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC3M_SHIFT)) & TIM3_CCMR2OUTPUT_OC3M_MASK)

#define TIM3_CCMR2OUTPUT_OC3PE_SHIFT            (3)
#define TIM3_CCMR2OUTPUT_OC3PE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC3PE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC3PE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC3PE_SHIFT)) & TIM3_CCMR2OUTPUT_OC3PE_MASK)

#define TIM3_CCMR2OUTPUT_OC3FE_SHIFT            (2)
#define TIM3_CCMR2OUTPUT_OC3FE_MASK             (0x1U << TIM3_CCMR2OUTPUT_OC3FE_SHIFT)
#define TIM3_CCMR2OUTPUT_OC3FE(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_OC3FE_SHIFT)) & TIM3_CCMR2OUTPUT_OC3FE_MASK)

#define TIM3_CCMR2OUTPUT_CC3S_SHIFT             (0)
#define TIM3_CCMR2OUTPUT_CC3S_MASK              (0x3U << TIM3_CCMR2OUTPUT_CC3S_SHIFT)
#define TIM3_CCMR2OUTPUT_CC3S(x)                (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2OUTPUT_CC3S_SHIFT)) & TIM3_CCMR2OUTPUT_CC3S_MASK)

/*!
 * @brief TIM3_CCMR2_INPUT Register Bit Definition
 */

#define TIM3_CCMR2INPUT_IC4F_SHIFT              (12)
#define TIM3_CCMR2INPUT_IC4F_MASK               (0xFU << TIM3_CCMR2INPUT_IC4F_SHIFT)
#define TIM3_CCMR2INPUT_IC4F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_IC4F_SHIFT)) & TIM3_CCMR2INPUT_IC4F_MASK)

#define TIM3_CCMR2INPUT_IC4PSC_SHIFT            (10)
#define TIM3_CCMR2INPUT_IC4PSC_MASK             (0x3U << TIM3_CCMR2INPUT_IC4PSC_SHIFT)
#define TIM3_CCMR2INPUT_IC4PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_IC4PSC_SHIFT)) & TIM3_CCMR2INPUT_IC4PSC_MASK)

#define TIM3_CCMR2INPUT_CC4S_SHIFT              (8)
#define TIM3_CCMR2INPUT_CC4S_MASK               (0x3U << TIM3_CCMR2INPUT_CC4S_SHIFT)
#define TIM3_CCMR2INPUT_CC4S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_CC4S_SHIFT)) & TIM3_CCMR2INPUT_CC4S_MASK)

#define TIM3_CCMR2INPUT_IC3F_SHIFT              (4)
#define TIM3_CCMR2INPUT_IC3F_MASK               (0xFU << TIM3_CCMR2INPUT_IC3F_SHIFT)
#define TIM3_CCMR2INPUT_IC3F(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_IC3F_SHIFT)) & TIM3_CCMR2INPUT_IC3F_MASK)

#define TIM3_CCMR2INPUT_IC3PSC_SHIFT            (2)
#define TIM3_CCMR2INPUT_IC3PSC_MASK             (0x3U << TIM3_CCMR2INPUT_IC3PSC_SHIFT)
#define TIM3_CCMR2INPUT_IC3PSC(x)               (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_IC3PSC_SHIFT)) & TIM3_CCMR2INPUT_IC3PSC_MASK)

#define TIM3_CCMR2INPUT_CC3S_SHIFT              (0)
#define TIM3_CCMR2INPUT_CC3S_MASK               (0x3U << TIM3_CCMR2INPUT_CC3S_SHIFT)
#define TIM3_CCMR2INPUT_CC3S(x)                 (((uint32_t)(((uint32_t)(x)) << TIM3_CCMR2INPUT_CC3S_SHIFT)) & TIM3_CCMR2INPUT_CC3S_MASK)

/*!
 * @brief TIM3_CCER Register Bit Definition
 */

#define TIM3_CCER_CC4NP_SHIFT                   (15)
#define TIM3_CCER_CC4NP_MASK                    (0x1U << TIM3_CCER_CC4NP_SHIFT)
#define TIM3_CCER_CC4NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC4NP_SHIFT)) & TIM3_CCER_CC4NP_MASK)

#define TIM3_CCER_CC4P_SHIFT                    (13)
#define TIM3_CCER_CC4P_MASK                     (0x1U << TIM3_CCER_CC4P_SHIFT)
#define TIM3_CCER_CC4P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC4P_SHIFT)) & TIM3_CCER_CC4P_MASK)

#define TIM3_CCER_CC4E_SHIFT                    (12)
#define TIM3_CCER_CC4E_MASK                     (0x1U << TIM3_CCER_CC4E_SHIFT)
#define TIM3_CCER_CC4E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC4E_SHIFT)) & TIM3_CCER_CC4E_MASK)

#define TIM3_CCER_CC3NP_SHIFT                   (11)
#define TIM3_CCER_CC3NP_MASK                    (0x1U << TIM3_CCER_CC3NP_SHIFT)
#define TIM3_CCER_CC3NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC3NP_SHIFT)) & TIM3_CCER_CC3NP_MASK)

#define TIM3_CCER_CC3P_SHIFT                    (9)
#define TIM3_CCER_CC3P_MASK                     (0x1U << TIM3_CCER_CC3P_SHIFT)
#define TIM3_CCER_CC3P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC3P_SHIFT)) & TIM3_CCER_CC3P_MASK)

#define TIM3_CCER_CC3E_SHIFT                    (8)
#define TIM3_CCER_CC3E_MASK                     (0x1U << TIM3_CCER_CC3E_SHIFT)
#define TIM3_CCER_CC3E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC3E_SHIFT)) & TIM3_CCER_CC3E_MASK)

#define TIM3_CCER_CC2NP_SHIFT                   (7)
#define TIM3_CCER_CC2NP_MASK                    (0x1U << TIM3_CCER_CC2NP_SHIFT)
#define TIM3_CCER_CC2NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC2NP_SHIFT)) & TIM3_CCER_CC2NP_MASK)

#define TIM3_CCER_CC2P_SHIFT                    (5)
#define TIM3_CCER_CC2P_MASK                     (0x1U << TIM3_CCER_CC2P_SHIFT)
#define TIM3_CCER_CC2P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC2P_SHIFT)) & TIM3_CCER_CC2P_MASK)

#define TIM3_CCER_CC2E_SHIFT                    (4)
#define TIM3_CCER_CC2E_MASK                     (0x1U << TIM3_CCER_CC2E_SHIFT)
#define TIM3_CCER_CC2E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC2E_SHIFT)) & TIM3_CCER_CC2E_MASK)

#define TIM3_CCER_CC1NP_SHIFT                   (3)
#define TIM3_CCER_CC1NP_MASK                    (0x1U << TIM3_CCER_CC1NP_SHIFT)
#define TIM3_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC1NP_SHIFT)) & TIM3_CCER_CC1NP_MASK)

#define TIM3_CCER_CC1P_SHIFT                    (1)
#define TIM3_CCER_CC1P_MASK                     (0x1U << TIM3_CCER_CC1P_SHIFT)
#define TIM3_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC1P_SHIFT)) & TIM3_CCER_CC1P_MASK)

#define TIM3_CCER_CC1E_SHIFT                    (0)
#define TIM3_CCER_CC1E_MASK                     (0x1U << TIM3_CCER_CC1E_SHIFT)
#define TIM3_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCER_CC1E_SHIFT)) & TIM3_CCER_CC1E_MASK)

/*!
 * @brief TIM3_CNT Register Bit Definition
 */

#define TIM3_CNT_CNT_SHIFT                      (0)
#define TIM3_CNT_CNT_MASK                       (0xFFFFU << TIM3_CNT_CNT_SHIFT)
#define TIM3_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_CNT_CNT_SHIFT)) & TIM3_CNT_CNT_MASK)

/*!
 * @brief TIM3_PSC Register Bit Definition
 */

#define TIM3_PSC_PSC_SHIFT                      (0)
#define TIM3_PSC_PSC_MASK                       (0xFFFFU << TIM3_PSC_PSC_SHIFT)
#define TIM3_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_PSC_PSC_SHIFT)) & TIM3_PSC_PSC_MASK)

/*!
 * @brief TIM3_ARR Register Bit Definition
 */

#define TIM3_ARR_ARR_SHIFT                      (0)
#define TIM3_ARR_ARR_MASK                       (0xFFFFU << TIM3_ARR_ARR_SHIFT)
#define TIM3_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_ARR_ARR_SHIFT)) & TIM3_ARR_ARR_MASK)

/*!
 * @brief TIM3_CCR1 Register Bit Definition
 */

#define TIM3_CCR1_CCR1_SHIFT                    (0)
#define TIM3_CCR1_CCR1_MASK                     (0xFFFFU << TIM3_CCR1_CCR1_SHIFT)
#define TIM3_CCR1_CCR1(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCR1_CCR1_SHIFT)) & TIM3_CCR1_CCR1_MASK)

/*!
 * @brief TIM3_CCR2 Register Bit Definition
 */

#define TIM3_CCR2_CCR2_SHIFT                    (0)
#define TIM3_CCR2_CCR2_MASK                     (0xFFFFU << TIM3_CCR2_CCR2_SHIFT)
#define TIM3_CCR2_CCR2(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCR2_CCR2_SHIFT)) & TIM3_CCR2_CCR2_MASK)

/*!
 * @brief TIM3_CCR3 Register Bit Definition
 */

#define TIM3_CCR3_CCR3_SHIFT                    (0)
#define TIM3_CCR3_CCR3_MASK                     (0xFFFFU << TIM3_CCR3_CCR3_SHIFT)
#define TIM3_CCR3_CCR3(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCR3_CCR3_SHIFT)) & TIM3_CCR3_CCR3_MASK)

/*!
 * @brief TIM3_CCR4 Register Bit Definition
 */

#define TIM3_CCR4_CCR4_SHIFT                    (0)
#define TIM3_CCR4_CCR4_MASK                     (0xFFFFU << TIM3_CCR4_CCR4_SHIFT)
#define TIM3_CCR4_CCR4(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_CCR4_CCR4_SHIFT)) & TIM3_CCR4_CCR4_MASK)

/*!
 * @brief TIM3_DCR Register Bit Definition
 */

#define TIM3_DCR_DBL_SHIFT                      (8)
#define TIM3_DCR_DBL_MASK                       (0x1FU << TIM3_DCR_DBL_SHIFT)
#define TIM3_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_DCR_DBL_SHIFT)) & TIM3_DCR_DBL_MASK)

#define TIM3_DCR_DBA_SHIFT                      (0)
#define TIM3_DCR_DBA_MASK                       (0x1FU << TIM3_DCR_DBA_SHIFT)
#define TIM3_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x)) << TIM3_DCR_DBA_SHIFT)) & TIM3_DCR_DBA_MASK)

/*!
 * @brief TIM3_DMAR Register Bit Definition
 */

#define TIM3_DMAR_DMAB_SHIFT                    (0)
#define TIM3_DMAR_DMAB_MASK                     (0xFFFFU << TIM3_DMAR_DMAB_SHIFT)
#define TIM3_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_DMAR_DMAB_SHIFT)) & TIM3_DMAR_DMAB_MASK)

/*!
 * @brief TIM3_OR Register Bit Definition
 */

#define TIM3_OR_TI4RMP_SHIFT                    (6)
#define TIM3_OR_TI4RMP_MASK                     (0x3U << TIM3_OR_TI4RMP_SHIFT)
#define TIM3_OR_TI4RMP(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_OR_TI4RMP_SHIFT)) & TIM3_OR_TI4RMP_MASK)

#define TIM3_OR_ETRRMP_SHIFT                    (0)
#define TIM3_OR_ETRRMP_MASK                     (0x3U << TIM3_OR_ETRRMP_SHIFT)
#define TIM3_OR_ETRRMP(x)                       (((uint32_t)(((uint32_t)(x)) << TIM3_OR_ETRRMP_SHIFT)) & TIM3_OR_ETRRMP_MASK)

/*!
 * @}
 */ /* end of group TIM3_Register_Masks */
/******************************************************************************
 *TIM3 Instance
*******************************************************************************/

#define TIM3                 ((TIM3_Type*)TIM3_BASE)

/*!
 * @}
 */ /* end of group TIM3_Peripheral_Access_Layer */



/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * UART Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t TDR;                                                          ///< UART Transmission Data Register              offset: 0x00
    __IO uint32_t RDR;                                                          ///< UART Receipt Data Register                   offset: 0x04
    __IO uint32_t CSR;                                                          ///< UART Current Status Register                 offset: 0x08
    __IO uint32_t ISR;                                                          ///< UART Interrupt Status Register               offset: 0x0C
    __IO uint32_t IER;                                                          ///< UART Interrupt Enable Register               offset: 0x10
    __IO uint32_t ICR;                                                          ///< UART Interrupt Clear Register                offset: 0x14
    __IO uint32_t GCR;                                                          ///< UART Global Control Register                 offset: 0x18
    __IO uint32_t CCR;                                                          ///< UART Universal Control Register              offset: 0x1C
    __IO uint32_t BRR;                                                          ///< UART Baud Rate Register                      offset: 0x20
    __IO uint32_t FRA;                                                          ///< UART Fraction Baud Rate Register             offset: 0x24
    __IO uint32_t RXADDR;                                                       ///< UART Receipt Address Register                offset: 0x28
    __IO uint32_t RXMASK;                                                       ///< UART Receipt Mask Register                   offset: 0x2C
    __IO uint32_t SCR;                                                          ///< UART SCR Register                            offset: 0x30
    __IO uint32_t IDLR;                                                         ///< UART Idle Data Length Register               offset: 0x34
    __IO uint32_t ABRCR;                                                        ///< UART Auto Baud Rate Control Register         offset: 0x38
    __IO uint32_t IRDA;                                                         ///< UART Infrared Function Control Register      offset: 0x3C
} UART_Type;

/*******************************************************************************
 * UART Type
 ******************************************************************************/

/*!
 * @addtogroup UART_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief UART_TDR Register Bit Definition
 */

#define UART_TDR_TXREG_SHIFT                    (0)
#define UART_TDR_TXREG_MASK                     (0x1FFU << UART_TDR_TXREG_SHIFT)
#define UART_TDR_TXREG(x)                       (((uint32_t)(((uint32_t)(x)) << UART_TDR_TXREG_SHIFT)) & UART_TDR_TXREG_MASK)

/*!
 * @brief UART_RDR Register Bit Definition
 */

#define UART_RDR_RXREG_SHIFT                    (0)
#define UART_RDR_RXREG_MASK                     (0x1FFU << UART_RDR_RXREG_SHIFT)
#define UART_RDR_RXREG(x)                       (((uint32_t)(((uint32_t)(x)) << UART_RDR_RXREG_SHIFT)) & UART_RDR_RXREG_MASK)

/*!
 * @brief UART_CSR Register Bit Definition
 */

#define UART_CSR_TXEPT_SHIFT                    (3)
#define UART_CSR_TXEPT_MASK                     (0x1U << UART_CSR_TXEPT_SHIFT)
#define UART_CSR_TXEPT(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CSR_TXEPT_SHIFT)) & UART_CSR_TXEPT_MASK)

#define UART_CSR_TXFULL_SHIFT                   (2)
#define UART_CSR_TXFULL_MASK                    (0x1U << UART_CSR_TXFULL_SHIFT)
#define UART_CSR_TXFULL(x)                      (((uint32_t)(((uint32_t)(x)) << UART_CSR_TXFULL_SHIFT)) & UART_CSR_TXFULL_MASK)

#define UART_CSR_RXAVL_SHIFT                    (1)
#define UART_CSR_RXAVL_MASK                     (0x1U << UART_CSR_RXAVL_SHIFT)
#define UART_CSR_RXAVL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CSR_RXAVL_SHIFT)) & UART_CSR_RXAVL_MASK)

#define UART_CSR_TXC_SHIFT                      (0)
#define UART_CSR_TXC_MASK                       (0x1U << UART_CSR_TXC_SHIFT)
#define UART_CSR_TXC(x)                         (((uint32_t)(((uint32_t)(x)) << UART_CSR_TXC_SHIFT)) & UART_CSR_TXC_MASK)

/*!
 * @brief UART_ISR Register Bit Definition
 */

#define UART_ISR_ABRERRINTF_SHIFT               (11)
#define UART_ISR_ABRERRINTF_MASK                (0x1U << UART_ISR_ABRERRINTF_SHIFT)
#define UART_ISR_ABRERRINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_ABRERRINTF_SHIFT)) & UART_ISR_ABRERRINTF_MASK)

#define UART_ISR_ABRENDINTF_SHIFT               (10)
#define UART_ISR_ABRENDINTF_MASK                (0x1U << UART_ISR_ABRENDINTF_SHIFT)
#define UART_ISR_ABRENDINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_ABRENDINTF_SHIFT)) & UART_ISR_ABRENDINTF_MASK)

#define UART_ISR_RXIDLEINTF_SHIFT               (9)
#define UART_ISR_RXIDLEINTF_MASK                (0x1U << UART_ISR_RXIDLEINTF_SHIFT)
#define UART_ISR_RXIDLEINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXIDLEINTF_SHIFT)) & UART_ISR_RXIDLEINTF_MASK)

#define UART_ISR_RXB8INTF_SHIFT                 (8)
#define UART_ISR_RXB8INTF_MASK                  (0x1U << UART_ISR_RXB8INTF_SHIFT)
#define UART_ISR_RXB8INTF(x)                    (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXB8INTF_SHIFT)) & UART_ISR_RXB8INTF_MASK)

#define UART_ISR_TXBRKINTF_SHIFT                (7)
#define UART_ISR_TXBRKINTF_MASK                 (0x1U << UART_ISR_TXBRKINTF_SHIFT)
#define UART_ISR_TXBRKINTF(x)                   (((uint32_t)(((uint32_t)(x)) << UART_ISR_TXBRKINTF_SHIFT)) & UART_ISR_TXBRKINTF_MASK)

#define UART_ISR_RXBRKINTF_SHIFT                (6)
#define UART_ISR_RXBRKINTF_MASK                 (0x1U << UART_ISR_RXBRKINTF_SHIFT)
#define UART_ISR_RXBRKINTF(x)                   (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXBRKINTF_SHIFT)) & UART_ISR_RXBRKINTF_MASK)

#define UART_ISR_RXFERRINTF_SHIFT               (5)
#define UART_ISR_RXFERRINTF_MASK                (0x1U << UART_ISR_RXFERRINTF_SHIFT)
#define UART_ISR_RXFERRINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXFERRINTF_SHIFT)) & UART_ISR_RXFERRINTF_MASK)

#define UART_ISR_RXPERRINTF_SHIFT               (4)
#define UART_ISR_RXPERRINTF_MASK                (0x1U << UART_ISR_RXPERRINTF_SHIFT)
#define UART_ISR_RXPERRINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXPERRINTF_SHIFT)) & UART_ISR_RXPERRINTF_MASK)

#define UART_ISR_RXOERRINTF_SHIFT               (3)
#define UART_ISR_RXOERRINTF_MASK                (0x1U << UART_ISR_RXOERRINTF_SHIFT)
#define UART_ISR_RXOERRINTF(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXOERRINTF_SHIFT)) & UART_ISR_RXOERRINTF_MASK)

#define UART_ISR_TXCINTF_SHIFT                  (2)
#define UART_ISR_TXCINTF_MASK                   (0x1U << UART_ISR_TXCINTF_SHIFT)
#define UART_ISR_TXCINTF(x)                     (((uint32_t)(((uint32_t)(x)) << UART_ISR_TXCINTF_SHIFT)) & UART_ISR_TXCINTF_MASK)

#define UART_ISR_RXINTF_SHIFT                   (1)
#define UART_ISR_RXINTF_MASK                    (0x1U << UART_ISR_RXINTF_SHIFT)
#define UART_ISR_RXINTF(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ISR_RXINTF_SHIFT)) & UART_ISR_RXINTF_MASK)

#define UART_ISR_TXINTF_SHIFT                   (0)
#define UART_ISR_TXINTF_MASK                    (0x1U << UART_ISR_TXINTF_SHIFT)
#define UART_ISR_TXINTF(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ISR_TXINTF_SHIFT)) & UART_ISR_TXINTF_MASK)

/*!
 * @brief UART_IER Register Bit Definition
 */

#define UART_IER_ABRERRIEN_SHIFT                (11)
#define UART_IER_ABRERRIEN_MASK                 (0x1U << UART_IER_ABRERRIEN_SHIFT)
#define UART_IER_ABRERRIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_ABRERRIEN_SHIFT)) & UART_IER_ABRERRIEN_MASK)

#define UART_IER_ABRENDIEN_SHIFT                (10)
#define UART_IER_ABRENDIEN_MASK                 (0x1U << UART_IER_ABRENDIEN_SHIFT)
#define UART_IER_ABRENDIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_ABRENDIEN_SHIFT)) & UART_IER_ABRENDIEN_MASK)

#define UART_IER_RXIDLEIEN_SHIFT                (9)
#define UART_IER_RXIDLEIEN_MASK                 (0x1U << UART_IER_RXIDLEIEN_SHIFT)
#define UART_IER_RXIDLEIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_RXIDLEIEN_SHIFT)) & UART_IER_RXIDLEIEN_MASK)

#define UART_IER_RXB8IEN_SHIFT                  (8)
#define UART_IER_RXB8IEN_MASK                   (0x1U << UART_IER_RXB8IEN_SHIFT)
#define UART_IER_RXB8IEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_IER_RXB8IEN_SHIFT)) & UART_IER_RXB8IEN_MASK)

#define UART_IER_TXBRKIEN_SHIFT                 (7)
#define UART_IER_TXBRKIEN_MASK                  (0x1U << UART_IER_TXBRKIEN_SHIFT)
#define UART_IER_TXBRKIEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_IER_TXBRKIEN_SHIFT)) & UART_IER_TXBRKIEN_MASK)

#define UART_IER_RXBRKIEN_SHIFT                 (6)
#define UART_IER_RXBRKIEN_MASK                  (0x1U << UART_IER_RXBRKIEN_SHIFT)
#define UART_IER_RXBRKIEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_IER_RXBRKIEN_SHIFT)) & UART_IER_RXBRKIEN_MASK)

#define UART_IER_RXFERRIEN_SHIFT                (5)
#define UART_IER_RXFERRIEN_MASK                 (0x1U << UART_IER_RXFERRIEN_SHIFT)
#define UART_IER_RXFERRIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_RXFERRIEN_SHIFT)) & UART_IER_RXFERRIEN_MASK)

#define UART_IER_RXPERRIEN_SHIFT                (4)
#define UART_IER_RXPERRIEN_MASK                 (0x1U << UART_IER_RXPERRIEN_SHIFT)
#define UART_IER_RXPERRIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_RXPERRIEN_SHIFT)) & UART_IER_RXPERRIEN_MASK)

#define UART_IER_RXOERRIEN_SHIFT                (3)
#define UART_IER_RXOERRIEN_MASK                 (0x1U << UART_IER_RXOERRIEN_SHIFT)
#define UART_IER_RXOERRIEN(x)                   (((uint32_t)(((uint32_t)(x)) << UART_IER_RXOERRIEN_SHIFT)) & UART_IER_RXOERRIEN_MASK)

#define UART_IER_TXCIEN_SHIFT                   (2)
#define UART_IER_TXCIEN_MASK                    (0x1U << UART_IER_TXCIEN_SHIFT)
#define UART_IER_TXCIEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_IER_TXCIEN_SHIFT)) & UART_IER_TXCIEN_MASK)

#define UART_IER_RXIEN_SHIFT                    (1)
#define UART_IER_RXIEN_MASK                     (0x1U << UART_IER_RXIEN_SHIFT)
#define UART_IER_RXIEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_IER_RXIEN_SHIFT)) & UART_IER_RXIEN_MASK)

#define UART_IER_TXIEN_SHIFT                    (0)
#define UART_IER_TXIEN_MASK                     (0x1U << UART_IER_TXIEN_SHIFT)
#define UART_IER_TXIEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_IER_TXIEN_SHIFT)) & UART_IER_TXIEN_MASK)

/*!
 * @brief UART_ICR Register Bit Definition
 */

#define UART_ICR_ABRERRICLR_SHIFT               (11)
#define UART_ICR_ABRERRICLR_MASK                (0x1U << UART_ICR_ABRERRICLR_SHIFT)
#define UART_ICR_ABRERRICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_ABRERRICLR_SHIFT)) & UART_ICR_ABRERRICLR_MASK)

#define UART_ICR_ABRENDICLR_SHIFT               (10)
#define UART_ICR_ABRENDICLR_MASK                (0x1U << UART_ICR_ABRENDICLR_SHIFT)
#define UART_ICR_ABRENDICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_ABRENDICLR_SHIFT)) & UART_ICR_ABRENDICLR_MASK)

#define UART_ICR_RXIDLEICLR_SHIFT               (9)
#define UART_ICR_RXIDLEICLR_MASK                (0x1U << UART_ICR_RXIDLEICLR_SHIFT)
#define UART_ICR_RXIDLEICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXIDLEICLR_SHIFT)) & UART_ICR_RXIDLEICLR_MASK)

#define UART_ICR_RXB8ICLR_SHIFT                 (8)
#define UART_ICR_RXB8ICLR_MASK                  (0x1U << UART_ICR_RXB8ICLR_SHIFT)
#define UART_ICR_RXB8ICLR(x)                    (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXB8ICLR_SHIFT)) & UART_ICR_RXB8ICLR_MASK)

#define UART_ICR_TXBRKICLR_SHIFT                (7)
#define UART_ICR_TXBRKICLR_MASK                 (0x1U << UART_ICR_TXBRKICLR_SHIFT)
#define UART_ICR_TXBRKICLR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_ICR_TXBRKICLR_SHIFT)) & UART_ICR_TXBRKICLR_MASK)

#define UART_ICR_RXBRKICLR_SHIFT                (6)
#define UART_ICR_RXBRKICLR_MASK                 (0x1U << UART_ICR_RXBRKICLR_SHIFT)
#define UART_ICR_RXBRKICLR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXBRKICLR_SHIFT)) & UART_ICR_RXBRKICLR_MASK)

#define UART_ICR_RXFERRICLR_SHIFT               (5)
#define UART_ICR_RXFERRICLR_MASK                (0x1U << UART_ICR_RXFERRICLR_SHIFT)
#define UART_ICR_RXFERRICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXFERRICLR_SHIFT)) & UART_ICR_RXFERRICLR_MASK)

#define UART_ICR_RXPERRICLR_SHIFT               (4)
#define UART_ICR_RXPERRICLR_MASK                (0x1U << UART_ICR_RXPERRICLR_SHIFT)
#define UART_ICR_RXPERRICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXPERRICLR_SHIFT)) & UART_ICR_RXPERRICLR_MASK)

#define UART_ICR_RXOERRICLR_SHIFT               (3)
#define UART_ICR_RXOERRICLR_MASK                (0x1U << UART_ICR_RXOERRICLR_SHIFT)
#define UART_ICR_RXOERRICLR(x)                  (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXOERRICLR_SHIFT)) & UART_ICR_RXOERRICLR_MASK)

#define UART_ICR_TXCICLR_SHIFT                  (2)
#define UART_ICR_TXCICLR_MASK                   (0x1U << UART_ICR_TXCICLR_SHIFT)
#define UART_ICR_TXCICLR(x)                     (((uint32_t)(((uint32_t)(x)) << UART_ICR_TXCICLR_SHIFT)) & UART_ICR_TXCICLR_MASK)

#define UART_ICR_RXICLR_SHIFT                   (1)
#define UART_ICR_RXICLR_MASK                    (0x1U << UART_ICR_RXICLR_SHIFT)
#define UART_ICR_RXICLR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ICR_RXICLR_SHIFT)) & UART_ICR_RXICLR_MASK)

#define UART_ICR_TXICLR_SHIFT                   (0)
#define UART_ICR_TXICLR_MASK                    (0x1U << UART_ICR_TXICLR_SHIFT)
#define UART_ICR_TXICLR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ICR_TXICLR_SHIFT)) & UART_ICR_TXICLR_MASK)

/*!
 * @brief UART_GCR Register Bit Definition
 */

#define UART_GCR_TXTOG_SHIFT                    (10)
#define UART_GCR_TXTOG_MASK                     (0x1U << UART_GCR_TXTOG_SHIFT)
#define UART_GCR_TXTOG(x)                       (((uint32_t)(((uint32_t)(x)) << UART_GCR_TXTOG_SHIFT)) & UART_GCR_TXTOG_MASK)

#define UART_GCR_RXTOG_SHIFT                    (9)
#define UART_GCR_RXTOG_MASK                     (0x1U << UART_GCR_RXTOG_SHIFT)
#define UART_GCR_RXTOG(x)                       (((uint32_t)(((uint32_t)(x)) << UART_GCR_RXTOG_SHIFT)) & UART_GCR_RXTOG_MASK)

#define UART_GCR_SWAP_SHIFT                     (8)
#define UART_GCR_SWAP_MASK                      (0x1U << UART_GCR_SWAP_SHIFT)
#define UART_GCR_SWAP(x)                        (((uint32_t)(((uint32_t)(x)) << UART_GCR_SWAP_SHIFT)) & UART_GCR_SWAP_MASK)

#define UART_GCR_SELB8_SHIFT                    (7)
#define UART_GCR_SELB8_MASK                     (0x1U << UART_GCR_SELB8_SHIFT)
#define UART_GCR_SELB8(x)                       (((uint32_t)(((uint32_t)(x)) << UART_GCR_SELB8_SHIFT)) & UART_GCR_SELB8_MASK)

#define UART_GCR_TXEN_SHIFT                     (4)
#define UART_GCR_TXEN_MASK                      (0x1U << UART_GCR_TXEN_SHIFT)
#define UART_GCR_TXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_GCR_TXEN_SHIFT)) & UART_GCR_TXEN_MASK)

#define UART_GCR_RXEN_SHIFT                     (3)
#define UART_GCR_RXEN_MASK                      (0x1U << UART_GCR_RXEN_SHIFT)
#define UART_GCR_RXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_GCR_RXEN_SHIFT)) & UART_GCR_RXEN_MASK)

#define UART_GCR_AUTOFLOWEN_SHIFT               (2)
#define UART_GCR_AUTOFLOWEN_MASK                (0x1U << UART_GCR_AUTOFLOWEN_SHIFT)
#define UART_GCR_AUTOFLOWEN(x)                  (((uint32_t)(((uint32_t)(x)) << UART_GCR_AUTOFLOWEN_SHIFT)) & UART_GCR_AUTOFLOWEN_MASK)

#define UART_GCR_DMAMODE_SHIFT                  (1)
#define UART_GCR_DMAMODE_MASK                   (0x1U << UART_GCR_DMAMODE_SHIFT)
#define UART_GCR_DMAMODE(x)                     (((uint32_t)(((uint32_t)(x)) << UART_GCR_DMAMODE_SHIFT)) & UART_GCR_DMAMODE_MASK)

#define UART_GCR_UARTEN_SHIFT                   (0)
#define UART_GCR_UARTEN_MASK                    (0x1U << UART_GCR_UARTEN_SHIFT)
#define UART_GCR_UARTEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_GCR_UARTEN_SHIFT)) & UART_GCR_UARTEN_MASK)

/*!
 * @brief UART_CCR Register Bit Definition
 */

#define UART_CCR_LIN_SHIFT                      (14)
#define UART_CCR_LIN_MASK                       (0x1U << UART_CCR_LIN_SHIFT)
#define UART_CCR_LIN(x)                         (((uint32_t)(((uint32_t)(x)) << UART_CCR_LIN_SHIFT)) & UART_CCR_LIN_MASK)

#define UART_CCR_WAKE_SHIFT                     (13)
#define UART_CCR_WAKE_MASK                      (0x1U << UART_CCR_WAKE_SHIFT)
#define UART_CCR_WAKE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_WAKE_SHIFT)) & UART_CCR_WAKE_MASK)

#define UART_CCR_RWU_SHIFT                      (12)
#define UART_CCR_RWU_MASK                       (0x1U << UART_CCR_RWU_SHIFT)
#define UART_CCR_RWU(x)                         (((uint32_t)(((uint32_t)(x)) << UART_CCR_RWU_SHIFT)) & UART_CCR_RWU_MASK)

#define UART_CCR_B8EN_SHIFT                     (11)
#define UART_CCR_B8EN_MASK                      (0x1U << UART_CCR_B8EN_SHIFT)
#define UART_CCR_B8EN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_B8EN_SHIFT)) & UART_CCR_B8EN_MASK)

#define UART_CCR_B8TOG_SHIFT                    (10)
#define UART_CCR_B8TOG_MASK                     (0x1U << UART_CCR_B8TOG_SHIFT)
#define UART_CCR_B8TOG(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CCR_B8TOG_SHIFT)) & UART_CCR_B8TOG_MASK)

#define UART_CCR_B8POL_SHIFT                    (9)
#define UART_CCR_B8POL_MASK                     (0x1U << UART_CCR_B8POL_SHIFT)
#define UART_CCR_B8POL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CCR_B8POL_SHIFT)) & UART_CCR_B8POL_MASK)

#define UART_CCR_B8TXD_SHIFT                    (8)
#define UART_CCR_B8TXD_MASK                     (0x1U << UART_CCR_B8TXD_SHIFT)
#define UART_CCR_B8TXD(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CCR_B8TXD_SHIFT)) & UART_CCR_B8TXD_MASK)

#define UART_CCR_B8RXD_SHIFT                    (7)
#define UART_CCR_B8RXD_MASK                     (0x1U << UART_CCR_B8RXD_SHIFT)
#define UART_CCR_B8RXD(x)                       (((uint32_t)(((uint32_t)(x)) << UART_CCR_B8RXD_SHIFT)) & UART_CCR_B8RXD_MASK)

#define UART_CCR_SPB1_SHIFT                     (6)
#define UART_CCR_SPB1_MASK                      (0x1U << UART_CCR_SPB1_SHIFT)
#define UART_CCR_SPB1(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_SPB1_SHIFT)) & UART_CCR_SPB1_MASK)

#define UART_CCR_CHAR_SHIFT                     (4)
#define UART_CCR_CHAR_MASK                      (0x3U << UART_CCR_CHAR_SHIFT)
#define UART_CCR_CHAR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_CHAR_SHIFT)) & UART_CCR_CHAR_MASK)

#define UART_CCR_BRK_SHIFT                      (3)
#define UART_CCR_BRK_MASK                       (0x1U << UART_CCR_BRK_SHIFT)
#define UART_CCR_BRK(x)                         (((uint32_t)(((uint32_t)(x)) << UART_CCR_BRK_SHIFT)) & UART_CCR_BRK_MASK)

#define UART_CCR_SPB0_SHIFT                     (2)
#define UART_CCR_SPB0_MASK                      (0x1U << UART_CCR_SPB0_SHIFT)
#define UART_CCR_SPB0(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_SPB0_SHIFT)) & UART_CCR_SPB0_MASK)

#define UART_CCR_PSEL_SHIFT                     (1)
#define UART_CCR_PSEL_MASK                      (0x1U << UART_CCR_PSEL_SHIFT)
#define UART_CCR_PSEL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_CCR_PSEL_SHIFT)) & UART_CCR_PSEL_MASK)

#define UART_CCR_PEN_SHIFT                      (0)
#define UART_CCR_PEN_MASK                       (0x1U << UART_CCR_PEN_SHIFT)
#define UART_CCR_PEN(x)                         (((uint32_t)(((uint32_t)(x)) << UART_CCR_PEN_SHIFT)) & UART_CCR_PEN_MASK)

/*!
 * @brief UART_BRR Register Bit Definition
 */

#define UART_BRR_DIVMANTISSA_SHIFT              (0)
#define UART_BRR_DIVMANTISSA_MASK               (0xFFFFU << UART_BRR_DIVMANTISSA_SHIFT)
#define UART_BRR_DIVMANTISSA(x)                 (((uint32_t)(((uint32_t)(x)) << UART_BRR_DIVMANTISSA_SHIFT)) & UART_BRR_DIVMANTISSA_MASK)

/*!
 * @brief UART_FRA Register Bit Definition
 */

#define UART_FRA_DIVFRACTION_SHIFT              (0)
#define UART_FRA_DIVFRACTION_MASK               (0xFU << UART_FRA_DIVFRACTION_SHIFT)
#define UART_FRA_DIVFRACTION(x)                 (((uint32_t)(((uint32_t)(x)) << UART_FRA_DIVFRACTION_SHIFT)) & UART_FRA_DIVFRACTION_MASK)

/*!
 * @brief UART_RXADDR Register Bit Definition
 */

#define UART_RXADDR_RXADDR_SHIFT                (0)
#define UART_RXADDR_RXADDR_MASK                 (0xFFU << UART_RXADDR_RXADDR_SHIFT)
#define UART_RXADDR_RXADDR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_RXADDR_RXADDR_SHIFT)) & UART_RXADDR_RXADDR_MASK)

/*!
 * @brief UART_RXMASK Register Bit Definition
 */

#define UART_RXMASK_RXMASK_SHIFT                (0)
#define UART_RXMASK_RXMASK_MASK                 (0xFFU << UART_RXMASK_RXMASK_SHIFT)
#define UART_RXMASK_RXMASK(x)                   (((uint32_t)(((uint32_t)(x)) << UART_RXMASK_RXMASK_SHIFT)) & UART_RXMASK_RXMASK_MASK)

/*!
 * @brief UART_SCR Register Bit Definition
 */

#define UART_SCR_HDSEL_SHIFT                    (12)
#define UART_SCR_HDSEL_MASK                     (0x1U << UART_SCR_HDSEL_SHIFT)
#define UART_SCR_HDSEL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_SCR_HDSEL_SHIFT)) & UART_SCR_HDSEL_MASK)

#define UART_SCR_SCFCNT_SHIFT                   (4)
#define UART_SCR_SCFCNT_MASK                    (0xFFU << UART_SCR_SCFCNT_SHIFT)
#define UART_SCR_SCFCNT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_SCR_SCFCNT_SHIFT)) & UART_SCR_SCFCNT_MASK)

#define UART_SCR_NACK_SHIFT                     (2)
#define UART_SCR_NACK_MASK                      (0x1U << UART_SCR_NACK_SHIFT)
#define UART_SCR_NACK(x)                        (((uint32_t)(((uint32_t)(x)) << UART_SCR_NACK_SHIFT)) & UART_SCR_NACK_MASK)

#define UART_SCR_SCAEN_SHIFT                    (1)
#define UART_SCR_SCAEN_MASK                     (0x1U << UART_SCR_SCAEN_SHIFT)
#define UART_SCR_SCAEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_SCR_SCAEN_SHIFT)) & UART_SCR_SCAEN_MASK)

#define UART_SCR_SCEN_SHIFT                     (0)
#define UART_SCR_SCEN_MASK                      (0x1U << UART_SCR_SCEN_SHIFT)
#define UART_SCR_SCEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_SCR_SCEN_SHIFT)) & UART_SCR_SCEN_MASK)

/*!
 * @brief UART_IDLR Register Bit Definition
 */

#define UART_IDLR_IDLR_SHIFT                    (0)
#define UART_IDLR_IDLR_MASK                     (0xFFFFU << UART_IDLR_IDLR_SHIFT)
#define UART_IDLR_IDLR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_IDLR_IDLR_SHIFT)) & UART_IDLR_IDLR_MASK)

/*!
 * @brief UART_ABRCR Register Bit Definition
 */

#define UART_ABRCR_LATTEREDGE_SHIFT             (4)
#define UART_ABRCR_LATTEREDGE_MASK              (0x1U << UART_ABRCR_LATTEREDGE_SHIFT)
#define UART_ABRCR_LATTEREDGE(x)                (((uint32_t)(((uint32_t)(x)) << UART_ABRCR_LATTEREDGE_SHIFT)) & UART_ABRCR_LATTEREDGE_MASK)

#define UART_ABRCR_FORMEREDGE_SHIFT             (3)
#define UART_ABRCR_FORMEREDGE_MASK              (0x1U << UART_ABRCR_FORMEREDGE_SHIFT)
#define UART_ABRCR_FORMEREDGE(x)                (((uint32_t)(((uint32_t)(x)) << UART_ABRCR_FORMEREDGE_SHIFT)) & UART_ABRCR_FORMEREDGE_MASK)

#define UART_ABRCR_ABRBITCNT_SHIFT              (1)
#define UART_ABRCR_ABRBITCNT_MASK               (0x3U << UART_ABRCR_ABRBITCNT_SHIFT)
#define UART_ABRCR_ABRBITCNT(x)                 (((uint32_t)(((uint32_t)(x)) << UART_ABRCR_ABRBITCNT_SHIFT)) & UART_ABRCR_ABRBITCNT_MASK)

#define UART_ABRCR_ABREN_SHIFT                  (0)
#define UART_ABRCR_ABREN_MASK                   (0x1U << UART_ABRCR_ABREN_SHIFT)
#define UART_ABRCR_ABREN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_ABRCR_ABREN_SHIFT)) & UART_ABRCR_ABREN_MASK)

/*!
 * @brief UART_IRDA Register Bit Definition
 */

#define UART_IRDA_PSCREG_SHIFT                  (8)
#define UART_IRDA_PSCREG_MASK                   (0xFFU << UART_IRDA_PSCREG_SHIFT)
#define UART_IRDA_PSCREG(x)                     (((uint32_t)(((uint32_t)(x)) << UART_IRDA_PSCREG_SHIFT)) & UART_IRDA_PSCREG_MASK)

#define UART_IRDA_SIRLP_SHIFT                   (1)
#define UART_IRDA_SIRLP_MASK                    (0x1U << UART_IRDA_SIRLP_SHIFT)
#define UART_IRDA_SIRLP(x)                      (((uint32_t)(((uint32_t)(x)) << UART_IRDA_SIRLP_SHIFT)) & UART_IRDA_SIRLP_MASK)

#define UART_IRDA_SIREN_SHIFT                   (0)
#define UART_IRDA_SIREN_MASK                    (0x1U << UART_IRDA_SIREN_SHIFT)
#define UART_IRDA_SIREN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_IRDA_SIREN_SHIFT)) & UART_IRDA_SIREN_MASK)

/*!
 * @}
 */ /* end of group UART_Register_Masks */
/******************************************************************************
 *UART Instance
*******************************************************************************/

#define UART1                ((UART_Type*)UART1_BASE)

#define UART2                ((UART_Type*)UART2_BASE)

#define UART3                ((UART_Type*)UART3_BASE)

#define UART4                ((UART_Type*)UART4_BASE)

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */



/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * USB Type
 ******************************************************************************/
#define  USB_FSEPCTL_COUNT 8u
typedef struct {
    __IO uint32_t Reserved0[32];                                                ///< Reserved
    __IO uint32_t FSINTSTAT;                                                    ///< Interrupt Status Register                    offset: 0x80
    __IO uint32_t FSINTENB;                                                     ///< Interrupt Enable Register                    offset: 0x84
    __IO uint32_t FSERRSTAT;                                                    ///< Error Interrupt Status Register              offset: 0x88
    __IO uint32_t FSERRENB;                                                     ///< Error Interrupt Enable Register              offset: 0x8C
    __IO uint32_t FSSTAT;                                                       ///< Status Register                              offset: 0x90
    __IO uint32_t FSCTL;                                                        ///< Control Register                             offset: 0x94
    __IO uint32_t FSADDR;                                                       ///< Address Register                             offset: 0x98
    __IO uint32_t FSBDTPAGE1;                                                   ///< BDT Page Register 1                          offset: 0x9C
    __IO uint32_t FSFRMNUML;                                                    ///< Low Frame Number Register                    offset: 0xA0
    __IO uint32_t FSFRMNUMH;                                                    ///< High Frame Number Register                   offset: 0xA4
    __IO uint32_t Reserved1[2];                                                 ///< Reserved
    __IO uint32_t FSBDTPAGE2;                                                   ///< BDT Page Register 2                          offset: 0xB0
    __IO uint32_t FSBDTPAGE3;                                                   ///< BDT Page Register 3                          offset: 0xB4
    __IO uint32_t Reserved2[2];                                                 ///< Reserved
    __IO uint32_t FSEPCTL[8];                                                   ///< Endpoint Control Register 0~7                offset: 0xC0
    __IO uint32_t Reserved3[8];                                                 ///< Reserved
    __IO uint32_t FSUSBCTRL;                                                    ///< USB Control Register                         offset: 0x100
} USB_Type;

/*******************************************************************************
 * USB Type
 ******************************************************************************/

/*!
 * @addtogroup USB_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief USB_FS_INTSTAT Register Bit Definition
 */

#define USB_FSINTSTAT_STALL_SHIFT               (7)
#define USB_FSINTSTAT_STALL_MASK                (0x1U << USB_FSINTSTAT_STALL_SHIFT)
#define USB_FSINTSTAT_STALL(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_STALL_SHIFT)) & USB_FSINTSTAT_STALL_MASK)

#define USB_FSINTSTAT_RESUME_SHIFT              (5)
#define USB_FSINTSTAT_RESUME_MASK               (0x1U << USB_FSINTSTAT_RESUME_SHIFT)
#define USB_FSINTSTAT_RESUME(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_RESUME_SHIFT)) & USB_FSINTSTAT_RESUME_MASK)

#define USB_FSINTSTAT_SLEEP_SHIFT               (4)
#define USB_FSINTSTAT_SLEEP_MASK                (0x1U << USB_FSINTSTAT_SLEEP_SHIFT)
#define USB_FSINTSTAT_SLEEP(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_SLEEP_SHIFT)) & USB_FSINTSTAT_SLEEP_MASK)

#define USB_FSINTSTAT_TOKDNE_SHIFT              (3)
#define USB_FSINTSTAT_TOKDNE_MASK               (0x1U << USB_FSINTSTAT_TOKDNE_SHIFT)
#define USB_FSINTSTAT_TOKDNE(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_TOKDNE_SHIFT)) & USB_FSINTSTAT_TOKDNE_MASK)

#define USB_FSINTSTAT_SOFTOK_SHIFT              (2)
#define USB_FSINTSTAT_SOFTOK_MASK               (0x1U << USB_FSINTSTAT_SOFTOK_SHIFT)
#define USB_FSINTSTAT_SOFTOK(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_SOFTOK_SHIFT)) & USB_FSINTSTAT_SOFTOK_MASK)

#define USB_FSINTSTAT_ERROR_SHIFT               (1)
#define USB_FSINTSTAT_ERROR_MASK                (0x1U << USB_FSINTSTAT_ERROR_SHIFT)
#define USB_FSINTSTAT_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_ERROR_SHIFT)) & USB_FSINTSTAT_ERROR_MASK)

#define USB_FSINTSTAT_USBRST_SHIFT              (0)
#define USB_FSINTSTAT_USBRST_MASK               (0x1U << USB_FSINTSTAT_USBRST_SHIFT)
#define USB_FSINTSTAT_USBRST(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_USBRST_SHIFT)) & USB_FSINTSTAT_USBRST_MASK)

/*!
 * @brief USB_FS_INTENB Register Bit Definition
 */

#define USB_FSINTENB_STALL_SHIFT                (7)
#define USB_FSINTENB_STALL_MASK                 (0x1U << USB_FSINTENB_STALL_SHIFT)
#define USB_FSINTENB_STALL(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_STALL_SHIFT)) & USB_FSINTENB_STALL_MASK)

#define USB_FSINTENB_RESUME_SHIFT               (5)
#define USB_FSINTENB_RESUME_MASK                (0x1U << USB_FSINTENB_RESUME_SHIFT)
#define USB_FSINTENB_RESUME(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_RESUME_SHIFT)) & USB_FSINTENB_RESUME_MASK)

#define USB_FSINTENB_SLEEP_SHIFT                (4)
#define USB_FSINTENB_SLEEP_MASK                 (0x1U << USB_FSINTENB_SLEEP_SHIFT)
#define USB_FSINTENB_SLEEP(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_SLEEP_SHIFT)) & USB_FSINTENB_SLEEP_MASK)

#define USB_FSINTENB_TOKDNE_SHIFT               (3)
#define USB_FSINTENB_TOKDNE_MASK                (0x1U << USB_FSINTENB_TOKDNE_SHIFT)
#define USB_FSINTENB_TOKDNE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_TOKDNE_SHIFT)) & USB_FSINTENB_TOKDNE_MASK)

#define USB_FSINTENB_SOFTOK_SHIFT               (2)
#define USB_FSINTENB_SOFTOK_MASK                (0x1U << USB_FSINTENB_SOFTOK_SHIFT)
#define USB_FSINTENB_SOFTOK(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_SOFTOK_SHIFT)) & USB_FSINTENB_SOFTOK_MASK)

#define USB_FSINTENB_ERROR_SHIFT                (1)
#define USB_FSINTENB_ERROR_MASK                 (0x1U << USB_FSINTENB_ERROR_SHIFT)
#define USB_FSINTENB_ERROR(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_ERROR_SHIFT)) & USB_FSINTENB_ERROR_MASK)

#define USB_FSINTENB_USBRST_SHIFT               (0)
#define USB_FSINTENB_USBRST_MASK                (0x1U << USB_FSINTENB_USBRST_SHIFT)
#define USB_FSINTENB_USBRST(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_USBRST_SHIFT)) & USB_FSINTENB_USBRST_MASK)

/*!
 * @brief USB_FS_ERRSTAT Register Bit Definition
 */

#define USB_FSERRSTAT_BTSERR_SHIFT              (7)
#define USB_FSERRSTAT_BTSERR_MASK               (0x1U << USB_FSERRSTAT_BTSERR_SHIFT)
#define USB_FSERRSTAT_BTSERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_BTSERR_SHIFT)) & USB_FSERRSTAT_BTSERR_MASK)

#define USB_FSERRSTAT_DMAERR_SHIFT              (5)
#define USB_FSERRSTAT_DMAERR_MASK               (0x1U << USB_FSERRSTAT_DMAERR_SHIFT)
#define USB_FSERRSTAT_DMAERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_DMAERR_SHIFT)) & USB_FSERRSTAT_DMAERR_MASK)

#define USB_FSERRSTAT_BTOERR_SHIFT              (4)
#define USB_FSERRSTAT_BTOERR_MASK               (0x1U << USB_FSERRSTAT_BTOERR_SHIFT)
#define USB_FSERRSTAT_BTOERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_BTOERR_SHIFT)) & USB_FSERRSTAT_BTOERR_MASK)

#define USB_FSERRSTAT_DFN8_SHIFT                (3)
#define USB_FSERRSTAT_DFN8_MASK                 (0x1U << USB_FSERRSTAT_DFN8_SHIFT)
#define USB_FSERRSTAT_DFN8(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_DFN8_SHIFT)) & USB_FSERRSTAT_DFN8_MASK)

#define USB_FSERRSTAT_CRC16_SHIFT               (2)
#define USB_FSERRSTAT_CRC16_MASK                (0x1U << USB_FSERRSTAT_CRC16_SHIFT)
#define USB_FSERRSTAT_CRC16(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_CRC16_SHIFT)) & USB_FSERRSTAT_CRC16_MASK)

#define USB_FSERRSTAT_CRC5EOF_SHIFT             (1)
#define USB_FSERRSTAT_CRC5EOF_MASK              (0x1U << USB_FSERRSTAT_CRC5EOF_SHIFT)
#define USB_FSERRSTAT_CRC5EOF(x)                (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_CRC5EOF_SHIFT)) & USB_FSERRSTAT_CRC5EOF_MASK)

#define USB_FSERRSTAT_PIDERR_SHIFT              (0)
#define USB_FSERRSTAT_PIDERR_MASK               (0x1U << USB_FSERRSTAT_PIDERR_SHIFT)
#define USB_FSERRSTAT_PIDERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_PIDERR_SHIFT)) & USB_FSERRSTAT_PIDERR_MASK)

/*!
 * @brief USB_FS_ERRENB Register Bit Definition
 */

#define USB_FSERRENB_BTSERR_SHIFT               (7)
#define USB_FSERRENB_BTSERR_MASK                (0x1U << USB_FSERRENB_BTSERR_SHIFT)
#define USB_FSERRENB_BTSERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_BTSERR_SHIFT)) & USB_FSERRENB_BTSERR_MASK)

#define USB_FSERRENB_DMAERR_SHIFT               (5)
#define USB_FSERRENB_DMAERR_MASK                (0x1U << USB_FSERRENB_DMAERR_SHIFT)
#define USB_FSERRENB_DMAERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_DMAERR_SHIFT)) & USB_FSERRENB_DMAERR_MASK)

#define USB_FSERRENB_BTOERR_SHIFT               (4)
#define USB_FSERRENB_BTOERR_MASK                (0x1U << USB_FSERRENB_BTOERR_SHIFT)
#define USB_FSERRENB_BTOERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_BTOERR_SHIFT)) & USB_FSERRENB_BTOERR_MASK)

#define USB_FSERRENB_DFN8_SHIFT                 (3)
#define USB_FSERRENB_DFN8_MASK                  (0x1U << USB_FSERRENB_DFN8_SHIFT)
#define USB_FSERRENB_DFN8(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_DFN8_SHIFT)) & USB_FSERRENB_DFN8_MASK)

#define USB_FSERRENB_CRC16_SHIFT                (2)
#define USB_FSERRENB_CRC16_MASK                 (0x1U << USB_FSERRENB_CRC16_SHIFT)
#define USB_FSERRENB_CRC16(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_CRC16_SHIFT)) & USB_FSERRENB_CRC16_MASK)

#define USB_FSERRENB_CRC5EOF_SHIFT              (1)
#define USB_FSERRENB_CRC5EOF_MASK               (0x1U << USB_FSERRENB_CRC5EOF_SHIFT)
#define USB_FSERRENB_CRC5EOF(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_CRC5EOF_SHIFT)) & USB_FSERRENB_CRC5EOF_MASK)

#define USB_FSERRENB_PIDERR_SHIFT               (0)
#define USB_FSERRENB_PIDERR_MASK                (0x1U << USB_FSERRENB_PIDERR_SHIFT)
#define USB_FSERRENB_PIDERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_PIDERR_SHIFT)) & USB_FSERRENB_PIDERR_MASK)

/*!
 * @brief USB_FS_STAT Register Bit Definition
 */

#define USB_FSSTAT_ENDP_SHIFT                   (4)
#define USB_FSSTAT_ENDP_MASK                    (0xFU << USB_FSSTAT_ENDP_SHIFT)
#define USB_FSSTAT_ENDP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_ENDP_SHIFT)) & USB_FSSTAT_ENDP_MASK)

#define USB_FSSTAT_TX_SHIFT                     (3)
#define USB_FSSTAT_TX_MASK                      (0x1U << USB_FSSTAT_TX_SHIFT)
#define USB_FSSTAT_TX(x)                        (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_TX_SHIFT)) & USB_FSSTAT_TX_MASK)

#define USB_FSSTAT_ODD_SHIFT                    (2)
#define USB_FSSTAT_ODD_MASK                     (0x1U << USB_FSSTAT_ODD_SHIFT)
#define USB_FSSTAT_ODD(x)                       (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_ODD_SHIFT)) & USB_FSSTAT_ODD_MASK)

/*!
 * @brief USB_FS_CTL Register Bit Definition
 */

#define USB_FSCTL_JSTATE_SHIFT                  (7)
#define USB_FSCTL_JSTATE_MASK                   (0x1U << USB_FSCTL_JSTATE_SHIFT)
#define USB_FSCTL_JSTATE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_JSTATE_SHIFT)) & USB_FSCTL_JSTATE_MASK)

#define USB_FSCTL_SE0_SHIFT                     (6)
#define USB_FSCTL_SE0_MASK                      (0x1U << USB_FSCTL_SE0_SHIFT)
#define USB_FSCTL_SE0(x)                        (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_SE0_SHIFT)) & USB_FSCTL_SE0_MASK)

#define USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT     (5)
#define USB_FSCTL_TXDSUSPENDTOKENBUSY_MASK      (0x1U << USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT)
#define USB_FSCTL_TXDSUSPENDTOKENBUSY(x)        (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT)) & USB_FSCTL_TXDSUSPENDTOKENBUSY_MASK)

#define USB_FSCTL_RESUME_SHIFT                  (2)
#define USB_FSCTL_RESUME_MASK                   (0x1U << USB_FSCTL_RESUME_SHIFT)
#define USB_FSCTL_RESUME(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_RESUME_SHIFT)) & USB_FSCTL_RESUME_MASK)

#define USB_FSCTL_ODDRST_SHIFT                  (1)
#define USB_FSCTL_ODDRST_MASK                   (0x1U << USB_FSCTL_ODDRST_SHIFT)
#define USB_FSCTL_ODDRST(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_ODDRST_SHIFT)) & USB_FSCTL_ODDRST_MASK)

#define USB_FSCTL_USBEN_SHIFT                   (0)
#define USB_FSCTL_USBEN_MASK                    (0x1U << USB_FSCTL_USBEN_SHIFT)
#define USB_FSCTL_USBEN(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_USBEN_SHIFT)) & USB_FSCTL_USBEN_MASK)

/*!
 * @brief USB_FS_ADDR Register Bit Definition
 */

#define USB_FSADDR_ADDR_SHIFT                   (0)
#define USB_FSADDR_ADDR_MASK                    (0x7FU << USB_FSADDR_ADDR_SHIFT)
#define USB_FSADDR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSADDR_ADDR_SHIFT)) & USB_FSADDR_ADDR_MASK)

/*!
 * @brief USB_FS_BDTPAGE1 Register Bit Definition
 */

#define USB_FSBDTPAGE1_BDTBA_SHIFT              (1)
#define USB_FSBDTPAGE1_BDTBA_MASK               (0x7FU << USB_FSBDTPAGE1_BDTBA_SHIFT)
#define USB_FSBDTPAGE1_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE1_BDTBA_SHIFT)) & USB_FSBDTPAGE1_BDTBA_MASK)

/*!
 * @brief USB_FS_FRMNUML Register Bit Definition
 */

#define USB_FSFRMNUML_FRM_SHIFT                 (0)
#define USB_FSFRMNUML_FRM_MASK                  (0xFFU << USB_FSFRMNUML_FRM_SHIFT)
#define USB_FSFRMNUML_FRM(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSFRMNUML_FRM_SHIFT)) & USB_FSFRMNUML_FRM_MASK)

/*!
 * @brief USB_FS_FRMNUMH Register Bit Definition
 */

#define USB_FSFRMNUMH_FRM_SHIFT                 (0)
#define USB_FSFRMNUMH_FRM_MASK                  (0x7U << USB_FSFRMNUMH_FRM_SHIFT)
#define USB_FSFRMNUMH_FRM(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSFRMNUMH_FRM_SHIFT)) & USB_FSFRMNUMH_FRM_MASK)

/*!
 * @brief USB_FS_BDTPAGE2 Register Bit Definition
 */

#define USB_FSBDTPAGE2_BDTBA_SHIFT              (0)
#define USB_FSBDTPAGE2_BDTBA_MASK               (0xFFU << USB_FSBDTPAGE2_BDTBA_SHIFT)
#define USB_FSBDTPAGE2_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE2_BDTBA_SHIFT)) & USB_FSBDTPAGE2_BDTBA_MASK)

/*!
 * @brief USB_FS_BDTPAGE3 Register Bit Definition
 */

#define USB_FSBDTPAGE3_BDTBA_SHIFT              (0)
#define USB_FSBDTPAGE3_BDTBA_MASK               (0xFFU << USB_FSBDTPAGE3_BDTBA_SHIFT)
#define USB_FSBDTPAGE3_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE3_BDTBA_SHIFT)) & USB_FSBDTPAGE3_BDTBA_MASK)

/*!
 * @brief USB_FS_EPCTL Register Bit Definition
 */

#define USB_FSEPCTL_EPCTLDIS_SHIFT              (4)
#define USB_FSEPCTL_EPCTLDIS_MASK               (0x1U << USB_FSEPCTL_EPCTLDIS_SHIFT)
#define USB_FSEPCTL_EPCTLDIS(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPCTLDIS_SHIFT)) & USB_FSEPCTL_EPCTLDIS_MASK)

#define USB_FSEPCTL_EPRXEN_SHIFT                (3)
#define USB_FSEPCTL_EPRXEN_MASK                 (0x1U << USB_FSEPCTL_EPRXEN_SHIFT)
#define USB_FSEPCTL_EPRXEN(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPRXEN_SHIFT)) & USB_FSEPCTL_EPRXEN_MASK)

#define USB_FSEPCTL_EPTXEN_SHIFT                (2)
#define USB_FSEPCTL_EPTXEN_MASK                 (0x1U << USB_FSEPCTL_EPTXEN_SHIFT)
#define USB_FSEPCTL_EPTXEN(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPTXEN_SHIFT)) & USB_FSEPCTL_EPTXEN_MASK)

#define USB_FSEPCTL_EPSTALL_SHIFT               (1)
#define USB_FSEPCTL_EPSTALL_MASK                (0x1U << USB_FSEPCTL_EPSTALL_SHIFT)
#define USB_FSEPCTL_EPSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPSTALL_SHIFT)) & USB_FSEPCTL_EPSTALL_MASK)

#define USB_FSEPCTL_EPHSHK_SHIFT                (0)
#define USB_FSEPCTL_EPHSHK_MASK                 (0x1U << USB_FSEPCTL_EPHSHK_SHIFT)
#define USB_FSEPCTL_EPHSHK(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPHSHK_SHIFT)) & USB_FSEPCTL_EPHSHK_MASK)

/*!
 * @brief USB_FS_USBCTRL Register Bit Definition
 */

#define USB_FSUSBCTRL_SUSPE_SHIFT               (7)
#define USB_FSUSBCTRL_SUSPE_MASK                (0x1U << USB_FSUSBCTRL_SUSPE_SHIFT)
#define USB_FSUSBCTRL_SUSPE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSUSBCTRL_SUSPE_SHIFT)) & USB_FSUSBCTRL_SUSPE_MASK)

/*!
 * @}
 */ /* end of group USB_Register_Masks */
/******************************************************************************
 *USB Instance
*******************************************************************************/

#define USB                  ((USB_Type*)USB_FS_BASE)

/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */



/*!
 * @addtogroup WWDG_Peripheral_Access_Layer WWDG Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * WWDG Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR;                                                           ///< Control register                             offset: 0x00
    __IO uint32_t CFGR;                                                         ///< Configuration register                       offset: 0x04
    __IO uint32_t SR;                                                           ///< Status register                              offset: 0x08
} WWDG_Type;

/*******************************************************************************
 * WWDG Type
 ******************************************************************************/

/*!
 * @addtogroup WWDG_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief WWDG_CR Register Bit Definition
 */

#define WWDG_CR_WDGA_SHIFT                      (7)
#define WWDG_CR_WDGA_MASK                       (0x1U << WWDG_CR_WDGA_SHIFT)
#define WWDG_CR_WDGA(x)                         (((uint32_t)(((uint32_t)(x)) << WWDG_CR_WDGA_SHIFT)) & WWDG_CR_WDGA_MASK)

#define WWDG_CR_T_SHIFT                         (0)
#define WWDG_CR_T_MASK                          (0x7FU << WWDG_CR_T_SHIFT)
#define WWDG_CR_T(x)                            (((uint32_t)(((uint32_t)(x)) << WWDG_CR_T_SHIFT)) & WWDG_CR_T_MASK)

/*!
 * @brief WWDG_CFGR Register Bit Definition
 */

#define WWDG_CFGR_EWI_SHIFT                     (9)
#define WWDG_CFGR_EWI_MASK                      (0x1U << WWDG_CFGR_EWI_SHIFT)
#define WWDG_CFGR_EWI(x)                        (((uint32_t)(((uint32_t)(x)) << WWDG_CFGR_EWI_SHIFT)) & WWDG_CFGR_EWI_MASK)

#define WWDG_CFGR_WDGTB_SHIFT                   (7)
#define WWDG_CFGR_WDGTB_MASK                    (0x3U << WWDG_CFGR_WDGTB_SHIFT)
#define WWDG_CFGR_WDGTB(x)                      (((uint32_t)(((uint32_t)(x)) << WWDG_CFGR_WDGTB_SHIFT)) & WWDG_CFGR_WDGTB_MASK)

#define WWDG_CFGR_W_SHIFT                       (0)
#define WWDG_CFGR_W_MASK                        (0x7FU << WWDG_CFGR_W_SHIFT)
#define WWDG_CFGR_W(x)                          (((uint32_t)(((uint32_t)(x)) << WWDG_CFGR_W_SHIFT)) & WWDG_CFGR_W_MASK)

/*!
 * @brief WWDG_SR Register Bit Definition
 */

#define WWDG_SR_EWIF_SHIFT                      (0)
#define WWDG_SR_EWIF_MASK                       (0x1U << WWDG_SR_EWIF_SHIFT)
#define WWDG_SR_EWIF(x)                         (((uint32_t)(((uint32_t)(x)) << WWDG_SR_EWIF_SHIFT)) & WWDG_SR_EWIF_MASK)

/*!
 * @}
 */ /* end of group WWDG_Register_Masks */
/******************************************************************************
 *WWDG Instance
*******************************************************************************/

#define WWDG                 ((WWDG_Type*)WWDG_BASE)

/*!
 * @}
 */ /* end of group WWDG_Peripheral_Access_Layer */



#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

#endif /* __MM32F0163D_H__ */