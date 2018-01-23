//
// Created by kratos on 18-1-9.
//

#include <iostream>
#include <dirent.h>
#include <cstring>
#include <boost/timer.hpp>

void PrintDirInfo(const std::string &root_path)
{
    DIR *dir = opendir(root_path.c_str());

    if (NULL == dir)
    {
        return;
    }

    dirent *dir_info = nullptr;
    std::string full_path = "";

    while (NULL != (dir_info = readdir(dir)))
    {
        // 跳过 "." “..” 和 无效的文件
        if (0 == strcmp(dir_info->d_name, ".") || 0 == strcmp(dir_info->d_name, "..")
            || DT_UNKNOWN == dir_info->d_type)
        {
            continue;
        }

        // 完整路径
        full_path = std::move(root_path + "/" + dir_info->d_name);

        switch (dir_info->d_type)
        {
            // 如果是目录递归遍历
            case DT_DIR:
                PrintDirInfo(full_path);
                break;
            // 记录其他类型的文件
            case DT_REG:
                break;
        }
        //std::cout << full_path << std::endl;
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        std::cerr << "command error" << std::endl;
        return 0;
    }

    std::string &&root_path = std::move(argv[1]);

    boost::timer t;

    for (int i = 0; i < 10; ++i)
    {

        PrintDirInfo(root_path);

        std::cout << t.elapsed() <<std::endl;
        t.restart();
    }

    return 1;
}