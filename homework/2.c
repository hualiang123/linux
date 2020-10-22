#include"ch04.h"
#define SIZE 8
int main(void)
{
        struct iobuf{
        char buf[SIZE];
        char others[SIZE];
        }buffer;
        memset(&buffer,'\0',sizeof(struct iobuf));
	printf("please input your string:");
	gets(buffer.buf);
        printf("the string gets() get is:%s\n",buffer.buf);
        printf("buffer.buf is:%s\n",buffer.others);
        return 0;
}

