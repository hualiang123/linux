#include"ch07.h"
static void __attribute__((destructor)) after_main()
{
printf("after main\n");
}
static void callback1(void)
{
printf("callback\n");
}
static void callback2(void)
{
printf("callback2\n");
}
static void callback3(void)
{
printf("callback3\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
        atexit(callback3);
	printf("main\n");
	exit(0);
	//_exit(0);
return 0;
}
