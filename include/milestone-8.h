/*
milestone-#8 (header file)
author:manthan shah

functions:
1.gensort
2.compar
3.exchng
*/
#ifndef _milestone_8
#define _milestone_8

void* gensort(void* input,int sortsize,int blocksize,int (*compar)(const void*,const void*));
int compar(const void* a,const void* b);
void exchng(char* a,char* b,int blocksize);

#endif