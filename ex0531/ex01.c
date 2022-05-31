#include <stdio.h>
#include <stdlib.h>

void atexit_handler1()
{
    printf("atexit_handler1 함수 호출합니다.\n");
}

void atexit_handler2()
{
    printf("atexit_handler2 함수 호출합니다.\n");
}

int main()
{
    atexit(atexit_handler1);
    atexit(atexit_handler2);
    exit(0);
    // 실행시 handler2, handler1 순으로 실행되는 것으로 보아
    // stack 구조이다.

    // getpid = 프로세스의 ID리턴
    // getppid = 부모 프로세스의 ID리턴
    
}