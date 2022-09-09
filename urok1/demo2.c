#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define  K 1000
#define N 10
struct elm {
   char item[K];
   int  pos;
   float sum;
};
typedef struct elm elm;
int main() {
    	elm  goods[N];
	elm*  some_memory;
	int  exit_code = EXIT_FAILURE;
	int i;
	some_memory = (elm *)malloc(sizeof(goods));
	if (some_memory != NULL) {
		for(i=0; i<N; i++) {
			sprintf(some_memory[i].item, "Item N %d\n", i); printf("some_memory[%d] - %s \n",i,some_memory[i].item);
             		strcpy(goods[i].item,some_memory[i].item);
			printf("goods[%d] - %s  \n",i, goods[i].item);
      		}
        sleep(10);
        exit_code = EXIT_SUCCESS;
	}
    	exit(exit_code);
}
