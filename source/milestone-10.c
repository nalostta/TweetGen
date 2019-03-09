/*
milestone-#10
author:-manthan shah

a menu-based program to implement a dictionary with the following functionalities:
	add a word and its meaning
	lookup a word
	remove a word from the dictionary
	print all the entries in the dictionary 
	
utility Functions:
OrderedEntry()

NOTE: this program requires milestone-#5
----------------------------------------------------
logic:
struct entry   => word/entry
struct entry*  => sheet/WordIndex
struct entry** => dictionary/SheetIndex
----------------------------------------------------
*/
#include"milestone-10.h"

void PopEntry(struct entry** sheet)
{
	struct entry* delete = (*sheet);
	(*sheet)=(*sheet)->next;
	free(delete);
	return;
}

void AddDummyEntry(struct entry** sheet)
{
	struct entry* dummy=(struct entry*)malloc(sizeof(struct entry));
	str_copy(dummy->word,"");
	str_copy(dummy->def,"");
	dummy->next=(*sheet);
	(*sheet)=dummy;
	return;
}

void OrderedEntry(struct entry** sheet,struct entry* new)
{
	if(new==NULL)return;
	int compareValue,flag=0;
	struct entry* trav=(*sheet);
	if(trav==NULL)
	{
		(*sheet)=new;
		new->next=NULL;
		return;
	}
	AddDummyEntry(sheet);
	trav=(*sheet);
	while(trav!=NULL)
	{
		compareValue=str_compare(new->word,trav->word,0);
		if(compareValue<=0)  //0=>equal 1=>str1>str2  -1=>str2>str1
		{
			flag=1;
			break;
		}else
		{
			trav=trav->next;
		}
	}
	struct entry* travBack=(*sheet);
	while(travBack->next!=trav)
	{
		travBack=travBack->next;
	}
	if(flag)
	{
		new->next=travBack->next;
		travBack->next=new;
	}else
	{
		travBack->next=new;
		new->next=NULL;
	}
	PopEntry(sheet);
	return;
}

void AddEntry(struct entry** sheet,char* word,char* definition)
{
	struct entry* new=(struct entry*)malloc(sizeof(struct entry));
	str_copy(new->word,word);
	str_copy(new->def,definition);
	OrderedEntry(sheet,new);
	return;
}

void PrintDictionary(struct entry* trav)
{
	int index=0;
	while(trav!=NULL)
	{
		printf("%d.%s:%s\n",index++,trav->word,trav->def);
		trav=trav->next;
	}
}

int LookUp(struct entry** sheet,char* word)
{
	int index=0,compare;
	struct entry* trav=(*sheet);
	if(sheet==NULL) return -1;
	if(trav==NULL)return -1;
	do
	{
		compare=str_compare(trav->word,word,0);
		if(compare==0)
		{
			return index;
		}else
		{
			index++;
			trav=trav->next;
		}
	}while(trav!=NULL);
	return -1;
}

int RemoveEntry(struct entry** sheet,char* word)
{
	int index=0,compare;
	AddDummyEntry(sheet);
	struct entry* trav=(*sheet);
	do
	{
		compare=str_compare(trav->next->word,word,0);
		if(compare==0)
		{
			struct entry* delete = trav->next;
			trav->next=trav->next->next;
			free(delete);
			PopEntry(sheet);
			return 0;
		}else
		{
			index++;
			trav=trav->next;
		}
	}while(trav->next!=NULL);
	PopEntry(sheet);
	return -1;
}