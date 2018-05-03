#include "head.h"
#include <stdlib.h>
#include <string.h>

void initBookStock(ptrTNode Q)                  //将书库初始化成五本书以便用户操作
{
       char bookName1[30] = "math1           ";
      char bookName2[30] = "math2           ";
     char bookName3[30] = "linearAlgebra   ";
    char bookName4[30] = "electrotechnics1";
   char bookName5[30] = "electrotechnics2";

       char bookAuthor1[30] = "TongJiUniversity";
        char bookAuthor2[30] = "TongJiUniversity";
         char bookAuthor3[30] = "TongJiUniversity";
          char bookAuthor4[30] = "SuChengYue      ";
           char bookAuthor5[30] = "SuChengYue      ";

         Q->rear->bookNum = 0;
   addBook(Q,bookName1,bookAuthor1);
     addBook(Q,bookName2,bookAuthor2);
   addBook(Q,bookName3,bookAuthor3);
     addBook(Q,bookName4,bookAuthor4);
   addBook(Q,bookName5,bookAuthor5);

}
void create1(ptrTNode Q)                    //创建一个书库
{
      Q->rear = (ptrTNode)malloc(LEN1);
      if (Q->rear == NULL)   exit(0);

      Q->rear->next = NULL;
      Q->rear->prev = NULL;

      initBookStock(Q);

}

void create2(ptrLNode P)                      //创建记录借阅者信息的链表
{
      P->rear = (ptrLNode)malloc(LEN2);
      if (P->rear == NULL)   exit(0);

      P->rear->next = NULL;
      P->rear->prev = NULL;
}





