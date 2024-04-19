#include <stdio.h>
#include <stdlib.h>
#include "linked_list_ds.h"

node_t *mylist;
uint32_t count=0;

int main()
{
    insert_at_begining(&mylist);
    insert_at_begining(&mylist);
    insert_at_begining(&mylist);
    count=get_list_count(mylist);
    printf("List count = %i \n=============================\n",count);
    display_list(mylist);
    insert_at_end(mylist);
    display_list(mylist);
    return 0;
}
