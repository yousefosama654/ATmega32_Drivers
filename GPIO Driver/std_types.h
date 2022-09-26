/*
 *  std_types.h
 *  Created on: Sep 26, 2022
 *  Author: Yousef_Osama
 *  Description :this file include all the data types in the projects
 */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/* define the unsigned int types */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
/* define the signed int types */
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
/* define the float types */
typedef float float32;
typedef double float64;
/* Boolean Data Type */
typedef unsigned char boolean;
/* Boolean Values */
/* use #ifndef in case that ant static library uses them */
#ifndef FALSE
#define FALSE (0u)
#endif
#ifndef TRUE
#define TRUE (1u)
#endif
/*  define the values of logic high and low in the program */
#define LOGIC_LOW (0u)
#define LOGIC_HIGH (1u)
/*define the null pointer with pointer casting*/
#define NULL_PTR ((void*)0)
#endif /* STD_TYPES_H_ */
