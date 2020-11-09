#include"../ch08.h"
void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}


void mysort(int a[])
{
	int len=sizeof(a)/sizeof(int);
	qsort(a,len,sizeof(int),cmp);
	for(int i=0;i<len;i++)
	{
		printf("%d",a[i]);
	}
}
