#include<stdio.h>
#include<stdlib.h>
#define array_lenth 63
#define LEN sizeof(struct TNode)

typedef struct TNode
{
	int data;
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;

typedef enum Status
{
	ERROR,
	SUCCESS
}Status;

//根据数组生成一条双向链表，成功则返回头节点，失败返回 NULL
ptr_TNode create(int *arr, int n)
{
	int i;
   ptr_TNode p,s,head;

   head=(ptr_TNode)malloc(LEN);
   head->data=arr[0];

   if (head == NULL)   exit(0);

      head->next = NULL;
      head->pre = NULL;
      p = head;

   for(i = 1;i < array_lenth;i++)
   {
      s=(ptr_TNode)malloc(LEN);
      if (s == NULL)     exit(0);


      s->data=arr[i];

	  s->next = NULL;

	  p->next=s;
	  s->pre=p;
	  p=s;

   }

   s->next = NULL;

   return head;
}

//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
Status delete_T(ptr_TNode *head, int index, int *data)
{
  if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("您所输入的结点位置有误，删除失败！\n\n");
            return ERROR;
        }

  ptr_TNode p,q;
  int point=0;

  p = *head;

  while(point !=index )
  {
     q = p;
     p = p->next;
     point++;
  }

  if(p == *head)
  {
      *data = p->data;
      *head = (*head)->next;
      (*head)->pre = NULL;
      free(p);
  }

  else

      if(p->next==NULL)
      {
         (*data) = p->data;
         free(p);
         p = NULL;
      }

      else
      {
          *data = p->data;
          p->next->pre = p->pre;
          p->pre->next = p->next;
          free(p);
      }

    return SUCCESS;
}
//双向链表,在第 index 位后面插入 node 结点
//插入成功返回 SUCCESS，失败返回 ERROR
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("您所输入的结点位置有误，插入失败！\n\n");
            return ERROR;
        }

	ptr_TNode p,q;
    int point = 0;

	p = *head;
	while(point != index)
	{ q = p;
	  p = p->next;
	  point++;
	}

	q->next = node;
	node->pre = q;
	node->next = p;
	p->pre = node;

	return SUCCESS;
}
//销毁给定的链表
void destroy(ptr_TNode head)
{
		ptr_TNode p=NULL;
      while(head!=NULL)
      {
          p = head ;

     	  head = p->next;

     	  free(p);

     	  p = NULL;
      }
}
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_TNode head)
{
	int i;
   ptr_TNode p;
   p=head;
   if (head == NULL)
    printf("该链表已经被删除\n");

   while(p != NULL)
   {
      for(i = 1;i <= 8;i++)
      {
          printf("%d\t",p->data);

          p = p->next;

          if(p==NULL)  break;
      }
      printf("\n");
   }
   printf("\n\n");
}

int main()
{
	const int n = array_lenth;
    int arr[n];
    int i;
    int index1,index2,index3;
    int save_data[10];
    int search_data;
    int modified_data;

    for(i = 0;i < n;i++)
    {
        arr[i] = i+1;
    }

    ptr_TNode head;
    ptr_TNode new_node;

    head = create(arr,n);

    printf("新建的链表数据如下：\n\n");
    print(head);

    printf("您想在第几位后面删除结点，请输入一个正整数：\n\n");
    scanf("%d",&index2);

    if(delete_T(&head, index2, save_data))                           //输入数据是否正确的判断
    {
        printf("删除结点后的链表数据如下：\n\n");
        print(head);
    }

	new_node=(ptr_TNode)malloc(LEN);

    printf("您想在第几位后面插入结点，请输入一个正整数：\n\n");
    scanf("%d",&index1);
    printf("您希望新节点的数据是什么，请输入一个整数：\n\n");
    scanf("%d",&(new_node->data));

    if(insert_T(&head, new_node, index1))                          //输入数据是否正确的判断
    {
        printf("插入结点后的链表数据如下：\n\n");
        print(head);
    }

    getch();
	return 0;
}
