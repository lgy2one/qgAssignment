#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <conio.h>
#include <string.h>

int main()
{
     printf("\n--------------------------------------------");
     printf("��ӭ����ͼ�����ϵͳ");
     printf("------------------------------------------------------\n");

           TNode Q;             //ָ������ָ�붨��ΪQ
           LNode P;            //ָ������û���Ϣ��ָ�붨��ΪP

     create1(&Q);                //��������
     create2(&P);

    char uselessArr[20];           //����������ʱ���õ��ַ���
    int operate = -1;
    while(1)
    {Interface();         //�����û�����
        scanf("%d",&operate);
         if(operate == -1)    gets(uselessArr);
          switch(operate)
         {
             case(1):print(&Q);break;              //��ʾ����е��鼰�������Ϣ

             case(2):addOperate(&Q);break;          //����һ����

             case(3):logoutBook(&Q);break;          //ע��һ����

             case(4):lendBook(&Q,&P);break;         //����

             case(5):returnBook(&Q,&P);break;        //����

             case(6):searchBook2(&Q);break;      //��Ѱĳ���ߵ�ȫ���鼮

             case(7):searchBook3(&Q,&P);break;    //��Ѱĳ�����ȫ����Ϣ

             case(8):appoint(&Q,&P);break;        //ԤԼ�鱾

             case(0):return 0;break;

             default:printf("\n����������ޣ�\n");

         }
    }

    getch();

    return 0;
}
