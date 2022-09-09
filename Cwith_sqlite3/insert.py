#!/usr/bin/env python3.8

import sqlite3

conn = sqlite3.connect('books.db')
c = conn.cursor()
print ("open successfully")

c.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (1, 'Paul', 32, 'California', 20000.00 )")

c.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (2, 'Allen', 25, 'Texas', 15000.00 )")

c.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (3, 'Teddy', 23, 'Norway', 20000.00 )")

c.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 )")

# c.execute("INSERT INTO Books VALUES " \
#          "(100, '978-5-8459-2020-1', 'Томас Коннолли','Базы данных. Проектирование, реализация и сопровождение', 34.99)," \
#          "(200, '978-5-8459-1937-3', 'Дженнифер Роббинс', 'HTML5: карманный справочник', 24.99)," \
#          "(300,'978-5-8459-2006-5', 'Эви Немет и др.', 'Unix и Linux: руководство системного администратора', 24.99)," \
#          "(500, '978-5-8459-1689-1', 'Мэтт Зандстра','PHP: объекты, шаблоны и методики программирования', 49.99);");

conn.commit()
print ("insert successfully")
conn.close()