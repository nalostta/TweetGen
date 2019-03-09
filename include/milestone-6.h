/*
milestone-#6 (header file)
author:manthan shah

functions:
1.str_copy : copy the string passed as parameter and return a pointer to the copied string.
2.tokenize : split string into an array of sub strings based on the tokens placed in between the characters
3.mem_copy : copies n bytes from source to destination or returns -1 on error
*/

#ifndef _milestone_6
#define _milestone_6

//
#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#ifndef stdlib__
#define stdlib__
#include<stdlib.h>
#endif

#ifndef string__
#define string__
#include<string.h>
#endif
//

#include"milestone-5.h"

char* quick_str_copy(const char* str,int len);
char** str_tokenize(char *str, char c);
void *mem_copy(void *dest, const void *src, unsigned int n);

#endif