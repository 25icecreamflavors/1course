    
import matplotlib.pyplot as plt
import csv
import webbrowser
x=[]
y=[]
x1=[]
y1=[]
i = 0
with open('TimeData.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(float(row[0]))
        y.append(float(row[1]))
        x1.append(float(row[0]))
        y1.append(float(row[2]))
plt.plot(x,y, marker='', color='green')
plt.plot(x1,y1, marker='', color='indigo')
plt.title('Algorithm Performance')

plt.xlabel('Number of digits')
plt.ylabel('Time in milliseconds')
print("FLEX")
print("Would you like to turn on radio?")
print("Yes/No?")
i = input()
webbrowser.open('https://www.youtube.com/watch?v=rEoRxWx4FeI')
plt.show()
