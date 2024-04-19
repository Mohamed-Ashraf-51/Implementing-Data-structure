#include <stdio.h>
#include <stdlib.h>
#include "queue_ds.h"
queue_t *myQueue1;
uint32_t value=0;
uint32_t value2=0;

queue_status_t state=QUEUE_NOK;
uint32_t queue_size=0;
uint32_t *ptr=0;
int main()
{
    printf("Enter the size of queue: \n");
    scanf("%i",&queue_size);
    myQueue1 = create_queue(queue_size,&state);
    printf("Enter the value you want to add in the queue :\n");
    scanf("%i",&value);
    state= Enqueue(myQueue1,&value);
    printf("the value (%i) is added to the queue\n",*(sint32_t*)myQueue1->queue_array[myQueue1->queue_rear]);
    printf("*****************Q_rear = %i   **************\n",myQueue1->queue_rear);
   printf("*****************Q_front = %i   **************\n",myQueue1->queue_front);
    printf("Enter the value you want to add in the queue :\n");
    scanf("%i",&value2);
    state= Enqueue(myQueue1,&value2);
    printf("the value (%i) is added to the queue\n",*(sint32_t*)myQueue1->queue_array[myQueue1->queue_rear]);
   printf("*****************Q_rear = %i   **************\n",myQueue1->queue_rear);
   printf("*****************Q_front = %i   **************\n",myQueue1->queue_front);

    printf("the Element count = (%i)\n",myQueue1->queue_count);
    ptr=(uint32_t*)Dequeue(myQueue1,&state);
    printf("The value (%i) is dequeued \n",*ptr);
    printf("the Element count = (%i)\n",myQueue1->queue_count);

 printf("the front = (%i) \n",*(sint32_t*)myQueue1->queue_array[myQueue1->queue_front]);
 printf("*****************Q_rear = %i   **************\n",myQueue1->queue_rear);
   printf("*****************Q_front = %i   **************\n",myQueue1->queue_front);
   printf("Enter the value you want to add in the queue :\n");
    scanf("%i",&value);
    state= Enqueue(myQueue1,&value);
    printf("the value (%i) is added to the queue\n",*(sint32_t*)myQueue1->queue_array[myQueue1->queue_rear]);
    printf("*****************Q_rear = %i   **************\n",myQueue1->queue_rear);
   printf("*****************Q_front = %i   **************\n",myQueue1->queue_front);

    return 0;
}
