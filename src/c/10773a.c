// 백준 10773번 문제 : 제로
// https://www.acmicpc.net/problem/10773
// 알고리즘 분류 : 구현, 자료 구조, 문자열, 스택

// 리스트 기반 스택

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;

typedef struct _node
{
    Data value;
    struct _node* next;
} Node;

typedef struct _list
{
    Node* tHead;
    int nodeCount;
} Stack;

bool stackInit(Stack*);
bool push(Stack*, const Data);
Data pop(Stack*);
Data stackTotal(Stack*);

int main(void)
{
    Stack stk;
    int cmd_count;
    Data input;

    stackInit(&stk);
    scanf("%d", &cmd_count);
    getchar();
    for (int i = 0; i < cmd_count; i++)
    {
        scanf("%d", &input);
        getchar();
        if (stk.nodeCount && input == 0)
            pop(&stk);
        else
            push(&stk, input);
    }
    printf("%d\n", stackTotal(&stk));

    return 0;
}

bool stackInit(Stack* target)
{
    target->tHead = NULL;
    target->nodeCount = 0;

    return true;
}
bool push(Stack* target, const Data d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = d;

    newNode->next = target->tHead;
    target->tHead = newNode;
    target->nodeCount++;

    return true;
}

Data pop(Stack* target)
{
    if (!target->tHead) return -1;

    Node* pos = target->tHead;
    Data rt = pos->value;
    target->tHead = pos->next;
    free(pos);
    target->nodeCount--;

    return rt;
}

Data stackTotal(Stack* target)
{
    Data total = 0;

    while (target->tHead)
        total += pop(target);
    
    return total;
}
