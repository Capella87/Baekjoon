// 백준 4256번 문제 : 트리
// https://www.acmicpc.net/problem/9935
// 알고리즘 분류 : 트리, 분할 정복, 재귀

// The website compiler's inputs may have unnecessary spaces, so ArgumentException is thrown when using Console.ReadLine().Split()
// To avoid this, I had to use Console.ReadLine().Trim().Split() instead.
// Source: https://www.acmicpc.net/board/view/128410

using System.Text;

int t = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

for (int i = 0; i < t; i++)
{
    int n = int.Parse(Console.ReadLine());
    var preorder = Array.ConvertAll<string, int>(Console.ReadLine().Trim().Split(), int.Parse);
    var inorder = Array.ConvertAll<string, int>(Console.ReadLine().Trim().Split(), int.Parse);

    GetTreePostorderTraversal(preorder, inorder, n);
}

Console.WriteLine(sb.ToString());

void GetTreePostorderTraversal(int[] preorder, int[] inorder, int n)
{
    var postorder = new int[n];
    int postorderStatusIdx = 0;

    GetPostorderRecurse(preorder, inorder, postorder,
        0, n - 1,
        0, n - 1,
        n - 1);

    foreach (var i in postorder)
        sb.Append($"{i} ");
    sb.AppendLine();
}

int FindNode(int[] arr, int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == target) return i;
    }

    return -1;
}

int GetPostorderRecurse(int[] preorder, int[] inorder, int[] postorder,
    int preorderStartIdx,  int preorderEndIdx,
    int inorderStartIdx, int inorderEndIdx, int postorderIdx)
{
    // Put the rootNode into the preorder
    int root = preorder[preorderStartIdx];
    postorder[postorderIdx--] = root;

    if (inorderStartIdx == inorderEndIdx)
        return postorderIdx;

    // Find Node from Idx
    int inorderRootIdx = FindNode(inorder, root, inorderStartIdx, inorderEndIdx);

    int leftSize = inorderRootIdx - inorderStartIdx;
    int rightSize = inorderEndIdx - inorderRootIdx;

    // Right descendants
    if (rightSize > 0)
        postorderIdx = GetPostorderRecurse(preorder, inorder, postorder,
            preorderEndIdx - rightSize + 1, preorderEndIdx,
            inorderRootIdx + 1, inorderRootIdx + rightSize,
            postorderIdx);

    // Left descendants
    if (leftSize > 0)
        postorderIdx = GetPostorderRecurse(preorder, inorder, postorder,
            preorderStartIdx + 1, preorderStartIdx + leftSize,
            inorderRootIdx - leftSize, inorderRootIdx - 1, postorderIdx);

    return postorderIdx;
}
