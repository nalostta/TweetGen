/*
milestone-#6 (main program file)
author:manthan shah

functions:
1.str_copy : copy the string passed as parameter and return a pointer to the copied string.
2.tokenize : split string into an array of sub strings based on the tokens placed in between the characters
3.mem_copy : copies n bytes from source to destination or returns -1 on error
*/
#include"milestone-6.h"

int main()
{
	char* string1="hello:world!!!";
	char** string2 = str_tokenize(string1,':');
	int i;
	for(i=0;i<2;i++)
	{
		printf("\n%s",string2[i]);
	}
	return 0;
}

