import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.datasets import make_classification

df = pd.read_csv('/content/gdrive/MyDrive/Sem 6/DWM/weather_dataset.csv')

X, y = make_classification(
    n_features=6,
    n_classes=3,
    n_samples=800,
    n_informative=2,
    random_state=1,
    n_clusters_per_class=1,
)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.33, random_state=125
)

model = GaussianNB()
model.fit(X_train,y_train)
predicted = model.predict([X_test[8]])

print("Actual Value:", y_test[8])
print("Predicted Value:", predicted[0])
