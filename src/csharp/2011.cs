// 백준 2011번 문제 : 암호코드
// https://www.acmicpc.net/problem/2011
// 알고리즘 분류 : 다이나믹 프로그래밍

var cipher = Console.ReadLine();
char prevIndv = (char)0;
bool isLigatureAllowed = false, isInvalid = false, isLigatureOnly = false, isOverflow = false;
int prevIndvCount = 0, indvCount = 1;
int prevLigaCount = 0, ligaCount = 0;

for (int i = 0; i < cipher!.Length; i++)
{
    prevIndvCount = indvCount;
    prevLigaCount = ligaCount;
    isLigatureOnly = false;

    if (prevIndv == (char)0 || prevIndv == '0')
    {
        char r = ConvertCipherNumToChar(prevIndv, cipher[i], out isOverflow);
        if (r == (char)0)
        {
            isInvalid = true;
            break;
        }

        isLigatureAllowed = false;
    }
    else
    {
        if (cipher[i] == '0')
        {
            isLigatureAllowed = true;
            isLigatureOnly = true;
        }
        char r = ConvertCipherNumToChar(prevIndv, cipher[i], out isOverflow);

        if (r == (char)0)
        {
            isInvalid = true;
            break;
        }
        
        if (isOverflow)
        {
            isLigatureAllowed = false;
            isLigatureOnly = false;
        }
        else isLigatureAllowed = true;
    }

    if (isLigatureOnly && isLigatureAllowed)
    {
        indvCount = 0;
        ligaCount = prevIndvCount;
    }
    else if (isLigatureAllowed)
    {
        indvCount = (prevLigaCount + prevIndvCount) % 1000000;
        ligaCount = prevIndvCount;
    }
    else
    {
        indvCount = (prevIndvCount + prevLigaCount) % 1000000;
        ligaCount = 0;
    }

    prevIndv = cipher[i];
}

Console.WriteLine(isInvalid ? 0 : (indvCount + ligaCount) % 1000000);

char ConvertCipherNumToChar(char prev, char current, out bool isBeyondZ)
{
    isBeyondZ = false;

    if (prev == (char)0)
    {
        return current == '0' ? (char)0 : (char)(current - '0' + 'A' - 1);
    }

    int chNum = ((prev - '0') * 10) + (current - '0');

    if (chNum == 0)
    {
        return (char)0;
    }
    else if (chNum > 26)
    {
        isBeyondZ = true;
        return (char)(chNum % 10) == (char)0 ? (char)0 : (char)((char)(chNum % 10) - 1 + 'A');
    }

    return (char)((char)chNum - 1 + 'A');
}
