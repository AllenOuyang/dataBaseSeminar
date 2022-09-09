#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <gdbm.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    GDBM_FILE gdbmf;
    gdbmf = gdbm_open(argv[1], 0, GDBM_READER, 0, NULL);
    datum key = gdbm_firstkey(gdbmf);
    while (key.dptr)
    {
        datum nextkey;

        /* print the key and value*/
        printf("%s ", key.dptr);
        printf("%s\n", gdbm_fetch(gdbmf, key).dptr);
        /* Obtain the next key */
        nextkey = gdbm_nextkey(gdbmf, key);
        /* Reclaim the memory used by the key */
        free(key.dptr);
        /* Use nextkey in the next iteration. */
        key = nextkey;
    }
    return 0;
}
