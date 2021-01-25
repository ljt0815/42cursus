#ifndef STACK_H
# define STACK_H
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
#endif