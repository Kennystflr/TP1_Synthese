//
// Created by ubuntu on 11/30/24.
//
#ifndef PRINT_H
#define PRINT_H
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define msg_welcome "Bienvenue dans le shell de VMmPo. \n Pour quitter, tapez 'exit'. \n "
#define msg_VMmPo "VMmPo"
#define pourcent "%%"
#define BUFMAXSIZE 1024
#define ByeBye "Bye bye....\n"
#define nsTOms 1000000
#define sTOms 1000


void print_prompt();
void welcome();
void print_pourcent();
int command_exit(char *cmd);
void prompt_read(char *cmd);
void exec_cmd(char *cmd, int *status);
void check_status(int status,int);
void complex_prompt_slice(char *cmd,char **argv);
void exec_complex_cmd(char**,int*);
int timespec_subtract(struct timespec timespec, struct timespec start_time);


#endif //PRINT_H
