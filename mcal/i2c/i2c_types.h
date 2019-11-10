/*
 * i2c_types.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_
#define E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_

#include "../../utils/STD_types.h"

typedef enum
{
    I2c_uiInit,
    I2c_idle,
    I2c_busy
}I2c_StatusType;

typedef enum
{
    I2c_Request_Write,
    I2c_Request_Read
}I2c_RequestType;


typedef enum
{
    I2c_Channel0,
    I2c_Channel1,
    I2c_Channel2,
    I2c_Channel3,
}I2c_ChannelType;

#ifdef I2C_PRIVATE_CONFIG
typedef enum
{
    GlitchFilter_PW_Bypass,
    GlitchFilter_PW_01_Clock,
    GlitchFilter_PW_02_Clocks,
    GlitchFilter_PW_03_Clocks,
    GlitchFilter_PW_04_Clocks,
    GlitchFilter_PW_08_Clocks,
    GlitchFilter_PW_16_Clocks,
    GlitchFilter_PW_31_Clocks,

}I2c_GlitchFilterPwType;

typedef struct
{
    I2c_ChannelType                 Channel;
    uint32                          ClockRate;
    STD_EnType                      MasterHighSpeed;
    STD_EnType                      ClockHighSpeed;
    STD_EnType                      AutoDataAck;
    STD_EnType                      GlitchFilter;
    I2c_GlitchFilterPwType          GlitchFilter_PulseWidth;
    STD_EnType                      LoopbackTest;
    STD_EnType                      FIfo;
    STD_EnType                      Interrupt_Master;
    STD_EnType                      Interrupt_ClkTimeout;
}I2c_MasterConfigType;

typedef struct
{
    I2c_ChannelType                 I2cChannel;
    uint32                          SlaveAddr;
    STD_EnType                      ALtSlaveAdrr_EN;
    uint32                          ALtSlaveAdrr;
    STD_EnType                      Slave_HighSpeed;
    STD_EnType                      Interrupt_STO;
    I2c_GlitchFilterPwType          Interrupt_STA;
    STD_EnType                      Interrupt_Rxc;
}I2c_SlaveConfigType;

typedef struct
{
    uint32 TxMsgSize;
    uint16 TxBuffer[I2c_TX_BUFFER_SIZE];
    uint32 TxBufferIndex;
    uint16 RxBuffer[I2c_RX_BUFFER_SIZE];
    uint32 RxBufferIndex;
    uint32 RxMsgSize;
    I2c_StatusType Status;
}I2c_ChannelParamType;

#endif /* I2C_PRIVATE_CONFIG */
#endif /* E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_ */
