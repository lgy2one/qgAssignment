#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void lendBook(ptrTNode Q,ptrLNode P)
{
    char uselessArr[20];

    printf("\n-*������������Ҫ���ĵ�������");

    char bookName[30];
    scanf("%s",bookName);              //��������

    ptrTNode p = Q->rear;
    while(p->prev != NULL)              //������������
    {
        if(!strcmp(p->bookName,format(bookName)))    //�������Ƿ��������
        {
           if(p->standingStock > 0)               //�ִ����0�����
           {
            printf("\n-*����Ҫ���鼮�ܿ��%d�����ִ�%d����",p->totalStock,p->standingStock);
            printf("�����%d������%d���Ѿ���ԤԼ��",p->able2lend,p->standingStock - p->able2lend);

                   printf("\n\n-*���������ͼ��֤�ţ�");
                    char ID[30];
                     scanf("%s",ID);

                     printf("\n-*��������Ľ������ޣ�����1-99�죩��");
                    int limitDate = 0;
                   scanf("%d",&limitDate);
                   if(limitDate == 0) {printf("\n������󣡽���ʧ�ܣ�\n");gets(uselessArr);return;}
                   if(limitDate > 99)  limitDate = 99;

                int appointDate = 0;
               addimfor(P,ID,limitDate,bookName,appointDate);   //���ӽ�������Ϣ��������

            p->standingStock--;
            p->able2lend--;
            printf("\n���ĳɹ���\n");
          }

            else       //�ִ�С��0�����
            printf("\n����Ҫ���鼮�ܿ��%d�����ִ�%d�����޷����\n",p->totalStock,p->standingStock);
            return;
        }
        p = p->prev;
    }

     printf("\n����Ҫ���ĵ��鲻�ڱ�����У�\n");    //�Ҳ�������

}

void returnBook(ptrTNode Q,ptrLNode P)
{
    printf("\n���������ͼ��֤�ţ�");
    char ID[30];
    scanf("%s",ID);

    printf("\n��������Ҫ�黹��������");
    char bookName[30];
    scanf("%s",bookName);

    ptrLNode q = P->rear;
    while(q->prev != NULL)
    {
        if(!strcmp(format(q->ID),format(ID)) && !strcmp(format(q->bookName),format(bookName)))
        {
            if(q == P->rear)
            {
                P->rear = q->prev;
                P->rear->next = NULL;
                searchBook1(Q,q);
                free(q);
                q = NULL;
            }
              else
               {
                  q->prev->next = q->next;
                  q->next->prev = q->prev;
                  searchBook1(Q,q);
                  free(q);
                  q = NULL;
               }
             printf("\n�黹�ɹ�\n");
             return;
        }

        q = q->prev;
    }

   printf("\n��ͼ��֤��û�н���飬�黹ʧ�ܣ�\n");

}


void appoint(ptrTNode Q,ptrLNode P)
{
    printf("\n-*������������ҪԤԼ���ĵ�������");

    char uselessArr[20];
    char bookName[30];
    scanf("%s",bookName);

    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookName,format(bookName)))
        {
           if(p->standingStock > 0)
           {
            printf("\n-*����Ҫ���鼮�ܿ��%d�����ִ�%d����",p->totalStock,p->standingStock);
            printf("��ԤԼ%d������%d���Ѿ���ԤԼ��",p->able2lend,p->standingStock - p->able2lend);

                   printf("\n\n-*���������ͼ��֤�ţ�");
                    char ID[30];
                     scanf("%s",ID);

                     printf("\n-*�������㼸���ȡ�飨����1-10�죩��");

                      int appointDate = 0;
                     scanf("%d",&appointDate);
                     if(appointDate == 0) {printf("\n�������ԤԼʧ�ܣ�\n");gets(uselessArr);return;}
                     if(appointDate > 10)  appointDate = 10;

                     printf("\n-*��������Ľ������ޣ�����1-99�죩��");
                    int limitDate = 0;
                   scanf("%d",&limitDate);
                   if(limitDate == 0) {printf("\n�������ԤԼʧ�ܣ�\n");gets(uselessArr);return;}
                   if(limitDate > 99)  limitDate = 99;

               addimfor(P,ID,limitDate,bookName,appointDate);

               p->able2lend--;
               printf("\nԤԼ�ɹ���\n");
          }

            else
              printf("����Ҫ���鼮�ܿ��%d�����ִ�%d�����޷�ԤԼ",p->totalStock,p->standingStock);

             return;
        }

        p = p->prev;
    }

      printf("\n���鲢��������У�ԤԼʧ�ܣ�\n");
}
