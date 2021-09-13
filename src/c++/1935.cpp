// 백준 1935번 문제 : 후위 표기식2
// https://www.acmicpc.net/problem/1935
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
#include <iomanip>
#include <string>
using namespace std;

double calc(string& expr, int* num, const int size)
{
    stack <char>operand;
    stack <double>temp;
    size_t len = expr.length();
    double tempVar[2];

    for (size_t i = 0; i < len; i++)
    {
        if (expr[i] >= 'A' && expr[i] <= 'Z')
        {
            operand.push(expr[i]);
            continue;
        }
        for (int j = 1; j >= 0; j--)
        {
            if (operand.top() == 't')
            {
                tempVar[j] = temp.top();
                temp.pop();
            }
            else tempVar[j] = num[operand.top() - 'A'];
            operand.pop();
        }
        switch (expr[i])
        {
        case '+':
            temp.push(tempVar[0] + tempVar[1]);
            break;
        case '-':
            temp.push(tempVar[0] - tempVar[1]);
            break;
        case '*':
            temp.push(tempVar[0] * tempVar[1]);
            break;
        case '/':
            temp.push(tempVar[0] / tempVar[1]);
            break;
        }
        operand.push('t');
    }
    return temp.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string expression;
    int n;

    cin >> n;
    cin.get();
    getline(cin, expression);

    int* num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cout << fixed << setprecision(2);
    cout << calc(expression, num, n) << '\n';

    delete[] num;
    return 0;
}