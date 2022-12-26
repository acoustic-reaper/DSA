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


void insert_at_beginning(Node** head, int x);
void print(Node* head);

void reverse_iteratively(Node** head)
{
    Node *prev, *curr, *next;
    prev = NULL;
    curr = *head;
    while (curr)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() 
{
	// your code goes here
    Node* head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 6);
    insert_at_beginning(&head, 7);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 9);
    insert_at_beginning(&head, 10);
    cout << "Before reversing: "; print(head);
    reverse_iteratively(&head);
    cout << "After reversing: ";
    print(head);
	return 0;
}




void insert_at_beginning(Node** head, int x)
{
    Node* temp = new Node(x);
    if (*head != NULL)
    {
        temp -> next = *head;
    }
    *head = temp;
}


void print(Node* head)
{
    while (head != NULL)
    {
        cout << head -> x << " ";
        head = head -> next;
    }
    cout << "\n";
}