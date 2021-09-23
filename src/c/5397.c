// 백준 5397번 문제 : 키로거
// https://www.acmicpc.net/problem/5397
// 알고리즘 분류 : 자료 구조, 스택, 연결 리스트

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Data;
typedef struct _node
{
    Data d;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _stack
{
    Node* head;
    Node* tail;
    Node* cursor;
    int count;
} Stack;

Node* getNode(const Data d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->d = d;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

bool initStack(Stack* stk)
{
    stk->head = getNode(-1);
    stk->tail = getNode(-1);
    stk->head->next = stk->tail;
    stk->tail->prev = stk->head;
    stk->head->prev = stk->tail->next = NULL;
    stk->cursor = stk->tail;
    stk->count = 0;
    return true;
}

bool push(Stack* stk, const Data d)
{
    Node* newNode = getNode(d);
    newNode->next = stk->cursor;
    newNode->prev = stk->cursor->prev;
    stk->cursor->prev->next = newNode;
    stk->cursor->prev = newNode;
    stk->count++;
    return true;
}

bool removeChar(Stack* stk)
{
    if (!stk->count || stk->cursor->prev == stk->head) return false;
    Node* temp = stk->cursor->prev;
    temp->prev->next = stk->cursor;
    stk->cursor->prev = temp->prev;
    free(temp);
    stk->count--;
    return true;
}

void moveCursor(Stack* stk, Data cmd)
{
    switch (cmd)
    {
    case '<':
        if (stk->cursor->prev == stk->head) break;
        stk->cursor = stk->cursor->prev;
        break;
    case '>':
        if (stk->cursor == stk->tail) break;
        stk->cursor = stk->cursor->next;
        break;
    }
}

int size(const Stack* stk)
{
    return stk->count;
}

bool freeStack(Stack* stk)
{
    stk->cursor = stk->tail;
    while (removeChar(stk));
    free(stk->tail);
    free(stk->head);
    stk->count = 0;
    return true;
}

bool readChar(Stack* stk)
{
    if (!size(stk)) return false;
    Node* c = stk->head->next;
    while (c != stk->tail)
    {
        printf("%c", c->d);
        c = c->next;
    }
    putchar('\n');
    return true;
}

int main(void)
{
    char input[1000010] = "";
    int n;

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        Stack stk;
        initStack(&stk);
        scanf("%[^\n]", input);
        getchar();
        size_t len = strlen(input);
        for (size_t j = 0; j < len; j++)
        {
            if (strchr("<>", input[j])) moveCursor(&stk, input[j]);
            else if (input[j] == '-') removeChar(&stk);
            else push(&stk, input[j]);
        }
        readChar(&stk);
        freeStack(&stk);
    }
    return 0;
}