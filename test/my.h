#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>

typedef struct user{
int id;
char name[18];
char htel[12];
char tel[12];
}recorder;

int input();
int save(recorder *);
int output();
int mysort();
int randdat();
int cmp1();
int cmp2();
int mysort();

