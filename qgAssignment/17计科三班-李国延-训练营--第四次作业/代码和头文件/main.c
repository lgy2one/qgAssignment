#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <conio.h>

int main()
{

   printf("\n1.手动测试\n");
   printf("\n2.自动测试\n");

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
                 printf("请耐心等候。");
                 testTime(choose,10000);
                 testTime(choose,50000);
                 testTime(choose,200000);
                 testTime2(choose);
                 Testresult();
                 break;

        default:printf("输入错误了噢！");
     }


    getch();

    return 0;
}
