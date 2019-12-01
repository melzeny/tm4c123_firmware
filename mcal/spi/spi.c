/*====================================
 * DEFINES
 *=================================== */
#define SPI_PRIVATE_CODE
#define BASE_ADDRESS_SSI0       0x40008000
#define BASE_ADDRESS_SSI1       0x40009000
#define BASE_ADDRESS_SSI2       0x4000A000
#define BASE_ADDRESS_SSI3       0x4000B000

/*====================================
 * DEFINES
 *=================================== */
#include "../mcu_hw.h"
#include "Spi_Types.h"
#include "../../config/spi_cfg.h"
#include "spi.h"


/*====================================
 * EXTERNS
 *=================================== */
extern SPI_CFGType SPI_CfgArr[];

/*====================================
 * LOCAL DECLERATIONS
 *=================================== */
static SPI_ChannelParamStructType ChannelParam[SPI_MaxNumOfChannels];
static uint32 SPI_BaseAddrArr[SPI_MaxNumOfChannels]={BASE_ADDRESS_SSI0,
                                                     BASE_ADDRESS_SSI1,
                                                     BASE_ADDRESS_SSI2,
                                                     BASE_ADDRESS_SSI3};
/*====================================
 * FUNCTION DEFINITIONS
 *=================================== */

void SPI_init(void)
{
    uint8 CfgArrIndex;
    SPI_ChannelType ChannelId;
    uint32 BaseAddress;
    for(CfgArrIndex =0; CfgArrIndex< SPI_NUMER_OF_ACTIVATED_CHANNELS; CfgArrIndex++)
    {
        ChannelId = SPI_CfgArr[CfgArrIndex].SPI_ChannelId;
        BaseAddress = SPI_BaseAddrArr[ChannelId];
        /*TODO (1): Disable SSI by Ensuring that the SSE bit in the SSICR1
         *       register is clear before making any configuration changes.*/
        SSICR1(BaseAddress).B.SSE = STD_low;

        /*TODO(2) Select whether the SSI is a master or slave:
		For master operations, set the SSICR1 register to 0x0000.0000.
		For slave mode (output enabled), set the SSICR1 register to 0x0000.0004.
		For slave mode (output disabled), set the SSICR1 register to 0x0000.000C.*/

        SPI_SetBaudRate(/* SPI_BaudRate_Hz from CFG*/);

        /*TODO(4) Set Desired clock phase/polarity, if using Freescale SPI mode */

        /*TODO(5) Set Desired Frame Formate */

        /*TODO (6) Set Desired data size*/

        /*TODO (7) Enable the SSI by setting the SSE bit in the SSICR1 register*/
    }
}
Std_ReturnType SPI_writeIB(SPI_ChannelType Channel, uint16* userTxMsg, uint8 TxMsgSize)
{

}
Std_ReturnType SPI_readIB(SPI_ChannelType Channel, uint16* userRxMsg, uint8*const RxMsgSize)
{

}
Std_ReturnType SPI_SyncTransmit(SPI_ChannelType Channel)
{

}
SPI_StatusType SPI_getStatus(SPI_ChannelType Channel)
{
    return ChannelParam[Channel].Status;
}

inline static SPI_SetBaudRate(/* SPI_BaudRate_Hz from CFG*/)
        {
    /* TODO(3): Configure the SSI clock source by writing to the SSICC register.
				Configure the clock prescale divisor by writing the SSICPSR register.
				Write the SSICR0 register with the following configuration:
				Serial clock rate (SCR) */

        }

static inline void Spi_IntRoutine(SPI_ChannelType Channel)
{
    uint32 BaseAddress = SPI_BaseAddrArr[Channel];

    if(SSIMIS(BaseAddress).B.TXMIS == STD_high)
    {


    }

    if(SSIMIS(BaseAddress).B.RXMIS == STD_high)
    {


    }

    if(SSIMIS(BaseAddress).B.RTMIS == STD_high)
    {


    }

    if(SSIMIS(BaseAddress).B.RORMIS == STD_high)
    {


    }

}

void SPI0_IntHandler(void)
{
    Spi_IntRoutine(SPI_Ch_0);
}
void SPI1_IntHandler(void)
{
    Spi_IntRoutine(SPI_Ch_1);
}
void SPI2_IntHandler(void)
{
    Spi_IntRoutine(SPI_Ch_2);
}
void SPI3_IntHandler(void)
{
    Spi_IntRoutine(SPI_Ch_3);
}
