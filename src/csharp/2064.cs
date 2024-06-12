// 백준 2064번 문제 : IP 주소
// https://www.acmicpc.net/problem/2064
// 알고리즘 분류 : 구현, 비트마스킹

using System.Text;

int n = int.Parse(Console.ReadLine()) - 1;
uint andTable = 0, orTable = 0, mask = 0, xorResult, address;
var sb = new StringBuilder();

var temp = Array.ConvertAll<string, ushort>(Console.ReadLine().Split('.'), ushort.Parse);
for (int i = 0; i < 4; i++)
{
    andTable <<= 8;
    orTable <<= 8;
    andTable |= temp[i];
    orTable |= temp[i];
}

while (n > 0)
{
    temp = Array.ConvertAll<string, ushort>(Console.ReadLine().Split('.'), ushort.Parse);
    AddressOperation();
    n--;
}

xorResult = andTable ^ orTable;
while (xorResult > 0)
{
    mask = (mask << 1) | 1;
    xorResult >>= 1;
}
mask = ~mask;
address = andTable & mask;
ConvertNumToAddress(address);
ConvertNumToAddress(mask);
Console.Write(sb.ToString());

void AddressOperation()
{
    uint num = 0;
    for (int i = 0; i < 4; i++)
    {
        num <<= 8;
        num |= temp[i];
    }
    andTable &= num;
    orTable |= num;
}

void ConvertNumToAddress(uint target)
{
    uint filter = 255;
    filter <<= 24;

    for (int i = 0; i < 4; i++)
    {
        sb.Append($"{(target & filter) >> 24}.");
        target <<= 8;
    }
    sb[sb.Length - 1] = '\n';
}
