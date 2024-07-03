// 백준 1005번 문제 : ACM Craft
// https://www.acmicpc.net/problem/1005
// 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 위상 정렬, 방향 비순환 그래프

using System.Text;

int t = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

while (t > 0)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    var minimumRequiredTime = new int[conditions[0] + 1];
    Array.Fill(minimumRequiredTime, -1);

    var tempTime = Console.ReadLine().Split();
    var requiredTime = new int[conditions[0] + 1];
    var outbounds = new List<int>[conditions[0] + 1];
    for (int i = 1; i <= conditions[0]; i++)
    {
        outbounds[i] = new List<int>();
        requiredTime[i] = int.Parse(tempTime[i - 1]);
    }
    var inboundCount = new int[conditions[0] + 1];
    for (int i = 0; i < conditions[1]; i++)
    {
        var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
        outbounds[temp[0]].Add(temp[1]);
        inboundCount[temp[1]]++;
    }
    int final = int.Parse(Console.ReadLine());

    sb.Append($"{ACMCraft(final, conditions[0], minimumRequiredTime, requiredTime, outbounds, inboundCount)}\n");
    t--;
}
Console.Write(sb.ToString());

int ACMCraft(int target, int n, int[] minimumRequiredTime, int[] requiredTime, List<int>[] outbounds, int[] inboundCount)
{
    for (int i = 1; i <= n; i++)
    {
        if (inboundCount[i] == 0 && minimumRequiredTime[i] == -1)
            AnalyzeBuildingProcesses(i, -1, minimumRequiredTime, requiredTime, outbounds, inboundCount, target);
    }
    return minimumRequiredTime[target];
}

void AnalyzeBuildingProcesses(int node, int previous, int[] minimumRequiredTime, int[] requiredTime, List<int>[] outbounds, int[] inboundCount, int target)
{
    if (minimumRequiredTime[node] == -1) minimumRequiredTime[node] = 0;

    if (previous != -1)
    {
        minimumRequiredTime[node] = Math.Max(minimumRequiredTime[node], minimumRequiredTime[previous]);
        inboundCount[node]--;
    }

    if (inboundCount[node] > 0) return;
    minimumRequiredTime[node] += requiredTime[node];
    if (node == target) return;

    for (int i = 0; i < outbounds[node].Count; i++)
        AnalyzeBuildingProcesses(outbounds[node][i], node, minimumRequiredTime, requiredTime, outbounds, inboundCount, target);
}
