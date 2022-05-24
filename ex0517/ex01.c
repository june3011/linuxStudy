#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/*
디렉토리 만들기
mkdir();
*/

/*
    ./ex01 argc=1
    ./ex01 aa argc=2

*/

int main(int argc, char **argv)
{

    char di_name[20];
    char *di_name2 = "aaa";

    if (argc != 2){
        strcpy(di_name, "temp");
    }
    else {
        strcpy(di_name, argv[1]);
    }

    printf("di_name = %s\n", di_name);

    if (mkdir(di_name, 0777) == -1){
        perror("making is fail");
        return 1;
    }
    
    // if (argc == 3)
    // {
    //     int perm = strtol(argv[2], (char **)NULL, 8);
    //     chmod(argv[2], perm);
    // }

    return 0;

}