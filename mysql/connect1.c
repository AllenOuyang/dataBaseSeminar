/*
 * @Date: 2022-01-05 09:18:14
 * @LastEditors: ArthurOyll
 * @LastEditTime: 2022-01-07 19:37:49
 * @FilePath: /mysql/connect1.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "mysql.h"
int main(int argc, char *argv[])
{
   MYSQL *conn_ptr;
   conn_ptr = mysql_init(NULL);
   if (!conn_ptr)
   {
      fprintf(stderr, "mysql_init failed\n");
      return EXIT_FAILURE;
   }
   conn_ptr = mysql_real_connect(conn_ptr, "localhost",
                                 "guest", "guest123", "children", 0, NULL, 0);
   if (conn_ptr)
   {
      printf("Connection success\n");
   }
   else
   {
      printf("Connection failed\n");
   }
   mysql_close(conn_ptr);
   return EXIT_SUCCESS;
}