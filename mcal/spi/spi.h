#ifndef SPI_H
#define SPI_H

#include "SPI_Types.h"

void SPI_init(void);
Std_ReturnType SPI_writeIB(SPI_ChannelType Channel, uint16* userTxMsg, uint8 TxMsgSize);
Std_ReturnType SPI_readIB(SPI_ChannelType Channel, uint16* userRxMsg, uint8*const RxMsgSize);
Std_ReturnType SPI_SyncTransmit(SPI_ChannelType Channel);
SPI_StatusType SPI_getStatus(SPI_ChannelType Channel);

#endif
