/*
 * STD_types.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_UTILS_STD_TYPES_H_
#define E15_ARM_REPO_UTILS_STD_TYPES_H_


typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;

typedef signed char         sint8;
typedef signed short        sint16;
typedef signed int          sint32;

typedef float               float32;
typedef double              float64;

typedef enum
{
    STD_low=0,
    STD_high=!STD_low
}Std_levelType;

typedef enum
{
    STD_off=0,
    STD_on=!STD_off
}Std_BoolType;

typedef enum
{
    STD_Suspended=0,
    STD_Active=!STD_Suspended
}Std_StatusType;

typedef enum
{
    false=0,
    true=!false
}boolean;

typedef enum
{
    DISABLE=0,
    ENABLE=1
}Std_EnType;

typedef enum
{
    E_OK,
    E_NOT_OK
}Std_ReturnType;
typedef void(*Ptr2FuncType)(void);



#endif /* E15_ARM_REPO_UTILS_STD_TYPES_H_ */
