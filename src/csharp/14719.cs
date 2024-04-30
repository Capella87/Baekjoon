// 백준 14719번 문제 : 빗물
// https://www.acmicpc.net/problem/14719
// 알고리즘 분류 : 구현, 시뮬레이션

// conditions[0] = h, conditions[1] = w
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var blocks = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var wallStk = new Stack<int>();
int bottom = 0, bottomIdx = -1, wallHeight, wallIdx, h, w, i = 0, total = 0;

while (i < blocks.Length && blocks[i] < 1) i++;
if (i == blocks.Length)
{
    Console.WriteLine(0);
    return;
}

wallStk.Push(i++);

for (; i < blocks.Length; i++)
{
    wallIdx = wallStk.Peek();
    wallHeight = blocks[wallIdx];

    if (wallHeight == blocks[i])
    {
        wallStk.Pop();
        while (i < blocks.Length - 1 && wallHeight == blocks[i + 1])
            i++;
    }
    else if (wallHeight < blocks[i])
    {
        wallStk.Pop();
        while (wallStk.Count > 0)
        {
            bottomIdx = wallIdx;
            bottom = wallHeight;

            wallIdx = wallStk.Peek();
            wallHeight = blocks[wallIdx];

            h = Math.Min(blocks[i], wallHeight) - bottom;
            w = i - wallIdx - 1;
            total += h * w;

            if (wallHeight <= blocks[i])
                wallStk.Pop();

            if (wallHeight >= blocks[i])
                break;
        }
    }

    wallStk.Push(i);
}

Console.WriteLine(total);
