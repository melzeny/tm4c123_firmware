/*
 * port_types.h
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_TYPES_H_
#define E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_TYPES_H_

#define PORT_MODE_PIN_X_DIO                 0

#define PORT_MODE_PIN_B0_U1RX               1
#define PORT_MODE_PIN_B1_U1TX               1

#define PORT_MODE_PIN_A2_SSI0Clk            2
#define PORT_MODE_PIN_A3_SSI0Fss            2
#define PORT_MODE_PIN_A4_SSI0Rx             2
#define PORT_MODE_PIN_A5_SSI0Tx             2

#define PORT_MODE_PIN_B4_SSI2Clk            2
#define PORT_MODE_PIN_B5_SSI2Fss            2
#define PORT_MODE_PIN_B6_SSI2Rx             2
#define PORT_MODE_PIN_B7_SSI2Tx             2

#define PORT_MODE_PIN_D0_SSI1Clk            2
#define PORT_MODE_PIN_D1_SSI1Fss            2
#define PORT_MODE_PIN_D2_SSI1Rx             2
#define PORT_MODE_PIN_D3_SSI1Tx             2

#define PORT_MODE_PIN_D0_SSI3Clk            1
#define PORT_MODE_PIN_D1_SSI3Fss            1
#define PORT_MODE_PIN_D2_SSI3Rx             1
#define PORT_MODE_PIN_D3_SSI3Tx             1

#define PORT_MODE_PIN_F0_SSI1Clk            2
#define PORT_MODE_PIN_F1_SSI1Fss            2
#define PORT_MODE_PIN_F2_SSI1Rx             2
#define PORT_MODE_PIN_F3_SSI1Tx             2

#define PORT_MODE_PIN_B2_I2C0SCL            3
#define PORT_MODE_PIN_B3_I2C0SDA            3

#define PORT_MODE_PIN_A6_I2C1SCL            3
#define PORT_MODE_PIN_A7_I2C1SDA            3

#define PORT_MODE_PIN_E4_I2C2SCL            3
#define PORT_MODE_PIN_E5_I2C2SDA            3

#define PORT_MODE_PIN_D0_I2C3SCL            3
#define PORT_MODE_PIN_D1_I2C3SDA            3

#include "../../utils/Std_Types.h"
typedef enum
{
    Port_Channel_A0,
    Port_Channel_A1,
    Port_Channel_A2,
    Port_Channel_A3,
    Port_Channel_A4,
    Port_Channel_A5,
    Port_Channel_A6,
    Port_Channel_A7,

    Port_Channel_B0,
    Port_Channel_B1,
    Port_Channel_B2,
    Port_Channel_B3,
    Port_Channel_B4,
    Port_Channel_B5,
    Port_Channel_B6,
    Port_Channel_B7,

    Port_Channel_C0,
    Port_Channel_C1,
    Port_Channel_C2,
    Port_Channel_C3,
    Port_Channel_C4,
    Port_Channel_C5,
    Port_Channel_C6,
    Port_Channel_C7,

    Port_Channel_D0,
    Port_Channel_D1,
    Port_Channel_D2,
    Port_Channel_D3,
    Port_Channel_D4,
    Port_Channel_D5,
    Port_Channel_D6,
    Port_Channel_D7,

    Port_Channel_E0,
    Port_Channel_E1,
    Port_Channel_E2,
    Port_Channel_E3,
    Port_Channel_E4,
    Port_Channel_E5,
    Port_Channel_E6_NotExist,
    Port_Channel_E7_NotExist,

    Port_Channel_F0,
    Port_Channel_F1,
    Port_Channel_F2,
    Port_Channel_F3,
    Port_Channel_F4,

    Port_Channel_MaxNum
}Port_ChIdType;

typedef enum
{
    Port_Id_A,
    Port_Id_B,
    Port_Id_C,
    Port_Id_D,
    Port_Id_E,
    Port_Id_F
}Port_IdType;

typedef enum
{
    port_Dir_Input,
    port_Dir_Output
}Port_DirType;

typedef enum
{
    Port_IntDisable,
    Port_IntFallingEdge,
    Port_IntRisingEdge,
    Port_IntBothEdges
}Port_IntCtrType;

typedef enum
{
    Port_Mode_DIO,
    Port_Mode_UART_Tx,
    Port_Mode_UART_Rx,
    Port_Mode_SSI_Clk,
    Port_Mode_SSI_Fss,
    Port_Mode_SSI_Rx,
    Port_Mode_SSI_Tx,
    Port_Mode_I2C_Scl,
    Port_Mode_I2C_Sda,
    Port_Mode_PWM,
    Port_Mode_CCP,
    Port_Mode_AIN,
    Port_Mode_CAN_Rx,
    Port_Mode_CAN_Tx
}Port_ModeType;

typedef enum
{
    Port_Unlocked,
    Port_locked
}Port_LockStatusType;


typedef enum
{
    Port_InternalAttach_NA,
    Port_InternalAttach_PullUpRes,
    Port_InternalAttach_PullDownRes,
    Port_InternalAttach_OpenDrain,

}Port_InternalAttachType;

typedef enum
{
    Port_CurrDrive_2mA,
    Port_CurrDrive_4mA,
    Port_CurrDrive_8mA,
}Port_CurrDriveType;


typedef struct
{
    Port_ChIdType           Channel;
    Port_DirType            Dir;
    uint8                   Mode;
    Port_IntCtrType         Interrupt;
    Port_InternalAttachType AttachedRes;
    Port_CurrDriveType      CurrentDrive;
    Port_LockStatusType     LockStatus;
}Port_CfgType;

#endif /* E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_TYPES_H_ */
