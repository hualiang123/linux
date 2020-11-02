#include"ch07.h"
static void __attribute__((constructor)) before_main()
{
printf("before main\n");
}
static void __attribute__((constructor)) after_main()
{
printf("after main\n");
}

int main()
{
printf("mian\n");
	return 0;
}
