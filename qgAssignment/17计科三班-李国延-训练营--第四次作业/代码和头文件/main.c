#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <conio.h>

int main()
{
   printf("\n1.�ֶ�����\n");
   printf("\n2.�Զ�����\n\n");

   int operate;                 //�������Ʒ�
   int choose;                  //ѡ���ֶ������Զ�
   int dataSize = 0;
   scanf("%d",&operate);

     switch(operate)
     {
        case(1): choose = 0;
                 testTime(choose,dataSize);              //testTime�������Դ�����
                 testTime2(choose);                    //testTime2�������Դ���С����
                 break;

        case(2): choose = 1;
                 printf("�����ĵȺ�Ŷ����Լ��Ҫһ�����ӡ�\n");
                     testTime(choose,10000);                   //�Զ�����10000��50000��200000
                     testTime(choose,50000);                    // �� 100*100K����С���ݣ�
                     testTime(choose,200000);
                 testTime2(choose);
                 testResult1();                        //�Ա����ʽ������
                 break;

        default:printf("����������ޣ�");
     }


    testResult2();             //�����Խ��������ļ���
    printf("\n���Խ���Ѿ���¼����ΪtestResult���ı��ļ��С�\n\n");

    printf("\n�����������Ѿ���¼����ΪtestData���ı��ļ��С�\n\n");
    testData();                //����10000���������ݣ�10000����������

    getch();

    return 0;
}
