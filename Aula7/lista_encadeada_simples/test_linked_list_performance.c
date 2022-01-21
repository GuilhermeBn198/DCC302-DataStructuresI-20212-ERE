#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	LinkedList *L_slow = LinkedList_create();
	double time_spent = 0.0;
	clock_t begin = clock();
	for (int i = 0; i < 200000; i++){
		LinkedList_add_last_slow(L_slow, i);
	}
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Performance ad_las_slow %f seconds", time_spent);
	
	//------------------------------------------------------------

	LinkedList *L_fast = LinkedList_create();
	double time_spent2 = 0.0;
	clock_t begin2 = clock();
	for (int i = 0; i < 200000; i++){
		LinkedList_add_last(L_fast, i);
	}
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("Performance add_las %f seconds\n", time_spent2);


	return 0;
}
