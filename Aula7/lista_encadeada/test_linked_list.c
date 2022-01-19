#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	LinkedList *L = LinkedList_create();
	LinkedList_print(L);
	LinkedList_add_first(L,10);
	LinkedList_print(L);
	LinkedList_add_first(L,10);
	LinkedList_print(L);
	LinkedList_add_first(L,10);
	LinkedList_print(L);
	
	return 0;
}
