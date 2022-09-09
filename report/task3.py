#!/usr/bin/env python3.8
# coding: utf-8
# %run test0
import dbm
db = dbm.open('students.gdbm', 'r')
k = db.firstkey()
while k != None:
    print(k)
    data = db[k]
    pdata = data.decode('UTF-8')
    pk = k.decode('UTF-8')
    print("k = ", pk, "data = ", pdata)
    k = db.nextkey(k)
print('all done!')
# db.close()
# quit()
