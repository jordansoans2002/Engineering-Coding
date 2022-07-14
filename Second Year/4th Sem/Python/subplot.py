import matplotlib.pyplot as plt
import numpy as np
x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [10, 12, 20, 18, 30, 40, 50, 78, 75, 90]
plt.figure(figsize=(10, 5))
plt.subplot(2, 3, 1)  # rows,cols,position
plt.plot(x,y,color='purple',linestyle='dotted',lw=5,label="Sales graph")
plt.subplot(2, 3, 2)
plt.scatter(x, y, color='purple', label="Sales graph", s=1, marker="d")
plt.subplot(2, 3, 3)
plt.bar(x, y, color='blue', label="funny", width=0.8)  # if width=1 then all will stick
plt.subplot(2, 3, 4)
plt.barh(x, y, color='blue', label="funny")
plt.subplot(2, 3, 5)
data = np.random.randint(1, 100, 50)
plt.hist(data, rwidth=0.9)
plt.subplot(2, 3, 6)
slices = [100, 80, 40, 90, 50]
names = ['AI', 'python', 'maths', 'edc', 'linux']
plt.pie(slices, labels=names, autopct='%0.1f%%', explode=(0, 0, 0, 0, 0), shadow=False)
plt.show()

