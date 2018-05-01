#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void QSortRecursion(ElemType array[], int n, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;      // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
        j = end;            // array[end]����������һλ

        while(i < j)
        {
            if(array[i] > array[begin])     // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                Swap(&array[i], &array[j]);   // ����������
                j--;
            }
            else
            {
                i++;                             // �����������һλ���������׼���Ƚϡ�
            }
        }

        if(array[i] >= array[begin])
        {
            i--;
        }

        Swap(&array[begin], &array[i]);         // ����array[i]��array[begin]

        QSortRecursion(array, n, begin, i);
        QSortRecursion(array, n, j, end);
    }

}



void Swap(ElemType *a, ElemType *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}


int sl[MAXSIZE];
int sr[MAXSIZE];
int sp = 0;

//��ջ
void PUSH(int A, int B)
{
    sl[sp]=A;
    sr[sp]=B;
    sp++;
}

//��ջ
void POP(int* pl, int* pr)
{
    sp--;
    *pl = sl[sp];
    *pr = sr[sp];
}

void QSort(int* a,int l,int r)
{
    int i,j,p,t;

    PUSH(l,r);

    while(sp){
        POP(&l,&r);
        i = l;
        j = r;
        p = a[(i+j)/2];
        while(i <= j) {
            while(a[i] < p)
                i++;
            while(a[j] > p)
                j--;
            if(i <= j){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++;
                j--;
            }
        }

        if(l<j)
            PUSH(l,j);
        if(i<r)
            PUSH(i,r);
    }


}
