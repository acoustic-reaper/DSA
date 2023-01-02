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

void delete_at_any_position(Node** head, int n)
{
    Node* temp = *head;
    if (n == 1)
    {
        *head = temp -> next;
        delete temp;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        temp = temp -> next;
        if (temp -> next == NULL && i < (n - 1))
        {
            cout << "Out of bounds\n";
            return;
        }
    }
    Node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    delete temp2;
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
    int n;
    print(head);
    while (true)
    {
        cout << "What position to delete? (press 0 to stop) ";cin >> n;
        if (n == 0)
        {
            cout << "Stopping...";
            break;
        }
        delete_at_any_position(&head, n);
        print(head);
    }
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