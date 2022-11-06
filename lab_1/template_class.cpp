#include <iostream>
using namespace std;

template<typename random>
class ArrayOperations
{
private:
    random *arr;
    int size;
public:
    ArrayOperations(random *arr, int size);
    void print();
    int binarySearch(random search, int size);
    ~ArrayOperations();
};


template <typename random> ArrayOperations<random>::ArrayOperations(random *arr, int size)
{
    this->size =size;
    this->arr = new random[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = arr[i];
    }
    
}

template <typename random> ArrayOperations<random>::~ArrayOperations()
{
    delete[] arr;
}

template <typename random> 
void ArrayOperations <random>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout<<"\t"<< arr[i];
    }
    
}

template <typename random> 
int ArrayOperations <random>::binarySearch( random search, int size)
{
    int start = 0;
    int end = size -1;
    int mid = end / 2;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    

    while (start <= end)
    {
        if (search == arr[mid])
        {
            return mid;
        }
        if (search > arr[mid])
        {
            start = mid + 1;
        }
        else if (search < arr[mid])
        {
            end = mid -1;
        }
        
        mid = start + (end -start)/2;
    }
    return -1;
}


int main() 
{
    const int size = 10;
    int array[size] = {5,6,4,2,3,1,9,8,7,10};
    float array2[size] = {5.6,6.4,4.2,2.3,3.1,1.9,9.8,8.7,7.10,10.5};

    ArrayOperations<int> obj(array, size);
    obj.print();
    cout<<endl;
    cout<<obj.binarySearch(10, size);
    cout<<endl;
    obj.print();
}
