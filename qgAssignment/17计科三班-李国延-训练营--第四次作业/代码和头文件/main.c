#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <conio.h>

int main()
{
   printf("\n1.手动测试\n");
   printf("\n2.自动测试\n\n");

   int operate;                 //操作控制符
   int choose;                  //选择手动还是自动
   int dataSize = 0;
   scanf("%d",&operate);

     switch(operate)
     {
        case(1): choose = 0;
                 testTime(choose,dataSize);              //testTime函数测试大数据
                 testTime2(choose);                    //testTime2函数测试大量小数组
                 break;

        case(2): choose = 1;
                 printf("请耐心等候哦，大约需要一两分钟。\n");
                     testTime(choose,10000);                   //自动测试10000、50000、200000
                     testTime(choose,50000);                    // 和 100*100K大量小数据；
                     testTime(choose,200000);
                 testTime2(choose);
                 testResult1();                        //以表格形式输出结果
                 break;

        default:printf("输入错误了噢！");
     }


    testResult2();             //将测试结果输出到文件中
    printf("\n测试结果已经记录到名为testResult的文本文件中。\n\n");

    printf("\n测试数据量已经记录到名为testData的文本文件中。\n\n");
    testData();                //生成10000个测试数据（10000个无序数）

    getch();

    return 0;
}
