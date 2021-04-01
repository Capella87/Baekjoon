// 백준 10828번 문제 : 스택
// https://www.acmicpc.net/problem/10828
// 알고리즘 분류 : 자료 구조, 스택
// C++11 Version

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef int Item;

class Stack
{
private:
    Item* arr;
    int m_max;
    int top;
public:
    Stack();
    Stack(const int max);
    ~Stack();

    bool push(const Item& item);
    bool pop(Item& target);
    int size(void);
    bool empty(void);
    bool getTop(Item& target);
};

void commandProcess(Stack& tStack, const int& n);

int main(void)
{
    int n;

    cin >> n;
    Stack place(n);
    commandProcess(place, n);

    return 0;
}

Stack::Stack()
{
    m_max = 0;
    arr = NULL;
    top = 0;
}

Stack::Stack(const int max)
{
    m_max = max;
    arr = new Item[m_max];
    if (arr == NULL)
        exit(EXIT_FAILURE);
    top = 0;
}

Stack::~Stack()
{
    delete[] arr;
}

bool Stack::push(const Item& item)
{
    if (top < m_max)
    {
        arr[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item& target)
{
    if (top > 0)
    {
        target = arr[--top];
        return true;
    }
    else
    {
        target = -1;
        return false;
    }
}

int Stack::size(void)
{
    return top;
}

bool Stack::empty(void)
{
    return top == 0 ? true : false;
}

bool Stack::getTop(Item& target)
{
    if (top > 0)
    {
        target = arr[top - 1];
        return true;
    }
    else
    {
        target = -1;
        return false;
    }
}

void commandProcess(Stack& tStack, const int& n)
{
    Item target;
    string cmd;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> target;
            tStack.push(target);
        }
        else if (cmd == "top")
        {
            tStack.getTop(target);
            cout << target << '\n';
        }
        else if (cmd == "pop")
        {
            tStack.pop(target);
            cout << target << '\n';
        }
        else if (cmd == "size")
            cout << tStack.size() << '\n';
        else if (cmd == "empty")
            cout << int(tStack.empty()) << '\n';
        cin.get();
    }
}