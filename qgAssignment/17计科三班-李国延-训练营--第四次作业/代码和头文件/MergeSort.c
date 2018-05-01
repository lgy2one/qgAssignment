#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void Merge(ElemType *array,int low,int mid,int high)
{

    int i = low,j = mid+1,p = 0;                //置初始值
    ElemType *array1;                        //R1是局部变量
    array1 = (ElemType *)malloc((high-low+1)*sizeof(ElemType));
    if(!array1)
    {
        return;                         //申请空间失败
    }

    while(i <= mid && j <= high)                //两子文件非空时取其小者输出到R1[p]上
    {
        array1[p++] = (array[i]<=array[j])?array[i++]:array[j++];
    }

    while(i <= mid)                         //若第1个子文件非空，则复制剩余记录到R1中
    {
        array1[p++] = array[i++];
    }
    while(j <= high)                      //若第2个子文件非空，则复制剩余记录到R1中
    {
        array1[p++]=array[j++];
    }

    for(p=0,i=low;i<=high;p++,i++)
    {
        array[i]=array1[p];                     //归并完成后将结果复制回R[low..high]
    }
}

void MergeSort(ElemType array[],int low,int high)
{
    //用分治法对R[low..high]进行二路归并排序
    int mid;
    if(low < high)        //区间长度大于1
    {
        mid = (low+high)/2;               //分解
        MergeSort(array,low,mid);           //递归地对R[low..mid]排序
        MergeSort(array,mid+1,high);        //递归地对R[mid+1..high]排序
        Merge(array,low,mid,high);          //组合，将两个有序区归并为一个有序区
    }

}
