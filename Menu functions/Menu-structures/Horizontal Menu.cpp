/*
                 Program that shows the functionality of the menu_h (Horizontal menu)

    It receives an op variable and changes from 0 to n - 1, n being the length of the string array

    when the user presses Enter it ends and keeps the op value that was selected.

*/

//default
#include <iostream>
//to use textcolor();
#include <windows.h>
//to use getch();
#include <conio.h>

using namespace std;


//function thats change the color
void textcolor (int iColor);
//function menu_h
void menu_h(string call,string op_array[],int n,int &op,int icolor);


int main()
{

    setlocale(LC_ALL, "Portuguese");

    // n is the size of op array
    int n = 3,op,color = 4;//color 4 in textcolor
    //op array is the options
    string op_array[n] = {"Option 1","Option 2","Option 3"};
    //call
    string call = "MENU_H \n\nPress [a/d] to change and [Enter] to choose\n\n";

    //it doesn't matter the op value when he enters
    menu_h(call,op_array,n,op,color);


    //Example of use:
    switch (op)
    {
    case 0 :
        system("cls");
        cout <<"\n\nYou selected option 1.";
        break;
    case 1 :
        system("cls");
        cout <<"\n\nYou selected  option 2.";
        break;
    default :
        system("cls");
        cout <<"\n\nYou selected  option 3.";
    }

    cout << endl << endl ;



    return 0;
}

//to use textcolor();
//#include <windows.h>
//to use getch();
//#include <conio.h>

void menu_h(string call,string op_array[],int n,int &op,int icolor)
{
    char key;
    //reset op
    op = 0;
    do
    {
        system("cls");
        //you can put what ever you want here, will be showed above the op_array
        cout << call << endl << endl;

        for(int i=0; i<n; i++)
        {
            if(i==op)
            {
                textcolor(icolor);
                cout << " " <<op_array[i] << "    ";
                //default color is set to 15 white
                textcolor(15);
            }
            else cout << " " <<op_array[i] << "    ";
        }

        //reset key
        key = 'z';
        // trap the user in getch (); until he types, a, d or enter
        while(key != 'a' and key != 'A' and key != 'd' and key !='D' and key != 13)
        {
            key = getch();

        }
        // move to the chosen direction [a/d]
        if(key == 'a' or key == 'A')
        {
            if(op != 0)
                op--;
        }

        else if(key == 'd' or key == 'D')
            if(op != n-1)
                op++;
    }
    // exit the loop if the user presses enter
    while(key != 13);
}


void textcolor (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}


