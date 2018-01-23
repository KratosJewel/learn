//
// Created by kratos on 17-12-18.
//

#include <dirent.h>
#include <iostream>

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        std::cerr << "command error" << std::endl;
        return 0;
    }

    DIR *dir = nullptr;

    //打开目录进行操作
    dir = opendir(argv[1]);

    if (NULL == dir)
    {
        std::cerr << "can't open " << argv[1] << std::endl;
        return 0;
    }

    dirent *dir_info = nullptr;

    //循环输出目录信息
    while (NULL != (dir_info = readdir(dir)))
    {
        std::cout << dir_info->d_name << std::endl;
    }

    //关闭目录
    closedir(dir);

    return 1;
}