//
// Created by 李玉龙 on 2024/7/30.
//

#include "v1.h"
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

int score = 0;
point segments[256];

int v1_snake() {
    int screen_width = 40;
    int screen_height = 20;

    //initialize screen
    WINDOW *win = initscr();

    // take player input
    keypad(win, true);
    nodelay(win, true);
    curs_set(FALSE); // Don't display a cursor

    //snake
    point head = {0, 0};
    point direction = {1, 0};

    point berry = {rand() % screen_width, rand() % screen_height};

    while (true) {
        int pressed = wgetch(win);
        if (pressed == KEY_LEFT) {
            if (direction.x == 1) continue;
            direction.x = -1;
            direction.y = 0;
        }
        if (pressed == KEY_RIGHT) {
            if (direction.x == -1) continue;
            direction.x = 1;
            direction.y = 0;
        }
        if (pressed == KEY_UP) {
            if (direction.y == 1) continue;
            direction.x = 0;
            direction.y = -1;
        }
        if (pressed == KEY_DOWN) {
            if (direction.y == -1) continue;
            direction.x = 0;
            direction.y = 1;
        }
        if (pressed == '\e') {
            break;
        }

        //update segments
        for (int i = score; i > 0; i--) {
            segments[i] = segments[i - 1];
        }
        segments[0] = head;

        //update
        head.x += direction.x;
        head.y += direction.y;

        if (head.x == berry.x && head.y == berry.y) {
            score += 1;
            berry.x = rand() % screen_width;
            berry.y = rand() % screen_height;
        }

        //---------------------- draw ----------------------
        erase();

        mvaddch(berry.y, berry.x * 2, '@');

        //draw snake
        for (int i = 0; i < score; ++i) {
            mvaddch(segments[i].y, segments[i].x * 2, 'o');
        }

        mvaddch(head.y, head.x * 2, 'O');

        usleep(200000);
    }

    endwin();

    return 0;


}