/*
 * processor.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_
#define TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_

#include "../Std_Types.h"

typedef uint8 PROCESSOR_ModeType;
#define PROCESSOR_ModePrivilege                 (uint8)0
#define PROCESSOR_ModeNonPrivilege              (uint8)1

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode);

void PROCESSOR_enableGlobalInt(void);

void PROCESSOR_disableGlobalInt(void);

#endif /* TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_ */
