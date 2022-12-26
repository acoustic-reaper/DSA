/*
 * Implementing Stacks using classes
 * 
 * Class uses array of size as per user's choice 
 */


#include<iostream>
// Defining max size of stack
#define MAX_SIZE 101
using namespace std;

class stack
{
    
    int* arr = NULL;
    int top = -1;
    int size;
    public:
        stack()
        {
            arr = new int(MAX_SIZE);
            size = MAX_SIZE;
        }

        stack(int sizee)
        {
            arr = new int(sizee);
            size = sizee;
        }
        // If user doesn't give size, initialize with MAX_SIZE 101
        

        void Push(int x){
            if (top == size - 1)
            {
                cout << "Error: Stack Overflow!\n";
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
        ~stack()
        {
            delete arr;
            cout << "Memory freed!\n";
        }
};

int main()
{
    stack mystack(2);
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