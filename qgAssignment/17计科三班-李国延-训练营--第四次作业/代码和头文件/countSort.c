#include "sort.h"
#include<stdio.h>
#include<stdlib.h>


// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num,int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

void RadixCountSort(ElemType* dataArray, int n)
{
    int *radixArrays[10];    //分别为0~9的序列空间
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int) * (n + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= 6; pos++)    //从个位开始到第6位
    {
        for (int i = 0; i < n; i++)    //分配过程
        {
            int num = GetNumInPos(dataArray[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = dataArray[i];
        }

        for (int i = 0, j =0; i < 10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                dataArray[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }

}

void countSort(int array[], int size)
{

    int *countArray = (int *) calloc(30000, sizeof(int));
    int *sortedArray = (int *) calloc(size, sizeof(int));

    int index = 0;
    for (index = 0; index < size; ++index) {
        countArray[array[index]]++;
    }

    for (index = 1; index < 30000; ++index) {
        countArray[index] += countArray[index - 1];
    }

    for (index = size - 1; index >= 0; --index) {
        sortedArray[countArray[array[index]] - 1] = array[index];
        --countArray[array[index]];
    }

    free(sortedArray);
    free(countArray);
}
