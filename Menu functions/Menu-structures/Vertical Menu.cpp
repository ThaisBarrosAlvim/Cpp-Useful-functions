/*
    This program shows the functionality of the menu_v (vertical menu)
*/

#include "iostream"
//to use textcolor();
#include <windows.h>
//to use getch();
#include <conio.h>
using namespace std;

//function thats change the color
void textcolor(int Color);
//function menu_v
void menu_v(string call, string op_array[], int n, int &op, int color);

int main()
{
    int n = 3, op;
    string op_array[n] = {"Option 1", "Option 2", "Option 3"};
    string call = "MENU_V \n\nPress [w/s] to change and [Enter] to choose.\n\n";

    //set the start point of op in menu_v
    op = 0;

    menu_v(call, op_array, n, op, 4);

    switch (op)
    {

    case 0: //Internal menu 1
        system("cls");  
        cout <<"You choose option 1.\n\n";
        system("pause");
        break;
    case 1:
        system("cls");  
        cout <<"You choose option 2.\n\n";
        system("pause");
        break;
    default:
        system("cls");  
        cout <<"You choose option 3.\n\n";
        system("pause");
    }

    return 0;
}

void menu_v(string call, string op_array[], int n, int &op, int color)
{
    char key;
    do
    {
        system("cls");
        cout << call << endl
             << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == op)
            {
                textcolor(color);
                cout << op_array[i] << endl;
                //default color is set to 15 white
                textcolor(15);
            }
            else
                cout << op_array[i] << endl;
        }

        //reset key
        key = 'z';
        // trap the user in getch (); until he types, w, s or enter
        while (key != 'w' and key != 'W' and key != 's' and key != 'S' and key != 13)
            key = getch(); //If this function is not compatible with some of your libraries, try _getch (); or getche();

        // move to the chosen direction [w/s]
        if (key == 'w' or key == 'W')
        {
            if (op != 0)
                op--;
        }

        else if (key == 's' or key == 'S')
        {
            if (op != n - 1)
                op++;
        }

    }
    // exit the loop if the user presses enter
    while (key != 13);
}

void textcolor(int Color)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= Color);
}
