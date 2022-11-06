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

    void preorder(TreeNode *p)
    {
        if (p != NULL)
        {
            cout << "\n Value -> " << p->data;
            preorder(p->left);
            preorder(p->right);
        }
    }

    void postorder(TreeNode *p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << "\n Value -> " << p->data;
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

    int CountNodes(TreeNode *p, int count)
    {
        if (p != NULL)
        {
            count = CountNodes(p->left, count + 1);
            count = CountNodes(p->right, count);
        }

        return count;
    }

    int treeNodeCount()
    {
        int count = 0;
        count = CountNodes(root, count);
        return count;
    }

    int retHeight()
    {
        return getheight(root) - 1;
    }

    void deleteNode(int gvData, TreeNode *&curr)
    {

        if (curr == NULL)
            cout << gvData << "\n[-] Error: 404 not found";

        else if (gvData < curr->data)
            deleteNode(gvData, curr->left);

        else if (gvData > curr->data)
            deleteNode(gvData, curr->right);

        else
            makeDeletion(curr);
    }

    void makeDeletion(TreeNode *&curr)
    {
        TreeNode *tempNodePtr;

        if (curr->right == NULL)
        {
            tempNodePtr = curr;
            curr = curr->left;
            delete tempNodePtr;
        }

        else if (curr->left == NULL)
        {
            tempNodePtr = curr;
            curr = curr->right;
            delete tempNodePtr;
        }

        else
        {
            tempNodePtr = curr->right;
            while (tempNodePtr->left)
            {
                tempNodePtr = tempNodePtr->left;
            }

            tempNodePtr->left = curr->left;
            tempNodePtr = curr;
            curr = curr->right;
            delete tempNodePtr;
        }
    }

    ~BST() {}

private:
    int getheight(TreeNode *ptr)
    {
        if (ptr == nullptr)
        {
            return 0;
        }
        else
        {
            int lheight = getheight(ptr->left);
            int rheight = getheight(ptr->right);
            if (lheight > rheight)
            {
                return lheight + 1;
            }
            else
                return rheight + 1;
        }
    }
};

int main()
{
    BST tree;
    int array[] = {1, 4, 7,
                 9,
                 10,
                 11,
                 13,
                 16,
                 19};

    for (int i = 0; i < 9; i++)
    {
        tree.insert(i);
    }
    

    tree.search(13);
    cout << "\nMax value is ";
    tree.max();
    cout << "\nMin value is ";
    tree.min();

    tree.inorder(tree.root);
    cout << endl
         << "[+] Total number of nodes"
         << tree.treeNodeCount();
    cout << endl
         << "[+] Height of tree"
         << tree.retHeight();

    cout << "\n[-] Deleting 10 from tree";
    tree.deleteNode(10, tree.root);
    cout << "\n[-] Printing in preorder";

    tree.preorder(tree.root);
}
