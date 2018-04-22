#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status initStack(SqStack *s,int sizes)  //��ʼ������
{
  s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);
  if (NULL == s->elem)
   {
     exit(0);
   }

  s->top = -1;
  s->size = sizes;

  return OK;
}


Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
{
   return (-1 == s->top?OK : ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�����ͷԪ��
{
   if(NULL == s || (*s).top == -1)
            return ERROR;
   else
            *e = s->elem[(*s).top];
   return OK;
}


Status clearStack(SqStack *s)   //�������
{
    if(NULL == s)
            return ERROR;

    s->top = -1;
    s->size = 0;

    return OK;
}


Status destoryStack(SqStack *s)  //��������
{
    if(NULL == s)
            return ERROR;
    free(s->elem);
    return OK;
}


Status stackLength(SqStack *s,int length)   //���������
{
    length = s->size;

    return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{
   if(NULL == s || s->top >= s->size - 1)      //ջ��
            return ERROR;
   s->top++;                      //ջ��ָ���һ
   s->elem[s->top] = datas;           //���²��뺯����ֵ��ջ���ռ�

   return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{
   if(NULL == s || s->top == -1)
       return ERROR;


   *datas = s->elem[s->top];       //��Ҫɾ����ջ��Ԫ�ظ�ֵ��datas
   s->top--;                       //ջ��ָ���һ

   return OK;
}
