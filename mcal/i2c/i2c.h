/*
 * i2c.h
 *
 *  Created on:
 *      Author:  Sprints wave4
 */

#ifndef E15_ARM_REPO_MCAL_I2c_I2c_H_
#define E15_ARM_REPO_MCAL_I2c_I2c_H_

#include "i2c_types.h"


void I2C_init(void);
Std_ReturnType I2C_writeIB(I2C_ChannelType Channel, uint8* Data, uint8 SizeCpy);
Std_ReturnType I2C_readIB(I2C_ChannelType Channel, uint8* Data, uint8* Size);
Std_ReturnType I2C_syncTransmit( I2C_ChannelType Channel,
                                 uint8 Sla,
                                 I2C_OperationType Operation, /*Read\Write*/
                                 uint8 RxSize,
                                 I2C_StopFrameEnType StopFrameEn
);

I2C_StatusType I2C_getStatus(I2C_ChannelType Channel);





#endif /* E15_ARM_REPO_MCAL_I2c_I2c_H_ */
