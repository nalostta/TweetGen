/*
milestone-#5 (header file)
author:manthan shah

functions:
1.Find the length of the string or return -1 on error.
2.Copy string 2 into string 1, returns 0 on success or -1 on error
3.compare strings and -> if str1 is less than str2 the function should return -1 if str1 is greater than str2 it should return 1 and if both are equal then return 0
4.find character: returns the position where ch is in str and if not present returns -1
5.find substring :returns the position where str2 is in str1 and if not present returns -1
*/

#ifndef _milestone_5
#define _milestone_5
//
#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif
//
#ifndef ITERATION_LIMIT
#define ITERATION_LIMIT 999
#endif

int str_length(char* string,int ignore_space); 
int str_copy(char *str1, char *str2);  					    //copies till the length of str2	
int str_find_char(char *str, char ch);
int str_compare(char* str1,char* str2,int ignore_size);
int str_find_substring(char* BaseString,char* SubString,int SubStringSize);

int str_compare_till(char* str1,char* str2,int CompareSize); //0=>equal 1=>str1>str2  -1=>str2>str1

#endif