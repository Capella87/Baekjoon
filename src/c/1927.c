// 백준 1927번 문제 : 최소 힙
// https://www.acmicpc.net/problem/1927
// 알고리즘 분류 : 자료 구조, 우선순위 큐

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;
typedef struct _heap
{
    Data* arr;
    int max;
    int size;
} Heap;

bool initHeap(Heap* h, const int max)
{
    h->arr = (Data*)malloc(sizeof(Data) * (max + 1));
    h->max = max;
    h->size = 0;
    return true;
}

bool enqueue(Heap* h, const Data d)
{
    if (h->size == h->max) return false;
    int idx = ++h->size;

    while (idx != 1 && h->arr[idx / 2] > d)
    {
        h->arr[idx] = h->arr[idx / 2];
        idx = idx / 2;
    }
    h->arr[idx] = d;
    return true;
}

void swap(Data* t1, Data* t2)
{
    Data temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

Data dequeue(Heap* h)
{
    if (!h->size) return 0;
    int rt = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int idx = 1, childIdx;

    while (1)
    {
        childIdx = idx * 2;
        if (childIdx < h->size && h->arr[childIdx] > h->arr[childIdx + 1])
            childIdx++;
        if (childIdx > h->size || h->arr[childIdx] >= h->arr[idx]) break;
        swap(&h->arr[childIdx], &h->arr[idx]);
        idx = childIdx;
    }
    return rt;
}

int main(void)
{
    Heap h;
    int n, c;

    scanf("%d", &n);
    initHeap(&h, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c);
        if (!c) printf("%d\n", dequeue(&h));
        else enqueue(&h, c);
    }
    free(h.arr);
    return 0;
}