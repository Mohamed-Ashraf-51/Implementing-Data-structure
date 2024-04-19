#include "queue_ds.h"

static uint8_t queue_is_full(queue_t* queue_obj)
{
    return (queue_obj->queue_rear==(queue_obj->queue_max_size)-1); //function return 1 if queue is full
}
static uint8_t queue_is_empty(queue_t* queue_obj)
{
    return (queue_obj->queue_count==0); //function return 1 if queue is empty
}


queue_t* create_queue(uint32_t max_size,queue_status_t *state)
{
    queue_t *myQueue=NULL;
    *state=QUEUE_NOK;
    myQueue =(queue_t*)malloc(sizeof(queue_t));
    if(!myQueue)
    {
        *state=QUEUE_NULL_POINTER;
        myQueue=NULL;
    }
    else
    {
       myQueue->queue_array=(void**)calloc(max_size,sizeof(void*));
       myQueue->queue_rear=-1;
       myQueue->queue_front=-1;
       myQueue->queue_max_size=max_size;
       myQueue->queue_count=0;
       printf("queue is created \n");
       *state=QUEUE_OK;

       if(!myQueue)
       {
           free(myQueue);
           myQueue=NULL;
           printf("queue can't be created\n");
           *state=QUEUE_NOK;
       }
    }
return myQueue;
}
/***********************************************************************************/
queue_status_t Enqueue(queue_t* queue_obj, void* item_ptr)
{
    queue_status_t state=QUEUE_NOK;
    if((queue_obj==NULL)||(item_ptr==NULL))
    {
        state=QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue_obj))
        {
            (queue_obj->queue_rear)++;
            (queue_obj->queue_front)++;
             queue_obj->queue_array[queue_obj->queue_rear]=item_ptr;
            (queue_obj->queue_count)++;
            state=QUEUE_OK;
        }
        else
        {
            if(queue_is_full(queue_obj))
            {
                if(queue_obj->queue_count==queue_obj->queue_max_size)/*To make circular queue*/
                {
                   state=QUEUE_FULL;
                }
                else
                {
                    (queue_obj->queue_rear)=0;
                    queue_obj->queue_array[queue_obj->queue_rear]=item_ptr;
                    (queue_obj->queue_count)++;
                    state=QUEUE_OK;


                }

            }
            else
            {
                (queue_obj->queue_rear)++;
                queue_obj->queue_array[queue_obj->queue_rear]=item_ptr;
                (queue_obj->queue_count)++;
                state=QUEUE_OK;
            }
        }

    }
return state;
}
/*********************************************************************************/
void* Dequeue(queue_t* queue_obj,queue_status_t* queue_status)
{
    void *ptr =NULL;
    if((queue_obj==NULL)||(queue_status==NULL))
    {
        *queue_status=QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue_obj))
        {
            *queue_status=QUEUE_EMPTY;
            queue_obj=NULL;
            *queue_status=QUEUE_EMPTY;
        }
        else
        {
           ptr= queue_obj->queue_array[queue_obj->queue_front];
           (queue_obj->queue_front)++;
           (queue_obj->queue_count)--;
           printf("Done Dequeue\n");
           *queue_status=QUEUE_OK;
        }
    }
return ptr;
}
/**********************************************************************************/
void* Queue_front(queue_t* queue_obj,queue_status_t* queue_status)
{
    void* ptr=NULL;
    if((queue_obj==NULL)||(queue_status==NULL))
    {
        *queue_status=QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue_obj))
        {
            ptr=NULL;
            *queue_status=QUEUE_EMPTY;
        }
        else
        {
            ptr=queue_obj->queue_array[queue_obj->queue_front];
            *queue_status=QUEUE_OK;
        }
    }
return ptr;
}
void* Queue_rear(queue_t* queue_obj,queue_status_t* queue_status)
{
    void* ptr=NULL;
    if((queue_obj==NULL)||(queue_status==NULL))
    {
        *queue_status=QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue_obj))
        {
            ptr=NULL;
            *queue_status=QUEUE_EMPTY;
        }
        else
        {
            ptr=queue_obj->queue_array[queue_obj->queue_rear];
            *queue_status=QUEUE_OK;
        }
    }
return ptr;
}
queue_status_t Queue_count(queue_t *queue_obj,uint32_t *elements_count)
{
    queue_status_t state=QUEUE_NOK;
    if((queue_obj==NULL)||(elements_count==NULL))
    {
        state=QUEUE_NULL_POINTER;
    }
    else
    {
        *elements_count=queue_obj->queue_count;
        state=QUEUE_OK;
    }
return state;
}
queue_status_t Queue_destroy(queue_t *queue_obj)
{
    queue_status_t state=QUEUE_NOK;
    if(queue_obj==NULL)
    {
        state = QUEUE_NULL_POINTER;
    }
    else
    {
        free(queue_obj->queue_array);
        free(queue_obj);
        state=  QUEUE_OK;
    }
    return state;
}
