#define I2C_PRIVATE_CODE
#include "../mcal/i2c/i2c_types.h"
#include "i2c_cfg.h"



I2C_CfgType I2C_CfgArr[I2C_NUM_OF_ACTIVATED_CHANNEL] =
{
 /**********************************************************************************************************************************************************/
 /***ChannelId***********BaudRate***********Mode******************Sla**************Alt_Sla*********SpeedMode******************TimeOutEn********LoopbackEn***/
 /**********************************************************************************************************************************************************/
 {   I2C_Channel_0,      5000,              I2C_Mode_Master,      0x24,             0x26,           I2C_SpeedMode_Standard,   false,            false},

 {   I2C_Channel_1,      5000,              I2C_Mode_Master,      0x24,             0x26,           I2C_SpeedMode_Standard,   false,            false},

 {   I2C_Channel_2,      5000,              I2C_Mode_Master,      0x24,             0x26,           I2C_SpeedMode_Standard,   false,            false},

 {   I2C_Channel_3,      5000,              I2C_Mode_Master,      0x24,             0x26,           I2C_SpeedMode_Standard,   false,            false},
};
