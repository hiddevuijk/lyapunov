import matplotlib.pyplot as plt
import numpy as np

ly = np.genfromtxt('ly.csv',delimiter=';')
dts = np.genfromtxt('dt.csv',delimiter=';')


plt.plot(dts,ly)
plt.show()





