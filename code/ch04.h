#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
void err_exit(char *s)
{       
       printf("Usage:%s is flase\n",s);
}  