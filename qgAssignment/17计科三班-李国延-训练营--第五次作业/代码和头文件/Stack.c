

int number[10];               //定义一个栈，分别存放数字
int nTop = 0;                 //栈顶


//入栈
void numPUSH(int num)
{
    number[nTop] = num;
     nTop++;
}


//出栈
void numPOP(int *num)
{
     nTop--;
    *num = number[nTop];
}

