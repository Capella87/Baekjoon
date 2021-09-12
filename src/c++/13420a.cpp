// 백준 13420번 문제 : 사칙연산
// https://www.acmicpc.net/problem/13420
// 알고리즘 분류 : 수학, 문자열, 사칙연산

// Solved problem by string

#include <iostream>
#include <string>
using namespace std;

bool signCheck(string::iterator* it, char* sign)
{
    if (**it == '-')
    {
        *sign = **it;
        return true;
    }
    else return false;
}

void applySign(long long* target, char* sign)
{
    if (*sign == '-')
    {
        *target *= -1;
        *sign = '+';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        long long a = 0L, b = 0L, proposed = 0L, result = 0L;
        string equation;
        char op, sign = '+';
        getline(cin, equation);
        string::iterator it = equation.begin();

        // 첫번째 숫자
        if (signCheck(&it, &sign)) it++;
        while (*it != ' ')
            a = a * 10L + (long long)(*(it++) - '0');
        applySign(&a, &sign);

        // 연산자 확인
        op = char(*(++it));
        it += 2;

        // 두번째 숫자
        if (signCheck(&it, &sign)) it++;
        if (*it == '-')
            sign = *(it++);
        while (*it != ' ')
            b = b * 10L + (long long)(*(it++) - '0');
        applySign(&b, &sign);
        it += 3;

        // 계산
        switch (op)
        {
        case '+':
            result = a + b;
            break;

        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        }

        // input에서 주어진 결과 숫자
        if (signCheck(&it, &sign)) it++;
        while (it != equation.end())
            proposed = proposed * 10L + (long long)(*(it++) - '0');
        applySign(&proposed, &sign);

        // 일치하는가?
        if (proposed == result) cout << "correct\n";
        else cout << "wrong answer\n";
    }
    return 0;
}