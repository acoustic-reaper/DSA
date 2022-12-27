#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

bool isBalanced(string s)
{
    unordered_map <char, int> m = {{'{', 1},{'(', 2}, {'[', 3}, {'}', -1}, {')', -2}, {']', -3}};
    stack <char> temp;
    for (char i : s)
    {
        if (m[i] > 0)
        {
            temp.push(i);
        }
        else
        {
            if (temp.empty() || (m[i] + m[temp.top()]) != 0)
            {
                return false;
            }
            else
            {
                temp.pop();
            }
        }
    }
    if (temp.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    cout << "Enter a string : ";
    string s; cin >> s;
    if (isBalanced(s))
    {
        cout << "Balanced!\n";
    }
    else
    {
        cout << "Not Balanced\n";
    }
    return 0;
}