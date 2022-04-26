#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MYEMPTY while(getchar()==\n);


typedef struct s
{
    char name[24];
    int id;
    int score;
} STUDENT;

// 입력 버퍼 지우기
void stdempty(){
    // while(getchar()=='\n');
    getchar();
}

int main()
{
    int fd;
    // int fd1;
    fd = open("studentdb", O_RDWR);

    if (fd == -1){
        printf("file open fail");
    }

    // fd1 = open("studentdb", O_RDONLY);
    // printf("fd = %d", fd);
    // printf("fd1 = %d", fd1);

    char c;
    STUDENT student;
    // STUDENT *student1 = &student;

    do {
        printf("찾을 학생의 번호를 입력하세요. ");
        scanf("%d", &student.id);
        getchar();
        if (student.id > 0){
            lseek(fd, sizeof(student) * student.id, SEEK_SET);
            // lseek(파일 디스크립터, 버퍼의 크기, 기준위치
            // 처음부터 sizeof(student) 만큼 커서이동
            // SEEK_CUR 현재 위치, SEEK_SET 처음, SEEK_END 마지막
            read(fd, &student, sizeof(student));
            // read(파일 디스크립터, 파일을 읽어 들일 버퍼, 버퍼의 크기);

            printf("학번 = %d, 이름 = %s, 점수 = %d\n", student.id, student.name, student.score);

            printf("수정하실 점수를 입력하세요. ");
            scanf("%d", &student.score);    // score 를 새로 입력받고
            stdempty();
            if (student.score != 0) {
                lseek(fd, -sizeof(student), SEEK_CUR);
                write(fd, &student, sizeof(student));   // 바뀐 값 써주기
            }
        }

        printf("계속 하시겠습니까? (Y/N) ");
        scanf("%c", &c);
        getchar();

    } while (c == 'Y' || c == 'y');
    close(fd);
    
    return 0;   
}