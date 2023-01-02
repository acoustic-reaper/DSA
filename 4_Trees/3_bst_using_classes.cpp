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
    void insert_using_norecursion(int x)
    {
        if (root == NULL)
        {
            root = new BstNode(x);
            return;
        }
        BstNode *temp = root;
        while (temp->left || temp->right)
        {
            if (temp->data >= x)
            {
                if (temp->left != NULL)
                    temp = temp->left;
                else
                    break;
            }
            else
            {
                if (temp->right != NULL)
                    temp = temp->right;
                else
                    break;
            }
        }
        (temp->data >= x) ? temp->left = new BstNode(x) : temp->right = new BstNode(x);
    }

    // Insertion using recursion but with a different algo
    void insert_using_norecursion_diff_algo(int x)
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

    // Insertion using recursion
    // Usage :
    // Bst Tree;
    // Tree.insert_using_recursion(&Tree.root, x)
    void insert_using_recursion(BstNode **node, int x)
    {
        if (*node == NULL)
        {
            *node = new BstNode(x);
            return;
        }

        ((*node)->data >= x) ? insert_using_recursion(&((*node)->left), x) : insert_using_recursion(&((*node)->right), x);
    }

    // Search using no recursion
    bool Search_using_no_recursion(int x)
    {
        if (root == NULL)
            return false;
        BstNode* temp = root;
        while (temp->left || temp->right)
        {
            if (temp->data == x)
                return true;
            if (temp->data > x)
            {
                if (temp->left != NULL)
                    temp = temp->left;
                else
                    break;
            }
            else
            {
                if (temp->right != NULL)
                    temp = temp->right;
                else
                    break;
            }
        }
        if (temp->data == x)
            return true;
        return false;
    }

    // Search using no recursion but with different algo
    bool Search_using_no_recursion_diff_algo(int x)
    {
        BstNode *temp = root;
        while (temp != NULL && temp->data != x)
        {
            temp = (temp->data > x) ? temp->left : temp->right;
        }
        return (temp != NULL) ? true : false;
    }

    // Search using recursion
    // Usage:
    // Bst Tree;
    // Search_using_recursion(Tree.root, x)
    bool Search_using_recursion(BstNode *node, int x)
    {
        if (node == NULL)
            return false;
        if (node->data == x)
            return true;

        return (node->data > x) ? Search_using_recursion(node->left, x) : Search_using_recursion(node->right, x);
    }

    // Just to see if insertion is working fine or not
    // Usage :
    // Bst Tree;
    // Tree.Print(Tree.root)
    void Print(BstNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        Print(node->left);
        Print(node->right);
    }
};

int main()
{
    Bst Tree;

    // Using no recursion
    Tree.insert_using_norecursion(15);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(10);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(20);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(25);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(8);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(12);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion(17);
    Tree.Print(Tree.root);
    cout << "\n";

    cout << Tree.Search_using_no_recursion(15) << "\n";
    cout << Tree.Search_using_no_recursion(8) << "\n";
    cout << Tree.Search_using_no_recursion(30) << "\n";
    cout << Tree.Search_using_no_recursion(9) << "\n";


    // Using no recursion diff algo
    Tree.insert_using_norecursion_diff_algo(15);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(10);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(20);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(25);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(8);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(12);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_norecursion_diff_algo(17);
    Tree.Print(Tree.root);
    cout << "\n";

    cout << Tree.Search_using_no_recursion_diff_algo(15) << "\n";
    cout << Tree.Search_using_no_recursion_diff_algo(8) << "\n";
    cout << Tree.Search_using_no_recursion_diff_algo(30) << "\n";
    cout << Tree.Search_using_no_recursion_diff_algo(9) << "\n";

    // Using recursion
    Tree.insert_using_recursion(&Tree.root, 15);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 10);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 20);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 25);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 8);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 12);
    Tree.Print(Tree.root);
    cout << "\n";
    Tree.insert_using_recursion(&Tree.root, 17);
    Tree.Print(Tree.root);
    cout << "\n";
    
    cout << Tree.Search_using_recursion(Tree.root, 15) << "\n";
    cout << Tree.Search_using_recursion(Tree.root, 8) << "\n";
    cout << Tree.Search_using_recursion(Tree.root, 30) << "\n";
    cout << Tree.Search_using_recursion(Tree.root, 9) << "\n";
    return 0;
}