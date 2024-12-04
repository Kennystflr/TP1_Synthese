//
// Created by ubuntu on 11/30/24.
//

#include "question3.h"

int command_exit(char *command) {
    if (strcmp(command, "exit") == 0) {
        write(STDOUT_FILENO, ByeBye, sizeof(ByeBye));
        return 1 ;
    }
    return 0;
}
