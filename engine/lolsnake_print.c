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

#include "lolsnake.h"

void lolsnake_printmap(lolsnake *lols) {
    int i, j;

#ifdef __linux
    char clear_command[] = "clear";
#else
    char clear_command[] = "cls";
#endif

#ifndef DEBUG_MOVES
    system(clear_command);
#endif

    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            putchar(lols->map[i][j]);
        }
        putchar('\n');
    }

}
