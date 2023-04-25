import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn import preprocessing, svm
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
df = pd.read_csv('/content/gdrive/MyDrive/Sem 6/DWM/Housing_Data_2_Variables.csv')

x = 'lotsize'
y = 'price'
xy_sum = (df[x] * df[y]).sum()
sum = df.sum()
sq_sum = (df**2).sum()
a = (sum[y]*sq_sum[x] - sum[x]*xy_sum) / (sq_sum[x] - sum[x]**2)
b = (xy_sum - sum[y]*sum[x]) / (sq_sum[x] - sum[x]**2)
a + b * float(input('Enter lotsize '))
x = np.linspace(0,16000,160000)
y = b*x + a
plt.scatter(df['lotsize'],df['price'],color='b')
plt.plot(x,y,color='k')
plt.title('9165 graph using calculation')
plt.show()

x = np.linspace(0,16000,160000)
y = b*x + a
plt.scatter(df['lotsize'],df['price'],color='b')
plt.plot(x,y,color='k')
plt.title('9165 graph using calculation')
plt.show()

X = np.array(df['lotsize']).reshape(-1,1)
y = np.array(df['price']).reshape(-1,1)

regr = LinearRegression()
regr.fit(X,y)

y_pred = regr.predict([[2350]])
y_pred
y_pred = regr.predict(X)
plt.scatter(X,y,color = 'b')
plt.plot(X,y_pred,color = 'k')
plt.show()

df2 = pd.read_csv('/content/gdrive/MyDrive/Sem 6/DWM/heart_data_3_variables.csv')
df2
x1 = 'biking'
x2 = 'smoking'
y = 'heart.disease'
mean = df2.mean()
x1x2 = (df2[x1] * df2[x2]).sum()
x1y = (df2[x1] * df2[y]).sum()
x2y = (df2[x2] * df2[y]).sum()
sq = (df2**2).sum()
b1 = (sq[x2]*x1y - x1x2*x2y) / (sq[x1]*sq[x2] - x1x2**2)
b2 = (sq[x1]*x2y - x1x2*x1y) / (sq[x1]*sq[x2] - x1x2**2)
b0 = mean[y] - b1*mean[x1] - b2*mean[x2]
print('b0 = ',b0)
print('b1 = ',b1)
print('b2 = ',b2)
b0 + b1*float(input('number of bikers ')) + b2*float(input('number of smokers '))
X = df2[['biking','smoking']]
y = df2['heart.disease']

regr = LinearRegression()
regr.fit(X,y)

y_pred = regr.predict([[0.75,0.1]])
print(y_pred)
