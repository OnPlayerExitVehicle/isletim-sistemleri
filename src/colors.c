#include "colors.h"
#include <stdio.h>

const char colorList[][10] = {
    "\033[0m",
    "\033[0;30m",
    "\033[0;31m",
    "\033[0;32m",
    "\033[0;33m",
    "\033[0;34m",
    "\033[0;35m",
    "\033[0;36m",
    "\033[0;37m"
};

void setColor(COLOR color)
{
    printf("%s", colorList[color]);
}
void resetColor(void)
{
    printf("%s", colorList[COLOR_RESET]); 
}