#include <stdio.h>      /* printf */
#include <errno.h>
#include <stdlib.h>     /* strtol */
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    pid_t pid = getppid();

    int num = 0;
    if (argc >= 2) {
        num = (int)strtol(argv[1], NULL, 10);
        if (num > 0) {
            
            for (int i = 0; i < num; i++) {
                printf("Process: %d %d\n", pid, (1+i));
            }

        } else {
            printf("Please run again with a number greater than zero !\n");
        }
    } else {
        printf("Please run again with a number greater than zero !\n");
    }

    //exit(num);
    return num;
}

