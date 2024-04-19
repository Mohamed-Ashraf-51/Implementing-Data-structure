#include "Stack_DS.h"
/**
  * @brief Check if the stack is full
  * @param mystack pointer to the stack
  * @retval status of the stack
  */
static stack_status stack_full(stack_DS_t *myStack)
{
    if ((stack_max_size-1)==myStack->Stack_pointer)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}
/**
  * @brief Check if the stack is Empty
  * @param mystack pointer to the stack
  * @retval status of the stack
  */
static stack_status stack_empty(stack_DS_t *myStack)
{
    if (-1==myStack->Stack_pointer)
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }

}

/**
  * @brief initialize the stack
  * @param mystack pointer to the stack
  * @retval status of the initialization process
  */
return_status stack_init(stack_DS_t *mystack)
{
   return_status ret=R_NOK;
   if (NULL==mystack)
   {
       ret=R_NOK;
   }
   else
    {
        mystack->Stack_pointer=-1;
        ret =R_OK;
    }
    return ret;
}
/**
  * @brief push element in the stack
  * @param mystack pointer to the stack
  * @param the value I want to push in the stack
  * @retval status of the push process
  */
return_status stack_push(stack_DS_t *mystack, uint32_t value)
{
    return_status ret;
    if ((mystack==NULL)||(stack_full(mystack)==STACK_FULL))
    {
        printf("Error !! can't push  (%i) to the stack\n",value);
        ret=R_NOK;
    }
    else{
        mystack->Stack_pointer++;
       mystack->data[mystack->Stack_pointer]=value;

        printf("vlaue %i pushed to the stack\n",value);
        ret=R_OK;
    }
    return ret;
}
/**
  * @brief pop element from the stack
  * @param mystack pointer to the stack
  * @param pointer to the variable I want to pop the value in it
  * @retval status of the pop process
  */
return_status stack_pop(stack_DS_t *mystack, uint32_t *value)
{
    return_status ret=R_NOK;
    if ((mystack==NULL)||(value ==NULL)||(stack_empty(mystack)==STACK_EMPTY))
    {
        printf("Error!!   Stack is empty ");
        ret=R_NOK;
    }
    else
    {
        *value = mystack->data[mystack->Stack_pointer];
        mystack->Stack_pointer--;
        printf("The value is poped \n");
        ret =R_OK;
    }

    return ret;
}
/**
  * @brief get the top element in the stack
  * @param mystack pointer to the stack
  * @param pointer to variable I want to get the value in it
  * @retval status of the getting the top element process
  */
return_status stack_top(stack_DS_t *mystack, uint32_t *value)
{
    return_status ret=R_NOK;
    if ((mystack==NULL)||(value ==NULL)||(stack_empty(mystack)==STACK_EMPTY))
    {
        printf("Error!!   Stack is empty ");
        ret=R_NOK;
    }
    else
    {
        *value = mystack->data[mystack->Stack_pointer];

        printf("The value is %i  \n",*value);
        ret =R_OK;
    }

    return ret;
}
/**
  * @brief get the size of the stack
  * @param mystack pointer to the stack
  * @param pointer to variable I want to get the size in it
  * @retval status of the getting the top element process
  */
return_status stack_size(stack_DS_t *mystack, uint32_t *stack_size)
{
  return_status ret=R_NOK;
    if ((mystack==NULL)||(stack_size ==NULL))
    {
        printf("Error!! Null pointer");
        ret=R_NOK;
    }
    else
    {
        *stack_size = mystack->Stack_pointer+1;
        ret =R_OK;
    }

    return ret;
}
/**
  * @brief display all elements in the stack
  * @param mystack pointer to the stack
  * @retval status of the getting the top element process
  */
return_status stack_display(stack_DS_t *mystack)
{
   return_status ret=R_NOK;
   sint32_t counter=Zero;
   if((mystack==NULL)||(stack_empty(mystack)==STACK_EMPTY))
   {
       ret=R_NOK;
   }
   else
   {
       for (counter =( mystack->Stack_pointer) ; counter>=0; counter--)
       {
        //  printf("counter = %i\n",counter);
           printf("%i \n",mystack->data[counter]);

           ret=R_OK;
       }
   }
   return ret;
}
