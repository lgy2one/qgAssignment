#include "queue.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void InitAQueue(AQueue *Q)
{

        *(Q->data) = (void *)malloc(Q->data_size * MAXQUEUE);

           if (*(Q->data) == NULL)
	      {
            exit(1);
          }


    Q->front = 0;
    Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
        while(*(Q->data) != NULL)
        {
            free(*(Q->data));
            *(Q->data) = NULL;
        }
         printf("\n销毁成功！\n");
}

Status IsFullAQueue(const AQueue *Q)
{
    if(Q->front == ((Q->rear + 1) % MAXQUEUE))
        return TRUE;
    else
        return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->front == Q->rear)
        return TRUE;
    else
        return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(*(Q->data) == NULL)
        return FALSE;
    else
        memcpy(e,(Q->data)[Q->front],Q->data_size);

    return TRUE;
}

int LengthAQueue(AQueue *Q)
{
    int count = Q->rear - Q->front;
    if(count < 0 )
        return 10-count;
    else
        return count;
}

Status EnAQueue(AQueue *Q, void *data)             //未选择哪一个地址所指向的数组
{
    if (!IsFullAQueue(Q))
	{
        void *elemAddr = (char *)(*(Q->data))+(Q->rear)*(Q->data_size);
        memcpy(elemAddr,data,Q->data_size);
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        printf("\n入队成功！\n");
        return TRUE;
    }
    else
    {
        printf("Queue Full!\n");
        return FALSE;
    }

}

Status DeAQueue(AQueue *Q)
{
    if(!IsEmptyAQueue(Q))
     {
        Q->front = (Q->front + 1) % MAXQUEUE;
        printf("\n出队成功！\n");
        return TRUE;
     }
    else
        printf("Queue Empty!\n");
    return FALSE;
}

void ClearAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    printf("\n清理成功！\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(*(Q->data) == NULL)
        return FALSE;

    (*foo)((void *)Q);

    return TRUE;
}


void APrint(void *q)
{
    AQueue *Q = (AQueue *)q ;
    int point = Q->front;
    switch(Q->data_size)
    {
        case(1):
            while(point != Q->rear)
            {
                printf("%c\t",*(char *)(*(Q->data)+point));
                point++;
            }
            break;


        case(4):
            while(point != Q->rear)
            {
                printf("%d\t",*(int *)(*(Q->data)+point*4));
                point++;
            }
            break;

        case(8):
            while(point != Q->rear)
            {
                printf("%f\t",*(double *)(*(Q->data)+point*8));
                point++;
            }
            break;

    }

}


