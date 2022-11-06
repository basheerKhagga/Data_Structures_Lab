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
    static int counter;
    int priority;

    node() { next = NULL; }
    void increment()
    {
        counter++;
        this->priority = counter;
    }
    ~node();
};

int node::counter = 0;

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

    void Enqueue(const Student &data)
    {
        
        node *temp = new node;
        temp->data.Student_ID = data.Student_ID;
        temp->data.Student_Name = data.Student_Name;
        temp->data.GPA = data.GPA;
        temp->data.age = data.age;
        temp->increment();

        if (head == NULL)
        {
            last = NULL;
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
        if (head == NULL)
        {
            return;
        }
        

        node *temp = head;
        
        while ((temp->next != NULL))
        {
            temp->data.display();
            temp = temp->next;
        }
        temp->data.display();
    }

   

    void remove()
    {
        node *temp = head;
        if (temp != NULL )
        {
            temp = head->next;
            delete head;
            head = temp;
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

       
    }

     void remove(int id)
    {
        node *temp = head;
        if (head->priority == id)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        else
        { // int i = 0;
            node *prev = NULL;

            while (temp->priority != id && temp->next != NULL)
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
                if ( temp->priority == id)
                {
                    prev->next = NULL;
                    last = prev;
                }
                
                
            }
        }
    }

    void PriorityBasedDequeue()
    {
        if (isEmpty())
        {
            return;
        }
        
        node * temp = head;
        int max = temp->priority;
        while(temp != NULL)
        {
            if (max < temp->priority)
            {
                max = temp->priority;
            }
            
            
            temp = temp->next;
        }

        if (head != NULL)
        {
            remove(max);

        }
        
    }   

    node * FRONT()
    {
        if (head != NULL)
        {
            /* code */
        head->data.display();

        }
        
        return head;
    }

    node * REAR()
    {
        if (last != NULL && head != NULL)
        {
            /* code */
                last->data.display();


        }
        return last;
    }

    ~Queue() {
        
        
        node * temp = head;
        while (head != NULL)
        {
            delete temp;
            head = head->next;
            temp = head;
        }
        
    }
};

int main()
{
    Student obj1("i211556", "Dawson", 3.77, 18);
    Student obj2("i211557", "Ahmad", 1.2, 20);
    Student obj3("i211558", "Shapper", 3.6, 21);
    Student obj4("i211559", "Hareem", 2.2, 22);

    Queue singlyList;

    cout<<"\n adding in list";
    singlyList.Enqueue(obj1);
    singlyList.Enqueue(obj2);
    singlyList.Enqueue(obj3);
    singlyList.Enqueue(obj4);
    singlyList.Enqueue(obj4);
    cout<<"\n added in list";

    cout << endl;
    system("pause");
    system("CLS");

    singlyList.display();

    
    cout << endl;
    system("pause");
    system("CLS");

    cout<<"\n deleting in list";
    singlyList.PriorityBasedDequeue();
    singlyList.PriorityBasedDequeue();
    singlyList.PriorityBasedDequeue();

    singlyList.PriorityBasedDequeue();
    singlyList.remove();

    cout<<"\n deleted all items in list";
    cout<<"\n adding in list";


    singlyList.Enqueue(obj1);
    singlyList.Enqueue(obj2);
    singlyList.Enqueue(obj3);
    singlyList.Enqueue(obj4);


    cout<<"\n displaying last and first";
    singlyList.FRONT();
    singlyList.REAR();

    cout<<"\n clearing the list";

    cout << endl;
    system("pause");
    system("CLS");


    singlyList.clear();

    


    // singlyList.remove("i211557");

    singlyList.display();

    

    cout << endl;
    system("pause");
    system("CLS");

    


    // cout << endl;
    // system("pause");
    // system("CLS");

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

    
   

    // singlyList.clear();
    // singlyList.display();
}
