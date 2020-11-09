#include"ch08.h"
static g=100,k;
void fun(void)
{
	int x,y;
	int *p=(int *)malloc(4);
	printf("fun:address x of x=%x,y=%x,p=%x\n",&x,&y,p);
	sleep(20);
}
int main()
{
	int i=0,j=0,a[10]={1};
	static int w=100;
	int *pt=(int *)malloc(sizeof(int)*10);
	printf("address of g=%x,k=%x\n",&g,&k);
	printf("address of i=%x,j=%x,a=%x\n",&i,&j,a);
	printf("address of g=%x,w=%x\n",&w);
	printf("address of pt=%d\n\n",pt);
	fun();
	return 0;

}
