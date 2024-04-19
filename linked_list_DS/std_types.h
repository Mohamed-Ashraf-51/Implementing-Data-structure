#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_
#include <stdio.h>
#include <stdlib.h>

#define Zero_init 0
#define Zero 0

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum return_status {
R_NOK,R_OK
}return_status;

#endif // _STD_TYPES_H_
