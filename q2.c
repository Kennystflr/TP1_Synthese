//
// Created by ubuntu on 11/30/24.


#include "question2.h"

// A function that reads a given command and put it in a buffer
void prompt_read(char *command){
    int nb = (int) read(STDIN_FILENO, command, MAXSIZE);
    command[nb-1] = '\0';
}

// A function that executes a comamand from a given buffer
void execute_command(char *command, int *status) {
    if (fork() == 0) {
        execlp(command, command, NULL);
        exit(1);
    }
    else {
        wait(status);
    }
}