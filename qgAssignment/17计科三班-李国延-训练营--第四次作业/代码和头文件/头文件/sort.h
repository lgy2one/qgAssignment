#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef int ElemType;

double result[24];


//��������
void insertSort(ElemType array[],int n);

//�鲢����
void MergeSort(ElemType R[],int low,int high);

//�õݹ�ʵ�ֵĿ�������
void QSortRecursion(ElemType array[], int n, int begin, int end);

//�õ���ʵ�ֵĿ�������
void QSort(int* a,int l,int r);

//��������
void countSort(int array[], int size) ;

//������������
void RadixCountSort(ElemType* dataArray, int n);

//��������
void Interface(void);

//���Դ����ݵ�����ʱ��
void testTime(int choose,int dataSize);

//���Դ���С���ݵ�����ʱ��
void testTime2(int choose);

//�������
void printArray(ElemType *array,int Size);

//������Խ��
void testResult1(void);

//�����Խ��������ļ���
void testResult2(void);

//�����ɵ������������ļ���
void testData(void);

//����size�������
void createArr(ElemType array[],int size);


#endif // SORT_H_INCLUDED
