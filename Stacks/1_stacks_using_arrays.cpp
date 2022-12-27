/* Stack Implementation using Array


 * Stack Functions include:


    * void Push(int x);
    * void Pop();
    * void top();
    * bool isEmpty();
*/


#include<iostream>
// Defining MAX_SIZE of our stack
#define MAX_SIZE 101
using namespace std;

// Declaring our stack of MAX_SIZE

int stack[MAX_SIZE];

// Initializing top as global variable and setting it to -1 (-1 means stack is currently empty)

int top = -1;

// Function prototypes

void Push(int x);
void Pop();
void Top();
bool isEmpty();
void Print();

// Main starts here

int main()
{
    if(isEmpty())cout << "YES" << "\n";
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    if (isEmpty()) cout << "YES" << "\n";
    Top();
    return 0;
}

// Function definitions
void Push(int x)
{
    // We can make a new array of size twice the MAX_SIZE then copy everthing into the new array 
    // But here we are keeping it simple, i.e. if stack is full and we try to push it throws Error
    if (top == (MAX_SIZE - 1))
    {
        cout << "Error : Stack Overflow!\n";
        return;
    }
    stack[++top] = x;
}

void Pop(){
    // Check if stack is empty
    if (top == -1)
    {
        cout << "Error : Stack is Empty\n";
        return;
    }
    top--;
}

void Top()
{
    cout << stack[top] << "\n";
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else return false;
}

void Print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << "\n";
}