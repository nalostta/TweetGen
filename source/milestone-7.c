/*
milestone-#7 
author:manthan shah

A menu driven program to work with strings and implement the following functions:
1. Add a 'string' to the array.The application should not allow the user to enter the same 'string' twice.
2. Search if a string exists in the array.
3. Remove a string from the array.
4. Sort the array.
5. Print all the strings in the array.
6. Exit.		
NOTE: requires milestone-#5 library
*/
#include"milestone-7.h"

void add_string(char* string,char*** PageIndex,int* PageSize)
{
    (*PageSize)++;
	int StringSize=str_length(string,0);
    (*PageIndex) = (char**)realloc((*PageIndex),(*PageSize)*sizeof(char*));
    (*PageIndex)[(*PageSize)-1] = (char*)malloc((StringSize)*sizeof(char));
    str_copy((*PageIndex)[(*PageSize)-1],string);
    return;
}

int search_string(char* string,char** Page,int PageSize) //will find the first instance only
{
	int i=0,index=-1;
	for(i=0;i<PageSize;i++)
	{
		if(str_compare(string,Page[i],0)==0)
		{
			index = i;
			break;
		}
	}
	return index;
}

void remove_string(char*** PageIndex,int index,int* PageSize)
{
	if((*PageIndex)[index]==NULL) return;
	int line;
	for(line=index;line<(*PageSize)-1;line++)
	{
		str_copy((*PageIndex)[line],(*PageIndex)[line+1]);
	}
	free((*PageIndex)[--(*PageSize)]);
	return;
}

void PrintPage(char** Page,int PageSize)
{
	int line;
	for(line=0;line<PageSize;line++)
	{
		printf("\n%s",Page[line]);
	}
	return;
}

void SortPage(char** Page,int PageSize)
{
	int line;
	char** trav=Page;
	char temp[STR_BUFF];
	for(line=0;line<PageSize-1;line++)
	{
		switch(str_compare(trav[line],trav[line+1],0))
		{
			case 0: //do nothing
					break;
			case 1:	//flip
					str_copy(temp,trav[line]);
					str_copy(trav[line],trav[line+1]);
					str_copy(trav[line+1],temp);
					break;
			case 2: //do nothing
					break;
		}
	}
	return;
}

void FreePage(char*** PageIndex,int* PageSize)
{
	int line;
	for(line=0;line<(*PageSize);line++)
	{
		free((*PageIndex)[line]);
	}
	PageIndex=NULL;
	*PageSize=0;
	return;
}

int get_PageSize(char*** PageIndex)
{
	if(PageIndex==NULL)return -1;
	int Line=0;
	int size=0;
	while(PageIndex[0][Line++]!=NULL&&Line<ITERATION_LIMIT)
	{
		size++;
	}
	return size;
}