#include"../ch07.h"
int main()
{
        void *dlib=dlopen("./libdlib.so",RTLD_NOW);
        if(!dlib)
        {
                printf("dlopen failed!\n");
                exit(-1);
        }
        void(*dfunc) (void)=dlsym(dlib,"dynamic_lib_call");
	void(*fn) (int)=dlsym(dlib,"dsum");
	if(!dfunc||!fn)
	{
		printf("dfunc is failed!\n");
		exit(-1);
	}
	dfunc();
	fn(100);
	dlclose(dlib);
        return 0;
}
      
    
