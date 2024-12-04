//
// Created by ubuntu on 11/30/24.
//
#ifndef PRINT_H
#define PRINT_H
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define msg_welcome "Bienvenue dans le shell de VMmPo. \n Pour quitter, tapez 'exit'. \n "
#define msg_VMmPo "VMmPo%%"
#define pourcent "%%"
#define MAXSIZE 1024
#define ByeBye "Bye bye...."

void print_prompt();
void welcome();
void print_pourcent();
int command_exit(char *command);
void prompt_read(char *command);
void execute_command(char *command, int *status);


#endif //PRINT_H
