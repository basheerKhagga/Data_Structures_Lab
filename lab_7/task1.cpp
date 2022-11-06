#include <iostream>
using namespace std;

class Plate
{
public:
    char data;
    Plate *next;
    Plate(int gvdata = 0, Plate *gvnext = NULL)
    {
        data = gvdata;
        next = gvnext;
    }
};

class stack
{
private:
    Plate *head;
    int totalCount;
    int total;

public:
    stack(int gvTotal = 5)
    {
        head = NULL;
        totalCount = 0;
        total = gvTotal;
    }

    bool isFull()
    {
        if (totalCount == total)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }

        return false;
    }

    void Push(char element)
    {
        if (isFull())
        {
            cout << "\n[-] Cannot add anymore elements \n[-] Stack is full";
        }
        else if (isEmpty())
        {
            totalCount++;
            head = new Plate(element);
        }
        else
        {
            totalCount++;
            head = new Plate(element, head);
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "\n [-]Stack is empty";
        }
        else
        {
            totalCount--;
            Plate *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void printStack()
    {
        Plate *temp = head;
        while (temp)
        {
            cout << "\n[+] Data inside Plate is : " << temp->data;
            temp = temp->next;
        }
    }

    void Peak()
    {
        if (isEmpty())
        {
            cout << "\n[-] Peak is empty";
        }
        else
            cout << "\n[+] Value at top is : " << head->data;
    }

    void clear()
    {
        while (!isEmpty())
        {
            Pop();
        }
    }

    ~stack()
    {
        while (!isEmpty())
        {
            Pop();
        }
    }
};

bool isStringCorrect(string gvData)
{
    stack objStack(gvData.length() + 1);

    
    for (int i = 0; i < gvData.length() + 1; i++)
    {
        if (gvData[i] == '(' || gvData[i] == '{' || gvData[i] == '[')
        {

            objStack.Push(gvData[i]);
        }
        else if (gvData[i] == ')' || gvData[i] == '}' || gvData[i] == ']')
        {
            objStack.Pop();
        }
    }

    if (objStack.isEmpty())
    {
        cout << "\n[+] Expression is correct";
        return true;
    }
    else
        cout << "\n[+] Expression is False";

    return false;
}

int main()
{
    string first = "1 + 2 * (3 / 4)";
    string second = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14";
    string third = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14";

    isStringCorrect(first);
    isStringCorrect(second);
    isStringCorrect(third);

    stack objStack;
    objStack.Push('a');
    objStack.Push('b');
    objStack.Push('c');
    objStack.Push('d');
    objStack.Push('e');

    objStack.clear();

    objStack.Push('a');
    objStack.Push('b');
    objStack.Push('c');
    objStack.Push('d');
    objStack.Push('e');

    objStack.Peak();
    objStack.printStack();
}
