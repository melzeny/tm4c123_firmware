/*
 * spi_types.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_Spi_Spi_TYPES_H_
#define E15_ARM_REPO_MCAL_Spi_Spi_TYPES_H_

typedef enum
{
    Spi_Channel0,
    Spi_Channel1,
    Spi_Channel2,
    Spi_Channel3
}Spi_ChannelType;
typedef enum
{
    SPI_UNINIT,
    SPI_IDLE,
    SPI_BUSY
}Spi_StatusType;

/*========================================================*
 *      PRIVATE TYPES                                     *
 * =======================================================*/

#ifdef SPI_PRIVATE_CONFIG



typedef enum
{
    Spi_FrameFormate_FreeScale,
    Spi_FrameFormate_Ti,
    Spi_FrameFormate_Microwire
}Spi_FrameFormateType;


typedef enum
{

    Spi_NumberOfData_04_Bits = 0X3,
    Spi_NumberOfData_05_Bits,
    Spi_NumberOfData_06_Bits,
    Spi_NumberOfData_07_Bits,
    Spi_NumberOfData_08_Bits,
    Spi_NumberOfData_09_Bits,
    Spi_NumberOfData_10_Bits,
    Spi_NumberOfData_11_Bits,
    Spi_NumberOfData_12_Bits,
    Spi_NumberOfData_13_Bits,
    Spi_NumberOfData_14_Bits,
    Spi_NumberOfData_15_Bits,
    Spi_NumberOfData_16_Bits

}Spi_NumberOfDataType;

typedef enum
{
    Spi_OprMode_Master,
    Spi_OprMode_Slave

}Spi_OprModeType;


typedef enum
{
    Spi_ClockSource_SysClock,
    Spi_ClockSource_PIOSC = 0x5,

}Spi_ClockSourceType;
typedef enum
{
    Spi_DataCaptureClockEdge_First,
    Spi_DataCaptureClockEdge_Second,
}Spi_DataCaptureClockEdgeType;
typedef enum
{
    FIFOBasedInterrupt, /*interrupt indicates that the transmit FIFO is half full or less.*/
    EndOfTxInterrupt, /*The End of Transmit interrupt */
}Spi_TxIntType;
typedef struct
{
    Spi_ChannelType                 Spi_Channel;
    uint32                          CFG_BitRate;
    Spi_DataCaptureClockEdgeType    CFG_DataCaptureClockEdge;
    STD_levelType                   CFG_IdleCLockState;
    Spi_FrameFormateType            CFG_FrameFormat;
    Spi_NumberOfDataType            CFG_DataSize;
    Spi_OprModeType                 CFG_OprMode;
    STD_EnType                      CFG_LoopBack;
    STD_EnType                      CFG_DMA_Tx;
    STD_EnType                      CFG_DMA_Rx;
    Spi_ClockSourceType             CFG_ClockSource;
    Spi_TxIntType                   CFG_TxIntMode;
    STD_EnType                      CFG_Interrupt_RxOverRun;
    STD_EnType                      CFG_Interrupt_RxTimeout;
    STD_EnType                      CFG_Interrupt_Rxc;
    STD_EnType                      CFG_Interrupt_Txc;
}Spi_ConfigType;

typedef struct
{
    uint32 TxMsgSize;
    uint16 TxBuffer[Spi_TX_BUFFER_SIZE];
    uint32 TxBufferIndex;
    uint16 RxBuffer[Spi_RX_BUFFER_SIZE];
    uint32 RxBufferIndex;
    Spi_StatusType Status;
}Spi_ChannelParamType;

#endif /* ifdef Spi_DRIVER */

#endif /* E15_ARM_REPO_MCAL_Spi_Spi_TYPES_H_ */
