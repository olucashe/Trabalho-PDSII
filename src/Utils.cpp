#include "Utils.hpp"

void initTermioss(int echo) {
  tcgetattr(0, &old);
  _new = old;
  _new.c_lflag &= ~ICANON;
  _new.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &_new);
}
void resetTermioss() {
  tcsetattr(0, TCSANOW, &old);
}

char getch__(int echo) {
  char ch;
  initTermioss(echo);
  ch = getchar();
  resetTermioss();
  return ch;
}

char getch2() {
  return getch__(0);
}