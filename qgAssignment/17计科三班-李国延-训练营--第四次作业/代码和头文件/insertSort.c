#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void insertSort(ElemType array[],int n)            //≤Â»Î≈≈–Ú
{
    int i,j;

    for(i = 1;i < n;i++)
    {
        int temp = array[i];
        for(j = i; j>0 && array[j-1]>temp ;--j)
            array[j] = array[j-1];

          array[j] = temp;
    }


}







