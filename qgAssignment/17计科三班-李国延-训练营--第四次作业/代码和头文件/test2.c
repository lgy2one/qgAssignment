#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

void testTime2(int choose)                //�������С������������ʱ��
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

        if(choose)               //��i���Լ�ʵ���Զ�
        {
            operate = i--;
        }
        else
        {
            Interface();
            printf("\n���ڲ��Դ���С���飬ѡ�����򷽷����Զ��������ʱ��\n\n");
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

         default:printf("����������ޣ�");

       }
          finish = clock();
          totaltime = (double)(finish-start)/CLOCKS_PER_SEC;

          result[index++] = totaltime;

          printf("\n�������е�ʱ��Ϊ: %.3f ��\n",totaltime);
    }

}
