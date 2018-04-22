#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int Cint(char mychar)                //���ַ�ת��������
{
   return(mychar-48);
}

int intPart(int *num ,int digitNum)             //�������������ַ�ת��������
{
    int i,j = 0;
    int sum = 0;

    for(i = digitNum ;i > 0 ;i--)
    {
        sum += num[j++] * pow(10,i-1);
    }

    return sum;
}

float fracPart(int *num ,int digitNum)             //�������������ַ�ת����С��
{
    int i,j = 0;
    float sum = 0;

    for(i = digitNum ;i > 0 ;i--)
    {
        sum += num[j++] * pow(10,i-digitNum-1);
    }

    return sum;
}

float Calc(float a,float b,char c)         //����ջ����������������
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

char priority(char y,char x)            //�������ź�����ջ�����űȽϵó����ȼ�
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
            if(ch >= '0' && ch <= '9')                      //�������֣����ȴ浽һ��������
               {
                   saveNum[i++] = Cint(ch);
                   flag = 0;
               }

            else
              {
                  intNumber = intPart(saveNum,i);     //����С���㣬��С����ǰ��������ַ���ת��������
                  memset(saveNum,0,sizeof(float)*10);    // ���ø�����
                  i = 0;
              }

            return 0;
        }

        else
            {
               if(flag == 0)
                 {
                    if(intNumber == 0)                              //���������������û��С����
                    {                                              //��������ַ���ת������������ջ��
                        intNumber = intPart(saveNum,i);
                        pushStack(numStack,intNumber);
                        i = 0;
                        memset(saveNum,0,sizeof(float)*10);
                        intNumber = 0;
                    }
                    else                                           //����С���㣬���С����ǰ��������
                    {                                              //�����������Ž�ջ��
                        fracNumber = fracPart(saveNum,i);
                        pushStack(numStack,intNumber+fracNumber);
                        memset(saveNum,0,sizeof(float)*10);         //���ø�����
                        intNumber = 0;                              //������������
                    }
                 }
            }

		    switch(priority(oprStack->top->data,ch))        //�ж����ȼ�
		 {
		    case('>'):pushLStack(oprStack , ch);break;
		    case('='):popLStack(oprStack , &c);break;
			case('<'):                                        //��������������
		    	popStack(numStack ,&b);
		    	popStack(numStack ,&a);
		    	popLStack(oprStack ,&c);
		    	pushStack(numStack , Calc(a,b,c));
		    	flag++;                                 //flag�����ã�����һ�μ����saveNum
		   	    process(numStack,oprStack,ch);          //��Ӧ���ٰ�saveNum������������ϳ�����ѹջ

		    	break;


			default:
			    {
			        printf("Enter data error!\n");                //�������ʱ��ʾ
			        return 1;
                }

         }

     return 0;
}


