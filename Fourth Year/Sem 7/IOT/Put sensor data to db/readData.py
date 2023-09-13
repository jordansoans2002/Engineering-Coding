import csv
import time
import random
import sqlite3

conn = sqlite3.connect("sensor_db")
print("database connected")

# conn.execute('''CREATE TABLE sensor_data
#     (ID INT PRIMARY KEY NOT NULL,
#     Temperature INT,
#     Humidity INT);''')
    
print("table created")
i=0
while 1<6:
    f = open("sensor_data.csv","r")
    data = f.readlines()[-1]
    th = data.split(",")
    print("Temp is "+th[0])
    print("Humidity is "+th[1])
    conn.execute("INSERT INTO sensor_data (ID,Temperature,Humidity) VALUES("+str(i)+","+str(th[0])+","+str(th[1])+")")
    i+=1
    f.close()
    time.sleep(1)
