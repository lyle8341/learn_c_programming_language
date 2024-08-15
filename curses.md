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
```



### 术语和概念
+ stdscr是指curses窗口，它与显示器的物理屏幕的尺寸完全一样。curses函数库用两个数据结构来映射终端屏幕，即stdscr和curscr。
+ stdscr：对应的是标准屏幕，它的工作方式与stdout相似，是curses程序中的默认输出窗口。
+ curscr：对应的是当前屏幕，在程序调用refresh函数之前，输出到stdscr上的内容不会显示在屏幕上。curses函数库会在refresh函数被调用时比较stdscr与第二个数据结构curscr之间的不同之处，然后用这两个数据结构之间的差异来刷新屏幕。
+ 以屏幕的左上角即坐标(0, 0)为起点，通过行号和列号来组织
+ 所有curses函数使用的坐标都是y值(行号)在前，x值(列号)在后。每个位置不仅包含该屏幕处的字符，还包含它的属性(粗体、下划线、反白显示、色彩)
+ 由于curses函数库在使用时需要创建和删除一些临时的数据结构，所以所有的curses程序必须在开始使用curses函数库之前对其进行初始化，并在结束使用后允许curses恢复原先设置。这两项工作由initscr和endwin函数分别完成



### 屏幕
+ 输出到屏幕
  ```c
  #include <curses.h>
  //chtype等同于unsigned long，由typedef定义
  int addch ( const chtype char_to_add ); /* 在光标的当前位置添加指定的字符 */
  int addchstr ( chtype *const string_to_add ); /* 在光标的当前位置添加指定的字符串 */
  int printw ( char *format, ... ); /* 对字符串进行格式化，并将其添加到光标的当前位置 */
  int refresh ( void ); /* 刷新物理屏幕，成功时返回OK，错误时返回ERR */
  int box ( WINDOW *win_ptr, chtype vertical_char, chtype horizontal_char ); /* 用来围绕一个窗口绘制方框 */
  int insch ( chtype char_to_insert ); /* 插入一个字符，将已有的字符向右移 */
  int insertIn ( void ); /* 插入一个空白行，将现有行依次向下移一行 */
  int delch ( void ); /* 删除一个字符，将已有的字符向左移 */
  int deleteIn ( void ); /* 删除一行，将现有行向上移一行 */
  int beep ( void ); /* 在终端上发出声音 */
  int flash ( void ); /* 使屏幕闪烁 */
  ```
+ 清除屏幕
  ```c
  #include <curses.h>
  int erase ( void ); /* 在每个屏幕位置写上空白字符 */
  int clear ( void ); /* 用于清屏，但在下次调用refresh函数时重现屏幕原文 */
  int clrtobot ( void ); /* 清除当前光标位置直到屏幕结尾的所有内容 */
  int clrtoeol ( void ); /* 清除当前光标位置直到光标所处行行尾的所有内容 */
  ```
+ move函数：用来将**逻辑光标**的位置移到指定地点，屏幕坐标以左上角(0, 0)为起点
  + 如果希望物理屏幕上的光标位置在调用move函数之后立刻有变化，则需在它之后立刻调用refresh函数
+ leaveok函数：设置一个标志，该标志用于控制在屏幕刷新后curses将物理光标放置的位置
  + 默认情况下，该标志为false，意为屏幕刷新后，硬件光标将停留在屏幕上逻辑光标所处的位置；如果该标志设置为true，则硬件光标会被随机地放置在屏幕上的任意位置。一般来说，默认选项更符合用户的需求，这能确保光标停留在一个有意义的位置。
  + 

+ 字符属性
  ```
  属性	             说明
  A_NORMAL	         Normal display (no highlight)
  A_STANDOUT	     Best highlighting mode of the terminal
  A_UNDERLINE	     Underlining
  A_REVERSE	         Reverse video
  A_BLINK	         Blinking
  A_DIM	             Half bright
  A_BOLD	         Extra bright or bold
  A_PROTECT	         Protected mode
  A_INVIS	         Invisible or blank mode
  A_ALTCHARSET	     Alternate character set
  ````
  ```c
  #include <curses.h>
  int attron ( chtype attribute ); /* 启用指定的属性 */
  int attroff ( chtype attribute ); /* 关闭指定的属性 */
  int attrset ( chtype attribute ); /* 设置curses属性 */
  int standout ( void ); /* 提供了一种强调或“突出”模式，在大多数终端上，通常被映射为反白显示 */
  ```




