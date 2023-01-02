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

BstNode* Delete(BstNode* root, int data);

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
    cout << "Before deleting:\n";
    Print(root); cout << "\n";
    cout << "After deleting 20:\n";
    root = Delete(root, 20);
    Print(root); cout << "\n";
    return 0;
}

BstNode* Delete(BstNode* root, int data)
{
    if (root == NULL) return root;
    else if (data > root -> data) root -> right = Delete(root -> right, data);
    else if (data < root -> data) root -> left = Delete(root -> left, data);

    else
    {
        // Case 1: No child
        if (root -> right == NULL && root -> left == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: 1 child
        else if (root -> right == NULL)
        {
            BstNode* temp = root;
            root = temp -> left;
            delete temp;
        }
        else if (root -> left == NULL)
        {
            BstNode* temp = root;
            root = temp -> right;
            delete temp;
        }

        // Case 3 : 2 child
        // We shall find the node having the minimum value in the right subtree
        // of this node
        // Then set this node's value to the min value
        // and update this node's right address using
        // node -> right = Delete(node -> right, min data)
        // i.e. delete the duplicate data below
        else
        {
            BstNode* temp = FindMin(root -> right);
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp -> data);
        }
        return root;
    }
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