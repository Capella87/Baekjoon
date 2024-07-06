// 백준 2056번 문제 : 작업
// https://www.acmicpc.net/problem/2056
// 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 위상 정렬, 방향 비순환 그래프

int n = int.Parse(Console.ReadLine()!);
var outbounds = new List<int>[n + 1];
var inboundCount = new int[n + 1];
var outboundCount = new int[n + 1];
var cachedTime = new int[n + 1];
var requiredTime = new int[n + 1];
int result = 0;
Array.Fill(cachedTime, -1);

for (int i = 1; i <= n; i++)
    outbounds[i] = new List<int>();

for (int i = 1; i <= n; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine()!.Split(), int.Parse);
    requiredTime[i] = temp[0];
    for (int j = 0; j < temp[1]; j++)
    {
        outbounds[temp[2 + j]].Add(i);
        inboundCount[i]++;
        outboundCount[temp[2 + j]]++;
    }
}

for (int i = 1; i <= n; i++)
{
    if (inboundCount[i] == 0 && cachedTime[i] == -1)
        result = Math.Max(result, ScheduleTaskTime(i, -1));
}
Console.WriteLine(result);

int ScheduleTaskTime(int task, int previous)
{
    if (cachedTime[task] == -1)
        cachedTime[task] = requiredTime[task];

    if (previous != -1) inboundCount[task]--;
    if (outboundCount[task] > 0)
    {
        cachedTime[task] = 0;
        for (int i = 0; i < outbounds[task].Count; i++)
        {
            cachedTime[task] = Math.Max(cachedTime[task], ScheduleTaskTime(outbounds[task][i], task));
            outboundCount[task]--;
        }
        cachedTime[task] += requiredTime[task];
    }
    return cachedTime[task];
}
