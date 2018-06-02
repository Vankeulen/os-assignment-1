#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>

int main() {
    pid_t parent = getpid();
    assert(parent);

    pid_t pid = fork();
    int status = 0;
    
    if (pid == 0) {
        // child process
        execl("/bin/sh", "sh", "-c", "./counter 5", (char*)0);
        perror("execl");
    } else {
        // parent process   
        assert(printf("Child PID: %d\nParent PID:%d\n", pid, parent) > 0);
        
        assert(wait(&status) != 0);
        
        assert(WIFEXITED(status));

        if (WIFEXITED(status)) {
            status = WEXITSTATUS(status);
        } 
        
    
    }
    assert(printf("Process %d exited with status %d\n", pid, status) > 0);
        
    return 0;
}
