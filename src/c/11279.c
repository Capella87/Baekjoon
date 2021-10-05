// 백준 11279번 문제 : 최대 힙
// https://www.acmicpc.net/problem/11279
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

bool initHeap(Heap* h, const int m)
{
    h->arr = (Data*)malloc(sizeof(Data) * (m + 1));
    h->max = m;
    h->size = 0;
    return true;
}

bool enqueue(Heap* h, const Data d)
{
    if (h->size == h->max) return false;
    int idx = ++h->size;
    
    while (idx != 1 && h->arr[idx / 2] < d)
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

    Data rt = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int idx = 1;
    int childIdx;

    while(1)
    {
        childIdx = idx * 2;
        if (h->size >= childIdx + 1 && h->arr[childIdx] < h->arr[childIdx + 1])
            childIdx++;
        if (h->size < childIdx || h->arr[idx] >= h->arr[childIdx]) break;
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