#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE] = { 0 };
int top = 0;

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];

    return '\0'; /* prevents compiler warning due to stack_underflow() call */
}

int main(void)
{
    char a[50] = { '\0' };
    int i = 0;
    printf("Enter parentheses and/or braces:");
    make_empty();
    while (1) {
        a[i] = getchar();
        if (a[i] == ' ')
            continue;
        if (a[i] == '\n') {
            a[i] = '\0';
            break;
        }
        i++;
    }
    i = 0;
    while (i <= 50) {
        push(a[i]);
        if (top >= 2) {
            if ((contents[top - 2] == '(' && contents[top - 1] == ')') || (contents[top - 2] == '{' && contents[top - 1] == '}')) {
                contents[top - 2] = 0, contents[top - 1] = 0;
                top -= 2;
            }
        }
        i++;
    }
    if (contents[0] == '\0')
        printf("Parentheses/braces are nested properly");
    else
        printf("Parentheses/braces are NOT nested properly");
    return 0;
}
