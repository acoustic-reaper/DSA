/*
 * Checking if given tree is BST : Part Four:
 * This approach uses the below function:
 *     bool IsBinarySearchTree(BstNode* root);
 * Here we use the concept of range for each node's data
 * Eg-> (root -> data)'s range is -INF to +INF
 * Similarly (root -> left -> data)'s range is -INF to root -> data(inclusive) and so
 * on 
 * Time Complexity : O(n)
 * Caution : CAN'T HANDLE DUPLICATES
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
bool IsBstUtil(BstNode* node, int minValue, int maxValue);

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
    return IsBstUtil(root, INT32_MIN, INT32_MAX);
}

bool IsBstUtil(BstNode* root, int minValue, int maxValue)
{
    if (root == NULL) return true;
    if (root -> data > minValue && root -> data < maxValue && IsBstUtil(root -> left, minValue, root -> data) && IsBstUtil(root -> right, root -> data, maxValue))
        return true;
    else return false;
}