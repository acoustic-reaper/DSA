/*
 * Applications of Stacks:
 *   1) Reversal of a string 
 *   2) Reversal of a linked list (in next file of stack applications)
*/


#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

void Reverse(char C[], int size)
{
    stack <char> temp;
    for (int i = 0; i < size; i++)
    {
        temp.push(C[i]);
    }
    for (int i = 0; i < size; i++)
    {
        C[i] = temp.top();
        temp.pop();
    }
}

int main()
{
    char C[51];
    cout << "Enter a string: ";
    gets(C);
    Reverse(C, strlen(C));
    printf("Output: %s", C);
    return 0;
}