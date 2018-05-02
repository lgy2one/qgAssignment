#include "head.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void addBook(ptrTNode Q,char *bookName,char *bookAuthor)
{
   ptrTNode p = Q->rear;            //����һ������ָ�����ĳһ�����
    int i = 0;

   while(p->prev != NULL)                      //���ж���ӵ����Ƿ�����Ѿ����ˣ����˾Ϳ��+1
   {                                           //��β����ʼ��������
       if(!strcmp(p->bookName,bookName))
       {
          p->standingStock++;
          p->totalStock++;
          p->able2lend++;
          return ;
       }
       else
        p = p->prev;
   }


        p = (ptrTNode)malloc(LEN1);           //���ٿռ䴢������Ŀռ�
       if (p == NULL)     exit(0);

          Q->rear->next = p;
        p->next = NULL;
        p->prev = Q->rear;
          Q->rear = p;

      p->bookNum = Q->rear->prev->bookNum + 1;                      //�����ż�һ


	    while(bookName[i] != '\0')                          //�������ȥ
        {
            p->bookName[i] = bookName[i];
            p->bookName[i+1] = '\0';
            i++;
        }
	    i = 0;
	        while(bookAuthor[i] != '\0')                 //���������ȥ
            {
                p->bookAuthor[i] = bookAuthor[i];
                p->bookAuthor[i+1] = '\0';
                i++;
            }

         p->standingStock = 1;                       //��桢�ִ桢�ɽ�����Ϊ1
	      p->totalStock = 1;
	       p->able2lend = 1;

}

void addOperate(ptrTNode Q)       //�����Ĳ�������
{
    printf("\n-*��������������");
    char bookName[30];
    scanf("%s",bookName);

       printf("\n-*�����������ߣ�");
       char bookAuthor[30];
       scanf("%s",bookAuthor);

    addBook(Q,format(bookName),format(bookAuthor));     //����鵽�����

    printf("\n��ӳɹ���\n");
}


void addimfor(ptrLNode P,char *ID,int limitDate,char *bookName,int appointDate)
{
    ptrLNode p = P->rear;            //����һ������ָ�����ĳһ�����
    int i = 0;

        p = (ptrLNode)malloc(LEN2);     //ͬ������һ�����������е����ֵ�浽�����
       if (p == NULL)     exit(0);

          P->rear->next = p;
        p->next = NULL;
        p->prev = P->rear;
          P->rear = p;

      p->limitDate = limitDate;
      p->appointDate = appointDate;

	    while(bookName[i] != '\0')
        {
            p->bookName[i] = bookName[i];
            p->bookName[i+1] = '\0';
            i++;
        }

	    i = 0;
	        while(ID[i] != '\0')
            {
                p->ID[i] = ID[i];
                p->ID[i+1] = '\0';
                i++;
            }

}

