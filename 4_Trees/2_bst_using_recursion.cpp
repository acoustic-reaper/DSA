#include <iostream>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left = NULL;
    BstNode *right = NULL;
    BstNode(int x)
    {
        data = x;
    }
};

void insert(BstNode** root, int x)
{
    if (*root == NULL)
    {
        *root = new BstNode(x);
        return;
    }

    ((*root)->data >= x) ? insert(&((*root)->left), x) : insert(&((*root)->right), x);
}

bool Search(BstNode* root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    return (root->data > x) ? Search(root->left, x) : Search(root->right, x);
}

void Print(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Print(root->left);
    Print(root->right);
}

int main()
{
    BstNode *root = NULL;
    insert(&root, 15);
    Print(root);
    cout << "\n";
    insert(&root, 10);
    Print(root);
    cout << "\n";
    insert(&root, 20);
    Print(root);
    cout << "\n";
    insert(&root, 25);
    Print(root);
    cout << "\n";
    insert(&root, 8);
    Print(root);
    cout << "\n";
    insert(&root, 12);
    Print(root);
    cout << "\n";
    insert(&root, 17);
    Print(root);
    cout << "\n";

    cout << Search(root, 15) << "\n";
    cout << Search(root, 8) << "\n";
    cout << Search(root, 30) << "\n";
    cout << Search(root, 9) << "\n";
    return 0;
}