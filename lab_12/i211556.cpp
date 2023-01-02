#include <iostream>
#include <string>

using namespace std;

class Heap
{
private:
    int *array;
    int capacity;
    int currentIndex;
    void insert(int i)
    {
        if (i <= 1)
        {
            return;
        }

        if (array[i / 2] < array[i])
        {
            cout << endl
                 << array[i / 2] << " > " << array[i];
            unsigned int temp = array[i / 2];
            array[i / 2] = array[i];
            array[i] = temp;
        }
        insert(i / 2);
    }

public:
    Heap(int size = 1)
    {
        if (size < 1)
        {
            size = 1;
        }
        capacity = size;
        currentIndex = 0;
        array = new int[capacity];
    }

    void insertion(int element)
    {
        currentIndex++;
        if (currentIndex >= capacity)
        {
            currentIndex--;
            cout<<"\n[-] Capacity reached";
            return;
        }
        array[currentIndex] = element;
        insert(currentIndex);
    }

    bool isHeap(int *array, int size)
    {
        bool isTrue = true;
        if (size <= 1)
        {
            return true;
        }
        else if (array[size / 2] < array[size])
        {
            return false;
        }

        isTrue = isHeap(array, size - 1);

        return isTrue;
    }

    void heapify(int *array, int currentIndex)
    {
        while (!isHeap(array, currentIndex))
        {
            for ( int i = currentIndex; i > 1; i--)
            {
                if (array[i / 2] < array[i])
                {
                    cout << endl
                         << array[i / 2] << " < " << array[i];
                    int temp = array[i / 2];
                    array[i / 2] = array[i];
                    array[i] = temp;
                }
            }
        }
    }

    void remove()
    {

        if (currentIndex < 1)
        {
            cout<<"No value in root";
            return;
        }
        
        int i = currentIndex;
        // for (i = current_size - 1; i > 0; i--)
        // {
        //     if (array[i] != -1)
        //     {
        //         break;
        //     }
        // }

        array[1] = array[i];
        array[i] = -1;
        currentIndex--;
        i = 1;

        for (int i = 1; (2 * i <= currentIndex && 2 * i + 1 <= currentIndex);)
        {
            
            // cout << endl <<"deletion " 
            //          << array[i] << " < " << max(array[2 * i], array[2 * i + 1]);
            if (array[i] < max(array[2 * i], array[2 * i + 1]))
            {
                cout << endl 
                     << array[i] << " < " << max(array[2 * i], array[2 * i + 1]);
                if (array[2 * i] < array[2 * i + 1])
                {
                    int temp = array[2 * i];
                    array[2 * i] = array[i];
                    array[i] = temp;
                    i *= 2;
                }
                else
                {
                    int temp = array[2 * i + 1];
                    array[2 * i + 1] = array[i];
                    array[i] = temp;
                    i = 2 * i + 1;
                }
            }
            else
                break;
        }
    }

    void print()
    {
        cout<<"\n\n";
        for (int i = 1; i < currentIndex + 1; i++)
        {
            cout<<"\t"<<array[i];
        }
        
    }

    ~Heap()
    {
        delete[] array;
    }
};

using namespace std;
int main()
{
    Heap obj(5);
    obj.insertion(10);
    obj.insertion(50);
    obj.insertion(60);
    obj.insertion(55);
    obj.insertion(10);
    obj.print();


    obj.remove();
    obj.print();

    
    int heapifythis[] = {5, 9, 8, 7, 6, 2, 15, 99, 20};
    obj.heapify(heapifythis, 9-1);
    cout<<endl;
    for (int i = 1; i < 9; i++)
    {
        cout<<"\t"<<heapifythis[i];
    }
    
}
