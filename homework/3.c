/*struct*/
typedef struct Node
{
	int num;//记录编号
	int len;//记录长度
}

/*function*/
char * seek(int k,char *fd)
{
	char buf[2048];
	char length[4];
	int lensum=0; //1到k个记录的总长度
	memset(buf,0,sizeof(buf));
	struct Node *p=(struct Node *)malloc(sizeof(Node)*(n+1));
	len=StrToInt(length);
	for(int i=1;i<=k;i++){  //求出每个记录的长度
			char length[4];
			memset(length,0,4);
			p[i].num=i;
			fseek(fd,4*k,SEEK_SET);
			fwrite(length,4,1,fd);
			p[i].len=StrToInt(length);
			lensum+=p[i].len;
	}	
	fseek(fd,lensum-p[k].len,SEEK_SET); //将指针移动到第k个记录处
	fwrite(buf,p[k].len,1,fd); //读取记录
	return buf;
}
