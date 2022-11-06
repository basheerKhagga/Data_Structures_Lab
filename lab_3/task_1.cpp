#include <iostream>
using namespace std;

class list
{
private:
    int *array;
    int size;

public:
    list(int given_size = 0)
    {
        this->size = given_size;
        array = new int[size];
    }

    void inserAtEnd(int element)
    {

        int *temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;

        size = size + 1;
        array = new int[size];
        for (int i = 0; i < size - 1; i++)
        {
            array[i] = temp[i];
        }
        array[size - 1] = element;
        delete[] temp;
    }

    void insertAtStart(int element)
    {
        int *temp = new int[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i + 1] = array[i];
        }
        delete[] array;
        size = size + 1;
        array = new int[size];
        for (int i = 1; i < size; i++)
        {
            array[i] = temp[i];
        }
        array[0] = element;
        delete[] temp;
    }

    void insertInMiddle(int index, int element)
    {
        if (index >= size || index < 0)
        {
            cout << "\n-> Invalid input";
        }
        else
        {
            int *temp = new int[size + 1];
            int shift = 0;
            for (int i = 0; i < size + 1; i++)
            {
                if (i == index)
                {
                    i++;
                }
                
                temp[i] = array[shift++];

            }
            delete[] array;
            temp[index] = element;
            size = size + 1;

            array = new int[size];
            for (int i = 0; i < size ; i++)
            {
                array[i] = temp[i];
            }
            
            // array = temp;
            // array[index] = element;

            // array = new int[size];
            
            // array[size - 1] = element;
            // delete[] temp;
        }
    }

    void removeAtIndex(int index)
    {
        if (isEmpty() || index >= size )
        {
            cout << "\n->Invalid Input";
        }
        else
        {
            size = size -1;
            int *temp = new int[size ];
            int shift = 0;
            for (int i = 0; i < size+1; i++)
            {
                if (i == index)
                {
                    i++;
                }
                temp[shift++] = array[i];
            }
            delete[] array;
            array = temp;
            
        }
    }

    void removeAtStart()
    {
        if (isEmpty())
        {
            cout << "\n->Size is zero";
        }
        else
        {
            int *temp = new int[size - 1];

            for (int i = 1; i < size; i++)
            {
                temp[i - 1] = array[i];
            }
            delete[] array;
            size = size - 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = temp[i];
            }

            delete[] temp;
        }
    }

    void removeAtEnd()
    {
        if (isEmpty())
        {
            cout << "\n->Size is zero";
        }
        else
        {
            int *temp = new int[size - 1];

            for (int i = 0; i < size - 1; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            size = size - 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = temp[i];
            }

            delete[] temp;
        }
    }

    void printinglist()
    {
        cout << endl
             << "Printing list\n";
        for (int i = 0; i < size; i++)
        {
            cout << "\t" << array[i];
        }
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        bool empty = false;
        for (int i = 0; i < size; i++)
        {
            if (array[i] != 0)
            {
                return false;
            }
            else 
                empty = true;
            
        }
        

        return empty;
    }

    void Replace(int index, int value)
    {
        if (isEmpty() || index >= size || index < 0)
        {
            cout << "\n->Invalid Input";
        }
        else
            array[index] = value;
    }

    void clearTheList()
    {
        size = 0;
        delete[] array;
    }

    void sort()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size ; j++)
            {
                if (array[i] < array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                
            }
            
        }
        
    }

    int search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == value)
                return i;
        }
        return -1;
    }

    bool duplicateElement()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                    if(i != j && array[i] == array[j])
                        return true;
            }
            
        }
        return false;
    }

    int next(int index)
    {
        int result = -1;
        if (isEmpty() || index >= size -1 || index < 0)
        {
            cout<<"\n->Invalid Input";
        }
        else 
            result = array[index + 1];
        return result;
    }

    int previous(int index)
    {
        int result = -1;
        if (isEmpty() || index >= size || index < 1)
        {
            cout<<"\n->Invalid Input";
        }
        else 
            result = array[index - 1];
        return result;
    }

    int *getArray()
    {
        return this->array;
    }
};

int main()
{
    list temp;
    cout<<"\nInserting elements : ";
    temp.inserAtEnd(5);
    temp.inserAtEnd(4);
    temp.insertAtStart(3);
    temp.insertAtStart(7);
    temp.inserAtEnd(4);
    temp.insertAtStart(3);
    temp.insertInMiddle(1, 10);

    temp.printinglist();

    // cout<<"\nRemoving elements : ";

    // temp.removeAtStart();
    // temp.removeAtEnd();
    // temp.removeAtIndex(2);
    
    // temp.printinglist();
    // temp.sort();
    // cout<<endl<<temp.search(10);
    // cout<<endl<<temp.duplicateElement();
    
    // cout<<endl<<temp.next(2);
    // cout<<endl<<temp.previous(3);
    // temp.printinglist();
}
