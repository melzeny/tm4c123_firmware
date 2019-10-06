/*
 * spi.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SPI_SPI_H_
#define E15_ARM_REPO_MCAL_SPI_SPI_H_

#include "../../utils/STD_Types.h"
#include "spi_types.h"


void Spi_init(void);
Spi_StatusType Spi_GetStatus(Spi_ChannelType Channel);
void Spi_enInterrupt(Spi_ChannelType SpiNo);
void Spi_diInterrupt(Spi_ChannelType SpiNo);

/*=================================================================================
 * NAME:        Spi_WriteIB
 * DESCRIBTION: The Function shall take over the given parame-ters,
 * and save the pointed data to the internal buffer defined with the function
 * =================================================================================*/
Std_ReturnType Spi_WriteIB( Spi_ChannelType Channel, const uint16* DataBufferPtr,uint8 DataBufferSize);

/* =================================================================================
 * NAME:          Spi_ReadIB
 * DESCRIBTION:   The function Spi_ReadIB provides the service
 * for reading synchronously one or more data from an IB
 * =================================================================================*/
Std_ReturnType Spi_ReadIB( Spi_ChannelType Channel, uint16* DataBufferPointer, uint8* DataBufferSizePtr );


Std_ReturnType Spi_AsyncTransmit(Spi_ChannelType Channel);
Std_ReturnType Spi_SyncTransmit(Spi_ChannelType Channel);


#endif /* E15_ARM_REPO_MCAL_SPI_SPI_H_ */
