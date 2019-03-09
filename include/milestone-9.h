/*
milestone-#9 (header file)
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
#ifndef _milestone_9
#define _milestone_9

struct node
{
	int data;
	struct node* next;
};

#define _ERROR_ -999
#ifndef ITERATION_LIMIT
#define ITERATION_LIMIT 999
#endif


#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

//utility functions:
struct node* push(struct node* head,int data); //clear
void PrintList(struct node* head); //clear
struct node* build123(); //clear
void add_dummy(struct node** headref); //clear
struct node* array_to_list(int* p,unsigned int size); //reads integer array makes a corresponding linked list and returns it //clear!

//main list functions:
int count(struct node* traverser,int num); //clear
int GetNth(struct node* traverser,unsigned int index); //clear
void DeleteList(struct node** headref);//clear
int pop(struct node** headref); //clear
int InsertNth(struct node** headref,int data,unsigned int index); //clear
int SortedInsert(struct node** headref,int data); //clear!
struct node* InsertSort(struct node** headref); //clear!
void append(struct node** aref,struct node** bref); //clear
void FrontBackSplit(struct node** source,struct node** frontref,struct node** backref); //clear & optimised!
void RemoveDuplicates(struct node** headref); //clear
void MoveNode(struct node** destRef, struct node** sourceRef); //clear
void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef); //clear 
struct node* ShuffleMerge(struct node* a, struct node* b); //clear
struct node* SortedMerge(struct node* a, struct node* b); //clear* (move node is node used here)
void MergeSort(struct node** headRef); //clear
struct node* SortedIntersect(struct node* a, struct node* b); //clear but could do better with more testing...
void Reverse(struct node** headref); //clear

#endif