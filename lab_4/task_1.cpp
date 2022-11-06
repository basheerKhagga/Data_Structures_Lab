#include <iostream>
using namespace std;

class employee
{
private:
public:
    int Emp_ID;
    string Emp_Name;
    string NIC;
    int Salary;
    int Bonus;
    employee(int value_ID = 0, string value_Name = "",
             string value_NIC = "",
             int value_Salary = 0,
             int value_Bonus = 0)
    {
        Emp_ID = value_ID;
        Emp_Name = value_Name;
        NIC = value_NIC;
        Salary = value_Salary;
        Bonus = value_Bonus;
    }

    employee(const employee &m)
    {
        Emp_ID = m.Emp_ID;
        Emp_Name = m.Emp_Name;
        NIC = m.NIC;
        Salary = m.Salary;
        Bonus = m.Bonus;
    }

    void display()
    {
        cout << "\n\nEmp_ID = " << Emp_ID;
        cout << "\tEmp_Name = " << Emp_Name;

        cout << "\tNIC = " << NIC;

        cout << "\tSalary = " << Salary;

        cout << "\tBonus = " << Bonus;
    }
};

class node
{

public:
    employee data;
    node *next;

    node() { next = NULL; }
    ~node();
};

node::~node()
{
}

class Queue
{
private:
    node *head;
    node *last;

public:
    Queue(/* args */)
    {
        head = NULL;
        last = NULL;
    }

    void insert(const employee &data)
    {
        node *temp = new node;
        temp->data.Emp_ID = data.Emp_ID;
        temp->data.Emp_Name = data.Emp_Name;
        temp->data.NIC = data.NIC;
        temp->data.Salary = data.Salary;
        temp->data.Bonus = data.Bonus;

        if (head == NULL && last == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    bool isEmpty()
    {
        if (head == NULL && last == NULL)
            return true;
        return false;
    }

    void display()
    {
        node *temp = head;
        while ((temp->next != NULL))
        {
            temp->data.display();
            temp = temp->next;
        }
        temp->data.display();
    }

    void updateSalary(const int &salary, int id)
    {
        node *temp = head;

        while (temp->data.Emp_ID != id && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            temp->data.Salary = salary;
        }
        else
        {
            if (temp->data.Emp_ID == id)
            {
                temp->data.Salary = salary;
            }
        }
    }

    void updateBonus(const int &bonus, int id)
    {
        node *temp = head;

        while (temp->data.Emp_ID != id && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            temp->data.Bonus = bonus;
        }
        else
        {
            if (temp->data.Emp_ID == id)
            {
                temp->data.Bonus = bonus;
            }
        }
    }

    void remove(int id)
    {
        node *temp = head;
        if (head->data.Emp_ID == id)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        else
        { // int i = 0;
            node *prev = NULL;

            while (temp->data.Emp_ID != id && temp->next != NULL)
            {
                // cout<<endl<<i++;
                prev = temp;
                temp = temp->next;
            }
            if (temp->next)
            {
                prev->next = temp->next;
                delete temp;
                // temp->next = prev->next;
            }
            else
            {
                prev->next = NULL;
                last = prev;
            }
        }
    }

    void sort()
    {
        node *curr = head->next;
        node *prev = head;
        bool isSorted = false;
        while (curr)
        {
            isSorted = false;

            // every time a bigger node is in wrong place insert that node in the end
            // and remove it from its previous position
            // do this until list is sorted
            if (curr->data.Salary < prev->data.Salary)
            {
                isSorted = true;
                insert(prev->data);
                remove(prev->data.Emp_ID);
            }
            // if there was a replace we have to bubble the small value to the start
            if (isSorted)
            {
                curr = head->next;
                prev = head;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void clear()
    {
        node *current = head;
        employee temp;

        while (current != NULL)
        {
            current->data = temp;
            current = current->next;
        }

        // cout<<endl<<"dsgagsfasgfgafgafdf"<<head;
        // delete head;
        // delete last;
        // last = NULL;
    }

    ~Queue() {}
};

int main()
{
    employee obj1(0, "khagga", "3135656", 500, 200);
    employee obj2(1, "khagga", "3135656", 500, 200);
    employee obj3(2, "khagga", "3135656", -10, 200);
    employee obj4(3, "khagga", "3135656", 1500, 200);

    Queue singlyList;

    singlyList.insert(obj1);
    singlyList.insert(obj2);
    singlyList.insert(obj3);
    singlyList.insert(obj4);
    singlyList.display();

    cout << endl;
    system("pause");
    system("CLS");

    singlyList.remove(2);
    singlyList.insert(obj4);
    singlyList.insert(obj4);
    singlyList.updateBonus(500, 1);
    singlyList.updateSalary(4500, 3);

    // singlyList.updateSalary(1500, 0);

    // singlyList.clear();
    // singlyList.display();

    // singlyList.insert(obj1);
    // singlyList.insert(obj2);
    // singlyList.insert(obj3);
    // singlyList.insert(obj4);
    // singlyList.remove(3);
    // singlyList.insert(obj4);

    singlyList.sort();
    singlyList.display();

    cout << endl;
    system("pause");
    system("CLS");

    singlyList.clear();
    singlyList.display();
}

// public:
// void add(double value) {head = add(head, value);} 
// // Recursive implementations 
// private:
// ListNode *add(ListNode *aList, double value); 

// NumberList2::ListNode *NumberList2::add(ListNode *aList, double value)
// {
//     if (aList == NULL)
//         return new ListNode(value);
//     else
//     {
//         // Split into constituent head and tail
//         ListNode *tail = aList->next;
//         // tail
//             aList->next = NULL;
//         // Detached head
//         // Recursively add value to tail
//                 ListNode *biggerTail = add(tail, value);
//         // Reattach the head

//             aList->next = biggerTail;
//         //Return pointer to head of bigger list 
//         return aList;
//     }
// }