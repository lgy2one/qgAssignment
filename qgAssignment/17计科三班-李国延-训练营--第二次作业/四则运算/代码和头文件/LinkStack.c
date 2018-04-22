#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status initLStack(LinkStack *s)   //��ʼ��
{
    LinkStackPtr pNewNode = (LinkStackPtr)malloc(sizeof(LinkStackPtr));

  if (NULL == pNewNode)
  {
     exit(0);
  }

  pNewNode->data = '0';
  s->count = 0;
  s->top = pNewNode;
  pNewNode->next = NULL;

  return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
    return (0 == s->count?OK : ERROR);
}

Status getTopLStack(LinkStack *s,char *e)  //�õ�����ͷԪ��
{
   if(NULL == s || s->top->next == NULL)
            return ERROR;
   else
            *e = s->top->data;
   return OK;
}

Status clearLStack(LinkStack *s)   //�������
{
    if(s->count == 0)
            return ERROR;
    else
    {
        s->count = 0;
        s->top = NULL;
    }

   return OK;
}

Status destoryLStack(LinkStack *s)   //��������
{
    if (NULL == s)
  {
     exit(0);
  }
    LinkStackPtr pTemp;

    while(s->count)
    {
     pTemp = s->top;
     s->top = s->top->next;
     s->count--;

         free(pTemp);
         pTemp = NULL;
    }
    return OK;
}

Status LStackLength(LinkStack *s,int *length)    //���������
{
     *length = s->count;
         return OK;
}

Status pushLStack(LinkStack *s,char datas)   //��ջ
{
    LinkStackPtr  pNewNode;

    pNewNode = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
    if (NULL == pNewNode)
     {
        exit(0);
     }

    pNewNode->next = s->top;
    pNewNode->data = datas;
	s->top = pNewNode;
	s->count++;

	return OK;
}

Status popLStack(LinkStack *s,char *datas)   //��ջ
{
    if (NULL == s->top || s->count == 0)
     {
        exit(0);
     }

     LinkStackPtr pTemp = s->top;

     *datas = s->top->data;
     s->top = s->top->next;
     s->count--;

     free(pTemp);
     pTemp = NULL;

     return OK;

}
