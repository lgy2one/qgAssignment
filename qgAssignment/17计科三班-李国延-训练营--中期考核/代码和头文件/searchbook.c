#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Count = 0;

void searchBook1(ptrTNode Q,ptrLNode q)                 //由借书ID搜寻所借的书
{
    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookName,format(q->bookName)))
        {
           p->standingStock++;
           p->able2lend++;

             return;
        }
        p = p->prev;
    }

}

void searchBook2(ptrTNode Q)                           //搜寻某一个作者的全部书籍
{
    printf("\n-*请输入作者名称：");

    int flag = 0;
    char bookAuthor[20];
    scanf("%s",bookAuthor);

    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookAuthor,format(bookAuthor)))
        {
              if(flag == 0)
              {
                  printf("\n该作者的书如下：\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("书本编号  | ");
             printf("书名    \t      | ");
            printf("作者     \t  | ");
           printf("现存  | ");
          printf("库存 | \t\n");
         printf("-------------------------------------------");
        printf("-------------------------------------------");
              }

        printf("\n %d\t  | ",p->bookNum);
         printf("%s  | ",p->bookName);
           printf("%s  | ",p->bookAuthor);
          printf("%d本\t  | ",p->standingStock);
         printf("%d本  | \t\n",p->totalStock);
        printf("------------------------------------------");
       printf("--------------------------------------------");
      flag++;
        }
        p = p->prev;
    }

    if(flag == 0)  printf("\n该作者没有书在此书库中！\n");
}

void bubbleSort(ptrLNode *Array)         //排序，找出最早过期的借阅者ID
{
     int i,j;
 	 ptrLNode temp;

 	 for(i = 0;i < Count-1;i++)
         for(j = 0;j < Count-1-i;j++)
           {
               if(Array[j]->limitDate > Array[j+1]->limitDate)
               {
                 temp = Array[j+1];
                 Array[j+1] = Array[j];
                 Array[j] = temp;
               }
           }
}

void searchBook3(ptrTNode Q,ptrLNode P)             //查找某一本书的全部信息
{
    printf("\n-*请输入你要查询的书名：");
    char bookName[20];
    scanf("%s",bookName);

    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookName,format(bookName)))
        {
                  printf("\n该书的状态如下：\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("书本编号  | ");
             printf("书名    \t      | ");
            printf("作者     \t  | ");
           printf("现存  | ");
           printf("预约  | ");
          printf("库存 | \t\n");
         printf("-------------------------------------------");
        printf("-------------------------------------------");

         printf("\n %d\t  | ",p->bookNum);
         printf("%s  | ",p->bookName);
           printf("%s  | ",p->bookAuthor);
          printf("%d本\t  | ",p->standingStock);
          printf("%d本\t  | ",p->standingStock - p->able2lend);
         printf("%d本  | \t\n",p->totalStock);
        printf("------------------------------------------");
       printf("--------------------------------------------");
        }

        p = p->prev;
    }

     ptrLNode Array[30];
     Array[0] = NULL;
     int i = 0;

     ptrLNode q = P->rear;
    while(q->prev != NULL)
    {
        if(!strcmp(q->bookName,format(bookName)) && q->appointDate == 0)
         {
            Array[i++] = q;
            Count++;
         }
       q = q->prev;
    }



    if(Array[0] != NULL)
    {
         void bookStatus(ptrLNode Array[],int n,ptrLNode P);
         bookStatus(Array,i,P);

      bubbleSort(Array);
      printf("\n最早逾期的借阅者证号为：%s\n",Array[0]->ID);
    }
    else   printf("\n没有人借阅过这本书！\n");

}

void bookStatus(ptrLNode Array[],int n,ptrLNode P)              //该种书的借阅者信息
{
     printf("\n\n该书的借阅者信息如下：\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("  借阅者证        \t| ");
           printf("预约时间  | ");
           printf("借阅期限  | \n");

         printf("-------------------------------------------");
        printf("-------------------------------------------");

         ptrLNode q = P->rear;
         for(int i = 0;i < n;i++,q = q->prev){
         printf("\n %s\t  | ",format(q->ID));
          printf("%d天\t      | ",q->appointDate);
          printf("%d天\t | \n",q->limitDate);
        printf("------------------------------------------");
       printf("--------------------------------------------");
        }

}
