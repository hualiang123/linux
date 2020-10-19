#include"ch04.h"
int main()
{
	int d1,d2;
	d1=open("./out1.info",O_CREAT|O_TRUNC|O_WRONLY,0644);
	dup2(d1,1);
	printf("Redirect stdout file!\n");
	return 0;
}
