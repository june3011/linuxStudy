#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char type(mode_t mode)
{
    if (S_ISREG(mode)) return '-';
    if (S_ISDIR(mode)) return 'd';
}

char *perm(mode_t mode)
{
    static char myString[10] = "---------";     // - 9개 + 마지막 null

    if (mode & S_IREAD){
        myString[1] = 'r';
    }
    if (mode & S_IWRITE){
        myString[2] = 'w';
    }
    if (mode & S_IEXEC){
        myString[3] = 'x';
    }
    if (mode & S_IREAD >> 3){
        myString[4] = 'r';
    }
    if (mode & S_IWRITE >> 3){
        myString[5] = 'w';
    }
    if (mode & S_IEXEC >> 3){
        myString[6] = 'x';
    }
    if (mode & S_IREAD >> 6){
        myString[7] = 'r';
    }
    if (mode & S_IWRITE >> 6){
        myString[8] = 'w';
    }
    if (mode & S_IEXEC >> 6){
        myString[9] = 'x';
    }
    return myString;
}

void printStat(char *pathname, char *file, struct stat *st)
{
    printf("%c%s", type(st->st_mode), perm(st->st_mode));
    printf(" %ld\t", st->st_blocks);
    printf(" %3ld", st->st_nlink);
    printf(" %s %s", (getpwuid(st->st_uid))->pw_name,
           (getgrgid(st->st_gid))->gr_name);
    printf(" %9ld", st->st_size);
    printf(" %.12s", ctime(&st->st_mtime));
    printf(" %s\n", file);}

int main()
{
    // 디렉토리,파일 엔트
    DIR *dp;
    // 디렉토리,파일 담는곳
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    char directoryname[512];

    // char fileMode[20] = file_info.st_mode;

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

    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", directoryname, d->d_name);
        if (lstat(path, &st) < 0){
            perror(path);
        }

        printStat(path, d->d_name, &st);

    }
    return 0;
} 