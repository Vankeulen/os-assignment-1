#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#include<unistd.h>

int main() {
    pid_t parent = getpid();
    pid_t pid = fork();
    int status;
        
    if (pid == 0) {
        // child process
        execl("/bin/sh", "sh", "-c", "./counter 5", (char*)0);
        
    } else {
        // parent process
        printf("Child PID: %d\nParent PID:%d\n", pid, parent);
        
        wait(&status);
        
        if (WIFEXITED(status)) {
            status = WEXITSTATUS(status);
        } 
        
    
    }
    printf("Process %d exited with status %d\n", pid, status);
        
    return 0;
}
