// 백준 1966번 문제 : 프린터 큐
// https://www.acmicpc.net/problem/1966
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 큐

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _node
{
    int priority;
    bool target;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _queue
{
    Node* front;
    Node* rear;
    int count;
} Queue;

void initQueue(Queue* q)
{
    q->count = 0;
    q->front = q->rear = NULL;
}

Node* getNode(const int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->priority = data;
    newNode->next = newNode->prev = NULL;
    newNode->target = false;

    return newNode;
}

bool isEmpty(const Queue* q)
{
    return !q->count ? true : false;
}

bool enqueue(Queue* q, const int data)
{
    Node* n = getNode(data);

    n->next = q->front;
    q->front = n;
    if (isEmpty(q)) q->rear = q->front;
    else q->front->next->prev = q->front;
    q->count++;

    return true;
}

bool moveFront(Queue* q) // Move rear node to front
{
    if (q->count < 2) return false;

    Node* pos = q->rear;

    pos->prev->next = NULL;
    pos->next = q->front;
    q->rear = pos->prev;
    pos->prev = NULL;
    q->front->prev = pos;
    q->front = pos;

    return true;
}

int dequeue(Queue* q)
{
    if (isEmpty(q)) return -1;

    Node* pos = q->rear;
    int result = pos->priority;

    q->rear = q->rear->prev;
    if (!q->rear) q->front = q->rear;
    else q->rear->next = NULL;
    q->count--;
    free(pos);

    return result;
}

Node* rearNode(const Queue* q)
{
    return !isEmpty(q) ? q->rear : NULL;
}

Node* searchNode(const Queue* q, const int order)
{
    if (isEmpty(q)) return NULL;

    Node* pos = q->rear;

    for (int i = 0; i < order; i++)
        pos = pos->prev;
    return pos;
}

int calcOrder(Queue* q, const int initOrder)
{
    Node* target = searchNode(q, initOrder);
    if (target) target->target = true;

    Node* pos = NULL;
    bool tt = false;
    int r;
    int tOrder = 0;

    do
    {
        pos = q->rear;
        r = pos->priority;
        while (r >= pos->priority && pos->prev)
            pos = pos->prev;
        if (r < pos->priority)
        {
            moveFront(q);
            continue;
        }

        tOrder++;
        tt = rearNode(q)->target;
        dequeue(q);
        if (tt) break;
    } while (!isEmpty(q));

    return tOrder;
}

void freeAll(Queue* q)
{
    while (!isEmpty(q))
        dequeue(q);
}

int main(void)
{
    Queue q;
    int t;
    int n, m, temp;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        getchar();
        initQueue(&q);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            enqueue(&q, temp);
        }
        printf("%d\n", calcOrder(&q, m));
        freeAll(&q);
    }

    freeAll(&q);
    return 0;
}