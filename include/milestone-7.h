/*
milestone-#7 (header file)
author:manthan shah

A menu driven program to work with strings and implement the following functions:
1. Add a 'string' to the array.The application should not allow the user to enter the same 'string' twice.
2. Search if a string exists in the array.
3. Remove a string from the array.
4. Sort the array.
5. Print all the strings in the array.
6. Exit.		
NOTE: requires milestone-#5 library
------------------------------------------------------------------------
logic:

[]			   = char		         (char)
[...] 		   = string/line  		 (char*) 
[str1...strN]  = Page/LineIndex      (char**)
[Page...PageN] = book/file/PageIndex (char***)
------------------------------------------------------------------------
*/
#ifndef _milestone_7
#define _milestone_7

#ifndef STR_BUFF
#define STR_BUFF 50
#endif
//
#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

#ifndef stdstring__
#define stdstring__
#include<string.h>
#endif
//
#include"milestone-5.h"

#ifndef ITERATION_LIMIT
#define ITERATION_LIMIT 999
#endif

#define PageMenu() printf("\nString Program\n\tMENU:\n1.Add line\n2.search line\n3.remove line\n4.sort ascending\n5.print Page\n6.EXIT\n\ncommand :")

//utility functions
int get_PageSize(char*** PageIndex); //clear
void FreePage(char*** PageIndex,int* PageSize); //clear
//main functions
void add_string(char* string,char*** PageIndex,int* PageSize); //clear
int search_string(char* string,char** Page,int PageSize); //clear
void remove_string(char*** PageIndex,int index,int* PageSize); //clear
void SortPage(char** Page,int PageSize); //clear
void PrintPage(char** Page,int PageSize); //clear

#endif