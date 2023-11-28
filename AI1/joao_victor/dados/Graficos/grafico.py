import matplotlib.pyplot as plt
import numpy as np
 
X, Y = np.loadtxt('heap.dat', delimiter=' ', unpack=True)
 
plt.scatter(X, Y)
plt.title('Gráfico da análise experimental')
plt.xlabel('n')
plt.ylabel('time (s)')
plt.show()