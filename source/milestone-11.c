#include<stdio.h>

int main()
{
	FILE * fpointer;
	fpointer = fopen("dictionaryinput.txt","r");
	if(fpointer==NULL)
	{
		printf("\n[error]:no input file found!\n");
		return -1;
	}
	char line[150];
	while(!feof(fpointer))
	{
		fgets(line,150,fpointer);
		int i=0;
		printf("\nword:");
		while(line[i]!=':')
		{
			printf("%c",line[i]);
			i++;
		}
		i++;
		printf("\ndefinition:");
		while(line[i]!='\0')
		{
			printf("%c",line[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}