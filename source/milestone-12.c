/*
milestone-#12
author:manthan shah

|
Modify Milestone 4 to add 2 menu items
To save the array in a file
To load the array from a file
||
Modify Milestone 10 and the following features to your dictionary
Load the dictionary from a file
Save the dictionary to a file

functions:
LoadArray()
SaveArray();
//
LoadDictionary();
SaveDictionary();
*/
#include"milestone-12.h"
#include<string.h>

int* LoadArray(int* array_size)
{
	int count=0,k=0;
	FILE* fpointer = fopen("SavedArray.txt","r");
	if(fpointer==NULL) return NULL;
	char trav[BUFFER_SIZE];
	int* array=(int*)malloc(BUFFER_SIZE*sizeof(int));
	while(!feof(fpointer))
	{
		fgets(trav,100,fpointer);
		k=0;
		while(trav[k]!='#')
		{
			int num=0;
			while(trav[k]!=':' && trav[k]!='#')
			{
				num*=10;
				num+=(int)trav[k]-48;
				k++;
			}
			array[count++]=num;
			k++;
		}
	}
	fclose(fpointer);
	(*array_size)=count;
	return array;
}

int SaveArray(int* array,int array_size)
{
	FILE* fpointer = fopen("SavedArray.txt","w");
	if(fpointer==NULL) return -1;
	int i=0;
	for(i=0;i<array_size;i++)
	{
		int status=fprintf(fpointer,"%d:",array[i]);
		if(status==-1)return -1;
	}
	fprintf(fpointer,"#");
	fclose(fpointer);
	return 0;
}

struct entry* LoadDictionary(char* filename)
{
	FILE* fpointer = fopen(filename,"r");
	if(fpointer==NULL) return NULL;
	char line[WORD_BUFF+DEF_BUFF];
	char word[WORD_BUFF];
	char def[DEF_BUFF];
	struct entry* list=NULL;
	while(!feof(fpointer) && fgets(line,WORD_BUFF+DEF_BUFF,fpointer)!=NULL)
	{
		int i=0,j=0;
		int notempty=(line[0]!='\n')&&(line[0]!=' ');
		while(line[i]!=':'&&notempty)
		{
			word[i]=line[i];
			i++;
		}
		if(notempty)word[i++]=0;
		//printf("\nword=%s\n",word);
		while(line[i]!=';'&&notempty)
		{
			def[j]=line[i];
			i++;
			j++;
		}
		if(notempty)def[j]=0;
		//printf("\ndef=%s\n",def);
		if(notempty)AddEntry(&list,word,def);
	}
	fclose(fpointer);
	return list;
}

void SaveDictionary(struct entry** sheet,char* filename)
{
	FILE* fpointer = fopen(filename,"w+");
	if(fpointer==NULL) return;
	struct entry* trav=(*sheet);
	while(trav!=NULL)
	{
		fprintf(fpointer,"%s:%s;\n",trav->word,trav->def);
		trav=trav->next;
	}
	fclose(fpointer);
	return;

}