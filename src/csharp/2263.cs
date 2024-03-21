// 백준 2263번 문제 : 트리의 순회
// https://www.acmicpc.net/problem/2263
// 알고리즘 분류 : 트리, 분할 정복, 재귀

using System.Text;

int n = int.Parse(Console.ReadLine());

var inorder = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var postorder = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var preorder = new int[n];
int preorderStatusIdx = 0;

var sb = new StringBuilder();

GetTreePreorderTraversal();

Console.WriteLine(sb.ToString());

void GetTreePreorderTraversal()
{
    GetPreorderRecurse(0, n - 1, 0, n - 1);

    foreach (var i in preorder)
        sb.Append($"{i} ");
}

int FindNode(int[] arr, int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == target) return i;
    }

    return -1;
}

void GetPreorderRecurse(int inorderStartIdx,  int inorderEndIdx,
    int postorderStartIdx, int postorderEndIdx)
{
    // Put the rootNode into the preorder
    int root = postorder[postorderEndIdx];
    preorder[preorderStatusIdx++] = root;

    if (inorderStartIdx == inorderEndIdx)
        return;

    // Find Node from Idx
    int inorderRootIdx = FindNode(inorder, root, inorderStartIdx, inorderEndIdx);

    int leftSize = inorderRootIdx - inorderStartIdx;
    int rightSize = inorderEndIdx - inorderRootIdx;

    // Left descendants
    if (leftSize > 0)
        GetPreorderRecurse(inorderStartIdx, inorderStartIdx + leftSize - 1, postorderStartIdx, postorderStartIdx + leftSize - 1);

    // Right descendants
    if (rightSize > 0)
        GetPreorderRecurse(inorderRootIdx + 1, inorderRootIdx + rightSize, postorderEndIdx - rightSize, postorderEndIdx - 1);
}
