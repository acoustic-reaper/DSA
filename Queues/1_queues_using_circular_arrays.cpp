/*
 * Queue Implementation using Circular Array
 * Functions:
 *      1) Enqueue()
 *      2) Dequeue()
 *      3) IsEmpty()
 *      4) IsFull()
 *      5) Front()
 *      6) Print()
 */

#include <iostream>
#define MAX_SIZE 101
using namespace std;

class Queue
{
    int a[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }

    bool IsFull()
    {
        return ((rear + 1) % MAX_SIZE == front) ? true : false;
    }

    void Enqueue(int x)
    {
        cout << "Enqueuing " << x << "\n";
        if (IsFull())
        {
            cout << "Error : Queue is Full!\n";
            return;
        }
        else if (IsEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        a[rear] = x;
    }

    void Dequeue()
    {
        cout << "Dequeing :\n";
        if (IsEmpty())
        {
            cout << "Error : Queue is already empty!\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return a[front];
    }

    void Print()
    {
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;

        for (int i = 0; i < count; i++)
        {
            int idx = (front + i) % MAX_SIZE;
            cout << a[idx] << " ";
        }
        cout << "\n\n";
    }
};

int main()
{
    Queue Q; // creating an instance of Queue.
    Q.Enqueue(2);
    Q.Print();
    Q.Enqueue(4);
    Q.Print();
    Q.Enqueue(6);
    Q.Print();
    Q.Dequeue();
    Q.Print();
    Q.Enqueue(8);
    Q.Print();
    return 0;
}