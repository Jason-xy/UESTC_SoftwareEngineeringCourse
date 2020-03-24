#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

int compute_reverse_polish_notation(char *str)
{
    Stack S;
    init_Stack(Stack &S);
    char* p=str;
    int x,num1,num2;
    for(;*p!='\0';p++)
    {
        if(*p==' ')continue;
        if(*p>='0'&&*p<='9') 
        {
            x=(int)(*p-'0');
            push(Stack* S, ElemType x);
        }
        else 
        {
            pop(Stack* S, ElemType *num1);
            pop(Stack* S, ElemType *num2);
            switch(*p)
            {
                case '+':
                {
                    num1 += num2;
                    break;
                }
                case '-':
                {
                    num1 -= num2;
                    break;
                }
                    case '*':
                {
                    num1 *= num2;
                    break;
                }
                    case '/':
                {
                    num1 /= num2;
                    break;
                }
                    case '%':
                {
                    num1 %= num2;
                    break;
                }
            }
            push(Stack* S, ElemType num1);
        }
    }
    pop(Stack* S, ElemType *num1);
    return num1;
}