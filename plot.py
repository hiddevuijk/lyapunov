import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

xs = np.genfromtxt('xt.csv',delimiter=';')
ys = np.genfromtxt('yt.csv',delimiter=';')
zs = np.genfromtxt('zt.csv',delimiter=';')

fig = plt.figure()
ax = fig.gca(projection='3d')

ax.plot(xs,ys,zs)
ax.set_xlabel('x-axis')
ax.set_ylabel('y-axis')
ax.set_zlabel('z-axis')

plt.show()


