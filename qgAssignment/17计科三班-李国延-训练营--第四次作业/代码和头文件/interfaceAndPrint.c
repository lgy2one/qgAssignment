#include "sort.h"
#include <stdio.h>


void Interface(void)
{
          printf("\n************************************************************");
         printf("************************************************************\n");
        printf("1->计数\t2->快排（迭代）\t3->快排（递归）\t");
       printf("4->插入\t5->归并\t6->基数\t0->退出\t");
      printf("*请选择你的操作*\n");
     printf("\n************************************************************");
    printf("************************************************************\n");

}


void printArray(ElemType *array,int Size)
{
    for(int i = 0;i < Size;i++)
    {
        printf("%d\t",array[i]);
    }
}


void Testresult()
{
      printf("\n---------------------------------------------------------");
         printf("---------------------------------------------------------\n");
        printf("\t       基数\t  归并\t   插入");
       printf("\t  快排（递归）\t 快排（迭代）\t 计数\t\n");
     printf("\n---------------------------------------------------------");
    printf("---------------------------------------------------------\n");

      for(int i = 0;i < 24;i++)
      {
          if(i == 0)    printf("\n10000:    ");

          if(i == 6)    printf("\n\n50000:    ");

          if(i == 12)   printf("\n\n200000:   ");

          if(i == 18)   printf("\n\n100*100K: ");

          printf("     %.3fs",result[i]);
      }
}





