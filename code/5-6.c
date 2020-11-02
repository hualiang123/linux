#include"ch05.h"
int main(){
char buf[20];
int ret;
FILE *fp= fopen("./tmp.txt","w+");
if(!fp){
printf("fail to open file!\n");
exit(-1);
}
	ret =fwirte("123",sizeof("123",1,fp));
	printf("we write %d byte\n",ret);
	memset(buf,0,sizeof(buf));
	lseek(fp,0,SEEK_SET);
	ret=fread(buf,1,1,fp);
	printf("we read %s,ret is %d\n",buf,ret);
	fwrite("456",sizeof("456"),1,fp);
	fclose(fp);
	return 0;
}
