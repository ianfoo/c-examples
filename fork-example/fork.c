#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    char* farewell_name = "my sweet baby process";
    pid_t pid = getpid();
    printf("[pid %d] parent process\n", pid);

    pid_t result = fork();
    switch(result) {
        case -1:
            {
                int err = errno;
                printf("error forking: error code %d\n", err);
                return 1;
            }
            break;
        case 0:
            pid = getpid();
            printf("[pid %d] I am the child; my mom is %d\n", pid, getppid());
            farewell_name = "Mom";
            break;
        default:
            printf("[pid %d] I am the parent, and I started child process %d\n", pid, result);
            sleep(1);
    }
    printf("[pid %d] too-da-loo, %s!\n", pid, farewell_name);
}
