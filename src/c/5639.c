// 백준 5639번 문제 : 이진 검색 트리
// https://www.acmicpc.net/problem/1018
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 트리, 재귀

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;
typedef struct _node
{
    Data data;
    struct _node* left;
    struct _node* right;
} Node;

Node* getNode(const Data d)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, const Data d)
{
    if (!root)
    {
        root = getNode(d);
        return root;
    }
    if(root->data > d) root->left = insert(root->left, d);
    else if (root->data < d) root->right = insert(root->right, d);
    return root;
}

bool postOrderTrav(Node* root)
{
    if (!root) return false;
    
    if (root->left) postOrderTrav(root->left);
    if (root->right) postOrderTrav(root->right);
    printf("%d\n", root->data);
    return true;
}

bool freeAll(Node* root)
{
    if (!root) return false;
    if (root->left) freeAll(root->left);
    if (root->right) freeAll(root->right);
    free(root);
    return true;
}

int main(void)
{
    int n;
    Node* tree = NULL;

    while (scanf("%d", &n) == 1)
        tree = insert(tree, n);
    postOrderTrav(tree);
    freeAll(tree);  
    return 0;
}