#include "sort.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Interface(void)
{
          printf("\n**********************************************************");
         printf("**********************************************************\n");
        printf("1->����    2->���ţ�������    3->���ţ��ݹ飩");
       printf("     4->����     5->�鲢     6->����     0->�˳�\t");
      printf("*��ѡ����Ĳ���*");
     printf("\n**********************************************************");
    printf("**********************************************************\n");

}

void printArray(ElemType *array,int Size)   //�������
{
    for(int i = 0;i < Size;i++)
    {
        printf("%d\t",array[i]);
    }
}

void testResult1(void)                     //������Խ��
{
      printf("\n---------------------------------------------------------");
         printf("---------------------------------------------------------\n");
        printf("\t         ����\t   �鲢\t       ����");
       printf("\t   �ݹ����    ��������\t    ����\t");
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
      printf("\n\n\nע��ʱ�����Ϊ0.000s��������ʱ��̫���ˣ�\
ʱ������һ���룬���Ȳ��������ʾΪ��\n\n");
}



void testResult2(void)                 //������Խ����һ���ļ���
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
        fprintf(fp,"\t         ����      �鲢        ����");
       fprintf(fp,"      �ݹ����    ��������    ����\t");
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
      fprintf(fp,"\n\n\nע��ʱ�����Ϊ0.000s��������ʱ��̫���ˣ�\
ʱ������һ���룬���Ȳ��������ʾΪ��\n\n");

       fclose(fp);
}

void testData(void)                //����������ݵ�һ���ļ���
{
    FILE *fp;
   if((fp=fopen("testData.txt","wt"))==NULL)
   {
      printf("Can't open the file!\nPress any key to exit!");
      getch();
      exit(0);
   }
         fprintf(fp,"\n��Ϊ������̫�󣬹����ݲ�һһ������������Ѿ�ʵ��\
                 \n��Ҫ�ۿ������Դ�ļ�inerfaceDndPrintȥ�鿴�����ʵ��\n\n\n");

           ElemType array1[10000];
           createArr(array1,10000);
          fprintf(fp,"10000���������\n\n");
          for(int i = 0;i < 10000;i++)
          {
             fprintf(fp,"%d\t",array1[i]);
          }
}

  /*  ElemType array2[50000];               //��Ϊ������̫�󣬲�һһ������������Ѿ�ʵ�֣�
    createArr(array2,50000);                   ���Լ򵥿�һ��//
    fprintf(fp,"\n\n\n\n\n\n50000���������\n\n");
    for(int i = 0;i < 50000;i++)
    {
       fprintf(fp,"%d\t",array2[i]);
    }

           ElemType array3[200000];
           createArr(array3,20000);
           fprintf(fp,"\n\n\n\n\n\n200000���������\n\n");
         for(int i = 0;i < 200000;i++)
         {
            fprintf(fp,"%d\t",array3[i]);
         }

            fprintf(fp,"\n\n\n\n\n\n10*100K���������\n\n");
             ElemType array4[100];
           for(int i = 0;i < 100000;i++)
                 {
                       createArr(array4,100);
                       for(int i = 0;i < 100;i++)
                              {fprintf(fp,"%d\t",array4[i]);
                               fprintf(fp,"\n\n\n\n\n\n\n\n");}

                 }*/







