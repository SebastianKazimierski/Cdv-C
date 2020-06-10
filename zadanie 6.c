#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
void proces();
int stat;
int main(int argc, char *argv[]){
    pid_t processid; 
    processid = fork(); //tworzenie nowego procesu
    if (processid==0){execlp("ls", "ls"."-l", NULL); // proces dziecka
    exit(0);
                     }
    else { // oczekuja na proces potomny
        wait(&stat);//Proces rodzica
    }
    if (WIFEXITED(stat))
    {
        printf("zakonczenie programu: %d\n",WEXITSTATUS(stat));
    }
    return 0;}
