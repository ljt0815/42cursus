# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# define MAZE_SIZE 6

typedef struct 
{
    short   r;
    short   c;
}           element;

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

element here = { 1,0 }, entry = { 1,0 };

char    maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1'},
    { 'e', '0', '0', '0', '1', '1'},
    { '1', '1', '0', '1', '1', '1'},
    { '1', '1', '0', '1', '1', '1'},
    { '1', '0', '0', '0', '0', 'x'},
    { '1', '1', '1', '1', '1', '1'},
};

void    push_loc(StackType *s, int r, int c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.')
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        s_push(s, tmp);
    }
}

void    maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++)
    {
        for (int c = 0; c < MAZE_SIZE; c++)
            printf("%c", maze[r][c]);
        printf("\n");
    }
}

int main(void)
{
    int r, c;
    StackType s;

    init_stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x')
    {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        if (is_empty(&s))
        {
            printf("실패\n");
            return 0;
        }
        else
            here = s_pop(&s);     
    }
    printf("성공\n");
    return 0;
}