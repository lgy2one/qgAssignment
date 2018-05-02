#include "head.h"
#include <stdio.h>
#include <string.h>

void Interface(void)          //选择界面
{
    printf("\n-----------------------------------------------------------");
    printf("-----------------------------------------------------------");
    printf("\n1->显示书 | 2->增加书 | 3->注销书 | ");
    printf("4->借阅 | 5->归还 | 6->查作者 | 7->查书 | 8->预约书 | 0->退出 | ");
    printf("*请选择你的操作* |\n");
    printf("-----------------------------------------------------------");
    printf("-----------------------------------------------------------\n");
}

void print(ptrTNode Q)                     //输出图书管中所有的书
{
        ptrTNode p = Q->rear;

    if (p == NULL)  {printf("库存已经没有图书!\n\n");return;}  //链表尾部为空时输出库存为空

if(p->prev != NULL) {printf("\n本系书库所存图书如下:\n\n");
                printf("-------------------------------------------");
               printf("-------------------------------------------\n");
              printf("书本编号  | ");
             printf("书名    \t      | ");
            printf("作者     \t  | ");
           printf("现存  | ");
          printf("库存 | \t\n");
         printf("-------------------------------------------");
        printf("-------------------------------------------");
      }

      else  printf("\n本书库已经没有书了！");

   while(p->prev != NULL)         //从尾部开始输出图书
      {
        printf("\n %d\t  | ",p->bookNum);
         printf("%s  | ",p->bookName);
           printf("%s  | ",p->bookAuthor);
          printf("%d本\t  | ",p->standingStock);
         printf("%d本  | \t\n",p->totalStock);
        printf("------------------------------------------");
       printf("--------------------------------------------");

          p = p->prev;
      }

   printf("\n\n");

}

char *format(char* Name)            //使书名和作者名限制在16个字符内
{
    int i = 0;
    while(i != 16)
    {
        if(Name[i] == '\0')
        {
           Name[i] = ' ';
           Name[i+1] = '\0';
        }
          i++;
    }
     Name[16] = '\0';               //格式需要和输入限制，最多允许16个字符

    return Name;
}





