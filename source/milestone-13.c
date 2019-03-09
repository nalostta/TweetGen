/*
milestone-#13 (header file)
author:manthan shah

Linked list (part 2)
functions:
RecursiveReverse() : Recursively reverses the given linked list by changing its .next pointers and its head pointer in one pass of the list.
*/

#include"milestone-13.h"

void RecursiveReverse(struct node** headRef)
{
	struct node* trav=(*headRef);
	static struct node* end=NULL;
	static int instance=0;
	if(trav->next->next==NULL)
	{
		end = trav->next;
		end->next=trav;
		trav->next=NULL;
		(*headRef) = end;
		return;
	}else
	{
		instance++;
		RecursiveReverse(&(trav->next));
		instance--;
		(trav->next)->next=trav;
		trav->next=NULL;
	}
	if(instance==0)(*headRef)=end;
	return;
}