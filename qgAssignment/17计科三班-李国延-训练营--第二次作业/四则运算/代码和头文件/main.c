#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "calculate.h"
#define sizes 50

int main()
{
    view();                                     //界面另作一函数，更简洁
    char str[sizes]={'0'};                      //初始化一个字符数组存放表达式
    int stringLen;                              //测定字符串长度
    int judge = 1;                              //判断是否输入出错

    while(1)
  {
          SqStack numStack;                    //顺序栈存放操作数
          LinkStack oprStack;                  //链栈存放运算符

    initLStack(&oprStack);                      //链表的初始化
    initStack(&numStack,sizes);
    pushLStack(&oprStack ,'#');

          printf("\n******************************\n");
          printf("\n请在下面输入你的式子:\n\n");
          gets(str);                            //输入运算表达式

          stringLen = strlen(str);
          str[stringLen] = '#';               //结尾增加一个#，方便之后的计算
          str[stringLen+1] = '\0';


    for(int i = 0;i < stringLen+1;i++)                   //逐个遍历字符串并进行运算
          if(process(&numStack,&oprStack,str[i]))        //若输入错误，则返回假值，跳出循环
              {
                  judge = 0;
                  break;
              }


     float result = 0;
         result = numStack.elem[numStack.top];                   //结果为顺序栈的栈顶元素的值

     if(judge)  printf("\nThe result is %.4f\n",result);         //无出错则输出结果

     judge = 1;

     destoryLStack(&oprStack);                                  //销毁栈
     destoryStack(&numStack);

     printf("\n\n按任意键继续，按空格键退出\n\n");
      str[49] = 32;                                             //若输入的是空格就结束函数
     if(str[49] == getch())  break;
   }

}
