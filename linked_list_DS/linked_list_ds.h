#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "std_types.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    uint32_t data;
    struct node_t *next;
}node_t;

void insert_at_begining(node_t **mylist);
void insert_at_end(node_t *mylist);
void insert_after_position(node_t *mylist);
void delete_at_position(node_t *mylist);
void retieval (node_t *mylist);
void traverse (node_t *mylist);
void display_list(node_t *mylist);
void reverse_list(node_t **mylist);

uint32_t get_list_count(node_t *mylist);


#endif // _LINKED_LIST_H_
