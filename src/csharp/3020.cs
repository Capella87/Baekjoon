// 백준 3020번 문제 : 개똥벌레
// https://www.acmicpc.net/problem/3020
// 알고리즘 분류 : 이분 탐색, 누적 합

var conds = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
int iter = conds[0] / 2;
// 석순, 종유석
var stalagmites = new int[conds[1] + 1];
var stalactites = new int[conds[1] + 1];

for (int i = 0; i < iter; i++)
{
    // The height of stalagmite can also be regarded as a section number.
    // e.g. stalagmite 1's height = 1 => The 1st section between height 0 and 1.
    stalagmites[int.Parse(Console.ReadLine())]++;

    // The result of subtracting number of a height of stalactite from the cave's height is the beginning point of blocked section, not meaning the section number itself,
    // so adding 1 is needed.
    // e.g. If stalactite height = 5 and the cave's height is 7, section 3 (height 2-3) is the first blocked section.
    stalactites[conds[1] + 1 - int.Parse(Console.ReadLine())]++;
}

int minValue = int.MaxValue;
int count = 1, sum;

for (int i = 2; i <= conds[1]; i++)
    stalagmites[^i] += stalagmites[^(i - 1)];
for (int i = 1; i <= conds[1]; i++)
{
    stalactites[i] += stalactites[i - 1];
    sum = stalagmites[i] + stalactites[i];
    if (minValue > sum)
    {
        minValue = sum;
        count = 1;
    }
    else if (minValue == sum)
        count++;
}

Console.WriteLine($"{minValue} {count}");
