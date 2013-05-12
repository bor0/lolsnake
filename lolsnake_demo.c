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

#include "engine/lolsnake.h"

int move[] = { UP, LEFT, DOWN, LEFT, DOWN, DOWN, DOWN, RIGHT };

int main() {

    int i, ret;
    lolsnake *lols = lolsnake_init(3, 1, 7, UP);

    lolsnake_printmap(lols);

    for (i=0;i<sizeof(move)/sizeof(int);i++) {
        sleep(1);
        ret = lolsnake_render(lols, move[i]);
        if (ret < 0) {
            printf("Collision [%d]!\n", ret);
            break;
        }
        lolsnake_printmap(lols);
    }

    lolsnake_deinit(lols);
    return 0;

}

