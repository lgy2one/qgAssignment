#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <conio.h>
#include <string.h>

int main()
{
     printf("\n--------------------------------------------");
     printf("欢迎进入图书管理系统");
     printf("------------------------------------------------------\n");

           TNode Q;             //指向书库的指针定义为Q
           LNode P;            //指向借书用户信息的指针定义为P

     create1(&Q);                //创建链表
     create2(&P);

    char uselessArr[20];           //存放输入错误时无用的字符串
    int operate = -1;
    while(1)
    {Interface();         //控制用户界面
        scanf("%d",&operate);
         if(operate == -1)    gets(uselessArr);
          switch(operate)
         {
             case(1):print(&Q);break;              //显示库存中的书及其相关信息

             case(2):addOperate(&Q);break;          //增加一本书

             case(3):logoutBook(&Q);break;          //注销一本书

             case(4):lendBook(&Q,&P);break;         //借书

             case(5):returnBook(&Q,&P);break;        //还书

             case(6):searchBook2(&Q);break;      //搜寻某作者的全部书籍

             case(7):searchBook3(&Q,&P);break;    //搜寻某本书的全部信息

             case(8):appoint(&Q,&P);break;        //预约书本

             case(0):return 0;break;

             default:printf("\n输入错误了噢！\n");

         }
    }

    getch();

    return 0;
}
