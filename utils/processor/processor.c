/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "processor.h"

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    /* TODO use Svc assembly instruction to switch to handler mode*/

}

/*TODO: Put the following function address in Vector table */
void PROCESSOR_SvcHandler(void)
{
    /*TODO use TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes.See page(88) */


}

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
