import matplotlib.pyplot as plt
import numpy as np

np.random.seed(1)  # produces same random no for that seed
c
plt.figure(figsize=(8, 5))
plt.title("My graph", fontsize=14, color='red')
plt.xlabel("Days", fontsize=14, color='red')
plt.ylabel("Sales", fontsize=14, color='red')
plt.grid()
plt.scatter(x, y, color='purple', label="Sales graph", s=y/x, marker="d")
# s:size of marker, markers: +,v,d,^,<,>,o,*
plt.legend(loc = 5)  # only between 1 and 10
plt.show()
