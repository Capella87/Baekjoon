#include <stdio.h>

int main(void)
{
    int month, day;
    int total = 0;

    scanf("%d %d", &month, &day); // 월 일을 입력받는다.

    for (int i = 1; i < month; i++) // 해당 월 전까지 일괄적으로 계산
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) // 한 달이 31일인 경우
            total += 31; 
        else if (i == 4 || i == 6 || i == 9 || i == 11) // 한 달이 30일인 경우
            total += 30;
        else if (i == 2) // 2월의 경우; 여기서는 윤달은 고려하지 않았다.
            total += 28;
    }
    total += day; // 해당 월의 입력된 일 수를 더한다.
    switch (total % 7)
    {
    case 1: // 2007년 1월 1일이 월요일을 기준으로 하였음
        printf("MON\n");
        break;
    case 2:
        printf("TUE\n");
        break;
    case 3:
        printf("WED\n");
        break;
    case 4:
        printf("THU\n");
        break;
    case 5:
        printf("FRI\n");
        break;
    case 6:
        printf("SAT\n");
        break;
    case 0:
        printf("SUN\n");
    }

    return 0;
}