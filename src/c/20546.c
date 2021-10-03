// 백준 20546번 문제 : 🐜 기적의 매매법 🐜
// https://www.acmicpc.net/problem/20546
// 알고리즘 분류 : 구현

#include <stdio.h>

int main(void)
{
    int money, price, prev, upDownCount = 0;
    int junhyeonStock = 0, seongminStock = 0;

    scanf("%d", &money);
    int junhyeonRemain = money, seongminRemain = money;
    scanf("%d", &price);
    junhyeonStock += money / price;
    junhyeonRemain = money % price;
    for (int i = 1; i < 14; i++)
    {
        prev = price;
        scanf("%d", &price);
        int diff = price - prev;
        if (!junhyeonStock && junhyeonRemain >= price)
        {
            junhyeonStock += junhyeonRemain / price;
            junhyeonRemain %= price;
        }
        if (diff > 0 && upDownCount >= 0)
            upDownCount++;
        else if (diff > 0 && upDownCount < 0)
            upDownCount = 1;
        else if (diff == 0)
            upDownCount = 0;
        else if (diff < 0 && upDownCount <= 0)
            upDownCount--;
        else if (diff < 0 && upDownCount > 0)
            upDownCount = -1;
        if (upDownCount == 3 || i == 13)
        {
            seongminRemain += price * seongminStock;
            seongminStock = 0;
            upDownCount = 0;
        }
        else if (upDownCount <= -3)
        {
            seongminStock += seongminRemain / price;
            seongminRemain %= price;
        }
    }
    junhyeonRemain += junhyeonStock * price;
    if (junhyeonRemain > seongminRemain) puts("BNP");
    else if (junhyeonRemain == seongminRemain) puts("SAMESAME");
    else puts("TIMING");
    return 0;
}