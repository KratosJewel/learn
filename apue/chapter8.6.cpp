//
// Created by kratos on 18-1-17.
//

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

void PrExit(int status)
{
    if (WIFEXITED(status))
    {
        std::cout << "normal termination, exit status = " << WEXITSTATUS(status) << std::endl;
    }
    else if (WIFSIGNALED(status))
    {
        std::cout << "abnormal termination, signal number = " << WTERMSIG(status)
                  << (WCOREDUMP(status) ? " (core file generated)" : "") << std::endl;
    }
    else if (WIFSTOPPED(status))
    {
        std::cout << "child stopped, signal number = " << WSTOPSIG(status) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    int pid = 0;
    int status = 0;

    // 正常结束
    pid = fork();

    if (0 > pid)
    {
        std::cerr << "fork error" << std::endl;
        return 0;
    }
    else if (0 == pid)
    {
        exit(35);
    }

    if (pid != waitpid(pid, &status, 0))
    {
        std::cerr << "waitpid error" << std::endl;
    }
    else
    {
        PrExit(status);
    }

    // 异常结束
    pid = fork();

    if (0 > pid)
    {
        std::cerr << "fork error" << std::endl;
        return 0;
    }
    else if (0 == pid)
    {
        abort();
    }

    if (pid != waitpid(pid, &status, 0))
    {
        std::cerr << "waitpid error" << std::endl;
    }
    else
    {
        PrExit(status);
    }

    // 除以0异常结束
    pid = fork();

    if (0 > pid)
    {
        std::cerr << "fork error" << std::endl;
        return 0;
    }
    else if (0 == pid)
    {
        status /= 0;
    }

    if (pid != waitpid(pid, &status, 0))
    {
        std::cerr << "waitpid error" << std::endl;
    }
    else
    {
        PrExit(status);
    }

    return 1;
}