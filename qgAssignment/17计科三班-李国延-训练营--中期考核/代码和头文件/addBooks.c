#include "head.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void addBook(ptrTNode Q,char *bookName,char *bookAuthor)
{
   ptrTNode p = Q->rear;            //定义一个变量指向代表某一个结点
    int i = 0;

   while(p->prev != NULL)                      //先判断添加的书是否书库已经有了，有了就库存+1
   {                                           //从尾部开始把书库遍历
       if(!strcmp(p->bookName,bookName))
       {
          p->standingStock++;
          p->totalStock++;
          p->able2lend++;
          return ;
       }
       else
        p = p->prev;
   }


        p = (ptrTNode)malloc(LEN1);           //开辟空间储存新书的空间
       if (p == NULL)     exit(0);

          Q->rear->next = p;
        p->next = NULL;
        p->prev = Q->rear;
          Q->rear = p;

      p->bookNum = Q->rear->prev->bookNum + 1;                      //书的序号加一


	    while(bookName[i] != '\0')                          //书名存进去
        {
            p->bookName[i] = bookName[i];
            p->bookName[i+1] = '\0';
            i++;
        }
	    i = 0;
	        while(bookAuthor[i] != '\0')                 //作者名存进去
            {
                p->bookAuthor[i] = bookAuthor[i];
                p->bookAuthor[i+1] = '\0';
                i++;
            }

         p->standingStock = 1;                       //库存、现存、可借量均为1
	      p->totalStock = 1;
	       p->able2lend = 1;

}

void addOperate(ptrTNode Q)       //添加书的操作函数
{
    printf("\n-*请你输入书名：");
    char bookName[30];
    scanf("%s",bookName);

       printf("\n-*请你输入作者：");
       char bookAuthor[30];
       scanf("%s",bookAuthor);

    addBook(Q,format(bookName),format(bookAuthor));     //添加书到书库中

    printf("\n添加成功！\n");
}


void addimfor(ptrLNode P,char *ID,int limitDate,char *bookName,int appointDate)
{
    ptrLNode p = P->rear;            //定义一个变量指向代表某一个结点
    int i = 0;

        p = (ptrLNode)malloc(LEN2);     //同增加书一样，将参数中的相关值存到结点中
       if (p == NULL)     exit(0);

          P->rear->next = p;
        p->next = NULL;
        p->prev = P->rear;
          P->rear = p;

      p->limitDate = limitDate;
      p->appointDate = appointDate;

	    while(bookName[i] != '\0')
        {
            p->bookName[i] = bookName[i];
            p->bookName[i+1] = '\0';
            i++;
        }

	    i = 0;
	        while(ID[i] != '\0')
            {
                p->ID[i] = ID[i];
                p->ID[i+1] = '\0';
                i++;
            }

}

