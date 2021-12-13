#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "parser.h"

char workingDir[80];
int childPID[5];

void cd(const char* path)
{
    int err = chdir(path);
    if(err)
    {
        setColor(COLOR_RED);
        printf("Hata: %s", path);
        printf("Hata: Komut icra edilemiyor.\n");
    }
    
    getcwd(workingDir, sizeof(workingDir));
    printf("Current Dir = %s\n", workingDir);
    setenv("pwd", workingDir, 1);
}

void showpid(void)
{
    
}

int main()
{
    printf("%d", childPID[0]);
    char input[80];
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
        //memset(input,0,strlen(input));
        setColor(COLOR_GREEN);
        printf("%s/: ", workingDir);
        setColor(COLOR_BLUE);
        printf("sau > ");
        resetColor();
        //scanf("%[^\n]", input);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        printf("You entered the command: %s\n", input);
        /*
        char* command = strtok(input, " ");
        char* token = strtok(NULL, " ");
        
        if(!strcmp(command, "cd"))
        {
            if(!token)
            {
                setColor(COLOR_RED);
                printf("Hata: Komutun icra edilmesi icin yeteri sayida parametre yok.\n");
                return 0;
            }
            else
            {
                cd(token);
            }
        }
        */
        char* argv[10];
        char command[80];
        int count = parse(input, command, argv);
        //printf("Command = %s\nCount = %d\n", command, count);
        pid_t pid = fork();
        if(pid > 0)
        {
            wait(NULL);
            //parent func
        }
        else if(pid == 0)
        {
            //char* argv[] = {"pwd", NULL};
            execvp(command, argv);
            exit(0);
        }
        else 
        {
                // error
        }
        
    } while (strcmp(input, "exit"));
    
    
    
    
}