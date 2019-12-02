/*
 * port_lcfg.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include <tm4c123_firmware/mcal/PortDriver/port_types.h>
#include "port_cfg.h"

Port_CfgType PortCfgArr[PORT_NUM_OF_ACTIVATED_CH] = {

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*    Channel                   Direction                Mode                          External Interrupt      Attached_Resistor                      Current_Drive_Strength      Lock_Status    */
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
{     Port_Channel_A0,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A1,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A2,          port_Dir_Input,          PORT_MODE_PIN_A2_SSI0Clk,     Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A3,          port_Dir_Input,          PORT_MODE_PIN_A3_SSI0Fss,     Port_IntDisable,        Port_InternalAttach_PullDownRes,       Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A4,          port_Dir_Input,          PORT_MODE_PIN_A4_SSI0Rx,      Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A5,          port_Dir_Output,         PORT_MODE_PIN_A5_SSI0Tx,      Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A6,          port_Dir_Input,          PORT_MODE_PIN_A6_I2C1SCL,     Port_IntDisable,        Port_InternalAttach_PullUpRes,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A7,          port_Dir_Input,          PORT_MODE_PIN_A7_I2C1SDA,     Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },

{     Port_Channel_C0,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C1,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C2,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C3,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C4,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C5,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C6,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_C7,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },

{     Port_Channel_D0,          port_Dir_Input,          PORT_MODE_PIN_D0_SSI3Clk,     Port_IntDisable,        Port_InternalAttach_PullUpRes,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D1,          port_Dir_Input,          PORT_MODE_PIN_D1_SSI3Fss,     Port_IntDisable,        Port_InternalAttach_PullDownRes,       Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D2,          port_Dir_Input,          PORT_MODE_PIN_D2_SSI3Rx,      Port_IntDisable,        Port_InternalAttach_PullUpRes,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D3,          port_Dir_Output,         PORT_MODE_PIN_D3_SSI3Tx,      Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D4,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D5,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D6,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_D7,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },

{     Port_Channel_E0,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_E1,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_E2,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_E3,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_E4,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_E5,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },
/*TODO: Configure PORTF Channels*/



};
