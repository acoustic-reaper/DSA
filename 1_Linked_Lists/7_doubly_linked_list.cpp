#include <iostream>
using namespace std;
class Node
{
    public:
        int x;
        Node* next;
        Node* prev;
        Node(int y){
            x = y;
            next = NULL;
            prev = NULL;
        }
};

void insert_at_head(Node** head, int x)
{
    Node* temp = new Node(x);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    (*head) -> prev = temp;
    temp -> next = *head;
    *head = temp;
}

void insert_at_tail(Node** head, int x)
{
    Node *temp1 = new Node(x);
    if (*head == NULL)
    {
        *head = temp1;
        return;
    }
    Node *temp2 = *head;
    while (temp2 -> next)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1;
    temp1 -> prev = temp2;
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
void print_reverse_using_prev_pointer(Node* head)
{
    if (head == NULL)
    {
        cout << "List empty!\n";
        return;
    }
    while (head -> next)
    {
        head = head -> next;
    }
    while(head)
    {
        cout << head -> x << " ";
        head = head -> prev;
    }
    cout << "\n";
}

int main() 
{
	// your code goes here
    Node* head = NULL;
    insert_at_head(&head, 1);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 2);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 3);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 4);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 5);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 6);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 7);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 8);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 9);
    print(head);
    print_reverse_using_prev_pointer(head);
    insert_at_head(&head, 10);
    print(head);
    print_reverse_using_prev_pointer(head);
	return 0;
}