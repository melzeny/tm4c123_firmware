/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"
#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    switch(PortId)
    {
    case Dio_Port_A:
        ret = GET_BIT(PORTA_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_B:
        ret = GET_BIT(PORTB_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_C:
        ret = GET_BIT(PORTC_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_D:
        ret = GET_BIT(PORTD_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_E:
        ret = GET_BIT(PORTE_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_F:
        ret = GET_BIT(PORTF_REG.GPIODATA,ChannelPos);
        break;
    default:
        /*error*/
        ret = 2;
        break;
    }
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    switch(PortId)
    {
    case Dio_Port_A:
        if(Level == STD_low)
        {
            CLR_BIT(PORTA_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTA_REG.GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_B:
        if(Level == STD_low)
        {
            CLR_BIT(PORTB_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTB_REG.GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_C:
        if(Level == STD_low)
        {
            CLR_BIT(PORTC_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTC_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_D:
        if(Level == STD_low)
        {
            CLR_BIT(PORTD_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTD_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_E:
        if(Level == STD_low)
        {
            CLR_BIT(PORTE_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTE_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_F:
        if(Level == STD_low)
        {
            CLR_BIT(PORTF_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTF_REG.GPIODATA,ChannelPos);
        }
        break;
    default:
        /*error*/
        break;
    }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    switch(PortId)
    {
    case Dio_Port_A:
        ret = PORTA_REG.GPIODATA;
        break;

    case Dio_Port_B:
        ret = PORTB_REG.GPIODATA;
        break;

    case Dio_Port_C:
        ret = PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D:
        ret = PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E:
        ret = PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F:
        ret = PORTF_REG.GPIODATA;
        break;
    default:
        /*error*/
        break;
    }

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    switch(PortId)
    {
    case Dio_Port_A:
        PORTA_REG.GPIODATA = value;
        break;
    case Dio_Port_B:
        PORTB_REG.GPIODATA = value;
        break;

    case Dio_Port_C:
        PORTC_REG.GPIODATA = value;
        break;
    case Dio_Port_D:
        PORTD_REG.GPIODATA = value;
        break;
    case Dio_Port_E:
        PORTE_REG.GPIODATA = value;
        break;
    case Dio_Port_F:
        PORTF_REG.GPIODATA = value;
        break;
    default:
        /*error*/
        break;
    }
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    switch(PortId)
    {
    case Dio_Port_A:
        TOGGLE_BIT(PORTA_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_B:
        TOGGLE_BIT(PORTB_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_C:
        TOGGLE_BIT(PORTC_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_D:
        TOGGLE_BIT(PORTD_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_E:
        TOGGLE_BIT(PORTE_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_F:
        TOGGLE_BIT(PORTF_REG.GPIODATA,ChannelPos);
        break;
    default:
        /*error*/
        break;
    }

}
void Dio_FlipPort(Dio_PortType PortId)
{
    switch(PortId)
    {
    case Dio_Port_A:
        PORTA_REG.GPIODATA = ~ PORTA_REG.GPIODATA;
        break;
    case Dio_Port_B:
        PORTB_REG.GPIODATA = ~PORTB_REG.GPIODATA;
        break;
    case Dio_Port_C:
        PORTC_REG.GPIODATA = ~PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D:
        PORTD_REG.GPIODATA = ~PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E:
        PORTE_REG.GPIODATA = ~PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F:
        PORTF_REG.GPIODATA = ~PORTF_REG.GPIODATA;
        break;
    default:
        /*error*/
        break;
    }
}



