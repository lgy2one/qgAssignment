#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void lendBook(ptrTNode Q,ptrLNode P)
{
    char uselessArr[20];

    printf("\n-*请输入你所需要借阅的书名：");

    char bookName[30];
    scanf("%s",bookName);              //输入书名

    ptrTNode p = Q->rear;
    while(p->prev != NULL)              //遍历整个链表
    {
        if(!strcmp(p->bookName,format(bookName)))    //找书名是否在书库中
        {
           if(p->standingStock > 0)               //现存大于0则外借
           {
            printf("\n-*你需要的书籍总库存%d本，现存%d本，",p->totalStock,p->standingStock);
            printf("可外借%d本，有%d本已经被预约。",p->able2lend,p->standingStock - p->able2lend);

                   printf("\n\n-*请输入你的图书证号：");
                    char ID[30];
                     scanf("%s",ID);

                     printf("\n-*请输入你的借阅期限（仅限1-99天）：");
                    int limitDate = 0;
                   scanf("%d",&limitDate);
                   if(limitDate == 0) {printf("\n输入错误！借阅失败！\n");gets(uselessArr);return;}
                   if(limitDate > 99)  limitDate = 99;

                int appointDate = 0;
               addimfor(P,ID,limitDate,bookName,appointDate);   //增加借阅者信息到链表中

            p->standingStock--;
            p->able2lend--;
            printf("\n借阅成功！\n");
          }

            else       //现存小于0则不外借
            printf("\n你需要的书籍总库存%d本，现存%d本，无法外借\n",p->totalStock,p->standingStock);
            return;
        }
        p = p->prev;
    }

     printf("\n你想要借阅的书不在本书库中！\n");    //找不到书名

}

void returnBook(ptrTNode Q,ptrLNode P)
{
    printf("\n请输入你的图书证号：");
    char ID[30];
    scanf("%s",ID);

    printf("\n请输入你要归还的书名：");
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
             printf("\n归还成功\n");
             return;
        }

        q = q->prev;
    }

   printf("\n该图书证号没有借过书，归还失败！\n");

}


void appoint(ptrTNode Q,ptrLNode P)
{
    printf("\n-*请输入你所需要预约借阅的书名：");

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
            printf("\n-*你需要的书籍总库存%d本，现存%d本，",p->totalStock,p->standingStock);
            printf("可预约%d本，有%d本已经被预约。",p->able2lend,p->standingStock - p->able2lend);

                   printf("\n\n-*请输入你的图书证号：");
                    char ID[30];
                     scanf("%s",ID);

                     printf("\n-*请输入你几天后取书（仅限1-10天）：");

                      int appointDate = 0;
                     scanf("%d",&appointDate);
                     if(appointDate == 0) {printf("\n输入错误！预约失败！\n");gets(uselessArr);return;}
                     if(appointDate > 10)  appointDate = 10;

                     printf("\n-*请输入你的借阅期限（仅限1-99天）：");
                    int limitDate = 0;
                   scanf("%d",&limitDate);
                   if(limitDate == 0) {printf("\n输入错误！预约失败！\n");gets(uselessArr);return;}
                   if(limitDate > 99)  limitDate = 99;

               addimfor(P,ID,limitDate,bookName,appointDate);

               p->able2lend--;
               printf("\n预约成功！\n");
          }

            else
              printf("你需要的书籍总库存%d本，现存%d本，无法预约",p->totalStock,p->standingStock);

             return;
        }

        p = p->prev;
    }

      printf("\n该书并不在书库中！预约失败！\n");
}
