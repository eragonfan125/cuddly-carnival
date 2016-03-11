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
#include <math.h>

#include "main.h"
#include "engine.h"
#include "render.h"
#include "input.h"

/*void printcol(alls *all, int col, int len) {
  int r = all->rn.rows;
  for (; r >= (int)((all->rn.rows - len)/2); --r)
    mvaddch(r, col, '.');
  for (; r >= (int)((all->rn.rows + len)/2); --r)
    mvaddch(r, col, 'W');
  for (; all->rn.rows >= 0; --r)
    mvaddch(r, col, '.');
}*/

void render2d(alls *all) {
  double r_A;// = all->p.p_A - all->s.p_FOV / 2;
  int i;
  double rx, ry, rdist;
  for (i = 0; i < all->rn.cols; ++i) {
    rx = all->p.p_X;
    ry = all->p.p_Y;
    rdist = 0;
    int rstatus;
      while(1) {
        r_A = ((all->s.p_FOV / 2) + all->p.p_A) + (i * (all->s.p_FOV / all->rn.cols));
	rx += cos(all->p.p_A) * 0.1;
	ry += sin(all->p.p_A) * 0.1;
	rdist += 0.1;

	//max dist
	if (rdist > 10) {
	  rstatus = -1;
	  break;
	}

        //check if ray hit a wall
	rstatus = all->rn.chunk[(int) ry][(int) rx];

	if (rstatus != 0)
		break;
      }
      //create a col
      int h = (int) ((1 / pow(rdist, 2)) * all->rn.rows);
      int f = (all->rn.rows - h) / 2;
      int ir;
      for (ir = 0; ir < all->rn.rows; ir++) {
        if ((ir < f) || (ir > (f + h)) || rstatus == -1)
	  mvaddch(ir, i, ' ');
	else
	  mvaddch(ir, i, '#');
      }
    //printcol(all, i, (int)(\
    p_raylen(all, r_A) == -1 ? 0 : \
    (p_raylen(all, r_A) < 1 ? all->rn.rows : all->rn.rows / p_raylen(all, r_A))));
    //r_A += all->s.p_FOV / all->rn.cols;
  }
}
