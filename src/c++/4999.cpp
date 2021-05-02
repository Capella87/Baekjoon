// 백준 4999번 문제 : 아!
// https://www.acmicpc.net/problem/4999
// 알고리즘 분류 : 문자열, 애드 혹

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string patient;
    string doctor;

    cin >> patient;
    cin >> doctor;
    if (patient.rfind("h") < doctor.rfind("h"))
        cout << "no\n";
    // string.rfind -> returns index number where input is appeared firstly.
    else cout << "go\n";

    return 0;
}