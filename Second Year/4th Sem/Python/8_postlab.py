import matplotlib.pyplot as plt
circle=plt.Circle((0.3, 0.3), 0.2,edgecolor='red',linewidth=1)
fig,ax=plt.subplots()
ax.add_patch(circle)
plt.show()