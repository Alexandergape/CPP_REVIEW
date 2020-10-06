//
// Created by Alexander P on 20/05/15.
//
//#include "my_header"
#include "iostream"//

#include <cstdio>
#include <cstdlib>//
#include <cctype>
#include <cstring>
//#include <conio.h>
//#include <windows.h>

//#include <string>//
//#include <limits>//
//#include <vector>//
//#include <sstream>//
//#include <numeric>//
//#include <ctime>//
//#include <cmath>//


//~ #include <clocale>//libreria para idiomas y caracteres especiales; not working
//#include <fstream>//librerias para ficheros en C++
//#include <iomanip>

using namespace std;

void imprime(){
    cout<<"HEYY\n";
    cout<<"Now you are in \'first.cpp\'...\n";

    char ch = 'C';
    char* ptr = &ch;
    cout <<*ptr<<endl;
    ch = 'Z';
    cout << *ptr<<endl;
    *ptr = 'X';
//    *ptr = '\0';
    cout << ch<<endl;

    cout<<"Now you exited from \'first.cpp\'...\n";
}

//int main(){
//    cout<<"Hello pi";
//}
