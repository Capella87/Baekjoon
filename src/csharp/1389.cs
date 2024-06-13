// 백준 1389번 문제 : 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 플로이드-와샬

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var friendNetwork = new int[conditions[0] + 1, conditions[0] + 1];

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    friendNetwork[temp[0], temp[1]] = 1;
    friendNetwork[temp[1], temp[0]] = 1;
}

for (int k = 1; k <= conditions[0]; k++)
{
    for (int i = 1; i <= conditions[0]; i++)
    {
        if (k == i) continue;
        for (int j = 1; j <= conditions[0]; j++)
        {
            if (k == j || i == j) continue;
            
            if (friendNetwork[i, k] != 0 && friendNetwork[k, j] != 0)
            {
                int total = friendNetwork[i, k] + friendNetwork[k, j];
                if (friendNetwork[i, j] == 0 || total < friendNetwork[i, j])
                {
                    friendNetwork[i, j] = friendNetwork[j, i] = total;
                }
            }
        }
    }
}

int minKevinBacon = 100_000_000, person = 0;

for (int i = 1; i <= conditions[0]; i++)
{
    int total = 0;
    for (int j = 1; j <= conditions[0]; j++)
        total += friendNetwork[i, j];

    if (total < minKevinBacon)
    {
        person = i;
        minKevinBacon = total;
    }
}

Console.WriteLine(person);
