#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef float ElemType;

typedef struct SqStack{
       ElemType	*elem;
       int top;      //����ջ��ָ��
       int size;
}SqStack;

typedef  struct StackNode
{
	char data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;


Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e);
Status clearStack(SqStack *s);
Status destoryStack(SqStack *s);
Status stackLength(SqStack *s,int length);
Status pushStack(SqStack *s,ElemType datas);
Status popStack(SqStack *s,ElemType *datas);


Status initLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,char *e);
Status clearLStack(LinkStack *s);
Status destoryLStack(LinkStack *s);
Status LStackLength(LinkStack *s,int *length);
Status pushLStack(LinkStack *s,char datas);
Status popLStack(LinkStack *s,char *datas);


#endif // STACK_H_INCLUDED
