/*
 * i2c.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_I2c_I2c_H_
#define E15_ARM_REPO_MCAL_I2c_I2c_H_

#include "../../utils/STD_Types.h"
#include "i2c_types.h"

void I2c_init(void);
void I2c_enInterrupt(I2c_ChannelType I2cNo);
void I2c_diInterrupt(I2c_ChannelType I2cNo);

/*=================================================================================
 * NAME:        I2c_WriteIB
 * DESCRIBTION: The Function shall take over the given parame-ters,
 * and save the pointed data to the internal buffer defined with the function
 * =================================================================================*/
Std_ReturnType I2c_WriteIB( I2c_ChannelType Channel, const uint8* DataBufferPtr,uint8 DataBufferSize);

/* =================================================================================
 * NAME:          I2c_ReadIB
 * DESCRIBTION:   The function I2c_ReadIB provides the service
 * for reading synchronously one or more data from an IB
 * =================================================================================*/
Std_ReturnType I2c_ReadIB( I2c_ChannelType Channel, uint8* DataBufferPointer, uint8* DataBufferSizePtr );


Std_ReturnType I2c_AsyncRequest(I2c_ChannelType Channel,
                                 uint32 SLA,
                                 I2c_RequestType Request,
                                 uint8 MsgSize);
Std_ReturnType I2c_SyncRequest(I2c_ChannelType Channel,
                                uint32 SLA,
                                I2c_RequestType Request,
                                uint8 MsgSize);


#endif /* E15_ARM_REPO_MCAL_I2c_I2c_H_ */
