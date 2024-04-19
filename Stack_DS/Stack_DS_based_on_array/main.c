#include <stdio.h>
#include <stdlib.h>
#include "Stack_DS.h"

stack_DS_t myStack1;
uint32_t value =Zero  ;
uint32_t size=0;
int main()
{
    return_status ret=R_NOK ;
    ret=stack_init(&myStack1);
    if (R_NOK== ret)
    {
        printf("Failed to initialize the stack\n");
    }
    else
    {
      printf("Initialization Done\n");
    }
     ret=stack_push(&myStack1,25);
    ret=stack_push(&myStack1,26);
    ret=stack_push(&myStack1,27);

    ret=stack_top(&myStack1,&value);
    ret=stack_size(&myStack1,&size);
    ret=stack_display(&myStack1);
    printf("Stack pointer = %i\n",myStack1.Stack_pointer);

    return 0;
}
