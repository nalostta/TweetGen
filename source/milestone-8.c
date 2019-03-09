/*
milestone-#8 
author:manthan shah

functions:
1.gensort
2.compar
3.exchng
*/
#include"milestone-8.h"

void* gensort(void* input,int sortsize,int blocksize,int (*compar)(const void*,const void*))
{
    int i,j;
    char* a;
    a = (char*)input;
    for(i=0;i<sortsize;i++)
    {
		for(j=0;j<sortsize-1;j++)
		{
			if(compar(&a[j*blocksize],&a[(1+j)*blocksize]) > 0)
			{
				exchng(&a[j*blocksize],&a[(1+j)*blocksize],blocksize);
			}
		}
    }
	return input;
}

void exchng(char* a,char* b,int blocksize)
{
    char temp;
    int i;
    for(i=0;i<blocksize;i++)
    {
	temp = a[i];
	a[i] = b[i];
	b[i] = temp;
    }
}

int compar(const void* a,const void* b)
{
   char* A = (char*)a;
   char* B = (char*)b;
   return *A-*B;
}

















