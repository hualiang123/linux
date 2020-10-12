#include"3-2.h"
int main()
{       
        FILE *fp;
        char buf[80];
        memset(buf,0,sizeof(buf));
        fp=fopen("./test1.txt","a+");
        fputs("append new infomation!",fp);
        fp=freopen("./test1.txt","r",fp);
        fgets(buf,sizeof(buf),fp);    //读取到换行的时候会结束
        printf("Content of file:%s\n",buf);
        fclose(fp);
        return 0;

} 