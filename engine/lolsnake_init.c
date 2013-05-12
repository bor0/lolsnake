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

lolsnake *lolsnake_init(int x, int y, int additional_length, int direction) {
    int i = 0;
    lolsnake *lols = (lolsnake *)malloc(sizeof(lolsnake));
    lolsnakepart *tmp;

    if (additional_length < 0) return;

    lols->head = (lolsnakepart *)malloc(sizeof(lolsnakepart));
    lols->head->x = x;
    lols->head->y = y;
    lols->head->direction = direction;

    tmp = lols->tail = lols->head;

    for (i=0;i<additional_length;i++) {
        tmp->next = (lolsnakepart *)malloc(sizeof(lolsnakepart));
        tmp = tmp->next;
        tmp->x = x;
        tmp->y = ++y;
        tmp->direction = direction;
        tmp->next = NULL;
        lols->tail = tmp;
    }

    lolsnake_handle(lols);

    return lols;

}

void lolsnake_deinit(lolsnake *lols) {
    lolsnakepart *tmp;

    while (lols->head != NULL) {
        tmp = lols->head;
        lols->head = lols->head->next;
        free(tmp);
    }

    free(lols);

}
