#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void Swap(ElemType *a, ElemType *b)         //交换函数，将两个数交换
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

void QSortRecursion(ElemType array[], int n, int begin, int end)    //递归快排
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;      // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;            // array[end]是数组的最后一位

        while(i < j)
        {
            if(array[i] > array[begin])     // 如果比较的数组元素大于基准数，则交换位置。
            {
                Swap(&array[i], &array[j]);   // 交换两个数
                j--;
            }
            else
            {
                i++;                             // 将数组向后移一位，继续与基准数比较。
            }
        }

        if(array[i] >= array[begin])
        {
            i--;
        }

        Swap(&array[begin], &array[i]);         // 交换array[i]与array[begin]

        QSortRecursion(array, n, begin, i);       //递归调用直至全部分配完毕
        QSortRecursion(array, n, j, end);
    }

}


int sl[100];               //定义两个栈，分别放索引指向的最低点和最高点
int sr[100];
int sp = 0;                //栈顶

//入栈
void PUSH(int A, int B)
{
    sl[sp]=A;
    sr[sp]=B;
    sp++;
}

//出栈
void POP(int* pl, int* pr)
{
    sp--;
    *pl = sl[sp];
    *pr = sr[sp];
}

void QSort(int* a,int l,int r)                 //迭代快排
{
    int i,j,p,t;

    PUSH(l,r);

    while(sp){                       //栈空的时候结束循环
        POP(&l,&r);
        i = l;
        j = r;                      //此处为第一次分配
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

        if(l<j)                    //这里是迭代分配，作用相当于递归
            PUSH(l,j);
        if(i<r)
            PUSH(i,r);
    }


}
