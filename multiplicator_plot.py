import time
import psutil
import matplotlib.pyplot as plt
from matplotlib import style
import webbrowser
%matplotlib notebook

style.use('classic')
webbrowser.open('https://www.youtube.com/watch?v=rEoRxWx4FeI')
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax1 = fig.add_subplot(1,1,1)
fig.show()

x=[]
y=[]
x1=[]
y1=[]
print("Olive line is for School method of multiplication")
print("Purple line is for Karatsuba method")
with open('TimeData.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        ax.clear()
        ax1.clear()
        x.append(float(row[0]))
        y.append(float(row[1]))
        x1.append(float(row[0]))
        y1.append(float(row[2]))
        ax.plot(x, y, marker = '', color='indigo')
        ax1.plot(x1,y1, marker='', color='olive')
        plt.xlabel('Number of digits')
        plt.ylabel('Time in milliseconds')
        plt.title('Algorithm Performance')
        fig.canvas.draw()
