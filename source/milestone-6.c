/*
milestone-#6 
author:manthan shah

functions:
1.str_copy : copy the string passed as parameter and return a pointer to the copied string.
2.tokenize : split string into an array of sub strings based on the tokens placed in between the characters
3.mem_copy : copies n bytes from source to destination or returns -1 on error
*/

#include"milestone-6.h"

char* quick_str_copy(const char* str,int len)
{													/*doubt: */			/*in this particular function, first the length of the string is calculated*/
	char* copy = (char*)calloc(len,sizeof(char));   /*and used to run a for loop but I could also opt for a while loop running */
	int i;											/*till pointer reaches null and use realloc inside to allocate one byte for*/
	for(i=0;i<len+1;i++)							/*each new iteration, however which one would be better? in terms of the   */
	{												/*cost of execution time and memory and would this matter?*/
		*copy = *str;
		copy++;
		str++;
	}
	copy = copy - len-1;
	return copy;
}

char** str_tokenize(char *str, char c)
{
	int len = str_length(str,0);
	int i=0,tokenCount=0,stringsize=0,index=0;
	for(i=0;i<len;i++)
	{
		if(str[i]==c)tokenCount++;
	}
	char** block = (char**)calloc(tokenCount,sizeof(char*));
	i=0;
	while(i<len)
	{
		stringsize=0;
		while(str[i+stringsize]!=c)
		{
			stringsize++;
		}
		block[index]=quick_str_copy((const char* )&str[i],stringsize-1);
		index++;
		i+=stringsize+1;
	}
	return block;
}

void *mem_copy(void *dest, const void *src, unsigned int n)
{
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	int i = str_length(p2,0);
	if(i<n) return NULL;
	for(i=0;i<n;i++)
	{ 
		p1[i] = p2[i];
	}
	p1[n]=0;
	return p1;
}