#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#pragma warning(push, 0)
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <termios.h>
#pragma warning(pop)

using namespace std;

static struct termios old, _new;
void initTermioss(int echo);
void resetTermioss();
char getch__(int echo);
char getch2();

#endif