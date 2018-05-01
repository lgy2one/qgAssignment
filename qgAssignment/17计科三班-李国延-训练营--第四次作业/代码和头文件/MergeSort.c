#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void MergeSort(ElemType R[],int low,int high)
{
    //�÷��η���R[low..high]���ж�·�鲢����
    int mid;
    if(low < high)
    {   //���䳤�ȴ���1
        mid = (low+high)/2;               //�ֽ�
        MergeSort(R,low,mid);           //�ݹ�ض�R[low..mid]����
        MergeSort(R,mid+1,high);        //�ݹ�ض�R[mid+1..high]����
        Merge(R,low,mid,high);          //��ϣ��������������鲢Ϊһ��������
    }

}

void Merge(ElemType *R,int low,int mid,int high)
{
    //��������������ļ�R[low..m)��R[m+1..high]�鲢��һ����������ļ�R[low..high]
    int i = low,j = mid+1,p = 0;                //�ó�ʼֵ
    ElemType *R1;                        //R1�Ǿֲ�����
    R1=(ElemType *)malloc((high-low+1)*sizeof(ElemType));
    if(!R1)
    {
        return;                         //����ռ�ʧ��
    }

    while(i<=mid && j<=high)                //�����ļ��ǿ�ʱȡ��С�������R1[p]��
    {
        R1[p++] = (R[i]<=R[j])?R[i++]:R[j++];
    }

    while(i <= mid)                         //����1�����ļ��ǿգ�����ʣ���¼��R1��
    {
        R1[p++] = R[i++];
    }
    while(j <= high)                      //����2�����ļ��ǿգ�����ʣ���¼��R1��
    {
        R1[p++]=R[j++];
    }

    for(p=0,i=low;i<=high;p++,i++)
    {
        R[i]=R1[p];                     //�鲢��ɺ󽫽�����ƻ�R[low..high]
    }
}
