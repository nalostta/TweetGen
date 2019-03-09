/*
milestone-#8 (main program file)
author:manthan shah

functions:
1.gensort
2.compar
3.exchng
*/

#ifndef stdio__
#define stdio__
#include<stdio.h>
#endif

#include"milestone-8.h"

int main()
{
    int i;
    int array[10] = {'a','e','i','j','b','z','y','t','p','q'};
    gensort(&array,10,sizeof(int),compar);
    for(i=0;i<10;i++) printf(" %c",array[i]);
    return 0;
}
