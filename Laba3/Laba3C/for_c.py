import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("/home/argo/Desktop/For-PenzGTU/Laba3/Laba3C/text.dat")
plt.plot(data[:,0], data[:,1])
plt.show()

