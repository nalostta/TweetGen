/*
milestone-#4 (main program file)
author:manthan shah

Menu-based,user input program to provide the following functionality
1. Add an element to the Array the application should not allow the user to enter the same number twice
2. Search if an element exists in the array
3. Remove an element from the array
4. Sort the array
5. Print all elements in the array
6. Exit		*/

#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

#include<conio.h>
#include"milestone-3.h"
#include"milestone-4.h"
#include"milestone-12.h"

int main()
{
	int array_size = 0;
	int* array=(int*)calloc(BUFFER_SIZE,sizeof(int));
	int num,ans=0,flag;
	char c;
	int** array_head=&array;
	while(ans!=8)
	{
		system("@cls");
		ArrayMenu();
		scanf("%d",&ans);
		switch(ans)
		{
			case 1:printf("\nEnter the element to be added :");
			scanf("%d",&num);
			flag = add_element(num,array_head,&array_size);
			if(flag==0) printf("\nelement added!");
			else printf("\n[error]");
			break;
			case 2:printf("\nEnter the element to be searched :");
			scanf("%d",&num);
			flag = search_element(num,array_head,(unsigned int)array_size);
			if(flag==-1) printf("\nElement NOT found!");
			else printf("\nElement found at index :%d",flag);
			break;
			case 3:printf("\nEnter the element to be deleted :");
			scanf("%d",&num);
			flag = remove_element(num,array_head,&array_size);
			if(flag==0) printf("\nelement deleted successfully!");
			else printf("\n[error]");
			break;
			case 4:printf("\nEnter sort type (a/d):");
			scanf(" %c",&c);
			flag=sort_array(array,array_size,c);
			if(flag==0)printf("\nelement sorted successfully!");
			else printf("\n[error]");
			break;
			case 5: print_array(array_head,array_size);
			break;
			case 6: ans=SaveArray(array,array_size); //reusing ans to save the status of SaveArray
			if(ans==-1) printf("\n[error]:array not saved!");
			break;
			case 7: array=LoadArray(&array_size);
			break;
		}
		printf("\n\n..........press any key to continue");
		while ((getchar()) != '\n');	//flush buffer
		getchar();
	}
	return 0;
}
