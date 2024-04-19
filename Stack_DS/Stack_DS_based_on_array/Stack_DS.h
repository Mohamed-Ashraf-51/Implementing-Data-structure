#ifndef _STACK_DS_H
#define _STACK_DS_H
#include "std_types.h"

#define stack_max_size 5
typedef struct stack_DS
{
    uint32_t Stack_pointer;
    uint32_t data[stack_max_size];
}stack_DS_t;
typedef enum stack_status
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL,
}stack_status;

/**
  * @brief initialize the stack
  * @param mystack pointer to the stack
  * @retval status of the initialization process
  */
return_status stack_init(stack_DS_t *mystack);
/**
  * @brief push element in the stack
  * @param mystack pointer to the stack
  * @param the value I want to push in the stack
  * @retval status of the push process
  */
return_status stack_push(stack_DS_t *mystack, uint32_t value);
/**
  * @brief pop element from the stack
  * @param mystack pointer to the stack
  * @param pointer to the variable I want to pop the value in it
  * @retval status of the pop process
  */
return_status stack_pop(stack_DS_t *mystack, uint32_t *value);
/**
  * @brief get the top element in the stack
  * @param mystack pointer to the stack
  * @param pointer to variable I want to get the value in it
  * @retval status of the getting the top element process
  */
return_status stack_top(stack_DS_t *mystack, uint32_t *value);
/**
  * @brief get the size of the stack
  * @param mystack pointer to the stack
  * @param pointer to variable I want to get the size in it
  * @retval status of the getting the top element process
  */
return_status stack_size(stack_DS_t *mystack, uint32_t *stack_size);
/**
  * @brief display all elements in the stack
  * @param mystack pointer to the stack
  * @retval status of the getting the top element process
  */
return_status stack_display(stack_DS_t *mystack);
#endif // _STACK_DS_H
