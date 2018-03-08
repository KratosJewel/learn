//
// Created by kratos on 18-3-1.
//

#include <pthread.h>
#include <iostream>
#include <unistd.h>

pthread_t ntid;
pthread_t ntid2;

void printids(std::string str)
{
    pid_t pid = getpid();

    // 获取当前线程
    pthread_t tid = pthread_self();

    std::cout << str << " pid " << pid << " tid " << tid << std::endl;
}

void *thr_fn(void *arg)
{
    sleep(2);
    printids("new thread:");

    // 直接结束线程，参数可以通过 pthread_join 获得
    // pthread_exit((void *) "test");
    return ((void *) 2);
}

void *thr_fn2(void *arg)
{
    printids("new thread2:");
    //线程分离
    pthread_detach(pthread_self());
    return ((void *) 2);
}

int main(int argc, char *argv[])
{
    // 创建线程，成功返回0
    int result = pthread_create(&ntid, NULL, thr_fn, NULL);

    // 创建分离线程
    int result2 = pthread_create(&ntid2, NULL, thr_fn2, NULL);

    if (0 != result)
    {
        std::cout << "create code:" << result << std::endl;
    }

    printids("main thread:");

    void *tret = NULL;

    // 等待线程结束，成功返回0
    result = pthread_join(ntid, &tret);

    if (0 != result)
    {
        std::cout << "join code:" << result << std::endl;
    }

    return 1;
}