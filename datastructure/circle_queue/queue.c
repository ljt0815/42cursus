#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef char element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void    error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void    init_queue(QueueType *q)
{
    q->rear = 0;
    q->front = 0;
}

int     is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void    queue_print(QueueType *q)
{
    int i;
    
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q))
    {
        i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");       
}

int     is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void    enqueue(QueueType *q, int item)
{
    if (is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int     dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int     main(void)
{
    QueueType q;
    char ele;
    
    init_queue(&q);
    puts("--데이터 추가 단계--");
    while (!is_full(&q))
    {
        printf("정수를 입력하시오: ");
        scanf("%c", &ele);
        getchar();
        enqueue(&q, ele);
        queue_print(&q);
    }
    puts("큐는 포화상태일껄 \n");
    
    puts("--데이터 삭제 단계--");
    while (!is_empty(&q))
    {
        ele = dequeue(&q);
        printf("꺼내진 정수: %c \n", ele);
        queue_print(&q);
    }
    puts("큐는 비어있을껄");
    return 0;
}
