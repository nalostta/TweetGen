/*
milestone-#5
author:manthan shah

functions:
1.Find the length of the string or return -1 on error.
2.Copy string 2 into string 1, returns 0 on success or -1 on error
3.compare strings and -> if str1 is less than str2 the function should return -1 if str1 is greater than str2 it should return 1 and if both are equal then return 0
4.find character: returns the position where ch is in str and if not present returns -1
5.find substring :returns the position where str2 is in str1 and if not present returns -1
*/
#include"milestone-5.h"

int str_length(char* string,int ignore_space) //ignores space if the corresponding parameter set to 1
{
	if(string == NULL) return -1;
	int counter=0,i=0;
	while((string[i]!=0)&&(i<=ITERATION_LIMIT))
	{
		counter++;
		i++;
		if(string[i] == 32 && ignore_space == 1)
		{
			counter--;
		}
		if(i==ITERATION_LIMIT)
		{
			printf("[error]:function str_length: iteration limit reached");
			return -1;
		}
	}
	return ++counter;
}
 
int str_copy(char* str1,char* str2) //copies till the length of str2
{
	int i;
	int strlen = str_length(str2,0); 
	if(strlen==-1)return -1; //error case
	for(i = 0;i<strlen;i++)
	{
		str1[i] = str2[i];
	}
	return 0;
}


int str_compare(char* str1,char* str2,int ignore_size) //0=>equal 1=>str1>str2  -1=>str2>str1
{
	int i=0;
	//
	while((str1[i])!=(int)NULL&&(str2[i]!=(int)NULL))
	{
		if(str2[i] > str1[i])
		{
			return -1;
		}
		if(str2[i] < str1[i])
		{
			return 1;
		}
		i++;
	}
	if(ignore_size==1)
	{
		return 0;
	}else
	{
		if((str1[i])==(int)NULL&&(str2[i])!=(int)NULL)
		{
			return -1;
		}else 
		if(str2[i]==(int)NULL&&(str1[i])!=(int)NULL)
		{
			return 1;
		}else
		{
			return 0;	
		}
	}
}

int str_compare_till(char* str1,char* str2,int CompareSize) //0=>equal 1=>str1>str2  -1=>str2>str1
{
	int i=0;
	for(i=0;i<CompareSize;i++)
	{
		if(str2[i] > str1[i])
		{
			return -1;
		}
		if(str2[i] < str1[i])
		{
			return 1;
		}
	}
	return 0;
}

int str_find_char(char* str,char ch)
{
	int len = str_length(str,0);
	int flag = -1,i;
	for(i=0;i<len;i++)
	{
		if(ch == str[i])
		{
			return flag;
		}
	}
	return -1;
}

int str_find_substring(char* BaseString,char* SubString,int SubStringSize) //str1=base string, str2=sub-string
{
	int index = 0,flag=-1;
	if(BaseString==NULL||SubString==NULL)return -1;
	while(BaseString[index] != 0)
	{
		int indexfound = str_compare_till(&BaseString[index],SubString,SubStringSize);
		if(indexfound == 0)
		{
			flag=index;
			break;
		}else
		{
			index++;
		}
	}
	return flag;
}



