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

double p_raylen(alls *all, double r_A) {
  const double r_X_unit = 0.1 * cos(r_A), r_Y_unit = 0.1 * sin(r_A);
  double raylen = 0, r_X = all->p.p_X, r_Y = all->p.p_Y;
  while (! (all->rn.chunk[(int)(r_Y + 10 * r_Y_unit)][(int)(r_X + 10 * r_X_unit)])) {
    ++raylen;
    r_X += 10 * r_X_unit;
    r_Y += 10 * r_Y_unit;
  }
  while (! (all->rn.chunk[(int)(r_Y + r_X_unit)][(int)(r_X + r_Y_unit)])) {
    raylen += 0.1;
    r_X += r_X_unit;
    r_Y += r_Y_unit;
  }
  while (! (all->rn.chunk[(int)(r_Y + r_X_unit/10)][(int)(r_X + r_Y_unit/10)])) {
    raylen += 0.01;
    r_X += r_X_unit/10;
    r_Y += r_Y_unit/10;
  }
  if (raylen < all->p.p_vis)
    return raylen;
  else
    return -1;
}

double s_raylen(alls *all, double r_A) {}