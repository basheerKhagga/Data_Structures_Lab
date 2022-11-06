#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

#define row 30
#define col 30

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


char isAlive(
		  char game[][col], 
		const int x, 
		const int y)
{

	int alive = 0;
	
	// testing the left
	if(x > 0 && game[x-1][y] == 1) alive+=1;
	// testing the right
	if(x <  col-1 && game[x+1][y] == 1) alive+=1;
	// testing top
	if(y > 0 && game[x][y-1] == 1) alive+=1;
	// testing bottom
	if(y <  row-1 && game[x][y+1] == 1) alive+=1;
	

	// testing top left
	if(y > 0 && x > 0 && game[x-1][y-1] == 1) alive+=1;
	// testing top right
	if(y > 0 && x <  col-1 && game[x+1][y-1] == 1) alive+=1;
	// testing bottom left
	if(y <  row-1 && x > 0 && game[x-1][y+1] == 1) alive +=1;
	// testing bottom right
	if(y <  row-1 && x <  col-1 && game[x+1][y+1] == 1) alive+=1;
	
	// alive and fewer than 2 die
	if(game[x][y] == 1 && alive < 2) return  ' ';
	// alive and 2 or 3 then live
	if(game[x][y] == 1 && (alive == 2 || alive == 3)) return  '*';
	// more than 3 live die
	if(alive > 3) return  ' ';
	// 3 alive and point is dead, come to life
	if(game[x][y] == 0 && alive == 3) return  '*';

	return  ' ';

}	

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

            play2[i][j] = isAlive(play1, i, j);
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
        Sleep(1000);
        changePlay(play1, play2);
    }

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

