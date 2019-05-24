import matplotlib.pyplot as plt
from matplotlib import animation
from numpy import random 
from matplotlib import style
import csv
import psutil
import pylab
%matplotlib notebook

style.use('bmh')

fig = plt.figure()
ax1 = plt.axes(xlim=(0, 1000), ylim=(0,600000))
line, = ax1.plot([], [], lw=2)
plt.xlabel('Number of digits')
plt.ylabel('Time in milliseconds')
plt.title('Algorithm Performance')
ax1.set_facecolor('#1b212cff')

plotlays, plotcols, labels = [2], ["#d9d9d9ff","#cc0000"], ['School multiplication', 'Karatsuba']
lines = []
for index in range(2):
    lobj = ax1.plot([],[] ,lw=2, color=plotcols[index], label = labels[index])[0]
    lines.append(lobj)

pylab.legend(loc='upper left')

def init():
    for line in lines:
        line.set_data([],[])
    return lines

x1,y1 = [],[]
x2,y2 = [],[]

with open('TimeData.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        x1.append(float(row[0]))
        y1.append(float(row[1]))
        x2.append(float(row[0]))
        y2.append(float(row[2]))
        
frame_num = 1000

def animate(i):

    xlist = [x1[:i], x2[:i]]
    ylist = [y1[:i], y2[:i]]

    for lnum,line in enumerate(lines):
        line.set_data(xlist[lnum], ylist[lnum])

    return lines

anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames=frame_num, interval=6)

plt.show()
