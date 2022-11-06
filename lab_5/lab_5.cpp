#include <iostream>
using namespace std;

class Student
{
private:
public:
    string Student_ID;
    string Student_Name;
    double GPA;
    int age;
    Student(string value_ID = "",
            string value_name = "",
            double value_GPA = 0,
            int value_age = 0)
    {
        Student_ID = value_ID;
        Student_Name = value_name;
        GPA = value_GPA;
        age = value_age;
    }

    Student(const Student &m)
    {
        Student_ID = m.Student_ID;
        Student_Name = m.Student_Name;
        GPA = m.GPA;
        age = m.age;
    }

    void display()
    {
        cout << "\nEmp_Name = " << Student_ID;

        cout << "\tNIC = " << Student_Name;

        cout << "\tSalary = " << GPA;

        cout << "\tBonus = " << age;
    }
};

class node
{

public:
    Student data;
    node *next;
    node *prev;

    node() { next = NULL; }
    ~node();
};

node::~node()
{
}

class List
{
private:
    node *head;
    node *last;

public:
    List(/* args */)
    {
        head = NULL;
        last = NULL;
    }

    void insert(const Student &data)
    {
        node *temp = new node;
        temp->data.Student_ID = data.Student_ID;
        temp->data.Student_Name = data.Student_Name;
        temp->data.GPA = data.GPA;
        temp->data.age = data.age;

        if (head == NULL && last == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
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

    void updateGPA(const double &GPA, string id)
    {
        node *temp = head;

        while (temp->data.Student_ID != id && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            temp->data.GPA = GPA;
        }
        else
        {
            if (temp->data.Student_ID == id)
            {
                temp->data.GPA = GPA;
            }
        }
    }


    void remove(string id)
    {
        node *temp = head;
        if (head->data.Student_ID == id)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        else
        { // int i = 0;
            

            while (temp->data.Student_ID != id && temp->next != NULL)
            {
                // cout<<endl<<i++;
                temp = temp->next;
            }
            if (temp->next)
            {
                
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                // temp->next = prev->next;
            }
            else
            {
                if (temp->data.Student_ID == id)
                {
                    last = temp->prev;
                    temp->prev->next = NULL;
                    delete temp; 
                }
                
                // temp->prev->next = NULL;
                // delete temp; 
            }
        }
    }

    void sort()
    {
        if (head == NULL)
        {
            return;
        }
        

        node *curr = head->next;
        
        bool isSorted = false;
        while (curr)
        {
            isSorted = false;

            // every time a bigger node is in wrong place insert that node in the end
            // and remove it from its previous position
            // do this until list is sorted
            if (curr->data.GPA < curr->prev->data.GPA)
            {
                isSorted = true;
                insert(curr->prev->data);
                remove(curr->prev->data.Student_ID);
            }
            // if there was a replace we have to bubble the small value to the start
            if (isSorted)
            {
                curr = head->next;
                
            }
            else
            {
                
                curr = curr->next;
            }
        }
    }

    void clear()
    {
        node *current = head;
        Student temp;

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

    ~List() {}
};

int main()
{
    Student obj1("i211556", "Dawson", 3.77, 18);
    Student obj2("i211557", "Ahmad", 1.2, 20);
    Student obj3("i211558", "Shapper", 3.6, 21);
    Student obj4("i211559", "Hareem", 2.2, 22);

    List singlyList;

    singlyList.insert(obj1);
    singlyList.insert(obj2);
    singlyList.insert(obj3);
    singlyList.insert(obj4);
    singlyList.remove("i211556");

    singlyList.updateGPA(3.4, "i211557");

    singlyList.sort();

    // singlyList.remove("i211557");

    singlyList.display();

    cout << endl;
    system("pause");
    system("CLS");

    // singlyList.insert(obj4);
    // singlyList.insert(obj4);
    // singlyList.updateBonus(500, 1);
    // singlyList.updateSalary(4500, 3);

    // singlyList.updateSalary(1500, 0);

    // singlyList.clear();
    // singlyList.display();

    // singlyList.insert(obj1);
    // singlyList.insert(obj2);
    // singlyList.insert(obj3);
    // singlyList.insert(obj4);
    // singlyList.remove(3);
    // singlyList.insert(obj4);

    // singlyList.sort();
    // singlyList.display();

    // cout << endl;
    // system("pause");
    // system("CLS");
    int si = 0;
    for (int i = 0; i <= 3; i++)
    {
        /* code */
        for (int j = i; j <= 8; j+=2)
        {
            for(int k = j; k >= i; k--){
                si++;
                cout<<endl<<si;
            }
        }
        cout<<"\nkhatam"; 
    }
    

    singlyList.clear();
    singlyList.display();
}
