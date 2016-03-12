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

int p_gameinput(alls *all) {
  int refresh = 1;
  switch (getch()) {
    case KEY_UP:
      all->p.p_X += all->p.p_speed * cos(all->p.p_A);
      all->p.p_Y += all->p.p_speed * sin(all->p.p_A);
      break;
    case KEY_DOWN:
      all->p.p_X -= all->p.p_speed * cos(all->p.p_A);
      all->p.p_Y -= all->p.p_speed * sin(all->p.p_A);
      break;
    case KEY_LEFT:
      all->p.p_A -= all->s.p_rspeed;
      break;
    case KEY_RIGHT:
      all->p.p_A += all->s.p_rspeed;
      break;
    case 'q':
      endwin();
      exit(0);
    default:
      refresh = 0;
      break;
  }
  return refresh;
}