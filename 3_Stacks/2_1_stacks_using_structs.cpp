/*
 * Implementing Stacks using structs
 * 
 * Struct uses array of fixed size 
 */


#include<iostream>
// Defining max size of stack
#define MAX_SIZE 101
using namespace std;

struct stack
{
    int arr[MAX_SIZE];
    int top = -1;
    
    void Push(int x){
        if (top == MAX_SIZE - 1)
        {
            cout << "Error: Stack Overflow!";
            return;
        }
        arr[++top] = x;
    }

    void Pop(){
        if (top == -1)
        {
            cout << "Error : Stack Empty!";
            return;
        }
        top--;
    }

    int Top()
    {
        return arr[top]; 
    }

    bool isEmpty(){
        if (top == -1)
            return true;
        return false;
    }

    void Print(){
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    stack mystack;
    if (mystack.isEmpty()) cout << "Stack Empty!" << "\n";
    mystack.Push(2);
    mystack.Print();
    mystack.Push(5);
    mystack.Print();
    mystack.Push(10);
    mystack.Print();
    mystack.Pop();
    mystack.Print();
    mystack.Push(12);
    mystack.Print();
    cout << mystack.isEmpty() << "\n";
    return 0;
}