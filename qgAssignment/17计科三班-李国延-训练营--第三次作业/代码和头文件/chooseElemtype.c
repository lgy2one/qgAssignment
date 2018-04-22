#include <stdio.h>
#include "queue.h"
#include <string.h>
#include <stdlib.h>

void chooseElemtype(AQueue *Q)
{
   void operate(int dataSize,int *num,int type,AQueue *Q);
    printf("\n输入对应类型前面的序号，便能选择对应的类型\n");
     printf("\n你想选择什么类型的数据来建立队列：");
      printf("\n*****************************************\n");
       printf("\n1.字符型(char)\n");
        printf("\n2.整型(int)\n");
         printf("\n3.浮点型(double)\n");
         printf("\n*****************************************\n");

    int num[3] = {0};                           //num数组里面存的数皆作判断标志所用

    scanf("%d",&num[0]);
    getchar();
    InitAQueue(Q);

    switch(num[0])
    {
        case(1):operate(sizeof(char),num,num[0],Q);break;

        case(2): operate(sizeof(int),num,num[0],Q);break;

        case(3): operate(sizeof(double),num,num[0],Q);break;

        default: printf("输入错误");break;
    }

}

void operate(int dataSize,int *num,int type,AQueue *Q)
{
          void *e = (void *)malloc(10);
          void *data = (void *)malloc(10);

            Q->data_size = dataSize;

             do
                {  printf("\n\n请选择你的操作\n");
                    printf("\n*****************************************\n");
                     printf("\n1.入队\n");
                      printf("2.遍历队列\n");
                       printf("3.出队\n");
                        printf("4.获取排头元素\n");
                       printf("5.看看队伍多长\n");
                      printf("6.清理队列\n");
                     printf("7.队伍解散\n");
                    printf("8.退出\n");
                   printf("\n*****************************************\n");

                    scanf("%d",&num[1]);
                    getchar();

                   switch(num[1])
                   {
                    case(1):
                        printf("\n请输入入队元素：\n");
                        scanf("%c", (char *)data);
                        getchar();
                        if(type == 2 || type == 3)
                            if(type == 2)
                                *(int *)data = *(char *)data - '0';
                            else
                                *(float *)data = *(char *)data - '0';

                        EnAQueue(Q,data);
                        break;

                    case(2):
                        printf("\n队伍的元素有：\n");
                        TraverseAQueue(Q,&APrint);break;

                    case(3):
                        DeAQueue(Q);break;

                    case(4):
                        GetHeadAQueue(Q, e);
                        if(type == 2 || type == 3)
                            if(type == 2)
                                 {printf("\n排头的元素为：%d\n",*(int*)e);break;}
                            else
                                 {printf("\n排头的元素为：%f\n",*(float*)e);break;}
                        else
                            printf("\n排头的元素为：%c\n",*(char*)e);break;

                    case(5):
                        printf("\n队伍元素个数为：%d\n",LengthAQueue(Q));break;

                    case(6):
                        ClearAQueue(Q);

                    case(7):
                        DestoryAQueue(Q);break;

                    case(8):
                        num[1] = 8;break;

                    default: printf("输入错误");break;

                   }

                }while(num[1] != 8);

}

