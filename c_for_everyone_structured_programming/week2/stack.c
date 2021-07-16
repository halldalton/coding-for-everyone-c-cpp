/*
  Stacks
  Dalton Hall
  July 16th, 2021
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100
#define EMPTY   -1
#define FULL    (MAX_LEN - 1)

typedef struct stack
{
    char s[MAX_LEN];
    int top;
} stack;

void reset(stack *stk)
{
    stk -> top = EMPTY;
}

void push(char c, stack *stk)
{
    stk -> top++;
    stk -> s[stk -> top] = c;
}

char pop(stack *stk)
{
    return (stk -> s[stk -> top--]);
}

char top(const stack *stk)
{
    return (stk -> s[stk -> top]);
}

int is_empty(const stack *stk)
{
    return (stk -> top == EMPTY);
}

int is_full(const stack *stk)
{
    return (stk -> top == FULL);
}

int main(void)
{
    stack stack_of_char;
    char *str = "i am otto am i";
    char str_reverse[20];
    int i = 0;

    reset(&stack_of_char);
    printf("\nOriginal is: %s\n", str);

    while (str[i] != '\0')
    {
        push(str[i++], &stack_of_char);
    }

    i = 0;

    while(!is_empty(&stack_of_char) && (i < 20))
    {
        str_reverse[i++] = pop(&stack_of_char);
    }

    printf("Reverse is : %s\n\n", str_reverse);

    return 0;
}