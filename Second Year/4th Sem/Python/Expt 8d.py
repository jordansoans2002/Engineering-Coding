import matplotlib.pyplot as plt
x = range(-10, 10, 1)
y = []
for i in range(len(x)):
    y.append(10 if x[i]==0 else 0)
plt.stem(x, y)
plt.show()
