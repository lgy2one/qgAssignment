#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


void testTime(int choose,int dataSize)
{
    clock_t start,finish;
    double totaltime;
    int i = 6;;

    if(!choose)
    {
         printf("\n注：退出后可以选择测试大量小数组\n");
        printf("\n现在测试大数据量\n\n");
       printf("请你想输入的数据量：");

      int temp;
    scanf("%d",&temp);
    dataSize = temp;
    Interface();
    }


    ElemType array[dataSize];

    while(1)
    {


        int operate;
        if(choose)
        {
            operate = i--;
        }
        else  scanf("%d",&operate);

     switch(operate)
     {
         case(1): createArr(array,dataSize);start = clock();countSort(array,dataSize);break;

         case(2): createArr(array,dataSize);start = clock();QSort(array,0,dataSize-1);break;

         case(3): createArr(array,dataSize);start = clock();QSortRecursion(array,dataSize,0,dataSize-1);break;

         case(4): createArr(array,dataSize);start = clock();insertSort(array,dataSize);break;

         case(5): createArr(array,dataSize);start = clock();MergeSort(array,0,dataSize-1);break;

         case(6): createArr(array,dataSize);start = clock();RadixCountSort(array,dataSize);break;

         case(0):return ;break;

         default:printf("输入错误了噢！");

     }

          finish = clock();

          totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
          static int index = 0;
          result[index++] = totaltime;

          printf("\n程序运行的时间为: %.3f 秒",totaltime);

    }
}

void createArr(ElemType array[],int size)
{
    int i;
   srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样

    for (i=0; i < size; i++)
    {
         array[i] = rand() % 30000; //产生30000的随机数
     }

}
