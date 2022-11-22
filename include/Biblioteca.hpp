#ifndef __BIBLIOTECA_HPP__
#define __BIBLIOTECA_HPP__

#pragma warning(push, 0)
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <termios.h>
#pragma warning(pop)

using namespace std;

#ifndef _mygetch_
#define _mygetch_
static struct termios old, _new;
void initTermioss(int echo);
void resetTermioss();
char getch__(int echo);
char getch2();
#endif

class Biblioteca
{
    public:
        char bookname[100], auname[50], sc[20], sc1[50];
        int q, B, p;
        Biblioteca();
        void get();
        void student();
        void pass();
        void librarian();
        void password();
        void getdata();
        void show(int);
        void booklist(int);
        void modify();
        void see(int);
        int branch(int);
        void issue();
        void der(char[], int, int);
        void fine(int, int, int, int, int, int);
};




#endif