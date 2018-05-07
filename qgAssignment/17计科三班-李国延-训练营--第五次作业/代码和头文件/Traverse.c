#include<stdio.h>
#include "Binarytree.h"

Status InOrderTraverse(BiTree T, void *visit(BiTree T))   //���������ӡ������
{
    if(T == NULL) return ERROR;

    if(T!=NULL)
    {
        InOrderTraverse(T->lchild,visit);
        visit(T);
        InOrderTraverse(T->rchild,visit);
    }

    return SUCCESS;
}

Status PostOrderTraverse(BiTree T, void *visit(BiTree T))  //����������ӡ������
{
    if(T == NULL) return ERROR;

    if(T != NULL)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T);
    }

    return SUCCESS;
}

Status LevelOrderTraverse(BiTree T, void *visit(BiTree T))
{
    if(T == NULL) return ERROR;

    BiTree string[50],temp;
    string[0] = T;

    int front = 0, rear = 1;

     while(front < rear)
      {
        temp = string[front++];

          visit(temp);                              //���ӵ�������е�β��
        if(temp->lchild != NULL) string[rear++] = temp->lchild; //������ӷ������
        if(temp->rchild != NULL) string[rear++] = temp->rchild;//���Ҷ��ӷ������
      }


    return SUCCESS;
}


void *visit(BiTree T)
{
    if(T == NULL)  return;

    printf("%c ",T->data);
}
