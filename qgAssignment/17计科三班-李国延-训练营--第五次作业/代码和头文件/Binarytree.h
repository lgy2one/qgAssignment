#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef char ElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct {
   ElemType *elem;     // 0�ŵ�Ԫ����
   int lastIndex;     // ���������һ�����ı��
} SqBiTree;          // ˳��洢�Ķ�����

typedef struct  BiTNode {
    ElemType data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
} Status;


Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T

BiTree CreateBiTree(BiTree T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T

void *visit(BiTree T);
//�Խ�������Ӧ�ú���

//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T);
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��

Status InOrderTraverse(BiTree T, void *visit(BiTree T));	//�������

Status PostOrderTraverse(BiTree T, void *visit(BiTree T));	//�������

Status LevelOrderTraverse(BiTree T, void *visit(BiTree T));	//�������


void numPUSH(int num);          //ѹջ

void numPOP(int *num);         //��ջ

int Value(BiTree T);		 //������Ķ�������ֵ

void face(void);           //�û�˵��

/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/

#endif // BINARYTREE_H_INCLUDED
