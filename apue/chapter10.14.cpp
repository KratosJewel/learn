//
// Created by kratos on 18-1-30.
//

#include <signal.h>
#include <iostream>
#include <unistd.h>

typedef void Sigfunc(int);

Sigfunc *wsignal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (SIGALRM == signo)
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }
    else
    {
        act.sa_flags |= SA_RESTART;
    }

    if (0 > sigaction(signo, &act, &oact))
    {
        return SIG_ERR;
    }

    return oact.sa_handler;
}

static void ale(int num)
{
    std::cout << num << std::endl;
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, ale);

    alarm(1);

    sleep(2);

    return 1;
}
