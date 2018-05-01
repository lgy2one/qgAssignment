#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


void testTime(int choose,int dataSize)           //输出测试大数据的时间
{
    clock_t start,finish;
    double totaltime;
    int i = 6;;

    if(!choose)                                              //选择手动测试时进行
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
        if(choose)  operate = i--;

        else  scanf("%d",&operate);

     switch(operate)
     {
         case(1): start = clock();createArr(array,dataSize);countSort(array,dataSize);break;

         case(2): start = clock();createArr(array,dataSize);QSort(array,0,dataSize);break;

         case(3): start = clock();createArr(array,dataSize);QSortRecursion(array,dataSize,0,dataSize);break;

         case(4): start = clock();createArr(array,dataSize);insertSort(array,dataSize);break;

         case(5): start = clock();createArr(array,dataSize);MergeSort(array,0,dataSize);break;

         case(6): start = clock();createArr(array,dataSize);RadixCountSort(array,dataSize);break;

         case(0):return ;break;

         default:printf("输入错误了噢！\n");

     }
          finish = clock();
          totaltime = (double)(finish-start)/CLOCKS_PER_SEC;

          static int index = 0;
          result[index++] = totaltime;            //result在头文件中定义，为了保存测试时间

          printf("程序运行的时间为: %.3f 秒\n\n",totaltime);

    }
}

void createArr(ElemType array[],int size)        //产生随机函数并存到数组中
{
    int i;
   srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样

    for (i=0; i < size; i++)
    {
         array[i] = rand() % 30000; //产生30000的随机数
     }

}
