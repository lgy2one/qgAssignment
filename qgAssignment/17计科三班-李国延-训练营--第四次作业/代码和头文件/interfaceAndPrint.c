#include "sort.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Interface(void)
{
          printf("\n**********************************************************");
         printf("**********************************************************\n");
        printf("1->计数    2->快排（迭代）    3->快排（递归）");
       printf("     4->插入     5->归并     6->基数     0->退出\t");
      printf("*请选择你的操作*");
     printf("\n**********************************************************");
    printf("**********************************************************\n");

}

void printArray(ElemType *array,int Size)   //输出函数
{
    for(int i = 0;i < Size;i++)
    {
        printf("%d\t",array[i]);
    }
}

void testResult1(void)                     //输出测试结果
{
      printf("\n---------------------------------------------------------");
         printf("---------------------------------------------------------\n");
        printf("\t         基数\t   归并\t       插入");
       printf("\t   递归快排    迭代快排\t    计数\t");
     printf("\n---------------------------------------------------------");
    printf("---------------------------------------------------------\n");

      for(int i = 0;i < 24;i++)
      {
          if(i == 0)    printf("\n10000:    ");

          if(i == 6)    printf("\n\n50000:    ");

          if(i == 12)   printf("\n\n200000:   ");

          if(i == 18)   printf("\n\n100*100K: ");

          printf("      %.3fs",result[i]);
      }
      printf("\n\n\n注：时间出现为0.000s的是运行时间太快了，\
时间少于一毫秒，精度不够因此显示为零\n\n");
}



void testResult2(void)                 //输出测试结果到一个文件中
{
   FILE *fp;
   if((fp=fopen("testResult.txt","wt"))==NULL)
   {
      printf("Can't open the file!\nPress any key to exit!");
      getch();
      exit(0);
   }

          fprintf(fp,"\n-----------------------------------------------");
         fprintf(fp,"-------------------------------------------------\n");
        fprintf(fp,"\t         基数      归并        插入");
       fprintf(fp,"      递归快排    迭代快排    计数\t");
      fprintf(fp,"\n-----------------------------------------------");
     fprintf(fp,"-------------------------------------------------\n");

    for(int i = 0;i < 24;i++)
      {
          if(i == 0)    fprintf(fp,"\n10000:    ");

          if(i == 6)    fprintf(fp,"\n\n50000:    ");

          if(i == 12)   fprintf(fp,"\n\n200000:   ");

          if(i == 18)   fprintf(fp,"\n\n100*100K: ");

          fprintf(fp,"      %.3fs",result[i]);
      }
      fprintf(fp,"\n\n\n注：时间出现为0.000s的是运行时间太快了，\
时间少于一毫秒，精度不够因此显示为零\n\n");

       fclose(fp);
}

void testData(void)                //输出测试数据到一个文件中
{
    FILE *fp;
   if((fp=fopen("testData.txt","wt"))==NULL)
   {
      printf("Can't open the file!\nPress any key to exit!");
      getch();
      exit(0);
   }
         fprintf(fp,"\n因为数据量太大，故数据不一一输出，但代码已经实现\
                 \n若要观看，请打开源文件inerfaceDndPrint去查看代码的实现\n\n\n");

           ElemType array1[10000];
           createArr(array1,10000);
          fprintf(fp,"10000个随机数：\n\n");
          for(int i = 0;i < 10000;i++)
          {
             fprintf(fp,"%d\t",array1[i]);
          }
}

  /*  ElemType array2[50000];               //因为数据量太大，不一一输出。但代码已经实现，
    createArr(array2,50000);                   可以简单看一看//
    fprintf(fp,"\n\n\n\n\n\n50000个随机数：\n\n");
    for(int i = 0;i < 50000;i++)
    {
       fprintf(fp,"%d\t",array2[i]);
    }

           ElemType array3[200000];
           createArr(array3,20000);
           fprintf(fp,"\n\n\n\n\n\n200000个随机数：\n\n");
         for(int i = 0;i < 200000;i++)
         {
            fprintf(fp,"%d\t",array3[i]);
         }

            fprintf(fp,"\n\n\n\n\n\n10*100K组随机数：\n\n");
             ElemType array4[100];
           for(int i = 0;i < 100000;i++)
                 {
                       createArr(array4,100);
                       for(int i = 0;i < 100;i++)
                              {fprintf(fp,"%d\t",array4[i]);
                               fprintf(fp,"\n\n\n\n\n\n\n\n");}

                 }*/







