#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "calculate.h"
#define sizes 50

int main()
{
    view();                                     //��������һ�����������
    char str[sizes]={'0'};                      //��ʼ��һ���ַ������ű��ʽ
    int stringLen;                              //�ⶨ�ַ�������
    int judge = 1;                              //�ж��Ƿ��������

    while(1)
  {
          SqStack numStack;                    //˳��ջ��Ų�����
          LinkStack oprStack;                  //��ջ��������

    initLStack(&oprStack);                      //����ĳ�ʼ��
    initStack(&numStack,sizes);
    pushLStack(&oprStack ,'#');

          printf("\n******************************\n");
          printf("\n���������������ʽ��:\n\n");
          gets(str);                            //����������ʽ

          stringLen = strlen(str);
          str[stringLen] = '#';               //��β����һ��#������֮��ļ���
          str[stringLen+1] = '\0';


    for(int i = 0;i < stringLen+1;i++)                   //��������ַ�������������
          if(process(&numStack,&oprStack,str[i]))        //����������򷵻ؼ�ֵ������ѭ��
              {
                  judge = 0;
                  break;
              }


     float result = 0;
         result = numStack.elem[numStack.top];                   //���Ϊ˳��ջ��ջ��Ԫ�ص�ֵ

     if(judge)  printf("\nThe result is %.4f\n",result);         //�޳�����������

     judge = 1;

     destoryLStack(&oprStack);                                  //����ջ
     destoryStack(&numStack);

     printf("\n\n����������������ո���˳�\n\n");
      str[49] = 32;                                             //��������ǿո�ͽ�������
     if(str[49] == getch())  break;
   }

}
