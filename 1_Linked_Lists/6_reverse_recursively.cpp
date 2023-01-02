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

void reverse_recursively(Node** head, Node* p)
{
    if (p -> next == NULL)
    {
        *head = p;
        return;
    }
    reverse_recursively(head, p -> next);
    Node* q = p -> next;
    q -> next = p;  
    p -> next = NULL;
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
    cout << "After  reversing: ";
    reverse_recursively(&head, head);
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