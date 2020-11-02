#include"ch07.h"
char test_env[]="test_env=test";
static void set_env_string(void)
{
	
	if(putenv(test_env)!=0)
	{
		printf("Putenv is failed!\n");
	}
	printf("The test_env= %s\n",getenv("test_env"));
}

static void show_env_string()
{
	printf("The test_env=%s\n",getenv("test_env"));
}
int main()
{
	set_env_string();
	show_env_string();
	return 0;
}
