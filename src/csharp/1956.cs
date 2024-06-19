// 백준 1956번 문제 : 운동
// https://www.acmicpc.net/problem/1956
// 알고리즘 분류 : 그래프 이론, 최단 경로, 플로이드-워셜

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
// міська мережа (City network)
var miskaMerezha = new int[conditions[0] + 1, conditions[0] + 1];

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    miskaMerezha[temp[0], temp[1]] = temp[2];
}

for (int k = 1; k <= conditions[0]; k++)
{
    for (int i = 1; i <= conditions[0]; i++)
    {
        if (k == i) continue;
        for (int j = 1; j <= conditions[0]; j++)
        {
            if (k == j) continue;
            if (miskaMerezha[i, k] != 0 && miskaMerezha[k, j] != 0)
            {
                int lenTotal = miskaMerezha[i, k] + miskaMerezha[k, j];
                if (miskaMerezha[i, j] == 0 || lenTotal < miskaMerezha[i, j])
                    miskaMerezha[i, j] = lenTotal;
            }
        }
    }
}

int minResult = int.MaxValue;
for (int i = 1; i <= conditions[0]; i++)
{
    if (miskaMerezha[i, i] == 0) continue;
    minResult = Math.Min(minResult, miskaMerezha[i, i]);
}
Console.WriteLine(minResult == int.MaxValue ? -1 : minResult);
