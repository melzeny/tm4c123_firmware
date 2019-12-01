#define SPI_PRIVATE_CODE

#include "spi_cfg.h"
#include "../mcal/spi/spi_Types.h"

/*
*  NOTE: For master mode, the system clock or the PIOSC must be at least
*  two times faster than the SSInClk, with the restriction that SSInClk cannot be faster than
*  25 MHz. For slave mode, the system clock or the PIOSC must be at least 12 times faster
*  than the SSInClk, with the restriction that SSInClk cannot be faster than 6.67 MHz.
*/
SPI_CFGType SPI_CfgArr[SPI_NUMER_OF_ACTIVATED_CHANNELS]=
{
/***************************************************************************************************************************************************************************/
/*ChannelID*********MODE*****************BaudRate*******ClockPolarity********************Clockphase************************FrameFormate*************************DataSize****/
/***************************************************************************************************************************************************************************/	
{SPI_Ch_0,          SPI_Mode_Master,     9600,          SPI_CLockPolarity_IdleLow,       SPI_CLockPhase_SampleFirstEdge,   SPI_FrameFormate_FreeScale,          16          },
{SPI_Ch_3,          SPI_Mode_Master,     5000000,       SPI_CLockPolarity_IdleLow,       SPI_CLockPhase_SampleFirstEdge,   SPI_FrameFormate_FreeScale,          16          },

};


