#ifndef include$
#define include$
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#endif

#ifdef lazy
#define ll ->
#endif


int alt = 0;
int frmgatecounter=1;

void cls()
{
	system("@cls||clear");
}



char formality(){
	system("@cls||clear");
	printf("\nInitiate program? (y/n) :");
	char answer;
	scanf(" %c",&answer);

	if(answer=='y'){
		return 0;
	}else if(answer == 'n')
	{
		printf("\nprogram exit(0)");
		exit(0);
    }
	else{
		printf("\ninvalid input!\n\nExiting program...");
		exit(1);
		printf("\nprogram exit(1)");
	}
}

int gate()
{
	printf("\nGATE CODE %d (0/1) :",frmgatecounter++);
	int gatecode;
	scanf(" %d",&gatecode);
	if(gatecode == 0)
	{
		return 0;
	}
	else
	{
		exit(0);
	}
}

int alternate()
{
	if(alt == 0)
	{
		alt = 1;
	}else if(alt == 1)
	{
		alt = 0;
	}
	return alt;
}