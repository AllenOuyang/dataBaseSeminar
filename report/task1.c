#include <stdio.h>
#include <string.h>
#include <gdbm.h>
int main(int argc, char **argv)
{
    GDBM_FILE gdbf;
    datum key, content;
    int status = 0;

    if (argc != 3)
    {
        fprintf(stderr, "usage: %s DBFILE KEY\n", argv[0]);
        return 2;
    }

    gdbf = gdbm_open(argv[1], 0, GDBM_READER, 0, NULL);
    if (gdbf == NULL)
    {
        fprintf(stderr, "can't open database: %s\n",
                gdbm_strerror(gdbm_errno));
    }

    key.dptr = argv[2];
    key.dsize = strlen(argv[2]);

    content = gdbm_fetch(gdbf, key);

    if (content.dptr != NULL)
    {

        fwrite(content.dptr, content.dsize, 1, stdout);
        putchar('\n');
        status = 0;
    }
    else if (gdbm_errno == GDBM_ITEM_NOT_FOUND)
    {
        fprintf(stderr, "no such key\n");
        status = 1;
    }
    else
    {
        fprintf(stderr, "%s\n", gdbm_db_strerror(gdbf));
        status = 2;
    }

    gdbm_close(gdbf);
    return status;
}
