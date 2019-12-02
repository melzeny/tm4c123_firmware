/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"


extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{
    /*TODO : switch to privilege mode - use switch function in processor.h*/


    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */



    /*TODO : return to non-privilege mode */

}



