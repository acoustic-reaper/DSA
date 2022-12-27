/*  
 * Stack implementation using linked lists
 *
 *  Insertion and deletion will be performed at beginning ie at head
 *  to have a constant time operation
*/

#include<iostream>
using namespace std;

// Defining linked list node
class Node
{
    public:
        int x;
        Node* next;
        Node()
        {
            x = 0;
            next = NULL;
        }
        Node(int y)
        {
            x = y;
            next = NULL;
        }
};

Node* top = NULL;

void Push(int x)
{
    Node* temp = new Node(x);
    temp -> next = top;
    top = temp;
}

void Pop()
{
    if (top == NULL)
    {
        cout << "Error : Stack Empty\n";
        return;
    }
    Node* temp = top;
    top = temp -> next;
    delete temp;
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

int Top()
{
    if (isEmpty())
    {
        cout << "Error : Stack Empty!\n";
        return -1;
    }
    return top -> x;
}


void Print()
{
    Node *temp = top;
    while(temp)
    {
        cout << temp -> x << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int main()
{
    cout << isEmpty() << "\n";
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    cout << isEmpty() << "\n";
    cout << Top() << "\n";
    Print();
    return 0;
}