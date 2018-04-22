#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status initStack(SqStack *s,int sizes)  //初始化链表
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


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
   return (-1 == s->top?OK : ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
   if(NULL == s || (*s).top == -1)
            return ERROR;
   else
            *e = s->elem[(*s).top];
   return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
    if(NULL == s)
            return ERROR;

    s->top = -1;
    s->size = 0;

    return OK;
}


Status destoryStack(SqStack *s)  //销毁链表
{
    if(NULL == s)
            return ERROR;
    free(s->elem);
    return OK;
}


Status stackLength(SqStack *s,int length)   //检测链表长度
{
    length = s->size;

    return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
   if(NULL == s || s->top >= s->size - 1)      //栈满
            return ERROR;
   s->top++;                      //栈顶指针加一
   s->elem[s->top] = datas;           //将新插入函数赋值给栈顶空间

   return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
   if(NULL == s || s->top == -1)
       return ERROR;


   *datas = s->elem[s->top];       //将要删除的栈顶元素赋值给datas
   s->top--;                       //栈顶指针减一

   return OK;
}
