#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"
int main()
{
    char command[80];
    char workingDir[80];
    if(getcwd(workingDir, sizeof(workingDir)))
    {
        //setColor(COLOR_WHITE);
        printf("Working directory info fetched successfully.\n");
    }
    else
    {
        setColor(COLOR_RED);
        printf("Working directory info did not fetched successfully. Exitting the program...");
        return 0;
    }

    do
    {
        setColor(COLOR_GREEN);
        printf("%s/: ", workingDir);
        setColor(COLOR_BLUE);
        printf("sau > ");
        resetColor();
        scanf("%s", command);
        //printf("%s\n", command);
    } while (strcmp(command, "exit"));
    
    
    
}