#include "stack.h"

typedef int element;
typedef struct {
    element *data;
    int     capacity;
    int     top;
}   StackType;

// 스택 생성 함수
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

int     main(void)
{
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    free(s.data);
    return 0;
}