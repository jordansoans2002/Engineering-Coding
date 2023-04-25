import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('Real_Estate_Sales_730_Days.csv')
df.columns
df.dtypes
df.count()
df['SalePrice'] = df['SalePrice'].str.replace(',','').astype('float64')
df['TotalAppraisedValue'] = df['TotalAppraisedValue'].str.replace(',','').astype('float64')
df['TotalFinishedArea'] = df['TotalFinishedArea'].str.replace(',','').astype('float64')df.head(10)
df.describe()[['SalePrice','TotalAppraisedValue','TotalFinishedArea']]
df.describe()
df['SalePrice'].corr(df['TotalAppraisedValue'])df.fillna(0)
df.fillna(0)
#postlab
df[['SalePrice','TotalAppraisedValue']].plot()
plt.show()
plt.hist(df['SalePrice'])
plt.show()
plt.scatter(df['SalePrice'],df['TotalAppraisedValue'])
plt.show()
plt.boxplot(df['SalePrice'])
plt.show()

from sklearn.linear_model import LinearRegression as lr
x_mean = df['TotalFinishedArea'].mean()
y_mean = df['SalePrice'].mean()
x = df[['TotalFinishedArea']].fillna(x_mean)
y = df[['SalePrice']].fillna(y_mean)
lr.fit(x, y)

plt.scatter(x, y,  color='black')
plt.plot(x, lr.predict(x), color='blue', linewidth=3)
plt.show()
