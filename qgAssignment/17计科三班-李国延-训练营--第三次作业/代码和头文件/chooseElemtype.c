#include <stdio.h>
#include "queue.h"
#include <string.h>
#include <stdlib.h>

void chooseElemtype(AQueue *Q)
{
   void operate(int dataSize,int *num,int type,AQueue *Q);
    printf("\n�����Ӧ����ǰ�����ţ�����ѡ���Ӧ������\n");
     printf("\n����ѡ��ʲô���͵��������������У�");
      printf("\n*****************************************\n");
       printf("\n1.�ַ���(char)\n");
        printf("\n2.����(int)\n");
         printf("\n3.������(double)\n");
         printf("\n*****************************************\n");

    int num[3] = {0};                           //num�����������������жϱ�־����

    scanf("%d",&num[0]);
    getchar();
    InitAQueue(Q);

    switch(num[0])
    {
        case(1):operate(sizeof(char),num,num[0],Q);break;

        case(2): operate(sizeof(int),num,num[0],Q);break;

        case(3): operate(sizeof(double),num,num[0],Q);break;

        default: printf("�������");break;
    }

}

void operate(int dataSize,int *num,int type,AQueue *Q)
{
          void *e = (void *)malloc(10);
          void *data = (void *)malloc(10);

            Q->data_size = dataSize;

             do
                {  printf("\n\n��ѡ����Ĳ���\n");
                    printf("\n*****************************************\n");
                     printf("\n1.���\n");
                      printf("2.��������\n");
                       printf("3.����\n");
                        printf("4.��ȡ��ͷԪ��\n");
                       printf("5.��������೤\n");
                      printf("6.�������\n");
                     printf("7.�����ɢ\n");
                    printf("8.�˳�\n");
                   printf("\n*****************************************\n");

                    scanf("%d",&num[1]);
                    getchar();

                   switch(num[1])
                   {
                    case(1):
                        printf("\n���������Ԫ�أ�\n");
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
                        printf("\n�����Ԫ���У�\n");
                        TraverseAQueue(Q,&APrint);break;

                    case(3):
                        DeAQueue(Q);break;

                    case(4):
                        GetHeadAQueue(Q, e);
                        if(type == 2 || type == 3)
                            if(type == 2)
                                 {printf("\n��ͷ��Ԫ��Ϊ��%d\n",*(int*)e);break;}
                            else
                                 {printf("\n��ͷ��Ԫ��Ϊ��%f\n",*(float*)e);break;}
                        else
                            printf("\n��ͷ��Ԫ��Ϊ��%c\n",*(char*)e);break;

                    case(5):
                        printf("\n����Ԫ�ظ���Ϊ��%d\n",LengthAQueue(Q));break;

                    case(6):
                        ClearAQueue(Q);

                    case(7):
                        DestoryAQueue(Q);break;

                    case(8):
                        num[1] = 8;break;

                    default: printf("�������");break;

                   }

                }while(num[1] != 8);

}

