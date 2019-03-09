/*
Recursive Reverse test
author: manthan shah
*/
#include<stdio.h>
#include"milestone-9.h"
#include"milestone-13.h"

int main()
{
	struct node* head=NULL;
	head=push(head,2);
	head=push(head,3);
	RecursiveReverse(&head);
	PrintList(head);
	return 0;
}