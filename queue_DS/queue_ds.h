#ifndef _QUEUE_DS_H_
#define _QUEUE_DS_H_
#include "std_types.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_t
{
    void **queue_array;
    sint32_t queue_count;
    sint32_t queue_rear;
    sint32_t queue_front;
    uint32_t queue_max_size;
}queue_t;
typedef enum queue_status_t
{
    QUEUE_NOK=0,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER

}queue_status_t;
queue_t* create_queue(uint32_t max_size,queue_status_t *state);
queue_status_t Enqueue(queue_t* queue_obj, void* item_ptr);
void* Dequeue(queue_t* queue_obj,queue_status_t* queue_status);
void* Queue_front(queue_t* queue_obj,queue_status_t* queue_status);
void* Queue_rear(queue_t* queue_obj,queue_status_t* queue_status);
queue_status_t Queue_count(queue_t *queue_obj,uint32_t *elements_count);
queue_status_t Queue_destroy(queue_t *queue_obj);
#endif // _QUEUE_DS_H_
