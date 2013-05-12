/*
    This file is part of Lolsnake.

    Lolsnake is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Lolsnake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Lolsnake.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdio.h>
#include <stdlib.h>

#define M 30

//#define DEBUG_MOVES 1

enum direction { LEFT = 0, RIGHT, UP, DOWN };

#define FOOD '@'
#define EMPTY '.'
#define SNAKE 'o'

typedef struct lolsnakepart {
    int x;
    int y;
    int direction;
    struct lolsnakepart *next;
} lolsnakepart;

typedef struct {
    lolsnakepart *head, *tail;
    char map[M][M];
} lolsnake;

int lolsnake_handle(lolsnake *);
lolsnake *lolsnake_init(int, int, int, int);
void lolsnake_deinit(lolsnake *);
void lolsnake_printmap(lolsnake *);
int lolsnake_render(lolsnake *, int);
