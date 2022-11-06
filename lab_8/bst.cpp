#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int gvData = 0)
    {
        data = gvData;
        left = NULL;
        right = NULL;
    }
    ~TreeNode() {}
};

class BST
{

public:
    TreeNode *root;
    BST(/* args */)
    {
        root = NULL;
    }

    void insert(int gvData)
    {
        if (root == NULL)
        {
            root = new TreeNode(gvData);
        }
        else
        {
            TreeNode *current = root;
            TreeNode *prev = NULL;
            while (current)
            {
                if (gvData < current->data)
                {
                    prev = current;
                    current = current->left;
                }
                else if (gvData > current->data)
                {
                    prev = current;
                    current = current->right;
                }
                else
                {
                    // if it is equal drop it
                    return;
                }
            }

            if (gvData < prev->data)
            {
                prev->left = new TreeNode(gvData);
            }
            else if (gvData > prev->data)
            {
                prev->right = new TreeNode(gvData);
            }
        }
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }

    void inorder(TreeNode *p)
    {
        if (p != NULL)
        {
            inorder(p->left);
            cout << "\n Value -> " << p->data;
            inorder(p->right);
        }
    }

    void max()
    {
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        if (curr->left == NULL && curr->right == NULL)
        {
            cout << "\nMax is " << curr->data;
        }
        else
        {
            while (curr)
            {
                prev = curr;
                curr = curr->right;
            }
            cout << "\nMax is " << prev->data;
        }
    }

    void min()
    {
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        if (curr->left == NULL && curr->right == NULL)
        {
            cout << "\nMin is " << curr->data;
        }
        else
        {
            while (curr)
            {
                prev = curr;
                curr = curr->left;
            }
            cout << "\nMin is " << prev->data;
        }
    }

    bool search(int gvdata)
    {
        TreeNode *curr = root;
        TreeNode *prev = NULL;

        while (curr)
        {
            if (gvdata < curr->data)
            {
                prev = curr;
                curr = curr->left;
            }
            else if (gvdata > curr->data)
            {
                prev = curr;
                curr = curr->right;
            }
            else
            {
                cout << "\nValue -> " << curr->data;
                return true;
            }
        }
        return false;
    }

    ~BST() {}
};

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(13);
    tree.insert(16);
    tree.insert(18);
    tree.insert(14);

    tree.search(13);
    tree.max();
    tree.min();

    tree.inorder(tree.root);
}
