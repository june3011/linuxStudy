#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZ 1024

int main(int argc, char **argv)
{
    int cnt = 0;
    char fileName[20];
    char continueProgram;
    // do{
        if (argc != 2){
            printf("Please type again\n");
            printf("%s \"fileName\"\n", argv[0]);
            exit(0);
        }

        int fd = open(argv[1], O_RDWR);

        if (fd < 0)
        {
            printf("존재하지 않는 파일입니다.\n");
            exit(0);
        }

        char fileContents[1000];
        
        int nread = read(fd, fileContents, BUFSIZ);

        printf("파일 이름 : %s\n", argv[1]);
        printf("파일 내용 : (아랫 줄 부터 시작)\n");
        printf("%s\n", fileContents);

        close(fd);
        
        // scanf("%c", &continueProgram);


    // } while(continueProgram == 'Y' || continueProgram == 'y');
    return 0;
}