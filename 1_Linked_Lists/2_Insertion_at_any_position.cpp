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
void insert_at_any_position(Node** head, int x, int n)
{
    Node* temp1 = new Node(x);
    if (n == 1)
    {
        temp1 -> next = *head;
        *head = temp1;
        return;
    }
    Node* temp2 = *head;
    for (int i = 1; i < n - 1; i++)
    {
        temp2 = temp2 -> next;
        if (temp2 -> next == NULL && i < (n - 2))
        {
            cout << "Out of bounds\n";
            return;
        }
    }
    temp1->next = temp2 -> next;
    temp2->next = temp1;
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

int main() 
{
	// your code goes here
    Node* head = NULL;
    insert_at_any_position(&head, 1, 1);
    print(head);
    insert_at_any_position(&head, 2, 2);
    print(head);
    insert_at_any_position(&head, 3, 3);
    print(head);
    insert_at_any_position(&head, 4, 35);
    print(head);
    insert_at_any_position(&head, 5, 4);
    print(head);
    insert_at_any_position(&head, 6, 5);
    print(head);
    insert_at_any_position(&head, 7, 3);
    print(head);
    insert_at_any_position(&head, 8, 5);
    print(head);
    insert_at_any_position(&head, 9, 7);
    print(head);
    insert_at_any_position(&head, 10, 8);
    print(head);
	return 0;
}