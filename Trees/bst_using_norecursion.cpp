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

void insert(BstNode** root, int x)
{
    if (*root == NULL)
    {
        *root = new BstNode(x);
        return;
    }
    BstNode* temp = *root;
    while (temp -> left || temp -> right)
    {
        if (temp -> data >= x)
        {
            if (temp -> left != NULL)
                temp = temp -> left;
            else break;
        }
        else
        {
            if (temp -> right != NULL)
                temp = temp -> right;
            else break;
        }
    }

    (temp -> data >= x)? temp -> left = new BstNode(x): temp -> right = new BstNode(x);
}

void insert_using_different_algo(BstNode** root, int x)
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

bool Search(BstNode* root, int x)
{
    if (root == NULL) return false;
    while (root -> left || root -> right)
    {
        if (root -> data == x) return true;
        if (root -> data > x)
        {
            if (root -> left != NULL)
                root = root -> left;
            else break;
        }
        else
        {
            if (root -> right != NULL)
                root = root -> right;
            else break;
        }
    }
    if (root -> data == x) return true;
    return false; 
}

bool Search_using_diff_algo(BstNode* root, int x)
{
    while (root != NULL && root -> data != x)
    {
        root = (root -> data >= x)? root -> left : root -> right;
    }

    return (root != NULL)? true : false; 
}

void Print(BstNode* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    Print(root -> left);
    Print(root -> right);
}
int main()
{
    BstNode* root = NULL;
    insert(&root, 15);
    Print(root); cout << "\n";
    insert_using_different_algo(&root, 10);
    Print(root); cout << "\n";
    insert(&root, 20);
    Print(root); cout << "\n";
    insert_using_different_algo(&root, 25);
    Print(root); cout << "\n";
    insert(&root, 8);
    Print(root); cout << "\n";
    insert_using_different_algo(&root, 12);
    Print(root); cout << "\n";
    insert(&root, 17);
    Print(root); cout << "\n";

    cout << Search(root, 30) << "\n";
    cout << Search(root, 9) << "\n";
    cout << Search_using_diff_algo(root, 30) << "\n";
    cout << Search_using_diff_algo(root, 9) << "\n";
    return 0;
}