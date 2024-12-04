//
// Created by ubuntu on 11/30/24.
//Functions to print a welcome message and the prompt line
#include <stdio.h>
#include <string.h>

#include "utils.h"


void welcome() {
    write(STDOUT_FILENO, msg_welcome, strlen(msg_welcome));
}

void print_prompt() {
    write(STDOUT_FILENO, msg_VMmPo, strlen(msg_VMmPo));
}

void print_pourcent(){
    write(STDOUT_FILENO, pourcent, strlen(pourcent));
}



