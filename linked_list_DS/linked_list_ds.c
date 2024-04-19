#include "linked_list_ds.h"

void insert_at_begining(node_t **mylist)
{
    node_t *temp_node;
    uint32_t value;
    if(mylist!= NULL)
    {
        temp_node=(node_t*)malloc(sizeof(node_t));
        printf("Enter the node value: \n");
        scanf("%i",&value);
        temp_node->data=value;
        temp_node->next=*mylist;
        *mylist=temp_node;
    }
    else{/*Do Nothing*/}

}
void insert_at_end(node_t *mylist)
{
    node_t *temp_node;
    uint32_t value=0;
    uint32_t count;
    if(mylist!= NULL)
    {

        temp_node=(node_t*)malloc(sizeof(node_t));
        printf("Enter the node value: \n");
        scanf("%i",&value);
        temp_node->data=value;
        temp_node->next=NULL;
        while ((count)<(get_list_count(mylist)))
        {
            mylist = mylist->next;
            count++;
        }
        mylist->next=temp_node;



    }
    else{/*Do Nothing*/}

}
void insert_after_position(node_t *mylist)
{

}
void delete_at_position(node_t *mylist);
void retieval (node_t *mylist);
void traverse (node_t *mylist);
void display_list(node_t *mylist)
{
    if(mylist!=NULL)
    {
        while(mylist!=NULL)
        {
            printf("->(%i)",mylist->data);
            mylist=mylist->next;
        }
    }
    else{/*Do Nothing*/}
}
uint32_t get_list_count(node_t *mylist)
{
    uint32_t count=0;
    if(mylist!=NULL)
    {
        while(mylist!=NULL)
        {
            count++;
            mylist=mylist->next;
        }
    }
    else{/*Do Nothing*/}
    return count;
}
void reverse_list(node_t **mylist);
