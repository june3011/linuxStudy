#include <stdio.h>
#define MAXLINE 100

// 문자열을 입력 받아 긴 문자열일 때 출력...하는 프로그램
// shift + v 한 줄 선택
// y 복사
// p 붙여넣기

void copy(char from[], char to[]);

char line[MAXLINE];
char regstr[MAXLINE];

int main(){
	int max=0;

	while(1){
		gets(line);
		printf("line = %s\n", line);

		int size = strlen(line);
		printf("size = %d\n", size);

		if ( max<size){
			max = size;
			copy(regstr,line);
		}
		printf("regstr = %s\n\n",regstr);
	}

	// 정상종료 일 때는 0을 리턴한다.
	return 0;
}

// u 뒤로 가기 ctrl+r 앞으로가기
// ctrl + z ps 프로세스
// fg
// bg
//
void copy(char from[], char to[]){
	int i=0;
	while( (from[i] = to[i]) !='\0'){
		i++;
	}
}
