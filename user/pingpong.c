
/*
* pingpong.c: Write a program that uses UNIX system calls to ''ping-pong''
* a byte between two processes over a pair of pipes, one for each direction.
* The parent should send a byte to the child; the child should print "<pid>: received ping",
* where <pid> is its process ID, write the byte on the pipe to the parent, and exit;
* the parent should read the byte from the child, print "<pid>: received pong",
* and exit. Your solution should be in the file user/pingpong.c.
*/

#include "kernel/types.h"
#include "user/user.h"

int main(){
    int p[2];
    char buf[100];
    pipe(p);
    if(fork() == 0) {
        read(p[0],buf,sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
        write(p[1],"pong",5);
        exit(0);
    } else {
        write(p[1], "ping", 5);
        wait(0);
        read(p[0],buf,sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
    }
    exit(0);
}