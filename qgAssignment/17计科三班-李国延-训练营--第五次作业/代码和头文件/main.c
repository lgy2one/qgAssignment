#include <stdio.h>
#include <stdlib.h>
#include "Binarytree.h"

int main()
{
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTNode));

    char definition = '1';            //��definition=1��ʱ�򣬽�һ��ǰ׺���ʽ����ɶ�����

    face();    //ʹ��˵��
    T = CreateBiTree(T,&definition);   //���������

    if(T != NULL)
    {
        printf("\n\n�����ӡ��������");
        PreOrderTraverse(T);               //���������ӡ

           printf("\n\n�����ӡ��������");
           InOrderTraverse(T,visit);         //���������ӡ

        printf("\n\n�����ӡ��������");
        PostOrderTraverse(T,visit);       //���������ӡ

           printf("\n\n��δ�ӡ��������");
           LevelOrderTraverse(T,visit);         //��α�����ӡ


        printf("\n\n��ǰ׺���ʽ��ֵΪ��");
        int result = Value(T);           //������

        printf("%d\n",result);


    DestroyBiTree(T);
    }


    return 0;
}
