#include <iostream>
using namespace std;

#define row 4
#define col 5

int main() 
{

    int array[row][col] = {{5,6,2,13,7},{1,2,3,10,5},{8,9,7,11,20},{20,51,79,43,23}};
    int temp = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool swapped = false;
            for (int k = 0; k < row; k++)
            {
                for (int l = 0; l < col; l++)
                {
                    if (array[i][j] < array[k][l])
                    {
                        
                        temp = array[i][j];
                        array[i][j] = array[k][l];
                        array[k][l] = temp;
                        swapped = true;
                    }
                    
                }
                
            }
            if (! swapped)
            {
                break;
            }
            
            
        }
    }
    

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"\t"<<array[i][j];
        }
        cout<<endl;
    }
    
}
