#include <unistd.h> 
#include <stdio.h>
int main(int argc, char* argv[])
{
        long mempagesize = sysconf(_SC_PAGESIZE);
        printf("memory pagesize: %li\n", mempagesize);
        return 0;
}
