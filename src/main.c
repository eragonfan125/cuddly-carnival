/*
WallWorlds - in-shell 3-d first person
Copyright (C) 2016 Mark Wright (thepiercingarrow@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <math.h>
#include <stdlib.h>
#include <curses.h>

#include "main.h"
#include "engine.h"
#include "render.h"
#include "input.h"

int main() {
  alls all = {
    {0,2,2, 10, 0.3},
    {2, (double)(M_PI/60)},
    {LINES, COLS, 1,
      {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
      }
    }
  }, *paul = &all;

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, 1);
  
  while(1) {
    all.rn.rows = LINES, all.rn.cols = COLS;
    if (p_gameinput(paul)) {
      render2d(paul);
      refresh();
    }
  }
}
