#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>

int main()
{

    // DIR *dir_info;
    // struct dirent *d;

    char directoryName[20];

    printf("새로 만들 디렉토리 명을 입력하세요. ");
    scanf("%s", directoryName);

    int nmkdir = mkdir(directoryName, 0755);

    // 디렉토리가 생성되었다면
    if (nmkdir >= 0)
    {
        printf("디렉토리가 잘 생성되었습니다.\n");

        // dir_info = opendir(".");

        // if (dir_info != NULL)
        // {
        //     while (d = readdir(dir_info))
        //     {
        //         printf("%s\n", d->d_name);
        //     }
        //     closedir(dir_info);
        // }
    }
    else
    {
        printf("중복되는 디렉토리 명입니다.\n디렉토리 생성에 실패하였습니다.\n");
    }
}