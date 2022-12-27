/*
 * This program is meant to evaluate prefix and postfix Expressions
*/


#include<iostream>
#include<stack>
using namespace std;

int calculate(string str, int decide)
{
    stack <int> s;
    if (decide == 1)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                if (str[i] == '+') s.push(op1 + op2);
                else if (str[i] == '-') s.push(op1 - op2);
                else if (str[i] == '*') s.push(op1 * op2);
                else s.push(int((op1 * 1.0) / (op2 * 1.0)));
            }
            else
            {
                s.push(str[i] - '0');
            }
            // cout << s.top() << "\n";
        }
    }
    else
    {
        for (char i : str)
        {
            if (i == '+' || i == '-' || i == '*' || i == '/')
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if (i == '+') s.push(op1 + op2);
                else if (i == '-') s.push(op1 - op2);
                else if (i == '*') s.push(op1 * op2);
                else s.push(int((op1 * 1.0) / (op2 * 1.0)));
            }
            else
            {
                s.push(i - '0');
            }
            // cout << s.top() << "\n";
        }
    }
    return s.top();
}

int main()
{
    int decide;
    cout << "Enter\n 1 : Prefix\n 2 : Postfix\n";
    cin >> decide;
    cout << "Enter the expression: ";
    string s; cin >> s;
    cout << calculate(s, decide) << "\n";
    return 0;
}