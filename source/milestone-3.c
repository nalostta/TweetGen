/*
milestone-#3
author:manthan shah

functions:
1.user input array
2.sort ascending/descending via bubble sort algorithm
3.check for an entry
*/

#include"milestone-3.h"

int get_array(int* array,unsigned int array_size)
{
	unsigned int i;
	for(i=0;i<array_size;i++)
	{
		if(array[i]==(int)NULL)
		{
			return -1;
		}else scanf("%d",&array[i]);
	}
	return 0;
}

int search_element(int element,int** array_head,unsigned int array_size)  //function assumes an unsorted array
{
	unsigned int i=0;
	int* trav=(*array_head);
	for(i=0;i<array_size;i++)
	{
		if(trav[i]==element) //error statement
		{
			return i;
		}else
		{
			continue;
		}
	}
	return -1;
}

int sort_array(int* array,unsigned int array_size,char sort_type)
{
	unsigned int i,j;
	if(sort_type!='a'&&sort_type!='d') return -1;
	for(i=0;i<array_size;i++)
	{
		for(j=0;j<array_size-1;j++)
		{
			if((array[j]>array[j+1]&&sort_type=='a') || (array[j]<array[j+1]&&sort_type=='d'))
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 0;
}

