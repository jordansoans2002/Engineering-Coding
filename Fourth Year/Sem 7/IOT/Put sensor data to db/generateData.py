import csv
import time
import random
filename = "sensor_data.csv"
header =("Temperature","Humidity")

f = open("sensor_data.csv","w",newline="")
sensor = csv.writer(f)
sensor.writerow(header)
f.close()
time.sleep(1)
while 1<6:
    f = open("sensor_data.csv","a",newline="")
    x = (round(random.uniform(20,32),2),round(random.uniform(62,90),2))
    print(x)
    sensor = csv.writer(f)
    sensor.writerow(x)
    f.close()
    time.sleep(1)                  
    
