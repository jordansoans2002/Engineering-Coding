import matplotlib.pyplot as plt
x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [10, 12, 20, 18, 30, 40, 50, 78, 75, 90]
plt.figure(figsize=(5,10))  # width, height
plt.title("Bar graph")
plt.xlabel('days')
plt.ylabel('sales')
plt.bar(x, y, color='blue', label="funny", width=0.8)  # if width=1 then all will stick
plt.legend()
plt.show()