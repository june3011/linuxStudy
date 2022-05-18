#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZ 1024

int main()
{
    int fd;
    char fileName[20];
    char fileContent[1000];
    char addContent[1000];
    // char result[1000];

    char continueProgram;
    // fd = open("studentdb", O_RDWR);

    // if (fd == -1){
    //     printf("file open fail");
    // }

    
        printf("내용을 추가할 파일 이름을 입력하세요. ");
        scanf("%s", fileName);

        fd = open(fileName, O_RDWR);

        if (fd >= 0){
            do{

                int nread = read(fd, fileContent, BUF_SIZ);
                if( nread > 0){
                    printf("현재파일 내용:\n%s\n",fileContent);
                }

                printf("파일에 추가할 내용을 입력하세요 :");
                scanf("%s", addContent);
                getchar();

                lseek(fd,0,SEEK_END);
                write(fd, addContent, strlen(addContent));


                // bufSize = strlen(fileContent);
                // printf("%d\n", bufSize);

                // lseek(fd,0,SEEK_SET);
                // read(fd, fileContent, bufSize);

                // lseek(fd, bufSize, SEEK_SET);

                // printf("현재 파일 내용:\n");
                // printf("%s\n", fileContent);

                // printf("파일에 추가할 내용을 입력하세요: ");
                // scanf("%s", addContent);
                // getchar();

                // strcat(fileContent, addContent);
                // bufSize = strlen(fileContent);
                // printf("concat : %s", fileContent);

                // // lseek(fd, 0, SEEK_END);
                // write(fd, fileContent, bufSize);

                // printf("\n수정된 내용:\n");
                // printf("%s\n", fileContent);
                printf("계속해서 수정하시겠습니까? (Y/N) :  ");
                scanf("%c", &continueProgram);
            } while(continueProgram == 'Y' || continueProgram == 'y');
            
        } else {
            printf("존재하지 않는 파일입니다.\n");
        }
        close(fd);
        
        // getchar();
    
    printf("수정 프로그램이 종료되었습니다.\n");
}