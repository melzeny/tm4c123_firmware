/*
 * i2c_types.h
 *
 *  Created on:
 *      Author: Sprins wave4
 */

#ifndef E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_
#define E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_

#include "../../utils/STD_types.h"

typedef enum
{
    I2C_Channel_0,
    I2C_Channel_1,
    I2C_Channel_2,
    I2C_Channel_3
}I2C_ChannelType;

typedef uint8   I2C_StatusType;
#define I2C_Status_Idle                 (uint8)0
#define I2C_Status_BUSY                 (uint8)1


typedef boolean  I2C_StopFrameEnType;

typedef enum
{
    I2C_Operation_Write,
    I2C_Operation_Read
}I2C_OperationType;

/**********************************
 * PRIVATE TYPES
 ******************************** */
#ifdef I2C_PRIVATE_CODE
#include "../../config/i2c_cfg.h"
typedef enum
{
    I2C_Mode_Master,
    I2C_Mode_Slave,
    I2C_Mode_Master_Slave,

}I2C_ModeType;

typedef enum
{
    I2C_SpeedMode_Standard,
    I2C_SpeedMode_Fast,
    I2C_SpeedMode_VeryFast,
    I2C_SpeedMode_HighSpeed
}I2C_SpeedModeType;

typedef struct
{
    I2C_ChannelType     I2C_ChannelId    ;
    uint32              I2C_BaudRate     ;
    I2C_ModeType        I2C_Mode         ;
    uint8               I2C_Sla          ;
    uint8               I2C_Alt_Sla      ;
    I2C_SpeedModeType   I2C_SpeedMode    ;
    boolean             I2C_TimeOutEn    ;
    boolean             I2C_LoopbackEn   ;
}I2C_CfgType;

typedef struct
{
  uint8 TxBuffer[MAX_TX_BUFFER_SIZE];
  uint8 RxBuffer[MAX_RX_BUFFER_SIZE];
  uint8 TxBufferIndex;
  uint8 RxBufferIndex;
  uint8 TxMsgSize;
  uint8 RxMsgSize;

}I2C_ChannelParamType;
#endif /* Private Code*/
#endif /* E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_ */
