#include"my.h"

int input()
{
	recorder *pt;
	char c;	
	int *id;
	int i=0;
	FILE *pp;
	pp=fopen("./id.dat","a+");
	id=(int*)malloc(sizeof(int)*1);
	while(fscanf(pp,"%d ",&id[i])>0)
	{
		id=(int*)realloc(id,sizeof(int)*(i+2));
		i++;
	}
	do{
	int flag=1;
	pt=(recorder *)malloc(sizeof(recorder));
	memset(pt,0,sizeof(recorder));
	while(flag)
	{
		int m=0;
		printf("Please input userid:");
		scanf("%d",&(pt->id));
		for(int j=0;j<=i;j++)
		{
			if(pt->id!=id[j])
			{
				m++;
			}
			else
			{
				break;
			}
		}
		if(m<i)
		{
			printf("The id had exist,please input against!\n");
		}
		else
		{
			id=(int*)realloc(id,sizeof(int)*(i+2));
			id[i+1]=pt->id;
			fprintf(pp,"%d ",pt->id);
			i++;
			flag=0;
		}	
	}	

	printf("Please input useriname:");
	scanf("%s",pt->name);
	printf("Please input userhtel:");
	scanf("%s",pt->htel);
	printf("Please input usertel:");
	scanf("%s",pt->tel);
	save(pt);
	printf("Do you want to input against?(y/n):");
	fgetc(stdin);
	c=fgetc(stdin);
	}
	while(c=='y');
	return 1;
}

int save(recorder *p)
{
	FILE *fp;
	if((fp=fopen("./user.dat","a+"))==NULL)
	{
		printf("create error");
		exit(1);
	}
	fprintf(fp,"%03d\t%s\t%s\t%s\n",p->id,p->name,p->htel,p->tel);
	return 1;
}

int output()
{
	FILE *fp;
	recorder rd;
	if((fp=fopen("./user.dat","r+"))==NULL)
	{
		printf("open error!");
		exit(1);
	}
	printf("id\tname\thtel\ttel\n");
	while(fscanf(fp,"%d\t%s\t%s\t%s\n",&rd.id,rd.name,rd.htel,rd.tel)>0)
	{
		printf("%03d\t%s\t%s\t%s\n",rd.id,rd.name,rd.htel,rd.tel);	
	}
	return 1;
}


int cmp1(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}

int cmp2(const void *a,const void *b)
{
	return strcmp((char*)b,(char*)a);
}

int mysort()
{
	FILE *p=fopen("./user.dat","r+");
	int i=0;
	int k;
	recorder *red;
	char a[100][18];
	red=(recorder*)malloc(sizeof(recorder));
	while(fscanf(p,"%d\t%s\t%s\t%s\n",&red[i].id,a[i],red[i].htel,red[i].tel)>0)
	{
		red=(recorder*)realloc(red,sizeof(recorder)*(i+2));
		i++;
	}
	printf("1.Asc\n2.Desc\nPlease select sorting method:");
	scanf("%d",&k);
	if(k==1)
	{
		qsort(a,i,sizeof(char)*18,cmp1);
	}
	else
	{
		qsort(a,i,sizeof(char)*18,cmp2);
	}	
	for(int j=0;j<i;j++)
	{
		printf("%s\n",a[j]);
	}
	return 1;
}

int randdat()
{
	recorder red;
	int i,j,k;
	char str[4];
	srand((unsigned)time(NULL));
	red.id=rand()%2147483648;
	int n=rand()%6+2;
	for(i=0;i<n;i++)
	{
		if(i==0)
		red.name[i]=rand()%26+65;
		else
		red.name[i]=rand()%26+97;	
	}
	red.name[i]='\0';
	
	for(j=0;j<11;j++)
	{
		if(j==2)
		red.htel[j]='-';
		else
		red.htel[j]=rand()%10+48;	
	}
	red.htel[j]='\0';

	do
	{
		for(k=0;k<11;k++)
		{
			red.tel[k]=rand()%10+48;
		}
		strncpy(str,red.tel,3);
		str[3]='\0';
		red.tel[k]='\0';
	}
	while(strcmp(str,"130")&&strcmp(str,"131")&&strcmp(str,"133")&&strcmp(str,"138"));

	printf("randdat is:\n");
	printf("id\t\tname\thtel\t\ttel\n");
	printf("%d\t%s\t%s\t%s\n",red.id,red.name,red.htel,red.tel);
	return 1;
}



