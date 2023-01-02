/*
 * Queue Implementation using Linked List
 * front shall store address of head node
 * rear shall store address of rear node
 * Functions:
 *      1) Enqueue()
 *      2) Dequeue()
 *      3) IsEmpty()
 *      4) IsFull()
 *      5) Front()
 *      6) Print()
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int x)
    {
        data = x;
    }
};

class Queue
{
    Node *front = NULL;
    Node *rear = NULL;

public:
    void Enqueue(int x)
    {
        Node* temp = new Node(x);
        if (front == NULL)
        {
            front = rear = temp;
            return;
        }
        rear -> next = temp;
        rear = temp;
    }
    void Dequeue()
    {
        Node* temp = front;
        if (front == NULL)
        {
            cout << "Queue is already empty.\n";
            return;
        }
        if (front == rear)
        {
            front = rear = NULL;
        }
        else 
            front = temp -> next;
        delete temp;
    }

    int Front()
    {
        if (front == NULL)
        {
            cout << "Queue Empty!\n";
            return -1;
        }
        return front -> data;
    }

    void Print()
    {
        Node* temp = front;
        while (temp)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue Q;
    Q.Enqueue(2); Q.Print();
	Q.Enqueue(4); Q.Print();
	Q.Enqueue(6); Q.Print();
	Q.Dequeue();  Q.Print();
	Q.Enqueue(8); Q.Print();
    return 0;
}