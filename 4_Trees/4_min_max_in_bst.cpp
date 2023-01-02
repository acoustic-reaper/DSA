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

class Bst
{
public:
    BstNode *root = NULL;

    // Insertion using no recursion
    void insert(int x);
    int min_using_loop();
    int min_using_recursion(BstNode* node);
    int max_using_loop();
    int max_using_recursion(BstNode* node);
};

int main()
{
    Bst Tree;

    Tree.insert(15);
    Tree.insert(10);
    Tree.insert(20);
    Tree.insert(8);
    Tree.insert(12);
    Tree.insert(17);
    Tree.insert(25);

    cout << Tree.min_using_loop() << "\n";
    cout << Tree.min_using_recursion(Tree.root) << "\n";
    cout << Tree.max_using_loop() << "\n";
    cout << Tree.max_using_recursion(Tree.root) << "\n";
    return 0;
}

void Bst :: insert(int x)
{
    if (root == NULL)
    {
        root = new BstNode(x);
        return;
    }

    BstNode *temp = root;
    BstNode *parentNode = NULL;

    while (temp)
    {
        parentNode = temp;
        temp = (x <= temp->data) ? temp->left : temp->right;
    }

    if (x <= parentNode->data)
        parentNode->left = new BstNode(x);
    else
        parentNode->right = new BstNode(x);
}

int Bst :: min_using_loop()
{
    if (root == NULL)
    {
        cout << "Error : Tree Empty\n";
        return -1; 
    }
    BstNode* temp = root;
    while (temp -> left)
    {
        temp = temp -> left;
    }
    return temp -> data;
}

int Bst :: min_using_recursion(BstNode* node)
{
    if (node == NULL)
    {
        cout << "Error : Tree Empty.\n";
        return -1;
    }
    else if (node -> left == NULL)
        return node -> data;
    return min_using_recursion(node -> left);
}

int Bst :: max_using_loop()
{
    if (root == NULL)
    {
        cout << "Error : Tree Empty\n";
        return -1; 
    }
    BstNode* temp = root;
    while (temp -> right)
    {
        temp = temp -> right;
    }
    return temp -> data;
}

int Bst :: max_using_recursion(BstNode* node)
{
    if (node == NULL)
    {
        cout << "Error : Tree Empty.\n";
        return -1;
    }
    else if (node -> right == NULL)
        return node -> data;
    return max_using_recursion(node -> right);
}