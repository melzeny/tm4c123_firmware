/*
 * Port_hw.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_
#define E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_

#include "../utils/STD_Types.h"
#include "../utils/Bit_Math.h"

/*===========================================================*
 * NVIC REGISTERS                                            *
 *========================================================== */

#define NVIC_REG    (*((volatile NVIC_TagType*)0xE000E100))

typedef struct
{
    uint32 B0:1;
    uint32 B1:1;
    uint32 B2:1;
    uint32 B3:1;
    uint32 B4:1;
    uint32 B5:1;
    uint32 B6:1;
    uint32 B7:1;
    uint32 B8:1;
    uint32 B9:1;
    uint32 B10:1;
    uint32 B11:1;
    uint32 B12:1;
    uint32 B13:1;
    uint32 B14:1;
    uint32 B15:1;
    uint32 B16:1;
    uint32 B17:1;
    uint32 B18:1;
    uint32 B19:1;
    uint32 B20:1;
    uint32 B21:1;
    uint32 B22:1;
    uint32 B23:1;
    uint32 B24:1;
    uint32 B25:1;
    uint32 B26:1;
    uint32 B27:1;
    uint32 B28:1;
    uint32 B29:1;
    uint32 B30:1;
    uint32 B31:1;
}bit_field_Type;


typedef struct
{
    bit_field_Type EN0 ;
    bit_field_Type EN1 ;
    bit_field_Type EN2 ;
    bit_field_Type EN3 ;
    bit_field_Type EN4 ;
}  NVIC_TagType;

/*===========================================================*
 * FLASH REGISTERS                                           *
 *========================================================== */
typedef union
{
    uint32 R;
    struct
    {
        uint32 Access               :1;
        uint32 Prog                 :1;
        uint32 EEPROM               :1;
        uint32                      :6;
        uint32 VoltErr              :1;
        uint32 InvalidData          :1;
        uint32 EraseVerErr          :1;
        uint32                      :1;
        uint32 ProgVerErr           :1;
        uint32                      :18;
    }B;
}FLASH_INT_TAG;


#define FLASH_FMA_R             (*((volatile uint32 *)0x400FD000))
#define FLASH_FMD_R             (*((volatile uint32 *)0x400FD004))
#define FLASH_FMC_R             (*((volatile uint32 *)0x400FD008))
#define FLASH_FCRIS             (*((volatile FLASH_INT_TAG *)0x400FD00C))
#define FLASH_FCIM_R            (*((volatile uint32 *)0x400FD010))
#define FLASH_FCMISC            (*((volatile FLASH_INT_TAG *)0x400FD014))
#define FLASH_FMC2_R            (*((volatile uint32 *)0x400FD020))
#define FLASH_FWBVAL_R          (*((volatile uint32 *)0x400FD030))
#define FLASH_FWBN_R            (*((volatile uint32 *)0x400FD100))
#define FLASH_FSIZE_R           (*((volatile uint32 *)0x400FDFC0))
#define FLASH_SSIZE_R           (*((volatile uint32 *)0x400FDFC4))
#define FLASH_ROMSWMAP_R        (*((volatile uint32 *)0x400FDFCC))
#define FLASH_RMCTL_R           (*((volatile uint32 *)0x400FE0F0))
#define FLASH_BOOTCFG_R         (*((volatile uint32 *)0x400FE1D0))
#define FLASH_USERREG0_R        (*((volatile uint32 *)0x400FE1E0))
#define FLASH_USERREG1_R        (*((volatile uint32 *)0x400FE1E4))
#define FLASH_USERREG2_R        (*((volatile uint32 *)0x400FE1E8))
#define FLASH_USERREG3_R        (*((volatile uint32 *)0x400FE1EC))
#define FLASH_FMPRE0_R          (*((volatile uint32 *)0x400FE200))
#define FLASH_FMPRE1_R          (*((volatile uint32 *)0x400FE204))
#define FLASH_FMPRE2_R          (*((volatile uint32 *)0x400FE208))
#define FLASH_FMPRE3_R          (*((volatile uint32 *)0x400FE20C))
#define FLASH_FMPPE0_R          (*((volatile uint32 *)0x400FE400))
#define FLASH_FMPPE1_R          (*((volatile uint32 *)0x400FE404))
#define FLASH_FMPPE2_R          (*((volatile uint32 *)0x400FE408))
#define FLASH_FMPPE3_R          (*((volatile uint32 *)0x400FE40C))

/*===========================================================*
 * GPIO REGISTERS                                            *
 *========================================================== */
typedef struct
{
    uint32 GPIODATA    ;
    uint32 GPIODIR     ;
    uint32 GPIOIS      ;
    uint32 GPIOIBE     ;
    uint32 GPIOIEV     ;
    uint32 GPIOIM      ;
    uint32 GPIORIS     ;
    uint32 GPIOMIS     ;
    uint32 GPIOICR     ;
    uint32 GPIOAFSEL   ; /*offset : 0x420 -> 424 */

    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R    ; /*offset : 0x500 */
    uint32 GPIODR4R    ;
    uint32 GPIODR8R    ;
    uint32 GPIOODR     ;
    uint32 GPIOPUR     ;
    uint32 GPIOPDR     ;
    uint32 GPIOSLR     ;
    uint32 GPIODEN     ;
    uint32 GPIOLOCK    ;
    uint32 GPIOCR      ;
    uint32 GPIOAMSEL   ;
    uint32 GPIOPCTL    ;
    uint32 GPIOADCCTL  ;
    uint32 GPIODMACTL  ;
}PORT_RegType;

#define PORTA_REG     (*((volatile PORT_RegType*)0x400043FC))
#define PORTB_REG     (*((volatile PORT_RegType*)0x400053FC))
#define PORTC_REG     (*((volatile PORT_RegType*)0x400063FC))
#define PORTD_REG     (*((volatile PORT_RegType*)0x400073FC))
#define PORTE_REG     (*((volatile PORT_RegType*)0x400243FC))
#define PORTF_REG     (*((volatile PORT_RegType*)0x400253FC))

/*===========================================================*
 * RCC REGISTERS                                             *
 *========================================================== */
typedef struct
{
    uint32 R0:1;
    uint32 R1:1;
    uint32 R2:1;
    uint32 R3:1;
    uint32 R4:1;
    uint32 R5:1;
    uint32 R6:1;
    uint32 R7:1;
}RCGC_TagType;

#define RCGCGPIO_REG    (*((volatile RCGC_TagType*)0x400FE608))
#define RCGCUART_REG    (*((volatile RCGC_TagType*)0x400FE618))
#define RCGCSSI_REG     (*((volatile RCGC_TagType*)0x400FE61C))
#define RCGCI2C_REG     (*((volatile RCGC_TagType*)0x400FE620))



/*===========================================================*
 * UART REGISTERS                                            *
 *========================================================== */

typedef union
{
    uint32 R;
    struct
    {
        uint32 UARTEN       :1;
        uint32 SIREN        :1;
        uint32 SIRLP        :1;
        uint32 SMART        :1;
        uint32 EOT          :1;
        uint32 HSE          :1;
        uint32              :1;
        uint32 LBE          :1;
        uint32 TXE          :1;
        uint32 RXE          :1;
        uint32              :1;
        uint32 RTS          :1;
        uint32              :2;
        uint32 RTSEN        :1;
        uint32 CTSEN        :1;
        uint32              :16;
    }B;
}UART_CTL_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 BRK        :1;
        uint32 PEN        :1;
        uint32 EPS        :1;
        uint32 STP2       :1;
        uint32 FEN        :1;
        uint32 WLEN       :2;
        uint32 SPS        :1;
        uint32            :24;
    }B;
}UART_LCRH_TAG;
typedef union
{
    uint32 R;
    struct
    {
        uint32 RXDMAE        :1;
        uint32 TXDMAE        :1;
        uint32 DMAERR        :1;
        uint32               :29;
    }B;
}UART_DMACTL_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32            :1;
        uint32 CTS        :1;
        uint32            :2;
        uint32 RX         :1;
        uint32 TX         :1;
        uint32 RT         :1;
        uint32 FE         :1;
        uint32 PE         :1;
        uint32 BE         :1;
        uint32 OE         :1;
        uint32            :1;
        uint32 _9BIT      :1;
        uint32            :19;
    }B;
}UART_INTERRUPT_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 CTS        :1;
        uint32            :2;
        uint32 BUSY       :1;
        uint32 RXFE       :1;
        uint32 TXFF       :1;
        uint32 RXFF       :1;
        uint32 TXFE       :1;
        uint32            :24;
    }B;
}UART_FR_TAG;


typedef struct
{
    uint32 DR               ;
    uint32 ECR              ;
    UART_FR_TAG FR          ;
    uint8 reserved[0x4]     ;
    uint32 ILPR             ;
    uint32 IBRD             ;
    uint32 FBRD             ;
    UART_LCRH_TAG LCRH      ;
    UART_CTL_TAG CTL        ;
    uint32 IFLS             ;
    UART_INTERRUPT_TAG IM  ;
    UART_INTERRUPT_TAG RIS  ;
    UART_INTERRUPT_TAG MIS  ;
    UART_INTERRUPT_TAG ICR  ;
    UART_DMACTL_TAG DMACTL  ;
    uint8 reserved_2[0x58]  ;
    uint32 U9BITADDR        ;
    uint32 U9BITAMASK       ;
    uint8 reserved_3[0xF14] ;
    uint32 PP               ;
    uint8 reserved_4[0x4]   ;
    uint32 CC               ;
}UART_RegType;

#define UART1_DR_R                                 (*((volatile uint32 *)0x4000D000))
#define UART1_RSR_R                                (*((volatile uint32 *)0x4000D004))
#define UART1_ECR_R                                (*((volatile uint32 *)0x4000D004))
#define UART1_FR                                   (*((volatile UART_FR_TAG *)0x4000D018))
#define UART1_ILPR_R                               (*((volatile uint32 *)0x4000D020))
#define UART1_IBRD_R                               (*((volatile uint32 *)0x4000D024))
#define UART1_FBRD_R                               (*((volatile uint32 *)0x4000D028))
#define UART1_LCRH                                 (*((volatile UART_LCRH_TAG *)0x4000D02C))
#define UART1_CTL                                  (*((volatile UART_CTL_TAG *)0x4000D030))
#define UART1_IFLS_R                               (*((volatile uint32 *)0x4000D034))
#define UART1_IM                                   (*((volatile UART_INTERRUPT_TAG *)0x4000D038))
#define UART1_RIS                                  (*((volatile UART_INTERRUPT_TAG *)0x4000D03C))
#define UART1_MIS                                  (*((volatile UART_INTERRUPT_TAG *)0x4000D040))
#define UART1_ICR                                  (*((volatile UART_INTERRUPT_TAG *)0x4000D044))
#define UART1_DMACTL                               (*((volatile UART_DMACTL_TAG *)0x4000D048))
#define UART1_9BITADDR_R                           (*((volatile uint32 *)0x4000D0A4))
#define UART1_9BITAMASK_R                          (*((volatile uint32 *)0x4000D0A8))
#define UART1_PP_R                                 (*((volatile uint32 *)0x4000DFC0))
#define UART1_CC_R                                 (*((volatile uint32 *)0x4000DFC8))


#define UARTDR_OFFSET                              0x000
#define UARTRSR_OFFSET                             0x004
#define UARTECR_OFFSET                             0x004
#define UARTFR_OFFSET                              0x018
#define UARTILPR_OFFSET                            0x020
#define UARTIBRD_OFFSET                            0x024
#define UARTFBRD_OFFSET                            0x028
#define UARTLCRH_OFFSET                            0x02C
#define UARTCTL_OFFSET                             0x030
#define UARTIFLS_OFFSET                            0x034
#define UARTIM_OFFSET                              0x038
#define UARTRIS_OFFSET                             0x03C
#define UARTMIS_OFFSET                             0x040
#define UARTICR_OFFSET                             0x044
#define UARTDMACTL_OFFSET                          0x048
#define UART9BITADDR_OFFSET                        0x0A4
#define UART9BITAMASK_OFFSET                       0x0A8
#define UARTPP_OFFSET                              0xFC0
#define UARTCC_OFFSET                              0xFC8

#define UARTDR(UART_BASE_ADDR)                     GET_REG(UART_BASE_ADDR, uint32, UARTDR_OFFSET)
#define UARTRSR(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, uint32, UARTRSR_OFFSET)
#define UARTECR(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, uint32, UARTECR_OFFSET)
#define UARTFR(UART_BASE_ADDR)                     GET_REG(UART_BASE_ADDR, UART_FR_TAG, UARTFR_OFFSET)
#define UARTILPR(UART_BASE_ADDR)                   GET_REG(UART_BASE_ADDR, uint32, UARTILPR_OFFSET)
#define UARTIBRD(UART_BASE_ADDR)                   GET_REG(UART_BASE_ADDR, uint32, UARTIBRD_OFFSET)
#define UARTFBRD(UART_BASE_ADDR)                   GET_REG(UART_BASE_ADDR, uint32, UARTFBRD_OFFSET)
#define UARTLCRH(UART_BASE_ADDR)                   GET_REG(UART_BASE_ADDR, UART_LCRH_TAG, UARTLCRH_OFFSET)
#define UARTCTL(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, UART_CTL_TAG, UARTCTL_OFFSET)
#define UARTIFLS(UART_BASE_ADDR)                   GET_REG(UART_BASE_ADDR, uint32, UARTIFLS_OFFSET)
#define UARTIM(UART_BASE_ADDR)                     GET_REG(UART_BASE_ADDR, UART_INTERRUPT_TAG, UARTIM_OFFSET)
#define UARTRIS(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, UART_INTERRUPT_TAG, UARTRIS_OFFSET)
#define UARTMIS(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, UART_INTERRUPT_TAG, UARTMIS_OFFSET)
#define UARTICR(UART_BASE_ADDR)                    GET_REG(UART_BASE_ADDR, UART_INTERRUPT_TAG, UARTICR_OFFSET)
#define UARTDMACTL(UART_BASE_ADDR)                 GET_REG(UART_BASE_ADDR, UART_DMACTL_TAG, UARTDMACTL_OFFSET)
#define UART9BITADDR(UART_BASE_ADDR)               GET_REG(UART_BASE_ADDR, uint32, UART9BITADDR_OFFSET)
#define UART9BITAMASK(UART_BASE_ADDR)              GET_REG(UART_BASE_ADDR, uint32, UART9BITAMASK_OFFSET)
#define UARTPP(UART_BASE_ADDR)                     GET_REG(UART_BASE_ADDR, uint32, UARTPP_OFFSET)
#define UARTCC(UART_BASE_ADDR)                     GET_REG(UART_BASE_ADDR, uint32, UARTCC_OFFSET)

#define UART0_BASE_ADDR                            0x4000C000
#define UART1_BASE_ADDR                            0x4000D000
#define UART2_BASE_ADDR                            0x4000E000
#define UART3_BASE_ADDR                            0x4000F000
#define UART4_BASE_ADDR                            0x40010000
#define UART5_BASE_ADDR                            0x40011000
#define UART6_BASE_ADDR                            0x40012000
#define UART7_BASE_ADDR                            0x40013000

/*===========================================================*
 * SPI REGISTERS                                             *
 *========================================================== */

typedef union
{
    uint32 R;
    struct
    {
        uint32 DSS        :4        ;
        uint32 FRF        :2        ;
        uint32 SPO        :1        ;
        uint32 SPH        :1        ;
        uint32 SCR        :8        ;
        uint32            :16       ;

    }B;
}SPI_SSICR0_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 LBM        :1        ;
        uint32 SSE        :1        ;
        uint32 MS         :1        ;
        uint32            :1        ;
        uint32 EOT        :1        ;
        uint32            :27       ;

    }B;
}SPI_SSICR1_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32 TFE        :1        ;
        uint32 TNF        :1        ;
        uint32 RNE        :1        ;
        uint32 RFF        :1        ;
        uint32 BSY        :1        ;
        uint32            :27       ;

    }B;
}SPI_SSISR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORIM        :1      ;
        uint32 RTIM         :1      ;
        uint32 RXIM         :1      ;
        uint32 TXIM         :1      ;
        uint32              :28     ;

    }B;
}SPI_SSIIM_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORRIS      :1       ;
        uint32 RTRIS       :1       ;
        uint32 RXRIS       :1       ;
        uint32 TXRIS       :1       ;
        uint32             :28      ;

    }B;
}SPI_SSIRIS_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORMIS       :1      ;
        uint32 RTMIS        :1      ;
        uint32 RXMIS        :1      ;
        uint32 TXMIS        :1      ;
        uint32              :28     ;

    }B;
}SPI_SSIMIS_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORIC        :1      ;
        uint32 RTIC         :1      ;
        uint32              :30     ;

    }B;
}SPI_SSIICR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RXDMAE      :1       ;
        uint32 TXDMAE      :1       ;
        uint32             :30      ;

    }B;
}SPI_SSIDMACTL_TAG;

#define SSICR0_OFFSET                       0x000
#define SSICR1_OFFSET                       0x004
#define SSIDR_OFFSET                        0x008
#define SSISR_OFFSET                        0x00C
#define SSICPSR_OFFSET                      0x010
#define SSIIM_OFFSET                        0x014
#define SSIRIS_OFFSET                       0x018
#define SSIMIS_OFFSET                       0x01C
#define SSIICR_OFFSET                       0x020
#define SSIDMACTL_OFFSET                    0x024
#define SSICC_OFFSET                        0xFC8

#define SPI0_BASE_ADDR                      0x40008000
#define SPI1_BASE_ADDR                      0x40009000
#define SPI2_BASE_ADDR                      0x4000A000
#define SPI3_BASE_ADDR                      0x4000B000

#define SSICR0(SPI_BASE_ADDR)               GET_REG(SPI_BASE_ADDR, SPI_SSICR0_TAG, SSICR0_OFFSET)
#define SSICR1(SPI_BASE_ADDR)               GET_REG(SPI_BASE_ADDR, SPI_SSICR1_TAG, SSICR1_OFFSET)
#define SSIDR(SPI_BASE_ADDR)                GET_REG(SPI_BASE_ADDR, uint32, SSIDR_OFFSET)
#define SSISR(SPI_BASE_ADDR)                GET_REG(SPI_BASE_ADDR, SPI_SSISR_TAG, SSISR_OFFSET)
#define SSICPSR(SPI_BASE_ADDR)              GET_REG(SPI_BASE_ADDR, uint32, SSICPSR_OFFSET)
#define SSIIM(SPI_BASE_ADDR)                GET_REG(SPI_BASE_ADDR, SPI_SSIIM_TAG, SSIIM_OFFSET)
#define SSIRIS(SPI_BASE_ADDR)               GET_REG(SPI_BASE_ADDR, SPI_SSIRIS_TAG, SSIRIS_OFFSET)
#define SSIMIS(SPI_BASE_ADDR)               GET_REG(SPI_BASE_ADDR, SPI_SSIMIS_TAG, SSIMIS_OFFSET)
#define SSIICR(SPI_BASE_ADDR)               GET_REG(SPI_BASE_ADDR, SPI_SSIICR_TAG, SSIICR_OFFSET)
#define SSIDMACTL(SPI_BASE_ADDR)            GET_REG(SPI_BASE_ADDR, SPI_SSIDMACTL_TAG, SSIDMACTL_OFFSET)
#define SSICC(SPI_BASE_ADDR)                GET_REG(SPI_BASE_ADDR, uint32, SSICC_OFFSET)


/*===========================================================*
 * I2C REGISTERS                                             *
 *========================================================== */

/*Register 1 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 RS      :1 ;
        uint32 SA      :7;
        uint32         :24;

    }B;
}I2C_I2CMSA_TAG;

/*Register 2 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 BUSY          :1;
        uint32 ERROR         :1;
        uint32 ADRACK        :1;
        uint32 DATACK        :1;
        uint32 ARBLST        :1;
        uint32 IDLE          :1;
        uint32 BUSBSY        :1;
        uint32 CLKTO         :1;
        uint32               :24;

    }B;
}I2C_I2CMCS_Read;


typedef union
{
    uint32 R;
    struct
    {
        uint32 RUN            :1;
        uint32 START          :1;
        uint32 STOP           :1;
        uint32 ACK            :1;
        uint32 HS             :1;
        uint32                :27;

    }B;
}I2C_I2CMCS_Write;


/*Register 3 */

typedef union
{
    uint32 R;
    struct
    {
    uint32 DATA          :8;
    uint32               :24;
    }B;
}I2C_I2CMDR_TAG;

/*Register 4 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 TPR          :7;
        uint32 HS           :1;
        uint32              :24;

    }B;
}I2C_I2CMTPR_TAG;

/*Register 5*/
typedef union
{
    uint32 R;
    struct
    {
        uint32 IM            :1;
        uint32 CLKIM         :1;
        uint32               :30;

    }B;
}I2C_I2CMIMR_TAG;

/*Register 6 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 RIS            :1;
        uint32 CLKRIS         :1;
        uint32                :30;

    }B;
}I2C_I2CMRIS_TAG;


/*Register 7 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 MIS           :1;
        uint32 CLKMIS        :1;
        uint32               :30;

    }B;
}I2C_I2CMMIS_TAG;

/*Register 8 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 IC           :1;
        uint32 CLKIC        :1;
        uint32              :30;

    }B;
}I2C_I2CMICR_TAG;


/*Register 9 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 LPBK       :1;
        uint32 reserved   :3;
        uint32 MFE        :1;
        uint32 SFE        :1;
        uint32 GFE        :1;
        uint32            :25;

    }B;
}I2C_I2CMCR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 CNTL       :8;
        uint32            :24;

    }B;
}I2C_I2CMCLKOCNT_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 SCL       :1;
        uint32 SDA       :1;
        uint32           :30;

    }B;
}I2C_I2CMBMON_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32 reserved       :4;
        uint32 GFPW           :3;
        uint32                :25;

    }B;
}I2C_I2CMCR2_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32 OAR       :7;
        uint32           :25;

    }B;
}I2C_I2CSOAR_TAG;

/*Register 14 */
typedef union
{
    uint32 R;
    struct
    {
        uint32 RREQ       :1;
        uint32 TREQ       :1;
        uint32 FBR        :1;
        uint32 OAR2SEL    :1;
        uint32            :28;

    }B;
}I2C_I2CSCSR_Read;


typedef union
{
    uint32 R;
    struct
    {
        uint32 DA       :1;
        uint32          :31;

    }B;
}I2C_I2CSCSR_Write;

typedef union
{
    uint32 R;
    struct
    {
        uint32 DATA       :8;
        uint32            :24;

    }B;
}I2C_I2CSDR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 DATAIM       :1;
        uint32 STARTIM      :1;
        uint32 STOPIM       :1;
        uint32              :29;

    }B;
}I2C_I2CSIMR_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32 DATARIS       :1;
        uint32 STARTRIS      :1;
        uint32 STOPRIS       :1;
        uint32              :29;

    }B;
}I2C_I2CSRIS_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32 DATAMIS       :1;
        uint32 STARTMIS      :1;
        uint32 STOPMIS       :1;
        uint32              :29;

    }B;
}I2C_I2CSMIS_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 DATAIC       :1;
        uint32 STARTIC      :1;
        uint32 STOPIC       :1;
        uint32              :29;

    }B;
}I2C_I2CSICR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 OAR2        :7;
        uint32 OAR2EN      :1;
        uint32             :24;

    }B;
}I2C_I2CSOAR2_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 ACKOEN        :1;
        uint32 ACKOVAL       :1;
        uint32               :30;

    }B;
}I2C_I2CSACKCTL_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 HS        :1;
        uint32           :31;

    }B;
}I2C_I2CPP_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 HS        :1;
        uint32           :31;

    }B;
}I2C_I2CPC_TAG;




#define I2CMSA_OFFSET                              0x000
#define I2CMCS_OFFSET                              0x004
#define I2CMDR_OFFSET                              0x008
#define I2CMTPR_OFFSET                             0x00C
#define I2CMIMR_OFFSET                             0x010
#define I2CMRIS_OFFSET                             0x014
#define I2CMMIS_OFFSET                             0x018
#define I2CMICR_OFFSET                             0x01C
#define I2CMCR_OFFSET                              0x020
#define I2CMCLKOCNT_OFFSET                         0x024
#define I2CMBMON_OFFSET                            0x02C
#define I2CMCR2_OFFSET                             0x038
#define I2CSOAR_OFFSET                             0x800
#define I2CSCSR_OFFSET                             0x804
#define I2CSDR_OFFSET                              0x808
#define I2CSIMR_OFFSET                             0x80C
#define I2CSRIS_OFFSET                             0x810
#define I2CSMIS_OFFSET                             0x814
#define I2CSICR_OFFSET                             0x818
#define I2CSOAR2_OFFSET                            0x81C
#define I2CSACKCTL_OFFSET                          0x820
#define I2CPP_OFFSET                               0xFC0
#define I2CPC_OFFSET                               0xFC4

#define I2C_0_BASE_ADDRESS                         0x40020000
#define I2C_1_BASE_ADDRESS                         0x40021000
#define I2C_2_BASE_ADDRESS                         0x40022000
#define I2C_3_BASE_ADDRESS                         0x40023000

#define I2CMSA(I2C_BASE_ADDR)                      GET_REG(I2C_BASE_ADDR,I2C_I2CMSA_TAG, I2CMSA_OFFSET)
#define I2CMCS_Read(I2C_BASE_ADDR)                 GET_REG(I2C_BASE_ADDR, I2C_I2CMCS_Read, I2CMCS_OFFSET)
#define I2CMCS_Write(I2C_BASE_ADDR)                GET_REG(I2C_BASE_ADDR, I2C_I2CMCS_Write, I2CMCS_OFFSET)
#define I2CMDR(I2C_BASE_ADDR)                      GET_REG(I2C_BASE_ADDR, uint32, I2CMDR_OFFSET)
#define I2CMTPR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMTPR_OFFSET)
#define I2CMIMR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMIMR_OFFSET)
#define I2CMRIS(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMRIS_OFFSET)
#define I2CMMIS(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMMIS_OFFSET)
#define I2CMICR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMICR_OFFSET)
#define I2CMCR(I2C_BASE_ADDR)                      GET_REG(I2C_BASE_ADDR, I2C_I2CMCR_TAG, I2CMCR_OFFSET)
#define I2CMCLKOCNT(I2C_BASE_ADDR)                 GET_REG(I2C_BASE_ADDR, uint32, I2CMCLKOCNT_OFFSET)
#define I2CMBMON(I2C_BASE_ADDR)                    GET_REG(I2C_BASE_ADDR, uint32, I2CMBMON_OFFSET)
#define I2CMCR2(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CMCR2_OFFSET)
#define I2CSOAR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSOAR_OFFSET)
#define I2CSCSR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSCSR_OFFSET)
#define I2CSDR(I2C_BASE_ADDR)                      GET_REG(I2C_BASE_ADDR, uint32, I2CSDR_OFFSET)
#define I2CSIMR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSIMR_OFFSET)
#define I2CSRIS(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSRIS_OFFSET)
#define I2CSMIS(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSMIS_OFFSET)
#define I2CSICR(I2C_BASE_ADDR)                     GET_REG(I2C_BASE_ADDR, uint32, I2CSICR_OFFSET)
#define I2CSOAR2(I2C_BASE_ADDR)                    GET_REG(I2C_BASE_ADDR, uint32, I2CSOAR2_OFFSET)
#define I2CSACKCTL(I2C_BASE_ADDR)                 GET_REG(I2C_BASE_ADDR, uint32, I2CSACKCTL_OFFSET)
#define I2CPP(I2C_BASE_ADDR)                       GET_REG(I2C_BASE_ADDR, uint32, I2CPP_OFFSET)
#define I2CPC(I2C_BASE_ADDR)                       GET_REG(I2C_BASE_ADDR, uint32, I2CPC_OFFSET)


#endif /* E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_ */
