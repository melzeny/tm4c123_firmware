
/*
 * port.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Mustafa Sayed
 */
#define MAX_NUM_OF_CH_IN_PORT       8

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    uint8 i;
    Port_IdType PortId;
    Port_ChIdType ChId;
    volatile PORT_RegType* PORT_Addr;
    for (i = 0; i < PORT_NUM_OF_ACTIVATED_CH; ++i)
    {
        PortId = i/ MAX_NUM_OF_CH_IN_PORT;
        ChId = i % MAX_NUM_OF_CH_IN_PORT;

        switch (PortId)
        {
        case Port_Id_A:
            PORT_Addr = &PORTA_REG;
            break;
        case Port_Id_B:
            PORT_Addr = &PORTB_REG;
            break;
        case Port_Id_C:
            PORT_Addr = &PORTC_REG;
            break;
        case Port_Id_D:
            /*TODO: Assign PORTD address to PORT_Addr variable */
            break;
        case Port_Id_E:
            PORT_Addr = &PORTE_REG;
            break;
        case Port_Id_F:
            PORT_Addr = &PORTF_REG;
            break;
        }

        /*TODO: set channel direction */


        /*TODO: set channel mode */


        /*TODO: set Interrupt configuration */
        if(PortCfgArr[i].Interrupt == Port_IntDisable)
        {
            CLR_BIT(PORT_Addr->GPIOIM, ChId);
        }
        else
        {


        }

        /*TODO: set Internal Attachment configuration */


        /*TODO: set current strength configuration */


        /*Check if analog functionality is required*/
        if(PortCfgArr[i].Mode != Port_Mode_AIN )
        {
            /*TODO: enable digital and disable ADC  */


        }
        else
        {
            /*TODO: disable digital and enable ADC */

        }
    }
}
