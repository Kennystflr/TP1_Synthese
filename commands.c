//
// Created by ubuntu on 11/30/24.


#include <time.h>

#include "utils.h"
#define ERRFORK "Fork failed\n"
struct timespec start_time;
struct timespec end_time;

// A function that reads a given command and put it in a buffer
void prompt_read(char *cmd){
    int nb = (int) read(STDIN_FILENO, cmd, BUFMAXSIZE);
    cmd[nb-1] = '\0';
}

//A function that slices the given buffer into a list of arguments that we can use later
void complex_prompt_slice(char *cmd,char**argv) {
    int k=0;
    char *token = strtok(cmd, " ");// creating a slicer of the given buffer
    while(token != NULL && k<BUFMAXSIZE-1) {
        argv[k] = token;
        token = strtok(NULL, " ");//to the next argument
        k++;
    }
    argv[k] = NULL;
}

void exec_complex_cmd(char **cmd,int *status) {
    pid_t pid = fork();
    if (pid==-1) {// Test of the fork success
        write(STDERR_FILENO,ERRFORK,strlen(ERRFORK));
    }else if (pid == 0) {
        execvp(cmd[0],cmd);
        exit(EXIT_SUCCESS);
    }else {
        wait(status);
    }
}

// A function that executes a command from a given buffer
void exec_cmd(char *cmd, int *status) {
    pid_t pid = fork();
    if (pid==-1) {
        write(STDERR_FILENO,ERRFORK,strlen(ERRFORK));
    }else if (pid == 0) {// The son transforms into the given function
        execlp(cmd, cmd, NULL);
        exit(1);
    }else {
        wait(status);
    }
}

//This function checks the status of the last executed process and give its time of execution
void check_status(int status, int time) {
    char prompt[BUFMAXSIZE] = {0};

    if (WIFEXITED(status)) {
        snprintf(prompt,BUFMAXSIZE,"[exit:%d|%d ms]",WEXITSTATUS(status),time);
        write(STDIN_FILENO,prompt,strlen(prompt));
    }else if (WIFSIGNALED(status)) {
        snprintf(prompt,BUFMAXSIZE,"[sign:%d|%d ms]",WIFSIGNALED(status),time);
        write(STDIN_FILENO,prompt,strlen(prompt));
    }
}

int timespec_subtract(struct timespec end_time, struct timespec start_time) {
    return ((end_time.tv_sec - end_time.tv_sec)*sTOms + ((end_time.tv_nsec - start_time.tv_nsec)/nsTOms));
}

int command_exit(char *cmd) {
    if (strcmp(cmd, "exit") == 0) {
        write(STDOUT_FILENO, ByeBye, strlen(ByeBye));
        return 1;
    }
    return 0;
}
