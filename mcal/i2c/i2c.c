/*
 * i2c.c
 *
 *  Created on:
 *      Author:  Sprints wave4
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define I2C_PRIVATE_CODE
#define I2C_NUM_OF_CHANNEL              4
/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"

#include "../../config/i2c_cfg.h"
#include "i2c_types.h"
#include "i2c.h"

/*================================================*
 * EXTERNS
 * ==============================================*/
extern I2C_CfgType I2C_CfgArr[];

/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 I2c_BaseAddrArr[] = {I2C_0_BASE_ADDRESS, I2C_1_BASE_ADDRESS, I2C_2_BASE_ADDRESS, I2C_3_BASE_ADDRESS};
static I2C_ChannelParamType I2C_ChannelParam[I2C_NUM_OF_CHANNEL];

/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/

void I2C_init(void)
{
    uint8 CfgIndex;
    for(CfgIndex=0; CfgIndex<I2C_NUM_OF_ACTIVATED_CHANNEL; CfgIndex++)
    {
        I2C_ChannelType ChannelId =  I2C_CfgArr[CfgIndex].I2C_ChannelId;
        uint32 BaseAddress = I2c_BaseAddrArr[ChannelId];

        /*
            TODO Initialize the I2C Master by writing the I2CMCR register with a value of 0x0000.0010.
         */
        I2CMCR(BaseAddress).B.MFE = STD_high;


        /*
            TODO Set the desired SCL clock speed of 100 Kbps by writing the I2CMTPR register with the correct
            value. The value written to the I2CMTPR register represents the number of system clock periods
            in one SCL clock period. The TPR value is determined by the following equation:
            TPR = (System Clock/(2*(SCL_LP + SCL_HP)*SCL_CLK))-1;
            TPR = (20MHz/(2*(6+4)*100000))-1;
            TPR = 9
            Write the I2CMTPR register with the value of 0x0000.0009.
                 */

        /*TODO use All Cfg parameters to init Channel Registers */







    }
}
Std_ReturnType I2C_writeIB(I2C_ChannelType Channel, uint8* Data, uint8 SizeCpy)
{
    Std_ReturnType Ret = E_OK;
    uint8 i;
    /*
     * TODO Check if  Channel status is Idle
     * */

    /*
     * TODO Set Channel status to Busy
     * */


    for (i = 0; i < SizeCpy; ++i)
    {
        I2C_ChannelParam[Channel].TxBuffer[i] = Data[i];
    }


    /*
     * TODO Set Channel status to Idle
     * */

    return Ret;

}
Std_ReturnType I2C_readIB(I2C_ChannelType Channel, uint8* Data, uint8* Size)
{
    Std_ReturnType Ret = E_OK;


    return Ret;

}
Std_ReturnType I2C_syncTransmit( I2C_ChannelType Channel,
                                 uint8 Sla,
                                 I2C_OperationType Operation, /*Read\Write*/
                                 uint8 RxSize,
                                 I2C_StopFrameEnType StopFrameEn)
{
    Std_ReturnType Ret = E_OK;

    /*
     * TODO Check if  Channel status is Idle
     * */

    /*
     * TODO Set Channel status to Busy
     * */

    /*
        TODO Specify the slave address of the master and that the next operation is a Transmit by writing the I2CMSA register with a value of 0x0000.0076. This sets the slave address to 0x3B.
     */

    /*
        TODOPlace data (byte) to be transmitted in the data register by writing the I2CMDR register with the desired data.
     */

    /*
        TODO Initiate a single byte transmit of the data from Master to Slave by writing the I2CMCS register with desired value of (STOP, START, RUN)
     */




    return Ret;

}

I2C_StatusType I2C_getStatus(I2C_ChannelType Channel)
{
    /*TODO Return Channel Status*/


}




/*==================================================================
 * INTERRUPT HANDLERS
 * ================================================================*/
static inline void I2c_IntRoutine(I2C_ChannelType Channel)
{




}

void I2c0_IntHandler(void)
{
    I2c_IntRoutine(I2C_Channel_0);
}
void I2c1_IntHandler(void)
{
    I2c_IntRoutine(I2C_Channel_1);
}
void I2c2_IntHandler(void)
{
    I2c_IntRoutine(I2C_Channel_2);
}
void I2c3_IntHandler(void)
{
    I2c_IntRoutine(I2C_Channel_3);
}
