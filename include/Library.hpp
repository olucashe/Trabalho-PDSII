#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#pragma warning(push, 0)
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
// include getch()
#include <conio.h>

#pragma warning(pop)

using namespace std;

class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
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
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};

#endif