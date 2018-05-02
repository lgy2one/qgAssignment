#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Count = 0;

void searchBook1(ptrTNode Q,ptrLNode q)                 //�ɽ���ID��Ѱ�������
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

void searchBook2(ptrTNode Q)                           //��Ѱĳһ�����ߵ�ȫ���鼮
{
    printf("\n-*�������������ƣ�");

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
                  printf("\n�����ߵ������£�\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("�鱾���  | ");
             printf("����    \t      | ");
            printf("����     \t  | ");
           printf("�ִ�  | ");
          printf("��� | \t\n");
         printf("-------------------------------------------");
        printf("-------------------------------------------");
              }

        printf("\n %d\t  | ",p->bookNum);
         printf("%s  | ",p->bookName);
           printf("%s  | ",p->bookAuthor);
          printf("%d��\t  | ",p->standingStock);
         printf("%d��  | \t\n",p->totalStock);
        printf("------------------------------------------");
       printf("--------------------------------------------");
      flag++;
        }
        p = p->prev;
    }

    if(flag == 0)  printf("\n������û�����ڴ�����У�\n");
}

void bubbleSort(ptrLNode *Array)         //�����ҳ�������ڵĽ�����ID
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

void searchBook3(ptrTNode Q,ptrLNode P)             //����ĳһ�����ȫ����Ϣ
{
    printf("\n-*��������Ҫ��ѯ��������");
    char bookName[20];
    scanf("%s",bookName);

    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookName,format(bookName)))
        {
                  printf("\n�����״̬���£�\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("�鱾���  | ");
             printf("����    \t      | ");
            printf("����     \t  | ");
           printf("�ִ�  | ");
           printf("ԤԼ  | ");
          printf("��� | \t\n");
         printf("-------------------------------------------");
        printf("-------------------------------------------");

         printf("\n %d\t  | ",p->bookNum);
         printf("%s  | ",p->bookName);
           printf("%s  | ",p->bookAuthor);
          printf("%d��\t  | ",p->standingStock);
          printf("%d��\t  | ",p->standingStock - p->able2lend);
         printf("%d��  | \t\n",p->totalStock);
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
      printf("\n�������ڵĽ�����֤��Ϊ��%s\n",Array[0]->ID);
    }
    else   printf("\nû���˽��Ĺ��Ȿ�飡\n");

}

void bookStatus(ptrLNode Array[],int n,ptrLNode P)              //������Ľ�������Ϣ
{
     printf("\n\n����Ľ�������Ϣ���£�\n");
                 printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("  ������֤        \t| ");
           printf("ԤԼʱ��  | ");
           printf("��������  | \n");

         printf("-------------------------------------------");
        printf("-------------------------------------------");

         ptrLNode q = P->rear;
         for(int i = 0;i < n;i++,q = q->prev){
         printf("\n %s\t  | ",format(q->ID));
          printf("%d��\t      | ",q->appointDate);
          printf("%d��\t | \n",q->limitDate);
        printf("------------------------------------------");
       printf("--------------------------------------------");
        }

}
