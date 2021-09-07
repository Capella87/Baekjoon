// 백준 16944번 문제 : 강력한 비밀번호
// https://www.acmicpc.net/problem/16944
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;
const string SPECIAL = "!@#$%^&*()+";

class Password
{
private:
    string str;
    size_t len;
    bool hasNum;
    bool hasBigCase;
    bool hasSmallCase;
    bool hasSpecialChar;
    
    size_t getNeedCharCount(void)
    {
        if (len >= 6 && hasNum && hasBigCase && hasSmallCase && hasSpecialChar) return 0;

        size_t rt = size_t(!hasNum) + size_t(!hasBigCase) + size_t(!hasSmallCase) + size_t(!hasSpecialChar);
        return (rt + len >= 6) ? rt : 6 - (rt + len) + rt;
    }
public:
    Password(string& str, size_t len)
    {
        this->str = str;
        this->len = len;
        hasNum = hasBigCase = hasSmallCase = hasSpecialChar = false;
    }

    size_t inspectWord(void)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (!hasSmallCase && str[i] >= 'a' && str[i] <= 'z')
                hasSmallCase = true;
            else if (!hasBigCase && str[i] >= 'A' && str[i] <= 'Z')
                hasBigCase = true;
            else if (!hasNum && str[i] >= '0' && str[i] <= '9')
                hasNum = true;
            else if (!hasSpecialChar && SPECIAL.find(str[i]) != string::npos)
                hasSpecialChar = true;
        }
        return getNeedCharCount();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string password;
    size_t len;

    cin >> len;
    cin.get();
    cin >> password;
    
    Password p(password, len);
    cout << p.inspectWord() << '\n';
    return 0;
}