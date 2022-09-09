#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "data.dat"
#define DATA_NUM 10
struct my_data
{     
	char f_name[10];
    char g_name[10];  
	int id;
};

int main()
{
	FILE * f;
	f = fopen(FILE_NAME, "w+b");

	struct my_data items_to_store[DATA_NUM];
	memset(items_to_store, '\0', sizeof(items_to_store));
	strcpy(items_to_store[0].f_name, "WANG");
    strcpy(items_to_store[0].g_name, "JUN");
    items_to_store[0].id = 1;

	strcpy(items_to_store[1].f_name, "WANG");
    strcpy(items_to_store[1].g_name, "YING");
    items_to_store[1].id = 2;

	strcpy(items_to_store[2].f_name, "MEI");
    strcpy(items_to_store[2].g_name, "YUTONG");
    items_to_store[2].id = 3;

	strcpy(items_to_store[3].f_name, "QU");
    strcpy(items_to_store[3].g_name, "JIA");
    items_to_store[3].id = 4;

	strcpy(items_to_store[4].f_name, "OU");
    strcpy(items_to_store[4].g_name, "WEILAI");
    items_to_store[5].id = 5;

	strcpy(items_to_store[5].f_name, "NI");
    strcpy(items_to_store[5].g_name, "JUN");
    items_to_store[6].id = 6;

	strcpy(items_to_store[6].f_name, "WANG");
    strcpy(items_to_store[6].g_name, "ZHAO");
    items_to_store[7].id = 7;

	strcpy(items_to_store[7].f_name, "SHENG");
    strcpy(items_to_store[7].g_name, "YIJIA");
    items_to_store[8].id = 8;

	strcpy(items_to_store[8].f_name, "SONG");
    strcpy(items_to_store[8].g_name, "YING");
    items_to_store[9].id = 9;
	
	strcpy(items_to_store[9].f_name, "SUN");
    strcpy(items_to_store[9].g_name, "ENZE");
    items_to_store[9].id = 10;

	fwrite(items_to_store, sizeof(struct my_data), 10, f);
	
	
	fclose(f);
}

