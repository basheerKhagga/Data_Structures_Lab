#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int given = 0, Node *givenptr = NULL)
    {
        data = given;
        next = givenptr;
    }

    ~Node() {}
};

class singlyList
{
private:
    Node *head;
    Node *tail;

public:
    singlyList(Node *gvhead = NULL, Node *gvtail = NULL)
    {
        head = gvhead;
        tail = gvtail;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

    void insertAtEnd(int givendat)
    {

        Node *temp = new Node(givendat);
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void removeFromEnd()
    {
        if (isEmpty())
        {
            cout << "\nList is empty";
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            tail = prev;
            delete curr;
        }
    }

    int findMid()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            int total = 0;
            Node *curr = head;
            while (curr)
            {
                total++;
                curr = curr->next;
            }

            total = total / 2;
            int temp = 0;
            curr = head;
            while (curr)
            {
                temp++;
                if (temp == total)
                {

                    break;
                }

                curr = curr->next;
            }
            return total;
        }
    }

    singlyList *split()
    {
        if (isEmpty())
        {
            return NULL;
        }

        int mid = findMid();

        Node *curr = head;
        int temp;
        while (curr)
        {
            temp++;
            if (temp == mid)
            {
                singlyList *sLtemp = new singlyList(curr->next, tail);
                tail = curr;
                curr->next = NULL;

                return sLtemp;
            }
            curr = curr->next;
        }
        return NULL;
    }

    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << "\nData in node : " << curr->data;
            curr = curr->next;
        }
    }
    ~singlyList()
    {
        while (!isEmpty())
        {
            removeFromEnd();
        }
    }
};

int main()
{
    singlyList list;
    for (int i = 1; i < 9; i++)
    {
        list.insertAtEnd(i);
    }
    list.print();
    cout<<"\nEnd of printing---------";
    cout <<"\nMid value : "<<list.findMid();

    singlyList *newList = list.split();
    newList->print();
    list.print();
}
