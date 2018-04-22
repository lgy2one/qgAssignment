#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)
#define array_lenth 63

typedef struct Node
{ int data;
  struct Node *next;
}Node, *ptr_Node;

typedef enum Status
{
	ERROR,
	SUCCESS
}Status;

//根据数组生成一条链表，成功则返回头节点，失败返回 NULL
ptr_Node create(int *arr, int n)
{
   ptr_Node q,p,head;
   int flag = 0;

   head = p = (ptr_Node)malloc(LEN);

   head->data = arr[0];

   while(flag != n-1)
   {
      flag++;

      q = p;
      p = (ptr_Node)malloc(LEN);
         p->data = arr[flag];
         q->next = p;

   }

    p->next = NULL;

    return head;
}
//销毁给定的链表
void destroy(ptr_Node head)
{
	ptr_Node p=NULL;
      while(head!=NULL)
      {
          p = head ;

     	  head = p->next;

     	  free(p);

     	  p = NULL;
      }

}

//在第 index 位后面插入 node 结点
//插入成功返回 SUCCESS，失败返回 ERROR
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("您所输入的结点位置有误，插入失败！\n\n");
            return ERROR;
        }

	ptr_Node p,q;
    int point = 0;

	p = *head;
	while(point != index)
	{ q = p;
	  p = p->next;
	  point++;
	}

	q->next = node;
	node->next = p;

	return SUCCESS;
}

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
//删除成功返回 SUCCESS，其他情况返回 ERROR
Status delet(ptr_Node *head, int index, int *data)
{
  if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("您所输入的结点位置有误，删除失败！\n\n");
            return ERROR;
        }

  ptr_Node p,q;
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
          q->next = p->next;
          free(p);
      }

    return SUCCESS;
}


//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置
//（例：头节点相等，返回 0），没找到或者其他情况返回-1
int search(ptr_Node head, int data)
{
   ptr_Node p;
   p=head;

   int position=0;

   while(p->data!=data)
   {
      position++;
      p=p->next;

	 if(p==NULL)
	 {
	     printf("不存在这个数据！\n\n");
	     return -1;
     }
   }

   return position;
}



//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data)
//修改成功返回 SUCCESS，其他情况返回 ERROR
Status edit(ptr_Node head, int index, int *data)
{
  if(index < 1 || index > array_lenth || head == NULL)
        {
            printf("您所输入的结点位置有误，修改失败！\n\n");
            return ERROR;
        }

  ptr_Node p,q;
  int point = 0;
  p = head;


  while(point != index)
  {  q=p;
     p=p->next;

	 if(p==NULL)
	 {
	     printf("不存在这个结点！\n\n仍然输出原来的链表：\n");
	     return ERROR;
     }

     point++;
  }

   p->data=*data;

   printf("修改结点后的链表为：\n");

   return SUCCESS;
}

//此题选做,实现单链表按照节点值大小升序排序
Status sort(ptr_Node *head)
{
    void select_sort(int a[],int n);
    int i = 0;
    int temp[array_lenth+1]={0} ;

    ptr_Node L = *head;

    if (*head == NULL)  return ERROR;

    for (i = 0; L != NULL; i++)
    {
        temp[i] = L->data;
        L = L->next;
    }

    select_sort(temp,array_lenth+1);
    L = *head;

    for (i = 0; L != NULL; i++)
    {
        L->data = temp[i];
        L = L->next;
    }

   return SUCCESS;
}

//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_Node head)
{
   int i;
   ptr_Node p;
   p=head;
   if (head == NULL)
    printf("该链表已经被删除或不存在。\n");

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
    int save_data[5];
    int search_data;
    int modified_data;

    for(i = 0;i < n;i++)                         //建立需要建成链表的数组
    {
        arr[i] = i+1;
    }

    ptr_Node head;
    ptr_Node new_node;

    head = create(arr,n);

    printf("新建的链表数据如下：\n\n");
    print(head);

    new_node=(ptr_Node)malloc(LEN);              //新建需要插入的结点

    printf("您想在第几位后面插入结点，请输入一个正整数：\n\n");
    scanf("%d",&index1);
    printf("您希望新节点的数据是什么，请输入一个整数：\n\n");
    scanf("%d",&(new_node->data));

    if(insert(&head, new_node, index1))                          //输入数据是否正确的判断
    {
        printf("插入结点后的链表数据如下：\n\n");
        print(head);
    }

    printf("您想在第几位后面删除结点，请输入：\n\n");
    scanf("%d",&index2);

    if(delet(&head, index2, save_data))                           //输入数据是否正确的判断
    {
        printf("删除结点后的链表数据如下：\n\n");
        print(head);
    }

    printf("您想搜索的结点数据是什么，请输入：\n\n");
    scanf("%d",&search_data);

    if(search(head, search_data) == -1)
        printf("该结点并不存在。\n\n");
    else
        printf("该结点的前一位是第%d个结点。\n\n",search(head, search_data));

    printf("您想在第几位后面修改结点，请输入：\n\n");
    scanf("%d",&index3);
    printf("您希望修改后的数据是什么，请输入：\n\n");
    scanf("%d",&modified_data);

    if(edit(head, index3, &modified_data))                           //输入数据是否正确的判断
    {
        printf("修改结点后的链表数据如下：\n\n");
        print(head);
    }


    sort(&head);
    printf("经过降序排序后的链表数据如下：\n\n");
    print(head);

    destroy(head);

    printf("请按任意键结束\n\n");
    getch();
	return 0;
}


 void select_sort(int a[],int n)
{
 	 int i,j,k;
 	 int temp;

 	 for(i=0;i<n-1;i++)
 	{ k=i;
	   for(j=i+1;j<n;j++)
	     if(a[j]>a[k])
		    k=j;
		 if(k!=i)
		{ temp=a[k];
		  a[k]=a[i];
		  a[i]=temp;
        }
     }

}

