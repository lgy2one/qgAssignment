#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void logoutBook(ptrTNode Q)
{
    printf("\n-*��������Ҫע�������������");

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


             printf("\nע���ɹ���\n");
             return;
        }
        p = p->prev;
    }

    printf("\nע��ʧ�ܣ�����в�û���Ȿ�飡\n");
}
