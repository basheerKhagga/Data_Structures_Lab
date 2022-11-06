#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    int min = arr[0];
    int min_index = 0;
    int temp = 0;
    for (int j = 0; j < size; j++)
    {
        min = arr[j];
        for (int i = j; i < size; i++)
        {
            
            if (arr[i] < min)
            {
                min = arr[i];
                min_index = i;
            }
        }
        temp = arr[j];
        arr[j] = arr[min_index];
        arr[min_index] = temp;
        min_index = j+1;
        
    }
}

int main()
{
    const int size = 10;
    int arr[size] = {5, 8, 4, 2, 3, 1, 6, 6, 7, 10};
    cout<<"\nUnsorted Array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }

    selectionSort(arr, size);
    cout<<"\nSorted Array : \n";

    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
}
