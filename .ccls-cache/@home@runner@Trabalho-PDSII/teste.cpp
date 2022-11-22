#include <stdio.h>
#include <termios.h>

static struct termios old, _new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
  tcgetattr(0, &old);                 // grab old terminal i/o settings
  _new = old;                          // make new settings same as old settings
  _new.c_lflag &= ~ICANON;             // disable buffered i/o
  _new.c_lflag &= echo ? ECHO : ~ECHO; // set echo mode
  tcsetattr(0, TCSANOW, &_new);        // apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void) { tcsetattr(0, TCSANOW, &old); }

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/*
Read 1 character without echo
getch() function definition.
*/
char getch(void) { return getch_(0); }

/*
Read 1 character with echo
getche() function definition.
*/
char getche(void) { return getch_(1); }

int main(void) {
  char c;

  printf("(getche example) Please enter a character: ");
  c = getche();
  printf("\nYou entered: %c\n", c);

  printf("(getch example) Please enter a character: ");
  c = getch();
  printf("\nYou entered: %c\n", c);

  return 0;
}