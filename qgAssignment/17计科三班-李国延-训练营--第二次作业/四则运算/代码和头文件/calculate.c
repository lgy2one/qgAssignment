#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int Cint(char mychar)                //将字符转换成整数
{
   return(mychar-48);
}

int intPart(int *num ,int digitNum)             //把连续的数字字符转化成整数
{
    int i,j = 0;
    int sum = 0;

    for(i = digitNum ;i > 0 ;i--)
    {
        sum += num[j++] * pow(10,i-1);
    }

    return sum;
}

float fracPart(int *num ,int digitNum)             //把连续的数字字符转化成小数
{
    int i,j = 0;
    float sum = 0;

    for(i = digitNum ;i > 0 ;i--)
    {
        sum += num[j++] * pow(10,i-digitNum-1);
    }

    return sum;
}

float Calc(float a,float b,char c)         //将出栈的两个数进行运算
{
   float result=0;
   switch(c)
 { case('+'):result = a+b;break;
   case('-'):result = a-b;break;
   case('*'):result = a*b;break;
   case('/'):result = a/b;break;
 //*  case('%'):result = a%b;break;   *//
   default:printf("enter data error!\n");
 }
   return result;

}

char priority(char y,char x)            //遇到符号后将其与栈顶符号比较得出优先级
{
    char priority='<';

    switch(x)

 {  case('+'):

    case('-'):   if(y=='('||y=='#') priority='>';break;

    case('*'):

   	case('/'):   if(y=='('||y=='#'||y=='+'||y=='-'||y=='%') priority='>';break;

    case('('):   priority='>';break;

   	case(')'):   if(y=='(') priority='=';break;

    case('#'):   if(y=='#') priority='=';break;

    case('%'):   if(y=='('||y=='#'||y=='+'||y=='-') priority='>';break;

    default: priority='E';break;
 }
	return priority;
}

int process(SqStack *numStack,LinkStack *oprStack,char ch)
{
    float a = 0,b = 0;
    static int intNumber = 0;
    float fracNumber = 0;
    char c;
    static int flag = 0;
    static int i = 0;
    static int saveNum[10];

	   if(ch >= '0' && ch <= '9' || ch == '.')
        {
            if(ch >= '0' && ch <= '9')                      //若是数字，则先存到一个数组中
               {
                   saveNum[i++] = Cint(ch);
                   flag = 0;
               }

            else
              {
                  intNumber = intPart(saveNum,i);     //若是小数点，将小数点前面的数字字符串转化成整数
                  memset(saveNum,0,sizeof(float)*10);    // 重置该数组
                  i = 0;
              }

            return 0;
        }

        else
            {
               if(flag == 0)
                 {
                    if(intNumber == 0)                              //若本来输入的数字没有小数点
                    {                                              //则把数字字符串转化成整数放入栈中
                        intNumber = intPart(saveNum,i);
                        pushStack(numStack,intNumber);
                        i = 0;
                        memset(saveNum,0,sizeof(float)*10);
                        intNumber = 0;
                    }
                    else                                           //若有小数点，则把小数点前后两部分
                    {                                              //的数加起来放进栈中
                        fracNumber = fracPart(saveNum,i);
                        pushStack(numStack,intNumber+fracNumber);
                        memset(saveNum,0,sizeof(float)*10);         //重置该数组
                        intNumber = 0;                              //重置整数部分
                    }
                 }
            }

		    switch(priority(oprStack->top->data,ch))        //判断优先级
		 {
		    case('>'):pushLStack(oprStack , ch);break;
		    case('='):popLStack(oprStack , &c);break;
			case('<'):                                        //若符合情况则计算
		    	popStack(numStack ,&b);
		    	popStack(numStack ,&a);
		    	popLStack(oprStack ,&c);
		    	pushStack(numStack , Calc(a,b,c));
		    	flag++;                                 //flag的作用：经过一次计算后，saveNum
		   	    process(numStack,oprStack,ch);          //不应该再把saveNum里面的数再整合成整数压栈

		    	break;


			default:
			    {
			        printf("Enter data error!\n");                //输入错误时显示
			        return 1;
                }

         }

     return 0;
}


