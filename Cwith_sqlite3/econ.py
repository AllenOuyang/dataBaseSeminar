#!/usr/bin/env python3.8

import sqlite3
import csv
#创建库
conn = sqlite3.connect('economics.db')
print ("open data base successfully")
c = conn.cursor()
#创建表
# c.execute('''CREATE TABLE CPI
#        (DATE        TEXT,
#         CPI         REAL);''')
# print ("create CPI table successfully")

# c.execute('''CREATE TABLE UNEM
#        (DATE        TEXT,
#         UNEM         REAL);''')
# print ("create CPI table successfully")

# c.execute('''CREATE TABLE GDEBT
#        (DATE        TEXT,
#         GDEBT         REAL);''')
# print ("create CPI table successfully")
# conn.commit()

#插入数据
with open('econdb_CPI.csv', 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    next(csvreader)
    for row in csvreader:
        print (row)
        c.execute('INSERT INTO CPI(DATE, CPI)' \
                            'VALUES(%s %s)',row)

with open('econdb_UNEM.csv', 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    next(csvreader)
    for row in csvreader:
        print (row)
        c.execute('INSERT INTO CPI(DATE, UNEM)' \
                            'VALUES(%s %s)',row)

with open('econdb_GDEBT.csv', 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    next(csvreader)
    for row in csvreader:
        print (row)
        c.execute('INSERT INTO CPI(DATE, GDEBT)' \
                            'VALUES(%s %s)',row)

print("successfully")
conn.close()