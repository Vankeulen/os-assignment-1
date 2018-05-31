#include <stdio.h>      /* printf */
#include <errno.h>
#include <stdlib.h>     /* strtol */
#include <sys/types.h>
#include <unistd.h>

#include <assert.h>

int main(int argc, char *argv[]) {
    
    pid_t pid = getppid();

    int num = 0;
    if (argc >= 2) {
        num = (int)strtol(argv[1], NULL, 10);
        if (num > 0) {
            
            for (int i = 0; i < num; i++) {
                assert(printf("Process: %d %d\n", pid, (1+i)) > 0);
            }

        } else {
            assert(printf("Please run again with a number greater than zero !\n") > 0);
        }
    } else {
        assert(printf("Please run again with a number greater than zero !\n") > 0);
    }

    exit(num);
    //return num;
}

