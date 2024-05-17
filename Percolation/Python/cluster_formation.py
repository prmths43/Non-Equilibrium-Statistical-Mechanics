import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random

p = 0.5
z = np.random.rand(100,100)
m = z<p
sns.heatmap(m, cmap='viridis')
plt.show()
