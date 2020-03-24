#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

int compute_reverse_polish_notation(char *str)
{
    Stack S;
    init_stack(&S);
    char* p=str;
    int x,num1,num2;
    for(;*p!='\0';p++)
    {
        x=0;
        if(*p>='0'&&*p<='9')
        {
            while(*p!=' ') 
            {
                x=10*x+(*p-'0');
                p++;
            }
            push(&S, x);
            p++;
        }
        else 
        {
            pop(&S, &num1);
            pop(&S, &num2);
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
            push(&S, num1);
        }
    }
    pop(&S, &num1);
    return num1;
}