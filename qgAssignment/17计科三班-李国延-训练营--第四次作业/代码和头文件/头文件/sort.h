#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define arraySize 10000
#define MAXSIZE 200000

typedef int ElemType;

double result[24];


void printArray(ElemType *array,int Size);

void insertSort(ElemType array[],int n);

void MergeSort(ElemType R[],int low,int high);

void Merge(ElemType *R,int low,int mid,int high);

void Swap(int *a, int *b);

void QSortRecursion(ElemType array[], int n, int begin, int end);

void countSort(int array[], int size) ;

void QSort(int* a,int l,int r);

void Interface(void);

void RadixCountSort(ElemType* dataArray, int n);

void testTime(int choose,int dataSize);

void testTime2(int choose);

void createArr(ElemType array[],int size);

void Testresult();

#endif // SORT_H_INCLUDED
