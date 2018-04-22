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

//������������һ��˫�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL
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

//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data����
Status delete_T(ptr_TNode *head, int index, int *data)
{
  if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("��������Ľ��λ������ɾ��ʧ�ܣ�\n\n");
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
//˫������,�ڵ� index λ������� node ���
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("��������Ľ��λ�����󣬲���ʧ�ܣ�\n\n");
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
//���ٸ���������
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
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print(ptr_TNode head)
{
	int i;
   ptr_TNode p;
   p=head;
   if (head == NULL)
    printf("�������Ѿ���ɾ��\n");

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

    printf("�½��������������£�\n\n");
    print(head);

    printf("�����ڵڼ�λ����ɾ����㣬������һ����������\n\n");
    scanf("%d",&index2);

    if(delete_T(&head, index2, save_data))                           //���������Ƿ���ȷ���ж�
    {
        printf("ɾ������������������£�\n\n");
        print(head);
    }

	new_node=(ptr_TNode)malloc(LEN);

    printf("�����ڵڼ�λ��������㣬������һ����������\n\n");
    scanf("%d",&index1);
    printf("��ϣ���½ڵ��������ʲô��������һ��������\n\n");
    scanf("%d",&(new_node->data));

    if(insert_T(&head, new_node, index1))                          //���������Ƿ���ȷ���ж�
    {
        printf("�������������������£�\n\n");
        print(head);
    }

    getch();
	return 0;
}
