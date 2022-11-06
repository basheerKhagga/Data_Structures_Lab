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
        cout<<"\n[+] Breadthwise traversal : ";
        queue<TreeNode *> list;
        list.push(root);
        while (!list.empty())
        {
            TreeNode *temp = list.front();
            cout <<" "<< temp->data;
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
    }

    ~BST() {}

    // functions not for practice task
private:
    // functions for lab
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
    // BST tree;
    // int array[] = {11,
    //                13,
    //                16,
    //                1,
    //                9,
    //                4, 7,
    //                10,
    //                19};

    // for (int i = 0; i < 9; i++)
    // {
    //     tree.insert(array[i]);
    // }

    // cout << "\n[+] Printing inorder traversal of object tree";
    // tree.inorder(tree.root);
    // int input = 16;
    // // cout << "\n Successor of which element? -> ";
    // // cin >> input;
    // cout << "\n[+] Successor of " << input << " -> " << tree.getSuccessor(input) << endl;
    // cout << "\n[+] Deleting " << input << " through successor " << endl;
    // tree.deleteNode(input, tree.root);
    // tree.inorder(tree.root);

    // BST invalidBst;
    // invalidBst.insert(11);
    // invalidBst.insert(9);
    // invalidBst.insert(4);
    // invalidBst.insert(5);
    // invalidBst.insert(6);
    // invalidBst.insert(3);
    // invalidBst.insert(29);
    // invalidBst.insert(16);
    // invalidBst.insert(18);
    // invalidBst.insert(15);
    // invalidBst.insert(20);
    // invalidBst.root->left->right = new TreeNode(50);

    // cout << "\n[+] Printing inorder traversal of object invalidBst";
    // invalidBst.inorder(invalidBst.root);
    // cout << "\n[+] Checking validity of object invalidBST";
    // (invalidBst.isValid(invalidBst.root)) ? cout << "\nTree is valid" : cout << "\nInvalid";

    // cout << "\n[+] Checking validity of object tree";
    // (tree.isValid(tree.root)) ? cout << "\nTree is valid" : cout << "\nInvalid";

    // const int size = 11;
    // int array1[size] = {3, 6, 5, 4, 9, 15, 20, 18, 16, 29, 11};
    // BST postorder;
    // postorder.postorderInsertion(array1, 0, size);
    // cout << "\n[+] Printing postorder traversal";
    // postorder.postorder(postorder.root);
    // cout << "\n[+] Printing in inorder traversal";
    // postorder.inorder(postorder.root);



    BST full;
    full.insert(8);
    full.insert(5);
    full.insert(9);
    full.insert(4);
    full.insert(6);

    if (full.isFull(full.root))
    {
        cout << "\n[+] Tree is Full" ;
    }
    else 
        cout << "\n[-] Tree is not Full";
    
        
    BST degenerate;    
    degenerate.insert(8);
    degenerate.insert(5);
    degenerate.insert(4);
    degenerate.insert(1);
    degenerate.isDegenerate(degenerate.root)? cout << "\n[+] Tree is degen" : cout << "\n[-] Tree is not degen";   

    BST Perfect;
    Perfect.insert(8);
    Perfect.insert(5);
    Perfect.insert(4);
    // Perfect.insert(3);
    Perfect.insert(6);
    Perfect.insert(10);
    Perfect.insert(9);
    Perfect.insert(11);
    Perfect.perfectionCheck()? cout << "\n[+] Tree is Perfect" : cout << "\n[-] Tree is not Perfect";   

    BST Balanced;
    Balanced.insert(8);
    Balanced.insert(5);
    Balanced.insert(4);
    // Perfect.insert(3);
    Balanced.insert(6);
    Balanced.insert(10);
    Balanced.insert(9);
    Balanced.insert(11);
    Balanced.isBalanced(Balanced.root)? cout << "\n[+] Tree is Balanced" : cout << "\n[-] Tree is not Balanced";

    Balanced.breadthwise();
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
