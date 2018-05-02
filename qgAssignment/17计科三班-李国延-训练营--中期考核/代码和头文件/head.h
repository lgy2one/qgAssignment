#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define LEN1 sizeof(struct TNode)
#define LEN2 sizeof(struct LNode)

typedef struct TNode          //�ý�㴢���鼮�������Ϣ
{
	struct TNode *next;
	struct TNode *prev;
	struct TNode *rear;

	int  bookNum;          //��ı��
	char bookName[30];
	char bookAuthor[30];
	int  standingStock;    //�ִ���
	int  totalStock;      //�����
	int  able2lend;      //�������鼮�����ֱ�ԤԼ��

}TNode, *ptrTNode;

typedef struct LNode                //�ý�㴢������ߵ������Ϣ
{
	struct LNode *next;
	struct LNode *prev;
	struct LNode *rear;

	int  appointDate;            //ԤԼʱ������
	int  limitDate;            //��������
	char bookName[30];
	char ID[30];             //ͼ��֤��

}LNode, *ptrLNode;


//�������
void create1(ptrTNode Q);

//���������������Ϣ������
void create2(ptrLNode Q);

//�鿴������
void print(ptrTNode Q);

//����鱾�Ĳ���
void addOperate(ptrTNode Q);

//���һ���鵽�����
void addBook(ptrTNode Q,char *bookName,char *bookAuthor);

//ע���鱾
void logoutBook(ptrTNode Q);

//�����鱾
void lendBook(ptrTNode Q,ptrLNode P);

//�黹�鱾
void returnBook(ptrTNode Q,ptrLNode P);

//��Ѱĳһ�����ߵ�ȫ���鼮
void searchBook2(ptrTNode Q);

//��Ѱĳ�����ȫ����Ϣ
void searchBook3(ptrTNode Q,ptrLNode P);

//ԤԼ����
void appoint(ptrTNode Q,ptrLNode P);

//��ʽ��Ҫ�����ַ���ͳһΪ16���ַ�
char* format(char* Name);

//��������
void Interface(void);

//��ӽ����ߵ���Ϣ
void addimfor(ptrLNode P,char *ID,int limitDate,char *bookName,int appointDate);

//��Ѱ������������鱾
void searchBook1(ptrTNode Q,ptrLNode q);



#endif // HEAD_H_INCLUDED


