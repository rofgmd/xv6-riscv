
/*
* sleep.c: Implement the UNIX program sleep for xv6; 
* your sleep should pause for a user-specified number of ticks. 
* A tick is a notion of time defined by the xv6 kernel, 
* namely the time between two interrupts from the timer chip. 
* Your solution should be in the file user/sleep.c.
*/

#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    if(argc <= 1){
        printf("sleep error, missing argument\n");
        exit(1);
    }else if(argc >=3){
        printf("sleep error, two much argument\n");
        exit(1);
    }else{
        char *sleep_time = argv[1];
        int time = atoi(sleep_time);
        sleep(time);
    }
    exit(0);
}