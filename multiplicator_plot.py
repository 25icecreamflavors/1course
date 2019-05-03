import time
import psutil
import pylab
import csv
import matplotlib.pyplot as plt
from matplotlib import style
import webbrowser
%matplotlib notebook

style.use('classic')
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
fig.show()

x=[]
y=[]
x1=[]
y1=[]
webbrowser.open('https://www.youtube.com/watch?v=rEoRxWx4FeI')
with open('TimeData.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        ax.clear()
        ax1.clear()
        x.append(float(row[0]))
        y.append(float(row[1]))
        x1.append(float(row[0]))
        y1.append(float(row[2]))
        
        ax.plot(x, y, marker = '', color='indigo', label='School multiplication')
        ax.plot(x1, y1, marker='', color='olive', label='Karatsuba')
        pylab.legend(loc='upper left')
        plt.xlabel('Number of digits')
        plt.ylabel('Time in milliseconds')
        plt.title('Algorithm Performance')
        fig.canvas.draw()
