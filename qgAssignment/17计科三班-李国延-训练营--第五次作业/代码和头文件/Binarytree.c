#include <stdio.h>
#include <stdlib.h>
#include "Binarytree.h"
#include <string.h>

BiTree CreateBiTree(BiTree T, char* definition)
{
   if(*definition == '1')             //definition为1时构造前缀表达式的二叉树
    {
        int tag;
        ElemType ch;
        scanf("%c",&ch);

            if(ch <= '9' && ch >= '0'){               //用tag标志是数字还是符号
                tag = 1;}

            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ){

                tag = 0;}

            else
                tag = -1;


        if(tag == 1)
        {
            T = (BiTree)malloc(sizeof(BiTNode));           //数字为结点则不再开辟左右孩子
            T->data = ch;
               T->lchild = NULL;
               T->rchild = NULL;
        }

        else if(tag == 0)
        {
            T = (BiTree)malloc(sizeof(BiTNode));        //符号为结点则依次开辟结点
            T->data = ch;
              T->lchild = NULL;
              T->rchild = NULL;

            T->lchild = CreateBiTree(T->lchild,definition);
            T->rchild = CreateBiTree(T->rchild,definition);
        }

        else {printf("\nEnter error!\n");return NULL;}          //tag=-1时为错误

    }

      return T;
}

Status DestroyBiTree(BiTree T)           //销毁二叉树
{
    if(T != NULL)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T = NULL;
    }

    if(T == NULL)  return SUCCESS;
    else          return ERROR;
}


char array[50];                      //数组用来存放输入的前缀表达式，以便后面的计算
int  j = 0;

Status PreOrderTraverse(BiTree T)
{
    if(T == NULL) return ERROR;

    if(T != NULL)
    {
        printf("%c  ",T->data);
        array[j++] = T->data;
        if(T->lchild != NULL)  PreOrderTraverse(T->lchild);
        if(T->rchild != NULL)  PreOrderTraverse(T->rchild);
    }

    return  SUCCESS;
}


int Value(BiTree T)                     //计算前缀表达式
{
    if(T == NULL) return ERROR;

    int result = 0;
    int a;
    int b;

   while(j)
   {

      if(array[j-1] >= '0' && array[j-1] <= '9')   //如果时数字则进栈
      {
          numPUSH((int)(array[j-1] - '0'));
      }

      else                                     //如果是符号则出栈，进行运算
      {
          numPOP(&a);
          numPOP(&b);

          switch(array[j-1])
          {
              case('+'):result = a + b;break;

              case('-'):result = a - b;break;

              case('*'):result = a * b;break;

              case('/'):result = a / b;break;

              default:printf("the end");break;
          }

           numPUSH(result);                             //结果进栈
       }
       j--;

   }
    return result;
}




