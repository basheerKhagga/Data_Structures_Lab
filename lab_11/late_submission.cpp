#include <iostream>
#include <queue>
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

    // Functions for practice task
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

    void avlInsert(int gvData)
    {
        if (!insersion(root, gvData))
        {
            cout << "\n[-] Same value cannot be inserted!";
        }
    }

    bool insersion(TreeNode *&p, int data)
    {
        bool isTrue = false;
        if (p == NULL)
        {
            p = new TreeNode(data);
            return true;
        }
        else if (data > p->data)
        {
            isTrue = insersion(p->right, data);
        }
        else if (data < p->data)
        {
            isTrue = insersion(p->left, data);
        }
        else
            return false;

        if (isTrue == false)
            return isTrue;

        BalanceTheTree(p, data);

        return true;
    }

    void BalanceTheTree(TreeNode *&p, int data)
    {
        if (p != NULL)
        {
            int nodeBal = getheight(p->left) - getheight(p->right);
            if (nodeBal < -1)
            {
                if (data < p->right->data)
                {
                    R(p->right);
                    L(p);
                }
                else
                {
                    L(p);
                }
            }
            else if (nodeBal > 1)
            {
                if (data > p->left->data)
                {
                    L(p->left);
                    R(p);
                }
                else
                {
                    R(p);
                }
            }
        }
    }

    void R(TreeNode *&p)
    {
        TreeNode *curr = p;
        TreeNode *lft = p->left;
        TreeNode *lftsri8 = lft->right;

        lft->right = curr;
        curr->left = lftsri8;
        p = lft;
    }

    void L(TreeNode *&p)
    {
        TreeNode *curr = p;
        TreeNode *ri8 = p->right;
        TreeNode *ri8sleft = ri8->left;

        ri8->left = curr;
        curr->right = ri8sleft;
        p = ri8;
    }

    TreeNode *minimum(TreeNode *p)
    {
        if (p == nullptr)
        {
            return p;
        }

        while (p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }

    int NotBstmax(TreeNode *iterator)
    {
        if (iterator != NULL)
        {
            int value1 = NotBstmax(iterator->left);
            int value2 = NotBstmax(iterator->right);
            if (iterator->data > value1)
                if (iterator->data > value2)
                    return iterator->data;
                else
                    return value2;
            else if (value1 > value2)
                return value1;
            else
                return value2;
        }
        return INT_MIN;
    }

    int NotBstmin(TreeNode *iterator)
    {
        if (iterator != NULL)
        {
            int value1 = NotBstmin(iterator->left);
            int value2 = NotBstmin(iterator->right);
            if (iterator->data < value1)
                if (iterator->data < value2)
                    return iterator->data;
                else
                    return value2;
            else if (value1 < value2)
                return value1;
            else
                return value2;
        }
        return INT_MAX;
    }

    bool isValid(TreeNode *p)
    {
        bool istrue = true;
        if (p != NULL)
        {
            int max = NotBstmax(p->left);  // p k left subtree ki max value
            int min = NotBstmin(p->right); // p k ri8 subtree ki min value
            if ((p->left != NULL && p->right != NULL) && (p->data > min || p->data < max))
            {
                istrue = false;
            }
            else if ((p->left == NULL && p->right == NULL))
            {
                istrue = true;
            }
            else if (p->left == NULL && p->data > min)
            {
                istrue = false;
            }
            else if (p->right == NULL && p->data < max)
            {
                istrue = false;
            }

            if (istrue)
            {
                istrue = isValid(p->left);
                if (istrue)
                {
                    istrue = isValid(p->right);
                }
            }
        }

        return istrue;
    }

    int getSuccessor(int key)
    {
        TreeNode *temp = inorderSuccessor(root, nullptr, key);

        if (temp)
        {
            return temp->data;
        }

        return -1;
    }

    bool isDegenerate(TreeNode *p)
    {
        bool istrue = true;
        if (p != NULL)
        {
            if (p->left != NULL && p->right != NULL)
            {
                istrue = false;
            }

            if (istrue)
            {
                istrue = isDegenerate(p->left);
                if (istrue)
                {
                    istrue = isDegenerate(p->right);
                }
            }
        }
        return istrue;
    }

    bool isBalanced(TreeNode *p)
    {
        bool istrue = true;
        if (p != NULL)
        {
            int diff = getheight(p->left) - getheight(p->right);
            if (diff < 0)
                diff *= -1;
            if (diff > 1)
            {
                istrue = false;
            }

            if (istrue)
            {
                istrue = isBalanced(p->left);
                if (istrue)
                {
                    istrue = isBalanced(p->right);
                }
            }
        }
        return istrue;
    }

    bool isPerfect(TreeNode *p, int height)
    {
        bool istrue = true;
        if (!(height < 0))
        {
            if (p == NULL)
            {
                istrue = false;
            }
            else if (p->left == NULL && p->right != NULL)
            {
                istrue = false;
            }
            else if (p->right == NULL && p->left != NULL)
            {
                istrue = false;
            }

            if (istrue)
            {
                istrue = isPerfect(p->left, height - 1);
                if (istrue)
                {
                    istrue = isPerfect(p->right, height - 1);
                }
            }
        }

        return istrue;
    }

    bool perfectionCheck()
    {
        int h = retHeight();
        cout << "\nheight " << h;
        return isPerfect(root, h);
    }

    void breadthwise()
    {
        cout << "\n[+] Breadthwise traversal : ";
        queue<TreeNode *> list;
        list.push(root);
        while (!list.empty())
        {
            TreeNode *temp = list.front();
            cout << " " << temp->data;
            if (temp->left != NULL)
            {
                list.push(temp->left);
            }

            if (temp->right != NULL)
            {
                list.push(temp->right);
            }

            list.pop();
        }
    }

    bool isFull(TreeNode *p)
    {
        bool istrue = true;
        if (p != NULL)
        {
            if (p->left == NULL && p->right != NULL)
            {
                istrue = false;
            }
            else if (p->right == NULL && p->left != NULL)
            {
                istrue = false;
            }

            if (istrue)
            {
                istrue = isFull(p->left);
                if (istrue)
                {
                    istrue = isFull(p->right);
                }
            }
        }

        return istrue;
    }

    void postorderInsertion(int *arr, int start, int size)
    {
        if (size <= 0)
        {
            return;
        }
        int value = arr[size - 1];

        for (int j = start; j < size; j++)
        {
            if (arr[j] > value || arr[j] == value)
            {
                insert(value);
                postorderInsertion(arr, start, j);
                postorderInsertion(arr, j, size - 1);
                break;
            }
        }
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
            tempNodePtr = inorderSuccessor(root, nullptr, curr->data);

            tempNodePtr->left = curr->left;
            tempNodePtr = curr;
            curr = curr->right;
            delete tempNodePtr;
        }
    }

    TreeNode *inorderSuccessor(TreeNode *current, TreeNode *successor, int key)
    {
        if (current == NULL)
            return successor;

        if (key == current->data)
        {
            if (current->right != nullptr)
                return minimum(current->right);
        }

        else if (key < current->data)
        {
            successor = current;
            return inorderSuccessor(current->left, successor, key);
        }

        else
        {
            return inorderSuccessor(current->right, successor, key);
        }

        return successor;
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

    void postorder(TreeNode *p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << "\n Value -> " << p->data;
        }
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

        if (curr != NULL)
        {
            BalanceTheTree(curr, gvData);
        }
    }

    ~BST() {}

    // functions not for practice task
private:
    // functions for lab
    int getheight(TreeNode *ptr)
    {
        if (ptr == nullptr)
        {
            return -1;
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

    void preorder(TreeNode *p)
    {
        if (p != NULL)
        {
            cout << "\n Value -> " << p->data;
            preorder(p->left);
            preorder(p->right);
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
};

int main()
{

    BST avlTree;
    // avlTree.avlInsert(4);
    // avlTree.avlInsert(2);
    // avlTree.avlInsert(3);
    // avlTree.avlInsert(5);
    // avlTree.avlInsert(6);
    // avlTree.avlInsert(8);
    // avlTree.avlInsert(15);
    // avlTree.avlInsert(19);
    // avlTree.avlInsert(7);
    // avlTree.avlInsert(12);
    // avlTree.avlInsert(13);
    // avlTree.avlInsert(-1);
    // avlTree.avlInsert(-2);
    // avlTree.avlInsert(-3);
    // avlTree.avlInsert(-4);
    // avlTree.avlInsert(5);

    avlTree.avlInsert(20);
    avlTree.avlInsert(17);
    avlTree.avlInsert(25);
    avlTree.avlInsert(14);
    avlTree.avlInsert(18);

    avlTree.deleteNode(19, avlTree.root);

    (avlTree.isBalanced(avlTree.root)) ? cout << "\n[+] Tree is Balanced" : cout << "\n[-] Tree is not Balanced";
    avlTree.inorder(avlTree.root);
    avlTree.breadthwise();
}

// TreeNode * inorderinsertion(TreeNode *p, bool isTrue)
// {
//     if (p != NULL)
//     {
//         cout<<endl<<p->data;
//     }

//     if (p == NULL || isTrue == false)
//     {
//         return p;
//     }

//     TreeNode * lfty = inorderinsertion(p->left, false);
//     TreeNode * r8ty = inorderinsertion(p->right, false);

//     if (lfty)
//     {
//         p = inorderinsertion(lfty, true);
//     }

//     if (r8ty)
//     {
//         p = inorderinsertion(r8ty, true);
//     }

//     return p;
// }

// void insertasNotBST(int gvData)
// {
//     if (root == NULL)
//     {
//         root = new TreeNode(gvData);
//     }
//     else
//     {
//         inorderinsertion(root);
//     }
// }
