// 백준 14891번 문제 : 톱니바퀴
// https://www.acmicpc.net/problem/14891
// 알고리즘 분류 : 구현, 시뮬레이션

var gears = new int[5];

// Convert binary number string to integer
for (int i = 1; i <= 4; i++)
    gears[i] = Convert.ToInt32(Console.ReadLine(), 2);
int rotations = int.Parse(Console.ReadLine());
var rotationDirections = new int[5];
while (rotations > 0)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    rotationDirections[conditions[0]] = conditions[1];
    int j = conditions[0] - 1;
    while (j > 0)
    {
        if (rotationDirections[j + 1] != 0 && (((gears[j] & 32) / 32) != ((gears[j + 1] & 2) / 2)))
            rotationDirections[j] = -rotationDirections[j + 1];
        else rotationDirections[j] = 0;
        j--;
    }
    j = conditions[0];
    while (j < 4)
    {
        if (rotationDirections[j] != 0 && (((gears[j] & 32) / 32) != ((gears[j + 1] & 2) / 2)))
            rotationDirections[j + 1] = -rotationDirections[j];
        else rotationDirections[j + 1] = 0;
        j++;
    }

    for (int i = 1; i <= 4; i++)
    {
        switch (rotationDirections[i])
        {
            case 1:
                gears[i] = (gears[i] & 1) * 128 + (gears[i] >> 1);
                break;
            case 0:
                break;
            case -1:
                gears[i] = (gears[i] & 128) / 128 + (gears[i] << 1);
                break;
        }
        gears[i] &= 255;
    }
    rotations--;
}

int result = 0;
for (int i = 1; i <= 4; i++)
    result += ((gears[i] & 128) / 128) * (1 << (i - 1));
Console.WriteLine(result);
