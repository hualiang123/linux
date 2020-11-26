#include"./ch10.h"
int main()
{
        int r;
        printf("10-4 :pid=%d,ppid=%d",getpid(),getppid());
        system("./test hello world 2020 11 23 ");
        printf("after calling\n");
        return 0;
}

