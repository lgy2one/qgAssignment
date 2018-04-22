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

//������������һ�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL
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
//���ٸ���������
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

//�ڵ� index λ������� node ���
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("��������Ľ��λ�����󣬲���ʧ�ܣ�\n\n");
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

//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data����
//ɾ���ɹ����� SUCCESS������������� ERROR
Status delet(ptr_Node *head, int index, int *data)
{
  if(index < 1 || index > array_lenth || *head == NULL)
        {
            printf("��������Ľ��λ������ɾ��ʧ�ܣ�\n\n");
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


//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ��
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
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
	     printf("������������ݣ�\n\n");
	     return -1;
     }
   }

   return position;
}



//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data)
//�޸ĳɹ����� SUCCESS������������� ERROR
Status edit(ptr_Node head, int index, int *data)
{
  if(index < 1 || index > array_lenth || head == NULL)
        {
            printf("��������Ľ��λ�������޸�ʧ�ܣ�\n\n");
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
	     printf("�����������㣡\n\n��Ȼ���ԭ��������\n");
	     return ERROR;
     }

     point++;
  }

   p->data=*data;

   printf("�޸Ľ��������Ϊ��\n");

   return SUCCESS;
}

//����ѡ��,ʵ�ֵ������սڵ�ֵ��С��������
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

//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print(ptr_Node head)
{
   int i;
   ptr_Node p;
   p=head;
   if (head == NULL)
    printf("�������Ѿ���ɾ���򲻴��ڡ�\n");

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

    for(i = 0;i < n;i++)                         //������Ҫ�������������
    {
        arr[i] = i+1;
    }

    ptr_Node head;
    ptr_Node new_node;

    head = create(arr,n);

    printf("�½��������������£�\n\n");
    print(head);

    new_node=(ptr_Node)malloc(LEN);              //�½���Ҫ����Ľ��

    printf("�����ڵڼ�λ��������㣬������һ����������\n\n");
    scanf("%d",&index1);
    printf("��ϣ���½ڵ��������ʲô��������һ��������\n\n");
    scanf("%d",&(new_node->data));

    if(insert(&head, new_node, index1))                          //���������Ƿ���ȷ���ж�
    {
        printf("�������������������£�\n\n");
        print(head);
    }

    printf("�����ڵڼ�λ����ɾ����㣬�����룺\n\n");
    scanf("%d",&index2);

    if(delet(&head, index2, save_data))                           //���������Ƿ���ȷ���ж�
    {
        printf("ɾ������������������£�\n\n");
        print(head);
    }

    printf("���������Ľ��������ʲô�������룺\n\n");
    scanf("%d",&search_data);

    if(search(head, search_data) == -1)
        printf("�ý�㲢�����ڡ�\n\n");
    else
        printf("�ý���ǰһλ�ǵ�%d����㡣\n\n",search(head, search_data));

    printf("�����ڵڼ�λ�����޸Ľ�㣬�����룺\n\n");
    scanf("%d",&index3);
    printf("��ϣ���޸ĺ��������ʲô�������룺\n\n");
    scanf("%d",&modified_data);

    if(edit(head, index3, &modified_data))                           //���������Ƿ���ȷ���ж�
    {
        printf("�޸Ľ���������������£�\n\n");
        print(head);
    }


    sort(&head);
    printf("�������������������������£�\n\n");
    print(head);

    destroy(head);

    printf("�밴���������\n\n");
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

