#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

#define row 30
#define col 30

// life rules
char decide(int count, char itself)
{
    if (itself == '*' && count <= 1)
        return ' ';
    else if (itself == '*' && (count == 2 || count == 3))
        return '*';
    else if (itself == '*' && (count > 3))
        return ' ';
    else if (itself == ' ' && (count == 3))
        return '*';

    return itself;
}

// check whether or not a box should be alive or not
char is_alive(int i, int j, char upleft, char up, char upright, char left, char itself, char right, char dowleft, char dow, char dowright)
{
    if (i == 0 && j == 0)
        upleft = up = upright = left = dowleft = ' ';
    else if (i == 0 && j == col - 1)
        upleft = up = upright = right = dowright = ' ';
    else if (i == row - 1 && j == 0)
        dowleft = dow = dowright = left = upleft = ' ';
    else if (i == row - 1 && j == col - 1)
        dowleft = dow = dowright = right = upright = ' ';
    else if (i == 0)
        upleft = up = upright = ' ';
    else if (j == 0)
        upleft = left = dowleft = ' ';
    else if (i == row - 1)
        dowleft = dow = dowleft = ' ';
    else if (j == col - 1)
        upright = right = dowright = ' ';

    char array[8] = {upleft, up, upright, left, right, dowleft, dow, dowright};
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] == '*')
        {
            count++;
        }
    }

    char answer = decide(count, itself);
    return answer;
}

// repeatedly display two arrays interchanging them each time
void changePlay(char play2[][col], char play1[][col])
{
    system("CLS");
    // cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // if (play1[i][j] != ' ')
            // cout <<" "<<i<< " "<< j<< play1[i][j];

            play2[i][j] = is_alive(i, j, play1[i - 1][j - 1], play1[i - 1][j], play1[i - 1][j + 1], play1[i][j - 1], play1[i][j], play1[i][j + 1], play1[i + 1][j - 1], play1[i + 1][j], play1[i + 1][j + 1]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << play2[i][j];
        }
        cout << endl;
    }
}

int main()
{
    // set seed to time(0)
    srand(time(0));

    char play1[row][col];
    int smallest = 300;
    int random = smallest + rand() % row * col - smallest + 1; // largest - smallest + 1
    for (int i = 0; i < random; i++)
    {
        int random1 = rand() % row;
        int random2 = rand() % col;
        play1[random1][random2] = '*';
    }

    // display the result of random values generated
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (play1[i][j] != '*')
            {
                play1[i][j] = ' ';
            }

            cout << play1[i][j];
        }
        cout << endl;
    }

    char play2[row][col];


    for (int i = 0; i < 500; i++)
    {

        Sleep(1000);
        changePlay(play2, play1);
        // cout<<endl<< 1;
        Sleep(1000);
        changePlay(play1, play2);
        // cout<<endl<<2;
    }


    // Trying to map each point through a list of pointers
    // Will try to make a linked list object where each object contains the info about all 8 neighbours as well 
    // So the chaniging can be truely simultaneous
    // int map = 10;

    // char **map_alive = new char*[map];

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if (play1[i][j] == '*')
    //         {
    //             map_alive[i] = &play1[i][j];
    //         }
    //         if (j >= map - 1)
    //         {
    //             map + 1;
    //             char **temp = new char*[map];

    //         }

    //     }

    // }

    // delete[] map_alive;
}
