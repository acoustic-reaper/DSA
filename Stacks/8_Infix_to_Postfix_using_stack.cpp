/*
 * Program to convert infix expression to postfix 
 * Operators supported -> { +, -, *, /, ^}
 * Operands supported -> { 0 - 9, A - Z, a - z}
*/


#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to convert infix to postfix
string InfixToPostfix(string expression);

// Function to check if a character is operator
bool IsOperator(char c);

// Function to check if a character is operator
bool IsOperand(char c);

// Function to check which operator has higher precedence
bool HasHigherPrecedence(char c1, char c2);

// Function to check for open paranthesis
bool IsOpenParanthesis(char c);

// Function to check for close paranthesis
bool IsCloseParanthesis(char c);

int main()
{
    string expression;
    cout << "Enter Infix Expression : ";
    cin >> expression;
    cout << "Converted Postfix Expression : ";
    cout << InfixToPostfix(expression) << "\n";   
    return 0;
}

string InfixToPostfix(string expression)
{
    stack <char> s;
    string toReturn = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ' || expression[i] == ',')continue;

        else if (IsOperator(expression[i]))
        {
            while (!s.empty() && !IsOpenParanthesis(s.top()) && HasHigherPrecedence(s.top(), expression[i]))
            {
                toReturn += s.top();
                s.pop();
            }
            s.push(expression[i]);  
        }

        else if (IsOperand(expression[i]))
        {
            toReturn += expression[i];
        }

        else if (IsOpenParanthesis(expression[i]))
        {
            s.push(expression[i]);
        }

        else if (IsCloseParanthesis(expression[i]))
        {
            while (!s.empty() && !IsOpenParanthesis(s.top()))
            {
                toReturn += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        toReturn += s.top();
        s.pop();
    }
    return toReturn;
}

bool IsOperator(char c)
{
    if (c == '*' || c == '+' || c == '-' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}

bool IsOperand(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

bool IsOpenParanthesis(char c)
{
    if (c == '{' || c == '[' || c == '(') return true;
    return false;
}

bool IsCloseParanthesis(char c)
{
    if (c == '}' || c == ']' || c == ')') return true;
    return false;
}

int GetWeight(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
        return 2;
    if (c == '^') return 3;
}

bool IsRightAssociative(char c)
{
    if (c == '^')
        return true;
    return false;
}

bool HasHigherPrecedence(char c1, char c2)
{
    int wt1 = GetWeight(c1);
    int wt2 = GetWeight(c2);
    if (wt1 == wt2)
    {
        if (IsRightAssociative(c1)) return false;
        return true;
    }
    return (wt1 > wt2)?  true : false;
}