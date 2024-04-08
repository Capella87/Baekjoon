// 백준 20055번 문제 : 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055
// 알고리즘 분류 : 구현, 시뮬레이션

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

int dou = conditions[0] * 2;
var beltDurabilityStatus = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

int brokenSlotCount = 0;
int movedRobotCount = 0;
int steps = 0, idx, next;
var beltRobotStatus = new bool[dou];
int startIdx = 0, endIdx = conditions[0] - 1;

while (brokenSlotCount < conditions[1])
{
    // Move the conveyor belt first
    startIdx = (dou + startIdx - 1) % dou;
    endIdx = (dou + endIdx - 1) % dou;
    ++steps;

    if (beltRobotStatus[endIdx])
    {
        beltRobotStatus[endIdx] = false;
        movedRobotCount++;
    }

    for (int i = 1; i < conditions[0]; i++)
    {
        idx = (dou + endIdx - i) % dou;
        next = (dou + idx + 1) % dou;

        if (!beltRobotStatus[idx]) continue;

        // Move it forward if the next slot is vacant and has durability
        if (beltDurabilityStatus[next] > 0 && !beltRobotStatus[next])
        {
            if (--beltDurabilityStatus[next] == 0)
            {
                brokenSlotCount++;
            }

            if (next != endIdx)
            {
                beltRobotStatus[next] = true;
                movedRobotCount++;
            }
            beltRobotStatus[idx] = false;
        }
    }

    if (beltDurabilityStatus[startIdx] > 0 && !beltRobotStatus[startIdx])
    {
        beltRobotStatus[startIdx] = true;
        if (--beltDurabilityStatus[startIdx] == 0)
        {
            brokenSlotCount++;
        }
    }
}

Console.WriteLine(steps);
