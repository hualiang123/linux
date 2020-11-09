#include"ch08.h"
int main()
{
int *pt=NULL;
int i,max;
max=1024*1024;
for(i=0;i<2048;i++)
{
pt=(int *)malloc(i*max);
if(!pt)
{
perror("malloc failed\n");
exit(-1);
}
else
{
printf("malloc %dMB\n",i);
}
}
free(pt);
return 0;
}
