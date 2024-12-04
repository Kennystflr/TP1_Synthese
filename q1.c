//
// Created by ubuntu on 11/30/24.
//Functions to print a welcome message and the prompt line
#include <stdio.h>
#include "question1.h"


void welcome() {
    write(STDOUT_FILENO, msg_welcome, sizeof(msg_welcome));
}

void print_prompt() {
    write(STDOUT_FILENO, msg_VMmPo, sizeof(msg_VMmPo));
}

void print_pourcent(){
    write(STDOUT_FILENO, pourcent, sizeof(pourcent));
}



