#ifndef COLORS_H
#define COLORS_H

#define COLOR_RESET 0

typedef enum
{
    COLOR_BLACK = 1,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_PURPLE,
    COLOR_CYAN,
    COLOR_WHITE,
} COLOR;



/*
const char color_reset[7]   = "\033[0m";
const char color_black[10]  = "\033[0;30m";
const char color_red[10]    = "\033[0;31m";
const char color_green[10]  = "\033[0;32m";
const char color_yellow[10] = "\033[0;33m";
const char color_blue[10]   = "\033[0;34m";
const char color_purple[10] = "\033[0;35m";
const char color_cyan[10]   = "\033[0;36m";
const char color_white[10]  = "\033[0;37m";
*/

void setColor(COLOR);
void resetColor(void);
#endif