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
    int tmp = 0;
    char top_op;
    StackType s;
    
    init_stack(&s);
    while (exp[i])
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            while (exp[i] >= '0' && exp[i] <= '9')
            {
                tmp = (tmp * 10) + (exp[i] - '0');
                i++;
            }
            printf("%d ", tmp);
            tmp = 0;
            continue;
        }
        else if (exp[i] == ' ')
        {
            i++;
            continue;
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*'|| exp[i] == '/')
        {
            while (!is_empty(&s) && (prec(exp[i]) <= prec(s_peek(&s))))
                printf("%c ", s_pop(&s));
            s_push(&s, exp[i]);
        }
        else if (exp[i] == '(')
            s_push(&s, exp[i]);
        else if (exp[i] == ')')
        {
            top_op = s_pop(&s);
            while (top_op != '(')
            {
                printf("%c ", top_op);
                top_op = s_pop(&s);
            }
        }
        i++;
    }
    while (!is_empty(&s))
        printf("%c", s_pop(&s));
    free(s.data);
}

int main(void)
{
    char *s = "5 * (10 + 2) / 2";
    infix_to_postfix(s);
    puts("");
    return 0;
}