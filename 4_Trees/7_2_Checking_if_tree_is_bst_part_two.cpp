/*
 * Checking if given tree is BST : Part Two:
 * This approach uses the below function:
 *     bool IsBinarySearchTree(BstNode* root);
 * Here we use Inorder Traversal (which gives a sorted array if tree is Bst)
 * keeping track of prev and curr data
 * If (prev > curr) return false
 * Time Complexity : O(n)
*/

#include <iostream>
#define INF 1e9
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
// Whenever defining functions with default params, always put the defaults 
// in the prototype itself like below
bool IsBinarySearchTree(BstNode* root, int prev = -1000000000);

// And function defintion shud be free of default params since they have
// already been informed to the compiler in the prototype

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

// Usage : IsBinarySearchTree(Tree.root, -INF);

bool IsBinarySearchTree(BstNode* root, int prev)
{
    if (root == NULL) return true;
    IsBinarySearchTree(root -> left, prev);
    if (root -> data < prev) return false;
    else prev = root -> data;
    IsBinarySearchTree(root -> right, prev);
}