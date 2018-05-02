#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void logoutBook(ptrTNode Q)
{
    printf("\n-*请输入所要注销的书的书名：");

        char bookName[30];
        scanf("%s",bookName);

    ptrTNode p = Q->rear;
    while(p->prev != NULL)
    {
        if(!strcmp(p->bookName,format(bookName)))
        {
            if(p == Q->rear)
            {
                Q->rear = p->prev;
                Q->rear->next = NULL;
                free(p);
                p = NULL;
            }
              else
              {
                  p->prev->next = p->next;
                  p->next->prev = p->prev;
                  free(p);
                  p = NULL;
              }


             printf("\n注销成功！\n");
             return;
        }
        p = p->prev;
    }

    printf("\n注销失败！书库中并没有这本书！\n");
}
