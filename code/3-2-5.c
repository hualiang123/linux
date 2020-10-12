#include"3-2.h"

int main(int argc,char *argv[])
{
        FILE *fp;
        int i;
        if((fp=fopen("./test1.txt","w"))==NULL)
        perror("open failed!\n");
        for(i=0;i<argc;i++)
        {
                fwrite(argv[i],1,strlen(argv[i]),fp);
        }
        fclose(fp);
        return 0;
}
