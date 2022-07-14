import matplotlib.pyplot as plt
import numpy as np
x = range(-10, 20)
y = []
for i in range(len(x)):
    y.append(x[i] if x[i]>=0 else 0)
plt.figure(figsize=(5, 8))

plt.subplot(2, 1, 1)
plt.stem(x, y)
plt.title('discrete')
plt.subplot(2, 1, 2)
plt.plot(x, y)
plt.title('continous')
plt.show()
