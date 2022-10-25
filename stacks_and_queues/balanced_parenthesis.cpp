#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string input)
{
    stack<char> s;
    for (auto ch : input)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            s.push(ch);
            break;
        case ')':
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            continue;
        }
    }
}

int main()
{
    string s = "((a+b+c)+[d])";
    if (isBalanced(s))
    {
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}