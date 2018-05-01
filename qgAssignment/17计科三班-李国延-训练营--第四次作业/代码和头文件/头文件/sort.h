#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef int ElemType;

double result[24];


//插入排序
void insertSort(ElemType array[],int n);

//归并排序
void MergeSort(ElemType R[],int low,int high);

//用递归实现的快速排序
void QSortRecursion(ElemType array[], int n, int begin, int end);

//用迭代实现的快速排序
void QSort(int* a,int l,int r);

//计数排序
void countSort(int array[], int size) ;

//基数计数排序
void RadixCountSort(ElemType* dataArray, int n);

//交互画面
void Interface(void);

//测试大数据的排序时间
void testTime(int choose,int dataSize);

//测试大量小数据的排序时间
void testTime2(int choose);

//输出数组
void printArray(ElemType *array,int Size);

//输出测试结果
void testResult1(void);

//将测试结果输出到文件中
void testResult2(void);

//将生成的随机数输出到文件中
void testData(void);

//创建size个随机数
void createArr(ElemType array[],int size);


#endif // SORT_H_INCLUDED
