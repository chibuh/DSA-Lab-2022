import pandas as pd
from matplotlib import pyplot as plt

plt.title('n vs time', fontdict={'fontname': 'Comic Sans MS', 'fontsize':20})
plt.xlabel('n')
plt.ylabel('time taken')

plt.rcParams["figure.figsize"] = [17.00, 17.00]
plt.rcParams["figure.autolayout"] = True
columns = ["N", "Time"]
df = pd.read_csv("observations.csv", usecols=columns)
# print("Contents in csv file:\n", df)
plt.plot(df.N, df.Time, label='n vs time', color='red')

x_cords = range(0,109000)
y_cords = [(x*x)/150000000 for x in x_cords]
plt.plot(x_cords, y_cords, label='y=cx^2')

plt.legend()
plt.show()