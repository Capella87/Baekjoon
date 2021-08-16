// 백준 1991번 문제 : 트리 순회
// https://www.acmicpc.net/problem/1991
// 알고리즘 분류 : 트리, 재귀

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char Data;

typedef struct _node
{
    Data data;
    struct _node* left;
    struct _node* right;
} Node;

typedef struct _tree
{
    Node* root;
    Node** nodeArr;
} Tree;

bool initTree(Tree* tr, const int n)
{
    tr->root = NULL;
    tr->nodeArr = (Node**)malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; i++)
        tr->nodeArr[i] = NULL;
    return true;
}

Node* getNode(const Data* d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = *d;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void assembleTree(Tree* tr, const char parent, const char left, const char right)
{
    Node* p;

    if (!tr->nodeArr[parent - 'A'])
    {
        p = getNode(&parent);
        tr->nodeArr[parent - 'A'] = p;
        if (!tr->root) tr->root = p;
    }
    else p = tr->nodeArr[parent - 'A'];
    Node* l = NULL, * r = NULL;
    if (left != '.')
    {
        l = getNode(&left);
        p->left = l;
        tr->nodeArr[left - 'A'] = l;
    }
    if (right != '.')
    {
        r = getNode(&right);
        p->right = r;
        tr->nodeArr[right - 'A'] = r;
    }
}

void preorderTraverse(Node* n)
{
    printf("%c", n->data);
    if (n->left)
        preorderTraverse(n->left);
    if (n->right)
        preorderTraverse(n->right);
}

void inorderTraverse(Node* n)
{
    if (n->left)
        inorderTraverse(n->left);
    printf("%c", n->data);
    if (n->right)
        inorderTraverse(n->right);
}

void postorderTraverse(Node* n)
{
    if (n->left)
        postorderTraverse(n->left);
    if (n->right)
        postorderTraverse(n->right);
    printf("%c", n->data);
}

void removeAll(Node* n)
{
    if (n->left)
        removeAll(n->left);
    if (n->right)
        removeAll(n->right);
    free(n);
}

int main(void)
{
    int n;
    char parent, left, right;
    Tree tree;

    scanf("%d", &n);
    initTree(&tree, n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c %c", &parent, &left, &right);
        assembleTree(&tree, parent, left, right);
    }
    preorderTraverse(tree.root);
    putchar('\n');
    inorderTraverse(tree.root);
    putchar('\n');
    postorderTraverse(tree.root);
    putchar('\n');

    removeAll(tree.root);
    free(tree.nodeArr);
    return 0;
}