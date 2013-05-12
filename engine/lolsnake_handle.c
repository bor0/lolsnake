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

int lolsnake_handle(lolsnake *lols) {
    int i, j;
    lolsnakepart *tmp;

    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (lols->map[i][j] != FOOD) {
                lols->map[i][j] = EMPTY;
            }
        }
    }

    tmp = lols->head;

    if (lols->map[tmp->y][tmp->x] == FOOD) { // handle food
        //
    }

#ifdef DEBUG_MOVES
    int k = 1;
    printf("%d [x: %d, y: %d, d:%d]\n", k, lols->head->x, lols->head->y, lols->head->direction);
    k++;
#endif

    // handle while printing
    while (tmp != NULL) {
#ifdef DEBUG_MOVES
        printf("%d [x: %d, y: %d, d:%d]\n", k, tmp->x, tmp->y, tmp->direction);
        k++;
#endif
        if (lols->map[tmp->y][tmp->x] == SNAKE) { // handle self collision
            return -1;
        }
        else if (tmp->y >= M || tmp->y < 0 || tmp->x >= M || tmp->y < 0) { // handle wall collision
            return -2;
        }
        else lols->map[tmp->y][tmp->x] = SNAKE;
        tmp = tmp->next;
    }

    return 1;

}
