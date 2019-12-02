/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODO: include the header file that contains register definitions */

#include "dio.h"

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the level value of given Channel */

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Write the input value in the corresponding ChannelId */
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    /*TODO: Return the Port Value*/

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*TODO: Write the input value in the corresponding PortId */

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* TODO: toggle the corresponding ChannelId */


}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */

}



