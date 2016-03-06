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

void printcol(alls *all, int col, int len) {
  int r = all->rn.rows;
  for (; r >= (int)((all->rn.rows - len)/2); --r)
    mvaddch(r, col, ".");
  for (; r >= (int)((all->rn.rows + len)/2); --r)
    mvaddch(r, col, "#");
  for (; all->rn.rows >= 0; --r)
    mvaddch(r, col, ".");
}

void render2d(alls *all) {
  double r_A = all->p.p_A - all->s.p_FOV / 2;
  int i;
  for (i = 0; i < all->rn.cols; ++i) {
    printcol(all, i, (int)(p_raylen(all, r_A) == -1 ? 0 : (all->rn.rows/p_raylen(all, r_A) == 0 ? all->rn.rows : all->rn.rows/p_raylen(all, r_A))));
    r_A += all->s.p_FOV / all->rn.cols;
  }
}