#include"ch07.h"
int main(int argc ,char* argv[])
{
for(int i=0;i<argc;i++)
{
printf("argv[%d]:%s\n",i,argv[i]);
}
int a,b;
	if(argc!=3)
	{
		printf("input error!");	
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("%d",a+b);
}
