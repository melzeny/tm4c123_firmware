/*
 * i2c.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define I2C_PRIVATE_CONFIG
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
extern const uint8 I2C_NumOfActivatedChannel;
extern const I2c_MasterConfigType I2C_Master_CfgArr[];
extern const I2c_SlaveConfigType I2C_Slave_CfgArr[];
/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 I2c_BaseAddrArr[] = {I2C_0_BASE_ADDRESS, I2C_1_BASE_ADDRESS, I2C_2_BASE_ADDRESS, I2C_3_BASE_ADDRESS};
static I2c_ChannelParamType I2c_ChannelParam[I2C_NUM_OF_CHANNEL];
/*================================================*
 * LOCAL FUNCTIONS
 * ==============================================*/
static inline void I2c_GenerateStartCond(I2c_ChannelType Channel);
static inline void I2c_GenerateStopCond(I2c_ChannelType Channel);
static inline void I2c_SetSlaveAddr(I2c_ChannelType Channel , uint8 SlaveAddress, I2c_RequestType Request);

/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/
void I2c_Init(void)
{
    uint8 i;
    I2c_ChannelType Channel;
    for (i = 0; i < I2C_NumOfActivatedChannel; ++i)
    {
#if (I2C_OPR_MODE_SELECTOR==I2C_OPR_MODE_SLAVE)


#else
        Channel = I2C_Master_CfgArr[i].Channel;
        /* Initialize the I2C Mode Master\slave */
        I2CMCR(I2c_BaseAddrArr[i]).B.MFE = STD_high;


        /* FOR MASTER: Set the desired SCL clock speed */

        /*FOR MASTER:  Enable Master TxRx */
#endif
    }
}
void I2c_enInterrupt(I2c_ChannelType Channel)
{

}
void I2c_diInterrupt(I2c_ChannelType Channel)
{

}


/*=================================================================================
 * NAME:        I2c_WriteIB
 * DESCRIBTION: The Function shall take over the given parame-ters,
 * and save the pointed data to the internal buffer defined with the function
 * =================================================================================*/
Std_ReturnType I2c_WriteIB( I2c_ChannelType Channel, const uint8* DataBufferPtr,uint8 DataBufferSize)
{
    Std_ReturnType  ret = E_OK;

    return ret;

}

/* =================================================================================
 * NAME:          I2c_ReadIB
 * DESCRIBTION:   The function I2c_ReadIB provides the service
 * for reading synchronously one or more data from an IB
 * =================================================================================*/
Std_ReturnType I2c_ReadIB( I2c_ChannelType Channel, uint8* DataBufferPointer, uint8* DataBufferSizePtr )
{
    Std_ReturnType  ret = E_OK;

    return ret;
}

Std_ReturnType I2c_AsyncRequest(I2c_ChannelType Channel,
                                uint32 SLA,
                                I2c_RequestType Request,
                                uint8 MsgSize)
{
    Std_ReturnType  ret = E_NOT_OK;
    /* check for the I2c controller idle and the bus is idle */
    if( (I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.BUSY == 0) && (I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.BUSBSY == 0) )
    {
        /* check for the Requested operation : Read/Write */
        if(Request==I2c_Request_Write)
        {
            /* check for the status of the I2c module is idle */
            if(I2c_ChannelParam[Channel].Status == I2c_idle)
            {
                I2c_ChannelParam[Channel].Status = I2c_busy; /* Change the status of the I2c module */
                I2CMCS_Write(I2c_BaseAddrArr[Channel]).B.STOP=0; // Stop bit -> For not sending stop bit at the end of the data frame (several frames) */
                I2CMCR(I2c_BaseAddrArr[Channel]).R = SLA; /* Send the slave address*/
                I2c_enInterrupt(Channel);
                if(I2c_ChannelParam[Channel].TxBufferIndex >=  MsgSize-1) /* Check for that the data is more than */
                {
                    I2CMCS_Write(I2c_BaseAddrArr[Channel]).B.ACK=1; /* Stop bit */
                }
                I2CMDR(I2c_BaseAddrArr[Channel])=I2c_ChannelParam[Channel].TxBuffer[I2c_ChannelParam[Channel].TxBufferIndex++];
            }
        }
        else if(Request == I2c_Request_Read)
        {

        }
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

Std_ReturnType I2c_SyncRequest(I2c_ChannelType Channel,
                               uint32 SLA,
                               I2c_RequestType Request,
                               uint8 MsgSize)
{
    Std_ReturnType ret = E_OK;
    if(I2c_ChannelParam[Channel].Status == I2c_idle)
    {
        I2c_ChannelParam[Channel].Status = I2c_busy;

        I2c_GenerateStartCond(Channel);
        I2c_SetSlaveAddr(Channel,SLA,Request);


        /* wait for Address acknowledgment*/
        while(I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.ADRACK == STD_high)
        {
            ;
        }
        if (Request==I2c_Request_Write) {

            for (I2c_ChannelParam[Channel].TxBufferIndex = 0;
                    I2c_ChannelParam[Channel].TxBufferIndex < I2c_ChannelParam[Channel].TxMsgSize;
                    I2c_ChannelParam[Channel].TxBufferIndex++)
            {
                I2CMDR(I2c_BaseAddrArr[Channel]) = I2c_ChannelParam[Channel].TxBuffer[I2c_ChannelParam[Channel].TxBufferIndex];

                /*wait the transmitted Data to be Acknowledge */
                while(I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.DATACK == STD_high)
                {
                    ;
                }
            }


        }
        else{

            for (I2c_ChannelParam[Channel].RxBufferIndex = 0;
                    I2c_ChannelParam[Channel].RxBufferIndex < I2c_ChannelParam[Channel].RxMsgSize;
                    I2c_ChannelParam[Channel].RxBufferIndex++)
            {


                I2c_ChannelParam[Channel].RxBuffer[I2c_ChannelParam[Channel].RxBufferIndex]= I2CMDR(I2c_BaseAddrArr[Channel]);

                while(I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.BUSY== STD_low)

                {
                    ;
                }
            }

        }
        I2c_ChannelParam[Channel].Status = I2c_idle;
    }
    else
    {
        ret =E_NOT_OK;
    }

    return ret;
}

static inline void I2c_GenerateStartCond(I2c_ChannelType Channel)
{

}
static inline void I2c_GenerateStopCond(I2c_ChannelType Channel)
{

}
static inline void I2c_SetSlaveAddr(I2c_ChannelType Channel , uint8 SlaveAddress, I2c_RequestType Request)
{


}
static inline void I2c_SetClockSpeed(I2c_ChannelType Channel ,uint32 SclPeriod)
{


}
/*==================================================================
 * INTERRUPT HANDLERS
 * ================================================================*/
static inline void I2c_IntRoutine(I2c_ChannelType Channel)
{
    /* ACK must be set */

    if( (I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.ARBLST )  &&
            (!I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.DATACK)  &&
            (!I2CMCS_Read(I2c_BaseAddrArr[Channel]).B.ADRACK))
    {
        if(I2c_ChannelParam[Channel].TxBufferIndex < I2c_ChannelParam[Channel].TxMsgSize-1  )
        {
            I2CMCR(I2c_BaseAddrArr[Channel]).R = I2c_ChannelParam[Channel].TxBuffer[I2c_ChannelParam[Channel].TxBufferIndex++];
        }
        else
        {
            I2CMCS_Write(I2c_BaseAddrArr[Channel]).B.ACK = 1; // Stop bit
            I2CMCR(I2c_BaseAddrArr[Channel]).R=I2c_ChannelParam[Channel].TxBuffer[I2c_ChannelParam[Channel].TxBufferIndex++];
            I2c_ChannelParam[Channel].Status = I2c_idle;
            I2c_diInterrupt(Channel);
        }
    }
}

void I2c0_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel0);
}
void I2c1_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel1);
}
void I2c2_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel2);
}
void I2c3_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel3);
}
