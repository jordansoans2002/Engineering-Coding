import math
import matplotlib.pyplot as plt
import numpy as np

# angles from 0 to 2pi on x-axis
x = np.arange(0, math.pi*2, 0.1)
y = np.sin(x)
plt.plot(x, y)
plt.xlabel("angle")
plt.ylabel("sine wave")
plt.title('sine wave')
plt.show()
