#pragma once

#include <ncurses.h>
#include "buffer.h"

class Editor
{
private:
  int x, y;
  char mode;
  Buffer *buff;
  string status, filename;

  // string tos(int);

  // Cursor Movement
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  void deleteLine();
  void deleteLine(int); // Deletes line <int>

  void saveFile(); // saves buffer into file

public:
  Editor();       // Normal Constructor
  Editor(string); // Constructor accepting Filename

  char getMode()
  {
    return mode;
  }

  void handleInput(int); // Handles keyboard input
  void printBuff();
  void printStatusLine(); // Prints the stats line (like vim!!)
  void updateStatus();    // Updates the status line(text, not display)
};