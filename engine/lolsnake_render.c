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

int lolsnake_render(lolsnake *lols, int direction) {
    int dx = 0, dy = 0, previous_direction;

    switch (direction) {
        case LEFT:
            dx = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
        case UP:
            dy = -1;
            break;
        case DOWN:
            dy = 1;
            break;
        default:
            return 0; //not valid direction
            break;
    }

    lolsnakepart *tmp = lols->head->next;
    previous_direction = lols->head->direction;

    while (tmp != NULL) {
        int dir;
        dir = tmp->direction;
        tmp->direction = previous_direction;
        previous_direction = dir;
        switch (tmp->direction) {
            case LEFT:
                tmp->x += -1;
                break;
            case RIGHT:
                tmp->x += 1;
                break;
            case UP:
                tmp->y += -1;
                break;
            case DOWN:
                tmp->y += 1;
                break;
            default:
                return 0; //not valid direction
                break;
        }

        tmp = tmp->next;
    }

    lols->head->x += dx;
    lols->head->y += dy;
    lols->head->direction = direction;

    return lolsnake_handle(lols);

}
