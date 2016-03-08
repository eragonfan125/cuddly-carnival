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
#ifndef MAIN_H
#define MAIN_H

typedef struct {
  double p_A;
  double p_X;
  double p_Y;
  double p_vis;
  double p_speed;
} p_info;
typedef struct {
  double p_FOV;
  double p_rspeed;
} settings;
typedef struct {
  int rows;
  int cols;
  int refresh;
  int chunk[5][5];
} rendering;
typedef struct {
  p_info p;
  settings s;
  rendering rn;
} alls;

#endif // MAIN_H
