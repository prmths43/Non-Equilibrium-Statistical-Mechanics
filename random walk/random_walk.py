import sys
import random
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import gaussian_kde



end_positions = []
f = open('output_file.dat','w')
p = 0.5
#for ensemble in range(0, 10000):
for i in range(0,100000):
	position = 0.0
	t = 0
	for j in range(0,100):
	    q = random.random()
	    if q>p:
	    	position = position + 1
	    else:
	    	position = position - 1
	f.write("%i\n" % (position))
	end_positions.append(position)
#print(end_positions)
#plt.hist(end_positions, bins = 100, edgecolor = 'black')
#plt.title('Histogram of Random Walk Problem')
#plt.xlabel('position')
#plt.ylabel('frequency')
#plt.show()

kde = gaussian_kde(end_positions)
x_vals = np.linspace(min(end_positions), max(end_positions), 100)
y_vals = kde(x_vals)
plt.plot(x_vals, y_vals)
plt.show()

f.close()
