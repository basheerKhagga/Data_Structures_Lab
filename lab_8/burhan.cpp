#include <iostream>
using namespace std;
int main() 
{
    int max = 1550, roi = 150, rod = 200, month = 8, year = 2022, curr = 1500;
    int res = max - curr; //res is the value we need to add in curr to make it max

    
    // curr - (roi(x) - rod(y)) = 0
    // curr - roix + rody = 0
    // curr + rody = roix
    // (curr + rod(y)) / roi = x

    // curr - y(12*res) = 0
    // curr = y(12*res)
    // curr/12*res = y

    double y = double(curr-1550)/double(6*(roi-rod));
    cout<<y;
    if (month > 8 || month < 3)
    {
        
    }
    else
    {

    }
    

}
