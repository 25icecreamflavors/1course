import matplotlib.pyplot as plt
import csv
import webbrowser
x=[]
y=[]

with open('TimeData1.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(float(row[0]))
        y.append(float(row[1]))

plt.plot(x,y, marker='', color='green')

plt.title('Algorithm Performance')

plt.xlabel('Number of digits')
plt.ylabel('Time in milliseconds')

plt.show()
