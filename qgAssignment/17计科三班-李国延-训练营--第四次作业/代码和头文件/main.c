#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <conio.h>

int main()
{

   printf("\n1.�ֶ�����\n");
   printf("\n2.�Զ�����\n");

   int operate;
   int choose;
   int dataSize = 0;
   scanf("%d",&operate);

     switch(operate)
     {
        case(1): choose = 0;
                 testTime(choose,dataSize);
                 testTime2(choose);
                 break;

        case(2): choose = 1;
                 printf("�����ĵȺ�");
                 testTime(choose,10000);
                 testTime(choose,50000);
                 testTime(choose,200000);
                 testTime2(choose);
                 Testresult();
                 break;

        default:printf("����������ޣ�");
     }


    getch();

    return 0;
}
