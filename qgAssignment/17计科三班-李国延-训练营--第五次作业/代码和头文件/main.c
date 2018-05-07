#include <stdio.h>
#include <stdlib.h>
#include "Binarytree.h"

int main()
{
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTNode));

    char definition = '1';            //当definition=1的时候，将一个前缀表达式构造成二叉树

    face();    //使用说明
    T = CreateBiTree(T,&definition);   //构造二叉树

    if(T != NULL)
    {
        printf("\n\n先序打印二叉树：");
        PreOrderTraverse(T);               //先序遍历打印

           printf("\n\n中序打印二叉树：");
           InOrderTraverse(T,visit);         //中序遍历打印

        printf("\n\n后序打印二叉树：");
        PostOrderTraverse(T,visit);       //后序遍历打印

           printf("\n\n层次打印二叉树：");
           LevelOrderTraverse(T,visit);         //层次遍历打印


        printf("\n\n该前缀表达式的值为：");
        int result = Value(T);           //计算结果

        printf("%d\n",result);


    DestroyBiTree(T);
    }


    return 0;
}
