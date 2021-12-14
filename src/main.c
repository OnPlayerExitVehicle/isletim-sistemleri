#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "parser.h"
#include "hashtable.h"

char workingDir[80];
int childPID[5];
int pidCounter = -1;

hash hash_cd;
hash hash_showpid;
hash hash_exit;

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
    setenv("pwd", workingDir, 1);
}

void showpid(void)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", childPID[i]);
    }
}


int main()
{
    // Initialize Built-in commands to hashtable

    datas data_cd = {.data = "cd"};
    datas data_showpid = {.data = "showpid"};
    datas data_exit = {.data = "exit"};
    hash_cd = hash_table_insert(&data_cd);
    hash_showpid = hash_table_insert(&data_showpid);
    hash_exit = hash_table_insert(&data_exit);

    // Get current working directory

    char input[80];
    if(!getcwd(workingDir, sizeof(workingDir)))
    {
        setColor(COLOR_RED);
        printf("Calisma ortami duzgun bir sekilde getirilemedi. Programdan cikiliyor...\n");
        return 0;
    }

    do
    {
        // Printing

        setColor(COLOR_GREEN);
        printf("%s/: ", workingDir);
        setColor(COLOR_BLUE);
        printf("sau > ");
        resetColor();
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        // Parsing input

        char* argv[10];
        char command[80];
        int count = parse(input, command, argv);

        int result = hash_table_get_key(command);
        
        if(result >= 0)
        {
            if(result == hash_cd)
            {
                if(count != 2)
                {
                    setColor(COLOR_RED);
                    printf("Hata: Komutun icra edilmesi icin gerekenden az veya cok parametre var.\n");
                }
                else
                {
                    cd(argv[1]);
                }
                continue;
                
            }
            else if(result == hash_showpid)
            {
                showpid();
                continue;
            }
            else if(result == hash_exit)
            {
                printf("exit\n");
                return 0;
            }
        }


        pid_t pid = fork();
        if(pid > 0)
        {
            wait(NULL);
            pidCounter = (pidCounter + 1) % 5;
            childPID[pidCounter] = pid;
        }
        else if(pid == 0)
        {
            int err = execvp(command, argv);
            if(err == -1)
            {
                setColor(COLOR_RED);
                printf("Hata: Komut icra edilemiyor.\n");
                resetColor();
            }
            exit(0);
        }
        else 
        {
                setColor(COLOR_RED);
                printf("Hata: Bilinmeyen bir problem olustu.\n");
                resetColor();
        }
        
    } while (1);
    
    
    
    
}