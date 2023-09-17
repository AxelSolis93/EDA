import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv('text.txt', header=None, names=['Distancia'])

df.plot.hist(grid=True, bins=20, rwidth=0.9, color='#607c8e')
plt.title('Histograma entre puntos con dimension 5000')
plt.xlabel('Distancia')
plt.ylabel('Frecuencia')
plt.grid(axis='y', alpha=0.75)

plt.show()