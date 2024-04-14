// 백준 14503번 문제 : 로봇 청소기
// https://www.acmicpc.net/problem/14503
// 알고리즘 분류 : 구현, 시뮬레이션

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var cleaner = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var map = new List<int[]>();

for (int i = 0; i < conditions[0]; i++)
{
    map.Add(Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse));
}

int cleanedTileCount = 0;
int currentDir = cleaner[2];
int x = cleaner[0], y = cleaner[1];
int[] xDirs = { -1, 0, 1, 0 };
int[] yDirs = { 0, 1, 0, -1 };
bool hasDirtyTile = false;

while (true)
{
    if (map[x][y] == 0)
    {
        map[x][y] = -1;
        cleanedTileCount++;
    }

    hasDirtyTile = false;
    // Check nearby 4 tiles
    for (int i = 0; i < 4; i++)
    {
        // Check whether nearby tile is dirty
        if (map[x + xDirs[i]][y + yDirs[i]] == 0)
        {
            hasDirtyTile = true;
            break;
        }
    }

    if (hasDirtyTile)
    {
        // Check availability to go back while keeping direction.
        currentDir = (4 + currentDir - 1) % 4;
        if (map[x + xDirs[currentDir]][y + yDirs[currentDir]] == 0)
        {
            x += xDirs[currentDir];
            y += yDirs[currentDir];
        }
        continue;
    }

    int reversedDir = (currentDir + 2) % 4;
    // Exit the loop if there's wall behind
    if (map[x + xDirs[reversedDir]][y + yDirs[reversedDir]] == 1)
    {
        break;
    }

    x += xDirs[reversedDir];
    y += yDirs[reversedDir];
}

Console.WriteLine(cleanedTileCount);
