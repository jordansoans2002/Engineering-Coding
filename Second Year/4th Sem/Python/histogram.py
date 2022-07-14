import matplotlib.pyplot as plt
import numpy as np
np.random.seed(1)
data = np.random.randint(1, 100, 50)
plt.hist(data, rwidth=0.9)  # plot the freq (no of repetitions) of the data
plt.show()
print(data)