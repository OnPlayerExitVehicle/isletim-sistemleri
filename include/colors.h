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

void setColor(COLOR);
void resetColor(void);
#endif