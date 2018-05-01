#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

void testTime2(int choose)                //输出大量小数组的排序测试时间
{
    clock_t start,finish;
    double totaltime;

     int i = 6;
     int index = 18;

    int dataSize = 100;

    ElemType array[dataSize];

     while(1)
    {

        int operate;

        if(choose)               //用i的自减实现自动
        {
            operate = i--;
        }
        else
        {
            Interface();
            printf("\n现在测试大量小数组，选择排序方法后自动输出测试时间\n\n");
            scanf("%d",&operate);
        }

     switch(operate)
       {
         case(1):
                      start = clock();
                  for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       countSort(array,dataSize);
                 }break;
         case(2):
                     start = clock();
                   for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       QSort(array,0,dataSize-1);
                 }break;
         case(3):
                        start = clock();
                    for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       QSortRecursion(array,dataSize,0,dataSize-1);
                 }break;
         case(4):
                         start = clock();
                    for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       insertSort(array,dataSize);
                 }break;
         case(5):
                         start = clock();
                     for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       MergeSort(array,0,dataSize-1);
                 }break;
         case(6):
                        start = clock();
                    for(int i = 0;i < 100000;i++)
                 {
                       createArr(array,dataSize);
                       RadixCountSort(array,dataSize);
                 }break;

         case(0):return ;

         default:printf("输入错误了噢！");

       }
          finish = clock();
          totaltime = (double)(finish-start)/CLOCKS_PER_SEC;

          result[index++] = totaltime;

          printf("\n程序运行的时间为: %.3f 秒\n",totaltime);
    }

}
