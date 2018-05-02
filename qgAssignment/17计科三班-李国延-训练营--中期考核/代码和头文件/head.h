#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define LEN1 sizeof(struct TNode)
#define LEN2 sizeof(struct LNode)

typedef struct TNode          //该结点储存书籍的相关信息
{
	struct TNode *next;
	struct TNode *prev;
	struct TNode *rear;

	int  bookNum;          //书的编号
	char bookName[30];
	char bookAuthor[30];
	int  standingStock;    //现存量
	int  totalStock;      //库存量
	int  able2lend;      //可外借的书籍（部分被预约）

}TNode, *ptrTNode;

typedef struct LNode                //该结点储存借阅者的相关信息
{
	struct LNode *next;
	struct LNode *prev;
	struct LNode *rear;

	int  appointDate;            //预约时间期限
	int  limitDate;            //借阅期限
	char bookName[30];
	char ID[30];             //图书证号

}LNode, *ptrLNode;


//建立书库
void create1(ptrTNode Q);

//建立储存借阅者信息的链表
void create2(ptrLNode Q);

//查看库存的书
void print(ptrTNode Q);

//添加书本的操作
void addOperate(ptrTNode Q);

//添加一本书到书库中
void addBook(ptrTNode Q,char *bookName,char *bookAuthor);

//注销书本
void logoutBook(ptrTNode Q);

//借阅书本
void lendBook(ptrTNode Q,ptrLNode P);

//归还书本
void returnBook(ptrTNode Q,ptrLNode P);

//搜寻某一个作者的全部书籍
void searchBook2(ptrTNode Q);

//搜寻某本书的全部信息
void searchBook3(ptrTNode Q,ptrLNode P);

//预约借书
void appoint(ptrTNode Q,ptrLNode P);

//格式需要，将字符串统一为16个字符
char* format(char* Name);

//交互界面
void Interface(void);

//添加借阅者的信息
void addimfor(ptrLNode P,char *ID,int limitDate,char *bookName,int appointDate);

//搜寻借阅者所借的书本
void searchBook1(ptrTNode Q,ptrLNode q);



#endif // HEAD_H_INCLUDED


