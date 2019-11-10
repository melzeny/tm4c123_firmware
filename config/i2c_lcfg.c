/*
 * i2c_lcfg.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define I2C_PRIVATE_CONFIG

/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../utils/STD_types.h"
#include "i2c_cfg.h"
#include "../mcal/i2c/i2c_types.h"





/*================================================*
 * CONFIGURATIONS
 * ==============================================*/
const uint8 I2C_NumOfActivatedChannel = 4;


const I2c_MasterConfigType I2C_Master_CfgArr[]    = {
/*============================================================================================================================================================================================================================================================================*
 *  I2C_ModNUm             CLockRate             Master_HighSpeed             CLock_HighSpeed           AutoDataAck       GlitchFilter                 GlitchFilter_PulseWidth             LoopBack       FIFO_EN             Interrupt_Master           Interrupt_ClkTimeout *
 *============================================================================================================================================================================================================================================================================*/
 {  I2c_Channel0,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2c_Channel1,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2c_Channel2,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2c_Channel3,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            }
};


const I2c_SlaveConfigType I2C_Slave_CfgArr[]    = {
/*=========================================================================================================================================================================================================*
 *  I2C_ModNUm             SlaveAddr             ALtSlaveAdrr_EN             ALtSlaveAdrr             HighSpeed             Interrupt_STO             Interrupt_STA                        Interrupt_Rxc   *
 *=========================================================================================================================================================================================================*/
 {  I2c_Channel0,                 0x12345678,            DISABLE,                   0x12345678,               DISABLE,              DISABLE,                 ENABLE ,                             DISABLE,        },
 {  I2c_Channel1,                 0x12312325,            DISABLE,                   0x12312325,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        },
 {  I2c_Channel2,                 0x45645678,            DISABLE,                   0x45645678,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        },
 {  I2c_Channel3,                 0x20245678,            DISABLE,                   0x20245678,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        }
};
