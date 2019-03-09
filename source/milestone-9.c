/*
milestone-#9 
author:manthan shah

Linked list functions
functions:
 1 — Count() :counts the number of times a given int occurs in a list.
 2 — GetNth():takes a linked list and an integer index and returns the data value stored in the node at that index position. 
 3 — DeleteList() :takes a list, deallocates all of its memory and sets its head pointer to NULL (the empty list). 
 4 — Pop() :Pop() takes a non-empty list, deletes the head node, and returns the head node's data.
 5 — InsertNth() :can insert a new node at any index within a list.
 6 — SortedInsert() : given a list that is sorted in increasing order, and a single node, inserts the node into the correct sorted position in the list.
 7 — InsertSort() :given a list, rearranges its nodes so they are sorted in increasing order. It should use SortedInsert().
 8 — Append() :that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',and then sets 'b' to NULL
 9 — FrontBackSplit() :Given a list,this function splits it into 2 sublists.1 for the front half,& 1 for the back half.If the no. of elements is odd, the extra element goes in the front list.
10 - RemoveDuplicates() :which takes a list sorted in increasing order and deletes any duplicate nodes from the list.
11 — MoveNode() :MoveNode() takes two lists, removes the front node from the second list and pushes it onto the front of the first.
12 — AlternatingSplit() :takes one list and divides up its nodes to make two smaller lists.
13 — ShuffleMerge() : Given two lists, merge their nodes together to make one list, taking nodes alternately between the two lists.
14 — SortedMerge() : takes two lists, each of which is sorted in increasing order,and merges the two together into one list which is in increasing order.
15 — MergeSort() :  using recursion.
16 — SortedIntersect() :Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists.
17 — Reverse() : iteratively reverses a list by rearranging all the .next pointers and the head pointer.


// basic utility functions :
push();
printList();
build123();
array_to_list();
*/
#include"milestone-9.h"

struct node* push(struct node* head,int data)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = head;
	return new;
}

void PrintList(struct node* head)
{
	printf("\n->");
	while(head!=NULL)
	{
		//if(head->next==NULL) return;
		printf(" %d",head->data);
		head=head->next;
	}
	return;
}

struct node* build123()
{
	struct node* head = NULL;
	head = push(head,3);
	head = push(head,2);
	head = push(head,1);
	return head;
}

void add_dummy(struct node** headref)
{
	struct node* dummy = (struct node*)malloc(sizeof(struct node));
	if(headref==NULL)
	{
		dummy->data=0;
		dummy->next=NULL;
	}else
	{
		dummy->data=(*headref)->data;
		dummy->next=(*headref);
	}
	(headref)=&dummy;
	return;
}

struct node* array_to_list(int* p,unsigned int size)
{
	int i=0;
	struct node* head=NULL;
	while(i<size)
	{
		head=push(head,p[size-(i++)-1]);
	}
	return head;
}
//

int count(struct node* traverser,int num)
{
	int num_count=0;
	while(traverser!=NULL)
	{
		if(traverser->data==num)num_count++;
		traverser=traverser->next;
	}
	return num_count;
}

int GetNth(struct node* traverser,unsigned int index)
{
	if(traverser==NULL) return -1;
	int i;
	for(i=0;i<index;i++)
	{
		if(traverser->next==NULL) return -1;
		traverser=traverser->next;
	}
	return traverser->data;
}

void DeleteList(struct node** HeadRef)
{
	struct node* travbase=*HeadRef;
	if(travbase==NULL) return;
	if(travbase->next==NULL)
	{
		free(travbase);
		return;
	}
	struct node* travfront = travbase->next;
	while(travfront->next!=NULL)
	{
		travfront = travbase->next;
		free(travbase);
		travbase=travfront;
	}
	free(travbase);
	(*HeadRef)=NULL;
	return;
}

int pop(struct node** headref) //----------pop----------
{
	struct node* point = (*headref);
	if(point==NULL) return 0;
	(*headref) = point->next;
	int data = point->data;
	free(point);
	return data;
}

int InsertNth(struct node** headref,int data,unsigned int index) //will not work for index 0
{
	int i;
	struct node* trav = *headref;
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	if(index==0)
	{
		new->next = *headref;
		*headref=new;
		return 0;
	}
	for(i=1;i<index;i++)
	{
		if(trav->next==NULL)return -1; 
		trav=trav->next;
	}
	new->next=trav->next;
	trav->next=new;
	return 0;
}

int SortedInsert(struct node** headref,int data)
{
	if(headref==NULL) return _ERROR_ ;
	struct node* trav = (*headref);
	if(trav==NULL)
	{
		(*headref)=(struct node*)malloc(sizeof(struct node));
		(*headref)->next=NULL;
		(*headref)->data=data;
		return 0;
	}
	struct node* new = (struct node*)malloc(sizeof(struct node));
	int flag = 0;
	while(trav->next!=NULL)
	{
		if(trav->data > data)
		{
			flag=1;
			break;
		}else
		{
			trav=trav->next;
		}
	}
	if(flag)
	{
		new->data=trav->data;
		trav->data=data;
		new->next=trav->next;
		trav->next=new;
	}else
	{
		trav->next=new;
		new->next=NULL;
		new->data=data;
	}
	return 0;
}

struct node* InsertSort(struct node** headref)
{
	struct node* trav=(*headref);
	struct node* new_list=NULL;
	int data=0;
	while(trav!=NULL)
	{
		trav=trav->next;
		data=pop(headref);
		SortedInsert(&new_list,data);
	}
	return new_list;
}

void append(struct node** aref,struct node** bref)
{
	struct node* traverse;
	traverse = (*aref);
	if(traverse != NULL)
	{
		while(traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = (*bref);
	}else
	{
		(*aref)=(*bref);
	}
	(*bref) = NULL;
	return;
}

void FrontBackSplit(struct node** source,struct node** frontref,struct node** backref)
{
	struct node* trav=(*source);
	if(trav==NULL || source==NULL)
	{
		(*frontref)=NULL;
		(*backref)=NULL;
		return;
	}
	struct node* trav_fast=trav;
	if(trav->next==NULL)
	{
		(*frontref)=(*source);
		(*backref)=NULL;
	}
	while(trav_fast!=NULL)
	{
		if(trav_fast->next!=NULL)
		{
			trav_fast=trav_fast->next;
			if(trav_fast->next!=NULL)
			{
				trav_fast=trav_fast->next;
				trav=trav->next;
			}else
			{
				break;
			}
		}else
		{
			break;
		}
	}
	(*backref)=trav->next;
	trav->next=NULL;
	(*frontref)=(*source);
	(*source)=NULL;
	return;
}

void RemoveDuplicates(struct node** headref)  //will terminate abruptly if the list is not sorted.
{
	struct node* trav=(*headref);
	if(trav==NULL) return;
	struct node* remove;
	while(trav->next!=NULL)
	{
		if(trav->data>trav->next->data) return;
		if(trav->data == trav->next->data)
		{
			remove = trav->next;
			trav->next=remove->next;
			free(remove);
		}
		trav=trav->next;
	}
	return;
}

void MoveNode(struct node** destRef, struct node** sourceRef)
{
	(*destRef)=push((*destRef),pop(sourceRef));
	return;
}

void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef)  //flips the list
{
	int flag=1;
	struct node* trav=(source);
	while(trav!=NULL)
	{
		if(flag)
		{
			flag=0;
			MoveNode(aRef,&trav);			
		}else
		{
			flag=1;;
			MoveNode(bRef,&trav);	
		}
	}
	return;
}

struct node* ShuffleMerge(struct node* a, struct node* b)
{
	struct node* head=NULL;
	head = push(head,0);
	struct node* trav=head;
	while(1)
	{
		if(a==NULL)
		{
			if(trav==NULL)return b;
			else
			{
				trav->next=b;
				pop(&head);
				return (head);
			}
		}else
		if(b==NULL)
		{
			if(trav==NULL)return a;
			else
			{
				trav->next=a;
				pop(&head);
				return (head);
			}
		}else
		{
			trav->next=(struct node*)malloc(sizeof(struct node));
			trav=trav->next;
			trav->data=pop(&a);
			trav->next=(struct node*)malloc(sizeof(struct node));
			trav=trav->next;
			trav->next=NULL;
			trav->data=pop(&b);
		}
	}
	pop(&head);
	return (head);
}

struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node* head=NULL;
	head = push(head,0);
	struct node* trav=head;
	while(1)
	{
		if(a==NULL)
		{
			if(trav==NULL)return b;
			else
			{
				trav->next=b;
				break;
			}
		}else
		if(b==NULL)
		{
			if(trav==NULL)return a;
			else
			{
				trav->next=a;
				break;
			}
		}else
		{
			trav->next=(struct node*)malloc(sizeof(struct node));
			trav=trav->next;
			trav->next=NULL;
			//
			if(a->data<=b->data)
			{
				trav->data=pop(&a);
			}else
			{
				trav->data=pop(&b);
			}
		}
	}
	pop(&head);
	return (head);
}

void MergeSort(struct node** headRef)
{
	if(headRef==NULL)return; //error scenarios
	if(*headRef==NULL)return; //error scenarios
	if((*headRef)->next!=NULL)
	{
		struct node* a=NULL;
		struct node* b=NULL;
		FrontBackSplit(headRef,&a,&b);
		MergeSort(&a);
		MergeSort(&b);
		(*headRef) = SortedMerge(a,b);
	}
	return;
}

struct node* SortedIntersect(struct node* a, struct node* b) //assumes no repetitions in either of the lists! 
{
	struct node* head=NULL;
	head=push(head,-99999);
	struct node* trav=head;
	int i=0;
	while(a!=NULL && b!=NULL && i++<ITERATION_LIMIT)
	{
		if(a->data==b->data)
		{
			trav->next=(struct node*)malloc(sizeof(struct node));
			trav=trav->next;
			trav->data=a->data;
			a=a->next;
			b=b->next;
		}else
		{
			if(a==NULL || b==NULL)break;
			if(a->data<b->data)a=a->next;
			else if(b->data<a->data)b=b->next;
		}
	}
	trav->next=NULL;
	pop(&head);
	return head;
}

void Reverse(struct node** headref)
{
	if(headref==NULL || (*headref)==NULL) return;
	struct node* back=(*headref);
	struct node* mid;
	struct node* front;
	if(back->next!=NULL)
	{
		mid=back->next;
		if(mid->next!=NULL)
		{
			front=mid->next;
		}else
		{
			mid->next=back;
			back->next=NULL;
			(*headref)=mid;
			return;
		}
	}else return;
	back->next=NULL;
	do{
		mid->next=back;
		back=mid;
		mid=front;
		front=front->next;
	}while(front!=NULL);
	mid->next=back;
	(*headref)=mid;
	return;
}
