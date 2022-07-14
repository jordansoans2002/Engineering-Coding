import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [10, 12, 20, 18, 30, 40, 50, 78, 75, 90]
plt.figure(figsize=(5, 5))  #size of the stage
plt.title("Expt9", fontsize=14, color='red')
plt.xlabel("Days")
plt.ylabel("Sales")
plt.xticks(x,color='red')
plt.yticks(color='red')
plt.grid()
plt.plot(x,y,color='purple',linestyle='dotted',lw=5,label="Sales graph")
# line style: dotted, dashed, solid ; lw:linewidth
plt.legend()  # tells what the graph indicates
plt.show()
