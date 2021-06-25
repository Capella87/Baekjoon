// 백준 10866번 문제 : 덱
// https://www.acmicpc.net/problem/10866
// 알고리즘 분류 : 자료 구조, 덱

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Data;
typedef struct _node
{
    struct _node* next;
    struct _node* prev;
    Data d;
} Node;
typedef struct _deque
{
    Node* head;
    Node* tail;
    int count;
} Deque;

void initDeque(Deque* dq)
{
    dq->count = 0;
    dq->head = dq->tail = NULL;
}

int size(const Deque* dq)
{
    return dq->count;
}

int empty(const Deque* dq)
{
    return !dq->count ? 1 : 0;
}

Data front(const Deque* dq)
{
    return !dq->head ? -1 : dq->head->d;
}

Data back(const Deque* dq)
{
    return !dq->tail ? -1 : dq->tail->d;
}

Node* getNode(const Data d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->d = d;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void push_front(Deque* dq, const Data d)
{
    Node* p = getNode(d);

    if (empty(dq))
        dq->head = dq->tail = p;
    else
    {
        p->next = dq->head;
        dq->head->prev = p;
        dq->head = p;
    }
    dq->count++;
}

void push_back(Deque* dq, const Data d)
{
    Node* p = getNode(d);

    if (empty(dq))
        dq->head = dq->tail = p;
    else
    {
        p->prev = dq->tail;
        dq->tail->next = p;
        dq->tail = p;
    }
    dq->count++;
}

Data pop_front(Deque* dq)
{
    if (empty(dq)) return -1;

    Node* p = dq->head;
    Data item = p->d;
    dq->head = p->next;
    if (!dq->head)
        dq->tail = NULL;
    else
        dq->head->prev = NULL;
    dq->count--;

    free(p);
    return item;
}

Data pop_back(Deque* dq)
{
    if (empty(dq)) return -1;

    Node* p = dq->tail;
    Data item = p->d;
    dq->tail = p->prev;
    if (!dq->tail)
        dq->head = NULL;
    else
        dq->tail->next = NULL;
    dq->count--;

    free(p);
    return item;
}

void freeAll(Deque* dq)
{
    while (!empty(dq))
        pop_back(dq);
}

int main(void)
{
    Deque dq;
    int n, num;
    char cmd[11] = "";

    initDeque(&dq);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_front"))
        {
            scanf("%d", &num);
            push_front(&dq, num);
        }
        if (!strcmp(cmd, "push_back"))
        {
            scanf("%d", &num);
            push_back(&dq, num);
        }
        else if (!strcmp(cmd, "pop_front"))
            printf("%d\n", pop_front(&dq));
        else if (!strcmp(cmd, "pop_back"))
            printf("%d\n", pop_back(&dq));
        else if (!strcmp(cmd, "front"))
            printf("%d\n", front(&dq));
        else if (!strcmp(cmd, "back"))
            printf("%d\n", back(&dq));
        else if (!strcmp(cmd, "size"))
            printf("%d\n", size(&dq));
        else if (!strcmp(cmd, "empty"))
            printf("%d\n", empty(&dq));
        getchar();
    }
    freeAll(&dq);
    return 0;
}