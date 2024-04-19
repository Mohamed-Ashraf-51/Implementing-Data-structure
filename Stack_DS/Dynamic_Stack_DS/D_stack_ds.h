#ifndef _D_STACK_DS_H_
#define _D_STACK_DS_H_

#include "std_types.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
    void **stack_array;  /*Pointer to the array that allocated in heap*/
    sint32_t element_count;  /* count the element in the stack*/
    uint32_t stack_max_size;  /*max number of elements in the stack*/
    sint32_t stack_top;  /*has the index of the top element in the stack*/
}stack_t;
typedef enum
{
    STACK_NOK=0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}stack_status_t;

stack_t *create_stack(uint32_t max_size, stack_status_t *ret_status);
stack_t *destroy_stack(stack_t *stack_obj, stack_status_t *ret_status);
stack_status_t push_stack(stack_t *stack_obj, void *item_ptr);
void * pop_stack (stack_t *stack_obj,stack_status_t *ret_status);
void * stack_top (stack_t *stack_obj,stack_status_t *ret_status);
 stack_status_t stack_count (stack_t *stack_obj,uint32_t *stackCount);



#endif // _D_STACK_DS_H_
