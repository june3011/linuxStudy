#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	int fd = open("myfile",O_RDWR);
	if (fd == -2){
		printf("File is nothing\n");
	}else{
		printf("Opening file successed!\n");
	}
	return 0;
}

// 자동정렬 = shift + v 로 블럭지정 + 화살표(=)
// shift + v로 지정 후에 명령어 모드로
// norm i// 하면 주석처리
// 파일 내용 읽기(myfile)
