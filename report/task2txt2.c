#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <gdbm.h>
#include <string.h>
#define TEST_DB_FILE "gdbm3_test.gdbm"
#define ITEMS_USED 10

struct my_data
{
    char key[20];
    char value[20];
};

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    datum key_datum;
    datum data_datum;
    GDBM_FILE gdbmf;
    gdbmf = gdbm_open(TEST_DB_FILE, 0, GDBM_WRCREAT, 0, NULL);
    if (gdbmf == NULL)
    {
        fprintf(stderr, "Failed to open database\n");
        gdbm_strerror(gdbm_errno);
        exit(EXIT_FAILURE);
    }

    FILE *f;

    f = fopen(argv[1], "r");
    struct my_data items_to_store[ITEMS_USED];
    char key_to_use[20];
    char datum_to_use[20];
    int i, result;

    for(int i = 0; i < ITEMS_USED; ++i)
    {
        fscanf(f, "%s", items_to_store[i].key);
        fgets(items_to_store[i].value, 20, f);
        items_to_store[i].value[strlen(items_to_store[i].value) - 1] = '\0';
    }

    for (i = 0; i < ITEMS_USED; ++i)
    {

        sprintf(key_to_use, "%s", items_to_store[i].key);

        key_datum.dptr = (void *)key_to_use;
        key_datum.dsize = strlen(key_to_use);

        memccpy(datum_to_use, items_to_store[i].value, 0, 20);
        data_datum.dptr = (void *)datum_to_use;
        data_datum.dsize = strlen(datum_to_use);

        result = gdbm_store(gdbmf, key_datum, data_datum, GDBM_REPLACE);
        if (result != 0)
        {
            fprintf(stderr, "gdbm_store failed on key %s\n", key_to_use);
            exit(2);
        }
    }
    key_datum.dptr = argv[2];
    key_datum.dsize = strlen(argv[2]);

    data_datum = gdbm_fetch(gdbmf, key_datum);
    if (data_datum.dptr)
    {
        printf("Data was found\n");
        printf("The value is - %s\n", data_datum.dptr);
    }
    else
    {
        printf("No data found for key %s\n", argv[2]);
    }
    gdbm_close(gdbmf);
    fclose(f);
    exit(EXIT_SUCCESS);
}
