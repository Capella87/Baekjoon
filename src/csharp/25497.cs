// 백준 25497번 문제 : 기술 연계마스터 임스
// https://www.acmicpc.net/problem/25497
// 알고리즘 분류 : 구현, 자료 구조, 스택

int n = int.Parse(Console.ReadLine()!);
var skills = Console.ReadLine()!;
var sk = new int[n];
var lr = new int[n];
int skIdx = -1, lrIdx = -1;
int triggered = 0;

for (int i = 0; i < n; i++)
{
    switch (skills[i])
    {
        case 'L':
            lr[++lrIdx] = i;
            break;
        case 'S':
            sk[++skIdx] = i;
            break;
        case 'K':
        // You must exit the loop if violation occurs
            if (skIdx < 0) goto term;
            else
            {
                triggered++;
                skIdx--;
            }
            break;
        case 'R':
            if (lrIdx < 0) goto term;
            else
            {
                lrIdx--;
                triggered++;
            }
            break;
        default:
            triggered++;
            break;
    }
}

term:
Console.WriteLine(triggered);
