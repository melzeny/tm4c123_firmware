#ifndef SPI_TYPES_H
#define SPI_TYPES_H

#include "../../utils/Std_Types.h"

typedef enum
 {
	SPI_Ch_0,
	SPI_Ch_1,
	SPI_Ch_2,
	SPI_Ch_3, 
	SPI_MaxNumOfChannels	 
 }SPI_ChannelType;
 typedef enum
 {
	SPI_Status_Idle,
	SPI_Status_Busy 
 }SPI_StatusType;
 
 
 /* PRIVATE TYPES */
 #ifdef SPI_PRIVATE_CODE
#include "../../config/spi_cfg.h"
 typedef struct
 {
	uint8 TxIbuffer[SPI_MAX_TX_BUFFER_SIZE];
	uint8 RxIbuffer[SPI_MAX_RX_BUFFER_SIZE];
	uint8 TxIndex;
	uint8 RxIndex;
	SPI_StatusType Status;
	uint8 TxMsgSize;
 }SPI_ChannelParamStructType;
 
typedef uint8 SPI_ModeType;
#define SPI_Mode_Master		0
#define SPI_Mode_Slave		1

typedef uint32	SPI_BaudRateHzType;


typedef uint8 SPI_CLockPolarityType;
#define SPI_CLockPolarity_IdleLow				0
#define SPI_CLockPolarity_IdleHigh				1

typedef uint8 SPI_ClockphaseType;
#define SPI_CLockPhase_SampleFirstEdge			0
#define SPI_CLockPhase_SetupFirstEdge			1

typedef uint8 SPI_FrameFormatType;
#define SPI_FrameFormate_Ti						0
#define SPI_FrameFormate_FreeScale				1
#define SPI_FrameFormate_Microwire				2

typedef uint8 SPI_DataSizeType;

typedef struct
{
	SPI_ChannelType 		SPI_ChannelId       ;
	SPI_ModeType 			SPI_Mode            ;
	SPI_BaudRateHzType 		SPI_BaudRate_Hz     ;
	SPI_CLockPolarityType	SPI_CLockPolarity   ;
	SPI_ClockphaseType		SPI_Clockphase      ;
	SPI_FrameFormatType 	SPI_FrameFormat     ;
	SPI_DataSizeType		SPI_DataSize        ;
}SPI_CFGType;

#endif

#endif

