/*
milestone-#3 (header file)
author:manthan shah

functions:
1.user input array
2.sort ascending/descending via bubble sort algorithm
3.check for an entry
*/
#ifndef _milestone_3
#define _milestone_3

#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

int get_array(int* array,unsigned int array_size); //does not allocate space for array
int search_element(int element,int** array_head,unsigned int array_size);  //function designed to used by the next program(milestone-#4_main) assumes an unsorted array
int sort_array(int* array,unsigned int array_size,char sort_type);
#endif