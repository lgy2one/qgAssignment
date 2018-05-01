#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void Merge(ElemType *array,int low,int mid,int high)
{

    int i = low,j = mid+1,p = 0;                //�ó�ʼֵ
    ElemType *array1;                        //R1�Ǿֲ�����
    array1 = (ElemType *)malloc((high-low+1)*sizeof(ElemType));
    if(!array1)
    {
        return;                         //����ռ�ʧ��
    }

    while(i <= mid && j <= high)                //�����ļ��ǿ�ʱȡ��С�������R1[p]��
    {
        array1[p++] = (array[i]<=array[j])?array[i++]:array[j++];
    }

    while(i <= mid)                         //����1�����ļ��ǿգ�����ʣ���¼��R1��
    {
        array1[p++] = array[i++];
    }
    while(j <= high)                      //����2�����ļ��ǿգ�����ʣ���¼��R1��
    {
        array1[p++]=array[j++];
    }

    for(p=0,i=low;i<=high;p++,i++)
    {
        array[i]=array1[p];                     //�鲢��ɺ󽫽�����ƻ�R[low..high]
    }
}

void MergeSort(ElemType array[],int low,int high)
{
    //�÷��η���R[low..high]���ж�·�鲢����
    int mid;
    if(low < high)        //���䳤�ȴ���1
    {
        mid = (low+high)/2;               //�ֽ�
        MergeSort(array,low,mid);           //�ݹ�ض�R[low..mid]����
        MergeSort(array,mid+1,high);        //�ݹ�ض�R[mid+1..high]����
        Merge(array,low,mid,high);          //��ϣ��������������鲢Ϊһ��������
    }

}
