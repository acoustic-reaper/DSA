#include<iostream>
using namespace std;

class BstNode
{
    public:
        int data;
        BstNode* left = NULL;
        BstNode* right = NULL;
        BstNode(int x)
        {    data = x;}
};

void insert(BstNode** root, int x);

void Print(BstNode* root);

BstNode* FindMin(BstNode* root);

BstNode* FindMax(BstNode* root);

BstNode* Find(BstNode* root, int data);

BstNode* GetSuccessor(BstNode* root, int x);

BstNode* GetPredecessor(BstNode* root, int x);

int main()
{
    BstNode* root = NULL;
    insert(&root, 15);
    // Print(root); cout << "\n";
    insert(&root, 10);
    // Print(root); cout << "\n";
    insert(&root, 20);
    // Print(root); cout << "\n";
    insert(&root, 25);
    // Print(root); cout << "\n";
    insert(&root, 8);
    // Print(root); cout << "\n";
    insert(&root, 12);
    // Print(root); cout << "\n";
    insert(&root, 17);
    Print(root); cout << "\n";

    cout << GetSuccessor(root, 15) -> data << "\n";

    cout << GetPredecessor(root, 12) -> data << "\n";
    return 0;
}

BstNode* GetSuccessor(BstNode* root, int x)
{
    BstNode* current = Find(root, x);
    if (current == NULL) return NULL;
    if (current -> right != NULL)
    {
        return FindMin(current -> right);
    }
    else
    {
        BstNode* successor = NULL;
        BstNode* ancestor = root;

        while (ancestor != current)
        {
            if (x < ancestor -> data)
            {
                successor = ancestor;
                ancestor = ancestor -> left;
            }
            else ancestor = ancestor -> right;
        }
        return successor;
    }
}

BstNode* GetPredecessor(BstNode* root, int x)
{
    BstNode* current = Find(root, x);
    if (current == NULL) return NULL;
    if (current -> left != NULL)
    {
        return FindMax(current -> left);
    }
    else
    {
        BstNode* predecessor = NULL;
        BstNode* ancestor = root;

        while (ancestor != current)
        {
            if (x < ancestor -> data)
            {
                ancestor = ancestor -> left;
            }
            else
            {
                predecessor = ancestor;
                ancestor = ancestor -> right;
            } 
        }
        return predecessor;
    }
}

BstNode* Find(BstNode* root, int data)
{
    if (root == NULL) return NULL;
    if (root -> data == data) return root;
    if (data < root -> data) return Find(root -> left, data);
    return Find(root -> right, data); 
}

void Print(BstNode* root)
{
    // Depth - first Traversal
    // Pre - order Traversal -> D L R
    // Using Inorder_traversal -> (LDR) -> we can get the data in increasing order
    // Using Inorder_traversal -> (RDL) -> we will get the data in decreasing order
    if (root == NULL)
    {
        return;
    }
    Print(root -> left);
    cout << root -> data << " ";
    Print(root -> right);
}


void insert(BstNode** root, int x)
{
    if (*root == NULL)
    {
        *root = new BstNode(x);
        return;
    }

    BstNode* temp = *root;
    BstNode* parentNode = NULL;

    while (temp)
    {
        parentNode = temp;
        temp = (x <= temp -> data)? temp->left : temp -> right;
    }

    if (x <= parentNode -> data) parentNode -> left = new BstNode(x);
    else parentNode -> right = new BstNode(x);
}


BstNode* FindMin(BstNode* root)
{
    while (root -> left) root = root -> left;
    return root;
}

BstNode* FindMax(BstNode* root)
{
    while (root -> right) root = root -> right;
    return root;
}

