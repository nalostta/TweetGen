/*
milestone-#7 (main program file)
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

int main()
{
	int answer=0;
	char** Page=NULL;
	int PageSize=0;
	char input_str[STR_BUFF];
	while(answer!=6)
	{
		system("cls");
		PageMenu();
		scanf(" %d",&answer);
		switch(answer)
		{
			case 1: printf("\nEnter the string:");
					scanf(" %[^\n]s",input_str);
					add_string(input_str,&Page,&PageSize);
					break;
			case 2: printf("\nEnter the string:");
					scanf(" %s",input_str);
					answer=search_string(input_str,Page,PageSize);
					switch(answer)
					{
						case -1:printf("\nThe input string does not exist!\n");
								break;
						default: printf("\nthe index of the string is :%d",answer);
								break;
					}
					break;
			case 3: printf("\nEnter the index:");
					scanf("%d",&answer);
					if(answer<0)
					{
						printf("[error]:invalid index!\n");
					}else
					{
						remove_string(&Page,answer,&PageSize);
					}
					break;
			case 4:	SortPage(Page,PageSize);
					break;		
			case 5:	PrintPage(Page,PageSize);
					break;
			case 6: //break out of switch and compare in while loop
					break;
			default:printf("\n[error]:invalid command!");
					break;
		}
		while ((getchar()) != '\n');
		printf("\n\n..........press any key to continue");
		getchar();
	}
	return 0;
}
