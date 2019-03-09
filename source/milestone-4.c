/*
milestone-#4
author:manthan shah

Menu-based,user input program to provide the following functionality
1. Add an element to the Array the application should not allow the user to enter the same number twice
2. Search if an element exists in the array
3. Remove an element from the array
4. Sort the array
5. Print all elements in the array
6. Exit		*/

#include"milestone-4.h"

int add_element(int num,int** array_head,int* array_size)
{	
	int duplicate = search_element(num,array_head,(unsigned int)(*array_size));
	if(duplicate!=-1) //if search_element returns a non -ve index, a duplicate exists 
	{
		return -1;
	}else
	{
		(*array_size)++;
		*array_head = realloc((*array_head),(*array_size)*sizeof(int));
		(*array_head)[(*array_size)-1]=num;
		return 0;
	}
}

int remove_element(int num,int** array_head,int* array_size)
{
	int element_location = search_element(num,array_head,(*array_size));
	if(element_location<0)
	{
		return -1;
	}else
	{
		int i;
		for(i=element_location;i<(*array_size);i++)
		{
			(*array_head)[i] = (*array_head)[i+1];
		}
		(*array_size)--;
	}
	return 0;
}

void print_array(int** array_head,int array_size)
{
	int i;
	for(i=0;i<array_size;i++)
	{
		printf(" %d",(*array_head)[i]);
	}
}
