/*struct*/
typedef struct Node
{
	int num;
	int len;
}

/*function*/
char * seek(int k,char *fd)
{
	char buf[2048];
	char length[4];
	int lensum=0;
	memset(buf,0,sizeof(buf));
	struct Node *p=(struct Node *)malloc(sizeof(Node)*(n+1));
	len=StrToInt(length);
	for(int i=1;i<=k;i++){
			char length[4];
			memset(length,0,4);
			p[i].num=i;
			fseek(fd,4*k,SEEK_SET);
			fwrite(length,4,1,fd);
			p[i].len=StrToInt(length);
			lensum+=p[i].len;
	}	
	fseek(fd,lensum-p[k].len,SEEK_SET);
	fwrite(buf,p[k].len,1,fd);
	return buf;
}
