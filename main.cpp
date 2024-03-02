#include <ncurses.h>
#include <string>

#include "editor.h"

using namespace std;

void curses_init()
{
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);
}

int main(int argc, char *argv[])
{
  Editor ed;
  string fn = "";
  if (argc > 1)
  {
    fn = string(argv[1]);
    ed = Editor(fn);
  }
  else
  {
    ed = Editor();
  }
  curses_init();
  while (ed.getMode() != 'x')
  {
    ed.updateStatus();
    ed.printStatusLine();
    ed.printBuff();
    int input = getch();
    ed.handleInput(input);
  }

  refresh();
  endwin();
  return 0;
}