#include<iostream>
#include<windows.h>

using namespace std;

void loadingBar(){
    system("cls");
    system("color 9F");
    char a = 127, b = 219;
    cout << "\n\t\t\t\t\tProject By Sahil Gawnar";
    cout << "\n\n\n\t\t\t\t\t Loading...\n";
    cout << endl;
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26;i++)
        cout << a;
    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 26;i++){
        cout << b;
        Sleep(200);
    }
}

