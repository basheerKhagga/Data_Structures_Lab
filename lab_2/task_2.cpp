#include <iostream>
using namespace std;

void reverse (int array[], int arr_lenght)
{
    int temp = 0;
    int j = arr_lenght;
    for (int i = 0; i < arr_lenght/2; i++)
    {
        temp = array[i];
        array[i] = array[--j];
        array[j] = temp;
    }
    
    
    
}

int main() 
{
    const int size = 10;
    int arr[size] = {5,6,4,2,3,1,9,8,7,10};
    
    
    reverse(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout<<"\t"<<arr[i];
    }
    
}
