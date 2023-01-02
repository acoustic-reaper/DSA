#include <iostream>
using namespace std;
class Node
{
    public:
        int x;
        Node* next;
        Node(int y){
            x = y;
            next = NULL;
        }
};

void insert_at_beginning(Node** head, int x)
{
    Node* temp = new Node(x);
    temp -> next = *head;
    *head = temp;
}

void print(Node* head)
{
    while (head)
    {
        cout << head -> x << " ";
        head = head -> next;
    }
    cout << "\n";
}

int main() 
{
	// your code goes here
    Node* head = NULL;
    insert_at_beginning(&head, 1);
    print(head);
    insert_at_beginning(&head, 2);
    print(head);
    insert_at_beginning(&head, 3);
    print(head);
    insert_at_beginning(&head, 4);
    print(head);
    insert_at_beginning(&head, 5);
    print(head);
    insert_at_beginning(&head, 6);
    print(head);
    insert_at_beginning(&head, 7);
    print(head);
    insert_at_beginning(&head, 8);
    print(head);
    insert_at_beginning(&head, 9);
    print(head);
    insert_at_beginning(&head, 10);
    print(head);
	return 0;
}