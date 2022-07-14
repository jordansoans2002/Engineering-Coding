import matplotlib.pyplot as plt

slices = [100, 80, 40, 90, 50]
names = ['AI', 'python', 'maths', 'edc', 'linux']
plt.figure(figsize=(5,5))
plt.pie(slices, labels=names, autopct="%0.2f%%", explode=(0,0,0.3,0,0), shadow=True)
# autopct:  ; explode pushes that part out by given value(3 label by 0.3)
plt.legend(loc=4)
plt.show()