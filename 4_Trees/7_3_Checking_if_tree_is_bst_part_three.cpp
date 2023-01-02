/*
 * Checking if given tree is BST : Part Three:
 * This approach uses the below function:
 *     bool IsBinarySearchTree(BstNode* root);
 * The following algo is applied to each subtree using recursion
 * Here, we find the minimum in the right subtree, and max in the left subtree
 * Then if min > root -> data, then each and every value in the right subtree 
 * will be greater than root.
 * And if max <= root -> data, then each and every value in the left subtree 
 * will be lesse than root. and hence it will be proved if tree is a BST.
 * Time Complexity : O(n^2)
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
bool IsBinarySearchTree(BstNode* root);
int findMax(BstNode* node);
int findMin(BstNode* node);

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

// Usage : IsBinarySearchTree(Tree.root);

bool IsBinarySearchTree(BstNode* root)
{
    if (root == NULL) return true;
    if (root -> data >= findMax(root -> left) && root -> data < findMin(root -> right) && IsBinarySearchTree(root -> left) && IsBinarySearchTree(root -> right))
        return true;
    return false;
}

int findMax(BstNode* node)
{
    if (node == NULL) return 0;
    int mx = 0;
    mx = max(findMax(node -> left), mx);
    mx = max(mx, findMax(node -> right));
    return max(mx, node -> data);
}

int findMin(BstNode* node)
{
    if (node == NULL) return 1000000000;
    int mn = 1000000000;
    mn = min(findMin(node -> left), mn);
    mn = min(mn, findMin(node -> right));
    return min(mn, node -> data);
}