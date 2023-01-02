/*
 * Checking if given tree is BST : Part One:
 * This approach uses three functions viz:
 *     bool IsBinarySearchTree(BstNode* root);
 *     bool IsSubtreeLesser(BstNode* node, int x);
 *     bool IsSubtreeGreater(BstNode* node, int x);
 * Time Complexity : O(n^2)
*/

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
};

bool IsBinarySearchTree(BstNode* root);
bool IsSubtreeLesser(BstNode* node, int x);
bool IsSubtreeGreater(BstNode* node, int x);

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

    cout << IsBinarySearchTree(Tree.root) << "\n";

    Bst Tree2;
    Tree2.insert(10);
    Tree2.root -> left = new BstNode(12);
    Tree2.root -> right = new BstNode(8);
    
    cout << IsBinarySearchTree(Tree2.root) << "\n";
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

bool IsBinarySearchTree(BstNode* root)
{
    if (root == NULL) return true;
    if (IsSubtreeLesser(root -> left, root -> data) && IsSubtreeGreater(root -> right, root -> data) && IsBinarySearchTree(root -> left) && IsBinarySearchTree(root -> right))
        return true;
    else 
        return false;
}

bool IsSubtreeLesser(BstNode* node, int x)
{
    if (node == NULL) return true;
    if (node -> data <= x && IsSubtreeLesser(node -> left, x) && IsSubtreeLesser(node -> right, x))
        return true;
    else return false;
}

bool IsSubtreeGreater(BstNode* node, int x)
{
    if (node == NULL) return true;
    if (node -> data > x && IsSubtreeGreater(node -> right, x) && IsSubtreeGreater(node -> left, x))
        return true;
    else return false;
}

