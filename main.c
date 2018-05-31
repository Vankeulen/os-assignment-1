#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>

#include <assert.h>

int main() {
    pid_t parent = getpid();
    pid_t pid = fork();
    int status;
        
    if (pid == 0) {
        // child process
        assert(pid == 0);
        execl("/bin/sh", "sh", "-c", "./counter 5", (char*)0);
        
    } else {
        // parent process
        assert(printf("Child PID: %d\nParent PID:%d\n", pid, parent) > 0);
        
        assert(wait(&status) != 0);
        
        if (WIFEXITED(status)) {
            status = WEXITSTATUS(status);
        } 
        
    
    }
    assert(printf("Process %d exited with status %d\n", pid, status) > 0);
        
    return 0;
}
