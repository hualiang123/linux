#include<stdio.h>

#include <float.h>
int main(void)
{
	int i=0,min,max;
	while(1){
		if(i+1<=0){
			max=i;
			min=i+1;
			break;
}
i++;
}
printf("max int is %d\nmin int is %d\n",max,min);
printf("min float is: %E\n", FLT_MIN );
printf("max float is: %E\n", FLT_MAX );
printf("min double is: %E\n", DBL_MIN );
printf("max double is: %E\n", DBL_MAX );
return 0;

}
