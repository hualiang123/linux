#include"ch09.h"
int main()
{
	int pid;
	int s;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child:pid=%d,ppid=%d\n",getpid(),getppid());
		exit(23);
	}
	else
	{
		int y;
		y=wait(&s);
		if(WIFEXITED(s))
			printf("chile %d is nomal back.The exit code=%d\n",y,WEXITSTATUS(s));
	}
}
