/*
milestone-#12 (header file)
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

#ifndef _milestone_12
#define _milestone_12

#include"milestone-10.h"
//
#ifndef STDIO__
#define STDIO__
#include<stdio.h>
#endif
//
#define LOAD_ARRAY_FILE_NAME_ SavedArray
#define BUFFER_SIZE 100

#ifndef ITERATION_LIMIT
#define ITERATION_LIMIT 999
#endif

int* LoadArray(int* array_size);
int SaveArray(int* array,int array_size);
void SaveDictionary(struct entry** sheet,char* filename);
struct entry* LoadDictionary(char* filename);

#endif