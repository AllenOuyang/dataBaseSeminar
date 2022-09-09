/*
 * @Date: 2022-01-07 19:09:56
 * @LastEditors: ArthurOyll
 * @LastEditTime: 2022-01-07 19:23:14
 * @FilePath: /mysql/task1.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "mysql.h"

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main()
{
    MYSQL *con = mysql_init(NULL);
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "guest", "guest123",
                           "children", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "insert into children(fname, age) values('Emma',4)"))
    {
        finish_with_error(con);
    }
    if (mysql_query(con, "insert into children(fname, age) values('Ben',5)"))
    {
        finish_with_error(con);
    }
    if (mysql_query(con, "insert into children(fname, age) values('Victor',10)"))
    {
        finish_with_error(con);
    }

    mysql_close(con);
    exit(0);
}
