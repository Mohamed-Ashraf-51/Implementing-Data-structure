#include <stdio.h>
#include <stdlib.h>
#include "D_stack_ds.h"

stack_t *mystack1;
uint32_t stack1_size;
stack_status_t state=STACK_NOK;
uint32_t *ptr_pop=0;
char value='a';
uint32_t count=0;

int main()
{
    printf("Enter the size of the stack:\n");
    scanf("%i",&stack1_size);
    mystack1=create_stack(stack1_size,&state);
    if(mystack1)
    {
        printf("mystack 1 created\n");
    }
    printf("Enter the value to be pushed: \n");
    scanf("%s",&value);
    state=push_stack(mystack1,&value);
    printf("the value %c is pushed to the stack\n",*(char*)mystack1->stack_array[mystack1->stack_top]);
    printf("the stack top value  is: %i\n",mystack1->stack_top);
    state=stack_count(mystack1,&count);
    printf("The number of elements in the stack = %i \n",count);
    ptr_pop=(char*)pop_stack(mystack1,&state);
    printf("the value %c is poped to the stack\n",*ptr_pop);
    printf("========================================================\n");
    state=stack_count(mystack1,&count);
    printf("The number of elements in the stack = %i \n",count);

    mystack1=destroy_stack(mystack1,&state);
    if(!mystack1)
    {
        printf("mystack 1 destroyed\n");
    }
    else
    {
        printf("failed to destroy mystack1\n");
    }


    return 0;
}
