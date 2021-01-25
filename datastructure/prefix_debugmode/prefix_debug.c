# include <stdio.h>
# include <stdlib.h>
# include <string.h> 

typedef int element;
typedef struct {
    element *data;
    int     capacity;
    int     top;
}           StackType;

void        init_stack(StackType *s);
int         is_full(StackType *s);
int         is_empty(StackType *s);
void        s_delete(StackType *s);
void        s_push(StackType *s, element item);
element     s_pop(StackType *s);
element     s_peek(StackType *s);
void    init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int     is_full(StackType *s)
{
    return (s->top == (s->capacity - 1));
}

int     is_empty(StackType *s)
{
    return (s->top == -1);
}

// 스택 삭제 함수
void    s_delete(StackType *s)
{
    free(s);
}

// 푸쉬푸쉬베이베
void    s_push(StackType *s, element item)
{
    element *tmp;

    if (is_full(s))
    {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element s_peek(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)];
}

// 삭제함수
element s_pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

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