/*
milestone-#4
author:manthan shah (header file)

Menu-based,user input program to provide the following functionality
1. Add an element to the Array the application should not allow the user to enter the same number twice
2. Search if an element exists in the array
3. Remove an element from the array
4. Sort the array
5. Print all elements in the array
6. Exit		
*/

#ifndef _milestone_4
#define _milestone_4
//
#include"milestone-3.h"

#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

#define ArrayMenu() printf("\n\n\tARRAY MENU:\n1.Add element\n2.search element\n3.remove element\n4.sort the array\n5.print the array\n6.Save array into a file\n7.Load array from a file\n8.EXIT\n\ncommand :")

int add_element(int num,int** array_head,int* array_size);
int remove_element(int num,int** array_head,int* array_size);
void print_array(int** array_head,int array_size);

#endif