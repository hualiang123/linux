#include"3-2.h"

int main()
{
	FILE *fp;
	char buf[80];
	memset(buf,0,sizeof(buf));
	if((fp=fopen("./test1.txt","w"))==NULL)
	perror("open failed!\n");
	printf("Please input:");
	fgets(buf,sizeof(buf),stdin);
	printf("Content is %s\n",buf);
	fwrite(buf,sizeof(buf),1,fp);
	fclose(fp);
	return 0;

}