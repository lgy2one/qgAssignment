

int number[10];               //����һ��ջ���ֱ�������
int nTop = 0;                 //ջ��


//��ջ
void numPUSH(int num)
{
    number[nTop] = num;
     nTop++;
}


//��ջ
void numPOP(int *num)
{
     nTop--;
    *num = number[nTop];
}

