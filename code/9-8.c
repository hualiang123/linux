#include"ch09.h"
int main(){
    pid_t pid[2];
    FILE *p;
    p=fopen("./out.dat","a+");
    int g=0;
    g++;
    printf("Root pid is %d,g is %d.\n",getpid(),g);
    fprintf(p,"%d : g=%d\n",getpid(),g);
    for( int i=0;i<2;++i ){
        pid[i] = vfork();

        if( pid[i]==0 ){
	    g++;
            printf("My parent is %d, my pid is %d,g is %d.\n",getppid(),getpid(),g);
fprintf(p,"%d : g=%d\n",getpid(),g);
	    if(i==0)
            for( int j=0;j<2;++j ){
                pid[j] = vfork();
                if( pid[j]==0 ){
                    g++;
            	    printf("My parent is %d, my pid is %d,g is %d.\n",getppid(),getpid(),g);
fprintf(p,"%d : g=%d\n",getpid(),g);
                    printf("Process %d had exited.\n",getpid());
                    exit(0);
                }
		else if( pid[j]!=-1 ){
                    printf("Parent process %d create child process %d.\n",getpid(),pid[j]);
                }
		else{
                    printf("Error: when %d fork()!\n",getpid());
                }
            }


            for( int j=0;j<2;++j ){
                waitpid(pid[j],NULL,0);
            }
            printf("Process %d had exited.\n",getpid());

            exit(0);
        }else if( pid[i]!=-1 ){
            printf("Parent process %d create child process %d.\n",getpid(),pid[i]);
        }else{
            printf("Error: when %d fork()!\n",getpid());
        }
    }


    for( int i=0;i<2;++i ){
        waitpid(pid[i],NULL,0);
    }

    printf("Process %d had exited.\n",getpid());
    exit(0);
}
