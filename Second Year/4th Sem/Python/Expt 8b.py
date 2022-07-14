import matplotlib.pyplot as plt

x = range(-10, 20, 1)
y = []
s = []
for i in range(len(x)):
    temp = (1 if x[i]>=0 else 0)
    y.append(temp)

plt.figure(figsize=(5, 5))
plt.subplot(2, 1, 1)
plt.xlabel("time(s)")
plt.ylabel("amplitude")
plt.title('Step funtion wit stem()')
plt.stem(x, y)
plt.subplot(2, 1, 2)
plt.plot(x, y)
plt.xlabel("time(s)")
plt.ylabel("amplitude")
plt.title('Step funtion with plot()')
plt.show()
