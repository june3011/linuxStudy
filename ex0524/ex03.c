#include <stdio.h>

int main(int argc, char *argv[])
{

    for (int i=1; i<argc; i++) {
        printf("%s", argv[i]);
    }

}

// 환경 변수로 만들면 어떤 경로에 있어도 실행할 수 있다

