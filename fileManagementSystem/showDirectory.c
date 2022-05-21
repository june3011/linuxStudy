#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // 디렉토리,파일 엔트
    DIR *dp;
    // 디렉토리,파일 담는곳
    struct dirent *d;

    char directoryname[512];

    printf("디렉토리 경로를 입력하세요: (현재 폴더 경로 : .)");
    scanf("%s", directoryname);

    // if (argc == 1)
    // if (directoryname == "\n")
    // {
    //     strcpy(directoryname, ".");
    // }
    // else
    // {
    //     // strcpy(directoryname, argv[1]);
    //     // strcpy(directoryname, directoryPath);
    //     strcpy(directoryname, directoryname);
    // }
    printf("directoryname =  %s\n", directoryname);

    dp = opendir(directoryname);

    if (dp == NULL)
    {
        perror("dp is null");
        exit(0);
    }

    printf("--------------------\n");
    while ((d = readdir(dp)) != NULL)
    {
        printf("%s\n", d->d_name);
    }
    printf("--------------------\n");

    return 0;
} 

