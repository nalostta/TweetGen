/*
milestone-#10 (header file)
author:-manthan shah

a menu-based program to implement a dictionary with the following functionalities:
	add a word and its meaning
	lookup a word
	remove a word from the dictionary
	print all the entries in the dictionary 
	
utility Functions:
OrderedEntry()
NOTE: this program requires milestone-#5!
----------------------------------------------------
nomenclature:
struct entry   => word/entry
struct entry*  => sheet/WordIndex
struct entry** => dictionary/SheetIndex
----------------------------------------------------
*/

#ifndef _milestone_10
#define _milestone_10

#define WORD_BUFF 20
#define DEF_BUFF 150
//
#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

#include<string.h>
//
#include"milestone-5.h"

#define DictionaryMenu() printf("\n\n\tMENU:\n1.Add entry\n2.Lookup a word\n3.Remove a word\n4.Print the Dictionary\n5.Save Dictionary\n6.Load Dictionary\n7.EXIT\n\ncommand :")

struct entry
{
	char word[WORD_BUFF];
	char def[DEF_BUFF];
	struct entry* next;
};

//utility functions:
void OrderedEntry(struct entry** sheet,struct entry* new); //clear
void AddDummyEntry(struct entry** sheet); //clear
void PopEntry(struct entry** sheet); //clear
//main functions:
void AddEntry(struct entry** sheet,char* word,char* definition); //clear
int LookUp(struct entry** sheet,char* word);
int RemoveEntry(struct entry** sheet,char* word);
void PrintDictionary(struct entry* trav);  //clear

#endif