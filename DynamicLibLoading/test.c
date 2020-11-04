#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <link.h> 
//函数指针
typedef int (*funcType)(int);

int main(int argc, char **argv)
{
    if(argc<3)
    {
        printf("usage: %s <library> <number>\n", argv[0]);
        exit(1);
    }

    char *librarypath = argv[1];
    int thenumber = atoi(argv[2]);

    void *libhandle = dlopen(librarypath, RTLD_LAZY);
    //void *libhandle = LoadLibrary(librarypath, RTLD_LAZY);

    if(libhandle == NULL)
    {
        perror("dlopen");
    }

    //int (*opfunc) (int);
    //opfunc = dlsym(libhandle, "do_operation");

    funcType opfunc = dlsym(libhandle, "do_operation");

    //funcType opfunc = GetProcAddress(libhandle, "do_operation");

    printf("%d --> %d\n", thenumber, opfunc(thenumber));

    dlclose(libhandle);
    //FreeLibrary(libhandle);

}