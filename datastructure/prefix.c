#include "stack.h"

int prec(char op)
{
    switch (op)
    {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[])
{
    int i = 0;
    char top_op;
    StackType s;
    
    init_stack(&s);
    while (exp[i])
    {
        ...;
    }

}