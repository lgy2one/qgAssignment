#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>


void testTime(int choose,int dataSize)           //������Դ����ݵ�ʱ��
{
    clock_t start,finish;
    double totaltime;
    int i = 6;;

    if(!choose)                                              //ѡ���ֶ�����ʱ����
    {
         printf("\nע���˳������ѡ����Դ���С����\n");
        printf("\n���ڲ��Դ�������\n\n");
       printf("�������������������");

         int temp;
        scanf("%d",&temp);
       dataSize = temp;
      Interface();
    }

    ElemType array[dataSize];

    while(1)
    {
        int operate;
        if(choose)  operate = i--;

        else  scanf("%d",&operate);

     switch(operate)
     {
         case(1): start = clock();createArr(array,dataSize);countSort(array,dataSize);break;

         case(2): start = clock();createArr(array,dataSize);QSort(array,0,dataSize);break;

         case(3): start = clock();createArr(array,dataSize);QSortRecursion(array,dataSize,0,dataSize);break;

         case(4): start = clock();createArr(array,dataSize);insertSort(array,dataSize);break;

         case(5): start = clock();createArr(array,dataSize);MergeSort(array,0,dataSize);break;

         case(6): start = clock();createArr(array,dataSize);RadixCountSort(array,dataSize);break;

         case(0):return ;break;

         default:printf("����������ޣ�\n");

     }
          finish = clock();
          totaltime = (double)(finish-start)/CLOCKS_PER_SEC;

          static int index = 0;
          result[index++] = totaltime;            //result��ͷ�ļ��ж��壬Ϊ�˱������ʱ��

          printf("�������е�ʱ��Ϊ: %.3f ��\n\n",totaltime);

    }
}

void createArr(ElemType array[],int size)        //��������������浽������
{
    int i;
   srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��

    for (i=0; i < size; i++)
    {
         array[i] = rand() % 30000; //����30000�������
     }

}
