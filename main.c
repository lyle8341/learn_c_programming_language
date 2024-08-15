#include <ncurses.h>

int main() {
    initscr();
    WINDOW * win = newwin(5, 6, 5, 6);

    getch();

    endwin();
    return 0;
}