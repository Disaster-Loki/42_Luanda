#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int r_bit;

void rest(int signal, siginfo_t *siginfo, void *context)
{
    static unsigned char buff;

    r_bit = 0;
    (void)context;
    if (signal == SIGUSR1)
        buff |= 1;
    r_bit++;
    if (r_bit == 8)
    {
        write(1, &buff, 1);
        r_bit = 0;
        buff = 0;
    }
    else
        buff = buff << 1;
    kill(siginfo->si_pid, SIGUSR1);
}

void sig_handler(void)
{
    struct sigaction sa;

    sa.sa_sigaction = rest;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        perror("Error - Problem receiving SIGUSR1");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        perror("Error - Problem receiving SIGUSR2");
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Server PID: %i\n", pid);
    sig_handler();
    while (1)
        pause();
    return 0;
}
