#include "utils.h"


#define True 1



int main() {
    char command[BUFMAXSIZE] = {0};
    char* argv[BUFMAXSIZE] ;
    int status = 0;
    struct timespec start_time;
    struct timespec end_time;


    welcome();
    print_prompt();
    print_pourcent();


    while(True) {

        prompt_read(command);
        complex_prompt_slice(command,argv);
        if (command_exit(command)==1){
            break;
        }
        clock_gettime(CLOCK_REALTIME, &start_time);
        exec_complex_cmd(argv,&status);
        clock_gettime(CLOCK_REALTIME, &end_time);
        print_prompt();
        check_status(status,timespec_subtract(end_time,start_time));
        print_pourcent();
        }


}



