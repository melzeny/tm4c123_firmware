/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_

#define SYSCTR_RCC_GPIO_PORTA                     ENABLE
#define SYSCTR_RCC_GPIO_PORTB                     ENABLE
#define SYSCTR_RCC_GPIO_PORTC                     ENABLE
#define SYSCTR_RCC_GPIO_PORTD                     ENABLE
#define SYSCTR_RCC_GPIO_PORTE                     ENABLE
#define SYSCTR_RCC_GPIO_PORTF                     ENABLE

#define SYSCTR_RCC_UART0                          DISABLE
#define SYSCTR_RCC_UART1                          DISABLE
#define SYSCTR_RCC_UART2                          DISABLE
#define SYSCTR_RCC_UART3                          DISABLE
#define SYSCTR_RCC_UART4                          DISABLE
#define SYSCTR_RCC_UART5                          DISABLE
#define SYSCTR_RCC_UART6                          DISABLE
#define SYSCTR_RCC_UART7                          DISABLE

#define SYSCTR_RCC_SSI0                           ENABLE
#define SYSCTR_RCC_SSI1                           DISABLE
#define SYSCTR_RCC_SSI2                           DISABLE
#define SYSCTR_RCC_SSI3                           ENABLE
                          
#define SYSCTR_RCC_I2C0                           ENABLE
#define SYSCTR_RCC_I2C1                           ENABLE
#define SYSCTR_RCC_I2C2                           DISABLE
#define SYSCTR_RCC_I2C3                           DISABLE

#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
