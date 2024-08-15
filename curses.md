# [curses使用](https://blog.csdn.net/fukangwei_lite/article/details/120211135)



### windows
        
>  WINDOW * win = newwin(nlines, ncols, y0, x0);
  
```
                 The screen (stdscr)
   (0,0)*----------------------------------* (0, COLUMNS-1)
        |                                  |
        |                                  |
        |    (y0,x0)                       |
        |      ---------------             |
        |      |             |             |
        |      |             |             |
        |      |     win     |nlines       |
        |      |             |             |
        |      |             |             |
        |      |             |             |
        |      ---------------             |
        |          ncols                   |
        |                                  |
        *----------------------------------*
  (LINES-1, 0)                              (LINES-1, COLUMNS-1) 

   0 <= y0 < LINES;
   0 <= x0 < COLUMNS;
```



### 术语和概念
+ stdscr是指curses窗口，它与显示器的物理屏幕的尺寸完全一样。curses函数库用两个数据结构来映射终端屏幕，即stdscr和curscr。
+ stdscr：对应的是标准屏幕，它的工作方式与stdout相似，是curses程序中的默认输出窗口。
+ curscr：对应的是当前屏幕，在程序调用refresh函数之前，输出到stdscr上的内容不会显示在屏幕上。curses函数库会在refresh函数被调用时比较stdscr与第二个数据结构curscr之间的不同之处，然后用这两个数据结构之间的差异来刷新屏幕。
+ 以屏幕的左上角即坐标(0, 0)为起点，通过行号和列号来组织
+ 所有curses函数使用的坐标都是y值(行号)在前，x值(列号)在后。每个位置不仅包含该屏幕处的字符，还包含它的属性(粗体、下划线、反白显示、色彩)
+ 由于curses函数库在使用时需要创建和删除一些临时的数据结构，所以所有的curses程序必须在开始使用curses函数库之前对其进行初始化，并在结束使用后允许curses恢复原先设置。这两项工作由initscr和endwin函数分别完成




+ One-character-a-time. To disable the buffering of typed characters by the TTY driver and get a character-at-a-time input, you need to call
  + cbreak();
+ No echo. To suppress the automatic echoing of typed characters, you need to call
  + noecho();
+ Special keys. In order to capture special keystrokes like Backspace, Delete and the four arrow keys by getch(), you need to call
  + keypad(stdscr, TRUE);


+ init_pair(1, COLOR_RED, COLOR_BLACK);
  +  the foreground and background


+ [curses demo](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/keys.html)
```c
#include <stdio.h>
#include <ncurses.h>

#define MENU_BORDER_WIDTH 30
#define MENU_BORDER_HEIGHT 10

int startX = 0;
int startY = 0;

char *choices[] = {
        "Choice 1",
        "Choice 2",
        "Choice 3",
        "Choice 4",
        "Exit"
};
int n_choices = sizeof(choices) / sizeof(char *);


void print_menu(WINDOW *menu_win, int highlight) {
    int x, y, i;
    x = 2; //列为0则在线上
    y = 2; //行为0则在线上
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) { /* High light the present choice */
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;//向下移动一行
    }
    wrefresh(menu_win);
}


int main() {
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;
    initscr();
    clear();
    noecho();
    cbreak();/* Line buffering disabled. pass on everything */
    startX = (80 - MENU_BORDER_WIDTH) / 2;
    startY = (24 - MENU_BORDER_HEIGHT) / 2;

    menu_win = newwin(MENU_BORDER_HEIGHT, MENU_BORDER_WIDTH, startY, startX);
    keypad(menu_win, TRUE);

    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_menu(menu_win, highlight);
    while (TRUE) {
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10:
                choice = highlight;
                break;
            default:
                mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        print_menu(menu_win, highlight);
        if (choice != 0)    /* User did a choice come out of the infinite loop */
            break;
    }

    mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol();
    refresh();
    getch();
    endwin();
    return 0;
}
```

+ 画框
  ```c
  int main() {
  
      initscr();
      clear();
      noecho();
      cbreak();    /* Line buffering disabled. pass on everything */
  
      WINDOW *menu_win = newwin(10, 30, 2, 2);
      refresh();// 必须刷新
  
      box(menu_win, 0, 0);
      wrefresh(menu_win); //必须使用 wrefresh 刷新
      refresh();
  
      getch();
      endwin();
      return 0;
  }
  ```

+ clrtoeol and wclrtoeol
  + erase the current line from the cursor to the end of the line, inclusive, in the current or specified window. 
  + These functions do not update the cursor.