#include"ch09.h"
int main()
{
        pid_t i;
        i=vfork();
        if(i<0)
        {
                perror("vfork failed!\n");
                exit(-1);
        }
        else if(i==0)
        {
                printf("child:pid=%d,ppid=%d,i=%d\n",getpid(),getppid(),i);
                _exit(0);
        }
        else
        {
                wait(NULL);
                printf("parent:pid=%d,ppid=%d,i=%d\n",getpid(),getppid(),i);
                _exit(0);
        }

}


