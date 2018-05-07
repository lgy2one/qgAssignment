#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef char ElemType;     // 假设二叉树结点的元素类型为字符

typedef struct {
   ElemType *elem;     // 0号单元闲置
   int lastIndex;     // 二叉树最后一个结点的编号
} SqBiTree;          // 顺序存储的二叉树

typedef struct  BiTNode {
    ElemType data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode,*BiTree;   // 二叉链表

typedef enum Status{
	SUCCESS,
	ERROR
} Status;


Status DestroyBiTree(BiTree T);
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T

BiTree CreateBiTree(BiTree T, char* definition);
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T

void *visit(BiTree T);
//对结点操作的应用函数

//以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTree T);
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败

Status InOrderTraverse(BiTree T, void *visit(BiTree T));	//中序遍历

Status PostOrderTraverse(BiTree T, void *visit(BiTree T));	//后序遍历

Status LevelOrderTraverse(BiTree T, void *visit(BiTree T));	//层序遍历


void numPUSH(int num);          //压栈

void numPOP(int *num);         //弹栈

int Value(BiTree T);		 //构造出的二叉树求值

void face(void);           //用户说明

/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/

#endif // BINARYTREE_H_INCLUDED
