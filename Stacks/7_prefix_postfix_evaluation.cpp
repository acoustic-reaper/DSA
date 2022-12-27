#include<iostream>
#include<stack>
using namespace std;

int calculate(string str, int decide)
{
    stack <int> s;
    if (decide == 1)
    {

    }
    else
    {
        for (char i : str)
        {
            if (i == '+' || i == '-' || i == '*' || i == '/')
            {
                ll op2 = s.top();
                s.pop();
                ll op1 = s.top();
                s.pop();
                if (i == '+') s.push(op1 + op2);
                else if (i == '-') s.push(op1 - op2);
            }
        }
    }
}

int main()
{
    int decide;
    cout << "Enter\n 1 : Prefix\n 2: Postfix\n";
    cin >> decide;
    cout << "Enter the expression: ";
    string s; cin >> s;
    cout << calculate(s, decide) << "\n";
    return 0;
}