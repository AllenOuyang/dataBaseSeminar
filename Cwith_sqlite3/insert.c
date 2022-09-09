/*
 * @Date: 2021-12-22 08:14:38
 * @LastEditors: ArthurOyll
 * @LastEditTime: 2021-12-22 16:55:28
 * @FilePath: /Cwith_sqlite3/insert.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("books.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   // for Books
   sql =    "INSERT INTO Books VALUES " \
            "(100, '978-5-8459-2020-1', 'Томас Коннолли','Базы данных. Проектирование, реализация и сопровождение', 34.99)," \
            "(200, '978-5-8459-1937-3', 'Дженнифер Роббинс', 'HTML5: карманный справочник', 24.99)," \
            "(300,'978-5-8459-2006-5', 'Эви Немет и др.', 'Unix и Linux: руководство системного администратора', 24.99)," \
            "(500, '978-5-8459-1689-1', 'Мэтт Зандстра','PHP: объекты, шаблоны и методики программирования', 49.99);";

   // for Book_Reviews
   // sql =    "INSERT INTO Book_Reviews VALUES " \
   //          "('999-5-8459-2020-1', 'Книга Роббинс написана доступным языком');";
   
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}