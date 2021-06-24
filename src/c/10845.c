// 백준 10845번 문제 : 큐
// https://www.acmicpc.net/problem/10845
// 알고리즘 분류 : 자료 구조, 큐

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Data;
typedef struct _node
{
    Data d;
    struct _node* next;
} Node;

typedef struct _queue
{
    Node* front;
    Node* rear;
    int count;
} Queue;

void initQueue(Queue* q)
{
    q->front = q->rear = NULL;
    q->count = 0;
}

int front(const Queue* q)
{
    return !q->front ? -1 : q->front->d;
}

int back(const Queue* q)
{
    return !q->rear ? -1 : q->rear->d;
}

int empty(const Queue* q)
{
    return !q->front && !q->rear ? 1 : 0;
}

int size(const Queue* q)
{
    return q->count;
}

void push(Queue* q, const Data x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->d = x;

    if (empty(q))
        q->front = q->rear = newNode;
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    newNode->next = NULL;
    q->count++;
}

Data pop(Queue* q)
{
    if (!q->front) return -1;

    Node* temp = q->front;
    Data d = temp->d;
    q->front = q->front->next;
    if (size(q) == 1) q->rear = q->front; // for size=1 queue
    free(temp);
    q->count--;

    return d;
}

void freeAll(Queue* q)
{
    while (!empty(q))
        pop(q);
}

int main(void)
{
    Queue q;
    int n, num;
    char cmd[6] = "";

    initQueue(&q);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push"))
        {
            scanf("%d", &num);
            push(&q, num);
        }
        else if (!strcmp(cmd, "front"))
            printf("%d\n", front(&q));
        else if (!strcmp(cmd, "back"))
            printf("%d\n", back(&q));
        else if (!strcmp(cmd, "size"))
            printf("%d\n", size(&q));
        else if (!strcmp(cmd, "empty"))
            printf("%d\n", empty(&q));
        else if (!strcmp(cmd, "pop"))
            printf("%d\n", pop(&q));
        getchar();
    }
    freeAll(&q);
    return 0;
}