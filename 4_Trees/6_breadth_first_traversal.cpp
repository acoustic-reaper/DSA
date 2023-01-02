#include <iostream>
#include <queue>
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
    void breadth_first_traversal(BstNode *node);
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

    Tree.breadth_first_traversal(Tree.root);
    return 0;
}

void Bst ::insert(int x)
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

void Bst ::breadth_first_traversal(BstNode *node)
{
    if (node == NULL)
    {
        cout << "Tree empty!\n";
        return;
    }
    queue <BstNode*> q;
    q.emplace(root);
    while (q.size())
    {
        cout << q.front() -> data << " ";
        if (q.front() -> left) q.emplace(q.front() -> left);
        if (q.front() -> right) q.emplace(q.front() -> right);
        q.pop();
    }
    cout << "\n";
}
